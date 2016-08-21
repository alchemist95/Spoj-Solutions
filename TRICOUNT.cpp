#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	long long n, answer;
	cin>>t;
	while(t--)
	{
		cin>>n;
		answer = n*(n+2)*(2*n+1)/8;
		cout<<answer<<endl;
	}
}