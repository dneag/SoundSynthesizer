/*
	main.cpp 
*/

#include <iostream>
#include <vector>

#include "noiseMaker.h"

// dTime represents the time passed since the start of the program
double makeNoise(double dTime) {
	
	// amplitude (0.5) times sin of frequency (440 - an A) times dTime 
	// the 2 * pi converts the hertz to angular velocity (required because sin doesn't 'understand' hertz)
	double dOutput = 1.0 * sin(440. * 2. * 3.14159 * dTime);

	// makes a square wave
	if (dOutput > 0.)
		return 0.008;
	else
		return -0.008;
}

int main()
{
	// get all sound hardware
	std::vector<std::wstring> devices = olcNoiseMaker<short>::Enumerate();

	// display findings
	for (auto d : devices)
		std::wcout << "Found Output Device:" << d << std::endl;

	// create sound machine
	olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

	// link noise function with sound machine
	sound.SetUserFunction(makeNoise);

	while (true) {


	}

	return 0;
} 