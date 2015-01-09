#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     leftDrive,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightDrive,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     topLeft,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     bottomLeft,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     bottomRight,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_2,     topRight,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S3_C1_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     arm,           tmotorTetrix, openLoop)
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
		if(joystick.joy1_y1>10) //if the left, driver joystick is positive
			leftPower=joystick.joy1_y1; //set the power for the left motor to the joystick value-- It will be positive
		else if(joystick.joy1_y1<-10) //or if the left, driver joystick is negative
			leftPower=joystick.joy1_y1; //set the power for the left motor to the joystick value--It will be negative
		else leftPower=0; //Otherwise the power will be 0
		//Threshold for Right Motor
		if(joystick.joy1_y2>10) //if the right, driver joystick is positive
			rightPower=joystick.joy1_y2; //set the power for the right motor to the joystick value--It will be positive
		else if(joystick.joy1_y2<-10) //or if the right, driver joystick is positive
			rightPower=joystick.joy1_y2; //set the power for the right motor to the joystick value--It will be negative
		else rightPower=0; //Otherwise the power will be 0
		drive(leftPower,rightPower); //calls the drive function located in chassi.The two arguments are the left and right joystick positions which are assigned in the above code
		if(joy2Btn(5))
			rotate(-50);
		else if(joy2Btn(6))
			rotate(30);
		else rotate(0);
		//Threshold and Individual Control of the lift
		if(joystick.joy2_y1>10)
				lift(joystick.joy2_y1);
		else if(joystick.joy2_y1<-10)
				lift(joystick.joy2_y1);
	 else lift(0);
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
		loopmain();
		//motor[topLeft] = joystick.joy1_y1;
		//motor[topRight] = joystick.joy1_y2;

	}

}
