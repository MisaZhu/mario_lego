#ifndef JSM_JSRemote
#define JSM_JSRemote

#include "mario_vm.h"

class JSRemote  {
	static var_t* constructor(vm_t* vm, var_t *env, void *);
	static var_t* process(vm_t* vm, var_t *env, void *);
	static var_t* connected(vm_t* vm, var_t *env, void *);

public:
	inline static void regNative(vm_t* vm, const char* className) {
		vm_reg_native(vm, className, "constructor(channel)", constructor, NULL);
		vm_reg_native(vm, className, "process()", process, NULL);
		vm_reg_native(vm, className, "connected()", connected, NULL);
	}
};

#endif
