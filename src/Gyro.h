#ifndef JSM_JSGyro
#define JSM_JSGyro

#include "mario.h"

class JSGyro {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* angle(vm_t* vm, var_t* env, void *);
	static var_t* rate(vm_t* vm, var_t* env, void *);
	static var_t* angleAndRate(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* clsname) {
		var_t* cls = vm_new_class(vm, clsname);
		vm_reg_native(vm, cls, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, cls, "angleAndRate()", angleAndRate, NULL);
		vm_reg_native(vm, cls, "angle()", angle, NULL);
		vm_reg_native(vm, cls, "rate()", rate, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
	}
};

#endif
