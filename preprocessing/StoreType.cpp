#include "StoreType.h"


StoreType::StoreType() {

}



// operator== overloading
bool StoreType::operator==(StoreType &item) {
	if (this->col.compare(item.col) == 0)
		return true;
	else
		return false;
}


// operator!= overloading
bool StoreType::operator!=(StoreType &item) {
	if (this->col.compare(item.col) != 0)
		return true;
	else
		return false;
}


// operator> overloading
bool StoreType::operator>(StoreType &item) {
	if (this->col.compare(item.col) > 0)
		return true;
	else
		return false;
}

// operator< overloading
bool StoreType::operator<(StoreType &item) {
	if (this->col.compare(item.col) < 0)
		return true;
	else
		return false;
}

/*
// ���Ϸ� ���� ���� ������.
int StoreType::ReadDataFromFile(ifstream& fin) {
	string temp;
	getline(fin, num);
	getline(fin, title);
	getline(fin, genre);
	getline(fin, artist);
	getline(fin, album);
	getline(fin, lyrics);

	return 1;
}

// ���Ͽ� ���� �ۼ�.
int StoreType::WriteDataToFile(ofstream& fout) {
	fout << num << endl;
	fout << title << endl;
	fout << genre << endl;
	fout << artist << endl;
	fout << album << endl;
	fout << lyrics << endl;

	return 1;
}
*/