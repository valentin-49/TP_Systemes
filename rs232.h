//---------------------------------------------------------------------------

#ifndef rs232H
#define rs232H
#include <Windows.h>
#include <string.h>
class COM
{
	private:
		HANDLE hcom;
		DCB serie;
		OVERLAPPED over;
		char *chaine;

	public:
		bool ouverture();
		void fermeture();
		bool ecriture(char * str, int taille);
		char *lecture();

};
//---------------------------------------------------------------------------
#endif


