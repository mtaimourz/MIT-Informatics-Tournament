#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");

   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){	
	int n;
	cin>>n;
	vector<int> numbers;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		numbers.push_back(temp);
	}

	sort(numbers.begin(), numbers.end());
	long long result = numbers[n-1] - numbers[0];

	for(int i = 1; i < n - 1; i++)
	{
		result += max(numbers[i] - numbers[0], numbers[n-1] - numbers[i]);
	}
	cout<<result<<endl;

   }

    // fin.close();
    // fout.close();
    return 0;
}
