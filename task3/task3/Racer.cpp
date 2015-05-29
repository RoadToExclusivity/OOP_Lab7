#include "stdafx.h"
#include "Racer.h"


CRacer::CRacer(std::string name, size_t award)
	:CPersonImpl<IRacer>(move(name)), m_award(award)
{
}

size_t CRacer::GetAwardsCount() const
{
	return m_award;
}