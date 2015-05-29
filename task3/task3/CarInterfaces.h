#pragma once

#include "VehicleInterfaces.h"
#include "PersonInterfaces.h"

enum MakeOfTheCar
{
	BMW,
	MITSUBISHI,
	FORD,
	MERCEDES,
	TOYOTA,
	KIA,
	FERRARI,
	PORSCHE,
	LEXUS,
	NISSAN,
	INIFINITI,
};

template <typename Passenger>
class ICar : public IVehicle<Passenger>
{
public:
	virtual MakeOfTheCar GetMakeOfTheCar() const = 0;
};

class IBus : public IVehicle<IPerson>
{
};

class ITaxi : public ICar<IPerson>
{
};

class IPoliceCar : public ICar<IPoliceMan>
{
};

class IRacerCar : public ICar<IRacer>
{
};