int sleepTime=3000;//time it takes to drive down the ramp in millseconds
int power=50; //power to drive the chassi motors
void downRamp(){
	 drive(power,power); //runs the motor in 607_chassi
	Sleep(sleepTime);//sleeps so the motor can remain on
	drive(0,0); //turns the motor off
}
