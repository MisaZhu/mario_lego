#include "Port.h"
#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;
using namespace std;

static void _destroyPort(void* p) {
	lego_port* port = (lego_port*)p;
	if(port == NULL)
		return;
	delete port;
}

#define GET_PORT lego_port* port = (lego_port*)get_raw(env, THIS); \
	if(port == NULL)\
		return NULL;

var_t* JSPort::constructor(vm_t* vm, var_t *env, void *) {
	int port = get_int(env, "port");
	string ePort = JSPorts::getEV3Port(port);
	lego_port* p = new lego_port(ePort);
	
	var_t* thisV = var_new_obj(p, _destroyPort);
	var_from_prototype(thisV, get_obj(env, THIS));
	return thisV;
}

var_t* JSPort::address(vm_t* vm, var_t *env, void *) {
	GET_PORT
	string r = "";
	if(port->connected())
		r = port->address();
	return var_new_str(r.c_str());
}

var_t* JSPort::mode(vm_t* vm, var_t *env, void *) {
	GET_PORT
	string r = "";
	if(port->connected())
		r = port->mode();
	return var_new_str(r.c_str());
}

var_t* JSPort::driverName(vm_t* vm, var_t *env, void *) {
	GET_PORT
	string r = "";
	if(port->connected())
		r = port->driver_name();
	return var_new_str(r.c_str());
}

var_t* JSPort::status(vm_t* vm, var_t *env, void *) {
	GET_PORT
	string r = "";
	if(port->connected())
		r = port->status();
	return var_new_str(r.c_str());
}

var_t* JSPort::setMode(vm_t* vm, var_t *env, void *) {
	string mode = get_str(env, "mode");
	GET_PORT
	if(port->connected())
		port->set_mode(mode);
	var_t* thisV = get_obj(env, THIS);
	return thisV;
}

var_t* JSPort::setSetDevice(vm_t* vm, var_t *env, void *) {
	string dev = get_str(env, "dev");
	GET_PORT
	if(port->connected())
		port->set_set_device(dev);
	var_t* thisV = get_obj(env, THIS);
	return thisV;
}

var_t* JSPort::modes(vm_t* vm, var_t *env, void *) {
	GET_PORT
	mode_set r;
	if(port->connected())
		r = port->modes();

	var_t* v = var_new_array();
	for(std::set<std::string>::iterator it=r.begin(); it!=r.end(); ++it) {
		string i = *it;
		var_add(v, "", var_new_str(i.c_str()));
	}
	return v;
}

var_t* JSPort::connected(vm_t* vm, var_t *env, void *) {
	GET_PORT
	int res = port->connected()?1:0;
	return var_new_int(res);
}
