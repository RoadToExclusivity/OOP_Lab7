#pragma once

template <typename Base>
class CPersonImpl : public Base
{
public:
	CPersonImpl(std::string &&name)
		:m_name(move(name))
	{
	}

	virtual std::string GetName() const
	{
		return m_name;
	}
private:
	std::string m_name;
};