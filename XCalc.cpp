//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("FXCalcMain.cpp", F_XCalcMain);
USEFORM("FHelp.cpp", F_Help);
USEFORM("FMathTest.cpp", F_MathTest);
//---------------------------------------------------------------------------
WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TF_XCalcMain), &F_XCalcMain);
		Application->CreateForm(__classid(TF_Help), &F_Help);
		Application->CreateForm(__classid(TF_MathTest), &F_MathTest);
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
