/* Contains all the code for the manipulator. These functions will be called by 607_main
*/
bool spinning=false;//true if the spinner is spinning
void lift(int power){ //function to power the lift motors
	motor[rightLift]=power;
	motor[leftLift]=power;
}

void toggleSpinner(){//toggles the spinning boolean
	spinning=!spinning;
}
void spin(){//function to spin the motor that captures balls
	if(spinning)// if the boolean is true
		motor[spinner]=100;// then spin the motor
	else motor[spinner]=0;// otherwise turn the motor off
}
