/* Contains all the code for the manipulator. These functions will be called by 607_main
*/
int spinning=0; // -1 backwards, 0 stopped, 1 forwards
int hookVal; //current position of the hook servo
void lift(int power){ //function to power the lift motors
	motor[rightLift]=power;
	motor[leftLift]=power;
}
void toggleSpinning(int direction){
	spinning=direction;
}
void spin(){//function to spin the motor that captures balls
	if(spinning==1)// if the direction is positive
		motor[spinner]=100;//then turn it forward
	else if(spinning==-1)//if the direction is negative
		motor[spinner]=-100;//turn the motor backwards
	else spinning=0; //otherwise turn it off
}

void hookGrab(int change){//given the smaller joystick value
	hookVal=hookVal+change; //set the new servo position to the original plus the modifier
	motor[hook]=hookVal; //set the servo to the new position
}
