#include <bits/stdc++.h>
using namespace std;

int main()
{
	for(int i=6;i<=100;i++)
	{
		for(int l=2;l<=100;l++)
		{
			for(int k=l+1;k<=100;k++)
			{
				for(int p=k+1;p<=100;p++)
				{
					if(i*i*i == l*l*l + k*k*k + p*p*p)
						cout<<"Cube = "<<i<<", Triple = ("<<l<<","<<k<<","<<p<<")"<<endl;
				}
			}
		}
	}
}