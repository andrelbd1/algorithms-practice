#include <bits/stdc++.h>

using namespace std;


int
jumpingOnClouds(vector<int> c)
{
	int count = 0;
	int size = c.size();
	int curr = 0;

	while (curr < size-1)
	{
		if (curr+2 < size)
		{
			if (c[curr+2] == 0)
			{
				curr+=2;
				count+=1;
			}
			else if (c[curr+1] == 0)
			{
				curr+=1;
				count+=1;
			}
			else
				break;
		}
		else
		{
			if (c[curr+1] == 0)
			{
				curr+=1;
				count+=1;				
			}
			break;
		}

	}

	return count;
}

int
main(int argc, char **argv)
{
	if (argc==1)
	        return 0;

	ifstream filein (argv[1]);

	string line;
	int size;
	string path;
	vector<int> c;

	if (filein.is_open())
    	{
        	getline ( filein, line );
	        size = stoi(line);

	        getline ( filein, line );
        	path = line;

	        filein.close();
	}
	else
	{
	        cout << "Unable to open file";
        	return 0;
	}
	
	for (int i = 0; i < size; i++)
	{	
		int c_item = 0;
     		if (path[i] != '0')
			c_item = 1;
		c.push_back( c_item );
	}

	int result = jumpingOnClouds(c);
	cout << result << "\n";

	return 0;
}
