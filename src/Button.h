#ifndef JSM_JSButton
#define JSM_JSButton

#include "mario_vm.h"

class JSButton {
	static var_t* run(vm_t* vm, var_t *env, void *);

public:
	inline static void regNative(vm_t* vm, const char* className) {
		vm_reg_native(vm, className, "run()", run, NULL);
	}
};

#endif
