#include "GcdLcm.h"

// returns d = gcd(a,b); find x, y such that d = ax + by
int extended_euclid(int a, int b, int &x, int &y){
	int current_x = y = 0;
	int current_y = x = 1;
	while(b)
	{
		int q = a/b;
		int t = b;
		b = a%b;
		a = t;
		t = current_x; current_x = x-q*current_x; x = t;
		t = current_y; current_y = y-q*current_y; y = t; 
	}
	return a;
}