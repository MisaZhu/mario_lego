#ifndef JSM_JSTouch
#define JSM_JSTouch

#include "mario_vm.h"

class JSTouch {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* pressed(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* className) {
		vm_reg_native(vm, className, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, className, "pressed()", pressed, NULL);
		vm_reg_native(vm, className, "connected()", connected, NULL);
	}
};

#endif
