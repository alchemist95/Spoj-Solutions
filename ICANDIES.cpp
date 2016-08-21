#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	int n;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int N = n;		
		while(N>0)
		{
			N-=5;
			if(N%3==0)
				break;
		}
		cout<<"Case "<<i<<": ";		
		if(N<0)
			cout<<"-1"<<endl;
		else
			cout<<N<<endl;
	}
}
