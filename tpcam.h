//---------------------------------------------------------------------------

#ifndef tpcamH
#define tpcamH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "rs232.h"
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *camhaut;
	TButton *cambas;
	TButton *camzoom;
	TButton *camdezoom;
	TButton *camdroite;
	TButton *camgauche;
	TButton *rs232;
	TButton *rs232deco;
	TShape *etatco;
	TButton *stopcam;
	TTrackBar *TrackBar1;
	TLabel *Label1;
	void __fastcall rs232Click(TObject *Sender);
	void __fastcall rs232decoClick(TObject *Sender);
	void __fastcall stopcamClick(TObject *Sender);
	void __fastcall camzoomClick(TObject *Sender);
	void __fastcall camdezoomClick(TObject *Sender);
	void __fastcall camhautMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall camhautMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall cambasMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall cambasMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall camdroiteMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall camdroiteMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall camgaucheMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall camgaucheMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
private:
		 COM *c1;
		 char * chaine;
		 int i;

		 // Déclarations utilisateur
public:
		// Déclarations utilisateur

	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
