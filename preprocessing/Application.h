#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "InfType.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:

	Application()
	{
		m_Command = 0;
	}

	~Application() {}


	void Run();

	int GetCommand();


	int OpenInFile(char *fileName);
	int OpenOutFile(char *fileName);
	int ReadDataFromFile();
	int WriteDataToFile();


private:
	ifstream m_InFile;								///< input file descriptor.
	ofstream m_OutFile;								///< output file descriptor.
	
	vector<StoreType> StoreList;
	vector<InfType> CategoryList;

	int m_Command;
};


#endif // !_APPLICATION_H

