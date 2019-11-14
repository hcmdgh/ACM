#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	int id;
	int chinese;
	int math;
	int english;
	int total;

	Student(int id = 0, int chinese = 0, int math = 0, int english = 0) :
		id(id), chinese(chinese), math(math), english(english) {
		total = chinese + english + math;
	}

	bool operator<(const Student& other) {
		if (total < other.total ||
			(total == other.total && chinese < other.chinese) ||
			(total == other.total && chinese == other.chinese && id > other.id))
			return false;
		else
			return true;
	}
};

int main() {
	int n;
	cin >> n;
	vector<Student> students(n);
	for (int i = 0; i < n; ++i) {
		int chinese, math, english;
		cin >> chinese >> math >> english;
		students[i] = Student(i + 1, chinese, math, english);
	}
	partial_sort(students.begin(), students.begin() + 5, students.end());
	
	for (int i = 0; i < 5; ++i) {
		cout << students[i].id << " " << students[i].total << endl;
	}

	return 0;
}