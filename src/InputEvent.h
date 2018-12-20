#ifndef JSM_JSInputEvent
#define JSM_JSInputEvent

#include "mario_vm.h"


class JSInputEvent {
	const static int KEY = 1;
	const static int PRESSED = 1;
	const static int RELEASED = 0;
	
	const static int UP = 103;
	const static int DOWN = 108;
	const static int LEFT	= 105;
	const static int RIGHT = 106;
	const static int ENTER = 28;
	const static int BACK = 14;

public:
	inline static void regNative(vm_t* vm, const char* className) {
		vm_reg_var(vm, className, "KEY", var_new_int(vm, KEY), true);
		vm_reg_var(vm, className, "PRESSED", var_new_int(vm, PRESSED), true);
		vm_reg_var(vm, className, "RELEASED", var_new_int(vm, RELEASED), true);
		vm_reg_var(vm, className, "UP", var_new_int(vm, UP), true);
		vm_reg_var(vm, className, "DOWN", var_new_int(vm, DOWN), true);
		vm_reg_var(vm, className, "LEFT", var_new_int(vm, LEFT), true);
		vm_reg_var(vm, className, "RIGHT", var_new_int(vm, RIGHT), true);
		vm_reg_var(vm, className, "ENTER", var_new_int(vm, ENTER), true);
		vm_reg_var(vm, className, "BACK", var_new_int(vm, BACK), true);
	}
};

#endif
