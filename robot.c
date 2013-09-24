int bound (int max1, int input1, int min1)
{
// our input is too high
	if (input1 > max1)
	{
		return max1;

// our input is too low
	}else if (input1 < min1)
	{
		return min1;

//our input is within bounds
	}else
	{
		return input1;
	}
}

int parabolic(int readJoy, int gain, int maxval)
{
	int parabolicValue;

	//Algorithm:
	//parabolicValue = ((((gain * readJoy) / 100)^2)*(1/maxval));

	parabolicValue = ((gain * readJoy) / 100);
	parabolicValue = (parabolicValue * parabolicValue);
	parabolicValue = (parabolicValue/maxval);

	// Adjust the sign (if readoy is a negative)
	if (readJoy < 0) {
		parabolicValue *=-1;
	}

	return(parabolicValue);
}


void rotateBody()
{
	int readJoy_x;				// will hold the X value of the analog stick
	int joy_x;					// will hold the X value after being applied to the parabolic scale
	int gain_x = 63;			//change this when you change max/min Motor Speed
	int maxMotorSpeed = 80;

	readJoy_x = vexRT[Ch4];   // This is the LEFT analog stick.  For RIGHT, change 'Ch4' to 'Ch1'.

	joy_x = parabolic(readJoy_x, gain_x, maxMotorSpeed);

	motor[bodyRotateMotor]  = bound(maxMotorSpeed, (joy_x), (0 - minMotorSpeed));

}



task main ()
{
	init();
	while(true)         // infinite loop, to keep the program alive
	{
		rotateBody();
		arm();
		rotateClaw();
		toggleClaw();
	}
}