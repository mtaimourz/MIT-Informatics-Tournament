#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

string try_build_arrangement(int letter_counts[3], char letter_order[3], int total_cards) {
    string arrangement = "";
    int remaining_counts[3] = {letter_counts[0], letter_counts[1], letter_counts[2]};
    
    while (arrangement.length() < total_cards) {
        int best_letter_index = -1;
        int highest_remaining_count = -1;
        
        for (int letter_index = 0; letter_index < 3; letter_index++) {
            if (remaining_counts[letter_index] == 0) continue;
            
            char current_letter = letter_order[letter_index];
            
            if (!arrangement.empty() && arrangement.back() == current_letter) continue;

            bool is_forbidden = false;
            int current_length = arrangement.length();
            if (current_length >= 2) { 
                string last_two_chars = arrangement.substr(current_length - 2, 2);
                string last_three_chars = last_two_chars + current_letter;
                
                if (last_three_chars == "MIT" || last_three_chars == "TIM") {
                    is_forbidden = true;
                }
            }

            if(is_forbidden) continue;

            
            if (remaining_counts[letter_index] > highest_remaining_count) {
                highest_remaining_count = remaining_counts[letter_index];
                best_letter_index = letter_index;
            }
        }
        
        if (best_letter_index == -1) return "";
        
        arrangement += letter_order[best_letter_index];
        remaining_counts[best_letter_index]--;
    }
    
    return arrangement;
}

string solve_card_arrangement(int m_card_count, int i_card_count, int t_card_count) {
    int total_cards = m_card_count + i_card_count + t_card_count;
    
    if (total_cards == 1) {
        if (m_card_count == 1) return "M";
        if (i_card_count == 1) return "I";
        if (t_card_count == 1) return "T";
    }
    
    // If one letter appears more than half the time, we cannot alternate without duplicates
    int max_letter_count = max({m_card_count, i_card_count, t_card_count});
    if (max_letter_count > (total_cards + 1) / 2) {
        return "";
    }
    
    char letter_orderings[6][3] = {
        {'M', 'I', 'T'},
        {'M', 'T', 'I'},
        {'I', 'M', 'T'},
        {'I', 'T', 'M'},
        {'T', 'M', 'I'},
        {'T', 'I', 'M'}
    };
    
    for (int ordering_index = 0; ordering_index < 6; ordering_index++) {
        int permuted_counts[3];
        for (int position = 0; position < 3; position++) {
            if (letter_orderings[ordering_index][position] == 'M') {
                permuted_counts[position] = m_card_count;
            } else if (letter_orderings[ordering_index][position] == 'I') {
                permuted_counts[position] = i_card_count;
            } else {
                permuted_counts[position] = t_card_count;
            }
        }
        
        string arrangement = try_build_arrangement(permuted_counts, 
                                                    letter_orderings[ordering_index], 
                                                    total_cards);
        if (!arrangement.empty()) {
            return arrangement;
        }
    }
    
    return "";
}

int main() {
    int test_case_count;
    fin >> test_case_count;
    
    while (test_case_count--) {
        int m_card_count, i_card_count, t_card_count;
        fin >> m_card_count >> i_card_count >> t_card_count;
        
        string arrangement_result = solve_card_arrangement(m_card_count, 
                                                           i_card_count, 
                                                           t_card_count);
        
        if (arrangement_result.empty()) {
            fout << "NO" << endl;
        } else {
            fout << "YES" << endl;
            fout << arrangement_result << endl;
        }
    }
    
    return 0;
}
/*


1 1 1
three cards
M I T
cann we placed in 4 different ways


3 0 0
M I T

can only be places like this
MMM 


in short we cannot have
MM
II
TT 

we cannot do MIT and TIM

Must use all the cards too










*/