#include <bits/stdc++.h>
using namespace std;

#define PRIMELIMIT 1000000

vector<int> myPrimes;
bool prime[1009];

void Sieve()
{
	for(int i=3;i*i<=1000;i+=2)
	{
		if(!prime[i])
		{
			for(int j=i*i;j<=1000;j+=i)
			{
				prime[j] = 1;
			}
		}
	}
	myPrimes.push_back(2);
	for(int i=3;i<=1000	;i+=2)
	{
		if(!prime[i])
			myPrimes.push_back(i);
	}
}


bool isPrime(int n){
    if(n == 1)
        return false;
    for(int i = 2 ; i*i <= n ; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
	Sieve();
	int myNumber = 0;
	int myVar;
	for(int i=1;i<=PRIMELIMIT;i++)
	{
		int temp = i;
		int product = 1;
		int k=0;
		for(int j=myPrimes[k];k<myPrimes.size() && j*j<=temp;j=myPrimes[++k])
		{
			int power = 0;
			while(temp%j==0)
			{
				power++;
				temp/=j;
			}
			product *= (power+1);
		}
		if(temp!=1)
			product*=2;
		k=0;
		for(int j=myPrimes[k];k<myPrimes.size() && j*j<=product;j=myPrimes[++k])
		{
			if(product%j == 0)
			{
				myVar = product/j;
				if(myVar!=j && isPrime(myVar))
				{
					myNumber++;
					if(myNumber%9==0)
					{
						printf("%d\n", i);
					}
					break;
				}
			}
		}

	}
return 0;
}		