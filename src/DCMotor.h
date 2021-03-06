#ifndef JSM_JSDCMotor
#define JSM_JSDCMotor

#include "mario.h"

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
	inline static void regNative(vm_t* vm, const char* clsname) {
		var_t* cls = vm_new_class(vm, clsname);
		vm_reg_native(vm, cls, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, cls, "stop()", stop, NULL);
		vm_reg_native(vm, cls, "run()", run, NULL);
		vm_reg_native(vm, cls, "runDirect()", runDirect, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
		vm_reg_native(vm, cls, "setTime(time)", setTime, NULL);
		vm_reg_native(vm, cls, "setStopAction(action)", setStopAction, NULL);
		vm_reg_native(vm, cls, "runTimed()", runTimed, NULL);
		vm_reg_native(vm, cls, "dutyCycle()", dutyCycle, NULL);
		vm_reg_native(vm, cls, "setDutyCycle(p)", setDutyCycle, NULL);
		vm_reg_native(vm, cls, "polarity()", polarity, NULL);
	}
};

#endif
