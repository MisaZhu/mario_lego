#include "ServoMotor.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

static void _destroyMotor(void* p) {
	servo_motor* m = (servo_motor*)p;
	if(m == NULL)
		return;
	if(m->connected())
		m->float_();
	delete m;
}

#define GET_MOTOR servo_motor* motor = (servo_motor*)get_raw(env, THIS); \
	if(motor == NULL)\
		return NULL;

var_t* JSServoMotor::constructor(vm_t* vm, var_t* env, void *) {
	int port = get_int(env, "port");
	std::string ePort = JSPorts::getEV3Port(port);

	servo_motor* m = new servo_motor(ePort);
	
	var_t* thisV = var_new_obj(m, _destroyMotor);
	var_t* protoV = get_obj_member(env, PROTOTYPE);
  var_add(thisV, PROTOTYPE, protoV);
	return thisV;
}

var_t* JSServoMotor::stop(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->float_();
	return get_obj(env, THIS);
}

var_t* JSServoMotor::run(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->run();
	return get_obj(env, THIS);
}

var_t* JSServoMotor::connected(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	return var_new_int(motor->connected()?1:0);
}

var_t* JSServoMotor::setPosition(vm_t* vm, var_t* env, void *) {
	int pos = get_int(env, "pos");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_position_sp(pos);
	return get_obj(env, THIS);
}

var_t* JSServoMotor::setRate(vm_t* vm, var_t* env, void *) {
	int rate = get_int(env, "rate");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_rate_sp(rate);
	return get_obj(env, THIS);
}


var_t* JSServoMotor::polarity(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	std::string p = "";
	if(motor->connected()) 
		p = motor->polarity();
	return var_new_str(p.c_str());
}

