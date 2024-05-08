#pragma once
#include <string.h>
#include <vector>
using namespace std;
class SList {
private:
	vector<const char*> list;
public:
	SList() {};

	bool Contains(const char* str) {
		for (const char* s : list) {
			if (strcmp(s, str) == 0) {
				return true;
			}
		}
		return false;
	}

	void Add(const char* str) {
		if (!Contains(str)) {
			char* newStr = new char[strlen(str)];
			strcpy_s(newStr, strlen(str) + 1, str);
			list.push_back(newStr);
		}
	}

	void Concatenate(SList& otherList) {
		for (const char* str : otherList.list) {
			Add(str);
		}
	}
	~SList() {
		for (const char* str : list) {
			delete[] str;
		}
	}
};