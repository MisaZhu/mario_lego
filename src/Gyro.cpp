#include "Gyro.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

static gyro_sensor* getGyro(var_t* c) {
	var_t* thisV = get_obj(c, THIS);
	var_t* n = get_obj(thisV, "gyro");
	if(n == NULL)
		return NULL;

	gyro_sensor* m = (gyro_sensor*)n->value;
	return m;
}

static void _destroyGyro(void* p) {
	gyro_sensor* m = (gyro_sensor*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_GYRO gyro_sensor* gyro = getGyro(env); \
	if(gyro == NULL)\
		return NULL;

var_t* JSGyro::constructor(vm_t* vm, var_t* env, void *) {
	var_t* thisV = get_obj(env, THIS);
	int port = get_int(env, "port");
	std::string ePort = JSPorts::getEV3Port(port);
	gyro_sensor* m = new gyro_sensor(ePort);
	
	var_t* v = var_new_obj(m, _destroyGyro);
	var_add(thisV, "gyro", v);
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
