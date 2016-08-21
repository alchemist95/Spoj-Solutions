#include <bits/stdc++.h>
using namespace std;

long long

long long gcd(long long a, long long b)
{
	if(a==0)
		return b;
	gcd(b%a, a);
}

long long lcm(long long a, long long b)
{
	return a*b/gcd(a,b);
}

void myFunction()
{
	long long sum = 0;
	for(int i=1;i<100000;i++)
	{
		sum+=lcm()
	}
}

int main()
{

}

