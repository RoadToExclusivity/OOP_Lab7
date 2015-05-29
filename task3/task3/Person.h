#pragma once
#include "PersonImplementation.h"
#include "PersonInterfaces.h"

class CPerson : public CPersonImpl<IPerson>
{
public:
	CPerson(std::string name);
};

