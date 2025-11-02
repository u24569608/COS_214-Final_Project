//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Main.cpp", frmMain);
USEFORM("Greenhouse_Information_Frame.cpp", frmGreenhouseInformation); /* TFrame: File Type */
USEFORM("Sales_Frame.cpp", frmSales); /* TFrame: File Type */
USEFORM("Add_Plant.cpp", frmAddPlant);
USEFORM("Add_Item.cpp", frmAddItem);
//---------------------------------------------------------------------------
/**
 * @brief Application entry point that initialises and runs the VCL main loop.
 * @param hInstance Handle to the current instance.
 * @param hPrevInstance Handle to the previous instance (unused).
 * @param lpCmdLine Command-line arguments.
 * @param nCmdShow Show state for the main window.
 * @return Exit code returned to the operating system.
 */
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		TStyleManager::TrySetStyle("Windows11 Polar Light");
		Application->CreateForm(__classid(TfrmMain), &frmMain);
		Application->CreateForm(__classid(TfrmAddPlant), &frmAddPlant);
		Application->CreateForm(__classid(TfrmAddItem), &frmAddItem);
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
