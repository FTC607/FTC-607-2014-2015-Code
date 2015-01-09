#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     leftDrive,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightDrive,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     topLeft,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     bottomLeft,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     bottomRight,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_2,     topRight,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     arm,           tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "chassi.c"
#include "manipulator.c"
int leftPower; //used to keep the power of the left drive motor
int rightPower; //used to keep the power of the right drive motor


void loopmain()
{
		getJoystickSettings(joystick); //gets the positions of all of the joysticks and buttons
		//Threshold for Left Motor
		if(abs(joystick.joy1_y1)>10) //if the left joystick's magnitude is greater than 10
			leftPower=joystick.joy1_y1; //set the power for the left motor to the joystick value
		else leftPower=0; //Otherwise the power will be 0
		//Threshold for Right Motor
		if(abs(joystick.joy1_y2)>10) //if the right joystick's magnitude is greater than 10
			rightPower=joystick.joy1_y2; //set the power for the right motor to the joystick value
		else rightPower=0; //Otherwise the power will be 0
		drive(leftPower,rightPower); //calls the drive function located in chassi.The two arguments are the left and right joystick positions which are assigned in the above code
		//Threshold and Individual Control of the lift
<<<<<<< HEAD
		if(joystick.joy2_y1>10)
				//lift(joystick.joy2_y1);
		if(joystick.joy2_y2<-10)
				//lift(joystick.joy2_y1);
	 lift(5);
=======
		if(joy2Btn(7)) //if the manipulator driver hits the top right trigger
			lift(50,0); //call lift in manipulator. The right side will be forward and the left side will be off
		else if(joy2Btn(5)) //or if the manipulator driver hits the bottom right trigger
			lift(-50,0); //call lift in manipulator. The right side will be negative and the left side will be off
		else if(joy2Btn(8)) //or if the manipualtor driver hits the top left trigger
			lift(0,50); //call lift in manipulator. The right side will be off and the left side will be positive
		else if(joy2Btn(6)) //or if the manipulator driver hits the bottom left trigge
			lift(0,-50); //call lift in manipulator. The right side will be off and the left side will be negative
		else if(joystick.joy2_y1>10) //or if the manipulator's left joystick is forward
			lift(100,100); // calls the lift method in manipulator and have the lift go up
		else if(joystick.joy2_y1<-10) //or if the manipulator's left joystick is negative
				lift(-100,-100); //calls the lift method in manipulator and have the lift go down
		else lift(0,0); //if none of the above happen, the lift is off
>>>>>>> origin/master
		if(joy2Btn(1)){ //turns the spinner on and off with the one button
			toggleSpinning(-1); //calls toggleSpinning in 607_manipulator with negative direction
		}
		else if(joy2Btn(2)){ //turns the spinner off
			toggleSpinning(0); //calls toggleSpinning in 607_manipulator with zero speed
		}
		else if(joy2Btn(3)){ //turns the spinnner forward
			toggleSpinning(1); //calls the toggleSpinning in 607_manipulator with positive direction
		}
		spin(); //calls the spin function in 607_manipulator
}


task main()
{
	while(true)
	{
		//loopmain();
		motor[topLeft] = joystick.joy1_y1;
		motor[topRight] = joystick.joy1_y2;

	}

}
