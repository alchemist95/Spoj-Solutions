#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,p=1;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		long long matrix[n][n];
		long long Debit[n];
		for(int i=0;i<n;i++)
			Debit[i] = 0;
		long long sumOfRows = 0;
		long long initial = 0;
		for(int i=0;i<n;i++)
		{
			sumOfRows = 0;
			for(int j=0;j<n;j++)
			{
				scanf("%lld", &matrix[i][j]);
				sumOfRows +=matrix[i][j];
				Debit[j] -= matrix[i][j];
			}
			initial +=sumOfRows;
			Debit[i] += sumOfRows;
		}
		long long answer = 0;
		for(int i=0;i<n;i++)
		{
			if(Debit[i]>0)
				answer +=Debit[i];
		}
		printf("%d. %lld %lld\n", p,initial,answer);
		p++;
	}
}