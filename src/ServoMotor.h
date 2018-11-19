#ifndef JSM_JSServoMotor
#define JSM_JSServoMotor

#include "mario_vm.h"

class JSServoMotor {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* stop(vm_t* vm, var_t* env, void *);
	static var_t* run(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);
	static var_t* setPosition(vm_t* vm, var_t* env, void *);
	static var_t* setRate(vm_t* vm, var_t* env, void *);
	static var_t* polarity(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* className) {
		vm_reg_native(vm, className, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, className, "stop()", stop, NULL);
		vm_reg_native(vm, className, "run()", run, NULL);
		vm_reg_native(vm, className, "connected()", connected, NULL);
		vm_reg_native(vm, className, "polarity()", polarity, NULL);
		vm_reg_native(vm, className, "setPosition(pos)", setPosition, NULL);
		vm_reg_native(vm, className, "setRate(rate)", setRate, NULL);
	}
};

#endif
