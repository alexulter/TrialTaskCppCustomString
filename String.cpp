#include "String.h"

String::String(std::size_t size) : data(new char[size]), size(size)
{
}

String::~String()
{
	delete[] data;
}

String::String(const String& s) : data(new char[s.size]), size(s.size)
{
	std::memcpy(data, s.data, s.size);
}

String::String(String&& s) noexcept : data(s.data), size(s.size)
{
	s.data = nullptr;
	s.size = 0;
}

String& String::operator=(String s)
{
	std::swap(data, s.data);
	std::swap(size, s.size);
	return *this;
}

String& String::operator+=(const String& s)
{
	String sumData = String(size + s.size);
	sumData.data = new char[sumData.size];

	std::memcpy(sumData.data, data, size);
	std::memcpy(&sumData.data[size], s.data, s.size);

	std::swap(data, sumData.data);
	std::swap(size, sumData.size);
	return *this;
}

String String::operator+(const String& s)
{
	String sumData = String(size + s.size);
	sumData.data = new char[sumData.size];

	std::memcpy(sumData.data, data, size);
	std::memcpy(&sumData.data[size], s.data, s.size);

	return sumData;
}

bool String::operator<(const String& rhs) const
{
	for (int i = 0; i < std::min(size, rhs.size); i++)
	{
		if (data[i] == rhs.data[i]) continue;
		if (data[i] < rhs.data[i]) return true;
		return false;
	}
	return size < rhs.size;
}

String operator+(const char* s1, const String& s2)
{
	auto tmp = String(s1);
	return tmp + s2;
}

String::String(const char* cs)
{
	size = strlen(cs);
	data = new char[size];
	std::memcpy(data, cs, size);
}

std::ostream& operator<<(std::ostream& os, const String& ms)
{
	for (int i = 0; i < ms.size; i++)
	{
		os << ms.data[i];
	}
	return os;
}