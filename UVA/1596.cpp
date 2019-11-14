#include <iostream>
#include <string>
#include <map>
#include <climits>
#include <set>
using namespace std;

struct Array {
    int size;
    map<int, int> elements;

    Array(int size) : size(size) {}
    Array() {}
};
map<char, Array> arrays;

int getNum(const string& str, int begin, int end) {
    char var = str[begin];
    if (var >= '0' && var <= '9') {
        return stoi(str.substr(begin, end - begin + 1));
    } else {
        if (arrays.count(var) == 0) {
            return -1;
        } else {
            int idx = getNum(str, begin + 2, end - 1);
            Array& arr = arrays[var];
            if (idx >= 0 && idx < arr.size && arr.elements.count(idx)) {
                return arr.elements[idx];
            } else {
                return -1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    string line;
    while (getline(cin, line) && line != ".") {
        int line_num = 1;
        int bug_line = INT_MAX;
        arrays.clear();
        do {
            if (bug_line == INT_MAX) {
                int pos = line.find('=');
                if (pos > -1) {
                    char var = line[0];
                    if (arrays.count(var) == 0) {
                        bug_line = min(bug_line, line_num);
                    }
                    Array& arr = arrays[var];
                    int idx = getNum(line, 2, pos - 2);
                    if (idx >= 0 && idx < arr.size) {
                        int num = getNum(line, pos + 1, line.size() - 1);
                        if (num < 0) {
                            bug_line = min(bug_line, line_num);
                        }
                        arr.elements[idx] = num;
                    } else {
                        bug_line = min(bug_line, line_num);
                    }
                } else {
                    char var = line[0];
                    if (arrays.count(var)) {
                        bug_line = min(bug_line, line_num);
                    }
                    int size = stoi(line.substr(2, line.size() - 3));
                    arrays[var] = Array(size);
                }
                ++line_num;
            }
        } while (getline(cin, line) && line != ".");
        if (bug_line == INT_MAX)
            bug_line = 0;
        cout << bug_line << endl;
    }

    return 0;
}
