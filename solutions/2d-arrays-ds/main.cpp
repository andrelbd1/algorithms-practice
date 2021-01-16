#include <bits/stdc++.h>

using namespace std;

int
calculate(vector<vector<int>> arr, int i, int j)
{
	int sum=arr[i][j];
	sum=sum+arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1];
	sum=sum+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1];
	return sum;
}

int
hourglassSum(vector<vector<int>> arr)
{	
	int res = -1000;
	for (int i=1; i<5; i++)
	{
		for (int j=1; j<5; j++)
		{	
			int sum = calculate(arr,i,j);
			res = max(sum,res);	
		}
	}
	
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
	vector<vector<int>> arr(6);

	if (filein.is_open())
    	{
		for (int i; i < 6; i++)
		{	
			size_t pos = 0;
			string token;
			
			arr[i].resize(6);
			int j=0;

        		getline ( filein, line );
			string s = line;

			while ((pos = s.find(delimiter)) != string::npos)
			{
				token = s.substr(0, pos);
				s.erase(0, pos+delimiter.length());

				arr[i][j]=stoi(token);
				j++;
			}
		}
	        filein.close();
	}
	else
	{
	        cout << "Unable to open file";
        	return 0;
	}
	
	int result = hourglassSum(arr);
	cout << result << "\n";

	return 0;
}
