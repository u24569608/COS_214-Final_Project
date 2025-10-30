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


// --- ADAPTER PATTERN ---
#include "../include/Inventory.h"
#include "../include/FileAdapter.h"
#include "../include/CSVAdapter.h"
#include "../include/TXTAdapter.h"

// --- ITERATOR PATTERN (for displaying inventory) ---
#include "../include/StockItem.h"
#include "../include/InventoryIterator.h"
#include "../include/InventoryCollection.h"
#include "../include/ConcreteInventoryIterator.h"

/**
 * @file Main.h
 * @brief Application main form hosting nursery management workflows.
 */
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
	TFileOpenDialog *dlgOpenLoadInventory;
	TFileSaveDialog *dlgSaveSaveInventory;
    /**
     * @brief Synchronises UI state with the current message body.
     */
	void __fastcall edtMessageBodyChange(TObject *Sender);
    /**
     * @brief Initialises runtime services after the form is created.
     */
	void __fastcall FormCreate(TObject *Sender);
    /**
     * @brief Sends a mediated message between colleagues.
     */
	void __fastcall btnSendClick(TObject *Sender);
    /**
     * @brief Clears the message history display.
     */
	void __fastcall btnClearMessagesClick(TObject *Sender);
    /**
     * @brief Reverses the selected mediator message conversation.
     */
	void __fastcall btnReverseClick(TObject *Sender);
    /**
     * @brief Updates greenhouse detail panels when a tree node changes.
     */
	void __fastcall tvGreenhouseChange(TObject *Sender, TTreeNode *Node);
    /**
     * @brief Loads inventory data from persistent storage.
     */
	void __fastcall btnLoadInventoryClick(TObject *Sender);
    /**
     * @brief Moves the selected inventory item upward in the display list.
     */
	void __fastcall btnInventoryUpClick(TObject *Sender);
    /**
     * @brief Moves the selected inventory item downward in the display list.
     */
	void __fastcall btnInventoryDownClick(TObject *Sender);
    /**
     * @brief Saves inventory data to persistent storage.
     */
	void __fastcall btnSaveInventoryClick(TObject *Sender);

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


	std::unique_ptr<Inventory> objInventory;
	void RefreshInventoryListView();

public:		// User declarations
    /**
     * @brief Constructs the main form and wires VCL components.
     * @param Owner Component that owns the form.
     */
	__fastcall TfrmMain(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
