#include <bits/stdc++.h>
using namespace std;

string transmute(string input, int flag)
{
	if(flag==1) 	// Front-Right
	{
		input[1] = char(int(input[1]) + 2);
		input[0] = char(int(input[0])+1);
		return input;
	}
	else if(flag == 2) // Front-Left
	{
		input[1] = char(int(input[1]) + 2);
		input[0] = char(int(input[0])-1);
		return input;		
	}
	else if(flag == 3)  // Left - Up
	{
		input[0] = char(int(input[0])-2);
		input[1] = char(int(input[1]) + 1);
		return input;		 
	}
	else if(flag == 4)  // Left - Down
	{
		input[0] = char(int(input[0])-2);
		input[1] = char(int(input[1]) -1);
		return input;			
	}
	else if(flag == 5) // Down-Left
	{
		input[1] = char(int(input[1]) - 2);
		input[0] = char(int(input[0])-1);
		return input;		
	}
	else if(flag == 6) // Down-Right
	{
		input[1] = char(int(input[1]) - 2);
		input[0] = char(int(input[0])+1);
		return input;		
	}
	else if(flag == 7)	// Right-Down
	{
		input[0] = char(int(input[0])+2);
		input[1] = char(int(input[1]) - 1);
		return input;		
	}
	else
	{
		input[0] = char(int(input[0])+2);
		input[1] = char(int(input[1]) + 1);
		return input;		
	}
}

int main()
{
	string input, output, transmuted;
	int value, t, level;
	char Q[5];
	char W[5];
	scanf("%d", &t);

	while(t--)
	{
		scanf("%s %s", &Q, &W);
		input += Q[0];
		input += Q[1];
		output += W[0];
		output += W[1];
		queue < pair< string, int> > myQueue;
		int visited[10000] = {0};
		myQueue.push(make_pair(output, 0));
		value = output[0]*(output[1]-'0');
		visited[value] = 1;

		while(!myQueue.empty())
		{
			output = myQueue.front().first;
			level = myQueue.front().second;
			myQueue.pop();

			if(input == output)
			{
				printf("%d\n", level);
				break;
			}
			else
			{

				// front-right
				if(output[1]!='7' && output[1]!='8' && output[0]!='h')
				{
					transmuted = transmute(output, 1);
					value = transmuted[0]*(transmuted[1]-'0');
					if(visited[value] == 0)
					{
						visited[value] = 1;	
						myQueue.push(make_pair(transmuted, level+1));
					}
				}


				// front-left

				if(output[1]!='7' && output[1]!='8' && output[0]!='a')
				{
					transmuted = transmute(output, 2);
					value = transmuted[0]*(transmuted[1]-'0');
					if(visited[value] == 0)
					{
						visited[value] = 1;
						myQueue.push(make_pair(transmuted, level+1));
					}
				}


				// left-up
				if(output[1]!='8' && output[0]!='a' && output[0]!='b')
				{
					transmuted = transmute(output, 3);
					value = transmuted[0]*(transmuted[1]-'0');
					if(transmuted!="DDHH" && visited[value] == 0)
					{
						visited[value] = 1;
						myQueue.push(make_pair(transmuted, level+1));
					}
				}

				// left-down
				if(output[1]!='1' && output[0]!='a' && output[0]!='b')
				{	
					transmuted = transmute(output, 4);
					value = transmuted[0]*(transmuted[1]-'0');
					if(transmuted!="DDHH" && visited[value] == 0)
					{
						visited[value] = 1;
						myQueue.push(make_pair(transmuted, level+1));
					}
				}

				// down-left
				if(output[1]!='1' && output[1]!='2' && output[0]!='a')
				{
					transmuted = transmute(output, 5);
					value = transmuted[0]*(transmuted[1]-'0');
					if(transmuted!="DDHH" && visited[value] == 0)
					{
						visited[value] = 1;
						myQueue.push(make_pair(transmuted, level+1));
					}
				}

				// down-right

				if(output[1]!='1' && output[1]!='2' && output[0]!='h')
				{
					transmuted = transmute(output, 6);
					value = transmuted[0]*(transmuted[1]-'0');
					if(transmuted!="DDHH" && visited[value] == 0)
					{
						visited[value] = 1;
						myQueue.push(make_pair(transmuted, level+1));
					}
				}

				// right-down

				if(output[0]!='g' && output[0]!='h' && output[1]!='1')
				{
					transmuted = transmute(output, 7);			
					value = transmuted[0]*(transmuted[1]-'0');
					if(transmuted!="DDHH" && visited[value] == 0)
					{
						visited[value] = 1;
						myQueue.push(make_pair(transmuted, level+1));
					}
				}

				// right - up
				if(output[0]!='g' && output[0]!='h' && output[1]!='8')
				{
					transmuted = transmute(output, 8);
					value = transmuted[0]*(transmuted[1]-'0');
					if(transmuted!="DDHH" && visited[value] == 0)
					{
						visited[value] = 1;
						myQueue.push(make_pair(transmuted, level+1));
					}
				}
			}
		}
		input.clear();
		output.clear();
	}
	return 0;
}