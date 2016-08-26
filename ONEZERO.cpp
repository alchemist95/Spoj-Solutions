#include <bits/stdc++.h>
using namespace std;

	
void solve(int n)
{
	int parent[20005];
	for(int i=0;i<=20000;i++)
		parent[i] = -1;	
	int value[20005] = {0};
	queue<int> myQueue;
	myQueue.push(1);
	parent[1] = 0;	
	int temp,myCurState;

	while(!myQueue.empty())
	{
		myCurState = myQueue.front();
		myQueue.pop();

		if(myCurState == 0)
		{
			// time to print the answer
			stack<int> s;
			while(parent[myCurState])
			{
				s.push(value[myCurState]);
				myCurState = parent[myCurState];
			}
			s.push(1);
			while(!s.empty())
			{
				printf("%d", s.top());
				s.pop();
			}
			printf("\n");
			break;
		}

		temp = (myCurState*10)%n;
		if(parent[temp] == -1)
		{
			myQueue.push(temp);
			parent[temp] = myCurState;
			value[temp] = 0;
		}
		temp = (myCurState*10+1);
		temp%=n;
		if(parent[temp] == -1)
		{
			myQueue.push(temp);
			parent[temp] = myCurState;
			value[temp] = 1;
		}
	}
}


int main()
{
	int n,t;

	string popped;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		solve(n);
	}
}