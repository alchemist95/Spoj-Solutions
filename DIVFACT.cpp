#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<long long> getMeMyPrimes(long long n)
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
	vector<long long> myVec;
	for(int i=2;i<=n;i++)
	{
		if(prime[i])
			myVec.push_back(i);
	}
	return myVec;
}

vector<long long> getMeMyPowers(vector<long long> primes, int n)
{
	int inAction;
	int keepCount;
	vector<long long> powers;
	for(int i=0;i<primes.size();i++)
	{
		inAction = primes[i];
		keepCount = 0;
		while((n/inAction) >= 1)
		{
			keepCount += n/inAction;
			inAction *=primes[i];
		}
		powers.push_back(keepCount);
	}
	return powers;
}

int main()
{
	int t,n;
	long long answer;
	vector<long long> myPrimes;
	vector<long long> myPowers;
	cin>>t;
	while(t--)
	{
		cin>>n;
		myPrimes = getMeMyPrimes(n);
		myPowers = getMeMyPowers(myPrimes, n);
		answer = 1;
		for(int i=0;i<myPowers.size();i++)
		{
			answer = ((myPowers[i]+1)*answer)%MOD;
		}
		cout<<answer<<endl;
	}
}