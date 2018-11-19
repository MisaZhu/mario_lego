#ifndef JSM_JSGyro
#define JSM_JSGyro

#include "mario_vm.h"

class JSGyro {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* angle(vm_t* vm, var_t* env, void *);
	static var_t* rate(vm_t* vm, var_t* env, void *);
	static var_t* angleAndRate(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* className) {
		vm_reg_native(vm, className, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, className, "angleAndRate()", angleAndRate, NULL);
		vm_reg_native(vm, className, "angle()", angle, NULL);
		vm_reg_native(vm, className, "rate()", rate, NULL);
		vm_reg_native(vm, className, "connected()", connected, NULL);
	}
};

#endif
