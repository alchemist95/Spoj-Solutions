#include <bits/stdc++.h>
using namespace std;

int main()
{
	int integerInput[1000];
	int multipliedInput[1000];
	string answer;
	char input[1000];
	while(scanf("%s", input)!=EOF)
	{

		answer = "";
		int size = strlen(input);
		if(strlen(input)==1 && input[0]=='1')
		{
			cout<<"1"<<endl;
			continue;
		}

		int p = 0;
		for(int i=size-1;i>=0;i--)
		{
			integerInput[p++] = input[i] - '0';
		}
		int product;
		int carry = 0;
		for(int i=0;i<size;i++)
		{
			product = integerInput[i]*2 + carry;
			if(product>9)
				carry = product/10;
			else
				carry = 0;
			multipliedInput[i] = product%10;
		}
		if(carry!=0)
		{
			multipliedInput[size] = carry;
			size++;
		}
		
		int tobeSubracted = 2;
		for(int i=0;i<size;i++)
		{
			if(multipliedInput[i]>=tobeSubracted)
			{
				multipliedInput[i]-=tobeSubracted;
				break;
			}
			else
			{
				multipliedInput[i] = multipliedInput[i] + 10 - tobeSubracted;
				tobeSubracted = 1;
			}
		}

		for(int i=size-1;i>=0;i--)
		{
			if(i==size-1 && multipliedInput[i]==0)
				continue;
			cout<<multipliedInput[i];
		}
		cout<<endl;
	}

}