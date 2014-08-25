//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("TechMain.cpp", MainWnd);
USEFORM("TechDataModul.cpp", DataModule1); /* TDataModule: File Type */
USEFORM("ChanTypeWndUnit.cpp", ChanTypeWnd);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->CreateForm(__classid(TMainWnd), &MainWnd);
     Application->CreateForm(__classid(TDataModule1), &DataModule1);
     //Application->CreateForm(__classid(TChanTypeWnd), &ChanTypeWnd);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  catch (...)
  {
     try
     {
       throw Exception("");
     }
     catch (Exception &exception)
     {
       Application->ShowException(&exception);
     }
  }
  return 0;
}
//---------------------------------------------------------------------------
