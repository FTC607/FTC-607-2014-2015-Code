/* Contains all of the robot's base movement code.
The functions in here will be called by 607_main to move the robot.*/
void drive(int lpower, int rpower)
{
		motor[leftDrive]=lpower; //sets the left motor to the power given by the 607_main
		motor[rightDrive]=rpower; //sets the right motor to the power given by the 607_main
}
