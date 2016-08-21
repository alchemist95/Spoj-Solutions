// things to learn
/*
	1)

	only perfect squares have odd number of factors
	d(n) for 25 can be obtained by running loop from 2 to sqrt(5) and not 5
	how??
		instead of multiplying by (power+1) for each specific prime factor, multiply by (2*power)+1

	2)

	Using sequential storage to enable binary search on non-uniform data and keeping track of starting index of each successive index

*/




#include <bits/stdc++.h>
using namespace std;

vector<long long> mySequentialStorage;
long long Divisors[100001];
int Count[1500];
int startIndex[1500];

long long myFunction(long long A)
{
	long long i,answer = 1;
	long long count = 0;
	int k = 0;
	for(i=2;i*i<=A;i++)
	{
			count = 0;
		while(A%i == 0)
		{
			count++;
			A = A/i;
		}	
		answer *=2*count+1;
	}
	if(A!=1)
		answer*=3;

	return answer;
}

void preSolve()
{
	memset(Count, 0, sizeof(Count));
	long long i,j,k,max;
	Divisors[1] = 1;
	max = 0;
	for(i=2;i<100000;i++)
	{
		Divisors[i] = myFunction(i);			
		Count[Divisors[i]]++;
	}
	int p;

	for(k=1,p=0;k<=1323;k+=2)
	{
		startIndex[k] = p;
		if(!Count[k])
			continue;
		for(i=2;i<100000;i++)
		{
			if(Divisors[i] == k)
			{
					mySequentialStorage.push_back(i*i);
					p++;
			}
		}
	}
	startIndex[k] = p;
}

int main()
{
	preSolve();
	long long K, left, right, myleft, myright;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %lld %lld", &K, &left, &right);
		int low = lower_bound(mySequentialStorage.begin()+startIndex[K], mySequentialStorage.begin()+startIndex[K+2],left) - mySequentialStorage.begin();
		int high = upper_bound(mySequentialStorage.begin()+startIndex[K], mySequentialStorage.begin()+startIndex[K+2], right) - mySequentialStorage.begin();
		printf("%d\n", high-low);
	}
}