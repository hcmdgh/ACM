#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int max_money = 0;
	string max_money_name;
	int total_money = 0;
	for (int i = 0; i < N; ++i) {
		string name;
		int final_score;
		int class_score;
		char is_leader;
		char is_western;
		int paper_num;
		cin >> name >> final_score >> class_score >> is_leader >>
			is_western >> paper_num;
		int money = 0;
		if (final_score > 80 && paper_num >= 1)
			money += 8000;
		if (final_score > 85 && class_score > 80)
			money += 4000;
		if (final_score > 90)
			money += 2000;
		if (final_score > 85 && is_western == 'Y')
			money += 1000;
		if (class_score > 80 && is_leader == 'Y')
			money += 850;
		if (money > max_money) {
			max_money = money;
			max_money_name = name;
		}
		total_money += money;
	}

	cout << max_money_name << endl;
	cout << max_money << endl;
	cout << total_money << endl;

	return 0;
}