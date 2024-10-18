#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << "swapped a and b!\n"<< "a = " << a << ", b = " << b << std::endl;
	std::cout << "minimum( a, b ) = " << ::minimum( a, b ) << std::endl;
	std::cout << "maximum( a, b ) = " << ::maximum( a, b ) << std::endl;
	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	//std::string d = "chaine";

	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "swapped c and d!\n"<< "c = " << c << ", d = " << d << std::endl;
	std::cout << "minimum( c, d ) = " << ::minimum( c, d ) << std::endl;
	std::cout << "maximum( c, d ) = " << ::maximum( c, d ) << std::endl;
	std::cout << std::endl;

	float e = 5.5f;
	float f = 20.7f;

	std::cout << "e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << "swapped e and f!\n"<< "e = " << e << ", f = " << f << std::endl;
	std::cout << "minimum( e, f ) = " << ::minimum( e, f ) << std::endl;
	std::cout << "maximum( e, f ) = " << ::maximum( e, f ) << std::endl;
	std::cout << std::endl;

	void *g = &a;
	void *h = &b;

	std::cout << "g = " << g << ", h = " << h << std::endl;
	::swap(g, h);
	std::cout << "swapped g and f!\n"<< "g = " << g << ", h = " << h << std::endl;
	std::cout << "minimum( g, h ) = " << ::minimum( g, h ) << std::endl;
	std::cout << "maximum( g, h ) = " << ::maximum( g, h ) << std::endl;
}