#include <bits/stdc++.h>

using namespace std;

void
minimumBribes(vector<int> q)
{   
    int count = 0;
    
    for (int i=0; i<q.size(); i++)
    {
        if (q[i]-(i+1) > 2)
        {
            cout << "Too chaotic" << "\n";
            return;
        }
        
        for (int j=max(0,q[i]-2); j < i; j++)
            if (q[j] > q[i])
                count++;
    }

    cout << count << "\n";
}

int
main(int argc, char **argv)
{
	if (argc==1)
	    return 0;

    ifstream filein (argv[1]);

	string line;
	string delimiter = " ";
    int t;
	int n;

	if (filein.is_open())
    {
	    size_t pos = 0;
		string token;
		
        getline ( filein, line );
		string s = line;
        t=stoi(s);

        for (int i=0; i < t; i++)
        {
            getline ( filein, line );
		    string s = line;
            n=stoi(s);
                    
	        vector<int> arr(n);
            
            getline ( filein, line );
		    s = line;
            
            int j=0;
		    
            while ((pos = s.find(delimiter)) != string::npos)
            {
			    token = s.substr(0, pos);
			    s.erase(0, pos+delimiter.length());

                arr[j]=stoi(token);
			    j++;
            }
            
            minimumBribes(arr);
        }

        filein.close();
	}
	else
	{
	    cout << "Unable to open file";
        return 0;
	}
	
	return 0;
}
