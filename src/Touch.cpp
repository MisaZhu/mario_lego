#include "Touch.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

static void _destroyTouch(void* p) {
	touch_sensor* m = (touch_sensor*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_TOUCH touch_sensor* touch = (touch_sensor*)get_raw(env, THIS); \
	if(touch == NULL)\
		return NULL;

var_t* JSTouch::constructor(vm_t* vm, var_t* env, void *) {
	int port = get_int(env, "port");
	std::string ePort = JSPorts::getEV3Port(port);
	touch_sensor* m = new touch_sensor(ePort);
	
	var_t* thisV = var_new_obj(vm, m, _destroyTouch);
	var_from_prototype(thisV, get_obj(env, THIS));
	return thisV;
}

var_t* JSTouch::pressed(vm_t* vm, var_t* env, void *) {
	GET_TOUCH
	bool r = false;
	if(touch->connected())
		r = touch->is_pressed();
	return var_new_int(vm, r?1:0);
}

var_t* JSTouch::connected(vm_t* vm, var_t* env, void *) {
	GET_TOUCH
	return var_new_int(vm, touch->connected()?1:0);
}
