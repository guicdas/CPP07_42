#include "Array.hpp"

void	test1( void ){
	std::srand(std::time(0));

	//Array<void> Arr1;
	Array<int> emptyArray;
	std::cout << "Empty array size:\t" << emptyArray.size() << "\n\n";
	try
	{
		std::cout << emptyArray[0] << std::endl;
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
}

void	test2( Array<int>  &normalArray ){
	try
	{
		for (int i = 0; i < 21; i++)
		{
			normalArray[i] = rand() % 100 + 1;
			std::cout << i << "\t: " << normalArray[i] << std::endl;
		}
	}
	catch(const std::exception& e){std::cerr << e.what() << std::endl;}
}

void	test3( Array<int>  &normalArray ){
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
}

int main( void ) {
	Array<int> normalArray(20);
	//Array<float> copyArray(normalArray);
	//std::cout << "test 1 - empty array" << std::endl;test1();
	//std::cout << "test 2 - Exception catch" << std::endl;
	test2(normalArray);			//copy?
	//std::cout << "test 3 - Copy array" << std::endl;test3(normalArray);

	return (0);
}
