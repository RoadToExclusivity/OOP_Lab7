#include "stdafx.h"
#include "CMySet.h"

using namespace std;

struct Student
{
	string name;

	Student(string sName)
		:name(move(sName))
	{
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Student students[3][5] = { { "AA", "BB", "CC", "DD", "EE" }, { "FF", "AA", "GG", "HH", "CC" }, { "DD", "QQ", "WW", "TT", "UU" } };
	CMySet<Student> allStudents;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 5; ++j)
		{
			allStudents.Add(students[i][j]);
		}
	}
	
	CMySet<Student> winners;
	winners.Add(Student("BB"));
	winners.Add(Student("GG"));
	winners.Add(Student("QQ"));

	CMySet<Student> res = allStudents.Difference(winners);

	for (size_t i = 0; i < res.Count(); ++i)
	{
		cout << res.Get(i).name << endl;
	}

	return 0;
}

