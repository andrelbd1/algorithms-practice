#include <bits/stdc++.h>

using namespace std;

vector<int>
rotLeft(vector<int> a, int d)
{
    int n = a.size();
    vector<int> res;

    for (int i = d; i < n; i++)
        res.push_back(a[i]);
    
    for (int i = 0; i < d; i++)
        res.push_back(a[i]);

    return res;
}

int
main(int argc, char **argv)
{
	if (argc==1)
	    return 0;

    ifstream filein (argv[1]);

	string line;
	string delimiter = " ";
	vector<int> arr;
    int n;
	int d;

	if (filein.is_open())
    {
	    size_t pos = 0;
		string token;
		
        getline ( filein, line );
		string s = line;

        pos = s.find(delimiter);
        token = s.substr(0,pos);
        s.erase(0, pos+delimiter.length());
        n=stoi(token);
        d=stoi(s);

		arr.resize(n);
		int i=0;

        getline ( filein, line );
		s = line;

		while ((pos = s.find(delimiter)) != string::npos)
		{
			token = s.substr(0, pos);
			s.erase(0, pos+delimiter.length());

            arr[i]=stoi(token);
			i++;
		}
        filein.close();
	}
	else
	{
	    cout << "Unable to open file";
        return 0;
	}
	
	vector<int> result = rotLeft(arr, d);
    for (int i=0; i < n; i++)
    {
        cout << result[i] << " ";
    }
	//cout << result << "\n";

	return 0;
}
