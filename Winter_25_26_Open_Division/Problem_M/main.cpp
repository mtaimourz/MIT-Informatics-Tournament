#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>
#include<iostream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
    int T;
    fin >> T;
    while (T--) {
        int n;
        fin>>n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                   if(j == 0 || j == n-1 || (i == j && j <= n/2) || (i + j == n-1 && j >= n/2)){
                    fout<<"#";
                }else{
                    fout<<".";
                }
            }
            fout<<endl;
        }

    }
    return 0;
}


/*

#...#
##.##
#.#.#
#...#
#...#


00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44


j = 0
j = n - 1

i == j

j <= 2
or
j <= n/2



*/