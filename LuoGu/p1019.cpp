#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 返回两个单词重叠部分的长度
int connect(const string& str1, const string& str2) {
    int length1 = str1.length();
    int length2 = str2.length();
    for (int i = 0; i < length1 && i < length2; ++i) {
        bool valid = true;
        for (int j = 0; j <= i; ++j) {
            if (str1[length1 - 1 - i + j] !=
              str2[j]) {
                valid = false;
                break;
            }
        }
        if (valid)
            return i + 1;
    }
    return 0;
}

int N;
int max_length = 0;
vector<string> words;
vector<int> used;

void explore(int current_word, int current_length) {
    int current_word_length = words[current_word].length();
    bool exist = false;
    for (int i = 0; i < N; ++i) {
        if (used[i] < 2) {
            int length = words[i].length();
            int common_length = connect(words[current_word], words[i]);
            if (common_length > 0 && common_length < length &&
                common_length < current_word_length) {
                ++used[i];
                explore(i, current_length + length - common_length);
                --used[i];
                exist = true;
            }
        }
    }
    if (!exist && current_length > max_length) {
        max_length = current_length;
    }
}

int main() {
    cin >> N;
    words.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }
    char begin_ch;
    cin >> begin_ch;

    used.resize(N);
    for (int i = 0; i < N; ++i) {
        if (words[i][0] == begin_ch) {
            used[i] = 1;
            explore(i, words[i].length());
            used[i] = 0;
        }
    }

    cout << max_length << endl;

    return 0;
}