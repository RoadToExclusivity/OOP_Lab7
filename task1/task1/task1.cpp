#include "stdafx.h"

using namespace std;

template <typename T, typename Less>
bool FindMaxEx(const vector<T> &arr, T &maxValue, const Less &less)
{
	if (arr.empty())
	{
		return false;
	}

	size_t maxIndex = 0;
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (less(arr[maxIndex], arr[i]))
		{
			maxIndex = i;
		}
	}

	maxValue = arr[maxIndex];
	return true;
}

struct Student
{
	string name;
	int age;
	int weight;
	int height;
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Student> students = {
			{ "First", 20, 100, 150 },
			{ "Second", 21, 87, 4188 },
			{ "Third", 22, 62, 199 },
			{ "Fourth", 23, 35, 245 }
	};

	Student oldestStudent;
	assert(FindMaxEx(students, oldestStudent, [](const Student &a, const Student &b)
	{
		return a.age < b.age;
	}));
	assert(oldestStudent.name == "Fourth");

	Student heaviestStudent;
	assert(FindMaxEx(students, heaviestStudent, [](const Student &a, const Student &b)
	{
		return a.weight < b.weight;
	}));
	assert(heaviestStudent.name == "First");

	Student tallestStudent;
	assert(FindMaxEx(students, tallestStudent, [](const Student &a, const Student &b)
	{
		return a.height < b.height;
	}));
	assert(tallestStudent.name == "Second");

	return 0;
}

