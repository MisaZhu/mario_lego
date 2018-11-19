#ifndef JSM_JSPort
#define JSM_JSPort

#include "mario_vm.h"

class JSPort {
	static var_t* constructor(vm_t* vm, var_t *env, void *);
	static var_t* address(vm_t* vm, var_t *env, void *);
	static var_t* mode(vm_t* vm, var_t *env, void *);
	static var_t* modes(vm_t* vm, var_t *env, void *);
	static var_t* setMode(vm_t* vm, var_t *env, void *);
	static var_t* setSetDevice(vm_t* vm, var_t *env, void *);
	static var_t* driverName(vm_t* vm, var_t *env, void *);
	static var_t* status(vm_t* vm, var_t *env, void *);
	static var_t* connected(vm_t* vm, var_t *env, void *);

public:
	static inline void regNative(vm_t* vm, const char* cls) {
		vm_reg_native(vm, cls, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, cls, "address()", address, NULL);
		vm_reg_native(vm, cls, "modes()", mode, NULL);
		vm_reg_native(vm, cls, "mode()", mode, NULL);
		vm_reg_native(vm, cls, "setMode(mode)", setMode, NULL);
		vm_reg_native(vm, cls, "setSetDevice(dev)", setSetDevice, NULL);
		vm_reg_native(vm, cls, "driverName()", driverName, NULL);
		vm_reg_native(vm, cls, "status()", status, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
	}
};

#endif
