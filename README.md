# mario_natives

Extra LEGO EV3 natives for mario js, related to https://github.com/misazhu/mario_vm.git project.

.build: 

	apt install gcc-arm-linux-gnueabi g++-arm-linux-gnueabi
	export CROSS_COMPILE=arm-none-linux-gnueabi-
	export MARIO_VM=<mario source path>
	
	then recompile the whole project.
