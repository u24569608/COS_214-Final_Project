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
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *sbarMain;
	TMainMenu *mmMain;
	TPanel *pnlTop;
	TPageControl *pgcBase;
	TPageControl *pgcMain;
	TTabSheet *tsLog;
	TTabSheet *tsMessages;
	TRichEdit *redtLog;
	TPanel *pnlMessaging;
	TComboBox *cbbSender;
	TComboBox *cbbReceiver;
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
	TTimer *tmrDateTime;
	void __fastcall edtMessageBodyChange(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall tmrDateTimeTimer(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
