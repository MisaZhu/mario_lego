#include "mario_vm.h"
#include "Ports.h"
#include "Port.h"
#include "Sound.h"
#include "Motor.h"
#include "DCMotor.h"
#include "ServoMotor.h"
#include "Infrared.h"
#include "Ultrasonic.h"
#include "Button.h"
#include "InputEvent.h"
#include "Remote.h"
#include "Touch.h"
#include "Gyro.h"
#include "ColorSensor.h"

#ifdef __cplusplus /* __cplusplus */
extern "C" {
#endif

void reg_natives(vm_t* vm) {
	JSPorts::regNative(vm, "Ports");
	JSPort::regNative(vm, "Port");
	JSSound::regNative(vm, "Sound");
	JSMotor::regNative(vm, "Motor");
	JSServoMotor::regNative(vm, "ServoMotor");
	JSDCMotor::regNative(vm, "DCMotor");
	JSInfrared::regNative(vm, "Infrared");
	JSUltrasonic::regNative(vm, "Ultrasonic");
	JSButton::regNative(vm, "Button");
	JSRemote::regNative(vm, "Remote");
	JSInputEvent::regNative(vm, "InputEvent");
	JSTouch::regNative(vm, "Touch");
	JSGyro::regNative(vm, "Gyro");
	JSColorSensor::regNative(vm, "ColorSensor");
}

#ifdef __cplusplus /* __cplusplus */
}
#endif
