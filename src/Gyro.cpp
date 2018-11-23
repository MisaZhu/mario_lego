#include "Gyro.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

static void _destroyGyro(void* p) {
	gyro_sensor* m = (gyro_sensor*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_GYRO gyro_sensor* gyro = (gyro_sensor*)get_raw(env, THIS); \
	if(gyro == NULL)\
		return NULL;

var_t* JSGyro::constructor(vm_t* vm, var_t* env, void *) {
	int port = get_int(env, "port");
	std::string ePort = JSPorts::getEV3Port(port);
	gyro_sensor* m = new gyro_sensor(ePort);
	
	var_t* thisV = var_new_obj(m, _destroyGyro);
	var_t* protoV = get_obj_member(env, PROTOTYPE);
  var_add(thisV, PROTOTYPE, protoV);
	return thisV;
}

var_t* JSGyro::rate(vm_t* vm, var_t* env, void *) {
	GET_GYRO
	int r = 0;
	if(gyro->connected())
		r = gyro->rate();
	return var_new_int(r);
}

var_t* JSGyro::angle(vm_t* vm, var_t* env, void *) {
	GET_GYRO
	int r = 0;
	if(gyro->connected())
		r = gyro->angle();
	return var_new_int(r);
}

var_t* JSGyro::angleAndRate(vm_t* vm, var_t* env, void *) {
	GET_GYRO
	std::tuple<int, int> r;
	if(gyro->connected())
		r = gyro->rate_and_angle();
	var_t* v = var_new();
	var_add(v, "angle", var_new_int(std::get<0>(r)));
	var_add(v, "rate", var_new_int(std::get<1>(r)));

	return v;
}

var_t* JSGyro::connected(vm_t* vm, var_t* env, void *) {
	GET_GYRO
	return var_new_int(gyro->connected()?1:0);
}
