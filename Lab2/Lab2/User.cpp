#include "User.h"


void User::print()
{
	cout << score << "  " << count << "  " << time << "  " << attempt;
}

bool User::operator<(const User& object)
{
	if (score != object.score) {
		if (score < object.score) {
			return true;
		}
		else {
			return false;
		}
	}

	if (count != object.count) {
		if (count < object.count) {
			return true;
		}
		else {
			return false;
		}
	}

	if (time != object.time) {
		if (time > object.time) {
			return true;
		}
		else {
			return false;
		}
	}

	if (attempt != object.attempt) {
		if (attempt > object.attempt) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool User::operator>(const User& object)
{
    return !(*this < object);
}

bool User::operator==(const User& object)
{
	return score == object.score && time == object.time && object.count == count && attempt == object.attempt;
}

ostream& operator<<(ostream& stream, User& object)
{
	stream << object.score << "  " << object.count << "  " << object.time << "  " << object.attempt;

	return stream;
}
