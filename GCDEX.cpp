/*

	1)

	Using Euler totient function to obtain sum of gcd(1,2)....gcd(1,n) + gcd(2,3)....gcd(2,n) +.......+ gcd(n-1,n) easily
	Didnt quite understand the concept

*/



#include <bits/stdc++.h>
using namespace std;

long long totient[1000001];
long long myResult[1000001];
long long myAnswer[1000001];

void preSolve()
{
	long long i,j;
	for(int i=1;i<1000001;i++)
		totient[i] = i;

	// Obtaining Euler Totient
	for(i=2;i<1000001;i++)
	{
		if(totient[i] == i)
		{
			for(j=i;j<1000001;j+=i)
			{
				totient[j] /= i;
				totient[j]*=i-1;
			}
		}
	}

	for(i=1;i<1000001;i++)
	{
		for(j=i;j<1000001;j+=i)
			myResult[j] = myResult[j] + (i*totient[j/i]);
	}

	for(i=1;i<1000001;i++)
		myResult[i] -=i;
	myAnswer[0] = 0;

	for(i=1;i<1000001;i++)
		myAnswer[i] = myAnswer[i-1]+myResult[i];
}


int main()
{
	preSolve();
	long long N,G, i, j;
	while(1)
	{
		scanf("%lld", &N);
		if (N==0)
			break;
		printf("%lld\n", myAnswer[N]);
	}
}