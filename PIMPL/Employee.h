#pragma once
#include <string>

class Employee
{
	class EmployeeImpl;
	EmployeeImpl* m_pEmp{};
public:
	Employee(const std::string& m_name, int m_basic_salary);
	int GetTotalSalary()const;
	int ComputeTaxLiability()const;
	const std::string GetName()const;
	~Employee();
};
