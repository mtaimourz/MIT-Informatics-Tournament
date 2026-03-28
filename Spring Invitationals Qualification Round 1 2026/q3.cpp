#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


pair<long long, long long> solve(vector<long long>& scores, int left, int right, int gapLeft, int gapRight, bool beaverTurn)
{
	if(left == right) return beaverTurn ? make_pair(scores[left], 0LL) : make_pair(0LL, scores[left]);

	int remaining = right - left + 1 - gapLeft - gapRight;
	if(remaining == 2)
	{
		if(beaverTurn)
		{
			return make_pair(max(scores[left], scores[right]), min(scores[left], scores[right]));
		}
		else
		{
			return make_pair(min(scores[left], scores[right]), max(scores[left], scores[right]));
		}
	}

	if(beaverTurn)
	{
		int pick1 = left;
		int pick2 = left + 1 + gapLeft;

		auto option1 = solve(scores, left + 1 + gapLeft, right, 0, gapRight, false);
		option1.first += scores[pick1];

		auto option2 = solve(scores, left, right, gapLeft + 1, gapRight, false);
		option2.first += scores[pick2];

		return option1.first >= option2.first ? option1 : option2;

	}
	else
	{
		int pick1 = right;
		int pick2 = right - 1 - gapRight;

		auto option1 = solve(scores, left, right - 1 - gapRight, gapLeft, 0, true);
		option1.second += scores[pick1];

		auto option2 = solve(scores, left, right, gapLeft, gapRight + 1, true);
		option2.second += scores[pick2];


		return option1.second >= option2.second ? option1 : option2;
	}

}


int main() {
    // ifstream fin("input.txt");
    // ofstream fout("output.txt");

   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
	int numCarrots, numUpdates;
	cin>>numCarrots>>numUpdates;
	vector<long long> scores(numCarrots);
	for(int i = 0; i < numCarrots; i++) cin>>scores[i];

	auto result = solve(scores, 0, numCarrots - 1, 0, 0, true);
	cout << result.first << " " << result.second << endl;

	for(int i = 0; i < numUpdates; i++)
	{
		int carrotIndex;
		long long newScore;
		cin>>carrotIndex>>newScore;
		scores[carrotIndex-1] = newScore;

		auto result = solve(scores, 0, numCarrots - 1, 0, 0, true);
		cout << result.first << " " << result.second << endl;		
	}
   }

    // fin.close();
    // fout.close();
    return 0;
}
