//---------------------------------------------------------------------------

#ifndef mysqlunitH
#define mysqlunitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "mysql.h"
#include "map.h";
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TDataModule1(TComponent* Owner);
        bool ExecuteQueryR(AnsiString query, bool need_store);


void Disconnect();
bool Connect();
MYSQL_RES     *Res;
MYSQL_ROW      Row;
MYSQL_FIELD   *Fields;
MYSQL          *mysql;
 typedef std::map<int, std::map<AnsiString,AnsiString> > BSTR;
    BSTR sql_result,sql_result1;
 typedef std::map<AnsiString, AnsiString> DSTR;
 int sql_result_rows,sql_result_rows1;
 bool ExecuteQuery(AnsiString query, bool need_store, BSTR * =NULL);
 AnsiString Host,DBase,User,Pass,LogPath;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
