#pragma once

class IBasicVehicle
{
public:
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual size_t GetPlaceCount() const = 0;
	virtual size_t GetPassengerCount() const = 0;
	virtual void RemoveAllPassengers() = 0;
};

template <typename Passenger>
class IVehicle : public IBasicVehicle
{
public:
	virtual void AddPassenger(std::shared_ptr<Passenger> pPassenger) = 0;
	virtual const Passenger& GetPassenger(size_t index) const = 0;
	virtual void RemovePassenger(size_t index) = 0;
};
