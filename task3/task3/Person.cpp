#include "stdafx.h"
#include "Person.h"

CPerson::CPerson(std::string name)
	:CPersonImpl<IPerson>(move(name))
{
}

