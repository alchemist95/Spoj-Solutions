#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, N;
	int first[1001], second[1001];
	cin>>t;
	while(t--)
	{
		cin>>N;
		int indexMax=0;
		for(int i=0;i<N;i++)
		{
			cin>>first[i]>>second[i];
			if(first[i]>first[indexMax])
				indexMax = i;
		}
		int flag=0;
		for(int i=0;i<N;i++)
		{
			if(i!=indexMax)
			{
				if(second[i]>first[indexMax])
					flag = 55;
			}
		}
		if(flag==55)
			cout<<"-1"<<endl;
		else
			cout<<indexMax+1<<endl;
	}
}