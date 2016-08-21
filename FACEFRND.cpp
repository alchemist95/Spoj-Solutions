#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,g,m;
	int myfriend[10000] = {0};
	int others[10000] = {0};
	cin>>n;
	while(n--)
	{
		cin>>g;
		myfriend[g] = 	1;
		cin>>m;
		while(m--)
		{
			cin>>g;
			others[g] = 1;
		}
	}

	int count =0;
	for(int i=0;i<=9999;i++)
	{
		if(others[i]==1 && myfriend[i]==0)
			count++;
	}
	cout<<count<<endl;

}