#include "Iter.hpp"

void	fAdd(int &number) {
	number += 2;
}

void	fToupper(char &c) {
	if (c > 96)
		c -= 48;
}

void	fRound(float &f) {
	f = round(f);
}

int main( void ) {
	int		a[] = {1, 2, 3, 4};
	char	b[] = {'a', 'b', 'c', 'd'};
	float	c[] = {1.2f, 2.2f, 3.2f, 4.2f};

	for (int i = 0; i < 4 ; i++)
		std::cout << "a[" << i << "] = "<< a[i] << std::endl;
	std::cout << "iter -> adding 2..." << std::endl;
	::iter( a, 4, fAdd );
	for (int i = 0; i < 4 ; i++)
		std::cout << "a[" << i << "] = "<< a[i] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4 ; i++)
		std::cout << "b[" << i << "] = "<< b[i] << std::endl; 
	std::cout << "iter: To upper..." << std::endl;
	::iter( b, 4, fToupper );
	for (int i = 0; i < 4 ; i++)
		std::cout << "b[" << i << "] = "<< b[i] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4 ; i++)
		std::cout << "c[" << i << "] = "<< c[i] << std::endl;
	std::cout << "iter: rounding..." << std::endl;
	::iter( c, 4, fRound );
	for (int i = 0; i < 4 ; i++)
		std::cout << "c[" << i << "] = "<< c[i] << std::endl;
	return (0);
}