#include <bits/stdc++.h>
using namespace std;

#define MAX 100000001

vector<long long> myPrimes;
unsigned prime[MAX>>6] = {0};
#define ifComp(x) (prime[x>>6]&(1<<((x>>1)&31)))
#define isComp(x) (prime[x>>6]|=(1<<((x>>1)&31)))

struct Power{
	long long prime;
	long long power;
};


void Sieve()
{
	int i,j,k;
	for(i=3;i<=10000;i+=2)
	{
		if(!ifComp(i))
		{
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isComp(j);
		}
	}	
	
	for(i=2;i<MAX;i++)
	{
		if(!ifComp(i))
		{
			myPrimes.push_back(i);
		}
	}
}

void myFunction(long long N)
{
	long long temp = N;
	for(int i=0;i<myPrimes.size(), myPrimes[i]*myPrimes[i]<=temp ;i++)
	{
		if(temp%myPrimes[i] == 0)
		{
			long long count = 0;
			printf("%lld", myPrimes[i]);
			while(temp%myPrimes[i] == 0)
			{
				temp/=myPrimes[i];
				count++;
			}
			printf("^%lld ", count);
		}
	}
	if(temp!=1)
	{
		printf("%lld^1", temp);
	}
	printf("\n");
}
int main()
{
	long long N;
	Sieve();
	while(1)
	{
		scanf("%lld", &N);
		if(N == 0)
			break;
		myFunction(N);
	}
}