//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mysqlunit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ZFPCOMLib_OCX"
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------

bool TDataModule1::Connect()
{
    AnsiString host=Host;
    AnsiString username=User;
    AnsiString password=Pass;
    AnsiString db_name=DBase;
    AnsiString query = "SET NAMES cp1251";
    if(mysql) return true;
    mysql = mysql_init(mysql);
    mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,username.c_str());    
    mysql = mysql_real_connect(mysql,host.c_str(),username.c_str(),password.c_str(),db_name.c_str(),0,NULL,CLIENT_MULTI_RESULTS);
    if(!mysql)
        return false;

    mysql_real_query(mysql,query.c_str(),query.Length());
    mysql->reconnect = 0;
    return true;

}
//---------------------------------------------------------------------------
void TDataModule1::Disconnect()
{
    mysql_close(mysql);
    mysql = NULL;
}

//---------------------------------------------------------------------------
bool TDataModule1::ExecuteQuery(AnsiString query, bool need_store,BSTR *tmp)
{
   BSTR *store_result;
    store_result = (tmp!=NULL)?(tmp):(&sql_result);

    if(!Connect())
    {
        ShowMessage("��������� ���������� � ��������");
        return false;
    }
    try
    {
        mysql_real_query(mysql,query.c_str(),query.Length());
    }
    catch(Exception *e)
    {
        ShowMessage(e->Message);
    }
    char ch[255];
    if(mysql_errno(mysql))
    {
        AnsiString erorr_str = mysql_error(mysql);
        ShowMessage(erorr_str);

        int err = mysql_errno(mysql);
        switch(err)
        {
            case 2006://MySQL server has gone away
                Disconnect();    
            break;
        }

        AnsiString time = TimeToStr(Time());
        while(time.Pos(":"))time[time.Pos(":")]='-';
        AnsiString from = DateToStr(Date());
        from += "_"+time;
        from += ".log";

        int file = FileCreate( LogPath+""+from);
        if(file>0)
        {
            erorr_str += "\r\n";
            erorr_str += query;

            FileWrite(file,erorr_str.c_str(),erorr_str.Length());
            FileClose(file);
        }
          
        if(need_store)
        {
            sql_result_rows = 0;
            store_result->clear();
            AnsiString ar1, ar2;
            ar1=ar2="a";
            BSTR::iterator it = store_result->insert(std::make_pair(-1, DSTR())).first;
            DSTR tmp=it->second;
            tmp[ar1]=ar2;
            
        }

        return false;
    }
   
    BSTR::iterator it;
    if(need_store)
    {
        sql_result_rows = 0;
        store_result->clear();

        Res = mysql_use_result(mysql);
        Row = mysql_fetch_row(Res);
        for(unsigned int j=0; j<Res->field_count; j++)
        {
            it = store_result->insert(std::make_pair(-1, DSTR())).first;
            it->second[IntToStr(j)]=Res->fields[j].name;
            it->second["num_fields"]=Res->field_count;
            it = store_result->insert(std::make_pair(-2, DSTR())).first;
            it->second[IntToStr(j)]=Res->fields[j].type;
            it = store_result->insert(std::make_pair(-3, DSTR())).first;
            it->second[IntToStr(j)]=Res->fields[j].length;
        }
       
        while(Row)
        {
            for(unsigned int j=0; j<Res->field_count; j++)
            {
                it = store_result->insert(std::make_pair(sql_result_rows, DSTR())).first;
                it->second[Res->fields[j].name]=Row[j];
            }

            sql_result_rows++;
            Row = mysql_fetch_row(Res);
        }
        mysql_free_result(Res);

        it = store_result->insert(std::make_pair(-1, DSTR())).first;
        it->second["num_rows"]=sql_result_rows;

        it = store_result->insert(std::make_pair(-1, DSTR())).first;
         while(!mysql_next_result(mysql)){
            Res = mysql_use_result(mysql);
            mysql_free_result(Res);
        }


    }
       return true;
}
//---------------------------------------------------------------------------
bool TDataModule1::ExecuteQueryR(AnsiString query, bool need_store)
{

    if(!Connect())

    {
        ShowMessage("��������� ���������� � ��������");
        return false;
    }
    try
    {
        mysql_real_query(mysql,query.c_str(),query.Length());
    }
    catch(Exception *e)
    {
        ShowMessage(e->Message);
    }
    char ch[255];
    if(mysql_errno(mysql))
    {
        AnsiString erorr_str = mysql_error(mysql);
        ShowMessage(erorr_str);

        int err = mysql_errno(mysql);
        switch(err)
        {
            case 2006://MySQL server has gone away
                Disconnect();    
            break;
        }
     if(need_store)
        {
            sql_result1.clear();
            sql_result1[-1]["num_rows"] = "0";
        }

        return false;
    }
 
    if(need_store)
    {
        sql_result1.clear();
        sql_result1[-1]["num_rows"] = "0";
        sql_result_rows1 = 0;
        Res = mysql_use_result(mysql);
        Row = mysql_fetch_row(Res);

        
        while(Row)
        {
            for(unsigned int j=0; j<Res->field_count; j++)
            {
                sql_result[sql_result_rows][Res->fields[j].name] = Row[j];
            }

            sql_result_rows1++;
            Row = mysql_fetch_row(Res);
        }

        mysql_free_result(Res);
    }

  
    return true; 
}