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
#include <functional>
#include <memory>
#include <optional>
#include <unordered_set>
#include <vector>

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


#include "Add_Item.h"
#include "Add_Plant.h"


#include "../include/WaterStrategy.h"
#include "../include/FrequentWatering.h"
#include "../include/SparseWatering.h"
#include "../include/SeasonalWatering.h"
#include "../include/FertilizeStrategy.h"
#include "../include/LiquidFertilizer.h"
#include "../include/OrganicFertilizer.h"
#include "../include/SlowReleaseFertilizer.h"
#include "../include/GreenhouseController.h"

struct ObserverEvent;
class Observer;
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
	TPanel *pnlGreenhouseListView;
	TLabel *lblAddPlantToRegistryHeading;
	TButton *btnAddPlantToRegistry;
	TLabeledEdit *lbledtPlantPrice;
	TLabel *lblAddItemHeading;
	TButton *btnAddItem;
	TLabel *lblIOHeading;
	TComboBox *cmbGreenhouseSelection;
	TLabel *Label1;
	TLabel *Label2;
	TButton *btnAssignObserve;
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
	void __fastcall btnAddPlantToRegistryClick(TObject *Sender);
	void __fastcall btnAddItemClick(TObject *Sender);
	void __fastcall btnClonePlantClick(TObject *Sender);
	void __fastcall cmbPrototypesChange(TObject *Sender);
	void __fastcall cmbGreenhouseSelectionChange(TObject *Sender);
	void __fastcall lbledtPlantPriceChange(TObject *Sender);
	void __fastcall btnProcessNextTaskClick(TObject *Sender);
	void __fastcall lvStaffTaskQueueSelectItem(TObject *Sender, TListItem *Item, bool Selected);
	void __fastcall btnSimulateClick(TObject *Sender);
	void __fastcall cmbStaffMemberChange(TObject *Sender);
	void __fastcall btnWaterClick(TObject *Sender);
	void __fastcall btnFertiliseClick(TObject *Sender);
	void __fastcall btnAssignObserveClick(TObject *Sender);
	void __fastcall rgWaterStrategyClick(TObject *Sender);
	void __fastcall rgFertiliseStrategyClick(TObject *Sender);
	void __fastcall lvStaffTaskQueueDblClick(TObject *Sender);


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


    std::unique_ptr<WaterStrategy> stratFreqWater;
	std::unique_ptr<WaterStrategy> stratSparseWater;
	std::unique_ptr<WaterStrategy> stratSeasonalWater;
	std::unique_ptr<FertilizeStrategy> stratLiquidFert;
	std::unique_ptr<FertilizeStrategy> stratOrganicFert;
	std::unique_ptr<FertilizeStrategy> stratSlowFert;
	std::unique_ptr<GreenhouseController> objGreenhouseController;

	PlantInstance* currentPlantSelection;
	Staff* currentStaffSelection;

	void PopulatePrototypeComboBox();
	void PopulateStaffMemberComboBox();
	void AttachGreenhouseFrameHandlers();
	/**
	 * @brief Lightweight snapshot of plant metrics for change detection.
	 */
	struct PlantDisplaySnapshot {
		std::string typeName; ///< Human-friendly plant category name.
		std::string stateName; ///< Current lifecycle state name.
		int health; ///< Health progress value.
		int water; ///< Water meter value.
		int nutrients; ///< Nutrient meter value.
		bool saleReady; ///< True when the plant is marked as market-ready.
	};
	/**
	 * @brief Populates the details frame using the provided plant context.
	 * @param plant Plant instance to inspect.
	 * @param logChanges When true, delta information is written to the log.
	 */
	void LoadPlantDetails(PlantInstance* plant, bool logChanges = false);
	/**
	 * @brief Clears the plant detail frame to its default state.
	 */
	void ClearPlantDetails();
	/**
	 * @brief Refreshes the detail frame for the currently selected plant.
	 * @param logChanges When true, emits log entries for metric deltas.
	 */
	void UpdateSelectedPlantDisplay(bool logChanges);
	Staff* ResolveStaffFromCombo(int index) const;
	Staff* FindStaffById(int id) const;
	WaterStrategy* WaterStrategyFromIndex(int index) const;
	FertilizeStrategy* FertilizeStrategyFromIndex(int index) const;
	int WaterStrategyIndexFromPointer(WaterStrategy* strategy) const;
	int FertilizeStrategyIndexFromPointer(FertilizeStrategy* strategy) const;
	/**
	 * @brief Adds a timestamped entry to the application log panel.
	 * @param message Text to append.
	 */
	void AppendLog(const UnicodeString& message);
	/**
	 * @brief Connects UI logging callbacks to each staff member.
	 */
	void RegisterStaffLoggers();
	/**
	 * @brief Ensures the UI logging observer is attached to the specified plant.
	 * @param plant Plant that should emit observer notifications to the UI.
	 */
	void AttachObserverToPlant(PlantInstance* plant);
	/**
	 * @brief Recursively attaches the UI logging observer to all plants in the greenhouse.
	 */
	void AttachLoggerToAllPlants();
	/**
	 * @brief Captures the current plant metrics for later comparisons.
	 * @param plant Plant to sample.
	 * @return Snapshot containing the latest metrics.
	 */
	PlantDisplaySnapshot BuildSnapshot(PlantInstance* plant) const;
	/**
	 * @brief Emits detailed log entries describing differences between two snapshots.
	 * @param before Baseline snapshot.
	 * @param after Updated snapshot.
	 * @param plantLabel Label identifying the plant instance in logs.
	 */
	void LogSnapshotDelta(const PlantDisplaySnapshot& before, const PlantDisplaySnapshot& after, const UnicodeString& plantLabel);
	/**
	 * @brief Disconnects all staff log callbacks.
	 */
	void ResetStaffLoggers();
	/**
	 * @brief Removes the UI observer from every tracked plant instance.
	 */
	void DetachObserverFromAllPlants();
	/**
	 * @brief Helper to re-select a staff row after refreshing the list view.
	 */
	void SelectStaffRowById(int staffId);
	/**
	 * @brief Rebuilds greenhouse tree UI after inventory changes.
	 */
	void RefreshGreenhouseDisplay();

    // New
    void RefreshStaffTaskQueue();
	void WireStaffTaskEvents();

public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
	/**
	 * @brief Cleans up UI observers and log sinks before destruction.
	 */
	__fastcall ~TfrmMain();
    void PopulateSalesItemComboBox();
	void UpdateOrderDisplay();
     // --- Sales/Order Objects ---
	std::unique_ptr<PaymentProcessor> objPaymentProcessor;
	std::unique_ptr<OrderBuilder> objOrderBuilder;
	std::unique_ptr<SalesFacade> objSalesFacade;
	std::unique_ptr<Order> currentOrder;
	std::unique_ptr<Inventory> objInventory;
	void RefreshInventoryListView();
	void UpdateCareActionState();

	void PopulateCustomerComboBox();
	void HandlePlantObserverEvent(const ObserverEvent& event);

    // A list to hold all colleagues (Staff and Customers)
	std::vector<std::unique_ptr<Colleague>> vtrColleagues;

     void PopulateGreenhouseBedComboBox(GreenhouseComponent* component, const std::string& prefix = "");

	std::optional<PlantDisplaySnapshot> currentPlantSnapshot;
	PlantInstance* snapshotPlant;
	std::unique_ptr<Observer> plantLogObserver;
	std::unordered_set<PlantInstance*> loggedPlants;
	std::vector<std::unique_ptr<Plant>> ownedPrototypeClones;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
