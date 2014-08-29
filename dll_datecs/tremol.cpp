//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "tremol.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ZFPCOMLib_OCX"
#pragma resource "*.dfm"
Ttremolmodule *tremolmodule;
//---------------------------------------------------------------------------
__fastcall Ttremolmodule::Ttremolmodule(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
