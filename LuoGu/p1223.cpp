#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
	int id, time;

	bool operator<(const Person& other) {
		return time < other.time ||
			(time == other.time && id < other.id);
	}
};

int main() {
	int N;
	cin >> N;
	vector<Person> people(N);
	for (int i = 0; i < N; ++i) {
		people[i].id = i + 1;
		cin >> people[i].time;
	}

	sort(people.begin(), people.end());
	for (int i = 0; i < N; ++i)
		cout << people[i].id << " ";
	cout << endl;

	long long sum = 0;
	long long total_time = 0;
	for (int i = 1; i < N; ++i) {
		sum += people[i - 1].time;
		total_time += sum;
	}
	double result = total_time * 1.0 / N;
	printf("%.2f\n", result);

	return 0;
}