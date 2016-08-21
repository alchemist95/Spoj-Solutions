#include <bits/stdc++.h>
using namespace std;

int main()
{
	int countOfdivisibility[10000] = {0};
	int LuckyNumber[1001];
	int i,j;
	for(i=2;i<10000;i++)
	{
		if(countOfdivisibility[i]==0)
		{
			for(j=2*i;j<10000;j+=i)
				countOfdivisibility[j]++;
		}
	}

	for(i=30,j=1;i<10000,j<1001;i++)
	{
		if(countOfdivisibility[i]>=3)
			LuckyNumber[j++] = i;
	}

	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<LuckyNumber[n]<<endl;
	}

}