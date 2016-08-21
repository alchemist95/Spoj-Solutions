#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long students[100001];
	long long candy[100001];
	while(1)
	{
		cin>>n;
		if(n==0)
			break;
		for(int i=0;i<n;i++)
			cin>>students[i];
		for(int i=0;i<n;i++)
			cin>>candy[i];
		sort(students,students+n);
		sort(candy,candy+n);
		long long sum = 0;
		int p = 0;
		for(int i=n-1;i>=0;i--)
		{
			sum += students[i]*candy[p];
			p++;
		}
		cout<<sum<<endl;
	}
		
}