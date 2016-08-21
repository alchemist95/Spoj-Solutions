#include <bits/stdc++.h>
using namespace std;

#define MAX 100000001

double Answer[MAX];
unsigned prime[MAX>>6] = {0};
#define ifComp(x) (prime[x>>6]&(1<<((x>>1)&31)))
#define isComp(x) (prime[x>>6]|=(1<<((x>>1)&31)))

void Sieve()
{
	int i,j,k;
	for(i=3;i<=10000;i+=2)
	{
		if(!ifComp(i))
		{
			for(j=i*i,k=i<<1;j<MAX;j+=k)
				isComp(j);
		}
	}	

	Answer[2] =1;
	for(i=3;i<MAX;i++)
	{
		if(i%2==1 && !ifComp(i))
		{
			Answer[i] = Answer[i-1]+1;
		}
		else
			Answer[i] = Answer[i-1];
	}
}
int main()
{
	Sieve();
	int x;
	while(1)
	{
		scanf("%d", &x);			
		if(x==0)
			break;
		double myX = x;
		myX = myX/log(x);
		double myAnswer = abs(Answer[x]-myX)/double(Answer[x]);
		myAnswer = 100*myAnswer;
		printf("%.1lf\n", myAnswer);
	}
}