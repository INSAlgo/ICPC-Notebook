// return a%b 
int mod(int a, int b)
{
	return ((a%b)+b)%b;
}

// computes gcd(a,b)
int gcd(int a, int b)
{
	int tmp;
	while(b)
	{
		a %= b;
		tmp = a;
		a = b;
		b = tmp;
	}
	return a;
}

// computes lcm(a,b)
int lcm(int a, int b)
{
	return a/gcd(a,b)*b;
}