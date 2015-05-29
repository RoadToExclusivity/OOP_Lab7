#pragma once
#include "CarInterfaces.h"
#include "CVehicleImplementation.h"

template <typename Base>
class CCarImpl : public Base
{
public:
	CCarImpl(const MakeOfTheCar &make, size_t places)
		:Base(places), m_make(make)
	{
	}

	MakeOfTheCar GetMakeOfTheCar() const
	{
		return m_make;
	}

private:
	MakeOfTheCar m_make;
};