#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	if(a==0)
		return b;
	return gcd(b%a, a);
}
int main()
{
	long long N, K, dummy;
	long long possibleCom, totalCom, removed, numTerms;
	while(1)
	{
		cin>>N>>K;
		if(N==-1 && K==-1)
			break;
		totalCom = (N*(N-1))/2;
		possibleCom = 0;
		removed = 0;
		numTerms = 0;	
		// place for time limit 
		if(K>2)
		{
			if(K%2)
			{
				numTerms = (K-3)/2 + 1;
				removed = numTerms*((K+1)/2); 
			}
			else 
			{
				numTerms = (K-4)/2 + 1;
				removed = numTerms*(K/2);
			}
		}
		possibleCom = (numTerms*K)-removed;

 		if(possibleCom == 0)
 			cout<<"0"<<endl;
 		else if(possibleCom == totalCom)
 			cout<<"1"<<endl;
 		else
 		{

 			long long nextDummy = possibleCom;
 			while(gcd(possibleCom, totalCom)!=1)
 			{
 				long long GCD = gcd(possibleCom, totalCom);
 				possibleCom = possibleCom/GCD;
 				totalCom = totalCom/GCD;
 			}
 			cout<<possibleCom<<"/"<<totalCom<<endl;
 		}
	}
}