#include <bits/stdc++.h>
using namespace std;

int isPrime(int a)
{
	for(int i=2;i<=sqrt(a);i++)
	{
		if(a%i==0)
			return 0;
	}
	return 1;
}

int transmute(int b, int myFlag, int replacement)
{
	int O,T,H,tH;
	O =  b%10;
	b/=10;
	T = b%10;
	b/=10;
	H = b%10;
	b/=10;
	tH=b;
	if(myFlag == 1)
		return (tH*1000 + H*100 + T*10 + replacement);
	else if(myFlag == 2)
		return (tH*1000 + H*100 + replacement*10 + O);
	else if(myFlag == 3)
		return (tH*1000 + replacement*100 + T*10 + O);
	else
		return (replacement*1000 +  H*100 + T*10 + O);
}



int main()
{
	vector<int> myPrimes;
	for(int i=1000;i<=9999;i++)
	{
		if(isPrime(i))
			myPrimes.push_back(i);
	}	
	int t, left, right, level;
	cin>>t;
	while(t--)
	{
		cin>>left>>right;
		queue < pair<int, int> > myQueue;
		myQueue.push(make_pair(left,0));
		int visited[10000] = {0};
		visited[left] = 1;
		int flag, transmuted;
		flag = 0;
		while(!myQueue.empty())
		{
			left = myQueue.front().first;
			level = myQueue.front().second;
			myQueue.pop();

			if(left == right)
			{
				flag = 1;
				break;
			}

			for(int i=0;i<=9;i++)
			{
				if(i>0)
				{	
					transmuted = transmute(left, 4, i);
					if(visited[transmuted]!=1 && isPrime(transmuted))
					{
						visited[transmuted] = 1;
						myQueue.push(make_pair(transmuted, level+1));
					}
				}

				transmuted = transmute(left, 3, i);
				if(visited[transmuted]!=1 && isPrime(transmuted))
				{
					visited[transmuted] = 1;
					myQueue.push(make_pair(transmuted, level+1));
				}				

				transmuted = transmute(left, 2, i);
				if(visited[transmuted]!=1 && isPrime(transmuted))
				{
					visited[transmuted] = 1;
					myQueue.push(make_pair(transmuted, level+1));
				}				

				transmuted = transmute(left, 1, i);
				if(visited[transmuted]!=1 && isPrime(transmuted))
				{
					visited[transmuted] = 1;
					myQueue.push(make_pair(transmuted, level+1));
				}				
			}	
		}
		if(flag == 1)
			cout<<level<<endl;
		else
			cout<<"Impossible"<<endl;
	}
}