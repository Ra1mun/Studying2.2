#pragma once
#include <iostream>
using namespace std;
class User {
private:
	int count, time, score, attempt;
public:
	User() {
		count = rand() % 6;
		time = 60 + rand() % 241;
		score = rand() % 26;
		attempt = rand() % 21;
	}
	void print();
	bool operator<(const User& object);
	bool operator>(const User& object);
	bool operator==(const User& object);
	friend ostream& operator<<(ostream& stream, User& object);
};
