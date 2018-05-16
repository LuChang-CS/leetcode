#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    string morse_table[] = { ".-", "-...", "-.-.", "-..",
                             ".", "..-.", "--.", "....",
                             "..", ".---", "-.-", ".-..",
                             "--", "-.", "---", ".--.",
                             "--.-", ".-.", "...", "-",
                             "..-", "...-", ".--", "-..-",
                             "-.--", "--.." };
    unordered_set<string> morse_codes(100);  // we know the max size of words is 100
    for (vector<string>::iterator iter = words.begin(); iter != words.end(); ++iter) {
        string word = *iter;
        string code;
        code.reserve(50);
        for (string::iterator ch_iter = word.begin(); ch_iter != word.end(); ++ch_iter) {
            code += morse_table[*ch_iter - 'a'];  // calculate the morse code of each letter
        }
        morse_codes.insert(code);
    }
    return morse_codes.size();
}

int main() {
    vector<string> words = { "gin", "zen", "gig", "msg" };
    cout << uniqueMorseRepresentations(words) << endl;
    return 0;
}
