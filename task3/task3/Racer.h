#pragma once
#include "PersonImplementation.h"
#include "PersonInterfaces.h"

class CRacer : public CPersonImpl<IRacer>
{
public:
	CRacer(std::string name, size_t award);
	virtual size_t GetAwardsCount() const;

private:
	size_t m_award;
};

