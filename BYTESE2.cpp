#include <bits/stdc++.h>
using namespace std;

int main()
{
	int first[101];
	int second[101];
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>first[i]>>second[i];
		}
		sort(first, first+n);
		sort(second, second+n);
		int max=1;
		int people = 1;
		int pointF = 1, pointS = 0;

		while(pointF!=n && pointS!=n)
		{
			if(first[pointF]<=second[pointS])
			{
				people++;
				pointF++;
			}
			else
			{
				people--;
				pointS++;
			}
			if(people>max)
				max = people;
		}
		cout<<max<<endl;
	}
}