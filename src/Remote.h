#ifndef JSM_JSRemote
#define JSM_JSRemote

#include "mario.h"

class JSRemote  {
	static var_t* constructor(vm_t* vm, var_t *env, void *);
	static var_t* process(vm_t* vm, var_t *env, void *);
	static var_t* connected(vm_t* vm, var_t *env, void *);

public:
	inline static void regNative(vm_t* vm, const char* clsname) {
		var_t* cls = vm_new_class(vm, clsname);
		vm_reg_native(vm, cls, "constructor(channel)", constructor, NULL);
		vm_reg_native(vm, cls, "process()", process, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
	}
};

#endif
