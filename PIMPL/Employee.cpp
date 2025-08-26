#include "Employee.h"

class Employee::EmployeeImpl {
	std::string m_Name{};
	int m_BasicSalary{};
	int m_HRA{};
	int m_LTA{};
	int m_CA{};
	int m_PA{};
public:
	EmployeeImpl(const std::string& m_name, int m_basic_salary)
		: m_Name(m_name),
		m_BasicSalary(m_basic_salary) {
		m_HRA = 50;
		m_LTA = 10;
		m_PA = 5;
	}
	int GetTotalSalary()const;  // outside the class
	int ComputeTaxLiability()const {
		return m_BasicSalary * .2f;
	}
	const std::string GetName()const {
		return m_Name;
	}
};

#define ENABLE_INSIDE_EMPLOYEEIMPL_CHANGE
// Implemented outside the EmployeeImpl class 
int Employee::EmployeeImpl::GetTotalSalary() const {
#ifndef ENABLE_INSIDE_EMPLOYEEIMPL_CHANGE
	return m_BasicSalary + m_HRA + m_LTA + m_PA;
#elif defined ENABLE_INSIDE_EMPLOYEEIMPL_CHANGE
	return m_BasicSalary + m_HRA + m_LTA + m_PA + 1;
#endif
}

Employee::Employee(const std::string& m_name, int m_basic_salary) {
	m_pEmp = new EmployeeImpl{ m_name, m_basic_salary };
}

int Employee::GetTotalSalary() const {
	return m_pEmp->GetTotalSalary();
}

int Employee::ComputeTaxLiability() const {
	return m_pEmp->ComputeTaxLiability();
}

const std::string Employee::GetName() const {
	return m_pEmp->GetName();
}

Employee::~Employee() {
	delete m_pEmp;
}
