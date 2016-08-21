
/*

Deviation from Collatz Conjecture

take a number

if it is even, make it its half
else make it equal to 3 times itself + 1

th number eventually becomes 1


*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long input;
	scanf("%lld", &input);

	while(input>1)
	{
		if(input%2==0)
			input= input/2;
		else
			break;
	}
	if(input!=1)
		printf("NIE\n");
	else
		printf("TAK\n");

}