//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Skia.hpp>
#include <Vcl.Skia.hpp>
#include <Vcl.BaseImageCollection.hpp>
#include <Vcl.ImageCollection.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.VirtualImageList.hpp>
#include <Vcl.Buttons.hpp>
#include "Greenhouse_Information_Frame.h"
#include "Sales_Frame.h"
#include <Vcl.Dialogs.hpp>
#include <vector>
#include <memory>

// MEDIATOR PATTERN
#include "../include/NurseryMediator.h"
#include "../include/Colleague.h"
#include "../include/Staff.h"
#include "../include/Customer.h"


// --- COMPOSITE & PROTOTYPE & ITERATOR ---
#include "../include/PlantPrototypeRegistry.h"
#include "../include/Plant.h"
#include "../include/GreenhouseBed.h"
#include "../include/PlantInstance.h"
#include "../include/GreenhouseComponent.h"
#include "../include/GreenhouseIterator.h"
#include "../include/ConcreteGreenhouseIterator.h"
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *mmMain;
	TPanel *pnlTop;
	TPageControl *pgcBase;
	TPageControl *pgcMain;
	TTabSheet *tsLog;
	TTabSheet *tsMessages;
	TRichEdit *redtLog;
	TPanel *pnlMessaging;
	TComboBox *cmbSender;
	TComboBox *cmbReceiver;
	TRichEdit *redtMessages;
	TEdit *edtMessageBody;
	TLabel *lblMessageBodyHeading;
	TLabel *lblSenderHeading;
	TLabel *lblReceiverHeading;
	TSkSvg *sksvgArrow;
	TImageCollection *imgclctnMain;
	TVirtualImageList *vrtlmglstMain;
	TBitBtn *btnSend;
	TTabSheet *tsGreenhouseManagement;
	TTabSheet *tsSalesInventory;
	TTabSheet *tsSystemAdmin;
	TTreeView *tvGreenhouse;
	TScrollBox *scrlbxGreenhouseInformation;
	TfrmGreenhouseInformation *frmGreenhouseInformation1;
	TPageControl *pgcSalesInventory;
	TTabSheet *tsInventory;
	TTabSheet *tsSales;
	TListView *lvInventory;
	TPanel *pnlInventoryMovement;
	TBitBtn *btnInventoryUp;
	TBitBtn *btnInventoryDown;
	TScrollBox *scrlbxSales;
	TfrmSales *frmSales1;
	TPageControl *pgcSystemAdmin;
	TTabSheet *tsInventoryManagement;
	TTabSheet *tsPlantPrototypes;
	TTabSheet *tsStaffTasks;
	TButton *btnLoadInventory;
	TButton *btnSaveInventory;
	TOpenDialog *dlgOpenLoadInventory;
	TSaveDialog *dlgSaveSaveInventory;
	TButton *btnClonePlant;
	TComboBox *cmbPrototypes;
	TLabel *lblSelectPlantCloneHeading;
	TListView *lvStaffTaskQueue;
	TLabel *lblStaffTaskQueueHeading;
	TBitBtn *btnProcessNextTask;
	TPanel *pnlPlantPrototype;
	TPanel *pnlInventoryManagement;
	TBitBtn *btnClearMessages;
	TBitBtn *btnReverse;
	TLabel *lblSwitchHeading;
	TLabel *lblClearMessagesHeading;
	TButton *btnSimulate;
	void __fastcall edtMessageBodyChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnSendClick(TObject *Sender);
	void __fastcall btnClearMessagesClick(TObject *Sender);
	void __fastcall btnReverseClick(TObject *Sender);
	void __fastcall tvGreenhouseChange(TObject *Sender, TTreeNode *Node);

private:	// User declarations
	// --- Mediator Pattern ---
	// Mediator Object
	std::unique_ptr<NurseryMediator> objMediator;

	// A list to hold all colleagues (Staff and Customers)
	std::vector<std::unique_ptr<Colleague>> vtrColleagues;

	// A helper function to fill in the combo boxes
	void PopulateColleagueComboBoxes();


	// --- Composite Pattern ---
	std::unique_ptr<PlantPrototypeRegistry> objPrototypeRegistry;
	std::unique_ptr<GreenhouseBed> objGreenhouse; // The (Composite) root
	void PopulateGreenhouseTree(TTreeNode* parentNode, GreenhouseComponent* component);

public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
