#ifndef JSM_JSColorSensor
#define JSM_JSColorSensor

#include "mario.h"

class JSColorSensor {
	static var_t* constructor(vm_t* vm, var_t* env, void *);
	static var_t* color(vm_t* vm, var_t* env, void *);
	static var_t* rgb(vm_t* vm, var_t* env, void *);
	static var_t* ambientLight(vm_t* vm, var_t* env, void *);
	static var_t* reflectedLight(vm_t* vm, var_t* env, void *);
	static var_t* connected(vm_t* vm, var_t* env, void *);

public:
	inline static void regNative(vm_t* vm, const char* clsname) {
		var_t* cls = vm_new_class(vm, clsname);
		//   - 0: No color
		//   - 1: Black
		//   - 2: Blue
		//   - 3: Green
		//   - 4: Yellow
		//   - 5: Red
		//   - 6: White
		//   - 7: Brown
		vm_reg_var(vm, cls, "NoColor", var_new_int(vm, 0), true);
		vm_reg_var(vm, cls, "Black", var_new_int(vm, 1), true);
		vm_reg_var(vm, cls, "Blue", var_new_int(vm, 2), true);
		vm_reg_var(vm, cls, "Green", var_new_int(vm, 3), true);
		vm_reg_var(vm, cls, "Yellow", var_new_int(vm, 4), true);
		vm_reg_var(vm, cls, "Red", var_new_int(vm, 5), true);
		vm_reg_var(vm, cls, "White", var_new_int(vm, 6), true);
		vm_reg_var(vm, cls, "Brown", var_new_int(vm, 7), true);

		vm_reg_native(vm, cls, "constructor(port)", constructor, NULL);
		vm_reg_native(vm, cls, "ambientLight()", ambientLight, NULL);
		vm_reg_native(vm, cls, "color()", color, NULL);
		vm_reg_native(vm, cls, "rgb()", rgb, NULL);
		vm_reg_native(vm, cls, "reflectedLight()", reflectedLight, NULL);
		vm_reg_native(vm, cls, "connected()", connected, NULL);
	}
};

#endif
