#include <iostream>
#include <string>
#include <map>
using namespace std;

int N;
string id2name[10];
map<string, int> name2id;
int sent_money[10];
int received_money[10];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    string name;
    for (int i = 0; i < N; ++i) {
        cin >> name;
        id2name[i] = name;
        name2id[name] = i;
    }
    while ((cin >> name)) {
        int _money, count;
        cin >> _money >> count;
        if (count == 0) {
            continue;
        }
        _money = _money / count * count;
        sent_money[name2id[name]] = _money;
        string _name;
        for (int i = 0; i < count; ++i) {
            cin >> _name;
            received_money[name2id[_name]] += _money / count;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << id2name[i] << ' ';
        cout << received_money[i] - sent_money[i] << endl;
    }

    return 0;
}