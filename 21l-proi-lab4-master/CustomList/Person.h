#pragma once
#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
public:
	Person() = default;
	Person(std::string Name);
	std::string get_name();

	Person& operator=(Person& person);
	bool operator<(const Person& person);
	bool operator==(const Person& person) const;
	bool operator==(bool n) const;
	bool operator!=(bool n) const;
};

Person::Person(std::string Name)
{
	name = Name;
}

std::string Person::get_name() {
	return name;
}

Person& Person::operator=(Person& person)
{
	name = person.get_name();
	return *this;
}

bool Person::operator<(const Person& person)
{
	if (name.compare(person.name) < 0)
	{
		return true;
	}
	return false;
}

bool Person::operator==(const Person& person) const
{
	return name == person.name;
}

bool Person::operator==(bool n) const
{
	bool notEmpty;
	if (name.compare("") == 0)
	{
		notEmpty = false;
	}
	else
		notEmpty = true;
	return notEmpty == n;
}

bool Person::operator!=(bool n) const
{
	bool notEmpty;
	if (name.compare("") == 0)
	{
		notEmpty = false;
	}
	else
		notEmpty = true;
	return notEmpty != n;
}