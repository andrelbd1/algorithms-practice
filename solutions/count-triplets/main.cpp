#include <bits/stdc++.h>

using namespace std;

map<long,long>
counter(vector<long> arr)
{
   map<long,long> map_arr;
   long n = arr.size();

   for (long i=0; i<n; i++)
   {
      if (map_arr.find(arr[i]) == map_arr.end())
         map_arr.insert(pair<long,long>(arr[i],1));
      else
         map_arr.at(arr[i]) = map_arr.find(arr[i])->second+1;
   }

   return map_arr;
}

long
countTriplets(vector<long> arr, long r)
{
   long n = arr.size();
   long count = 0;
   
   map<long,long> map_arr_l;
   map<long,long> map_arr_r = counter(arr);

   for (long i=0; i<n; i++)
   {
      map_arr_r.at(arr[i]) = map_arr_r.find(arr[i])->second-1;

      if (arr[i]%r == 0)
      {
         long left = arr[i]/r;
         long right = arr[i]*r;
      
         if ((map_arr_l.find(left) != map_arr_l.end()) && (map_arr_r.find(right) != map_arr_r.end()))
         {
            long aux = map_arr_l.find(left)->second * map_arr_r.find(right)->second;
            count+=aux;
         }
      }
      
      if (map_arr_l.find(arr[i]) == map_arr_l.end())
         map_arr_l.insert(pair<long,long>(arr[i],1));
      else
         map_arr_l.at(arr[i]) = map_arr_l.find(arr[i])->second+1;
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
   long n;
   long r;
   vector<string> ar_temp;

   if (filein.is_open())
   {
	   getline ( filein, line );
    	ar_temp = split_string(line);

      n = stol(ar_temp[0]);
      r = stol(ar_temp[1]);
 
	   getline ( filein, line );
      ar_temp = split_string(line);
      
      vector<long> numbers(n);

      for (long i = 0; i < n; i++) 
         numbers[i] = stol(ar_temp[i]);
      
      filein.close();

      long result = countTriplets(numbers, r);
      cout << result << "\n";
   }
   else
   {
      cout << "Unable to open file";
   }
   
   return 0;
}
