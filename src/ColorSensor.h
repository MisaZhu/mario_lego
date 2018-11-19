#ifndef JSM_JSColorSensor
#define JSM_JSColorSensor

#include "mario_vm.h"

class JSColorSensor {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* color(vm_t* vm, var_t* env, void *);
	static var_t* rgb(vm_t* vm, var_t* env, void *);
	static var_t* ambientLight(vm_t* vm, var_t* env, void *);
	static var_t* reflectedLight(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* className) {
		//   - 0: No color
		//   - 1: Black
		//   - 2: Blue
		//   - 3: Green
		//   - 4: Yellow
		//   - 5: Red
		//   - 6: White
		//   - 7: Brown
		vm_reg_var(vm, className, "NoColor", var_new_int(0), true);
		vm_reg_var(vm, className, "Black", var_new_int(1), true);
		vm_reg_var(vm, className, "Blue", var_new_int(2), true);
		vm_reg_var(vm, className, "Green", var_new_int(3), true);
		vm_reg_var(vm, className, "Yellow", var_new_int(4), true);
		vm_reg_var(vm, className, "Red", var_new_int(5), true);
		vm_reg_var(vm, className, "White", var_new_int(6), true);
		vm_reg_var(vm, className, "Brown", var_new_int(7), true);

		vm_reg_native(vm, className, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, className, "ambientLight()", ambientLight, NULL);
		vm_reg_native(vm, className, "color()", color, NULL);
		vm_reg_native(vm, className, "rgb()", rgb, NULL);
		vm_reg_native(vm, className, "reflectedLight()", reflectedLight, NULL);
		vm_reg_native(vm, className, "connected()", connected, NULL);
	}
};

#endif
