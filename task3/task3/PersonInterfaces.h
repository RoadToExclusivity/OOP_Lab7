#pragma once

class IPerson
{
public:
	virtual std::string GetName() const = 0;
};

class IPoliceMan : public IPerson
{
	virtual std::string GetDepartmentName() const = 0;
};

class IRacer : public IPerson
{
	virtual size_t GetAwardsCount() const = 0;
};