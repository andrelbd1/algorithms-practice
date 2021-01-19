#include <bits/stdc++.h>

using namespace std;

int 
minimumSwaps(vector<int> arr)
{
   int size = arr.size();
   int count = 0;
   
   for (int i=0; i<size-1; i++)
   {
       if (arr[i]!=i+1)
       {    
           int aux = arr[arr[i]-1];
           arr[arr[i]-1] = arr[i];
           arr[i] = aux;
           count++;
           i--;
       }
   }

   return count;
}

vector<string> 
split_string(string input_string) 
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) 
    {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') 
        input_string.pop_back();

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) 
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

int 
main(int argc, char **argv)
{
    if (argc==1)
	    return 0;

    ifstream filein (argv[1]);
    
    string line;
    int n;
    vector<string> ar_temp;

    if (filein.is_open())
    {
	    getline ( filein, line);
    	n = stoi(line);

	    getline ( filein, line );
    	ar_temp = split_string(line);
	
	    filein.close();
    }
    else
    {
    	cout << "Unable to open file";
	    return 0;
    }

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);
        ar[i] = ar_item;
    }

    int result = minimumSwaps(ar);
    cout << result << "\n";

    return 0;
}
