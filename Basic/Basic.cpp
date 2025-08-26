
#include "Abstraction.h"
#include "ConcreteImplementorA.h"
#include "ConcreteImplementorB.h"
#include "RefinedAbstraction.h"

int main() {
	ConcreteImplementorA impl;
	Abstraction* p = new RefinedAbstraction{ &impl };
	p->Operation();
}

