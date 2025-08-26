#pragma once
#include "Implementor.h"

class Abstraction
{
protected:
	Implementor* m_pImplementor{};
public:
	explicit Abstraction(Implementor* m_p_implementor)
		: m_pImplementor(m_p_implementor) {
	}
	virtual void Operation() = 0;
	virtual ~Abstraction() = default;
};
