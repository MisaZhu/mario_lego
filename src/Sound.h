#ifndef JSM_JSSound
#define JSM_JSSound

#include "mario.h"

class JSSound {
	static var_t* speak(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* clsname) {
		var_t* cls = vm_new_class(vm, clsname);
		vm_reg_native(vm, cls, "speak(words)", speak, NULL);
	}
};

#endif
