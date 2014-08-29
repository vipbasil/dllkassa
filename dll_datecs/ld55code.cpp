//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include "databaseunit.h"
#include "mysqlunit.h"
#include "tremol.h"
#include "ld55code.h"
#include "sysvari.h"
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  Application->CreateForm(__classid(Ttremolmodule), &tremolmodule);
  return 1;
}
//---------------------------------------------------------------------------

int DLL_SPEC GetChannelsTypeCount(func_param_description *params)
{
  /*int count = 0;
  params->table->Open();
  params->table->First();

  while(!params->table->Eof)
  {
    params->param1[params->table->FieldByName("TYPE")->AsInteger] = 1;
    params->table->Next();
  }
  params->table->Close();

  for(int i=0; i<MAX_TYPE_COUNT; i++)
    count += params->param1[i] ? 1 : 0;

  params->result = count;
    */
  return 0;
}
//---------------------------------------------------------------------------

int DLL_SPEC PrintBon(void)
{
WORD wCom = 1;
DWORD baud = 9600;
tremolmodule->tremol->Setup(wCom,baud,2,10);// zfp(wCom, baud)
tremolmodule->tremol->Connect();
//OpenFiscalBon
AnsiString pswd="0000";
wchar_t* wpswd;
wpswd=pswd.WideChar(wpswd,pswd.Length());

WideString text="lapte";
/*wchar_t* wtext,wtextdest;
int buffsize=text.WideCharBufSize();
wtext=text.WideChar(wtext,buffsize);*/
//ZekaFP1->printLogo();
tremolmodule->tremol->OpenFiscalBon(1,wpswd,0,0);
tremolmodule->tremol->SellFree(text, 0, 5.50f, 10.000f,-10);
tremolmodule->tremol->PrintText(text,0);

tremolmodule->tremol->Payment(500,1,0)  ;
tremolmodule->tremol->CloseFiscalBon();

  return 0;
}
int DLL_SPEC GetChannelsCountOfSomeType(func_param_description *params)
{
 /* params->table->Open();
  params->table->First();

  int count = 0;
  while(!params->table->Eof)
  {
    if(params->table->FieldByName("TYPE")->AsInteger == params->param1[0])
    {
      count++;
      params->string = params->table->FieldByName("PRIM")->AsString;
    }
    params->table->Next();
  }
  params->table->Close();

  params->result = count;
   */
  return 0;
}

int DLL_SPEC GetChannelsDataOfSomeType(func_param_description *params)
{
 /* int count = 0;
  params->table->Open();
  params->table->First();
  Variant var;

  while(!params->table->Eof)
  {
    if(params->table->FieldByName("TYPE")->AsInteger == params->param1[0])
    {
      params->param2[count].params = new field_data[params->table->FieldCount];
      params->param2[count].count = params->table->FieldCount;
      for(int i=1; i<params->table->FieldCount; i++)
      {
        params->param2[count].params[i].name = params->table->Fields->FieldByNumber(i)->FieldName;
        params->param2[count].params[i].var = params->table->FieldValues[params->table->Fields->FieldByNumber(i)->FieldName];
      }
      count++;
    }

    params->table->Next();
  }
  params->table->Close();

  params->result = 1;
           */
  return 0;
}


