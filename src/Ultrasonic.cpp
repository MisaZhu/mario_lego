#include "Ultrasonic.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;
using namespace std;

static void _destroyUltrasonic(void* p) {
	ultrasonic_sensor* m = (ultrasonic_sensor*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_ULTRASONIC ultrasonic_sensor* ultrasonic = (ultrasonic_sensor*)get_raw(env, THIS); \
	if(ultrasonic == NULL)\
		return NULL;

var_t* JSUltrasonic::constructor(vm_t* vm, var_t* env, void *) {
	int port = get_int(env, "port");
	string ePort = JSPorts::getEV3Port(port);
	ultrasonic_sensor* m = new ultrasonic_sensor(ePort);
	
	var_t* thisV = var_new_obj(vm, m, _destroyUltrasonic);
	var_from_prototype(thisV, get_obj(env, THIS));
	return thisV;
}

var_t* JSUltrasonic::distance_cm(vm_t* vm, var_t* env, void *) {
	GET_ULTRASONIC
	float f = 0.0;
	if(ultrasonic->connected())
		f = ultrasonic->distance_centimeters(true);
	return var_new_float(vm, f);
}

var_t* JSUltrasonic::connected(vm_t* vm, var_t* env, void *) {
	GET_ULTRASONIC
	int res = ultrasonic->connected()?1:0;
	return var_new_int(vm, res);
}
