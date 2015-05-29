#pragma once

template <typename Base, typename Passenger>
class CVehicleImpl : public Base
{
public:
	CVehicleImpl(size_t places)
		:m_passengers(places), m_occupied(0)
	{
	}

	virtual bool IsEmpty() const
	{
		return m_occupied == 0;
	}

	virtual bool IsFull() const
	{
		return m_occupied == m_passengers.size();
	}

	virtual size_t GetPlaceCount() const
	{
		return m_passengers.size();
	}

	virtual size_t GetPassengerCount() const
	{
		return m_occupied;
	}

	virtual void AddPassenger(std::shared_ptr<Passenger> pPassenger)
	{
		if (IsFull())
		{
			throw std::logic_error("No free places");
		}

		m_passengers.push_back(pPassenger);
		m_occupied++;
	}

	virtual const Passenger& GetPassenger(size_t index) const override
	{
		if (index < 0 || index >= m_passengers.size())
		{
			throw std::out_of_range("Wrong index");
		}

		return *m_passengers[index];
	}

	virtual void RemovePassenger(size_t index)
	{
		if (index < 0 || index >= m_passengers.size())
		{
			throw std::out_of_range("Wrong index");
		}

		m_passengers.erase(m_passengers.begin() + index);
		m_occupied--;
	}
	
	virtual void RemoveAllPassengers()
	{
		m_passengers.clear();
		m_occupied = 0;
	}

private:
	std::vector<std::shared_ptr<Passenger>> m_passengers;
	size_t m_occupied;
};