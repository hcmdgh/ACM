#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cassert>
using namespace std;

map<string, string> books;
struct Cmp {
    bool operator()(const string& title1, const string& title2) const {
        return books[title1] < books[title2] || (books[title1] == books[title2] && title1 < title2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    string str;
    set<string, Cmp> shelf;
    while (getline(cin, str) && str != "END") {
        int length = str.length();
        int pos = -1;
        for (int i = 1; i < length; ++i) {
            if (str[i] == '\"') {
                pos = i;
                break;
            }
        }
        assert(pos != -1);
        string title = str.substr(1, pos - 1);
        string author = str.substr(pos + 5);
        books[title] = author;
        shelf.emplace(title);
    }
    set<string, Cmp> returned;
    while (getline(cin, str) && str != "END") {
        string command = str.substr(0, 6);
        int length = str.length();
        if (command == "BORROW") {
            string title = str.substr(8, length - 9);
            shelf.erase(title);
        } else if (command == "RETURN") {
            string title = str.substr(8, length - 9);
            returned.emplace(title);
        } else if (command == "SHELVE") {
            for (const string& title : returned) {
                auto res = shelf.emplace(title);
                auto iter = res.first;
                if (iter == shelf.begin()) {
                    cout << "Put \"" << title << "\" first" << endl;
                } else {
                    --iter;
                    cout << "Put \"" << title << "\" after \"" << *iter << '\"' << endl;
                }
            }
            returned.clear();
            cout << "END" << endl;
        } else {
            assert(0);
        }
    }

    return 0;
}
