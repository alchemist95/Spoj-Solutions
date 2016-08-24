#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int answer = 0;
	for(int i=1;i<=n;i++)
	{
		answer++;
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
				answer++;
		}
	}
	cout<<answer<<endl;
}