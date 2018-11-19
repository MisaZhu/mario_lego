#include "Ports.h"
#include "ev3dev.h"

using namespace ev3dev;

std::string JSPorts::getEV3Port(int port) {
	switch(port) {
		case OUT_AUTO:
			return OUTPUT_AUTO;
		case OUT_A:
			return OUTPUT_A;
		case OUT_B:
			return OUTPUT_B;
		case OUT_C:
			return OUTPUT_C;
		case OUT_D:
			return OUTPUT_D;
		case IN_1:
			return INPUT_1;
		case IN_2:
			return INPUT_2;
		case IN_3:
			return INPUT_3;
		case IN_4:
			return INPUT_4;
		case IN_AUTO:
			return INPUT_AUTO;
	}
	return "";
}

