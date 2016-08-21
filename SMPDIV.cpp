#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		int m = x;
		while(m<n)
		{
			if(m%y!=0)
				cout<<m<<" ";
			m+=x;
		}
		cout<<endl;
	}
}