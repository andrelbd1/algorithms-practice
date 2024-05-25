#include <bits/stdc++.h>

using namespace std;

int 
sockMerchant(int n, vector<int> ar)
{
    if (ar.size() == 0)
        return 0;

    sort(ar.begin(), ar.end()); //O(nlogn)

    int count=0;
    int count_curr=0;
    int curr = ar.at(0);

    for (int i: ar) //O(n)
    {
        if (i == curr)
            count_curr+=1;
        else
        {
            count+=count_curr/2;
            count_curr=1;
            curr=i;
        }
    }

    if (count_curr > 1)
        count+=count_curr/2;

    return count;
}

vector<string> 
split_string(string input_string) 
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
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

	getline ( filein, line);
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

    int result = sockMerchant(n, ar);
    cout << result << "\n";

    return 0;
}
