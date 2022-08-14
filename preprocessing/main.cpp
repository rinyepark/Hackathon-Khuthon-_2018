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

	string 학교;
	int 음식;
	int 소매;
	int 학문;
	int 생활서비스;
	int 부동산;
	int 관광;
	int 의료;
	/*
	friend ostream& operator<<(ostream& out, StoreType& item) {
		out << item.학교 << endl;
		out << item.음식 << endl;
		out << item.소매<< endl;
		out << item.학문<< endl;
		out << item.생활서비스 << endl;
		out << item.부동산 << endl;
		out << item.관광 << endl;
		out << item.의료 << endl;
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

	str = item.학교 + "," + to_string(item.음식) + "," + to_string(item.소매) + ","
		+ to_string(item.생활서비스) + "," + to_string(item.학문) + "," + to_string(item.의료) + "," + to_string(item.부동산)
		+ "," + to_string(item.관광) + "\n";

	return str;
}

int main() {

	vector<StoreType> StoreList;
	vector<StoreType> 음식;
	vector<StoreType> 의료;
	vector<StoreType> 부동산;
	vector<StoreType> 관광여가오락;
	vector<StoreType> 소매;
	vector<StoreType> 생활서비스;
	vector<StoreType> 학문;

	vector<StoreType> ans;

/*
	//읽어오기
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
		cout << "\t 학교 입력(q는 종료):";
		cin >> school;
		if (school == "q") {
			break;
			return 0;
		}

		//읽어오기
		ifstream Infile;
		string str = school + ".csv";
		Infile.open(str);


		StoreList.clear();
		음식.clear();
		소매.clear();
		생활서비스.clear();
		의료.clear();
		부동산.clear();
		관광여가오락.clear();
		학문.clear();

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
				cout << "음잇ㄱㅇ깅" << endl;
				음식.push_back(T);
			}
			else if ((T.MidCID).find("D") != -1) {
				소매.push_back(T);
			}
			else if ((T.MidCID).find("F") != -1) {
				생활서비스.push_back(T);
			}
			else if ((T.MidCID).find("R") != -1) {
				학문.push_back(T);
			}
			else if ((T.MidCID).find("S") != -1) {
				의료.push_back(T);
			}
			else if ((T.MidCID).find("L") != -1) {
				부동산.push_back(T);
			}
			else {
				관광여가오락.push_back(T);
			}
		}

		Simple Temp;
		Temp.학교 = school;
		Temp.음식 = 음식.size();
		Temp.소매 = 소매.size();
		Temp.부동산 = 부동산.size();
		Temp.관광 = 관광여가오락.size();
		Temp.의료 = 의료.size();
		Temp.학문 = 학문.size();
		Temp.생활서비스 = 생활서비스.size();

		/*
		cout << "\t 기준 경도 입력: ";
		cin >> inCol;
		cout << "\t 기준 위도 입력: ";
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
		if (st.store_city == "서울특별시") {
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
			음식.push_back(T);
		}
		else if ((T.MidCID).find("D") != -1){
			소매.push_back(T);
		}
		else if ((T.MidCID).find("F") != -1) {
			생활서비스.push_back(T);
		}
		else if ((T.MidCID).find("R") != -1) {
			학문.push_back(T);
		}
		else if ((T.MidCID).find("S") != -1) {
			의료.push_back(T);
		}
		else if ((T.MidCID).find("L") != -1) {
			부동산.push_back(T);
		}
		else {
			관광여가오락.push_back(T);
		}
	}
	*/
	//Infile.close();

	/*
	cout << "음식" << 음식.size() << " 소매" << 소매.size() << " 생홞서비스" << 생활서비스.size() <<
		" 학문" << 학문.size() << " 의료" << 의료.size() << " 부동산" << 부동산.size() << " 관광여가오락" << 관광여가오락.size() << endl;
	*/
	
	/*
	for (int i = 0;i < 음식.size();i++) {
		Outfile << MakeStr(음식[i]);
	}

	for (int i = 0;i < 소매.size();i++) {
		Outfile << MakeStr(소매[i]);
	}

	for (int i = 0;i < 생활서비스.size();i++) {
		Outfile << MakeStr(생활서비스[i]);
	}

	for (int i = 0;i < 학문.size();i++) {
		Outfile << MakeStr(학문[i]);
	}

	for (int i = 0;i < 의료.size();i++) {
		Outfile << MakeStr(의료[i]);
	}

	for (int i = 0;i < 부동산.size();i++) {
		Outfile << MakeStr(부동산[i]);
	}

	for (int i = 0;i < 관광여가오락.size();i++) {
		Outfile << MakeStr(관광여가오락[i]);
	}
	*/

	/*
	Outfile.open("생활서비스.csv");

	StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("F") != -1) {
			Outfile << MakeStr(T);
		}
	}

	ofstream Outfile2;
	Outfile2.open("소매.csv");
	//StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("D") != -1) {
			Outfile2 << MakeStr(T);
		}
	}

	ofstream Outfile3;
	Outfile3.open("학문교육.csv");
	//StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("R") != -1) {
			Outfile3 << MakeStr(T);
		}
	}

	ofstream Outfile4;
	Outfile4.open("관광여가오락.csv");
	//StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("N") != -1) {
			Outfile4 << MakeStr(T);
		}
	}

	ofstream Outfile5;
	Outfile5.open("의료.csv");
	//StoreType T;
	for (int i = 0;i < StoreList.size();i++) {
		T = StoreList[i];
		if ((T.MidCID).find("S") != -1) {
			Outfile5 << MakeStr(T);
		}
	}

	ofstream Outfile6;
	Outfile6.open("부동산.csv");

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