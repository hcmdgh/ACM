#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<string, string> Rule;

int main() {
    string src, dest;
    cin >> src >> dest;
    vector<Rule> rules;
    string temp;
    while ((cin >> temp) && temp != "genghao") {
        Rule rule;
        rule.first = temp;
        cin >> temp;
        rule.second = temp;
        rules.emplace_back(rule);
    }

    vector<string> v1, v2;
    v1.emplace_back(src);
    int step = 0;
    while (step < 10) {
        ++step;
        vector<string>& v_src = (step % 2 == 1) ? v1 : v2;
        vector<string>& v_dest = (step % 2 == 1) ? v2 : v1;
        v_dest.clear();
        for (const string& str : v_src) {
            for (const Rule& rule : rules) {
                int str_length = str.length();
                const string& replace_before = rule.first;
                const string& replace_after = rule.second;
                int replace_before_len = replace_before.length();
                for (int i = 0; i < str_length + 1 - replace_before_len; ++i) {
                    bool valid = true;
                    for (int j = 0; j < replace_before_len; ++j) {
                        if (str[i + j] != replace_before[j]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        string new_str = str.substr(0, i) + replace_after + str.substr(i + replace_before_len);
                        if (new_str == dest) {
                            cout << step << endl;
                            return 0;
                        }
                        v_dest.emplace_back(new_str);
                        i += replace_before_len - 1;
                    }
                }
            }
        }
    }
    cout << "NO ANSWER!" << endl;

    return 0;
}