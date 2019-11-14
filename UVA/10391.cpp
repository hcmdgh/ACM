#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

string words[120000];

inline bool starts_with(const string& str, const string& prefix) {
    int str_length = str.length();
    int prefix_length = prefix.length();
    if (str_length <= prefix_length)
        return false;
    for (int i = 0; i < prefix_length; ++i) {
        if (str[i] != prefix[i])
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    string word;
    int N = 0;
    while (cin >> word) {
        words[N] = word;
        ++N;
    }

    set<string> ans;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (starts_with(words[j], words[i])) {
                string other_word = words[j].substr(words[i].length());
                if (binary_search(words, words + N, other_word)) {
                    ans.emplace(words[j]);
                }
            } else {
                break;
            }
        }
    }

    for (const string& str : ans) {
        cout << str << endl;
    }

    return 0;
}
