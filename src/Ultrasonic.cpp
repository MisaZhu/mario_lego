#include "Ultrasonic.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;
using namespace std;

static ultrasonic_sensor* getUltrasonic(var_t* env) {
	var_t* thisV = get_obj(env, THIS);
	var_t* n = get_obj(thisV, "ultrasonic");
	if(n == NULL)
		return NULL;

	ultrasonic_sensor* m = (ultrasonic_sensor*)n->value;
	return m;
}

static void _destroyUltrasonic(void* p) {
	ultrasonic_sensor* m = (ultrasonic_sensor*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_ULTRASONIC ultrasonic_sensor* ultrasonic = getUltrasonic(env); \
	if(ultrasonic == NULL)\
		return NULL;

var_t* JSUltrasonic::constructor(vm_t* vm, var_t* env, void *) {
	var_t* thisV = get_obj(env, THIS);
	int port = get_int(env, "port");
	string ePort = JSPorts::getEV3Port(port);
	ultrasonic_sensor* m = new ultrasonic_sensor(ePort);
	
	var_t* v = var_new_obj(m, _destroyUltrasonic);
	var_add(thisV, "ultrasonic", v);
	return thisV;
}

var_t* JSUltrasonic::distance_cm(vm_t* vm, var_t* env, void *) {
	GET_ULTRASONIC
	float f = 0.0;
	if(ultrasonic->connected())
		f = ultrasonic->distance_centimeters(true);
	return var_new_float(f);
}

var_t* JSUltrasonic::connected(vm_t* vm, var_t* env, void *) {
	GET_ULTRASONIC
	int res = ultrasonic->connected()?1:0;
	return var_new_int(res);
}
