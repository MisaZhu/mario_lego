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
		vm_reg_var(vm, className, "KEY", var_new_int(KEY), true);
		vm_reg_var(vm, className, "PRESSED", var_new_int(PRESSED), true);
		vm_reg_var(vm, className, "RELEASED", var_new_int(RELEASED), true);
		vm_reg_var(vm, className, "UP", var_new_int(UP), true);
		vm_reg_var(vm, className, "DOWN", var_new_int(DOWN), true);
		vm_reg_var(vm, className, "LEFT", var_new_int(LEFT), true);
		vm_reg_var(vm, className, "RIGHT", var_new_int(RIGHT), true);
		vm_reg_var(vm, className, "ENTER", var_new_int(ENTER), true);
		vm_reg_var(vm, className, "BACK", var_new_int(BACK), true);
	}
};

#endif
