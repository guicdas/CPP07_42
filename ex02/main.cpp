#include "Array.hpp"

int main( void ) {
	std::srand(std::time(0));
	int				arraySize = 20;

	Array<int>		normalArray(arraySize);
	Array<void *>	voidArray(arraySize);
	Array<float>	floatArray(arraySize);
	Array<int>		emptyArray;

	std::cout << "TEST 1 - empty array" << std::endl;
	std::cout << "Empty array size:\t" << emptyArray.size() << "\n\n";
	try
	{
		std::cout << emptyArray[0] << std::endl;
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}

	std::cout << "TEST 2 - Exception catch" << std::endl;
	try
	{
		for (int i = 0; i < 21; i++)
		{
			voidArray[i] = reinterpret_cast<void *> (std::rand() % 100 + 1);
			floatArray[i] = static_cast<float> (std::rand() % 100 + 1) + 0.2f;
			normalArray[i] = std::rand() % 100 + 1;
			std::cout << i << "\t: " << normalArray[i] << "\t" << voidArray[i] << "\t" << floatArray[i] << std::endl;
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}

	std::cout << "TEST 3 - Copy array" << std::endl;
	Array<int> copyArray(normalArray);
	try
	{
		std::cout << "ORIGINAL COPY" << std::endl;
		for (int i = 0; i < 21; i++)
		{
			std::cout << normalArray[i] << "\t " << copyArray[i] << std::endl;
			if (normalArray[i] != copyArray[i])
				std::cerr << "Error: Array doesn't have the same values as the original one!" << std::endl;
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
	
	std::cout << "ORIGINAL COPY" << std::endl;
	std::cout << normalArray[6] << "\t " << copyArray[6] << std::endl;
	copyArray[6] = 123123;
	std::cout << "changed 5th value" << std::endl;
	std::cout << normalArray[6] << "\t " << copyArray[6] << std::endl;

	Array<int> copyArray2 = emptyArray;
	return (0);
}
