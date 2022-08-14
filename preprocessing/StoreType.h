#ifndef STORETYPE_H_
#define STORETYPE_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class StoreType {

public:
	StoreType();

	string store_id;
	string store_name;
	//string store_BigCategory;
	//string store_Mid1Category;
	//string store_Mid2Category;

	//string BigID;

	//string Mid1ID;
	string MidCID;
	//string store_SmlCategory;
	string SmlCID;

	string store_city;
	//string cityID;
	//string district;
	//string viliage;
	string col;
	string row;

	bool operator==(StoreType &item);
	bool operator!=(StoreType &item);
	bool operator>(StoreType &item);
	bool operator<(StoreType &item);


	friend ostream& operator<<(ostream& out, StoreType& item) {
		out << item.store_id << endl;
		out << item.store_name << endl;
		out << item.MidCID << endl;
		out << item.SmlCID << endl;
		out << item.store_city << endl;
		out <<item.col << endl;
		out << item.row << endl;
		out << endl;
		return out;
	}

	/*
	friend istream& operator >> (istream& is, StoreType& item)
	{
		getline(is, item.store_id, '\n');
		getline(is, item.store_name, ',');
		getline(is, item.store_BigCategoty, '\t');

		return is;
	}
	*/
	/*
	friend istream& operator >>(istream& in, StoreType& item) {
		in >> item.store_id >> item.store_name >> item.store_BigCategoty >> store_Mid1Category >> store_Mid2Category >> MidCID >>
			store_SmlCategory >> SmlCID >> store_city >> cityID >> district >> viliage >> col >> row;
		return in;
	}
	*/
};

#endif // !STORETYPE_H_
