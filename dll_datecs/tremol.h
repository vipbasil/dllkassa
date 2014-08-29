//---------------------------------------------------------------------------

#ifndef tremolH
#define tremolH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ZFPCOMLib_OCX.h"
#include <OleServer.hpp>
//---------------------------------------------------------------------------
class Ttremolmodule : public TDataModule
{
__published:	// IDE-managed Components
        TZekaFP *tremol;
private:	// User declarations
public:		// User declarations
        __fastcall Ttremolmodule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Ttremolmodule *tremolmodule;
//---------------------------------------------------------------------------
#endif
