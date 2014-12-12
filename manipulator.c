/* Contains all the code for the manipulator. These functions will be called by 607_main
*/
int spinning=0; // -1 backwards, 0 stopped, 1 forwards
int hookVal; //current position of the hook servo
bool doorOpen=false; //stores the current value of the door servo
int openDoor=0; //the servo value when the door is open
int closedDoor=0; //the servo value when the door is closed
void lift(int rpower, int lpower){ //function to power the lift motors
	motor[rightLift]=rpower; //the right motor is set to the given right power
 	motor[leftLift]=lpower; //the left motor is set to the given left power
}

void toggleSpinning(int direction){
	spinning=direction; //sets the spinning variable to the given direction from 607
}
void spin(){//function to spin the motor that captures balls
	if(spinning==1)// if the direction is positive
		motor[spinner]=100;//then turn it forward
	else if(spinning==-1)//if the direction is negative
		motor[spinner]=-100;//turn the motor backwards
	else motor[spinner]=0; //otherwise turn it off
}
void hookGrab(int change){//given the smaller joystick value
	hookVal=hookVal+change; //set the new servo position to the original plus the modifier
	motor[hook]=hookVal; //set the servo to the new position
}

void toggleDoor(){ //toggles the door between open and closed
	doorOpen=!doorOpen; //sets the boolean to whatever it currently isn't
	if(doorOpen) //then if it's true
		motor[door]=openDoor; //set the door to open
	else motor[door]=closedDoor; //otherwise it's false and the door will be set to closed
}
