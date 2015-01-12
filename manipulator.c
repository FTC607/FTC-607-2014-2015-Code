/* Contains all the code for the manipulator. These functions will be called by 607_main
*/
int spinning=0; // -1 backwards, 0 stopped, 1 forwards
bool doorOpen=false;
void lift(int power){ //function to power the lift motors
	motor[bottomRight]=power;
	motor[bottomLeft]=power;
	motor[topRight]=power;
	motor[topLeft]=power;
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
void rotate(int speed){
	motor[arm]=speed;
}
void toggleDoor(){
	doorOpen=!doorOpen;
	if(doorOpen)
			servo[door]=128;
	else servo[door]=0;
}
