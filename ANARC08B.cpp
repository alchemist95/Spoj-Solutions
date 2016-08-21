#include <bits/stdc++.h>
using namespace std;

int myFunction(string input)
{
	if(input=="063")
		return 0;
	else if(input== "010")
		return 1;
	else if(input== "093")
	return 2;
	else if(input== "079")
		return 3;
	else if(input== "106")
		return 4;
	else if(input== "103")
		return 5;
	else if(input== "119")
		return 6;
	else if(input== "011")
		return 7;
	else if(input== "127")
		return 8;
	else
		return 9;
}

string getString(int a)
{
	if(a == 0)
		return "063";
	else if(a==1)
		return "010";
	else if(a==2)
		return "093";
	else if(a==3)
		return "079";
	else if(a==4)
		return "106";
	else if(a==5)
		return "103";
	else if(a==6)
		return "119";
	else if(a==7)
		return "011";
	else if(a==8)
		return "127";
	else
		return "107";
}


int main()
{
	int h,g;
	string input;
	while(1)
	{
		cin>>input;
		if(input=="BYE")
			break;
		int flag = 0,p = 0;
		g = 0;
		h =0;
		p=0;
		for(int i=input.length()-2;i>=0;i--)
		{
			if(input[i] == '+')
			{
				flag=55;
				p=0;
				i--;
			}

			if(flag==0)
			{
				g = pow(10,p)*myFunction(input.substr(i-2, 3))+g;
				p++;
				i-=2;
			}
			else
			{
				h = pow(10,p)*myFunction(input.substr(i-2,3))+h;
				p++;
				i-=2;
			}
		}
		h = h+g;
		string answer;
		if(h==0)
			answer = "063";
		while(h>0)
		{
			answer = getString(h%10) + answer;
			h = h/10;
		}

		cout<<input<<answer<<endl;
		answer.clear();
	}
}