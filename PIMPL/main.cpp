
#include <iostream>

#include "Employee.h"

int main() {
	Employee emp{ "Umar", 1000 };
	std::cout << "Name:" << emp.GetName() << std::endl;
	std::cout << "Total salary:" << emp.GetTotalSalary() << std::endl;
	std::cout << "Tax : " << emp.ComputeTaxLiability() << std::endl;
}
