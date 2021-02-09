#ifndef JSM_JSInputEvent
#define JSM_JSInputEvent

#include "mario.h"


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
		var_t* cls = vm_new_class(vm, className);
		vm_reg_var(vm, cls, "KEY", var_new_int(vm, KEY), true);
		vm_reg_var(vm, cls, "PRESSED", var_new_int(vm, PRESSED), true);
		vm_reg_var(vm, cls, "RELEASED", var_new_int(vm, RELEASED), true);
		vm_reg_var(vm, cls, "UP", var_new_int(vm, UP), true);
		vm_reg_var(vm, cls, "DOWN", var_new_int(vm, DOWN), true);
		vm_reg_var(vm, cls, "LEFT", var_new_int(vm, LEFT), true);
		vm_reg_var(vm, cls, "RIGHT", var_new_int(vm, RIGHT), true);
		vm_reg_var(vm, cls, "ENTER", var_new_int(vm, ENTER), true);
		vm_reg_var(vm, cls, "BACK", var_new_int(vm, BACK), true);
	}
};

#endif
