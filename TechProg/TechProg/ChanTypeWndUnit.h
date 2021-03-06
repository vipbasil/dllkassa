//---------------------------------------------------------------------------

#ifndef ChanTypeWndUnitH
#define ChanTypeWndUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include "TechMain.h"

//---------------------------------------------------------------------------
class TChanTypeWnd : public TForm
{
__published:	// IDE-managed Components
  TListView *ListView1;
  TPopupMenu *PopupMenu1;
  TMenuItem *N5;
  TMenuItem *N6;
  TMenuItem *N7;
  TMenuItem *N8;
    TMainMenu *MainMenu1;
    TMenuItem *N11;
private:	// User declarations
public:		// User declarations
  __fastcall TChanTypeWnd(TComponent* Owner);
  void ChanTypeTableInit(database_types*);
};

struct ChanTypeStruct
{
  TChanTypeWnd *ChanTypeWnd;
} table_wnd[MAX_TYPE_COUNT];

//---------------------------------------------------------------------------
extern PACKAGE TChanTypeWnd *ChanTypeWnd;
//---------------------------------------------------------------------------
#endif
