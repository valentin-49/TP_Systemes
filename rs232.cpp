//---------------------------------------------------------------------------

#pragma hdrstop

#include "rs232.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



bool COM::ouverture(){

	hcom=CreateFile(L"COM1",
	GENERIC_READ | GENERIC_WRITE,
	0,
	NULL,
	OPEN_EXISTING,
	FILE_FLAG_NO_BUFFERING,
	NULL);

	if (hcom==INVALID_HANDLE_VALUE)
	return false;


		GetCommState(hcom,&serie);
		serie.BaudRate=9600;
		serie.ByteSize= 8;
		serie.Parity= NOPARITY;
		serie.StopBits= ONESTOPBIT;
		SetCommState(hcom,&serie);

	return true;


}
bool COM::ecriture(char * str,int taille){

	unsigned long pt=0;



	//wcstombs(chaine,str,strlen(str));


		/*over.Internal=0;
		over.InternalHigh=0;
		over.Offset=0;
		over.OffsetHigh=0;
		over.Pointer= NULL;
		over.hEvent=NULL;
		 */

		 WriteFile(hcom,str, taille,&pt, NULL);
		 PurgeComm(hcom,PURGE_TXCLEAR);

	 if (pt==0){

		 return false;
	 }

	 return true;
}

void COM::fermeture(){

	CloseHandle(hcom);
}

char* COM::lecture(){
	 int taille = 5;

	char * message;
	message = new char[taille+1];
	message[0]='\0';
	unsigned long pt = 0;



		/*
		 over.Internal=0;
		 over.Internalhigh=0;
		 over.Offset=0;
		 over.Offsethigh=0;
		 over.Pointer=NULL;
		 over.hEvent=NULL;
		 */
		 ReadFile(hcom,message, taille,&pt,NULL);
		 PurgeComm(hcom, PURGE_RXCLEAR);


		 return message;






}
