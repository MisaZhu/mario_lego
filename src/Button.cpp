#include "Button.h"
#include "ev3dev.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

/*
 * The event structure itself
 */

struct input_event {
	struct timeval time;
	uint16_t type;
	uint16_t code;
	int32_t value;
};

using namespace ev3dev;

typedef struct threadData {
	vm_t* vm;
	var_t* obj;
} thread_data_t;

static void* _buttonThread(void* data) {
  thread_data_t* p = (thread_data_t*)data;
	vm_t* vm = p->vm;
	var_t* obj = p->obj;

  pthread_detach(pthread_self());

  int fd = open("/dev/input/by-path/platform-gpio-keys.0-event", O_RDONLY);
  if (fd  < 0) {
    _debug("Couldn't open platform-gpio-keys device!\n");
    return NULL;
  }

  input_event ev;
  while (true) {
    size_t rb = ::read(fd, &ev, sizeof(ev));
    if (rb < sizeof(input_event))
      continue;
		var_t* v = var_new_obj(NULL, NULL);
		var_add(v, "type", var_new_int(ev.type));
		var_add(v, "code", var_new_int(ev.code));
		var_add(v, "value", var_new_int(ev.value));

		var_t* args = var_new();
		var_add(args, "", v);
		interrupt_by_name(vm, obj, "onEvent", args);
  }

  return NULL;
}

static thread_data_t _data;
var_t* JSButton::run(vm_t* vm, var_t* env, void *) {
  pthread_t tid;
	_data.vm = vm;
	_data.obj = get_obj(env, THIS);

	if(_data.obj == NULL) {
		_debug("Button.run() THIS obj is null\n");
		return NULL;
	}

  pthread_create(&tid, NULL, _buttonThread, &_data);
	return NULL;
}

