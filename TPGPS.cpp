#include "TPGPS.h"

TPGPS::TPGPS() 
{
	
}
// fonction qui ouvre et se connecte au port s�rie du GPS.
bool TPGPS::ouvrirPort()
{
	hcom = CreateFileA("COM1", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, NULL);
	if (hcom == INVALID_HANDLE_VALUE) 
	{
		return false;
	}
	else
	{
		GetCommState(hcom, &dcb);
		dcb.BaudRate = CBR_4800;
		dcb.ByteSize = 8;
		dcb.Parity = NOPARITY;
		dcb.StopBits = ONESTOPBIT;

		SetCommState(hcom, &dcb);
		com.ReadIntervalTimeout = MAXDWORD;
		com.ReadTotalTimeoutMultiplier = 0;
		com.ReadTotalTimeoutConstant = 0;
		com.WriteTotalTimeoutMultiplier = 0;
		com.WriteTotalTimeoutConstant = 0;

		SetCommTimeouts(hcom, &com);

		return true;
	}

}
// fonction pour r�cup�rer les trames GPS.
bool TPGPS::lirePort(char * buffer)
{
	int n = 0;
	unsigned long d = 0;
	if ((n = ReadFile(hcom, buffer, 1, &d, NULL)) < 0)
	{
		return false;
	}
	buffer[n] = '\0';
	return true;
}
// fonction pour �crire sur le port s�rie (pas utilse pour ce projet).
bool TPGPS::ecrirePort()
{
	return true;
}
// fonction pour fermer le port s�rie.
void TPGPS::fermerPort()
{
	CloseHandle(hcom);
}