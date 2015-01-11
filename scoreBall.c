int sleepTimer=2000;//time it takes to raise and lower the lift
void scoreBall(){
	lift(100);//turn the lift on
	Sleep(sleepTimer); //keep the lift on
	lift(0); //turn the lift off
	//raises arm
	//waits
	//drops arm
	lift(-100); //lower the lift
	Sleep(sleepTimer); //keep it on
	lift(0); //turn it off and it is now lowered
}
