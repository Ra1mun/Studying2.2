#pragma once
#include <string.h>
#include <vector>
using namespace std;
class SList {
private:
	vector<const char*> list;
public:
	SList() {};

	void Add(const char* str) {
		int len = strlen(str);
		char* newStr = new char[len + 1];
		for (int i = 0; i < len; i++) {
			newStr[i] = str[i];
		}
		newStr[len] = '\0';
		list.push_back(newStr);
	}

	void Concatenate(SList& otherList) {
		for (const char* str : otherList.list) {
			Add(str);
		}
	}

	friend ostream& operator<<(std::ostream& stream, const SList& obj)
	{
		for (const char* str : obj.list) {
			for (int i = 0; i < strlen(str); i++) {
				stream << str[i];
			}
			stream << '\n';
		}
		return stream;
	}

	~SList() {
		for (const char* str : list) {
			delete[] str;
		}
	}
};