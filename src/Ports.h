#ifndef JSM_JSPorts
#define JSM_JSPorts

#include "mario_vm.h"
#include <string>

class JSPorts {
	const static int OUT_AUTO = 0;
	const static int OUT_A = 1;
	const static int OUT_B = 2;
	const static int OUT_C = 3;
	const static int OUT_D = 4;

	const static int IN_1 = 5;
	const static int IN_2 = 6;
	const static int IN_3 = 7;
	const static int IN_4 = 8;
	const static int IN_AUTO = 9;

public:
	static std::string getEV3Port(int port);
	static void regNative(vm_t* vm, const char* cls) {
	vm_reg_var(vm, cls, "OUT_AUTO", var_new_int(OUT_AUTO), true);
	vm_reg_var(vm, cls, "OUT_A", var_new_int(OUT_A), true);
	vm_reg_var(vm, cls, "OUT_B", var_new_int(OUT_B), true);
	vm_reg_var(vm, cls, "OUT_C", var_new_int(OUT_C), true);
	vm_reg_var(vm, cls, "OUT_D", var_new_int(OUT_D), true);
	vm_reg_var(vm, cls, "IN_AUTO", var_new_int(IN_AUTO), true);
	vm_reg_var(vm, cls, "IN_1", var_new_int(IN_1), true);
	vm_reg_var(vm, cls, "IN_2", var_new_int(IN_2), true);
	vm_reg_var(vm, cls, "IN_3", var_new_int(IN_3), true);
	vm_reg_var(vm, cls, "IN_4", var_new_int(IN_4), true);
}

};

#endif
