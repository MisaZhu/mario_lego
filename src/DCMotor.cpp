#include "DCMotor.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

static dc_motor* getMotor(var_t* c) {
	var_t* thisV = get_obj(c, THIS);
	var_t* n = get_obj(thisV, "motor");
	if(n == NULL)
		return NULL;

	dc_motor* m = (dc_motor*)n->value;
	return m;
}

static void _destroyMotor(void* p) {
	dc_motor* m = (dc_motor*)p;
	if(m == NULL)
		return;
	if(m->connected())
		m->stop();
	delete m;
}

#define GET_MOTOR dc_motor* motor = getMotor(env); \
	if(motor == NULL)\
		return NULL;

var_t* JSDCMotor::constructor(vm_t* vm, var_t* env, void *) {
	var_t* thisV = get_obj(env, THIS);
	int port = get_int(env, "port");
	std::string ePort = JSPorts::getEV3Port(port);

	dc_motor* m = new dc_motor(ePort);
	
	var_t* v = var_new_obj(m, _destroyMotor);
	var_add(thisV, "motor", v);
	return thisV;
}

var_t* JSDCMotor::stop(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->stop();
	return get_obj(env, THIS);
}

var_t* JSDCMotor::run(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->run_forever();
	return get_obj(env, THIS);
}

var_t* JSDCMotor::runDirect(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->run_direct();
	return get_obj(env, THIS);
}

var_t* JSDCMotor::connected(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	return var_new_int(motor->connected()?1:0);
}

var_t* JSDCMotor::setTime(vm_t* vm, var_t* env, void *) {
	int time = get_int(env, "time");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_time_sp(time);
	return get_obj(env, THIS);
}

var_t* JSDCMotor::setStopAction(vm_t* vm, var_t* env, void *) {
	std::string act = get_str(env, "action");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_stop_action(act);
	return get_obj(env, THIS);
}

var_t* JSDCMotor::runTimed(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected()) 
		motor->run_timed();
	return get_obj(env, THIS);
}

var_t* JSDCMotor::polarity(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	std::string p = "";
	if(motor->connected()) 
		p = motor->polarity();
	return var_new_str(vm, p.c_str());
}

var_t* JSDCMotor::dutyCycle(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int p = 0;
	if(motor->connected()) 
		p = motor->duty_cycle_sp();
	return var_new_int(p);
}

var_t* JSDCMotor::setDutyCycle(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int p = get_int(env, "p");
	if(motor->connected()) 
		motor->set_duty_cycle_sp(p);
	return get_obj(env, THIS);
}
