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
	// --- BEGIN Mediator Pattern Setup ---
	// 1. Create the Mediator object
	objMediator = std::make_unique<NurseryMediator>();

	// 2. Create Colleagues
	//    The constructor is Colleague(int id, FloorMediator* mediator)
	vtrColleagues.push_back(std::make_unique<Staff>(101, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(201, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(202, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Staff>(102, objMediator.get()));

	// 3. Register all colleagues with the mediator
	for (const auto& colleague : vtrColleagues) {
		objMediator->addColleague(colleague.get());
	}

	// 4. Fill GUI combo boxes with the IDs
	PopulateColleagueComboBoxes();
    // --- END Mediator Pattern Setup ---
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

void TfrmMain::PopulateColleagueComboBoxes()
{
	// Clear any old items
	cmbSender->Clear();
	cmbReceiver->Clear();

	// Loop through list of Colleague objects
	for (const auto& colleague : vtrColleagues)
	{
		// Get the INT ID and convert it to a UnicodeString
		UnicodeString idString = colleague->getID();

		// Add the ID string to both comboboxes
		cmbSender->Items->Add(idString);
		cmbReceiver->Items->Add(idString);
	}
}

void __fastcall TfrmMain::btnSendClick(TObject *Sender)
{
    // 1. Get all the data from the GUI
	UnicodeString senderIdStr = cmbSender->Text;
	UnicodeString receiverIdStr = cmbReceiver->Text;
	std::string message = AnsiString(edtMessageBody->Text).c_str();

	// 3. Convert GUI strings back to INTs
	int senderId = -1;
	int receiverId = -1;

	try {
		senderId = std::stoi(AnsiString(senderIdStr).c_str());
		receiverId = std::stoi(AnsiString(receiverIdStr).c_str());
	}
	catch(...) {
		ShowMessage("Error: Invalid Sender or Receiver ID");
		return;
	}

	// 4. Find the sender Colleague object in our list (using the INT ID)
	Colleague* sender = nullptr;
	for (const auto& colleague : vtrColleagues) {
		if (colleague->getID() == senderId) {
			sender = colleague.get();
			break;
		}
	}

	// 5. Call the backend send() method
	if (sender != nullptr) {
		// === THIS IS THE MEDIATOR PATTERN IN ACTION ===
		sender->send(message, receiverId);

		// 6. Log the message to the RichEdit (using ID strings)
		UnicodeString logLine = senderIdStr + " -> " + receiverIdStr + ": " + message.c_str();
		redtMessages->Lines->Add(logLine);

		// 7. Clear the message box
		edtMessageBody->Text = "";
	} else {
		ShowMessage("Error: Could not find sender object.");
	}
}
//---------------------------------------------------------------------------

