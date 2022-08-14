#include "Application.h"


void Application::Run() {

	while (1)
	{
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 9:	
			ReadDataFromFile();
			break;
		case 10:
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}

int Application::GetCommand() {
	int command;
	cout << endl << endl;

	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   9 : Read" << endl;
	cout << "\t   10 : Write" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;

	return command;
}


int Application::OpenInFile(char *fileName) {

	m_InFile.open(fileName);	
						
	if (!m_InFile)	
		return 0;
	else	
		return 1;
}
int Application::OpenOutFile(char *fileName) {

	m_OutFile.open(fileName);	

	if (!m_OutFile)	
		return 0;
	else	
		return 1;
}
int Application::ReadDataFromFile() {

}
int Application::WriteDataToFile() {

}