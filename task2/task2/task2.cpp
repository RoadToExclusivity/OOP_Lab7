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

	bool operator<(const Student &r) const
	{
		return name < r.name;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Student students[3][15] = { { "AAlitov", "ABogdanov", "ABorisov", "AVeselov", "AVinokurov", "AGavrilenko", "ADolgushev", "AEmelyanov", "AEfremov", "AJiryakov", "AIvanov", "AKalinnikov", "AKirillov", "AKornev", "AKorotkov"},
	{ "BAlitov", "BBogdanov", "BBorisov", "BVeselov", "BVinokurov", "BGavrilenko", "BDolgushev", "BEmelyanov", "BEfremov", "BJiryakov", "BIvanov", "BKalinnikov", "BKirillov", "BKornev", "BKorotkov" }, 
	{ "CAlitov", "CBogdanov", "CBorisov", "CVeselov", "CVinokurov", "CGavrilenko", "CDolgushev", "CEmelyanov", "CEfremov", "CJiryakov", "CIvanov", "CKalinnikov", "CKirillov", "CKornev", "CKorotkov" } };
	
	CMySet<Student> allStudents;
	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 15; ++j)
		{
			allStudents.Add(students[i][j]);
		}
	}

	srand(time(0));
	CMySet<Student> participants;
	for (size_t i = 0; i < 3; ++i)
	{
		CMySet<int> nums;
		for (size_t j = 0; j < 5;)
		{
			size_t index = rand() % 15;
			if (!nums.Contains(index))
			{
				nums.Add(index);
				participants.Add(students[i][index]);
				j++;
			}
		}
	}

	CMySet<Student> winners;
	CMySet<int> nums;
	for (size_t i = 0; i < 3;)
	{
		size_t index = rand() % 15;
		if (!nums.Contains(index))
		{
			nums.Add(index);
			winners.Add(participants.Get(index));
			i++;
		}
	}

	CMySet<Student> res = allStudents.Difference(winners);
	for (size_t i = 0; i < res.Count(); ++i)
	{
		cout << res.Get(i).name << endl;
	}

	cout << endl << "Winners: " << endl;
	for (size_t i = 0; i < winners.Count(); ++i)
	{
		cout << winners.Get(i).name << endl;
	}

	return 0;
}

