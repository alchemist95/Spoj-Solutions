		#include <bits/stdc++.h>
		using namespace std;

		bool prime[1000001];
		long long Prime[100001];
		void Sieve()
		{
			memset(prime, true, sizeof(prime));

			for(int i=2;i*i<=1000000;i++)
			{
				if(prime[i] == true)
				{
					for(int j=i*2;j<=1000000;j+=i)
					{
						prime[j] = false;
					}
				}
			}
			int count = 0;
			for(long long i=2;i<=150000;i++)
			{
				if(prime[i] == true)
				{
					Prime[count] = i;
					count++;
				}
			}


		}

		int main()
		{
			int t, i;
			long long N, K;
			Sieve();
			long long answer;
			scanf("%d",&t);
			while(t--)
			{
				scanf("%lld %lld", &N, &K);
				if (K==0)
					answer = ((N-1)*N)/2;
				else
				{
 					i = K-1;
 					answer = 0;
 					while(Prime[i] <= N)
 					{
 						answer += N-Prime[i]+1;
 						if(Prime[i+1] <= N)
 						{
 							answer += (Prime[i-K+2] - Prime[i-K+1] - 1) * (N - Prime[i+1] + 1);
 							i++;
 						}
 						else
 							break;
 					}
				}
				printf("%lld\n", answer);
			}
		}
