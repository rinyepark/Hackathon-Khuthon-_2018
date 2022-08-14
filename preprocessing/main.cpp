#include "InfType.h"


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

class Simple {
public:

	string �б�;
	int ����;
	int �Ҹ�;
	int �й�;
	int ��Ȱ����;
	int �ε���;
	int ����;
	int �Ƿ�;
	/*
	friend ostream& operator<<(ostream& out, StoreType& item) {
		out << item.�б� << endl;
		out << item.���� << endl;
		out << item.�Ҹ�<< endl;
		out << item.�й�<< endl;
		out << item.��Ȱ���� << endl;
		out << item.�ε��� << endl;
		out << item.���� << endl;
		out << item.�Ƿ� << endl;
		out << endl;
		return out;
	}
	*/
};


string Convert(float& number) {
	std::ostringstream buff;
	buff << number;
	return buff.str();
}

string MakeStr(StoreType& item) {
	string str;

	str = item.store_id + "," + item.store_name + "," + item.MidCID + ","
		+ item.SmlCID + "," + item.store_city + "," + item.col + "," + item.row + "\n";

	return str;
}

string MakeStr2(Simple& item) {
	string str;

	str = item.�б� + "," + to_string(item.����) + "," + to_string(item.�Ҹ�) + ","
		+ to_string(item.��Ȱ����) + "," + to_string(item.�й�) + "," + to_string(item.�Ƿ�) + "," + to_string(item.�ε���)
		+ "," + to_string(item.����) + "\n";

	return str;
}

