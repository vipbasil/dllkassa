//---------------------------------------------------------------------------

#ifndef TechMainH
#define TechMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include "global.h"
#include "ChanTypeWndUnit.h"


//---------------------------------------------------------------------------
class TMainWnd : public TForm
{
__published:	// IDE-managed Components
  TMainMenu *MainMenu1;
  TMenuItem *File1;
  TMenuItem *Channels1;
  TMenuItem *Close1;
  TMenuItem *CH1;
  TMenuItem *Tools1;
  TMenuItem *Options1;
  TMenuItem *XML1;
  TMenuItem *Restoreposition1;
  TMenuItem *test1;
  void __fastcall Close1Click(TObject *Sender);
  void __fastcall CH1Click(TObject *Sender);
  void __fastcall XML1Click(TObject *Sender);
  void __fastcall Restoreposition1Click(TObject *Sender);
  void __fastcall test1Click(TObject *Sender);

private:	// User declarations

public:		// User declarations
  __fastcall TMainWnd(TComponent* Owner);

  typedef int __import *FType(*func_param_description);

  FType  *GetChannelsTypeCount;
  FType  *GetChannelsCountOfSomeType;
  FType  *GetChannelsDataOfSomeType;

  int *chan_types;
  func_param_description *func_param_desc;

  database_types *db_types;
  int db_types_count;

  int params_count;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainWnd *MainWnd;
//---------------------------------------------------------------------------
#endif
