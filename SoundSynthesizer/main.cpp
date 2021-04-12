/*
main.cpp
*/

#include <iostream>
#include <vector>

#include "noiseMaker.h"

atomic<double> dFrequencyOutput = 0.;

// dTime represents the time passed since the start of the program
double makeNoise(double dTime) {

	// amplitude (0.5) times sin of frequency (440) times dTime 
	// the 2 * pi converts the hertz to angular velocity (required because sin doesn't 'understand' hertz)
	double dOutput = sin(dFrequencyOutput * 2. * 3.14159 * dTime);

	// makes it a square wave
	if (dOutput > 0.)
		return .008;
	else
		return -.008;

	return dOutput;
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

	double dOctaveBaseFrequency = 110.; // A2
	double d12thRootOf2 = pow(2., 1. / 12.);

	while (true) {

		bool bKeyPressed = false;
		for (int k = 0; k < 15; k++) {

			if (GetAsyncKeyState((unsigned char)("ZSXCFVGBNJMK\xbcL\xbe"[k])) && 0x8000) {

				dFrequencyOutput = dOctaveBaseFrequency * pow(d12thRootOf2, k);
				bKeyPressed = true;
			}
		}

		if (!bKeyPressed)
			dFrequencyOutput = 0.;
	}

	return 0;
}