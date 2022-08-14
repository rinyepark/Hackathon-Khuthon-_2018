#include "InfType.h"

InfType::InfType() {
}

InfType::InfType(string inName) {
	name = inName;
}


// operator== overloading
bool InfType::operator==(InfType &item) {
	if (this->name.compare(item.name) == 0)
		return true;
	else
		return false;
}


// operator!= overloading
bool InfType::operator!=(InfType &item) {
	if (this->name.compare(item.name) != 0)
		return true;
	else
		return false;
}


// operator> overloading
bool InfType::operator>(InfType &item) {
	if (this->name.compare(item.name) > 0)
		return true;
	else
		return false;
}

// operator< overloading
bool InfType::operator<(InfType &item) {
	if (this->name.compare(item.name) < 0)
		return true;
	else
		return false;
}
