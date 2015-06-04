#pragma once
#include "stdafx.h"

template<typename T, typename Comp = std::less<T>>
class CMySet
{
public:
	struct Item
	{
		Item(T value, std::shared_ptr<Item> &&previous)
			:value(move(value)), previous(move(previous))
		{
		}

		T value;
		std::shared_ptr<Item> previous;
	};

	CMySet()
		:m_elements(nullptr), m_comp(Comp()), m_size(0)
	{
	}
	
	~CMySet()
	{
		auto curPtr = m_elements;
		while (curPtr)
		{
			auto prevPtr = curPtr->previous;
			curPtr = nullptr;
			curPtr = prevPtr;
		}
	}

	CMySet<T>& operator=(const CMySet<T> &other)
	{
		if (std::addressof(other) != this)
		{
			auto curPtr = other.m_elements;
			std::unique_ptr<Item> prevPtr = make_shared<Item>(curPtr->value, nullptr);
			m_elements = prevPtr;
			while (curPtr)
			{
				auto newPtr = make_shared<Item>(curPtr->value, nullptr);
				prevPtr->previous = newPtr;
				prevPtr = newPtr;
				curPtr = curPtr->previous;
			}
			m_size = other.m_size;
			m_comp = other.m_comp;
		}
	}

	CMySet<T>& operator=(CMySet<T> &&other)
	{
		if (m_elements)
		{
			auto curPtr = m_elements;
			while (curPtr)
			{
				auto prevPtr = curPtr->previous;
				curPtr = nullptr;
				curPtr = prevPtr;
			}
		}
		m_elements = other.m_elements;
		m_size = other.m_size;
		m_comp = other.m_comp;

		other.m_elements = nullptr;
	}

	size_t Count() const
	{
		return m_size;
	}

	const T& Get(size_t index) const
	{
		if (index < 0 || index >= m_size)
		{
			std::out_of_range("Wrong index");
		}

		auto curPtr = m_elements;
		while (index--)
		{
			curPtr = curPtr->previous;
		}

		return curPtr->value;
	}

	bool Empty() const
	{
		return !m_elements;
	}

	bool Contains(const T &elem) const
	{
		auto curPtr = m_elements;
		while (curPtr)
		{
			if (!m_comp(elem, curPtr->value) && !m_comp(curPtr->value, elem))
			{
				return true;
			}
			curPtr = curPtr->previous;
		}

		return false;
	}

	bool ContainsSubset(const CMySet<T> &other) const
	{
		auto curPtr = other.m_elements;
		while (curPtr)
		//for (size_t i = 0; i < other.m_elements.size(); ++i)
		{
			if (!Contains(curPtr->value))
			{
				return false;
			}
			curPtr = curPtr->previous;
		}

		return true;
	}

	bool EqualSubsets(const CMySet<T> &other) const
	{
		return ContainsSubset(other) && other.ContainsSubset(*this);
	}

	void Add(const T &newElem)
	{
		if (!Contains(newElem))
		{
			m_elements = make_shared<Item>(newElem, std::move(m_elements));
			m_size++;
		}
	}

	void Erase(const T &elem)
	{
		auto curPtr = other.m_elements;
		std::unique_ptr<Item> prevPtr = nullptr;
		while (curPtr)
		//for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (!m_comp(curPtr->value, elem) && !m_comp(elem, curPtr->value))
			{
				//m_elements.erase(m_elements.begin() + i);
				if (!prevPtr)
				{
					m_elements = curPtr->previous;
				}
				else
				{
					prevPtr->previous = curPtr->previous;
					curPtr = nullptr;
				}
				m_size--;
				return;
			}
			prevPtr = curPtr;
			curPtr = curPtr->previous;
		}
	}

	CMySet<T> Union(const CMySet<T> &other) const
	{
		CMySet<T> result = other;
		
		auto curPtr = m_elements;
		while (curPtr)
		//for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (!other.Contains(curPtr->value))
			{
				result.ForceAdd(curPtr->value);
			}
			curPtr = curPtr->previous;
		}

		return result;
	}

	CMySet<T> Intersection(const CMySet<T> &other) const
	{
		CMySet<T> result;

		auto curPtr = m_elements;
		while (curPtr)
		//for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (other.Contains(curPtr->value))
			{
				result.ForceAdd(curPtr->value);
			}
			curPtr = curPtr->previous;
		}

		return result;
	}

	CMySet<T> Difference(const CMySet<T> &other) const
	{
		CMySet<T> result;
		
		auto curPtr = m_elements;
		while (curPtr)
		//for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (!other.Contains(curPtr->value))
			{
				result.ForceAdd(curPtr->value);
			}
			curPtr = curPtr->previous;
		}

		return result;
	}

	CMySet<T> SymmetricDifference(const CMySet<T> &other) const
	{
		CMySet<T> result = Difference(other);

		auto curPtr = other.m_elements;
		while (curPtr)
		//for (size_t i = 0; i < other.m_elements.size(); ++i)
		{
			if (!Contains(curPtr->value))
			{
				result.ForceAdd(curPtr->value);
			}
			curPtr = curPtr->previous;
		}

		return result;
	}

private:
	std::shared_ptr<Item> m_elements;
	size_t m_size;
	Comp m_comp;

	void ForceAdd(const T &newElem)
	{
		m_elements = make_shared<Item>(newElem, std::move(m_elements));
		m_size++;
	}
};