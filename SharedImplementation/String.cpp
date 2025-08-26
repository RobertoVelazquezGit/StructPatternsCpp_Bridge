#include "String.h"
#include <iostream>
#ifdef DOTRACE
#define TRACETHIS std::cout << __FUNCSIG__ << std::endl
#else
#define TRACETHIS
#endif

void String::Create(const char* pstr) {
	m_Length = strlen(pstr);
	m_pString = new char[m_Length + 1];
	strcpy(m_pString, pstr);
}

String::String() {
	TRACETHIS;
	m_pString = new char[1] { '\0' };
}

String::String(const char* pstr) {
	TRACETHIS;
	Create(pstr);
}

String::String(const String& other) {
	TRACETHIS;
	Create(other.m_pString);
}

String::String(String&& other) noexcept {
	TRACETHIS;
	m_Length = other.m_Length;
	m_pString = other.m_pString;

	other.m_Length = 0;
	other.m_pString = nullptr;
}

String& String::operator=(const String& other) {
	TRACETHIS;
	if (this != &other) {
		Assign(other.m_pString);
	}
	return *this;
}

String& String::operator=(String&& other) noexcept {
	TRACETHIS;
	if (this != &other) {
		m_Length = other.m_Length;
		m_pString = other.m_pString;

		other.m_Length = 0;
		other.m_pString = nullptr;
	}
	return *this;
}

String::~String() {
	TRACETHIS;
	delete[]m_pString;
}

void String::Assign(const char* pstr) {
	delete[]m_pString;
	Create(pstr);
}

bool operator == (const String& left, const char* right) {
	TRACETHIS;
	return strcmp(left.m_pString, right) == 0;
}
