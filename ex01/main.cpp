#include "Iter.hpp"

int main( void ) {
	int		a[] = {1, 2, 3, 4};
	char	b[] = {'a', 'b', 'c', 'd'};
	float	c[] = {1.2f, 2.2f, 3.7f, 4.2f};

	for (int i = 0; i < 4 ; i++)
		std::cout << "a[" << i << "] = "<< a[i] << std::endl;
	std::cout << "iter -> adding 2..." << std::endl;
	::iter( a, 4, fAdd<int> );
	for (int i = 0; i < 4 ; i++)
		std::cout << "a[" << i << "] = "<< a[i] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4 ; i++)
		std::cout << "b[" << i << "] = "<< b[i] << std::endl; 
	std::cout << "iter -> adding 2..." << std::endl;
	::iter( b, 4, fAdd<char> );
	for (int i = 0; i < 4 ; i++)
		std::cout << "b[" << i << "] = "<< b[i] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4 ; i++)
		std::cout << "c[" << i << "] = "<< c[i] << std::endl;
	std::cout << "iter -> adding 2..." << std::endl;
	::iter( c, 4, fAdd<float> );
	for (int i = 0; i < 4 ; i++)
		std::cout << "c[" << i << "] = "<< c[i] << std::endl;
	return (0);
}