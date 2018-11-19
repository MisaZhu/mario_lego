#ifndef JSM_JSUltrasonic
#define JSM_JSUltrasonic

#include "mario_vm.h"

class JSUltrasonic {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* distance_cm(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* cls) {
		vm_reg_native(vm, cls, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, cls, "distance_cm()", distance_cm, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
	}
};

#endif
