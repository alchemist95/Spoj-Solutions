#include <stdio.h>
#include <cmath>
int main()
{
	int myNumber = 0;
	int divisors[1000];
	int p;
	int dOfN[1000001] = {0};
	for(int i=1;i<=1000000;i++)
	{
		p = 0;
		dOfN[i] += 2;
		float square = sqrt(float(i));
		for(int j=i/2;j>sqrt(i);j--)
		{
			if(i%j==0)
			{
				divisors[p++] = j;
				divisors[p++] = i/j;
				dOfN[i] +=2;
			}
		}
		if(square == int(square))
		{
			dOfN[i]++;
			divisors[p++] = sqrt(i);
		}
		if(dOfN[i]>3)
		{
			int flag = 0;
			for(int k=0;k<p;k++)
			{
				if(dOfN[i]%dOfN[divisors[k]])
				{
					flag = 55;
					break;
				}
			}
			if(flag == 0)
			{
				myNumber++;
				if(myNumber%108==0)
					printf("%d\n", i);
			}
		}	
	}
}