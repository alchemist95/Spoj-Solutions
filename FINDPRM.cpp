#include <bits/stdc++.h>
using namespace std;

bool prime[10000001];
int khata[10000001];
void Sieve()
{
	
	memset(prime, true, sizeof(prime));

	for(int i=2;i*i<=10000000;i++)
	{
		if(prime[i] == true)
		{
			for(int j=i*2;j<=10000000;j+=i)
			{
				prime[j] = false;
			}
		}
	}

}



void myMunshi()
{
	khata[1] = 0;
	khata[2] = 1;
	int count = 1;
	for(int i=3;i<=10000000;i++)
	{
		if(prime[i] == true)
			count++;
		khata[i] = count;
	}
}



int myFun(int a, int end)
{
	int count = 0;
	if(prime[a] == true)
		return khata[end] - khata[a] + 1;
	else
		return khata[end] - khata[a];
}

int main()
{
	int t, n;
	Sieve();
	myMunshi();
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int myStart = n/2 + 1;
		int answer = myFun(myStart, n);
		printf("%d\n", answer);
	}
}
