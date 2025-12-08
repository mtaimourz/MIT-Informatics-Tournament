#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int T;
    fin >> T;
    
    while (T--) {
        string a, b;
        fin >> a >> b;
        
        int total_p_in_a = 0, total_p_in_b = 0;
        for(char ch : a) if(ch == 'P') total_p_in_a++;
        for(char ch : b) if(ch == 'P') total_p_in_b++;
        
        if(total_p_in_a != total_p_in_b) {
            fout << "NO" << endl;
            continue;
        }
        
        int total_n_after_p_in_a = 0, total_n_after_p_in_b = 0;
        
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] == 'N') total_n_after_p_in_a++;
            else break;
        }
        
        for(int i = b.size() - 1; i >= 0; i--) {
            if(b[i] == 'N') total_n_after_p_in_b++;
            else break;
        }
        
        if(total_n_after_p_in_a == total_n_after_p_in_b) {
            fout << "YES" << endl;
        } else {
            fout << "NO" << endl;
        }
    }
    return 0;
}


/*
I can pick P and replace it with NP.
I can pickNP and replace it with P

source target
P NP

result
NP NP 

source target
PNPP PPNNNNNNNNNNNNNNNNNNP

result
PNPP -> PPP => change np to p
PPP -> PNPP -> PNNPP -> PNPNP

all possible combinations. bfs ?

optimized


P → NP :  adds a p in front
NP → P : removes a p in start


PPNNPPNNPP
         ^^ These P's at end mean: 0 trailing N's

NNPPNNPPNN
        ^^ These N's at end mean: 2 trailing N's (trapped!)


*/