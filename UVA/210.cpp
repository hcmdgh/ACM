#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while (Q--) {
        int N, T1, T2, T3, T4, T5, T;
        cin >> N >> T1 >> T2 >> T3 >> T4 >> T5 >> T;
        vector<queue<string>> commands(N);
        queue<int> blocked_queue;
        deque<int> ready_queue;
        vector<int> vars(26);
        cin.ignore(1024, '\n');
        for (int i = 0; i < N; ++i) {
            while (true) {
                string str;
                getline(cin, str);
                commands[i].emplace(str);
                if (str == "end")
                    break;
            }
            ready_queue.emplace_back(i);
        }

        bool locked = false;
        while (!ready_queue.empty()) {
            int program = ready_queue.front();
            ready_queue.pop_front();
            int t = 0;
            queue<string>& _commands = commands[program];
            bool blocked = false;
            while (t < T && !_commands.empty()) {
                string command = _commands.front();
                stringstream s(command);
                string str;
                s >> str;
                if (str.length() == 1) {
                    char var = str[0];
                    s >> str;
                    int val;
                    s >> val;
                    vars[var - 'a'] = val;
                    t += T1;
                } else if (str == "print") {
                    s >> str;
                    char var = str[0];
                    cout << program + 1 << ": " << vars[var - 'a'] << endl;
                    t += T2;
                } else if (str == "lock") {
                    if (locked) {
                        blocked_queue.emplace(program);
                        blocked = true;
                        break;
                    } else {
                        locked = true;
                        t += T3;
                    }
                } else if (str == "unlock") {
                    locked = false;
                    t += T4;
                    if (!blocked_queue.empty()) {
                        ready_queue.emplace_front(blocked_queue.front());
                        blocked_queue.pop();
                    }
                } else {
                    _commands.pop();
                    break;
                }
                _commands.pop();
            }
            if (!_commands.empty() && !blocked) {
                ready_queue.emplace_back(program);
            }
        }
        if (Q > 0) {
            cout << endl;
        }
    }

    return 0;
}
