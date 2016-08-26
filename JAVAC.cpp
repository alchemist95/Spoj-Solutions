#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[105];
	while(scanf("%s", s)!=EOF)
	{
		char d;
		string result;
		int flag = 0;
		int status=1;

		if(s[0]=='_' || s[strlen(s)-1]=='_' || (s[0]>=65 && s[0]<=90))
			flag = 55;
		for(int i=0;i<strlen(s);i++)
		{
			d = s[i];
			if(d=='_')
				status=0;

			if(status==0 && (s[i]>=65 && s[i]<=90))
				flag=55;

			if( (d<65 || d>122 || (d>90 && d<97)) && d!='_')
			{
				flag = 55;
			}

			if(d=='_' && s[i+1]=='_')
			{
				flag = 55;
			}
		}

		if(flag == 55)
			printf("Error!\n");
		else
		{
			if(status==0)
			{
				for(int i=0;i<strlen(s);i++)
				{
					if(s[i]=='_')
					{
						printf("%c", int(s[i+1]-32));
						i++;
					}
					else
						printf("%c", s[i]);
				}
				printf("\n");
			}
			else
			{
				for(int i=0;i<strlen(s);i++)
				{
					if(s[i]>=65 && s[i]<=90)
					{
						printf("_%c", int(s[i])+32);
					}
					else
						printf("%c", s[i]);
				}
				printf("\n");
			}
		}


	}
}