#include <bits/stdc++.h>

using namespace std;

long 
arrayManipulation(int n, vector<vector<int>> queries)
{
   long res = -1000;
   int m = queries.size();
   vector<long> arr(n+2);
   
   for (int q=0; q<m; q++)
   {
      int a = queries[q][0];
      int b = queries[q][1];
      long k = queries[q][2];
      
      arr[a]+=k;
      arr[b+1]-=k;
   }
   
   for (int i=1; i<arr.size(); i++)
   {
      arr[i]+=arr[i-1];
      res=max(arr[i],res);
   }

   return res;
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
   int m;
   vector<string> ar_temp;

   if (filein.is_open())
   {
	   getline ( filein, line );
    	ar_temp = split_string(line);

      n = stoi(ar_temp[0]);
      m = stoi(ar_temp[1]);
      
      vector<vector<int>> queries(m);

      for (int i = 0; i < m; i++) 
      {
         getline ( filein, line );
    	   ar_temp = split_string(line);
         
         queries[i].resize(3);
         
         for (int j = 0; j < 3; j++)
            queries[i][j] = stoi(ar_temp[j]);
      }
      
      filein.close();

      long result = arrayManipulation(n, queries);
      cout << result << "\n";
   }
   else
   {
      cout << "Unable to open file";
   }
   
   return 0;
}
