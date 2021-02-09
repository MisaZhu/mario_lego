# mario_natives

Extra LEGO EV3 natives for mario js, related to mario_js project.

.build: 

	apt install gcc-arm-linux-gnueabi
	export CROSS_COMPILE=arm-none-linux-gnueabi-
	export MARIO_VM=<mario source path>
	
	then recompile the whole project.
