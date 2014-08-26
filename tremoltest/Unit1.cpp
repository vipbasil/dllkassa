//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "C:\Program Files (x86)\ZekaFP\3.0\include\ZekaFP.h"
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        DWORD com = CZekaFP::FindFirstFPCOMEx();
	WORD wCom = (WORD)(com >> 24);
	DWORD baud = com & 0x00FFFFFFL;

}
//---------------------------------------------------------------------------
