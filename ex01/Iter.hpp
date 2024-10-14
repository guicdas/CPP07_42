#pragma once

#include <iostream>
#include <cmath>

/*
template < typename T >
void	function(T & number) {
	number + 2;
}*/


template < typename Tarray, typename Tfunc>
void	iter(Tarray *aAddr, int aLength, Tfunc aFunction) {
	for (int i = 0; i < aLength; i++)
		aFunction(aAddr[i]);
}
