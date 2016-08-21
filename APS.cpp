#include <bits/stdc++.h>
using namespace std;

long long mySieve[10000000] = {0};
long long myAPS[10000000];
int main()
{
	int i,j;
	for(i=2;i<10000;i++)
	{
		for(j=2*i;j<10000000;j+=i)
		{
			if(mySieve[j]==0)
				mySieve[j] = i;
		}
	}

	myAPS[1] = myAPS[0] = 0;
	for(i=2;i<10000000;i++)
	{
		if(mySieve[i]==0)
			myAPS[i] = myAPS[i-1] + i;
		else
			myAPS[i] = myAPS[i-1] + mySieve[i];
	}
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<myAPS[n]<<endl;
	}

}