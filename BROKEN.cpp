#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m;
	int myHash[128] = {0};
	string h;
	while(1)
	{
		cin>>m;
		if(m==0)
			break;
		cin.ignore(256,'\n');
		getline(cin,h);

		for(int i=0;i<128;i++)
			myHash[i] = 0;
		int i=0;
		int j=1;

		int max, currentChars;

		if(m==1)
		{
			myHash[h[0]]++;
			max = 1;
			currentChars = 1;
		}
		else
		{
			myHash[h[0]]++;
			myHash[h[1]]++;
			if(h[0] == h[1])
				currentChars=1;
			else
				currentChars=2;
			max = 2;
			j=2;
		}

		while(h[j]!='\0')
		{
			if(myHash[h[j]] == 0)
			{
				currentChars++;
			}
			myHash[h[j]]++;
			if(currentChars<=m)
			{
				if((j-i+1) > max)
					max = j-i+1;
			}
			else
			{

				myHash[h[i]]--;
				if(myHash[h[i]] == 0)
					currentChars--;
				i++;
			}
			j++;
		}
		cout<<max<<endl;
	}
}
