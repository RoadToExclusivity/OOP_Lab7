#include "stdafx.h"
#include "PoliceMan.h"


CPoliceMan::CPoliceMan(std::string name, std::string departmentName)
	:CPersonImpl<IPoliceMan>(move(name)), m_departmentName(move(departmentName))
{
}

std::string CPoliceMan::GetDepartmentName() const
{
	return m_departmentName;
}
