#pragma once
#include "stdafx.h"

template<typename T, typename Comp = std::less<T>>
class CMySet
{
public:
	CMySet()
		:m_elements()
	{
	}
	
	size_t Count() const
	{
		return m_elements.size();
	}

	const T& Get(size_t index) const
	{
		if (index < 0 || index >= m_elements.size())
		{
			std::out_of_range("Wrong index");
		}

		return m_elements[index];
	}

	bool Empty() const
	{
		return m_elements.empty();
	}

	bool Contains(const T &elem) const
	{
		Comp &comp = std::less<T>();
		for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (!comp(elem, m_elements[i]) && !comp(m_elements[i], elem))
			{
				return true;
			}
		}

		return false;
	}

	bool ContainsSubset(const CMySet<T> &other) const
	{
		for (size_t i = 0; i < other.m_elements.size(); ++i)
		{
			if (Contains(other.m_elements[i]))
			{
				return true;
			}
		}

		return false;
	}

	bool EqualSubsets(const CMySet<T> &other) const
	{
		return ContainsSubset(other) && other.ContainsSubset(*this);
	}

	void Add(const T &newElem)
	{
		if (!Contains(newElem))
		{
			m_elements.push_back(newElem);
		}
	}

	void Erase(const T &elem)
	{
		for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (m_elements[i] == elem)
			{
				m_elements.erase(m_elements.begin() + i);
				return;
			}
		}
	}

	CMySet<T> Union(const CMySet<T> &other) const
	{
		CMySet<T> result = other;
		
		for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (!other.Contains(m_elements[i]))
			{
				result.Add(m_elements[i]);
			}
		}

		return result;
	}

	CMySet<T> Intersection(const CMySet<T> &other) const
	{
		CMySet<T> result;

		for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (other.Contains(m_elements[i]))
			{
				result.Add(m_elements[i]);
			}
		}

		return result;
	}

	CMySet<T> Difference(const CMySet<T> &other) const
	{
		CMySet<T> result;

		for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (!other.Contains(m_elements[i]))
			{
				result.Add(m_elements[i]);
			}
		}

		return result;
	}

	CMySet<T> SymmetricDifference(const CMySet<T> &other) const
	{
		CMySet<T> result;

		for (size_t i = 0; i < m_elements.size(); ++i)
		{
			if (!other.Contains(m_elements[i]))
			{
				result.Add(m_elements[i]);
			}
		}

		for (size_t i = 0; i < other.m_elements.size(); ++i)
		{
			if (!Contains(other.m_elements[i]))
			{
				result.Add(other.m_elements[i]);
			}
		}

		return result;
	}

private:
	std::vector<T> m_elements;
};