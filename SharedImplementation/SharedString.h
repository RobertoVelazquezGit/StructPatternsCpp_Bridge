#pragma once
#include <unordered_map>

#include "String.h"

class SharedString
{
	inline static std::unordered_map<String*, size_t*> m_Strings{};
	String* m_pString{};
	void RemoveString();
public:
	SharedString() = default;
	SharedString(const char* pstr);
	SharedString(const SharedString& other);
	SharedString(SharedString&& other)noexcept;

	SharedString& operator =(const SharedString& other);
	SharedString& operator=(SharedString&& other)noexcept;

	~SharedString();

	size_t GetLength()const;
	const char* GetString()const;
	void Assign(const char* pstr);
};
