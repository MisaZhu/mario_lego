#include "Infrared.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;
using namespace std;

static void _destroyInfrared(void* p) {
	infrared_sensor* m = (infrared_sensor*)p;
	if(m == NULL)
		return;
	delete m;
}

#define GET_INFRARED infrared_sensor* infrared = (infrared_sensor*)get_raw(env, THIS); \
	if(infrared == NULL)\
		return NULL;

var_t* JSInfrared::constructor(vm_t* vm, var_t* env, void *) {
	int port = get_int(env, "port");
	string ePort = JSPorts::getEV3Port(port);
	infrared_sensor* m = new infrared_sensor(ePort);
	if(m->connected())
		m->set_mode(infrared_sensor::mode_ir_prox);
	
	var_t* thisV = var_new_obj(vm, m, _destroyInfrared);
	var_from_prototype(thisV, get_obj(env, THIS));
	return thisV;
}

var_t* JSInfrared::proximity(vm_t* vm, var_t* env, void *) {
	GET_INFRARED
	float f = 0.0;
	if(infrared->connected())
		f = infrared->proximity(false);
	return var_new_float(vm, f);
}

var_t* JSInfrared::connected(vm_t* vm, var_t* env, void *) {
	GET_INFRARED
	int res = infrared->connected()?1:0;
	return var_new_int(vm, res);
}
