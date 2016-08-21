#include <bits/stdc++.h>
using namespace std;


int reV(int a)
{
	int sum = 0;
	while(a>0)
	{
		sum = sum*10+a%10;
		a = a/10;
	}
	return sum;
}

int main()
{
	int n, left, right;
	cin>>n;
	while(n--)
	{
		cin>>left>>right;
		left = reV(left);
		right = reV(right);
		left = left+right;
		left = reV(left);
		cout<<left<<endl;
	}
}