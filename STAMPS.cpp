#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,t;
	int input[1000001];
	int n, Rey;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>Rey>>n;
		for(i=0;i<n;i++)
		{
			cin>>input[i];
		}
		sort(input, input+n);
		int sum = 0;
		int p = 0;
		for(i=n-1;i>=0;i--)
		{
			sum+=input[i];
			p++;
			if(sum>=Rey)
				break;
		}
		cout<<"Scenario #"<<j<<":"<<endl;
		if(i==-1)
			cout<<"impossible"<<endl;
		else
			cout<<p<<endl;
		cout<<endl;
	}
}