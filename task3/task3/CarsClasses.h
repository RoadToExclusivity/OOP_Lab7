#pragma once
#include "CarInterfaces.h"
#include "CCarImplementation.h"
#include "PersonImplementation.h"
#include "PersonInterfaces.h"

class CTaxi : public CCarImpl<CVehicleImpl<ITaxi, IPerson>>
{
	CTaxi(const MakeOfTheCar &make, size_t places)
		:CCarImpl<CVehicleImpl<ITaxi, IPerson>>(make, places)
	{
	}
};

class CPoliceCar : public CCarImpl<CVehicleImpl<IPoliceCar, IPoliceMan>>
{
	CPoliceCar(MakeOfTheCar make, size_t places)
		:CCarImpl<CVehicleImpl<IPoliceCar, IPoliceMan>>(make, places)
	{
	}
};

class CRacingCar : public CCarImpl<CVehicleImpl<IRacerCar, IRacer>>
{
	CRacingCar(const MakeOfTheCar &make, size_t places)
		:CCarImpl<CVehicleImpl<IRacerCar, IRacer>>(make, places)
	{
	}
};

class CBus : public CVehicleImpl<IBus, IPerson>
{
	CBus(size_t places)
		:CVehicleImpl<IBus, IPerson>(places)
	{
	}
};