#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int len = 2*n+1;
	string target;
	target.assign(len, ' ');
	target[0] = 'M';
	for(int i = 1; i < len; i+=2)
	{
		target[i] = 'I';
	}
	for(int i = 2; i < len; i+=2)
	{
		target[i] = 'T';
	}

	string combined = s + s;

	int ans = -1;
	if(s == target)
	{
		ans = 0;
	}
	else
	{
		size_t start_idx = combined.find(target);
		if(start_idx != string::npos)
		{
			ans = 1;
		}
	}

	cout<<ans<<endl;
   }

    // cin.close();
    // cout.close();
    return 0;
}
