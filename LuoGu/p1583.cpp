#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
	int id, weight;

	bool operator<(const Person& other) {
		return weight > other.weight ||
			(weight == other.weight && id < other.id);
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> E(10);
	for (int i = 0; i < 10; ++i)
		cin >> E[i];
	vector<Person> persons(n);
	for (int i = 0; i < n; ++i) {
		persons[i].id = i + 1;
		cin >> persons[i].weight;
	}
	sort(persons.begin(), persons.end());
	for (int i = 0; i < n; ++i) {
		persons[i].weight += E[i % 10];
	}
	partial_sort(persons.begin(), persons.begin() + k, persons.end());
	for (int i = 0; i < k; ++i) {
		cout << persons[i].id << " ";
	}
	cout << endl;

	return 0;
}