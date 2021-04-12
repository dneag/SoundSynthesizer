/*
	main.cpp 
*/

#include <iostream>
#include <vector>

#include "noiseMaker.h"

// dTime represents the time passed since the start of the program
double makeNoise(double dTime) {
	
	// amplitude (0.5) times sin of frequency (440) times dTime 
	// the 2 * pi converts the hertz to angular velocity (required because sin doesn't 'understand' hertz)
	return 0.5 * sin(440.0 * 2. * 3.14159 * dTime);
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

	return 0;
} 