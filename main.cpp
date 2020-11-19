//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "Classe.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)      //Connexion au serveur
	{
	WSADATA wsa;
	int error = WSAStartup(MAKEWORD(2, 2), &wsa);     // initialisation de WSAS Windows seulement
	if (error < 0) 

		{
			lblWSASratupEchec->Visible = true;  
		}   

   else {
			lblWSAStartupReussi->Visible = true;
		}

	sock = socket(AF_INET, SOCK_STREAM, 0);     // Création du socket
	if(sock == INVALID_SOCKET)

	{
		lblSocketEchec->Visible = true;	
	}

	else 

	{
		lblSocketReussi->Visible = true;
	}


	struct hostent *hostinfo = NULL;
	SOCKADDR_IN sin = { 0 }; /* initialise la structure avec des 0 */
	const char *hostname = "192.168.64.124";

	hostinfo = gethostbyname(hostname); /* on récupère les informations de l'hôte auquel on veut se connecter */
	if (hostinfo == NULL) /* l'hôte n'existe pas */

	{
	    lblHoteInconnu->Visible = true;
	}  

	else

	{ 
		lblHoteValide->Visible = true;
    }

	sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
	sin.sin_port = htons(502); /* on utilise htons pour le port */
	sin.sin_family = AF_INET;

	if(connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR)) == SOCKET_ERROR)   // Connexion a l'hôte 
	{
		lblConnexionEchec->Visible = true;	
	}

	else 

	{
		lblConnexionReussi->Visible = true;
		txtEnvoi->Visible = true;
        btnEnvoyer->Visible = true;
	}

int WSACleanup(void);

}
//-------------------------------------------------------------------
void __fastcall TForm1::btnEnvoyerClick(TObject *Sender) // Envoi des données 
{
		char trame[12];
		trame[0] = 00;
		trame[1] = 00;
		trame[2] = 00;
		trame[3] = 00;
		trame[4] = 00;
		trame[5] = 06;
		trame[6] = 02;
		trame[7] = 06;
		trame[8] = 00;
		trame[9] = 02;
		trame[10] = 00;
		trame[11] = 00;

	 if (txtEnvoi->Text == 'a')
	{

		lblEnvoiReussi->Visible = true;
    	lblEnvoiEchec->Visible = false;

		trame[11] = 01;
		if(send(sock, trame, 12, 0) < 0);

		trame[11] = 00;
		if(send(sock, trame, 12, 0) < 0);

	}


	else if (txtEnvoi->Text == 'z')

	{
		lblEnvoiEchec->Visible = false;
		lblEnvoiReussi->Visible = true;

		trame[11] = 02;
		if(send(sock, trame, 12, 0) < 0);

		trame[11] = 00;
		if(send(sock, trame, 12, 0) < 0);

	}


	else if (txtEnvoi->Text == 'e')

	{
		trame[11] = 04;
		if(send(sock, trame, 12, 0) < 0);

		trame[11] = 00;
		if(send(sock, trame, 12, 0) < 0);

		lblEnvoiEchec->Visible = false;
		lblEnvoiReussi->Visible = true;

	}


	else if (txtEnvoi->Text == 'r')

	{

		trame[11] = 8;
		if(send(sock, trame, 12, 0) < 0);

		trame[11] = 00;
		if(send(sock, trame, 12, 0) < 0);

		lblEnvoiEchec->Visible = false;
		lblEnvoiReussi->Visible = true;

	}
	else

	{
		lblEnvoiReussi->Visible = false;
		lblEnvoiEchec->Visible = true;
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::btnReceptionClick(TObject *Sender)
{

	char buffer[1024];
	int n = 0;

	if((n = recv(sock, buffer, sizeof buffer - 1, 0)) < 0)

	{
		perror("recv()");
		exit(errno);
	}

	buffer[n] = '\0';
	txtRecu->Text = buffer;

    closesocket(sock);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
		char trame[12];
		trame[0] = 00;
		trame[1] = 00;
		trame[2] = 00;
		trame[3] = 00;
		trame[4] = 00;
		trame[5] = 06;
		trame[6] = 02;
		trame[7] = 06;
		trame[8] = 00;
		trame[9] = 02;
		trame[10] = 00;
		trame[11] = 01;

		if(send(sock, trame, 12, 0) < 0);

		trame[11] = 00;

		if(send(sock, trame, 12, 0) < 0);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
		char trame[12];
		trame[0] = 00;
		trame[1] = 00;
		trame[2] = 00;
		trame[3] = 00;
		trame[4] = 00;
		trame[5] = 06;
		trame[6] = 02;
		trame[7] = 06;
		trame[8] = 00;
		trame[9] = 02;
		trame[10] = 00;
		trame[11] = 02;

		if(send(sock, trame, 12, 0) < 0);

		trame[11] = 00;

		if(send(sock, trame, 12, 0) < 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
		char trame[12];

		trame[0] = 00;
		trame[1] = 00;
		trame[2] = 00;
		trame[3] = 00;
		trame[4] = 00;
		trame[5] = 06;
		trame[6] = 02;
		trame[7] = 06;
		trame[8] = 00;
		trame[9] = 02;
		trame[10] = 00;
		trame[11] = 04;

		if(send(sock, trame, 12, 0) < 0);

		trame[11] = 00;

		if(send(sock, trame, 12, 0) < 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
		char trame[12];

		trame[0] = 00;
		trame[1] = 00;
		trame[2] = 00;
		trame[3] = 00;
		trame[4] = 00;
		trame[5] = 06;
		trame[6] = 02;
		trame[7] = 06;
		trame[8] = 00;
		trame[9] = 02;
		trame[10] = 00;
		trame[11] = 8;

		if(send(sock, trame, 12, 0) < 0);

		trame[11] = 00;

		if(send(sock, trame, 12, 0) < 0);
}
//---------------------------------------------------------------------------



