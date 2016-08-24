#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long *input;
	int n;
	while(1)
	{
		scanf("%d", &n);
		input = new long long[n];
		if(n==0)
			break;
		long long myNegative = -1;
		long long myPositive = -1;
		for(int i=0;i<n;i++)
		{
			scanf("%lld", &input[i]);
			if(input[i]>0 && myPositive==-1)
				myPositive = i;
			if(input[i]<0 && myNegative==-1)
				myNegative = i;
		}
		long long answer = 0;
		while(myNegative<n && myPositive<n)
		{
			if(abs(input[myNegative])<=input[myPositive])
			{
				// need a new seller
				answer += abs(input[myNegative])*(abs(myNegative-myPositive));
				input[myPositive] -= abs(input[myNegative]);
				myNegative++;
				while(input[myNegative]>0 && myNegative<n)
					myNegative++;			
			}
			else
			{
				//need a new buyer
				answer += input[myPositive]*(abs(myNegative-myPositive));
				input[myNegative] += input[myPositive];
				myPositive++;
				while(input[myPositive]<0 && myPositive<n)
					myPositive++;
			}
		}
		printf("%lld\n", answer);
		delete []input;
	}
}