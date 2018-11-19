#include "Motor.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;
using namespace std;

static motor* getMotor(var_t* env) {
	var_t* thisV = get_obj(env, THIS);
	var_t* n = get_obj(thisV, "motor");
	if(n == NULL)
		return NULL;

	motor* m = (motor*)n->value;
	return m;
}

static void _destroyMotor(void* p) {
	motor* m = (motor*)p;
	if(m == NULL)
		return;
	if(m->connected())
		m->stop();
	delete m;
}

#define GET_MOTOR motor* motor = getMotor(env); \
	if(motor == NULL)\
		return NULL;

var_t* JSMotor::constructor(vm_t* vm, var_t* env, void *) {
	var_t* thisV = get_obj(env, THIS);
	int port = get_int(env, "port");
	string ePort = JSPorts::getEV3Port(port);

	motor mt(ePort);
	motor* m = NULL;
	if(mt.driver_name() == motor::motor_large)
		m = new large_motor(ePort);
	else 
		m = new medium_motor(ePort);
	
	var_t* v = var_new_obj(m, _destroyMotor);
	var_add(thisV, "motor", v);
	return thisV;
}

var_t* JSMotor::stop(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->stop();
	return get_obj(env, THIS);
}

var_t* JSMotor::reset(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->reset();
	return get_obj(env, THIS);
}

var_t* JSMotor::run(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->run_forever();
	return get_obj(env, THIS);
}

var_t* JSMotor::runDirect(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected())
		motor->run_direct();
	return get_obj(env, THIS);
}

var_t* JSMotor::connected(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int res = motor->connected()?1:0;
	return var_new_int(res);
}

var_t* JSMotor::setSpeed(vm_t* vm, var_t* env, void *) {
	int sp = get_int(env, "speed");
	var_t* thisV = get_obj(env, THIS);

	GET_MOTOR
	if(motor->connected()) 
		motor->set_speed_sp(sp);
	return thisV;
}

var_t* JSMotor::setSpeedP(vm_t* vm, var_t* env, void *) {
	int sp = get_int(env, "speed");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_speed_p(sp);
	return get_obj(env, THIS);
}

var_t* JSMotor::setSpeedI(vm_t* vm, var_t* env, void *) {
	int sp = get_int(env, "speed");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_speed_i(sp);
	return get_obj(env, THIS);
}

var_t* JSMotor::setSpeedD(vm_t* vm, var_t* env, void *) {
	int sp = get_int(env, "speed");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_speed_d(sp);
	return get_obj(env, THIS);
}

var_t* JSMotor::setTime(vm_t* vm, var_t* env, void *) {
	int time = get_int(env, "time");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_time_sp(time);
	return get_obj(env, THIS);
}

var_t* JSMotor::setPosition(vm_t* vm, var_t* env, void *) {
	int pos = get_int(env, "pos");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_position_sp(pos);
	return get_obj(env, THIS);
}

var_t* JSMotor::setStopAction(vm_t* vm, var_t* env, void *) {
	string act = get_str(env, "action");

	GET_MOTOR
	if(motor->connected()) 
		motor->set_stop_action(act);
	return get_obj(env, THIS);
}

var_t* JSMotor::runToPos(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected()) 
		motor->run_to_abs_pos();
	return get_obj(env, THIS);
}

var_t* JSMotor::runTimed(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	if(motor->connected()) 
		motor->run_timed();
	return get_obj(env, THIS);
}

var_t* JSMotor::countPerRotation(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int ct = 0;
	if(motor->connected()) 
		ct = motor->count_per_rot();
	return var_new_int(ct);
}

var_t* JSMotor::countPerMeter(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int ct = 0;
	if(motor->connected()) 
		ct = motor->count_per_m();
	return var_new_int(ct);
}

var_t* JSMotor::polarity(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	string p = "";
	if(motor->connected()) 
		p = motor->polarity();
	return var_new_str(vm, p.c_str());
}

var_t* JSMotor::dutyCycle(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int p = 0;
	if(motor->connected()) 
		p = motor->duty_cycle_sp();
	return var_new_int(p);
}

var_t* JSMotor::fullTravelCount(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int p = 0;
	if(motor->connected()) 
		p = motor->full_travel_count();
	return var_new_int(p);
}

var_t* JSMotor::maxSpeed(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int p = 0;
	if(motor->connected()) 
		p = motor->max_speed();
	return var_new_int(p);
}

var_t* JSMotor::setDutyCycle(vm_t* vm, var_t* env, void *) {
	GET_MOTOR
	int p = get_int(env, "p");
	if(motor->connected()) 
		motor->set_duty_cycle_sp(p);
	return get_obj(env, THIS);
}
