Sound.speak("Hello, Lego EV3 JS world");
/*
let port = new Port(Ports.OUT_A);
let motor = new Motor(Ports.OUT_A);
	motor.setTime(1000).setSpeed(100).runTimed();
	System.sleep(3);
 */

let _quit = false;

Button.onEvent = function(event) {
	dump(event);
	if(event.value != InputEvent.PRESSED)
		return;

	if(event.code == InputEvent.BACK) 
		_quit = true;
	else if(event.code == InputEvent.RIGHT)
		Sound.speak("right");
	else if(event.code == InputEvent.LEFT)
		Sound.speak("left");
	else if(event.code == InputEvent.UP)
		Sound.speak("up");
	else if(event.code == InputEvent.DOWN)
		Sound.speak("down");
};

let remote = new Remote(1);
remote.onEvent = function(button, state) {
	dump(button);
};

Button.run();

while(!_quit) {
	remote.process();
	yield();
}

