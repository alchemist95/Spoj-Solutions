#include <bits/stdc++.h>
using namespace std;

long long sum(long long a)
{
	return (a*(a+1))/2;
}

int main()
{
	long long a,b;
	cin>>a>>b;
	long long remaining = 0;
	if(a%2 && b%2)
	{
		remaining = a;
		a++;
	}
	else if(a%2 && b%2==0)
	{
		remaining = a;
		a++;
		b--;
	}
	else if(a%2==0 && b%2==0)
		b--;
	long long mySum = sum(b) - sum(a-1);
	long long length = b-a+1;
	long long sum2 = mySum - length/2;
	sum2 = sum2/2;
	sum2 = sum2 + length/2;
	sum2 +=remaining;
	cout<<sum2<<endl;
}