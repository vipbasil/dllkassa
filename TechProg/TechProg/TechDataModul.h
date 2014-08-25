//---------------------------------------------------------------------------

#ifndef TechDataModulH
#define TechDataModulH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <xmldom.hpp>
#include <Xmlxform.hpp>
#include <DBClient.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <XMLIntf.hpp>
#include <oxmldom.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
  TDataSource *DataSource;
  TTable *Table;
  TXMLDocument *XMLDocument;
private:	// User declarations
public:		// User declarations
  __fastcall TDataModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
