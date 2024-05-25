#include <bits/stdc++.h>

using namespace std;

int
countingValleys(int steps, string path)
{
	int level=0;
	int valley=0;
	int count_valley=0;
    for (int i=0; i<steps; i++)
	{
		if(path[i] == 'U')
			level+=1;
		else if (path[i] == 'D')
			level-=1;
		
		if(level < 0)
		{
			if (valley == 0)
				valley = 1;
		}
		else if (valley == 1) 
		{
			count_valley+=1;
			valley=0;
		}
	}
	return count_valley;	
}

int
main(int argc, char **argv)
{
	if (argc==1)
	        return 0;

	ifstream filein (argv[1]);

	string line;
	int steps;
	string path;

	if (filein.is_open())
    	{
        	getline ( filein, line );
	        steps = stoi(line);

	        getline ( filein, line );
        	path = line;

	        filein.close();
	}
	else
	{
	        cout << "Unable to open file";
        	return 0;
	}

	int result = countingValleys(steps, path);
	cout << result << "\n";

	return 0;
}
