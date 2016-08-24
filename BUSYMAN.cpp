#include <bits/stdc++.h>
using namespace std;

struct mytime{
	int start;
	int end;
};

bool myFunction(mytime A, mytime B)
{
	if(A.end<B.end)
		return true;
	else if(A.end > B.end)
		return false;
	else
	{
		if(A.start<B.start)
			return true;
		else
			return false;
	}
}

mytime myInput[100001];

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>myInput[i].start>>myInput[i].end;
		sort(myInput, myInput+n, myFunction);
		
		int count = 1;		
		int myEnd = myInput[0].end;
		for(int i=1;i<n;i++)
		{
			if(myEnd <= myInput[i].start)
			{
				count++;
				myEnd = myInput[i].end;
			}
		}
		cout<<count<<endl;
	}
}