	#include <bits/stdc++.h>
	using namespace std;

	int main()
	{
		int n,g,myXor = 0;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &g);
			myXor = myXor ^ g;
		}
		printf("%d\n", myXor);
	
	}