#include "Remote.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

static remote_control* getRemote(var_t* c) {
	var_t* thisV = get_obj(c, THIS);
	var_t* n = get_obj(thisV, "remote");
	if(n == NULL)
		return NULL;

	remote_control* m = (remote_control*)n->value;
	return m;
}

static void _destroyRemote(void* p) {
	remote_control* m = (remote_control*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_REMOTE remote_control* remote = getRemote(env); \
	if(remote == NULL)\
		return NULL;

static std::function<void(bool)> remoteEvent(vm_t* vm, var_t* thisV, const char* button) {
	return [vm, thisV, button](bool state) {
		var_t* args = var_new();
		var_t* bt = var_new_str(vm, button);
		var_t* st = var_new_int(state ? 1:0);

		var_add(args, "", bt);
		var_add(args, "", st);
		interrupt_by_name(vm, thisV, "onEvent", args);
	};
}

var_t* JSRemote::constructor(vm_t* vm, var_t* env, void *) {
	var_t* thisV = get_obj(env, THIS);
	int channel = get_int(env, "channel");
	remote_control* m = new remote_control(channel);
	m->on_red_up = remoteEvent(vm, thisV, "RED_UP");
	m->on_red_down = remoteEvent(vm, thisV, "RED_DOWN");
	m->on_blue_up = remoteEvent(vm, thisV, "BLUE_UP");
	m->on_blue_down = remoteEvent(vm, thisV, "BLUE_DOWN");
	m->on_beacon = remoteEvent(vm, thisV, "BEACON");
	
	var_t* v = var_new_obj(m, _destroyRemote);
	var_add(thisV, "remote", v);
	return thisV;
}

var_t* JSRemote::process(vm_t* vm, var_t* env, void *) {
	GET_REMOTE
	if(remote->connected())
		remote->process();
	return NULL;
}

var_t* JSRemote::connected(vm_t* vm, var_t* env, void *) {
	GET_REMOTE
	return var_new_int(remote->connected()?1:0);
}
