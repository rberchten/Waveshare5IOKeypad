// Waveshare 5Io Keypad
//  10 Buttons
//  1  Joystick
// written by AMOSMarin (c) 2016 Rene Berchten
#if (ARDUINO >= 100)
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "IO5Keypad.h"

/*
// Arduino-Pins
byte _KeyIo_1 = 9;
byte _KeyIo_2 = 10;
byte _KeyIo_3 = 11;
byte _KeyIo_4 = 12;
byte _KeyIo_5 = 13;
*/

IO5KeyPad::IO5KeyPad(
	int KeyIo_1=9,
	int KeyIo_2=10,
	int KeyIo_3=11,
	int KeyIo_4=12,
	int KeyIo_5=13)
{   
    _prevKey = 0;
	_KeyIo_1 = KeyIo_1;
	_KeyIo_2 = KeyIo_2;
	_KeyIo_3 = KeyIo_3;
	_KeyIo_4 = KeyIo_4;
	_KeyIo_5 = KeyIo_5;
	// KeyPress-Detection
	pinMode(_KeyIo_1, INPUT);
	pinMode(_KeyIo_2, INPUT);
	pinMode(_KeyIo_3, INPUT);
	pinMode(_KeyIo_4, INPUT);
	pinMode(_KeyIo_5, INPUT);
}

int IO5KeyPad::GetKeyChanged()
{
	int result = GetKey();
	if (_prevKey != result) 
	{
		_prevKey = result;
		return result;
	}	
	else
	{
		return 0;
	}
}

int IO5KeyPad::GetKey()
{
	int result = GetJoystickKey();
	if (result == 0)
	{
		result = GetKeyboardKey();
	}
	return result;
}

int IO5KeyPad::GetKeyboardKey()
{
	int result = 0;
	if (pinPairToggleState(_KeyIo_1, _KeyIo_2) == 1)   // Key 1
	{
		result = Key01;
	}
	else if (pinPairToggleState(_KeyIo_1, _KeyIo_3) == 1)   // Key 2
	{
		result = Key02;
	}
	else if (pinPairToggleState(_KeyIo_1, _KeyIo_4) == 1)   // Key 3
	{
		result = Key03;
	}
	else if (pinPairToggleState(_KeyIo_1, _KeyIo_5) == 1)   // Key 4
	{
		result = Key04;
	}
	else if (pinPairToggleState(_KeyIo_2, _KeyIo_3) == 1)   // Key 5
	{
		result = Key05;
	}
	else if (pinPairToggleState(_KeyIo_2, _KeyIo_4) == 1)   // Key 6
	{
		result = Key06;
	}
	else if (pinPairToggleState(_KeyIo_2, _KeyIo_5) == 1)   // Key 7
	{
		result = Key07;
	}
	else if (pinPairToggleState(_KeyIo_3, _KeyIo_4) == 1)   // Key 8
	{
		result = Key08;
	}
	else if (pinPairToggleState(_KeyIo_3, _KeyIo_5) == 1)   // Key 9
	{
		result = Key09;
	}
	else if (pinPairToggleState(_KeyIo_4, _KeyIo_5) == 1)   // Key 10
	{
		result = Key10;
	}
	return result;
}

int IO5KeyPad::pinPairToggleState(int pinNoOut, int pinNoIn)
{
	int countSameState = 0;
	int result = 0;
	pinMode(pinNoOut, OUTPUT);
	for (int x = 0; x < 5; x++)
	{
		digitalWrite(pinNoOut, LOW);
		if (digitalRead(pinNoIn) == LOW)
		{
			digitalWrite(pinNoOut, HIGH);
			if (digitalRead(pinNoIn) == HIGH)
			{
				countSameState++;
				delay(10);
			}
		}
	}

	pinMode(pinNoOut, INPUT);
	if (countSameState > 3)
	{
		result = 1;
	}
	return result;
}

int IO5KeyPad::GetJoystickKey()
{
	int result = 0;
	if (pinStateLow(_KeyIo_1) == 1)
	{
		result = JoystickLeft;
	}
	else if (pinStateLow(_KeyIo_2) == 1)
	{
		result = JoystickUp;
	}
	else if (pinStateLow(_KeyIo_3) == 1)
	{
		result = JoystickOK;
	}
	else if (pinStateLow(_KeyIo_4) == 1)
	{
		result = JoystickDown;
	}
	else if (pinStateLow(_KeyIo_5) == 1)
	{
		result = JoystickRight;
	}
	return result;
}

int IO5KeyPad::pinStateLow(int pinNo)
{
	int countLow = 0;
	int result = 0;
	for (int x = 0; x < 5; x++)
	{
		if (digitalRead(pinNo) == 0)
		{
			countLow++;
			delay(10);
		}
	}
	if (countLow > 3)
	{
		result = 1;
	}
	return result;
}

