#pragma once
#include <iostream>

class String
{
private:
	char* data;
	size_t size;
public:
	String(std::size_t size);
	~String();

	String(const String& s);
	String(String&& s) noexcept;
	String(const char* cs);

	String& operator=(String s);

	String& operator+=(const String& s);
	String operator+(const String& s);
	friend String operator+(const char* s1, const String& s2);

	friend std::ostream& operator<<(std::ostream& os, const String& ms);

	bool operator<(const String& rhs) const;
};

