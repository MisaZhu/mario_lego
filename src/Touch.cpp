#include "Touch.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

static touch_sensor* getTouch(var_t* c) {
	var_t* thisV = get_obj(c, THIS);
	var_t* n = get_obj(thisV, "touch");
	if(n == NULL)
		return NULL;

	touch_sensor* m = (touch_sensor*)n->value;
	return m;
}

static void _destroyTouch(void* p) {
	touch_sensor* m = (touch_sensor*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_TOUCH touch_sensor* touch = getTouch(env); \
	if(touch == NULL)\
		return NULL;

var_t* JSTouch::constructor(vm_t* vm, var_t* env, void *) {
	var_t* thisV = get_obj(env, THIS);
	int port = get_int(env, "port");
	std::string ePort = JSPorts::getEV3Port(port);
	touch_sensor* m = new touch_sensor(ePort);
	
	var_t* v = var_new_obj(m, _destroyTouch);
	var_add(thisV, "touch", v);
	return thisV;
}

var_t* JSTouch::pressed(vm_t* vm, var_t* env, void *) {
	GET_TOUCH
	bool r = false;
	if(touch->connected())
		r = touch->is_pressed();
	return var_new_int(r?1:0);
}

var_t* JSTouch::connected(vm_t* vm, var_t* env, void *) {
	GET_TOUCH
	return var_new_int(touch->connected()?1:0);
}
