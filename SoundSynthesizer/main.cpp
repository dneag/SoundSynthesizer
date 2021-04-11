/*
	main.cpp 
*/

#include <iostream>
#include <vector>

#include "noiseMaker.h"

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