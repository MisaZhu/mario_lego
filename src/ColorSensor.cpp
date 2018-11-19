#include "ColorSensor.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

static void _destroyColor(void* p) {
	color_sensor* m = (color_sensor*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_COLOR color_sensor* color = (color_sensor*)get_raw(env, THIS); \
	if(color == NULL)\
		return NULL;

var_t* JSColorSensor::constructor(vm_t* vm, var_t* env, void *) {
	int port = get_int(env, "port");
	std::string ePort = JSPorts::getEV3Port(port);
	color_sensor* m = new color_sensor(ePort);
	
	var_t* thisV = var_new_obj(m, _destroyColor);
	var_t* protoV = get_obj(env, PROTOTYPE);
  var_add(thisV, PROTOTYPE, protoV);
	return thisV;
}

var_t* JSColorSensor::ambientLight(vm_t* vm, var_t* env, void *) {
	GET_COLOR
	int r = 0;
	if(color->connected())
		r = color->ambient_light_intensity();
	return var_new_int(r);
}

var_t* JSColorSensor::reflectedLight(vm_t* vm, var_t* env, void *) {
	GET_COLOR
	int r = 0;
	if(color->connected())
		r = color->reflected_light_intensity();
	return var_new_int(r);
}

var_t* JSColorSensor::color(vm_t* vm, var_t* env, void *) {
	GET_COLOR
	int r = 0;
	if(color->connected())
		r = color->color();
	return var_new_int(r);
}

var_t* JSColorSensor::rgb(vm_t* vm, var_t* env, void *) {
	GET_COLOR
	std::tuple<int, int, int> r;
	if(color->connected())
		r = color->raw();
	var_t* v = var_new();
	var_add(v, "r", var_new_int(std::get<0>(r)));
	var_add(v, "g", var_new_int(std::get<1>(r)));
	var_add(v, "b", var_new_int(std::get<2>(r)));
	
	return v;
}

var_t* JSColorSensor::connected(vm_t* vm, var_t* env, void *) {
	GET_COLOR
	return var_new_int(color->connected()?1:0);
}
