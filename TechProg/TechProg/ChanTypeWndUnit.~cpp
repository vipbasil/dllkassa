//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ChanTypeWndUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TChanTypeWnd *ChanTypeWnd;

//---------------------------------------------------------------------------
__fastcall TChanTypeWnd::TChanTypeWnd(TComponent* Owner)
  : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void TChanTypeWnd::ChanTypeTableInit(database_types *db_types)
{
  TListItem *Item;
  TListColumn *column;

  ListView1->Items->BeginUpdate();
  ListView1->Items->Clear();

  column = ListView1->Columns->Add();
  column->Caption = db_types->chan[0].params[1].name;
  column->AutoSize = true;
  column->MaxWidth = 20;
  column->MinWidth = 20;
  column->Width = 20;
  column = ListView1->Columns->Add();
  column->Caption = db_types->chan[0].params[2].name;
  column->AutoSize = true;
  column = ListView1->Columns->Add();
  column->Caption = db_types->chan[0].params[3].name;
  column->AutoSize = true;
  column = ListView1->Columns->Add();
  column->Caption = db_types->chan[0].params[4].name;
  column->AutoSize = true;
  column = ListView1->Columns->Add();
  column->Caption = db_types->chan[0].params[5].name;
  column->AutoSize = true;

  for(int i=0; i<db_types->count; i++)
  {
    Item = ListView1->Items->Add();
    Item->SubItems->Add(db_types->chan[i].params[1].name);
    Item->SubItems->Add(db_types->chan[i].params[2].name);
    Item->SubItems->Add(db_types->chan[i].params[3].name);
    Item->SubItems->Add(db_types->chan[i].params[4].name);
  }
  ListView1->Items->EndUpdate();
}
