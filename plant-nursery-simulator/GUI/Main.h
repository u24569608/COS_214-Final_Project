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
#include <Vcl.Mask.hpp>
#include <vector>
#include <memory>

#include "../include/NurseryMediator.h"
#include "../include/Colleague.h"
#include "../include/Staff.h"
#include "../include/Customer.h"

#include "../include/PlantPrototypeRegistry.h"
#include "../include/Plant.h"
#include "../include/GreenhouseBed.h"
#include "../include/PlantInstance.h"
#include "../include/GreenhouseComponent.h"
#include "../include/GreenhouseIterator.h"
#include "../include/ConcreteGreenhouseIterator.h"

#include "../include/Inventory.h"
#include "../include/FileAdapter.h"
#include "../include/CSVAdapter.h"
#include "../include/TXTAdapter.h"

#include "../include/StockItem.h"
#include "../include/InventoryIterator.h"
#include "../include/InventoryCollection.h"
#include "../include/ConcreteInventoryIterator.h"

#include "../include/SalesFacade.h"
#include "../include/OrderBuilder.h"
#include "../include/CustomOrderBuilder.h"
#include "../include/Order.h"
#include "../include/PaymentProcessor.h"
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
	TPanel *Panel1;
	TLabel *Label1;
	TButton *btnAddPlantToRegistry;
	TLabeledEdit *LabeledEdit1;
	TLabel *Label2;
	TButton *Button2;
	TLabel *Label3;
	void __fastcall edtMessageBodyChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall btnSendClick(TObject *Sender);
	void __fastcall btnClearMessagesClick(TObject *Sender);
	void __fastcall btnReverseClick(TObject *Sender);
	void __fastcall tvGreenhouseChange(TObject *Sender, TTreeNode *Node);
	void __fastcall btnLoadInventoryClick(TObject *Sender);
	void __fastcall btnInventoryUpClick(TObject *Sender);
	void __fastcall btnInventoryDownClick(TObject *Sender);
	void __fastcall btnSaveInventoryClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);

private:	// User declarations
	// --- Mediator Pattern ---
	// Mediator Object
	std::unique_ptr<NurseryMediator> objMediator;




	// A helper function to fill in the combo boxes
	void PopulateColleagueComboBoxes();


	// --- Composite Pattern ---
	std::unique_ptr<PlantPrototypeRegistry> objPrototypeRegistry;
	std::unique_ptr<GreenhouseBed> objGreenhouse; // The (Composite) root
	void PopulateGreenhouseTree(TTreeNode* parentNode, GreenhouseComponent* component);






public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
    void PopulateSalesItemComboBox();
	void UpdateOrderDisplay();
     // --- Sales/Order Objects ---
	std::unique_ptr<PaymentProcessor> objPaymentProcessor;
	std::unique_ptr<OrderBuilder> objOrderBuilder;
	std::unique_ptr<SalesFacade> objSalesFacade;
	std::unique_ptr<Order> currentOrder;
    std::unique_ptr<Inventory> objInventory;
	void RefreshInventoryListView();

	void PopulateCustomerComboBox();

    // A list to hold all colleagues (Staff and Customers)
    std::vector<std::unique_ptr<Colleague>> vtrColleagues;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
