//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TechMain.h"
#include "TechDataModul.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainWnd *MainWnd;
//---------------------------------------------------------------------------
__fastcall TMainWnd::TMainWnd(TComponent* Owner)
  : TForm(Owner)
{
  chan_types = new int[MAX_TYPE_COUNT];
}
//---------------------------------------------------------------------------
void __fastcall TMainWnd::Close1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainWnd::CH1Click(TObject *Sender)
{
  HINSTANCE lib = LoadLibrary("database_analyse_project.dll");
  AnsiString str1,str2;

  int mtype[MAX_TYPE_COUNT];
  ZeroMemory(mtype,sizeof(mtype));

  int count;
  str1 = "c:\\Agattex_222\\Database\\";
  str2 = "skiM1.DBF";

  bool b;

  DataModule1->Table->DatabaseName = str1;
  DataModule1->Table->TableName = str2;

  func_param_desc = new func_param_description;

  func_param_desc->table = DataModule1->Table;
  func_param_desc->param1 = mtype;

  if(lib)
  {
		GetChannelsTypeCount = (FType *)GetProcAddress(lib,"_GetChannelsTypeCount");
    if(GetChannelsTypeCount)
    {
      GetChannelsTypeCount((int*)func_param_desc);
      params_count = func_param_desc->result;
    }
    else
    {
      FreeLibrary(lib);
    	GetChannelsTypeCount = NULL;
      return;
    }

    db_types = new database_types[params_count];
    ZeroMemory(db_types,sizeof(database_types));
    db_types_count = params_count;

		GetChannelsCountOfSomeType = (FType *)GetProcAddress(lib,"_GetChannelsCountOfSomeType");
    if(!GetChannelsCountOfSomeType)
    {
      FreeLibrary(lib);
      GetChannelsCountOfSomeType = NULL;
    	GetChannelsTypeCount = NULL;
      return;
    }

    int a[1];
    func_param_desc->param1 = a;
    int index = 0;
    for(int i=0; i<MAX_TYPE_COUNT; i++)
    {
      if(mtype[i])
      {
        *a = i;
        GetChannelsCountOfSomeType((int*)func_param_desc);
        count = func_param_desc->result;
        if(count)
        {
          db_types[index].chan = new database_chan_params[count];
          db_types[index].param_type = i;
          db_types[index].name = func_param_desc->string;
          db_types[index++].count = count;
        }
      }
    }

    GetChannelsDataOfSomeType = (FType *)GetProcAddress(lib,"_GetChannelsDataOfSomeType");
    if(!GetChannelsDataOfSomeType)
    {
      FreeLibrary(lib);
      GetChannelsDataOfSomeType = NULL;
      GetChannelsCountOfSomeType = NULL;
    	GetChannelsTypeCount = NULL;
      return;
    }

    for(int i=0; i<db_types_count; i++)
    {

      func_param_desc->param1[0] = db_types[i].param_type;
      func_param_desc->param2 = db_types[i].chan;
      GetChannelsDataOfSomeType((int*)func_param_desc);
    }

    Variant v = db_types[0].chan[1].params[1].var;
  /////
  for(int i=0; i<params_count; i++)
  {
    if(!db_types[i].count)
      break;

    Application->CreateForm(__classid(TChanTypeWnd), &table_wnd[i].ChanTypeWnd);
    table_wnd[i].ChanTypeWnd->Parent = MainWnd;
    table_wnd[i].ChanTypeWnd->Top = 0;
    table_wnd[i].ChanTypeWnd->Left = 0;
    table_wnd[i].ChanTypeWnd->Caption = db_types[i].name;
    table_wnd[i].ChanTypeWnd->ChanTypeTableInit(&db_types[i]);
  }


  for(int i=0; i<params_count; i++)
    table_wnd[i].ChanTypeWnd->Show();
  ////

    FreeLibrary(lib);
    GetChannelsDataOfSomeType = NULL;
    GetChannelsCountOfSomeType = NULL;
    GetChannelsTypeCount = NULL;
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainWnd::XML1Click(TObject *Sender)
{
  DataModule1->XMLDocument->FileName = "config.xml";
  DataModule1->XMLDocument->Active = true;

  TStrings *mass = new TStringList;
//  mass = DataModule1->XMLDocument->;
  _di_IXMLNode nod = DataModule1->XMLDocument->DocumentElement->ChildNodes->GetNode(WideString("WINDOW_TENZO"));

  int a = nod->ChildNodes->Count;
  WideString str1 = nod->ChildNodes->Nodes[WideString("Height")]->Text;
  WideString str2 = nod->ChildNodes->Nodes[WideString("Width")]->Text;
  str1 = "200";
  nod->ChildNodes->Nodes[WideString("Width")]->SetText(str1);

  nod->ChildNodes->Nodes[WideString("PosX")]->SetText(WideString(MainWnd->Left));
  nod->ChildNodes->Nodes[WideString("PosY")]->SetText(WideString(MainWnd->Top));
  nod->ChildNodes->Nodes[WideString("Height")]->SetText(WideString(MainWnd->Height));
  nod->ChildNodes->Nodes[WideString("Width")]->SetText(WideString(MainWnd->Width));

  DataModule1->XMLDocument->SaveToFile("config.xml");
  DataModule1->XMLDocument->Active = false;
}
//---------------------------------------------------------------------------

void __fastcall TMainWnd::Restoreposition1Click(TObject *Sender)
{
  DataModule1->XMLDocument->FileName = "config.xml";
  DataModule1->XMLDocument->Active = true;

  _di_IXMLNode nod = DataModule1->XMLDocument->DocumentElement->ChildNodes->GetNode(WideString("WINDOW_TENZO"));

  MainWnd->Left = StrToInt(nod->ChildNodes->Nodes[WideString("PosX")]->Text);
  MainWnd->Top = StrToInt(nod->ChildNodes->Nodes[WideString("PosY")]->Text);
  MainWnd->Height = StrToInt(nod->ChildNodes->Nodes[WideString("Height")]->Text);
  MainWnd->Width = StrToInt(nod->ChildNodes->Nodes[WideString("Width")]->Text);
  DataModule1->XMLDocument->Active = false;

}
//---------------------------------------------------------------------------

void __fastcall TMainWnd::test1Click(TObject *Sender)
{
  TChanTypeWnd *ChanTypeWnd1;
  Application->CreateForm(__classid(TChanTypeWnd), &ChanTypeWnd1);
  ChanTypeWnd1->Parent = MainWnd;
  ChanTypeWnd1->Top = 0;
  ChanTypeWnd1->Left = 0;
  ChanTypeWnd1->Show();
}
//---------------------------------------------------------------------------

