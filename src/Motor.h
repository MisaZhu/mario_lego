#ifndef JSM_JSMotor
#define JSM_JSMotor

#include "mario_vm.h"

class JSMotor {
	static var_t* constructor(vm_t* vm, var_t *env, void *);
	static var_t* stop(vm_t* vm, var_t *env, void *);
	static var_t* reset(vm_t* vm, var_t *env, void *);
	static var_t* run(vm_t* vm, var_t *env, void *);
	static var_t* runDirect(vm_t* vm, var_t *env, void *);
	static var_t* connected(vm_t* vm, var_t *env, void *);
	static var_t* setSpeed(vm_t* vm, var_t *env, void *);
	static var_t* setSpeedP(vm_t* vm, var_t *env, void *);
	static var_t* setSpeedI(vm_t* vm, var_t *env, void *);
	static var_t* setSpeedD(vm_t* vm, var_t *env, void *);
	static var_t* setTime(vm_t* vm, var_t *env, void *);
	static var_t* setPosition(vm_t* vm, var_t *env, void *);
	static var_t* runToPos(vm_t* vm, var_t *env, void *);
	static var_t* runTimed(vm_t* vm, var_t *env, void *);
	static var_t* setStopAction(vm_t* vm, var_t *env, void *);
	static var_t* dutyCycle(vm_t* vm, var_t *env, void *);
	static var_t* setDutyCycle(vm_t* vm, var_t *env, void *);
	static var_t* countPerRotation(vm_t* vm, var_t *env, void *);
	static var_t* countPerMeter(vm_t* vm, var_t *env, void *);
	static var_t* polarity(vm_t* vm, var_t *env, void *);
	static var_t* fullTravelCount(vm_t* vm, var_t *env, void *);
	static var_t* maxSpeed(vm_t* vm, var_t *env, void *);
	
public:
	inline static void regNative(vm_t* vm, const char* cls) {
		vm_reg_native(vm, cls, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, cls, "stop()", stop, NULL);
		vm_reg_native(vm, cls, "run()", run, NULL);
		vm_reg_native(vm, cls, "maxSpeed()", maxSpeed, NULL);
		vm_reg_native(vm, cls, "runDirect()", runDirect, NULL);
		vm_reg_native(vm, cls, "reset()", reset, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
		vm_reg_native(vm, cls, "setSpeed(speed)", setSpeed, NULL);
		vm_reg_native(vm, cls, "setSpeedP(speed)", setSpeedP, NULL);
		vm_reg_native(vm, cls, "setSpeedI(speed)", setSpeedI, NULL);
		vm_reg_native(vm, cls, "setSpeedD(speed)", setSpeedD, NULL);
		vm_reg_native(vm, cls, "setTime(time)", setTime, NULL);
		vm_reg_native(vm, cls, "setStopAction(action)", setStopAction, NULL);
		vm_reg_native(vm, cls, "setPosition(pos)", setPosition, NULL);
		vm_reg_native(vm, cls, "runToPos()", runToPos, NULL);
		vm_reg_native(vm, cls, "runTimed()", runTimed, NULL);
		vm_reg_native(vm, cls, "dutyCycle()", dutyCycle, NULL);
		vm_reg_native(vm, cls, "setDutyCycle(p)", setDutyCycle, NULL);
		vm_reg_native(vm, cls, "countPerRotation()", countPerRotation, NULL);
		vm_reg_native(vm, cls, "countPerMeter()", countPerMeter, NULL);
		vm_reg_native(vm, cls, "polarity()", polarity, NULL);
		vm_reg_native(vm, cls, "fullTravelCount()", fullTravelCount, NULL);
	}
};

#endif
