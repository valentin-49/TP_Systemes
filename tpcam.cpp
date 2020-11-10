//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tpcam.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	c1 = new COM();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rs232Click(TObject *Sender)
{
	if(c1->ouverture())
	{
		this->etatco->Brush->Color=clGreen;
	}else
	{
		this->etatco->Brush->Color=clRed;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rs232decoClick(TObject *Sender)
{
	c1->fermeture();
	this->etatco->Brush->Color=clRed;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::stopcamClick(TObject *Sender)
{
	char trame[5];

	trame[0]=0x81;
	trame[1]=0x01;
	trame[2]=0x06;
	trame[3]=0x04;
	trame[4]=0xFF;

	c1->ecriture(trame,5);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::camzoomClick(TObject *Sender)
{
	char trame[7];

	trame[0]=0x81;
	trame[1]=0x01;
	trame[2]=0x04;
	trame[3]=0x07;
	trame[4]=0x22;
	trame[5]=0xFF;

	c1->ecriture(trame,6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::camdezoomClick(TObject *Sender)
{
	char trame[7];

	trame[0]=0x81;
	trame[1]=0x01;
	trame[2]=0x04;
	trame[3]=0x07;
	trame[4]=0x32;
	trame[5]=0xFF;

	c1->ecriture(trame,6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::camhautMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	char trame[9];

	trame[0]=0x81;
	trame[1]=0x01;
	trame[2]=0x06;
	trame[3]=0x01;
	trame[4]=0x05;
	trame[5]=0x05;
	trame[6]=0x03;
	trame[7]=0x01;
	trame[8]=0xFF;

		c1->ecriture(trame,9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::camhautMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{

	char chaine[9];

	chaine[0]=0x81;
	chaine[1]=0x01;
	chaine[2]=0x06;
	chaine[3]=0x01;
	chaine[4]=0x05;
	chaine[5]=0x05;
	chaine[6]=0x03;
	chaine[7]=0x03;
	chaine[8]=0xFF;


	c1->ecriture(chaine,9);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::cambasMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	char chaine[9];

	chaine[0]=0x81;
	chaine[1]=0x01;
	chaine[2]=0x06;
	chaine[3]=0x01;
	chaine[4]=0x03;
	chaine[5]=0x03;
	chaine[6]=0x03;
	chaine[7]=0x02;
	chaine[8]=0xFF;

	c1->ecriture(chaine,9);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::cambasMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	char chaine[9];

	chaine[0]=0x81;
	chaine[1]=0x01;
	chaine[2]=0x06;
	chaine[3]=0x01;
	chaine[4]=0x05;
	chaine[5]=0x05;
	chaine[6]=0x03;
	chaine[7]=0x03;
	chaine[8]=0xFF;


	c1->ecriture(chaine,9);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::camdroiteMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	char trame[9];

	trame[0]=0x81;
	trame[1]=0x01;
	trame[2]=0x06;
	trame[3]=0x01;
	trame[4]=0x05;
	trame[5]=0x05;
	trame[6]=0x02;
	trame[7]=0x03;
	trame[8]=0xFF;



		c1->ecriture(trame,9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::camdroiteMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	char chaine[9];

	chaine[0]=0x81;
	chaine[1]=0x01;
	chaine[2]=0x06;
	chaine[3]=0x01;
	chaine[4]=0x05;
	chaine[5]=0x05;
	chaine[6]=0x03;
	chaine[7]=0x03;
	chaine[8]=0xFF;


	c1->ecriture(chaine,9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
	char trame[9];

	switch(this->TrackBar1->Position)
	{
		case 0:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x00;
			trame[7]=0x00;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 1:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x05;
			trame[7]=0x05;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 2:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x09;
			trame[7]=0x09;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 3:
            trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x20;
			trame[7]=0x20;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 4:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x30;
			trame[7]=0x30;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 5:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x40;
			trame[7]=0x40;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 6:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x50;
			trame[7]=0x50;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 7:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x60;
			trame[7]=0x60;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 8:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x70;
			trame[7]=0x70;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 9:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x00;
			trame[6]=0x80;
			trame[7]=0x80;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		case 10:
			trame[0]=0x81;
			trame[1]=0x01;
			trame[2]=0x04;
			trame[3]=0x47;
			trame[4]=0x00;
			trame[5]=0x03;
			trame[6]=0x0F;
			trame[7]=0x0F;
			trame[8]=0xFF;
			c1->ecriture(trame,9);
			break;

		default:
			break;
    }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::camgaucheMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
		char chaine[9];

	chaine[0]=0x81;
	chaine[1]=0x01;
	chaine[2]=0x06;
	chaine[3]=0x01;
	chaine[4]=0x05;
	chaine[5]=0x05;
	chaine[6]=0x03;
	chaine[7]=0x03;
	chaine[8]=0xFF;


	c1->ecriture(chaine,9);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::camgaucheMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
		char trame[9];

	trame[0]=0x81;
	trame[1]=0x01;
	trame[2]=0x06;
	trame[3]=0x01;
	trame[4]=0x05;
	trame[5]=0x05;
	trame[6]=0x01;
	trame[7]=0x03;
	trame[8]=0xFF;



		c1->ecriture(trame,9);
}
//---------------------------------------------------------------------------


