#include <bits/stdc++.h>
using namespace std;

vector<int> myPrimes;
int sheet[1000001];
int bigSheet[1000001][11];
void Sieve(int n)
{
	bool prime[n+1];

	memset(prime, true, sizeof(prime));

	for(int i=2;i*i<=n;i++)
	{
		if(prime[i] == true)
		{
			for(int j=i*2;j<=n;j+=i)
			{
				prime[j] = false;
			}
		}
	}

	for(int i=2;i<=n;i++)
	{
		if(prime[i])
		{
			myPrimes.push_back(i);
			sheet[i] = 1;
		}
	}	
}

void myFunction()
{
	memset(bigSheet, 0, sizeof(bigSheet));
	for(int i=1;i<=1000000;i++)
	{
		int temp = i;
		int k = 0;
		int count = 0;
		for(int j=myPrimes[k];j*j<=temp && k<myPrimes.size();j = myPrimes[k++])
		{
			if(temp%j == 0)
			{
				count++;
				while(temp%j == 0)
					temp/= j;
			}
		}
		if(temp!=1)
			count++;
		sheet[i] = count;
	}
	bigSheet[1][0] = 1;
	for(int i=2;i<=1000000;i++)
	{
		for(int j=0;j<=10;j++)
		{
			bigSheet[i][j] = bigSheet[i-1][j];
		}
		bigSheet[i][sheet[i]]++;
	}

}

int main()
{
	Sieve(1000000);
	int t, left, right, n;
	myFunction();
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &left, &right, &n);
		int answer = bigSheet[right][n] - bigSheet[left-1][n];
		printf("%d\n", answer);
	}

}

