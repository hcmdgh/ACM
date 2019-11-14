// and和or未完成

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string NOT_FOUND = "Sorry, I found nothing.";
const string SEP = "----------";

int main() {
    ios::sync_with_stdio(false);
    int N;
    string line;
    cin >> N;

    vector<vector<string>> raw_articles(N);
    vector<vector<string>> articles(N);
    cin.ignore(1024, '\n');
    for (int i = 0; i < N; ++i) {
        while (getline(cin, line) && line != "**********") {
            raw_articles[i].emplace_back(line);
            int length = line.length();
            for (int j = 0; j < length; ++j) {
                if (line[j] >= 'A' && line[j] <= 'Z') {
                    line[j] = line[j] - 'A' + 'a';
                }
            }
            articles[i].emplace_back(line);
        }
    }

    int Q;
    cin >> Q;
    cin.ignore(1024, '\n');
    while (Q--) {
        getline(cin, line);
        int pos;
        if ((pos = line.find("AND")) > -1) {
            string term1 = line.substr(0, pos - 1);
            string term2 = line.substr(pos + 4);
            bool first = true;
            for (int i = 0; i < N; ++i) {
                bool exist = false;
                for (const string& _line : articles[i]) {
                    if (_line.find(term) != string::npos) {
                        cout << _line << endl;
                        exist = true;
                    }
                }
                if (exist) {
                    if (!first) {
                        cout << SEP << endl;
                    }
                    first = false;
                }
            }
            if (first) {
                cout << NOT_FOUND << endl;
            }
        } else if ((pos = line.find("OR")) > -1) {

        } else if ((pos = line.find("NOT")) > -1) {
            string term = line.substr(4);
            bool first = true;
            for (int i = 0; i < N; ++i) {
                bool exist = false;
                for (const string& _line : articles[i]) {
                    if (_line.find(term) != string::npos) {
                        exist = true;
                        break;
                    }
                }
                if (!exist) {
                    if (!first) {
                        cout << SEP << endl;
                    }
                    first = false;
                    for (const string& _line : raw_articles[i]) {
                        cout << _line << endl;
                    }
                }
            }
            if (first) {
                cout << NOT_FOUND << endl;
            }
        } else {
            string term = line;
            bool first = true;
            for (int i = 0; i < N; ++i) {
                bool exist = false;
                for (int j = 0; j < articles[i].size(); ++j) {
                    if (articles[i][j].find(term) != string::npos) {
                        cout << raw_articles[i][j] << endl;
                        exist = true;
                    }
                }
                if (exist) {
                    if (!first) {
                        cout << SEP << endl;
                    }
                    first = false;
                }
            }
            if (first) {
                cout << NOT_FOUND << endl;
            }
        }

        cout << "==========" << endl;
    }

    return 0;
}
