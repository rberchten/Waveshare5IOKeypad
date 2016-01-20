// 5IOKeypad.h

#ifndef _IO5KEYPAD_h
#define _IO5KEYPAD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


// Result-Value Key pressed
#define Key01  1
#define Key02  2
#define Key03  3
#define Key04  4
#define Key05  5
#define Key06  6
#define Key07  7
#define Key08  8
#define Key09  9
#define Key10  10

#define JoystickUp    11
#define JoystickDown  12
#define JoystickLeft  13
#define JoystickRight 14
#define JoystickOK    15



class IO5KeyPad
{
public:
	IO5KeyPad(
		int KeyIo_1,
		int KeyIo_2,
		int KeyIo_3,
		int KeyIo_4,
		int KeyIo_5
		);
	int GetKey();
	int GetKeyChanged();
private:
	// letzter gültiger Key
    int _prevKey = 0;
	// Arduino-Pins
	byte _KeyIo_1 = 9;
	byte _KeyIo_2 = 10;
	byte _KeyIo_3 = 11;
	byte _KeyIo_4 = 12;
	byte _KeyIo_5 = 13;	// SubFunktion scan Key pressed
	// ----------------------------
	// Darf nur ausgefèhrt werden, wenn an allen
	// IO-Pins kein LOW anliegt
	int GetKeyboardKey();
	// SubFunktion festellen Pin StateChanges (Prellen unterdrücken)
	int pinPairToggleState(int pinNoOut, int pinNoIn);
	// SubFunktion Joystick-State
	int GetJoystickKey();
	// SubFunktion festellen Pin State (Prellen unterdrècken)
	int pinStateLow(int pinNo);
};

#endif