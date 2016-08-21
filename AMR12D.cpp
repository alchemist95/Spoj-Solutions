#include <bits/stdc++.h>
using namespace std;
int main()
{
	string input;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>input;
		int flag=0;
		for(int i=0;i<input.length()/2;i++)
		{
			if(input[i]!=input[input.length()-i-1])
				flag=55;
		}
		if(flag==55)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
}