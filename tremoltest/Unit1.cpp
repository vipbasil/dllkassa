//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "C:\Program Files (x86)\ZekaFP\3.0\include\ZekaFP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ZFPCOMLib_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 //ZekaFP1->
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//AnsiString command="d:\\dw\\zfpcash.exe COM1 9600 d:\\Casyst\\ceck351132.inp ";

//system(command.c_str());
//ZekaFP1->Connect();
/*int com=ZekaFP1->FindFirstFPCOMEx();

WORD wCom = (WORD)(com >> 24);
DWORD baud = com & 0x00FFFFFFL;*/
WORD wCom = 1;
DWORD baud = 9600;
ZekaFP1->Setup(wCom,baud,2,10);// zfp(wCom, baud)
ZekaFP1->Connect();
//OpenFiscalBon
AnsiString pswd="0000";
wchar_t* wpswd;
wpswd=pswd.WideChar(wpswd,pswd.Length());

AnsiString text="lapte";
wchar_t* wtext,wtextdest;
int buffsize=text.WideCharBufSize();
wtext=text.WideChar(wtext,buffsize);
//ZekaFP1->printLogo();
ZekaFP1->OpenFiscalBon(1,wpswd,0,0);
ZekaFP1->SellFree(wtext, 0, 0.54f, 10.372f,-10);
ZekaFP1->PrintText(wtext,0);

ZekaFP1->Payment(500,1,0)  ;
ZekaFP1->CloseFiscalBon();



}
//---------------------------------------------------------------------------
