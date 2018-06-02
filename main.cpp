#include <AFMotor.h>
//#include <iostream>
//#include <string>
#include "ClassList.h"
#include "Function.h"
AF_DCMotor motor1(1);
AF_DCMotor motor4(4);

int val;



using namespace std;

void setup() {
	Serial.begin(9600);           // set up Serial library at 9600 bps
	Serial.println("Motor test!");

	motor1.setSpeed(200);
	motor4.setSpeed(200);
	motor1.run(RELEASE);
	motor4.run(RELEASE);

}

void loop()
{
	List<char> forward;
	List<char> back;
	List<char> left;
	List<char> right;
	List<char> stp;

	forward.push_back('8');
	back.push_back('2');
	left.push_back('4');
	right.push_back('6');
	stp.push_back('0');

	uint8_t i = 250;
	if (Serial.available())
	{
		val = Serial.read();


		if (containe(forward, val))  // forward
		{
			//Serial.println("Motor 8 test!");

			motor1.run(FORWARD);
			motor4.run(FORWARD);
			motor4.setSpeed(i);
			motor1.setSpeed(i);
		}

		if (containe(back, val)) // backward
		{
			//Serial.println("Motor 2 test!");

			motor1.run(BACKWARD);
			motor4.run(BACKWARD);
			motor4.setSpeed(i);
			motor1.setSpeed(i);
		}

		if (containe(left, val)) // left
		{
			//Serial.println("Motor 4 test!");

			motor4.run(RELEASE);
			motor1.run(FORWARD);
			motor1.setSpeed(i);
		}

		if (containe(right, val)) //right
		{
			//  Serial.println("Motor 6 test!");

			motor1.run(RELEASE);
			motor4.run(FORWARD);
			motor4.setSpeed(i);
		}

		if (containe(stp, val)) { // stop 

								  //Serial.print("RELEASE\n");
			motor4.run(RELEASE);
			motor1.run(RELEASE);

		}
	}
}