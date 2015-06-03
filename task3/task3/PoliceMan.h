#pragma once
#include "PersonImplementation.h"
#include "PersonInterfaces.h"

class CPoliceMan : public CPersonImpl<IPoliceMan>
{
public:
	CPoliceMan(std::string name, std::string departmentName);
	virtual std::string GetDepartmentName() const;

private:
	std::string m_departmentName;
};

