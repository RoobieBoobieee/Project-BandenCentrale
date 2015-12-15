#include <iostream>
#include <string>

struct StringSerializer
{
	std::string& value;
	StringSerializer(std::string const& v):value(const_cast<std::string&>(v)) {}
	friend std::ostream& operator<<(std::ostream& stream, StringSerializer const& data)
	{
		stream << data.value.size() << ':' << data.value;
		return stream;
	}
	friend std::istream& operator>>(std::istream& stream, StringSerializer const& data)
	{
		std::size_t size;
		char mark(' ');
		stream >> size >> mark;
		if (!stream || mark != ':')
		{
			stream.setstate(std::ios::badbit);
			return stream;
		}
		data.value.resize(size);
		stream.read(&data.value[0], size);
	}
};