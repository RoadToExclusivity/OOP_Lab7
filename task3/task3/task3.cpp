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
		
		auto johnPtr = make_shared<CPoliceMan>(john);
		auto jimPtr = make_shared<CPoliceMan>(jim);
		ford.AddPassenger(johnPtr);
		ford.AddPassenger(jimPtr);

		cout << "1) Ford passengers: " << endl;
		for (size_t i = 0; i < ford.GetPassengerCount(); ++i)
		{
			cout << ford.GetPassenger(i).GetName() << " from " << ford.GetPassenger(i).GetDepartmentName() << endl;
		}
		cout << endl;

		ford.RemovePassenger(1);

		CTaxi toyota(MakeOfTheCar::TOYOTA, 2);
		auto rajahPtr = make_shared<CPerson>("Rajah Gandi");
		auto michaelPtr = make_shared<CRacer>("Michael Schumacher", 300);
		toyota.AddPassenger(rajahPtr);
		toyota.AddPassenger(michaelPtr);

		cout << "2) Toyota passengers: " << endl;
		for (size_t i = 0; i < toyota.GetPassengerCount(); ++i)
		{
			cout << toyota.GetPassenger(i).GetName() << endl;
		}
		cout << endl;
		cout << "Ford passengers: " << endl;
		for (size_t i = 0; i < ford.GetPassengerCount(); ++i)
		{
			cout << ford.GetPassenger(i).GetName() << endl;
		}

		toyota.RemovePassenger(0);
		toyota.AddPassenger(jimPtr);

		cout << endl << "3) Toyota passengers: " << endl;
		for (size_t i = 0; i < toyota.GetPassengerCount(); ++i)
		{
			cout << toyota.GetPassenger(i).GetName() << endl;
		}

		cout << endl;
		toyota.AddPassenger(rajahPtr);
	}
	catch (logic_error e)
	{
		cout << "Logic_error: " << e.what() << endl;
	}
	
	return 0;
}

