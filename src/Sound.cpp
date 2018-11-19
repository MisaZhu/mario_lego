#include "Sound.h"
#include "ev3dev.h"

using namespace ev3dev;

var_t* JSSound::speak(vm_t* vm, var_t *env, void *) {
	std::string words = get_str(env, "words");
	sound::speak(words, true);
	return NULL;
}

