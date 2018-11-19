#ifndef JSM_JSDCMotor
#define JSM_JSDCMotor

#include "mario_vm.h"

class JSDCMotor {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* stop(vm_t* vm, var_t* env, void *);
	static var_t* run(vm_t* vm, var_t* env, void *);
	static var_t* runDirect(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);
	static var_t* setTime(vm_t* vm, var_t* env, void *);
	static var_t* runTimed(vm_t* vm, var_t* env, void *);
	static var_t* setStopAction(vm_t* vm, var_t* env, void *);
	static var_t* dutyCycle(vm_t* vm, var_t* env, void *);
	static var_t* setDutyCycle(vm_t* vm, var_t* env, void *);
	static var_t* polarity(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* className) {
		vm_reg_native(vm, className, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, className, "stop()", stop, NULL);
		vm_reg_native(vm, className, "run()", run, NULL);
		vm_reg_native(vm, className, "runDirect()", runDirect, NULL);
		vm_reg_native(vm, className, "connected()", connected, NULL);
		vm_reg_native(vm, className, "setTime(time)", setTime, NULL);
		vm_reg_native(vm, className, "setStopAction(action)", setStopAction, NULL);
		vm_reg_native(vm, className, "runTimed()", runTimed, NULL);
		vm_reg_native(vm, className, "dutyCycle()", dutyCycle, NULL);
		vm_reg_native(vm, className, "setDutyCycle(p)", setDutyCycle, NULL);
		vm_reg_native(vm, className, "polarity()", polarity, NULL);
	}
};

#endif
