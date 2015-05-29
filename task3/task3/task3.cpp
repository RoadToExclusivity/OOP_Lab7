#include "stdafx.h"
#include "CarsClasses.h"
#include "Person.h"
#include "Racer.h"
#include "PoliceMan.h"
#include "CarInterfaces.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		CPoliceMan john("John Smith", "North-west department"), jim("Jim Clark", "South-east department");
		CPoliceCar ford(MakeOfTheCar::FORD, 5);
		ford.AddPassenger(make_shared<CPoliceMan>(john));
		ford.AddPassenger(make_shared<CPoliceMan>(jim));

		for (size_t i = 0; i < ford.GetPassengerCount(); ++i)
		{
			cout << ford.GetPassenger(i).GetName() << ford.GetPassenger(i).GetDepartmentName() << endl;
		}
	}
	catch (exception e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	
	return 0;
}

