#ifndef JSM_JSServoMotor
#define JSM_JSServoMotor

#include "mario.h"

class JSServoMotor {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* stop(vm_t* vm, var_t* env, void *);
	static var_t* run(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);
	static var_t* setPosition(vm_t* vm, var_t* env, void *);
	static var_t* setRate(vm_t* vm, var_t* env, void *);
	static var_t* polarity(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* clsname) {
		var_t* cls = vm_new_class(vm, clsname);
		vm_reg_native(vm, cls, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, cls, "stop()", stop, NULL);
		vm_reg_native(vm, cls, "run()", run, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
		vm_reg_native(vm, cls, "polarity()", polarity, NULL);
		vm_reg_native(vm, cls, "setPosition(pos)", setPosition, NULL);
		vm_reg_native(vm, cls, "setRate(rate)", setRate, NULL);
	}
};

#endif
