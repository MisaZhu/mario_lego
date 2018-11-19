#ifndef JSM_JSInfrared
#define JSM_JSInfrared

#include "mario_vm.h"

class JSInfrared {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* proximity(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* cls) {
		vm_reg_native(vm, cls, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, cls, "proximity()", proximity, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
	}
};

#endif
