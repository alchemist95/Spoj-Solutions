#include <stdio.h>
#include <math.h>
int main()
{
	int myNumber = 0;
	int divisors[1000];
	int i,j,k,p;
	int dOfN[1000001] = {0};
	for(i=1;i<=1000000;i++)
	{
		p = 0;
		dOfN[i] += 2;
		float square = sqrt((float)i);
		for(j=i/2;j>square;j--)
		{
			if(i%j==0)
			{
				divisors[p++] = j;
				divisors[p++] = i/j;
				dOfN[i] +=2;
			}
		}
		if(square == (int)square)
		{
			dOfN[i]++;
			divisors[p++] = sqrt(i);
		}
		if(dOfN[i]>3)
		{
			int flag = 0;
			for(k=0;k<p;k++)
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
	return 0;
}