int main() {

	vector<StoreType> StoreList;
	vector<StoreType> ����;
	vector<StoreType> �Ƿ�;
	vector<StoreType> �ε���;
	vector<StoreType> ������������;
	vector<StoreType> �Ҹ�;
	vector<StoreType> ��Ȱ����;
	vector<StoreType> �й�;

	vector<StoreType> ans;

/*
	//�о����
	ifstream Infile;
	Infile.open("result_f.csv");



	StoreType st;
	int count = 0;
	while (getline(Infile, st.store_id, ',') && getline(Infile, st.store_name, ',') && getline(Infile, st.MidCID, ',')
		&& getline(Infile, st.SmlCID, ',') && getline(Infile, st.store_city, ',') && getline(Infile, st.col, ',') && getline(Infile, st.row, '\n')) {
		StoreList.push_back(st);
		cout << "yeah" << endl;
	}

	Infile.close();
	*/

	while (1) {
		float inCol;
		float inRow;

		float maxCol;
		float maxRow;
		float a = 0.008333;
		float b = 0.006667;


		string school;
		cout << "\t �б� �Է�(q�� ����):";
		cin >> school;
		if (school == "q") {
			break;
			return 0;
		}

		//�о����
		ifstream Infile;
		string str = school + ".csv";
		Infile.open(str);


		StoreList.clear();
		����.clear();
		�Ҹ�.clear();
		��Ȱ����.clear();
		�Ƿ�.clear();
		�ε���.clear();
		������������.clear();
		�й�.clear();

		StoreType st;
		int count = 0;
		while (getline(Infile, st.store_id, ',') && getline(Infile, st.store_name, ',') && getline(Infile, st.MidCID, ',')
			&& getline(Infile, st.SmlCID, ',') && getline(Infile, st.store_city, ',') && getline(Infile, st.col, ',') && getline(Infile, st.row, '\n')) {
			StoreList.push_back(st);
			cout << "yeah" << endl;
		}

		Infile.close();


		StoreType T;
		for (int i = 0;i < StoreList.size();i++) {
			T = StoreList[i];
			if ((T.MidCID).find("Q") != -1) {
				cout << "���դ�����" << endl;
				����.push_back(T);
			}
			else if ((T.MidCID).find("D") != -1) {
				�Ҹ�.push_back(T);
			}
			else if ((T.MidCID).find("F") != -1) {
				��Ȱ����.push_back(T);
			}
			else if ((T.MidCID).find("R") != -1) {
				�й�.push_back(T);
			}
			else if ((T.MidCID).find("S") != -1) {
				�Ƿ�.push_back(T);
			}
			else if ((T.MidCID).find("L") != -1) {
				�ε���.push_back(T);
			}
			else {
				������������.push_back(T);
			}
		}

		Simple Temp;
		Temp.�б� = school;
		Temp.���� = ����.size();
		Temp.�Ҹ� = �Ҹ�.size();
		Temp.�ε��� = �ε���.size();
		Temp.���� = ������������.size();
		Temp.�Ƿ� = �Ƿ�.size();
		Temp.�й� = �й�.size();
		Temp.��Ȱ���� = ��Ȱ����.size();

		/*
		cout << "\t ���� �浵 �Է�: ";
		cin >> inCol;
		cout << "\t ���� ���� �Է�: ";
		cin >> inRow;

		maxCol = inCol;
		maxRow = inRow;

		inCol -= a;
		inRow -= b;

		maxCol += a;
		maxRow += b;

		int c1 = 0;
		int c2 = 0;
		int c3 = 0;
		int c4 = 0;
		string mCol, mRow;
		mCol = Convert(inCol);
		mRow = Convert(inRow);

		string pCol, pRow;
		pCol = Convert(maxCol);
		pRow = Convert(maxRow);

		
		for (int i = 0;i < StoreList.size();i++) {
			if (i == 0) {
				continue;
			}
			else {
				if (mCol.compare(StoreList[i].col) <= 0)
				{
					c1++;
					if (mRow.compare(StoreList[i].row) <= 0) {
						c2++;
						if (pCol.compare(StoreList[i].col) >= 0) {
							c3++;
							if (pRow.compare(StoreList[i].row) >= 0) {
								c4++;
								cout << "WOW!" << StoreList[i].col << " : " << StoreList[i].row << endl;
								ans.push_back(StoreList[i]);
							}
							else {
								continue;
							}
						}
						else {
							continue;
						}

					}
					else {
						continue;
					}
				}
				else {
					continue;
				}
			}
		}

		cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
		*/

		
		ofstream Outfile;
		string s = school + "Count.csv";
		Outfile.open(s);

		Outfile << MakeStr2(Temp);
		
		Outfile.close();
	}


	



	/*
	while (getline(Infile, st.store_id, ',') && getline(Infile, st.store_name, ',') && getline(Infile, st.MidCID, ',')
		&& getline(Infile, st.SmlCID, ',') && getline(Infile, st.store_city, ',') && getline(Infile, st.col, ',') && getline(Infile, st.row, '\n')) {
		if (st.store_city == "����Ư����") {
			StoreList.push_back(st);
		}

	}
	*/

	

	/*
	while (getline(Infile, st.store_id, ',') && getline(Infile, st.store_name, ',') && getline(Infile, st.MidCID, ',')
		&& getline(Infile, st.SmlCID, ',') && getline(Infile, st.store_city, ',') && getline(Infile, st.col, ',') && getline(Infile, st.row, '\n')) {
		if ((st.MidCID).find("Q") != -1) {
			FoodList.push_back(st);
		}

	}
	*/
	/*
	StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("Q") != -1) {
			����.push_back(T);
		}
		else if ((T.MidCID).find("D") != -1){
			�Ҹ�.push_back(T);
		}
		else if ((T.MidCID).find("F") != -1) {
			��Ȱ����.push_back(T);
		}
		else if ((T.MidCID).find("R") != -1) {
			�й�.push_back(T);
		}
		else if ((T.MidCID).find("S") != -1) {
			�Ƿ�.push_back(T);
		}
		else if ((T.MidCID).find("L") != -1) {
			�ε���.push_back(T);
		}
		else {
			������������.push_back(T);
		}
	}
	*/
	//Infile.close();

	/*
	cout << "����" << ����.size() << " �Ҹ�" << �Ҹ�.size() << " ���W����" << ��Ȱ����.size() <<
		" �й�" << �й�.size() << " �Ƿ�" << �Ƿ�.size() << " �ε���" << �ε���.size() << " ������������" << ������������.size() << endl;
	*/
	
	/*
	for (int i = 0;i < ����.size();i++) {
		Outfile << MakeStr(����[i]);
	}

	for (int i = 0;i < �Ҹ�.size();i++) {
		Outfile << MakeStr(�Ҹ�[i]);
	}

	for (int i = 0;i < ��Ȱ����.size();i++) {
		Outfile << MakeStr(��Ȱ����[i]);
	}

	for (int i = 0;i < �й�.size();i++) {
		Outfile << MakeStr(�й�[i]);
	}

	for (int i = 0;i < �Ƿ�.size();i++) {
		Outfile << MakeStr(�Ƿ�[i]);
	}

	for (int i = 0;i < �ε���.size();i++) {
		Outfile << MakeStr(�ε���[i]);
	}

	for (int i = 0;i < ������������.size();i++) {
		Outfile << MakeStr(������������[i]);
	}
	*/

	/*
	Outfile.open("��Ȱ����.csv");

	StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("F") != -1) {
			Outfile << MakeStr(T);
		}
	}

	ofstream Outfile2;
	Outfile2.open("�Ҹ�.csv");
	//StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("D") != -1) {
			Outfile2 << MakeStr(T);
		}
	}

	ofstream Outfile3;
	Outfile3.open("�й�����.csv");
	//StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("R") != -1) {
			Outfile3 << MakeStr(T);
		}
	}

	ofstream Outfile4;
	Outfile4.open("������������.csv");
	//StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("N") != -1) {
			Outfile4 << MakeStr(T);
		}
	}

	ofstream Outfile5;
	Outfile5.open("�Ƿ�.csv");
	//StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("S") != -1) {
			Outfile5 << MakeStr(T);
		}
	}

	ofstream Outfile6;
	Outfile6.open("�ε���.csv");

	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("L") != -1) {
			Outfile6 << MakeStr(T);
		}
	}


	/*
	for (int i = 0;i < FoodList.size();i++) {
		Outfile << MakeStr(FoodList[i]);
	}
	*/
	/*
	Outfile.open("result3.csv");

	for (int i = 0;i < StoreList.size();i++) {
		Outfile << MakeStr(StoreList[i]);
	}
	*/
	/*
	Outfile.close();
	Outfile2.close();
	Outfile3.close();
	Outfile4.close();
	Outfile5.close();
	Outfile6.close();
	*/
}