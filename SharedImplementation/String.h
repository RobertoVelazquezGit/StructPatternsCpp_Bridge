#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstddef>
#include <cstring>
#define DOTRACE
class String
{
	char* m_pString{};
	size_t m_Length{};
	void Create(const char* pstr);
public:
	String();
	String(const char* pstr);
	String(const String& other);
	String(String&& other)noexcept;

	String& operator =(const String& other);
	String& operator=(String&& other)noexcept;

	~String();
	size_t GetLength()const {
		return m_Length;
	}
	const char* GetString()const {
		return m_pString;
	}
	void Assign(const char* pstr);
	friend bool operator < (const String& left, const String& right) {
		return strcmp(left.m_pString, right.m_pString) < 0;
	}
	friend bool operator > (const String& left, const String& right) {
		return strcmp(left.m_pString, right.m_pString) > 0;
	}
	friend bool operator != (const String& left, const String& right) {
		return strcmp(left.m_pString, right.m_pString) != 0;
	}
	friend bool operator == (const String& left, const String& right) {
		return strcmp(left.m_pString, right.m_pString) == 0;
	}

	friend bool operator == (const char* left, const String& right) {
		return strcmp(left, right.m_pString) == 0;
	}
	friend bool operator != (const char* left, const String& right) {
		return strcmp(left, right.m_pString) != 0;
	}
	friend bool operator != (const String& left, const char* right) {
		return strcmp(left.m_pString, right) != 0;
	}
	friend bool operator == (const String& left, const char* right);  // Defined in the cpp
};
