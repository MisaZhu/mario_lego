#ifndef JSM_JSSound
#define JSM_JSSound

#include "mario_vm.h"

class JSSound {
	static var_t* speak(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* cls) {
		vm_reg_native(vm, cls, "speak(words)", speak, NULL);
	}
};

#endif
