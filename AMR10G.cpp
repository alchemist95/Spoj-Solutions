#include <bits/stdc++.h>
using namespace std;

int main()
{
	int input[20005];
	int t,n,k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		for(int i=0;i<n;i++)
			scanf("%d", &input[i]);
		sort(input, input+n);
		int min = INT_MAX;
		for(int i=0;i<=n-k;i++)
		{
			if(input[i+k-1] - input[i] < min)
				min = input[i+k-1] - input[i];
		}
		printf("%d\n", min);
	}
}	