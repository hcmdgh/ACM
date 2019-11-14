#include <iostream>
#include <map>
using namespace std;

typedef pair<int, int> Student;

int main() {
    ios::sync_with_stdio(false);
    int N;
    while (cin >> N && N > 0) {
        map<Student, int> _map;
        for (int i = 0; i < N; ++i) {
            Student student;
            cin >> student.first >> student.second;
            Student _student = Student(student.second, student.first);
            auto iter = _map.find(_student);
            if (iter != _map.end()) {
                --(iter->second);
                if (iter->second <= 0) {
                    _map.erase(iter);
                }
            } else {
                ++_map[student];
            }
        }
        if (_map.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
