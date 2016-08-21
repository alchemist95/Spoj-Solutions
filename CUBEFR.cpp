#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001

int myAnswer[MAX];
int cubeFree[MAX] = {0};

void myFunction()
{
	vector<int> myCubes;
	for(int i=2;i<=100;i++)
	{
		myCubes.push_back(i*i*i);
	}
	int meraCube;

	for(int i=0;i<myCubes.size();i++)
	{
		meraCube = myCubes[i];
		cubeFree[meraCube] = 1;
		for(int j=meraCube*2;j<MAX;j+=meraCube)
		{
			cubeFree[j] = 1;
		}
	}
	
	int p = 1;
	for(int i=1;i<MAX;i++)
	{
		if(cubeFree[i]==0)
		{
			myAnswer[i] = p;
			p++;
		}
	}

}

int main()
{
	int t,n;
	myFunction();
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		scanf("%d", &n);
		if(myAnswer[n]==0)
			printf("Case %d: Not Cube Free\n", i);
		else
			printf("Case %d: %d\n",i, myAnswer[n]);
	}
}