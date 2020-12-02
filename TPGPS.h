#pragma once
#include <windows.h>

class TPGPS
{
	HANDLE hcom;
	DCB dcb;
	COMMTIMEOUTS com;
public:
	TPGPS();
	bool ouvrirPort();
	bool lirePort(char * buffer);
	bool ecrirePort();
	void fermerPort();
};

