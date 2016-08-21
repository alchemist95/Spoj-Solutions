#include <bits/stdc++.h>
using namespace std;

int myFun(int a)
{
	float result = a;
	if(a%2==0)
	{
		while(a%2==0)
			a/=2;
		result*=(1.0-(1.0/float(2)));
	}
	for(int i=3;i*i<=a;i+=2)
	{
		if(a%i==0)
		{
			while(a%i==0)
				a/= i;	
			result*=(1.0-(1.0/float(i)));
		}

	}
	if(a>1)
		result*=(1.0-(1.0/float(a)));
	return int(result);
}

int main()
{
	int t,n;
	int answers[1000001];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%d\n", myFun(n));
	}
}