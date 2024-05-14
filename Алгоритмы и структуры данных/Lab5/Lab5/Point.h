#pragma once

struct Point
{
public:
	int x, y;
	Point() : x(0), y(0) { }
	Point(int x, int y) : x(x), y(y) { }

    friend std::ostream& operator<<(std::ostream& stream, const Point& obj)
    {
        stream << obj.x << ';' << obj.y << '\n';

        return stream;
    }
};