// Stanford Notebook
#include <vector>
#include "ExtendedEuclid.h"

// find all solutions to ax = b (mod n)
vector<int> modular_linear_equation_solver(int a, int b, int n)
{
	int x,y;
	vector<int> sol;
	int d = extended_euclid(a, n, x, y);
	if(!(b%d)) {
		x = mod(x%(b/d), n);
		for(int i=0; i < d; ++i)
			sol.push_back(mod(x + i*(n/d),n));
	}
	return sol;
}

// computes b such tath ab = 1(mod n), returs -1 on failure
int mod_inverse(int a, int n)
{
	int x, y;
	int d = extended_euclid(a, n, x, y);
	if(d>1) return -1;
	return mod(x,n);
}

// computes x and y such that ax + by =c; on failure, x = y =-1
void linear_diophantine(int a,int b, int c,int &x, int &y)
{
	int d = gcd(a,b);
	if(c%d) x = y = -1;
	else 
	{
		x = c/d * mod_inverse(a/d,b/d);
		y = (c-a*x)/b;
	}
}