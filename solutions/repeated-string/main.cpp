#include <bits/stdc++.h>

using namespace std;


long
repeatedString(string s, long n)
{
	long count=0;
	for (long i=0; i < s.size(); i++)
	{
		if (s[i]=='a')
			count+=1;
	}
	
	long mult = n/s.size();
	int diff = n%s.size();
	
	count*=mult;

	for (long i=0; i < diff; i++)
	{
		if (s[i]=='a')
			count+=1;
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
	string s;
	long n;

	if (filein.is_open())
    	{
        	getline ( filein, line );
        	s = line;

	        getline ( filein, line );
	        n = stol(line);

	        filein.close();
	}
	else
	{
	        cout << "Unable to open file";
        	return 0;
	}
	
	long result = repeatedString(s,n);
	cout << result << "\n";

	return 0;
}
