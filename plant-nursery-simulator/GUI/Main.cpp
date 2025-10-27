//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Greenhouse_Information_Frame.h"
#include "Sales_Frame.h"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Greenhouse_Information_Frame"
#pragma link "Sales_Frame"
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------







void __fastcall TfrmMain::edtMessageBodyChange(TObject *Sender)
{
	if (edtMessageBody->Text.Length() == 0) {
		btnSend->Enabled = false;
	}
	else if (edtMessageBody->Text.Length() > 0) {
		btnSend->Enabled = true;
	}
}
//---------------------------------------------------------------------------







void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
	// Display Welcome Message in Log
	redtLog->Lines->Add("Welcome to Plant Palace!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::tmrDateTimeTimer(TObject *Sender)
{
	//sbarMain->Panels->Items[0]->Text = DateToStr(Date());
    //sbarMain->Panels->Items[1]->Text = TimeToStr(Time());
}
//---------------------------------------------------------------------------

