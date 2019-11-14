#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> words;
vector<int> max_len;

int main() {
    ios::sync_with_stdio(false);
    string str;
    int i = 0;
    int max_col = 0;
    while (getline(cin, str)) {
        stringstream sstr(str);
        string word;
        words.emplace_back(vector<string>());
        while (sstr >> word) {
            words[i].emplace_back(word);
        }
        max_col = max(max_col, int(words[i].size()));
        ++i;
    }

    for (int j = 0; j < max_col; ++j) {
        int maxlen = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() > j) {
                maxlen = max(maxlen, int(words[i][j].length()));
            }
        }
        max_len.emplace_back(maxlen);
    }

    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < words[i].size(); ++j) {
            cout << words[i][j];
            if (j < words[i].size() - 1) {
                int space = max_len[j] - words[i][j].length() + 1;
                for (int k = 0; k < space; ++k) {
                    cout << ' ';
                }
            }
        }
        cout << endl;
    }

    return 0;
}
