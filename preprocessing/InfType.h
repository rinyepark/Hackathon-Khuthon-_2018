#ifndef INFTYPE_H_
#define INFTYPE_H_

#include "StoreType.h"
#include <vector>
using namespace std;

class InfType {
public:

	InfType();
	InfType(string inName);



	void AddItem(StoreType item);
	bool SearchItem(string inId);


	bool operator==(InfType &item);
	bool operator!=(InfType &item);
	bool operator>(InfType &item);
	bool operator<(InfType &item);

	string name;
	vector<StoreType> InfList;
};

#endif // !INFTYPE_H_
