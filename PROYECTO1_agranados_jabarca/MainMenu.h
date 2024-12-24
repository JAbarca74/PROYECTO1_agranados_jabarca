#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class MainMenu
{
private:
	int browser;
	int interact;
	int* ptr;
	int* arrayName;
	string nameEvent;
	string dateEvent;
	int seatingEvent;
	int segmentsEvent;

public:

	MainMenu();
	int getBrowser();
	void setBrowser(int nBrowser);
	void cleanScreen();
	void informationMenu();
	void interfaseActivity();
	void interMenuModifityEvent();
	void modifityEvent();
	void informationEvent();
	void createdEventNameInformation();
};