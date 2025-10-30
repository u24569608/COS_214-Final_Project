object frmMain: TfrmMain
  Left = 41
  Top = 55
  Caption = 'Plant Palace'
  ClientHeight = 608
  ClientWidth = 849
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = mmMain
  Position = poDesigned
  WindowState = wsMaximized
  OnActivate = FormActivate
  OnCreate = FormCreate
  TextHeight = 21
  object pnlTop: TPanel
    Left = 0
    Top = 0
    Width = 849
    Height = 49
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitWidth = 847
    object btnSimulate: TButton
      Left = 8
      Top = 11
      Width = 161
      Height = 28
      Caption = 'Simulate Growth'
      ImageIndex = 15
      ImageName = 'Plant'
      Images = vrtlmglstMain
      TabOrder = 0
    end
  end
  object pgcBase: TPageControl
    Left = 0
    Top = 347
    Width = 849
    Height = 261
    ActivePage = tsLog
    Align = alBottom
    Images = vrtlmglstMain
    TabOrder = 0
    ExplicitTop = 339
    ExplicitWidth = 847
    object tsLog: TTabSheet
      Caption = 'Log'
      ImageIndex = 1
      ImageName = 'Log'
      object redtLog: TRichEdit
        Left = 0
        Top = 0
        Width = 841
        Height = 225
        Align = alClient
        BevelInner = bvNone
        BevelOuter = bvNone
        Color = clBlack
        Font.Charset = ANSI_CHARSET
        Font.Color = clWhite
        Font.Height = -17
        Font.Name = 'Consolas'
        Font.Style = []
        ParentFont = False
        PlainText = True
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
        StyleElements = [seBorder]
        ExplicitWidth = 839
      end
    end
    object tsMessages: TTabSheet
      Caption = 'Messages'
      ImageName = 'Messages'
      object pnlMessaging: TPanel
        Left = 0
        Top = 0
        Width = 841
        Height = 129
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        DesignSize = (
          841
          129)
        object lblMessageBodyHeading: TLabel
          Left = 4
          Top = 69
          Width = 100
          Height = 21
          Caption = 'Message Body'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 9203809
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          StyleElements = [seClient, seBorder]
        end
        object lblSenderHeading: TLabel
          Left = 4
          Top = 7
          Width = 49
          Height = 21
          Caption = 'Sender'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 9203809
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          StyleElements = [seClient, seBorder]
        end
        object lblReceiverHeading: TLabel
          Left = 249
          Top = 7
          Width = 59
          Height = 21
          Caption = 'Receiver'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 9203809
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          StyleElements = [seClient, seBorder]
        end
        object sksvgArrow: TSkSvg
          Left = 210
          Top = 34
          Width = 33
          Height = 29
          Svg.Source = 
            '<svg xmlns="http://www.w3.org/2000/svg" height="24px" viewBox="0' +
            ' -960 960 960" width="24px" fill="#61708c"><path d="M647-440H160' +
            'v-80h487L423-744l57-56 320 320-320 320-57-56 224-224Z"/></svg>'
        end
        object lblSwitchHeading: TLabel
          Left = 463
          Top = 7
          Width = 179
          Height = 21
          Caption = 'Switch Sender && Receiver'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 9203809
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          StyleElements = [seClient, seBorder]
        end
        object lblClearMessagesHeading: TLabel
          Left = 666
          Top = 7
          Width = 108
          Height = 21
          Caption = 'Clear Messages'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = 9203809
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentFont = False
          StyleElements = [seClient, seBorder]
        end
        object cmbSender: TComboBox
          Left = 4
          Top = 34
          Width = 200
          Height = 29
          Sorted = True
          TabOrder = 0
          Text = 'Sender'
        end
        object cmbReceiver: TComboBox
          Left = 249
          Top = 34
          Width = 200
          Height = 29
          Sorted = True
          TabOrder = 1
          Text = 'Receiver'
        end
        object edtMessageBody: TEdit
          Left = 4
          Top = 95
          Width = 730
          Height = 29
          Anchors = [akLeft, akTop, akRight]
          TabOrder = 2
          TextHint = 'Enter your message'
          OnChange = edtMessageBodyChange
        end
        object btnSend: TBitBtn
          Left = 743
          Top = 95
          Width = 89
          Height = 28
          Anchors = [akTop, akRight]
          Caption = 'Send'
          Enabled = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          HotImageIndex = 2
          HotImageName = 'Send'
          ImageIndex = 2
          ImageName = 'Send'
          Images = vrtlmglstMain
          ParentFont = False
          TabOrder = 3
          OnClick = btnSendClick
        end
        object btnClearMessages: TBitBtn
          Left = 666
          Top = 34
          Width = 95
          Height = 29
          Caption = 'Clear'
          ImageIndex = 21
          ImageName = 'Clear'
          Images = vrtlmglstMain
          TabOrder = 4
          OnClick = btnClearMessagesClick
        end
        object btnReverse: TBitBtn
          Left = 463
          Top = 34
          Width = 98
          Height = 29
          Caption = 'Switch'
          ImageIndex = 22
          ImageName = 'Switch'
          Images = vrtlmglstMain
          TabOrder = 5
          OnClick = btnReverseClick
        end
      end
      object redtMessages: TRichEdit
        Left = 0
        Top = 129
        Width = 841
        Height = 96
        Align = alClient
        BevelInner = bvNone
        BevelOuter = bvNone
        Color = clBlack
        Font.Charset = ANSI_CHARSET
        Font.Color = clWhite
        Font.Height = -17
        Font.Name = 'Consolas'
        Font.Style = []
        ParentFont = False
        PlainText = True
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 1
        StyleElements = [seBorder]
      end
    end
  end
  object pgcMain: TPageControl
    Left = 0
    Top = 49
    Width = 849
    Height = 298
    ActivePage = tsGreenhouseManagement
    Align = alClient
    Images = vrtlmglstMain
    TabOrder = 2
    ExplicitWidth = 847
    ExplicitHeight = 290
    object tsGreenhouseManagement: TTabSheet
      Caption = 'Greenhouse Management   '
      ImageIndex = 3
      ImageName = 'Greenhouse'
      object scrlbxGreenhouseInformation: TScrollBox
        Left = 181
        Top = 0
        Width = 660
        Height = 262
        VertScrollBar.Smooth = True
        VertScrollBar.Tracking = True
        Align = alClient
        BevelInner = bvNone
        BevelOuter = bvNone
        TabOrder = 0
        UseWheelForScrolling = True
        inline frmGreenhouseInformation1: TfrmGreenhouseInformation
          Left = 0
          Top = 0
          Width = 635
          Height = 467
          Align = alTop
          Color = clWhite
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Segoe UI'
          Font.Style = []
          ParentBackground = False
          ParentColor = False
          ParentFont = False
          TabOrder = 0
          ExplicitWidth = 635
          inherited grpAction: TGroupBox
            inherited btnFertilise: TBitBtn
              Images = nil
            end
            inherited btnWater: TBitBtn
              Images = nil
            end
          end
        end
      end
      object pnlGreenhouseListView: TPanel
        Left = 0
        Top = 0
        Width = 181
        Height = 262
        Align = alLeft
        Caption = 'Panel1'
        TabOrder = 1
        object tvGreenhouse: TTreeView
          Left = 1
          Top = 1
          Width = 179
          Height = 260
          Align = alClient
          Indent = 19
          TabOrder = 0
          OnChange = tvGreenhouseChange
        end
      end
    end
    object tsSalesInventory: TTabSheet
      Caption = 'Sales && Inventory   '
      ImageIndex = 5
      ImageName = 'Inventory 2'
      object pgcSalesInventory: TPageControl
        Left = 0
        Top = 0
        Width = 841
        Height = 262
        ActivePage = tsInventory
        Align = alClient
        Images = vrtlmglstMain
        TabOrder = 0
        object tsInventory: TTabSheet
          Caption = 'Inventory   '
          ImageIndex = 1
          ImageName = 'Log'
          object lvInventory: TListView
            Left = 0
            Top = 0
            Width = 792
            Height = 226
            Align = alClient
            Columns = <
              item
                Caption = 'Name'
                MinWidth = 100
                Width = 150
              end
              item
                Caption = 'Price'
                MinWidth = 100
                Width = 150
              end
              item
                Caption = 'Availability'
                MinWidth = 100
                Width = 150
              end>
            ReadOnly = True
            TabOrder = 0
            ViewStyle = vsReport
          end
          object pnlInventoryMovement: TPanel
            Left = 792
            Top = 0
            Width = 41
            Height = 226
            Align = alRight
            BevelOuter = bvNone
            TabOrder = 1
            object btnInventoryUp: TBitBtn
              Left = 0
              Top = 0
              Width = 41
              Height = 49
              Align = alTop
              ImageIndex = 10
              ImageName = 'Up'
              Images = vrtlmglstMain
              TabOrder = 0
              OnClick = btnInventoryUpClick
            end
            object btnInventoryDown: TBitBtn
              Left = 0
              Top = 58
              Width = 41
              Height = 49
              ImageIndex = 11
              ImageName = 'Down'
              Images = vrtlmglstMain
              TabOrder = 1
              OnClick = btnInventoryDownClick
            end
          end
        end
        object tsSales: TTabSheet
          Caption = 'Sales   '
          ImageIndex = 9
          ImageName = 'Sales'
          object scrlbxSales: TScrollBox
            Left = 0
            Top = 0
            Width = 833
            Height = 226
            VertScrollBar.Smooth = True
            Align = alClient
            TabOrder = 0
            UseWheelForScrolling = True
            inline frmSales1: TfrmSales
              Left = 0
              Top = 0
              Width = 808
              Height = 761
              Align = alTop
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Segoe UI'
              Font.Style = []
              ParentBackground = False
              ParentColor = False
              ParentFont = False
              TabOrder = 0
              ExplicitWidth = 808
              inherited btnRefund: TBitBtn
                Images = nil
              end
              inherited btnAddToOrder: TBitBtn
                Anchors = [akLeft]
                Images = nil
              end
              inherited btnProcessPayment: TBitBtn
                AlignWithMargins = False
                Images = nil
              end
            end
          end
        end
      end
    end
    object tsSystemAdmin: TTabSheet
      Caption = 'System Admin   '
      ImageIndex = 6
      ImageName = 'System Admin'
      object pgcSystemAdmin: TPageControl
        Left = 0
        Top = 0
        Width = 841
        Height = 262
        ActivePage = tsInventoryManagement
        Align = alClient
        Images = vrtlmglstMain
        TabOrder = 0
        ExplicitWidth = 839
        ExplicitHeight = 254
        object tsInventoryManagement: TTabSheet
          Caption = 'Inventory Management   '
          ImageIndex = 5
          ImageName = 'Inventory 2'
          object pnlInventoryManagement: TPanel
            Left = 0
            Top = 0
            Width = 833
            Height = 226
            Align = alClient
            BevelOuter = bvNone
            Color = clWhite
            ParentBackground = False
            TabOrder = 0
            StyleElements = []
            object lblAddItemHeading: TLabel
              Left = 25
              Top = 135
              Width = 151
              Height = 21
              Caption = 'Add Item to Inventory'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 9203809
              Font.Height = -16
              Font.Name = 'Segoe UI'
              Font.Style = []
              ParentFont = False
              StyleElements = [seClient, seBorder]
            end
            object lblIOHeading: TLabel
              Left = 26
              Top = 16
              Width = 265
              Height = 21
              Caption = 'Save/Open Inventory List To/From File'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 9203809
              Font.Height = -16
              Font.Name = 'Segoe UI'
              Font.Style = []
              ParentFont = False
              StyleElements = [seClient, seBorder]
            end
            object btnSaveInventory: TButton
              Left = 25
              Top = 86
              Width = 150
              Height = 28
              Caption = 'Save Inventory...'
              ImageIndex = 16
              ImageName = 'Save'
              Images = vrtlmglstMain
              TabOrder = 0
              OnClick = btnSaveInventoryClick
            end
            object btnLoadInventory: TButton
              Left = 25
              Top = 46
              Width = 150
              Height = 28
              Caption = 'Load Inventory...'
              ImageIndex = 17
              ImageName = 'Load'
              Images = vrtlmglstMain
              TabOrder = 1
              OnClick = btnLoadInventoryClick
            end
            object btnAddItem: TButton
              Left = 26
              Top = 162
              Width = 150
              Height = 25
              Caption = 'Add Item...'
              ImageIndex = 12
              ImageName = 'Add'
              Images = vrtlmglstMain
              TabOrder = 2
              OnClick = btnAddItemClick
            end
          end
        end
        object tsPlantPrototypes: TTabSheet
          Caption = 'Plant Prototypes   '
          ImageIndex = 15
          ImageName = 'Plant'
          object pnlPlantPrototype: TPanel
            Left = 0
            Top = 0
            Width = 833
            Height = 226
            Align = alClient
            BevelOuter = bvNone
            Color = clWhite
            ParentBackground = False
            TabOrder = 0
            StyleElements = []
            ExplicitWidth = 831
            ExplicitHeight = 218
            object lblSelectPlantCloneHeading: TLabel
              Left = 227
              Top = 16
              Width = 254
              Height = 21
              Caption = 'Select a Plant to Plant in Greenhouse'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 9203809
              Font.Height = -16
              Font.Name = 'Segoe UI'
              Font.Style = []
              ParentFont = False
              StyleElements = [seClient, seBorder]
            end
            object lblAddPlantToRegistryHeading: TLabel
              Left = 25
              Top = 16
              Width = 146
              Height = 21
              Caption = 'Add Plant to Registry'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 9203809
              Font.Height = -16
              Font.Name = 'Segoe UI'
              Font.Style = []
              ParentFont = False
              StyleElements = [seClient, seBorder]
            end
            object Label1: TLabel
              Left = 227
              Top = 43
              Width = 128
              Height = 21
              Caption = 'Select a Plant Type'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 11573902
              Font.Height = -16
              Font.Name = 'Segoe UI'
              Font.Style = []
              ParentFont = False
              StyleElements = [seClient, seBorder]
            end
            object Label2: TLabel
              Left = 431
              Top = 43
              Width = 141
              Height = 21
              Caption = 'Select a Greenhouse'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = 11573902
              Font.Height = -16
              Font.Name = 'Segoe UI'
              Font.Style = []
              ParentFont = False
              StyleElements = [seClient, seBorder]
            end
            object btnClonePlant: TButton
              Left = 696
              Top = 116
              Width = 120
              Height = 28
              Caption = 'Plant'
              Enabled = False
              ImageIndex = 15
              ImageName = 'Plant'
              Images = vrtlmglstMain
              TabOrder = 0
              OnClick = btnClonePlantClick
            end
            object cmbPrototypes: TComboBox
              Left = 227
              Top = 71
              Width = 180
              Height = 29
              TabOrder = 1
              Text = 'Plant'
              OnChange = cmbPrototypesChange
            end
            object btnAddPlantToRegistry: TButton
              Left = 25
              Top = 46
              Width = 120
              Height = 28
              Caption = 'Add Plant...'
              ImageIndex = 12
              ImageName = 'Add'
              Images = vrtlmglstMain
              TabOrder = 2
              OnClick = btnAddPlantToRegistryClick
            end
            object lbledtPlantPrice: TLabeledEdit
              Left = 636
              Top = 71
              Width = 180
              Height = 29
              EditLabel.Width = 60
              EditLabel.Height = 21
              EditLabel.Caption = 'Set Price'
              Enabled = False
              TabOrder = 3
              Text = ''
              OnChange = lbledtPlantPriceChange
            end
            object cmbGreenhouseSelection: TComboBox
              Left = 431
              Top = 71
              Width = 180
              Height = 29
              Enabled = False
              TabOrder = 4
              Text = 'Greenhouse'
              OnChange = cmbGreenhouseSelectionChange
            end
          end
        end
        object tsStaffTasks: TTabSheet
          Caption = 'Staff Tasks   '
          ImageIndex = 14
          ImageName = 'Staff'
          DesignSize = (
            833
            226)
          object lblStaffTaskQueueHeading: TLabel
            Left = 25
            Top = 16
            Width = 114
            Height = 21
            Caption = 'Staff Task Queue'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = 9203809
            Font.Height = -16
            Font.Name = 'Segoe UI'
            Font.Style = []
            ParentFont = False
            StyleElements = [seClient, seBorder]
          end
          object lvStaffTaskQueue: TListView
            Left = 0
            Top = 48
            Width = 833
            Height = 178
            Align = alBottom
            Anchors = [akLeft, akTop, akRight, akBottom]
            Columns = <>
            TabOrder = 0
          end
          object btnProcessNextTask: TBitBtn
            Left = 632
            Top = 14
            Width = 185
            Height = 28
            Anchors = [akTop, akRight]
            Caption = 'Process Next Task'
            ImageIndex = 19
            ImageName = 'Next'
            Images = vrtlmglstMain
            TabOrder = 1
          end
        end
      end
    end
  end
  object mmMain: TMainMenu
    Left = 928
    Top = 16
  end
  object imgclctnMain: TImageCollection
    Images = <
      item
        Name = 'Messages'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000080000000800806000000C33E61
              CB00000A8E494441547801EC5C5D8C1B5715BED7DEDDB4B45B9656A825AB9004
              4145A1201404A2150F9578A03C2055AAB60F4D937A3652A12AC9CEAEC7D9865F
              5341B6ACED78BC093F0ACD8E4B48110D428217FE24E02508100555A2015A4192
              D296828A9AB6DB363F6BDF9E9378A4D43B33BE77F78E67AEE758733277EE3DF7
              FC7CE75BCFF85EC73946AF4C234004C874F91923021001328E40C6D3A7770022
              40C611C878FAF40E4004C83802194DDF4F9BDE017C24327A260264B4F07EDA44
              001F898C9E8900192DBC9F3611C04722A3672240460BEFA74D04F091C8E89908
              90B1C277A7DB3702585395BB2CBB7A16449054E3C4E04C617ADF9DDD850EBB8E
              9D00DBEF3B700D169C717E18821801A1235E04D671D13E82984F7EEE1BEB7BB9
              8A95009376E5A6FCF099177A0541E3F1202086F2CF16A6AA1F89B21E1B01B6DF
              B7F71AC1F8EFA29CD358FC0870CEFE88B508F3141B01F2C32327C29C527F7F11
              88AA452C04989898C8438AA32074A40381D1898947B1262BA2898500A3E31FFD
              D20A4FD4912802A3E3FF0EAC492C04102C774BA2D992F3150808C6026B9263B1
              BCC4C65E6621A0239EEB7092B5638058F6C29BB1E09AC44480DEE170C6B65A76
              F599DE9AA411850062885846E9448D2546804E50E390802897CB49C7D109C79C
              136286D841C4E320AB3E5201FCA9D357B67614AB3D6F1BABCE72C02616ECB94D
              88998EB45241004CA4DD622727A7AB9FC536493802963D7F2F67C3DAD6580209
              50B06BF5825DF5C2656E537888AB1F11827DBB60577EBA7A0B833DF32236B96F
              E9CC3290009C89DBE0C1A210263A03E8B6C519FFB465D79EEFEECFFA356282D8
              E8C6219000BA9DA8DB13D75A76557C6AE7C23AF5B983356327608058C0C7B86B
              579359AF392925C0C5B0AFCB9F3B53D835FF9E8B57D9FB17735F020CE2CC3CD5
              04C0C4792EF7A465D71C6C67490A539512E61E77CE891040B0F39B99602DF9E4
              44C5B2ABBF91D7375B1373E59CCF2B64D1BA80A9C2045F351102A073AFE10C31
              C6FFC6E45FB70030FF97573753B39363E0BA7D604682FD1D96D301CBC0D19E9D
              89110023F3DCE2FBE0A3DF83D89694AB0120B1CDA95C21A96F8C1AE684B941C0
              5783481D5CB00AFC21DD20A51CA294280130A666C3D9C3792BF26B4BA877A90C
              2DF3A5ED53950F5EDA67721B73C19C947210E2638B0D67B7D29C00E5C4098031
              2DD667FFB43C24AEC4B6ACE4397F7CD2AE05EE71CBDA48839E3555FD32E6A212
              0B1F695DE5354A7F509913A69B0A02607087ABA557E15EC6A1FD3A88D4219878
              C0B22B8F4929A750C9B26B8F31CEBEAA10DA59C468717EF6955E7364C7534300
              3F6048F02DD07E1C44F2E05B00C897249553A366D9D5976171678B6C4082B127
              009BCB64F565F55247000C1C12FD10E34CE1ED5D5C05808A825D1FC3F969168C
              D182554E8851E13B93E2EB4DD7B911E6683F524900CCD2AB3B5FCB0D890F605B
              56386BBD68EDAADD2CABDF6F3D6BA67633C6A8E23797E35B3CB7F44595392ABA
              A925002671A85AFAAB38BD7439B6A525278E59766DAFB47E9F140B53D539D616
              C754DC0D8F8D5E71685FF12F2A735475534D004CA6D92C9FF15C073EF232B867
              628F8C883DF070785C46B31F3A40C8E39CB3FB157C5D78203E58FECC6B0A7356
              A59A7A02F859C13DF0ADB07CFC7BFFBAF799DF60D9D5D801EC15C7C51884C262
              8DF833105EE92371AF18A2C68D210026E1359C9B04E3456C4BCAE5500061EDDC
              FB76497D6D6AE8137D8341F95B98605FF1DCD287614EDF0EA30880A834DDE23E
              D11EBE1EDBD2921FF99F55AC7E525A7F8D8A85E9F95B19F85431D3E6B91B81E0
              0FA8CC09D255ED338E0098607361EAA9A56797D4BE2CD2623FB7A66B0D9C1FA7
              A00F2E723F53F1810FBA0FD7679E5099A34BD7480260F2478F96CF79F070086D
              F9FF7E2EC42E785BFE27CC89E58027FD7F31F0216F5CBC8439E083AEFC1CBD9A
              C612C0870100C4FBFBAFFD6B89F3BB8004E725F49454D0263CE96F969D04CBD8
              C73CB794F8C295F10440C03DD7F904FCE5EDC4B6A40C41C1C45D76FD1D92FAA1
              6AF7800DB4050A0A7BF2E2F34DB7F4719893F83110044014BD46E98060F9CDD8
              969561D67AAE30539B90D5EFD6BB7BBA72C779B0D1DD1F75CD45EBBD9E5B9A8B
              D2E9E7D8C01000416BBAD3274F8C2D0D635B56785B3C5AB0AB9EACBEAF877372
              82FFD0BF96390FBFF6E4C86263F61F32BAFDD21928022068BF2D97973D783814
              8CFD07AF6504F6A00BF036FEB48C2EEAA02ECEC1B6A4BC80311D3C7850FBB387
              A4FF50B58123809F69D375D633C67FC2E45F1BA0B0C01BD8870C9FC33B3A1BC2
              55568CFC028A8F0FAA2B067476ACD6D6C0120001F1DCE26DA2CDEEC5B6AC4081
              DBDB763DF8CE6E7DECC3B1EEFEC86BCE66A0F8B746EA243C38D004406C9B0BCE
              7796DBCB4AFFF3782837746A72BAB203E7A3601BFBB02D2BED56FBDDB0A55D97
              D54F4A6FE00980C01E5EB8FF69AF5E54CA5508FE5061BAF623146CA31D59D938
              B6947F78FFEED8169C64E390D1530245C6606A753817F0760CCF6E4CFA5749B8
              10B7A348E724D8F3E8A35C2EB7A5E724AC981D02748086026D10423CD2B9D479
              FAB1D770D6BCB0A43320195B99230082D26C94B672C1EFC6B60E815BC43D40AC
              DB75D8EAB78D4C1200415E6C14BF77AED552F93887D35648EE3CDBD46C14BFBB
              62C0908ECC1200EB7364FFEC33F0978BCF0578A92C38F7D0379D53CA13354E58
              ABA94C13C0070F0BC918975E09648CAD8938303F350711A0530ACF2DE25AC162
              E732F424183B0C8459F3AD23D4419F07880097000E85DD010F74775CD2D5DDBC
              139698B777779A7C4D04E8AA1E3CD01DE5CBADF1AE6E867D40901F74F79B7E4D
              0408A8E0E281D9E7A0D89C0986BF62D2C236F605A81ADF45048828212CEC0C41
              F115BEE913612CA54344809416A65F611101FA85B4663FBACC1101742169A81D
              2280A185D315361140179286DA2102185A385D611301742169A81D2280A185D3
              15361140179286DA2102185638DDE1120174236A983D22806105D31D2E114037
              A286D92302185630DDE1120174236A983D22806105D31D2E114037A286D92302
              1852B0B8C28C8B0027A302E66CF884655705893E0C10D328CC612CB026311180
              FF121CD29122040467BF0A0A271602786E3135BF8215947416FB9A7527F027F4
              63214007E0FF76CE744A1E81D05AC446808D634BEB93CF9B224004BC7A31F477
              0B6223C0855FC968B1F7630024C92120DAEDEB19E7222C82D808800EBDFDCE71
              C1F26FC33649FF11C88BB3D73517763F15E5395602A0E3A63B7DDA731DCE84D8
              06D7E740E850406015AA6705CF6D45CC1F6A7C21F4DEEFDB8D9D00BE23AF51FA
              3E04B50E84933871627059B33EF3888F7BAF73DF08D02B101A4F0601224032B8
              A7C62B112035A5482610224032B8A7C62B112035A5482610224032B8A7C62B11
              2035A5787320FDBA0A2340E0DEB11F14EE3DD35EBEBEBD7C552C0BF6DC26BF16
              6B3D871080F6F3D70AAC29F30309E0D17EBE29F55B739C8104E858EDB98EDCD1
              A393C108841280F6F30DAEAA42E8A104A0FD7C05140D560D2500E644FBF988C2
              604B24013075DACF4714FA27FDF6D493007E40B49F1FEB1EBED2F7039AEE9EC8
              751ABF6632676902C818231DF3102002985733AD111301B4C2699E3122807935
              D31A3111402B9CE6192302985733AD111301B4C2B97A6349CD240224857C4AFC
              1201525288A4C2200224857C4AFC1201525288A4C2200224857C4AFC12015252
              88A4C2200224857C4AFC1201122E44D2EEDF000000FFFF15D790D40000000649
              4441540300535FCF5BB8E1E1520000000049454E44AE426082}
          end>
      end
      item
        Name = 'Log'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D4948445200000080000000800806000000C33E61
              CB00000572494441547801EC9B3D88244514C75FDD7187E82297095EB29B18C9
              81A0288B70229869249BCF9C6060B233EE8C6272AC181C62AFDB62206EB03362
              6AA49920F8118868201C060A7A07061AAEF8C1C99E5B56B1D3DC5D2FD573DDAF
              BAFA75D57F98474F574D55BDF77B3F860D7A4F115E4913800049B79F08024080
              C409245E3E7E012040E204122F1FBF001020710289965F948D5F808244A25708
              9068E38BB221404122D12B0448B4F145D910A02091E8150224DAF8A26C085090
              48F40A01126B7CB95C08502692D83D0448ACE1E5722140994862F71020B18697
              CB8500652289DD4380C41A5E2E1702948924760F011269B8AB4C08E02293C838
              0448A4D1AE3221808B4C22E310209146BBCA84002E32898C4380441AED2A1302
              B8C824320E01226FF4B2F220C0324291CF4380C81BBCAC3C08B08C50E4F31020
              F2062F2B0F022C2314F9BC370186E3B72F0E47D96726BE1A6C66CF70B90D4657
              56CD5ED7105925032E672F029826FD41FAE87393CCD3269E548A3E35637F99CF
              DCF7AAD9004154C580382FB600C371969904EE37517EDF3718EF7C541EC47D18
              02777B0A5B00D2B4E53A4C69FDBC6B0EE33208F005905107B26848802F80D637
              1A9E8D650208B005383AD20FBBEAB8A9FE7BCC3587711904D8027CF0EE2B3F93
              D64F94CBD1A45EF870F7D5EFCAE3B89745802D802D67F6CEF49B593E5167FEF9
              E9AC0DFB799E6FEDDBB9E671CF81A6C335443583E67C8F577A11E0782BA2BDBD
              BD431BC53DE73ACFC707F3FCB5EB886A061CC676AD5701EC86886E09D43D1D02
              D42516D9F72140640DAD5B0E04A84B2CB2EF4380C81A5AB71C0850975864DF87
              009135B46E3910A02EB1C8BE0F01226968D3322040537291AC83009134B26919
              10A029B948D64180481AD9B40C6F025C1A653F0E47993E8E9DDF5FDC7EFFDEA6
              49D9758BC7C217FB15FBE27ACCF71607CB8A135E04B04969A2876E25A21F383C
              F8F36F73AF4CE02D98005B80C166F68BAB3E23C6AFAE398CCB20C01640295AAB
              28E57CC51CA63C10E06EC116809B00D6774BC087005FBB4B503FB8E730238100
              5B80593E59771532CBB79C8F8CBBD6603C2C01B600365D2381FD6BFFF65F82AB
              8B313B8D104CC08B00B63ED3F075136A1117EC1827ECD3C08BBD8A3D71CD2727
              187018DBB5DE04B09B21FA470002F4AF675E3386005E7186DBCCD74910C017C9
              9EEE03017ADA385F6943005F247BBA0F04E869E37CA50D017C91ECE93E10A0A7
              8DF3953604F045B2A7FB40809E35CE77BA10C037D19EED07017AD630DFE97A15
              606363E3F4C6F6F6591F490E46BBE7EC93C1882BAB550CB8ACBD083018BFF5DC
              7094E995F38FDF5C3958F9D77E1E6E66AFF392BB714ED1996B886A063CC6446C
              012E8DDF7C5469F5F18944145D1E6EEE3C7B621C03A208B005D0FAF4B7CE8A94
              FEC43987091104D80288A80249342600011AA30BBBB0ADD3D80268D297DDC9E9
              F7DC73989140802DC03C9FBE610AF9DEC41D6F45F4DB2C9FBE74C7206EC41160
              0B602B9AE59347B43A7541137D49A4BF50A4D7F7F3C983768E19D7CD7A045115
              03E2BCBC08601398EFBE7C759E4F2ECEF2E953FBF9F4F6FF11B0D3B563F158F8
              DA2C9F202A18D4065B5AE04D80D2BEB8ED090108D09346B5952604688B6C4FF6
              8500C21BD5767A10A06DC2C2F78700C21BD4767A10A06DC2C2F78700C21BD476
              7A10A06DC2C2F78700C21BD4767A10A06DC2C2F78700421B142A2D08108AB4D0
              732080D0C6844A0B0284222DF41C0820B431A1D28200A1480B3D0702086D4CA8
              B4204028D242CF8100C21A133A1D08109AB8B0F32080B086844E070284262EEC
              3C0820AC21A1D38100A1890B3B0F02086B48E874204068E2C2CE8300421AD255
              1A10A02BF242CE8500421AD1551A10A02BF242CE8500421AD1551A10A02BF242
              CE8500421AD1551A10A02BF242CE85001D37A2EBE3FF070000FFFF945B8FDA00
              000006494441540300342B364C0B4531570000000049454E44AE426082}
          end>
      end
      item
        Name = 'Send'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9D0B9C1B55F5C7EF4D76B7A56CA105E421288280
              F247F109882FF45F54FC0B2AC20A16DB66B65881D2CDA499140A8A5184DA66B2
              49B614A4B69BB4C8B388EFBFA0E25F4001051F28225214F44F05C496D22EB4DD
              DDE47AEE6CB60DCBEE36C9CE2477E6FEFA99D324F338F79CEF99F3CB64663609
              31FC030110D096000440DBD2237110600C0280BD000434260001D0B8F8485D6F
              02327B0880A40003014D094000342D3CD206014900022029C04040530210004D
              0B8FB4F526309C3D046098041E4140430210000D8B8E9441609800046098041E
              4140430210000D8B8E94F52650993D04A092069E8380660420009A151CE98240
              25010840250D3C0701CD084000342B38D2D59BC0C8EC21002389E03508684400
              02A051B1912A088C240001184904AF4140230210008D8A8D54F526305AF61080
              D1A8601E0868420002A049A19126088C460002301A15CC03014D084000342934
              D2D49BC058D94300C62283F920A0010108800645468A2030160108C05864301F
              0434200001D0A0C848516F02E3650F01188F0E968140C0094000025E60A40702
              E31180008C4707CB4020E0042000012F30D2D39BC0EEB28700EC8E1096834080
              094000025C5CA40602BB230001D81D212C07810013800004B8B8484D6F02D564
              0F01A88612D601818012800004B4B0480B04AA210001A88612D6018180128000
              04B4B0484B6F02D5660F01A89614D603810012800004B0A8480904AA250001A8
              9614D60381001268BA0018A62D8C68EAB199E72F991E40BE4809041A4EA09601
              9B2E004EB09C1F396952EB26470C4CFB4C671EFE030110F09C801A02F0F234D7
              9585E0A697CFC62B100001B709A82800C3399E5516828D73162C7BFDF04C3C82
              0008B84740650118CE729F5038F4B8148388995E383C138F200002AF2450EB1C
              3F08C0CE9C38136929048699BA7BDEBC6B5B772EC013100081BA08F84A007665
              C8DF3730656B3F89C18ECE2EFBBDBBE6E3190880402D047C2A003B536C132176
              0F09015D4AB4ED9D73F1040440A02A027E17805D4972167784C0B4D7CF8D75EF
              B36B019E81801E04EAC9323802B02BFB234AA2B4518AC19CAED4A777CDC63310
              008191048228003B730C85F8CD52082251FB969D33F1040440602781400BC070
              969CB30E2904641BE9E3C111C3F3F10802BA13D042002A8ABC0F7D3C584F4220
              0C336D55CCC75310F035817A83D74D002A38899421FF10C9B4EFE9E848B6552C
              C05310D08680C602B0B3C6EF6D3FB87D078941FF9CA8FDFE9D73F10404342000
              01D855E4D61067779110884E339DDE351BCF4020B8042000A3D45630B1500A01
              D95F67CFBF72DF5156C12C105086C0440281008C4FEFF0706BDBBF490884114D
              9F35FEAA580A02FE230001A8B6665CDCE4088169AFAB7613AC0702AA138000D4
              5EA133A51044A2F6A64857EEC8DA37C71620A00E0108409DB5E09C4DE7A181C7
              86C42095A8D30D360381091198E8C610808912A4ED39E7CBA4101851FB971D49
              DC53404830F9840004C0CD4271F6EEF6CDCE3D050346ACFB24375DC317087841
              0002E00555C65A9828FD5C1E1544A2A98C3743C02B084C9C4068E22E9AEB219F
              B57831C4DF40516C26536EA28F07A661DA824E1AFE6DF6FCAB704F817215F26F
              406E44EE7B019010D676C71F2321984EC699E0DF96F35433CED961E1D6ED43F7
              1498F667548B0FF1E8492010025059BA7C2EFEA9B210CCAA9CAFD8F31B9CA382
              58FA56C5E242389A11089C000CD78F84E09B5208065BC401346F0399721317E2
              0C290464CF774697BE41B9001150E009045600862B779D9DF81709C12164F4F1
              405C3B3C5FB1C76982871F35E85C01D922C56243380A12702BA4C00B4025A87C
              2E719E1402C1431FAD9CAFD8F3A5240282ECDE050B7A2629161BC2091801AD04
              60B87685CCC2DBA510ECD1BFC754C6F8434CCD7F27F685FBB7779AF640C44C7D
              40CD101195DF09682900C345BBFAEAF97DF96CFCAD520C98605F1D9EAFD2A360
              AC8533FE7F7444208F0AB22AC58658FC4F20E4FF14DCC9209FB3BE2885400876
              3C79DC46A6E2142D0BC1939F89DBFBA9182062F29E809B23400046D02CE4AC07
              4808A61C3AAD2F4C8B7E46A6E274E8E4227B4E8A41A42B3553C50011933F0840
              00C6A85332992C9110CC20E382339329FA8F87F8F552088C68EA36454344580A
              13800054519C42C6CA4921080F8AC369F58D64EA4D9C9FEE0881693F1F89DB6F
              542F4044A4220108400D55597555E2091282FDC8386DA6EAAF0D4DE345F66729
              0691987D31C589294004DC4E05025027511281B3C83813FCEC3A5D78BE19176C
              891402239ABE0FF714788EDB970340002658B67C2E7EB31482E2C0643A2BCF9F
              9CA03B6F36E7E25DF29E02128341C34CFDB73783C0AB1F0940005CAADADA1517
              6ECC67E3874931609CF7B8E4D66D37746583DF4942208C583AE7B673F8F31F01
              08800735CB67E2512904A1103F99DC97C8D49B84E892421031537F9F877B0AD4
              ABCF281179310B02E005D5B2CFD5DDF13B4908C2D378688A10EC37E5D94A3D70
              C65F3B50BEA7A0D3B4CF512A3804E339010880E78819CB64166E2BE4AC779218
              D04943F6A5060C59D71082B16FCAA302120225BF54A5AEA4B0D1B8042000E3E2
              717F613E677D450A8160A5B791F717C9949B48083E2985806CF3B966E668E502
              4440AE118000B886B2364785ECA2DF9310B49371DAF20E3215A7BD8BACF80809
              8130CCD4621503D42526AFF284007845B606BF2402A790713A4F30BF86CD1ABC
              2ABF520A41C4B47F158924273778700CE7110108804760EB714BE709AE964210
              2E165FC39878AE1E1F5E6F43872BC7F369EDDB480C8A73BAD233BC1E0FFEBD25
              0001F0966F5DDE572DBFE8A97C36B17F3E6B71FA3C7E7D5D4EBCDF28140A899F
              921008239A5AEEFD7018C10B0210002FA8BAE8B390B53E9B1F1282335C74EBAE
              2BCE2F7484C0B4FF612CE87995BBCEE1CD4B0210002FE9BAE89B84E03629043B
              760CEC436ED793A938BD8685FBFF25C580CE15A8FCB5EC2AB26B4A4C1080A660
              AF7FD01BAE59FC3C09C151649C7196AEDF93B75B72C6D64A2130CCF477BC1D09
              DE2742000230117A4DDE369FB12C47088A25F9A5A1834D0E678CE1C5278CA1AF
              3B7F614EEC6BC78CB1126637890004A049E0DD1C36BF7CD15D2404ADCF14DB26
              D3A5C4FBDDF4EDA2AFBD42A2E561290691987D898B7E03EDCAEBE420005E136E
              A0FF1F2DEFDA51C859279218D011B850B6C9E8D2C6155208C87EDD11EBDEA381
              8830D408021080114082F2329F4D2CC9D3D583121F7C13E5B4854CC5E9B87651
              7A2912B54B641F5231C0A0C70401087885D7642EFE1309C1DE649C4E1AFE40C5
              74394546F6633A221074F5E02A15630C6A4C1080A0567694BCE8A4E169520804
              E3734759ACC42CCED8FCB2103C35EBBCD4FE4A04D5A4201A312C04A01194151B
              A3908DF73A42D05A3A888E0A9E512C3C271C1282835B26F367A5187446D3B39D
              99F8CF75021000D791FAC76121B5E8193A2A38488A01132CAF6AE4828B358E10
              98F677558DD1AF714100FC5A3997E3CEE7AC4E2904D46C1F77D9B56BEE04631F
              3786EE29D832B72B254F6EBAE65B574710005D2B3F46DE854CE2FB5208FA8B6D
              7BD3C78347C658ADD9B3A79642FC8F8E1844ED2F343B182FC66F944F0840A348
              FB6C9CEB97776DA18F07C7483110827D4DD9F039BBDC110233FD00EE29A8BD4A
              1080DA9969B74521672D9642C099783725BF834CC149BC53DE536098E952676C
              D987150C50C99020004A9645CDA07AB389FB4808263F31ADAF95CED2DFAD6694
              74164384EE30E85C4167CC5EA1668CEA44050150A716BE89E4E7C9E4606FD63A
              299FB538E7CC523570FAE872811402236A6F9865F9E79E8246F2840034927600
              C7EACD58692904A2543A8AD2DB4CA6DEC4D9AB5B0687EE298898CB22EA05D8BC
              882000CD631FA8910B3D8BD693104C27A34F07EC365593E32C94778E0A62F6F7
              19FE3108007602D70990089C4146E70C85BADF0A24D8A98E1098F69648ACFBCD
              AE43F08943DF0B40249652F6E7B97DB20F7816663E97F8A62304C536794FFF06
              CF069A98E3A95C94FE20C52062A6BF38315713DFBAD11E7C2F005CF01B65F1CA
              F6FB39D1B4B277B235BAB8AA8C975FDEF51C09C12164F4F1805FA34A5C23E3A0
              4396AF0CED47A9DFCC9B979C327279105FFB5E004614E52D212EBE3B54445BD0
              E3BD9D66EAE411EBE0651309E4B3F10BA410085EFA6813C3D8CDD0FCED0353DA
              5F34E852225D41F8C86E56F6F5E2A009C0C8629C2818FF8953482A662466FFD4
              58989637B38C5C0FAF1B4CA0905974BB1482C116D14E433F44A6E6C4D9ED72FF
              E98CDACA1EB94C045CD005E0656CB860335849FC5216B46CDFA3CB426F7DD94A
              78D15002D7D989174908DE4A46E511973774F01A06139C9D27F7998869FFF3DC
              E81507D4B069D5AB366345AD046014C0A77116FA9D2CACB448D4BE31D2B5EC48
              867F4D2150C8262E9342C079F1380A601B9972139DC438A8C8273DE3EC2F66BA
              53B9006B0C48770178192ECED9D93C147A4C16976C9004E19AC805CB0E7CD94A
              78E13981DECC450F92104CC967E221AAC99D9E0F58E70074D27035ED27F26BCC
              94FCAAB56AD282008C4D294C3BDF79BC2DF4B42CB211B3B7D1E7C02B3A172D9D
              3AF62658E22A01CE456FC63A99C4807A4D445DF5EDA2333A2AF898B38F98F6D6
              73A3A9635D74EDB92B0840B588059B4C9F032F11FDE12DE562D3636A714732D9
              56AD0BAC573F817C2ED1238540B081C3C8CB463215A7F622E70F39FB47D4BEAC
              96009BB52E04A07EF27424C0AF6CDFDCBE43169C4E0E3D4B5719CEABDF1DB6AC
              864021BBF8491282FDC8E88D97DD5CCD364D5987B32FCBFD822E23FE765EF2DA
              294D89A18A4121005540AA6615DA1BF7A7D3D8D73845A74B8EF4F80489C2AC6A
              B6C53AF5112011389B8CD32785B3EAF3D080AD387BDBC0E6ADCE3D0591D8B253
              1A30624D4340006AC255D3CAAF2351584B42206F4892278A1EEEECEA3EBD260F
              58B92A02BD99C42D52088A03FDFBD1064F9229397111FA51797FB85695002100
              0DAA0489C1312254BAADBC0308239ABEAFD3ECC65D8A2EF25FBBE2928D240487
              9171C6458F8BAEDD7635CFD90FA2F6D3E746B307B8EDBC167F10805A68B9B92E
              17EF12ACB4EB2E45337D87114D9DE0E6103AFBCA67125147089898411C4A64EA
              4D9C1D58E483CE3D052408E7362340084033A88F322667E2C38CF3FB694718FA
              C8104DDD3ACB5C7AF428AB62560D04F2D9C4CFF2592BDCC74374224E3C58C3A6
              8D5EF51B4EED63A91F36726008402369D730169DD93AA385851F71760A795231
              6AF7CE8E751F5C830BAC5A41605D66E1B67C36715C3E6BD1B95A7159C522B59E
              0AFE3FE59AF7752E4CBFC5EBE020005E1376CB3F674658949E2AEF1CC288D9DD
              E72CE8D9CB2DF73AF9296413974B21080BF1163A59D0D7CCDCC7197B4F5112BF
              97F58E98A9E438EB4D6811046042F89AB6F100676C5B68D28E62D32208C0C045
              2E5A0413843200C9D4990204A04E700DDE6C07EDA8974FA3CFB1F29D8BACAD37
              635D2AFF92AEC171046238C34C5D29DF59190BFD8612DA934CC5E9451EE2CE5F
              49D2114BD2AB0021005E919D805F41EFEE74F897149BFBF6A066E764936927B8
              2C9359A8E45FC84D20D5866D3AF3FC25D33B4DFB2F438DCF17376CE05A07E2E2
              7FA9DEB2E6EDBDDDF1876ADDBCD6F52100B512F366FD1719135FE89BD6374916
              BF90B5A6147A125F2E078AB8F100000D9D494441541492DBBD194E1FAF7363A9
              B365D34F9AD4BA8984F52895321F11CBE764EDE9F2E5C746CCF7F42504C053BC
              633ADF2284B8F8D0697DAD4ED1B3567B3E9BB8625D32D93FE616585013012396
              766EBA2A097E634D1B367265C19E098B9603F37465826C5523871E1E0B02304C
              C2DBC74D9CF158DF865FB550A1E5E1DDDE855C626932991CF47658BDBCCF8EA6
              8EA577FB2D648209A1F26DD72B9DFD20671DB42A673EDBCC2A41003CA1CF9F15
              9CCDA72287C864C3EFDB9B8D67D7AD5B57F46438CD9D1A31DBF9CBBB30E70F11
              8AA9644A4E82973E5ADE1F3EAF4A801000772AB1810B3EAF5C5C6AF8F881858C
              7535B9A68F9DF43F26D709C87B20E89DFE61327AB7670ADFD8C37ED73A6DEA9E
              72DF905F843A0C42954708405D95E04FB292E894452DDB21BDB9F837EA72858D
              6A22400D7F2699680BF7BF401B1E43A6E624D8979C7D2367BD7D65F2F32FA919
              24631080EA2AF338BD95CF760AEA9CB0891F96EF49E4ABDB146BB941802EE1DD
              221B9F7CAD235375EA9377173AFB49CEFA8AAA4156C60501A8A431FC5CB04743
              5C7CC629A4D3F0D6917469EEBAE1C5786C0C8173CDA54753D36F261324C01D8D
              19B5F65128B61F96F795A9AB72893FD4EEA1795B400086D8FF911E3ACA45E4F9
              9C75F4EA4CE2269A87A90904E8A4DE1764D31759F8111A7E6F322527C1F85CB9
              CFD09BC3A9B504A8D2BA7A0A8060BF138C9D2E8B57B663E9F156950AA35B2C1D
              1724DBA9E99D3F7E61825DAE6AFEB4DF3C1D163B9C6BF7856CBC57D538AB8D4B
              0F0110EC811013A7529373C7E8C44C216B7DA75A4858CF3B02462CF5096A7CD1
              DED6BE9546F1FCCF5F698CBA262ED8D7E5BE43FBCDAB57E52E6DEAB5FBBA1218
              63A3600A8060F7D2BBC829B2608EE5ACE35767130DFDA285317863769980114D
              5D2F1B9F09AEB6100B768ADC877A73D6F9E5D003F5100801A0C3B2BB19133364
              A11CCB59EFA1CFF17704AA520148666EACFB884834B5C9697CCE67AA9B92F86D
              EB4B7DCEB57BB7F723D572F6BD00C886A7C3B293F2D9C4CF54838B78860874C6
              EC8B65D39744693DE77CFAD05CF5FE178C3BBF4D48FBD23B56AE4C2A7BEDDE4D
              72BE17003761C0977B04E6CD4B4E31CCD403B2F1E91ADE12F73CBBEE69ABE021
              791298D3493D654F3EBA9E75D92104A00C020FEE108874A59DEFB41B98D2FE22
              63FC9D4CD57F9CFD203F748FC75E85CC42791958D5483D8D0B02E0295E7D9CD3
              3B7D818CDE4C85D2275B052B194EE367ACD31A5D1D15C78300A858159FC41431
              97BC8E9AFE39324121CF21537312EC9F832DE200D9F885ECA2829A4136272A08
              4073B8FB7AD4CEA81D974DCF59EB139488FC392E7A506FE29C5D2D9B9ECEE41F
              7C9D9DF8977A11363F220840F36BE08B08162CE899444D7F2F99109CD9EA06CD
              05E7A58FC8C6EFCD58F3D58D538DC820006AD441D9282251FB43D4F4C5BE70BF
              FC7EC213950D94F107E5AFFFE4B3F1506F66D18F558B53D5782000AA56A6C971
              45A2A995D4F8F46ECA6433A9BB9F08F645F96E4F8D7F9CFCF59F2663F3DDF0EA
              16D67728FD1FB0FCE9B188693F3BD4F8FC730A67B43554126F761A3F677D55E1
              38950F0D02A07C89BC0FD088A6BA64D38745E929CED8FEDE8F58DF0814DBF79C
              A6CF5A7BADEE493C5C9F176C55490002504943A3E7F3E65DDB4AEFF677C9C667
              9CE7544E9D4EEBCD918DDF9BB53EA1729C63C5A6F27C0880CAD5F120B6D95DE9
              0F52D30F0C4CD9DA4FEFA8EFF76008575C0AC6360C6E1FBA76DF9B8BAF75C529
              9CBC820004E015488239C388A59753E38B7048C83F9A6A51354B6AFC15F2DDBE
              90B50EB9EEEBB876EF759D20005E136EA2FFC805CB0EEC34ED7FCAC667425CD8
              C450C61D5A088A4EB00F971B5FD938C74DC2A70B21003E2DDC78611B66FA7CC3
              B4056F0B3D4DEFA8078DB76E93973D20AFDD17725688EC274D8EC593E155770A
              0150BD4255C6D7D1D111EE8CA57F2A1B9F31217F94A4CA2D1BBF9AE0EC52F96E
              4F763CAEDD379E7FE58810804A1A3E7CDED965BF979A7E7BFBC1270C0A216628
              9CC296121F7C13353D2F64AC2B158E53ABD020003E2D77C44C65A8F18508B17B
              288549648A4EFCBBB2E9C9F65E93B9F84F8A06A96D5810001F957ED679A9FD0D
              33FD77437EBE67DC5439743AF750FE25A5F827558ED3CBD8FCE01B02E0832A45
              CC659DB2E95B26F367E9F3FD6B150EF9FF59B16D7F7AB7E774190FBFA4A470A1
              864383000C9350F0919AFE76323A67165AAD6078BB4212E22AD9F464AFCD2FEF
              7A6ED7023C539D000440B10A19D1D409D4F42F91D15134FB8862E15586532A95
              F8C9D4F43C9F4B2CA85C80E7FE21000150A45691A8BDCC697ACEEFA790F62053
              722255FAB5D8DCB707357E784D4FFC4E2583542028BF8400016862A566CFBF6A
              5F6AFABF9209CE59A289A15431B4B8849A5E7EB63FA15048CA2F07A9621BACA2
              3A010840132A4487F99F954D1F6EDDFE6F1AFE703255A717C22CFC5FB2F1F3D9
              84CADFEDAF2A3FE5E30A291F6180023462F6F765E333CE953E43CE19FB4E3E6B
              71B269ABB2B13F07A8044865040108C008206EBF9CD365BF839ABE8F4C30C14E
              75DBBF9BFEA8F13F4B4DCF7BB3D6E96EFAD5CD979FF285007854ADCEA87D856C
              FA50883D4843EC49A6E444AAF48FD6307B55B9F1AF57324804E5190108808B68
              679EBF64BA61A61E958D2F38BBC445D7EEBBE2BC274F87F9856CE2D095694B9E
              8B707F0C78549E0004C0851219D1F459B2E9274D6ADDC4187F0353F75F913131
              43367E3E138FAA1B26226B140108C004481BB1F46D86690BC6C54D1370E3FDA6
              82DFDF5E6C9B4C8DDF92C7CFA87BCADB6FCE210035566C7634752C35FD0B64F4
              F159287DB24C70B6384F87F9F95CFCC4E5CBBB76D4982A56D7800004A0CA2277
              9AA9A441EFF661CE1FA24DF6225375DA2CC2EC68D9F8858CF5355583445C6A10
              80008C53877316F4EC454DFF473241C7F95F1A67D5E62F12E2DBB2E9C9A617D2
              D6A3CD0F0811F881000460942A454CFB53B2E9DBC2FD2FD0E23791293B899238
              879A9EE773894F291BA42681F9314D084045D52251FB16D9F89CB16F55CC56F1
              E9DFB797AFDD177A1237A8182062F20701ED056096B9F4686AFAE7C904E7AC43
              F1B2E59C77FBACF5BA1B71ED5EF152F9233C6D05C030D3971A7452AF85851FA1
              524D235372A2A39141BADCF0C172E32BFD35604A024450E312D04A003A2E58D1
              6E44EDDFCAC6674CA8FEABB2F7C96BF7BD59ABB5904DFC7CDC2A6261D309F835
              002D0420124B9D269BBEBD6DDB56C6D9DB142FD645E577FB77E3DABDE2950A40
              78811600239ABA5E363E17FC7B8AD76A3317C537961B7F99E2B122BC0011089C
              00CC8D751F414DFF6F32BA74CF67AA5C2B3AEBF8AD72D34FEFCD5DF417956345
              6CC124101801A0865F444697C54BEBA954FB92A93CCD948D5FC8C4CF543948C4
              561D013FAFE57B018898F6AF64E353119692293B09C19E280E4CDE4F363ED98D
              CA068AC0B422E07B01A0CB64C7AB5C312144961A9E1772D6E16B575CB851E558
              119B7E047C2F008A966C90F1D007861A3F115334468405020C02E0E64E20D8BD
              7DD3FA2651E3B7E6330BEF72D3357CA949C0EF5141005CA8201DE62FA2A6E7F9
              9CF59E75C964BF0B2EE102041A4200025027663AA9F7BC28B51E251BBF904BA4
              EA7483CD40A0A9042000B5E3BF75A8E9AD7D0A3D5179C9B1760FD80204142100
              01A8B610829F2D1B9F4CF5BF18AC3623AC37410241D81C02307E15FF561CE81F
              BA769F8BDF3CFEAA580A02FE23000118A5669CF16E7AA7E764AF5FBBE2125CBB
              1F8511660583000460571D074A829D444DCF7BB3F1F8AED9780602C125000160
              EC177D1B9C6BF76D6B72D6DDC12D3532739340507C692C003C21DFEDC9DEB76E
              1DAEDD076587461EB511D04D00368578E8486A7AFA7C1FB76B4385B541207804
              B4100021D8BAA1A6B7F65D9D59F878F0CA888C40A03E0281168052499C251BBF
              90B33E5D1F1E6C0502AF2410A439411480C7E9307F5FD9F86B7A12B704A958C8
              0504DC26101C01102C2D9B9EEC483ACCDFE43628F803812012F0BB00F4F3127B
              1F353DCFE72C2B8805424E20E025019F0A80B8A7F5A5A96DD4F8937A7BAC5F78
              0908BE41A09240D09EFB4A0038E3716A7A9ECF26DEBF72E5E70782560CE40302
              8D26E00701D8542A968EC8672D798B6E77A301613C100832019505E066D9F464
              FBAE59BEE8AF412E0272038166115051003AA8E9E930DF3ABB5950302E088C46
              2088F3D4100021D6EFD831B04FB9F16F0D2268E404022A1268BA00384D9F4B1C
              75C3358B9F571110620281201368BA0004192E720301D509400054AF10E25382
              405083800004B5B2C80B04AA200001A80212560181A012800004B5B2C80B04AA
              200001A8021256D19B4090B3870004B9BAC80D0476430002B01B40580C024126
              0001087275911B08EC860004603780B0586F0241CF1E0210F40A233F10188700
              04601C3858040241270001087A85911F088C430002300E1C2CD29B800ED94300
              74A83272048131084000C60083D920A0030108800E55468E2030060108C01860
              305B6F02BA640F01D0A5D2C813044621000118050A6681802E042000BA541A79
              82C028042000A340C12CBD09E8943D0440A76A235710184100023002085E8280
              4E0420003A551BB982C0080210801140F0526F02BA650F01D0ADE2C817042A08
              40002A60E02908E8460002A05BC5912F085410800054C0C053BD09E8983D0440
              C7AA236710281380009441E0010474240001D0B1EAC81904CA042000651078D0
              9B80AED9430074AD3CF206012200012008984040570210005D2B8FBC41800840
              00080226BD09E89C3D0440E7EA2377ED094000B4DF050040670210009DAB8FDC
              B5270001D07E17D01B80EED9FF070000FFFF61D0E26700000006494441540300
              050AE8793355AEF60000000049454E44AE426082}
          end>
      end
      item
        Name = 'Greenhouse'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9D0D701CE579C79FF74E12C691832131841A300E
              1F856912086992424BD2340D9D264D27D3D664F830BE95C11920D6ED4927BB0E
              04144800FBF6AC95449CF0A53B9C92A1386966923699814EEB649AAF0E09043A
              298100066C423060070B8C25DDBD795EC922B27CD2EDEDEDBBB7BBEFFF6657B7
              1FEFFB7CFC9EDDFFEE696FF7528417088080B1042000C6961E8983001104005B
              0108184C00026070F191BAD90454F6100045012308184A00026068E191360828
              02100045012308184A00026068E191B6D904A6B387004C93C03B081848000260
              60D19132084C1380004C93C03B08184800026060D191B2D90466660F01984903
              D3206018010880610547BA203093000460260D4C83806104200086151CE99A4D
              6076F61080D944300F020611800018546CA40A02B30940006613C13C08184400
              026050B191AAD9046A650F01A84505CB40C010021000430A8D3441A016010840
              2D2A58060286108000185268A4693681B9B28700CC4506CB41C000021000038A
              8C1441602E021080B9C86039081840000260409191A2D904E6CB1E02301F1DAC
              03818413800024BCC0480F04E6230001988F0ED68140C2094000125E60A46736
              817AD94300EA114AF07ACB76BEABC604A788D4EA108000D40194D4D519DB799D
              73FB5B351E9CE6490CA61180001856F1CBB3EE7BF8A82F05D191D3A9AB69B5AC
              ABA778D6F432BC9B41000260469D27B3E49DFCB68A98F8C5E44C8D3FB22A1FEE
              CA156FAFB10A8B6248C04BC810002F9412D0C6B20B2F711A6B789C7790525EC1
              42F1F2BC8DB03231042000892965ED445676DF7212EFD09248BC8DBCBF8E517D
              565FED2CF3DE052DE348000210C7AA798CB9CB2EF4B7A5DA9EF1D8FCB066D576
              DA61659D1B0F5B810589210001484C290F4DC4B29D672589EB0F5DEA634ED0B5
              6CEB391F3DD1A58504BCBA8600782515937617F53A6FE71D5672B827F218D470
              82B269AD1D5A129441D8890601084034EA104814999C73D5820AED0EC4582D23
              E9B117AD6CA1BBD62A2C8B270108403CEB7658D4BC633E2A247DF9B015412F10
              6290AF28FC3268B3B0D71A021080D6700FCCEB9A35B72D54A7E724C4BB02335A
              D7903853F9BCEAAA2F77D66D8A06A11368C42104A0115A116B6B658B7F37BE70
              DF6BAD0A6B7FC7FE7D19DBF98756F987DFE60940009A67D8120B7C04BE9F84FC
              4E4B9CCF702A88BEC91F09B6CF5884C918118000C4A858D3A15A59673F4F7F8C
              C7880CE2C32C48073818D603FE8B2136042000B1291551C61E38DBB21D498216
              4430EC0E8EAD7A596EE30722189B3121359A2804A051622D6A9FC916EE145479
              A845EE3DBB4DCBF44FF98AC4D73C7740C396128000B414BF37E77C647D5908B1
              DA5BEB08B412E2528E796F0422410875084000EA006AE56A75330EEF48926338
              86C7B80D47A9D8BBECCDEF8C5BE026C50B018868B53376E10675334E44C3F31C
              96A4EA932C041B3D774043DF04FC748400F8A1A6B90FEF30CF09129FD7EC862A
              441F173CEAF6C3F6D775D9CEF3FC8E2162042000112A88B5F6A625BCF3AB53FE
              137487352A520BB7BAF9EF8DF0A8A675FBE3A48E57B95D6A7FE978DDBE60DF3B
              01088077565A5B66724E96D21D2F6A75A28C0B7AA8E4E6C5B6811EF55D02B584
              D4B45AC6330FF3A87568A7239E672158A7D5098C7B260001F08C4A5F43CB2E3C
              2624B9A4F92549AC2E0DE4CF99CB0D8BC07BA5946BE65A1FE0F28D2C02BF0ED0
              9EF1A6FC028000F8251740BF95F9C25B78479044E28F49F36BC182F163CA6EEF
              483D37E5C1BE3B5222D5C8E3C3EA999C6BFD2996EDC8156B6E396AAE0658AE9F
              0004403FE39A1E56DBCEA7DA26C468CD95C12EDCC14776F1955B36ECF16AF6AE
              819E57541F6EEFFB7162DCD7D3D0B9B06D6F2657B8D85363340A9C00042070A4
              F50D666CE7FB55A26FD56FD95C0B29E91ADE9197FBB5C27D4F9624AFF3DBDF6B
              3F21C53DCCE4A75EDBA35D70042000C1B1AC6F494AD1653BE37CE9ED43F51B37
              D7424C54969607F337356785A8ECF6DD3856A904F978B19A2131930FF0478289
              FEFE7E6C933509CDBDB0993580DD0CBD06FA5AF6C03956AE58E50FFC6D0D74F3
              D3F4B77CE41623B7AE0FECBAFB3DC3EB772A9B4452DFE3C6A6324D3FB3B7B362
              7517CF9B9AC55FDD042000BA09B37D2BE794892A3FE349CD837478477D872E27
              25B7EF5816B0415DF6DFB49B923FECB28BF7BD398F096D042000DAD04E19E6D3
              DA3D2469D5D49CBEBFB25A3D9D77D03E7D1EA62C97DDBC2D27E8CCA9397D7FF9
              7F0F2B98DD3E7D1E6059118000280A1AC68C7DF3C9BC01F301931693DED7AB25
              372FCA43EB9ED0EBE60FD6CBB7E61F533E7989EEAB189D8A61A67BD369EC0B43
              0D02CD2E8200344BB0467FCB2E7C5150FBD3355605BA484ABA9777C4965D4767
              DF8B8410DF0C34A91AC6442AF578C62E0CD45885454D12800034097076773E62
              ED2412D790E697AC54CEE5FFF25FA4D94D5DF32303BDFF24D2747EDD864D3610
              246C1656FD5F956E32CEB87587000454B195F9C2B1BCF3AB53FEA501999CCB4C
              6574D7496DE5E1F53F99AB41D8CB478AF9FF79FAE1D176225121AD2F3179B3D4
              256B376ABF594A6B1A11320E0108A01856D6C9B54D88DF06606A7E13927E5472
              F36DDBB65DA879479B3F8C5A6BB76FEF9F28B9BD6D7CA4FEDF5AEB835CD6914E
              3FC71F09B4DF2E1D64CC3A6C05611302D024453EEA3F4E82363769C64BF715A5
              C1FC9F7B69D8CA36236EEF0765555EA23B06169A1B98FD0EDD7E926E1F02E0B3
              C2EA5771780354A7FCA7F934E1B9DBE8D8E8223EF27FC3738716372C0FF57D7D
              AC321AC63F2797A91A64EC01DD575A5A4C549F7B08800FB656B6F8E9FD1DFBC3
              B846FD2BDEF1C5B62DFDBA2FB7F9A0307F977B86FB272F4F72ABA778D43A08AA
              ECB172054BAB93841A87003458D84CD6F93109796F83DD1A6F2E659677FE331A
              EF18AD1E9CC3291CD17A1EF50E528CF05582C83F363D280841D981007824A96E
              52B16C470A417FE6B18BEF66ED695A521AEC1BF26D20621D590436C9B16A088F
              0213933F9CB262C57DE98821886C3810000FA5B1B2850FAA9B543C346DB6C94E
              DE59C4EDC5FC4BCD1A8A5AFFF296752FA8DC48D20BBA63EB5CFAEC84B576D387
              75FB49827D08409D2AF269E5BF9210FAAFB90BBA81779013EB8413FBD5A5C1BC
              3A13D8A43D91746A3B9FB17D5BBB9F983B8000CC5340CB2EF23FFAC485F33409
              64D54475625969207F7D20C6626084856EBDA071F5BF01DDD17ED2B29DD7753B
              09DB7E90FE20003568AECC1796F386C397F864678DD5812D9292F6F0CE20BE36
              F4CFCF066634268646DC0D4FA9DC39DCDFF1A8733852D572A5BD51FB1D8C3A93
              D0651B02308B2C6F2C1BDB2684FE4B5742DC511ECCC7F127BF66116B6E964560
              3109BABB392BF57BB751FA97FC716E4BFD9666B58000CCA8B795757EC3B3DA9F
              595F91F2AC9181DE301EBFCDE9447FE08F3F19A2EAFBF4472AAE64817F59BF9F
              F878800070AD2ECFBAC7F186214990B6A7E9B01B358CF1114F6C1DEC7B44CD60
              FC038192BBEEE78A0D2F19E751E7708CAAF5CAEE5B4ED2E94497EDA0ED1A2F00
              5D59A7B72226B45F9A9224EFE70DFC88A00B98347BCCA88373FA2F1EB50E6DA9
              B667AC9CF305AD4E6260DC6801E023C1135290A3BB4E324D1794DDBEBFD1ED27
              29F659043E2A53E213DAF391745DC676766AF7136107460A40D7BA8D8B78E797
              5C975379D43A8C2E1E3DA25CCC3FA0D549028D9737F77EB7B3D2B140776A8268
              A9DA162EBEF2E6A375FB8AA27DE30480157FA51C4BBFAABB18AC2E8FF0914C6C
              EBEF1FD3ED2BA9F68787BB0F28869CDFFFF1A87538E288F657AC6CF1335A9D34
              695C4777A3048095FE4156FCAD3A40CEB27945D9CD9F356B19667D12601178B7
              ACD2953EBB7BEF26E457791B79D47B87F8B7344200D4CD215C583E2893F64B4D
              92D247F3067B67FC378D6865501ECA7FF5C081F130BE37F12EB5ADF4F7F7EBFE
              019748004EBC0064729BCE5737878440FB19DEF145D9CDED0DC197912EBEFE95
              0D7B146322A1FD9B93CFECED1CEFB237FF3525FC956801E0CFFBDF1632F503FD
              3514D7F28679B27E3FF0A00894DCDE657C59F53A35AD7394547D80CF06EED7E9
              C3AB6D5DED122B005CB837F8F3FE2775819BB65B116F9CC01BE497A6E7F11E0E
              81B2DB776345A4C2783AF0C7785B3A104E56E17B499C005CD1533C9D0BA63EEF
              EBFED2CD4B7CD4175B07AEDD157ED9E05111D83AD0B34BD580A7753F3FA1436D
              5399DCE677B3AF440D8912002B571C9CA8CA5FE9AF90DC2A69FCFD19FBE69331
              B69E81AA0591D47E7547C8EA23996C2151FFE04D8C00B042EF2629BBF5EFFCCA
              83B84C50FBD318A3C380485C4621BC8410AB795B0BF51FBD3AD38ABD005C6A0F
              1CCF0551A7FC6FD7090AB641600681A3D436B7BAD7593663592C27632D00965D
              D8D04E95E763491E41C79E40B5423BBA724EACFF011C5B01B0ECE2D344E226C2
              0B045A48404AFA9C653BBB5A184253AE63270097AC1D7A2B03E7537E89EBEE4D
              951E9D0324F0476A9BBCECEA9BDE16A0CD4953BAFFC44A003276B1AB233DA6FB
              1972BA99C37E4209A4DB3B5EB2B285CFC629BDD808002BEC2382E45D71828B58
              0D2420C4B09573FE3F2E99475E00D44D19BCF34B069AB82F61704E18924840D2
              196A9B5DB1A25F3DDD28D219465A0056F5143FAA6ECA8834410407027310E85C
              DA7920D353FCF81CABEB2E0EA34164058015F4815455FE671810E00304741110
              55F91F5DB6F37D5DF69BB51B4901B0B2CE042796F85B3139470C0610E0CFAF1F
              B2ECA2DAA623976DA40460556EF39F58B62349509AF0028144119069B56D67EC
              81B3A394566404C0B29DDB52B2AAFDD96F51828F58CC2320A8F2106FEBE57A99
              87B53E120260D9057573057E2927ACAAC34FAB09AC6211D8D7EA2094FF960A80
              D5533C914148227114E105026611E854DBFECACF1696B732ED960980A57E95A5
              2AB53FDBCD275C7546B283FB62244A0A038AE2ABAD4D3CD565176F69556C2D11
              0056BEE748D275AD4ABA9E5F3E2579B8E4E697634C0E837A356FE57A49723D5F
              F9FACD740C61BE872A00EAD75778E7E7FD8BC278965B981CE12BF904C6B5A628
              E81D6ADFB8A8D709F5B916A109806517AF54BFBEA215E294F15FB0A27E646A12
              7F412018027C36A8BED6ABFD27DE165468B7952D86F4642BA25004C0CAAA9B23
              E496604A318F952A65B85091BACE3A4FB458153302BC6D5D20255DA03D6C2107
              2DDB795CBB1F76A05500D6ACB9AD9D139124E80CF6A5753872ECC845A5A1FCDD
              5A9DC0B8F104CA83F907DA5F5FA4CE06B4B09861F434B5EFAC5D3BA4F5E9D6DA
              0460B55DF8C4F8C27D633312D23329E9495666B165CBD5A37A1CC02A081C4AE0
              F6DB3F33AEB6393E1B78ECD035C1CF8DA6C7DEC8D8CEA782B73C65518B005876
              F1075512FF3EE542DF5F4122571ACC9FAACF032C83C0DC04F86CE04C29E8EAB9
              5B04B346107DCBB20B3F0AC6DAA1560217004B7D979FE4F987BA097EAE3D4D4B
              46DC5E3778CBB00802DE099407F25B522215C2A3C0C4B953FB96F7D8BCB40C4C
              002E5B5B7CAF8E0067272189267F0DE6F6625EF7AFC1CC768D7910A849E0AE81
              9E57D447025ED9D4C341B97FDD41ED63ABBA9DF7D56DE8B1412002D0653B5BD3
              69F9738F3E7D371324BF5076F3F80E816F82E8A893008BC0094292F62755A752
              F4A0952BDE13442E4D0B002BD2281F95570611CC7C36C62A951347DCBEFEF9DA
              601D08B49AC0C860FEF17364CA00000837494441541A49E3FABFDF2FE5C556B6
              F05AB3F9FA1680CBF385E5BCF3F3BE4F6F693688F9FB8BDD25372FEE195EBF73
              FE76580B02D120507637EC50DB2C47A3F78E3F2116AA7DB0CBDEFC4EF6E56BF0
              2500965DDC5899104FF9F2D84827490325B7F7D846BAA02D084485008BC05BF9
              52E1BD5EE269A68DA4EA935D3967931F1B0D0B80653B2F10C9757E9C35D2A75A
              A99ECA97F87A1AE983B6201035027CA9F02259A99CAB3B2E169ABEA97DB3314F
              9E05C05A3BB4841DA853FEE31A73D170EBBDAC9CE2EEE1754F36DC131D402082
              04CAC3EB7F32BAEBA4B610423B4EEDA36A5FF5EACBB3009486BB770B123FF46A
              D867BB3B79E73FDA675F740381C812D8B6EDC20A6FDB82CF9E1FD41CE4F7D4BE
              EAD5876701500647DCDEBFE0772D4F379522F51E067405DBC7000289255072FB
              DE2FA4583533C100A77F5772F30DFD0E414302A0025DB67834E89B135EE3A045
              79A0E751651F2308249DC0C860EF5649E9C0CF74793F5ADC28BB8605A0BFBFBF
              2A489ED7A8A35AED25D1BF71D09DB5D6611908249940D9CD4DFEAF8B73548F5C
              E3B7E606315159EAC742C302A09C8CB87D3FE6F7FB78F43D084A9F5776F3FF48
              788180C104F800B89C247DBE19047C20ED1EB975FDF37E6CF81200E58803FF34
              BFFBB90577BCB478343DE2E69488B0090C20602E0195395FEEFE62BA5239514D
              373C4A7A880FA4C30DF73BD8C1B700A8FE2C028BD4BBE751D27F739F0EEAEFAF
              7AEE8386206000813B87D7EFE47D83AF12502337B955593CCE69064F5302A01C
              CB6AF574F55E6F9415F9F71CEC5FD56B87F52060320116812552CA3BBC30E0B6
              4DFF845ED302501E5AF7842439EF7DF9A322B5B03CDCF71D2F49A10D08984EA0
              3CD8B7A65211F31ED9AB95EAA941706A5A00541065B72FC7EF2FF2387BF819AB
              94D836D0B37FF60ACC8380E904E6CB7FEB70EF4325B757ED9F070E6B27E986BB
              03FAA6AC7270987D3F0B78473FF42BC252ACE4657FEAC716FA800008280242F2
              3EB480A7B6F37870104FF147E9EB0FCE34FD1698004C4652199BBC736FACD271
              5469B0F75F2697C5F00FFF27E66CCB769EC6981C0631DC0CDF0C994540FDCEC5
              0AB580CF0A4E51EF418D810A4069F87307EFDDEF7E35A8005B64477DA3EA64F6
              8D9128290C28CE2F16816FF0C8C7A660B3085400820D0DD64020B904A2921904
              202A95401C20D0020210801640874B10880A010840542A813840A0050420002D
              800E9766138852F61080285503B18040C80420002103873B10881201084094AA
              81584020640210809081C39DD904A2963D04206A15413C20102201084088B0E1
              0A04A246000210B58A201E10089100042044D87065368128660F018862551013
              08844400025003B424DA2E697C39C6E430A851662C6202100086506B28BB1B76
              604C0E835A35C632220800B60210088140545D4000A25A19C405022110800084
              00192E4020AA04200051AD0CE202811008400042800C1766138872F610802857
              07B1818066021000CD80611E04A24C000210E5EA203610D04C0002A01930CC9B
              4D20EAD94300A25E21C407021A09400034C2856910883A010840D42B84F84040
              2301088046B8306D368138640F0188439510230868220001D004166641200E04
              200071A8126204014D0420009AC0C2ACD904E2923D04202E95429C20A0810004
              400354980481B8108000C4A5528813043410800068800A9366138853F6108038
              550BB18240C0042000010385391088130108409CAA85584120600210808081C2
              9CD904E2963D04A046C504D15F5AB623312687418D32631113800030040C2060
              2A010880A99547DE20C00420000C0103080441208E36200071AC1A6206818008
              40000202093320104702108038560D3183404004200001818419B309C4357B08
              405C2B87B84120000210800020C20408C495000420AE9543DC20100001084000
              1061C26C0271CE1E0210E7EA21761068920004A04980E80E02712600018873F5
              103B0834490002D0244074379B40DCB38700D4A8A024DA5E72F302637218D428
              33163101080043C00002A6128000985A79E40D024C0002C0103080801F0249E8
              0301484215910308F8240001F0090EDD40200904200049A8227200019F042000
              3EC1A19BD90492923D04202995441E20E0830004C00734740181A410800024A5
              92C803047C108000F880862E66134852F61080245513B98040830420000D0243
              7310481201084092AA895C40A0410210800681A1B9D90492963D04206915453E
              20D00001084003B0D014049246000290B48A221F1068800004A00158686A3681
              24660F0148625591130878240001F0080ACD40208904200049AC2A7202018F04
              20001E41A199D904929A3D0420A995455E20E0810004C00324340181A4128000
              24B5B2C80B043C1080007880842666134872F61080245717B981401D0210803A
              80B01A04924C000290E4EA223710A8430002500710569B4D20E9D9275200CA6E
              DFF6929B177EC7B29BFF48D20B6F5A7E7EB785E97E49E5954801486AB1901708
              044D0002103451D8038118118000C4A85808355C0226788300985065E4080273
              108000CC01068B41C00402100013AA8C1C41600E02108039C060B1D9044CC91E
              02604AA5912708D4200001A801058B40C014021000532A8D3C41A0060108400D
              285864360193B2870098546DE40A02B30840006601C12C08984400026052B591
              2B08CC220001980504B36613302D7B0880691547BE203083000460060C4C8280
              69042000A6551CF982C00C02108019303069360113B38700985875E40C020709
              40000E82C01B08984800026062D59133081C2400013808026F661330357B0880
              A99547DE20C00420000C010308984A0002606AE59137083001080043C0603601
              93B38700985C7DE46E3C010880F19B0000984C00026072F591BBF1042000C66F
              026603303DFBDF030000FFFF1E1C2FF2000000064944415403007FEB59B5F0FB
              45FB0000000049454E44AE426082}
          end>
      end
      item
        Name = 'Inventory 1'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9CDB761C471586AB050A0412308B17885F8024E4
              4072C955CEE7E416340E21472CD91971B8F35D16968447989844048D58ACDCE0
              9CCF77B925E49C3C40F2082108034EAC62D778248F9591D433D3DDB5ABF6A735
              658D7AAAABF6FEFEEABFF6F4C89A727C4100026609600066A5277108388701B0
              0A206098000660587C52B74D20648F01040A34081825800118159EB421100860
              0081020D02460960004685276DDB0436B3C7003649F01D020609600006452765
              086C12C0003649F01D020609600006452765DB0406B3C7000669F01C02C60860
              00C604275D080C12C0000669F01C02C6086000C604275DDB04B6678F016C27C2
              CF1030440003302436A942603B010C603B117E86802102188021B149D5368161
              D96300C3A8700C02460860004684264D080C2380010CA3C23108182180011811
              9A346D13D8297B0C6027321C87800102188001914911023B11C0007622C37108
              18208001181099146D13D82D7B0C60373ABC0681CC096000990B4C7A10D88D00
              06B01B1D5E8340E6043080CC05263DDB04F6CA1E03D88B50A6AFB766976E6ECD
              2DFA5E3BBC7473A66992D61E0430803D00E5F6B25CF02F49F3AEF02F6FE5B6E1
              5F0EC7A4BDB4758C27260860000664BE776EE126B9B87BBBBDA47B8BB49D1EB7
              6CF66B5115ECC428ABE3184056729E9F8C5CCC2F4AF31BAE78E5FC574AFC4455
              500292EE2E65A2C300CA504AA8CFB6DDFED60A42A72AA800A2D6213000ADCA8C
              1897ECF4E3EFF665E7A22A284B2A997E184032527D35D099C34B37CA85BFF9DE
              BE8ADDFEAB930C3F4255309C4B72473180E42473AE35B7F4424B3EC22B36FCAB
              D1C3A72A882EC1B000CA1EC300CA928ADC6FE6E0D181DDDEDF16399C61D35315
              0CA3A2FC1806A05CA003738BCFF776FBA9A9F8BB7D59565405654945EF870144
              97E0AB01C8457F43B8E843F3CEDDEED2FDA22A50AE1D06A04820B9F07BBBBD5C
              F4AF290AAB9A50A80AAAE158629451BA6000A3D0AAA1AF5CF4B9ECF665E95015
              9425D5403F0CA001C8C3A6681D5A7AAE5FE2E7B7DB0F4B78D8B17E553033B7C0
              FF4118C6A781631840039037A7F8C9DCE2D66EEFBCBF63F3B8F5EF852BA80A22
              2D020CA001F0ADD985DE6EFF35E7ECEEF66539F7AB02A98E5E2C7B0AFDCE1118
              F51906302AB192FD670EFDEE7A59C4677F4BAF28D8ED4B721BE876EB263FFE67
              E200958A9F620015039545FBAC345FF88DD72B1EBAEAE13EF6EE6BDF0B4D06FE
              589ADE0755416DDA600015A03D6FB777EECE0A86AC6D0879BFFD48B7D32EA4FD
              60AD73E8B3D0C2736985DC97F8456D135733F0B9AA6096BF625405520C60028A
              B2D327B1DB7BE73E9AFEC697FBC245BEDA79F4F19D52EE2ECFFF21F449A22A28
              FA7FC56876917B057D41C7F986018C486DE6E0D173EFED95EFF6BE700F870B7A
              ADD3BE74E5B7BFFE67D95407AB825031943D2F4ABFC251154C001E032809EFC0
              A1A56764C7F7C5D494F6F7F61F4E9F3ABBDBAF1D6B9F2899DE8EDD42C5104C24
              54108554123B76D4F0C2665530B7F482867052880103D845A5D6ECE275E1A20F
              CD7B7FD72E5D15BC543C142E546997ADAC94DFEDCB061E2A8855A92464FC62C3
              6D3C52F6BC38FDFC6D41B3D0EE9D5BB8294E0C69CC8A010CD1696676A1B7DBBB
              C2BD31E4654587FC07A7CF5CF0DD7051763B8FFEB1A9C0FED2F9E5E361CE14AA
              820D57BC128CA095795530AEF618409FDCE06E5F1485EADDBE28DC83E102EC76
              E62F7FFAF8C1CFFB2934FE6DB02AF0DE3DDC7800234D4855300C9779034866B7
              F7EEFDD367D67BBBFDEAB1F613C3C48C796C6DB97DA22B1F2F86AAC03BFF51CC
              58F69AFB5C55B060FE5E8149034869B777BE78205C58DDE5F60F9F3E7E24DA6E
              BFD745B5F97AA80AD63AF39786989D2B1E72AABF8AAD7B053F357AAFC0940124
              B3DBBBE2BDE28233DF09175177F9D127555F43BB0417EE4B841CD64F7DB94FEE
              A77CB84BD7E82F4DF5EF151C985B7C3E7A3023063049F7A9494E4EE1DCA4767B
              E7EE0F178C5C3857AC1EFDD5BF52E05B26C693F2A944F758FBB2905BB87F51E6
              9C587DBC73B7B7E6167BFF8763E6F0D28DB1E2686ADE6C0D40443C29CDCBCEA3
              FD4EFE7BC5E7FDDDBED35E694AF858F384FB17C108C2A7171283EAAA20FCD5E5
              B0865AB34BCF49AC593EB23280D6C0E7F6A2D6DDD2343FFABBFDFC15ABABF9EC
              F66581874F2FC4087A5581974F35CA9E17A55FE1EFE819815406B95505591880
              8893C86EEFDEBDF0F48517CBC22FA465BFDB97BD58D7E4530DE15184FB1E724E
              2255C1828AAA40784DF448D60052DAEDBDF73F0F0B5CDA95274E3CBC3E916219
              9F1CEE7B08A3B355C1867B5075AA4571AE2A387834D97B05C919403ABBBD7F67
              FDF47A6FB75F5B9EFF93EAC5AC30B8B5DFB79F1033D8AC0A3E5018E25648C5D4
              D4ABB22EC38DC367B70E26F22409034873B79FBFEAE48923ECF6135E08FDAAE0
              F260065E7B55E0DC9D7D23F0F271E20D13A6DEC8E9AA0D4020FE2D00D57F27DF
              BDFDE5D7FD456191B2DBD7B76E37AB82701FC579F77E7D334D3EB277EEB5B076
              0F1C5A7866F2D1868F50C551750630B8DB0BC47BAA48B2AE3106DEDB5FFDD7C5
              F97FD7350FE39E4F20DC4709BF19190CD7F9E281F35FD5F593F7C55DC1084293
              0D4D5D55A0C600044E32BBFDF4BE8BBF1D161FBB7DFC8B2DFCA664D022DC6F71
              AE78CF29FE920DAD571584DF48D5126654034869B717C1EE0B0B4DDAD52B47EE
              3F253FF3504420DC6F09BF4129FA14DAAB82A2385715CC1C3A7A7D4C8C510CE0
              C0EC6212BBBD38F63FA64FADF7767B59584FC5148AB9CB13D8AC0AC27D19E7BC
              EAAAA0F053AF87B707D24E96CFD0B9AAFA366600E7EDF68553FDDE5EE0F676FB
              B54EFB472B2B47D8ED05488A8F705FA6DB99BFA2DB694B55E055DF2B10BE778B
              09848F127DB856E4E7461EB51B404ABBFDBE62EA5B61B14863B76F64F9353749
              7779FE49D1B508F76F9C77EF3637F3183315EE8D6006E1BED818678F744A2D06
              101C2C24109A4F68B73F76ECF07F46A247E7E40884FB37DDE5F695C10C24F8FB
              A5A97DC85BD07BC235D46BB38BD7D511682D06209FDB3F5147B0158EF9D63ABB
              7D8538D31C4A4C60455A11EEF33857BCE3347F156EEB9AAA32CC7A0CA0CA08AB
              1DABF7DE5E44BFE624BB7DB564131E2DDCE7914F10AE927551481AAAAB0289AF
              D287050378CBEFFBFE85415C69BCB7AF74F9E43798AC915E55102A44F9044177
              555001FE9C0D606BB75F3BD2FA6F05AC18C210815021763BF3BDAA20FCC667AE
              A9E76500DEFDDD7FB6CE6E9FEB6A8D9457F88DCFAE7C94D8AB0ABC7B3B5218BD
              69ABFE27170338BBDB2FB7AF5D5B3BC26E5FF52A61BC1E815E55B0DCBE3A9881
              1CB84F5AF28F740D4076FB8BCE5CF0CD208634DEDB27BF14D34A20AC396945A8
              3825F2B7A425F948CE008AC2FF2C8097CF72AF3D7EFCE0FF92A44ED0D9100815
              A7ACC76BA4854F1092AB0AD2308081DD7EF5D8FC9FB3593D249215013181A7A4
              9DAD0A64CD569D5C1DE3A93680C2B3DBD7213A63D64BA05715C8FDA86006A162
              AD77B6C946576900DE7DB13FC05B5D66B79F4C5ECE8E4D2054AC612D87351D3B
              9661F3AB34806181720C0210A89E0006503D53468440E504EA1A1003A88B2CE3
              4220010218400222112204EA228001D4459671219000010C20019108D136813A
              B3C700EAA4CBD810504E0003502E10E141A04E0218409D74191B02CA096000CA
              05223CDB04EACE1E03A89B30E3434031010C40B138840681BA0960007513667C
              0828268001281687D06C1368227B0CA009CACC0101A5043000A5C21016049A20
              80013441993920A0940006A05418C2B24DA0A9EC3180A648330F041412C00014
              8A424810688A0006D01469E6818042021880425108C9368126B3C7009AA4CD5C
              1050460003502608E140A04902184093B4990B02CA086000CA04211CDB049ACE
              1E03689A38F3414011010C409118840281A60960004D13673E08282280012812
              83506C1388913D0610833A73424009010C4089108401811804308018D4991302
              4A0860004A84200CDB0462658F01C422CFBC105040000350200221402016010C
              6008F999B9C72EA1E5C76088D4E60F6100439640E1A6DF94F6096D3A27066F0E
              915AC5A19841600031E93337042213C000220BC0F4108849000388499FB92110
              990006105900A6B74D2076F618406C05981F021109600011E13335046213C000
              622BC0FC108848000388089FA96D13D0903D06A041056280402402184024F04C
              0B010D0430000D2A1003042211C0002281675ADB04B4648F0168518238201081
              000610013A5342400B010CA01E253E956169CE55CDC0F1552D010CA05A9EBDD1
              BCFBE2C7DD4E7B3FAD3A0681690F6E06FF684A0103D0A406B140A061021840C3
              C0990E029A0860009AD4201608344C0003681838D3D926A02D7B0C409B22C403
              81060960000DC2662A08682380016853847820D020010CA041D84C659B80C6EC
              31008DAA1013041A22800134049A6920A0910006A05115628240430430808640
              338D6D025AB3C700B42A435C1068800006D00064A68080560218805665880B02
              0D10C0001A80CC14B60968CE1E03D0AC0EB141A066021840CD80191E029A0960
              009AD5213608D44C0003A81930C3DB26A03D7B0C40BB42C407811A09600035C2
              65680868278001685788F8205023010CA046B80C6D9B400AD9630029A8448C10
              A88900065013588685400A0430801454224608D4440003A8092CC3DA26904AF6
              18402A4A1127046A208001D400952121900A010C2015A58813023510C0006A80
              CA90B609A4943D0690925AC40A818A0960001503653808A444000348492D6285
              40C50430808A81329C6D02A9658F01A4A6D888F1B6E616FD246DC4E9E89E1801
              0C2031C10817025512C000AAA4C95810488C000690986084AB97408A91610029
              AA46CC10A88800065011488681408A043080145523660854440003A80824C3D8
              26906AF61840AACA1137042A2080015400912120902A010C2055E5881B021510
              C0002A80C810B609A49C3D0690B27AC40E81090960001302E47408A44C000348
              593D6287C084043080090172BA6D02A9678F01A4AEE01EF1773BED6292B6C7F0
              BC9C38010C207101091F029310C00026A1C7B910489C000690B880841F8F400E
              33630039A8480E10189300063026384E83400E0430801C542407088C49000318
              131CA7D926904BF618402E4A920704C62080018C018D5320900B010C201725C9
              03026310C000C680C629B609E4943D0690939AE40281110960002302A33B0472
              228001E4A426B94060440218C088C0E86E9B406ED9AB3480C24D7FD29A5BF4B1
              9A887C89B4461F33738F5D3261BE9F3415B0C439913E21D7A6621D986752BE13
              ADC7B0A6076251F354A501A8A1432010C89C000690B9C0A40781DD086000BBD1
              E135080C10C8F1290690A3AAE404819204308092A0E806811C09600039AA4A4E
              102849000328098A6EB609E49A3D0690ABB2E40581120430801290E802815C09
              6000B92A4B5E10284100032801892EB609E49C3D0690B3BAE406813D0860007B
              00E26508E44C0003C8595D7283C01E0430803D00F1B26D02B9675F8B01743BED
              FDD20AAB6DADF39B4F475D38E19C0979ED1F75CE71FB4B9C13E91B721D75EE70
              8ECC6B764D49EEB5E85B8B018C2A2EFD2100813804308038DC9915022A086000
              2A6420088D042CC484015850991C21B003010C6007301C8680050218800595C9
              11023B10C0007600C3608907B4000000E44944415461DB04AC648F0158519A3C
              213084000630040A872060850006604569F284C0100218C010281CB24DC052F6
              188025B5C91502DB086000DB80F023042C11C0002CA94DAE10D8460003D80684
              1F6D13B0963D06604D71F285C000010C6000064F21608D0006604D71F285C000
              010C6000064F6D13B0983D066051757286409F0006D007C13708582480015854
              9D9C21D0278001F441F0CD3601ABD963005695276F0808010C4020F080805502
              188055E5C91B0242000310083C6C13B09C3D0660597D72374F000330BF040060
              99000660597D72374F000330BF046C03B09EFDFF010000FFFF37760B5C000000
              06494441540300120F6579767DE53D0000000049454E44AE426082}
          end>
      end
      item
        Name = 'Inventory 2'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600000CBE494441547801ECDADF8B5EC51DC7F139BBC4DEB54269A1D096E4C6
              D25E14845CB4B4B437FE0F5228B209A197F56972B6A585420B8540CD669F6DEF
              0CE6AC8A98FFC12B050591205E292A24087AA388E88DBF768F33CB2E3EAC9BF5
              FC98EFCC77E6FB5EF6F83C79F69C99F9BEBE331F129335C717020898152000CC
              B69EC211708E006017206058800030DC7C4AB72D10AA27008202170246050800
              A38DA76C048200011014B810302A4000186D3C65DB1638AA9E003892E0150183
              020480C1A6533202470204C09104AF08181420000C369D926D0BAC564F00AC6A
              F01E0163020480B186532E02AB0204C0AA06EF1130264000186B38E5DA16385E
              3D01705C845F236048800030D46C4A45E0B80001705C845F236048800030D46C
              4AB52D7052F504C0492A7C8680110135017071B1B5716171EDC6C6A3D79EF7AF
              77B8AE61B0A8CBE0706FDF087B5D4BBE640D007FC86FF9AB0F57EFFACEA35C6A
              1AF73BFF7A96CB61E0EA3238DCDB97C25E0F7BFEF0BAE5327E6509800B8BC79E
              0BC5FBBA1FF617DF08581678389C8570262411EE3576D200B87079EB27A158E7
              9A871C5F0820B022D03C14CE4638232B1F8ABF4D160017FF72FDBCDBEFDF11AF
              8809102859C09F9183B392A8862401F0C8A38FFDB2EFF75F495413D32050B440
              382BE1CCA428423C00FEB8D8FED17AD3BC96A218E640A016817066C2D98951CF
              69638807C019B7F7DE690BE067082070B2408AB3231A00B9FECFE6C99C7C8A40
              7902D2674834001CFFB7DFF185C03C01D9BF31130B00FF571A59FF81C33C749E
              46408FC09CB3F46D558805809F987FE4E311F846208280D859920C8008753304
              0208480A8804C0C662EBA2E4A2191B016B0252674A24001AD7FFDA5A83A81701
              498129676AC87A4402A0EFDD034326E71E041018262075A64402A069DC4F8795
              75F25DBDDB7FB0775F9CE3C2A09E3DB0FFE0C9BB7DD8A773CFD4BD661109807B
              4D36FCF3BD8F76977FBFCB85412D7BC0B9BD8F86EFFF74772A0D807400CC8440
              8D02436B2200864A711F02150A10001536959210182A40000C95E23E042A1420
              002A6C2A25D91618533D0130468B7B11A84C8000A8ACA19483C0180102608C16
              F7225099000150594329C7B6C0D8EA0980B162DC8F404502044045CDA41404C6
              0A100063C5B81F818A0408808A9A4929B605A6544F004C51E319042A1120002A
              692465203045800098A2C633085422400054D248CAB02D30B57A0260AA1CCF21
              50810001504113290181A90204C054399E43A0020102A0822652826D8139D513
              0073F4781681C2050880C21BC8F21198234000CCD1E359040A1720000A6F20CB
              B72D30B77A0260AE20CF2350B000015070F3583A0273050880B9823C8F40C102
              0440C1CD63E9B60562544F00C450640C040A1520000A6D1CCB46208600011043
              9131102854800028B4712CDBB640ACEA098058928C834081020440814D63C908
              C412501A00EBF76F2CAE9EE5C2A0963DE0DCFAFDB10E6DCC714402A071EE9D39
              8B6CDCDAAB8D3B73870B837AF6C0DAAB6EC6D7EA999A31CC371E150980DEB9B7
              BF31131F2080C06401A933251200BECA97FDC5370208C4131039532201D02DDB
              C7E3D5CD4808202075A6440280762180808C40EC51C502C0FF99E5E9D88B653C
              042C0A489E25B100D85DB68F586C163523105B40F22C89054040685CF36278E5
              4200816902D2674834006E2EAFFC765AD93C8500024160F50C855FC7BE440320
              2C76BF77BF0FAF5C0820304E20C5D9110F802777DA175CEFFE33AE74EE46C0B8
              803F3307674798413C00C2FABB9DF69F4DE3DAF09E0B01044E170867259C99D3
              EF8AF3D3240110967A73BBDD727DFFABF09E0B0104EE21E0CFC8C15939F663A9
              5F260B805040B7B3F972B76C1BFFFE5D7FF18D00025F0BBC1BCE4638235F7F24
              FF2E69001C95E30BFD7173DFDE779DEB5F3FFA8C57046C0AF4AF87B310CE448E
              FAB3044028F4E67FFFF649B7DCFC45783FF3BAEB9FE7720E833C066ECE573803
              E12CCC1963CEB3D90260CEA2579FED96ED392E0C72ED81D5BD28F55E72DCE203
              401287B111A85D8000A8BDC3D487C0290204C02938FC0881DA050880DA3B4C7D
              450B482F9E009016667C04140B10008A9BC3D21090162000A485191F01C50204
              80E2E6B034DB0229AA270052283307024A050800A58D615908A4102000522833
              07024A050800A58D6159B60552554F00A492661E04140A10000A9BC292104825
              4000A492661E04140A10000A9BC2926C0BA4AC9E0048A9CD5C08281320009435
              84E5209052800048A9CD5C0828132000943584E5D816485D3D01905A9CF91050
              244000286A064B4120B50001905A9CF91050244000286A064BB12D90A37A0220
              873A7322A044800050D2089681400E010220873A7322A044800050D20896615B
              2057F504402E79E64540810001A0A0092C01815C0204402E79E64540810001A0
              A0092CC1B640CEEA09809CFACC8D40660102207303981E819C0204404E7DE646
              20B3000190B9014C6F5B2077F50440E60E5C585CEB2D5F99F9CD4F4F0098DF02
              00581620002C779FDACD0B1000E6B70000B90434CC4B0068E8026B4020930001
              90099E6911D020400068E8026B402093000190099E696D0B68A99E00D0D209D6
              814006010220033A5322A0458000D0D209D6814006010220033A53DA16D0543D
              01A0A91BAC0581C40204406270A64340930001A0A91BAC0581C40204406270A6
              B32DA0AD7A02207347BA65DB58BE32F39B9F9E0030BF0500B02C400058EE3EB5
              9B172000CC6F01005209689C8700D0D815D68440220102201134D320A0518000
              D0D815D68440220102201134D3D816D05A3D01A0B533AC0B81040204400264A6
              4040AB0001A0B533AC0B81040204400264A6B02DA0B97A02407377581B02C202
              04803030C323A0598000D0DC1DD68680B00001200CCCF0B605B4574F0068EF10
              EB434050800010C4656804B40B1000DA3BC4FA1010142000047119DAB64009D5
              130025748935222024400008C1322C022508100025748935222024400008C132
              AC6D8152AA27004AE914EB444040800010406548044A1120004AE914EB444040
              800010406548DB0225554F0094D42DD68A40640102203228C321509200015052
              B7582B0291050880C8A00C675BA0B4EA0980D23AC67A118828400044C4642804
              4A1320004AEB18EB4520A20001101193A16C0B94583D015062D7583302910408
              8048900C834089020440895D63CD08441220002241328C6D8152AB27004AED1C
              EB462082000110019121102855800028B573AC1B8108020440044486B02D5072
              F50440C9DD63ED08CC1420006602F23802250B100025778FB523305380009809
              C8E3B6054AAF9E0028BD83AC1F81190204C00C3C1E45A0740102A0F40EB27E04
              6608100033F078D4B6400DD513003574911A10982840004C84E331046A102000
              6AE8223520305180009808C763B6056AA99E00A8A593D481C004010260021A8F
              20508B0001504B27A90381090204C004341EB12D5053F504404DDDA41604460A
              100023C1B81D819A0408809ABA492D088C142000468271BB6D81DAAA27006AEB
              28F520304280001881C5AD08D4264000D4D651EA416084000130028B5B6D0BD4
              583D01506357A90981810204C040286E43A0460102A0C6AE5213020305088081
              50DC665BA0D6EA09805A3B4B5D080C1020000620710B02B50A141F001B8BAB67
              B930C8B5074A0F86E203A07167EE706120B9074E1B9B00285D80F523605840C3
              EF003E33EC4FE9B605B2EF7D0501D05CB7BD07A8DEAE40FEBD9F3D003E5DEF09
              00BB27407DE5920BD4B0F7B307C0B35BED0792C88C8D8056010D7B3F7B001C34
              A777970F5EF90F02560494EC791501D0EDB4DB56FA4E9D0804012D7B5E450004
              90BDB5E667E1950B012D0252EBD0B4D7D504C053D7AFBCD937CD1352E88C8B80
              0681B0C7C35ED7B096B00635011016B3BB7DE592EBDD1BE13D1702D509F8BD7D
              B0C71515A62A00828BFFB3D1CF5DE35E0AEFB910A848E0F6C1DE565690BA0008
              3EDD76FB1BE7FAABE13D1702390462CEE97FDB7FA35BB6E7638E196B2C950110
              8AEB969BFFF87CEFBEEFF9F79FFB8B6F044A14F872AD59FBBEFF6DFF9FB42E5E
              6D0004B067FEFFE78FBB65FB9D7E7FFF01FF3B82F7C3675C08E817E8DF0F7BD6
              EFDD334F6C5FFE50F37A5507C011DCEEFFFEFA56B7DCFC61B76C9B4FD7DD0F7A
              D7FFBBE9DD2DFFF3DBFEBACBE53070D90C6E87BD18F664D89B618F767EAF863D
              EB0AF82A2200561DC33F9FDC5D6EFEEBE64EFB87CEFFB9CA5FE7B85A0C96F10C
              46EEA7F3612F863D19F6E6EA5E2DE17D710150022A6B44A0140102A0944EB14E
              040404080001548644A0140102A0944EB1CE2402D6262100AC759C7A11581120
              005630788B80350102C05AC7A91781150102600583B7B6052C564F0058EC3A35
              23702840001C42F08280450102C062D7A91981430102E0108217DB0256AB2700
              AC769EBA11F002048047E01B01AB020480D5CE5337025E8000F0087CDB16B05C
              3D0160B9FBD46E5E800030BF0500B02C400058EE3EB59B172000CC6F01DB00D6
              ABFF0A0000FFFF06C9BB0200000006494441540300327992C4681EE6AA000000
              0049454E44AE426082}
          end>
      end
      item
        Name = 'System Admin'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC5D099C2355997F2FE9E9B91A182E5744E5F040D0
              5D457EFE5C05995150617551761D51462015C641067ABAD2A9F480A80441904E
              75A732C38C804C120E41995D761515540E05F1E0E7A2EBC1A1888382178723D3
              CCD59DBCFDBE74673693E97427A957AFEA557DFD7BAFAB52F5BEEBFFBDF7CFCB
              AB4A25C6E88F102004228B00114064534F8113028C1101502F2004228C001140
              84934FA1471B018C9E080051A04A08441401228088269EC22604100122004481
              2A211051048800229A780A3BDA08D4A32702A823415B4220820810014430E914
              322150478008A08E046D09810822400410C1A453C8D146A0317A22804634689F
              108818024400114B38854B0834224004D08806ED130211438008206209A770A3
              8D4073F44400CD88D06B4220420810014428D9142A21D08C0011403322F49A10
              8810024400114A36851A6D04A68B9E08603A54E8182110110488002292E8E630
              13666E8961DA5BB0E27EF3797A1D0D048800A291E75A944B5766FB60C0DF0B55
              70C6EF85837D58711F8F41BD17DBC0312A114180082002898677F82C0C6ED1D7
              DBB705C25D02B55559826DB02DCAB46A44C7F543A095C74400AD90D1FC380CE0
              FA141FDFED2FEE341C98155C8C4400750BEAEA549EDAEB810011801E796ACBCB
              952BD7C1143FF75D18B438E8EB53FCB6646768D4076450FBD86098B9EFA28D19
              DAD229CD102002D02C61D3B99B3473B529FEB6DE6D30C5E78BA76B23E7185F8C
              360CD31649B029472769F1130122003FD177611BA7E5863982ABF84230DEF114
              DF85E99A28DA3480080CF0017DA91DA47F81446026A7880066422760E770851E
              A7E1060C3C9C9633267015DF672FC56E1F11D0479F1D22F31D204004D001587E
              354DC274DB80418F2BF48C710FA7F8CCE51F5F8C3EA2AF49F0D9A53212578000
              11800290BB31915C35F2CE244CAF0D18F838DDEE46879F32E833FA8E31602C7E
              FA42B65B234004D01A1BE567CEB0720B0D73A4B68A2F62E21E118829BE3B1830
              068CC500223320368CD19D4692EE0481D9DA1201CC869082F3B088565BC5EF99
              E063F0B93EC0537CB76088C518A301648031BBD546F2EE112002708F61571A96
              4FDE8B3F86830116F42EEE4A89C6421833C60E750CB1D03814AD5D270250983E
              9CFE1A66AE36C5AF4CDE8BBF50A1F9A09A5A8858001108C406310AAAA361F48B
              0840415613E648EDB65A9CFEB240AFE2339FFF78C3478491C8CD8A6483DF8E3E
              22807650EAA20D7CC6C57BF1A7A6F822DB858A488B70266AEB22303318432C23
              0D8687C11301480477C58AEC02E8B0B5FBE6E1332EDE8B4F537CF7F82E442C01
              57F88860DF8B18BB57491AEA081001D49170B14DACCAD5A6F8E30BFA5E043533
              7DDD164E537181C012C418C9003177A18744A71020029802A2D30D4E4BA1234E
              4EF1635CAB293EE7FCCE311E5B50722C8E15F7F158A718F8D99E03E6803FCE0A
              E823C2348968F7101140BB4841BBA5A9D1F9D0E9749DE23FCB58F5181CF0C57C
              FAE48DF9C16D1052ADE03E1EC373D8060E425BF8AF47D9ED2302E6480FB783E1
              2511401B793006ECCFC0C0177DA2BA159A6B35C5E79C9D8B031BEA812567E821
              F07FC6826D26DB5A9C83EC8C8D83777209E6087385390B9E7BC1F38808A0454E
              8CD4E862E848B5293EE3EC9216CD827998B3120CE2DAF4BE98B7AEEED64994AD
              EB61A0B35B3DBEC841CE207FB58F08984B5F7CD0C0281140439270FA9830EDDA
              149F89EA77E19446ABF8E29171B6E365B5019BB792E0BBD452029DA81B6D3026
              1E91AADC5B650B31974806985BCCB1B7E6FCD7DE8907440080164E17B183E0F4
              9133A6D3147F5C30762A0ECC929339EA26E7A23F318FFFD006DA2AC10222DA06
              73E350B528985BCC31E61A73AE85D31E3B195902387BC03E1E3A8296537C21D8
              E7710042ED2D3BD67F7BDC475AAA47DBE803548E3EB56C18C4130D1F11B02F04
              D145153E458A001289EC3C18F477431555CEBE07006B34C567F74CF4883E1C6C
              E5827521F81EA8823EA16FE82338760F545DCA42EC0BD827A0DE8D7D4417C765
              F81909024898239F86E40ABEA80F2F7DBD4B06702A740821FEC684F8671C5850
              4FB8D1CEE08D462A4C776D037D445FA172F4BD1643D7DA940BBE0BFB08F615EC
              33CAAD4B30D8A98AD012402235FC0E48646D8A0F3DF1B39D02E3677BCEF8F938
              80CA85CC7EA542E6C77EFAE2C636FA5E8B01D60B302637BA54CB629F81FE53BB
              8A807D49B57D55F6424500FDFD6BE62606ECBB30715CC4EE0310B599E273C66E
              C4418FB5E8A4D781EFA12A1813C6861563D528B885D897B04F61DFC23EA691EF
              B3BA1A0A028015DD4F6182C6E23BB773CE4E9835EA80348055F4DFC62B9557E0
              A0283AD6990171CB733730568C1963470C3C3728C900F62DEC63D8D7B0CF4952
              EBAB1A6D0920B9CA3E0E12519BE233CE2EF515C5CE8C573917A7E1008055F457
              5FB776F5539D8987A735C68E1820168809445685AA47813E07FDAFF61101FB62
              109CEEC607AD0800A75F8699FB0E022F62EC7E08589B29BEE02C871D1D6ABC98
              CFDC0ABE5369400031416CA072C4AAE154D07717625FC43E897D13FB68D01D6E
              F44F1B024898571C8AD32FC6F8894C933F98DEDE377FE7FCBDB05397F3D69026
              6EFBEE26628598217688A1EF0EB5ED003F11FB28F6D5B6457C6EA80D01F88C53
              DBE6A1C3BE5065D5E3B003C3F476F1FAF5E78DB52D4C0D774300B1430C114BC4
              14B1DDAD01BD708D0011806B082715C0B4D5C48E0A1D769FEB9DA107268FD27F
              590820A665C7DA073146AC65E90D8B9E6EE32002E81639908377A42F6187C40A
              D3D6021CA2A20001C41A31C78A39506032B42688003A4FED932CC65F899D0FDE
              913ED6B93849C844007380B9C09C80DE27A152E90001228036C1125C2CC38E06
              F5D0D268FA0F6D8A51334508604E6AB9712CB88A20962932ABBD192280995228
              581E3A55EDC11AE57CE6E6999AD2B9E02080B9AAE78D410E83E399379EB8D14A
              04D0841E67FC01DE5BD9BBD6810AD660D3697AA9190225C821E612738AB9D5CC
              7DCFDD25029884784CF0EAF1D8518A4EFAB8E2F0EA2D9387E97F5810C09C626E
              31C7986B888B2ECF0208D12600CE06B14340DDAB9C1FC23B0B01122A61470073
              8D39870A930216E9595E1409E0164C7CADE6AD7CD83B3BC537330225E803B5BE
              008B87D0F216A85A15B7CE468900364D25FA74B7A0917C381180FE713A540ED1
              6D821A89122502884442294842A0130488003A418BDA120221438008206409A5
              70A283808C48890064A0483A08014D112002D03471E436212003012200192892
              0E424053048800344D1CB91D6D0464454F04200B49D243086888001180864923
              97090159081001C84292F410021A224004A061D2C8E5682320337A2200996892
              2E424033048800344B18B94B08C844800840269AA48B10D00C012200CD1246EE
              461B01D9D11301C84694F411021A214004A051B2C855424036024400B211257D
              84804608100168942C7235DA0878113D118017A8924E424013048800344914B9
              4908788100118017A8924E424013048800344914B9196D04BC8A9E08C02B6449
              2F21A0010244001A24895C2404BC428008C02B64492F21A0010244001A24895C
              8C36025E464F04E025BAA49B100838024400014F10B94708788900118097E892
              6E4220E0081001043C41E45EB411F03A7A2200AF1126FD844080112002087072
              C83542C06B048800BC4698F413020146800820C0C921D7A28D808AE8890054A0
              4C3608818022400410D0C4905B84800A04880054A04C3608818022400410D0C4
              905BD1464055F44400AA90263B844000112002086052C825424015024400AA90
              263B844000112002086052C8A56823A0327A22009568932D422060081001042C
              21E40E21A0120122009568932D422060081001042C21E44EB411501D3D11806A
              C4C91E21102004880002940C728510508D0011806AC4C91E2110200488000294
              0C7225DA08F8113D11801FA8934D422020086843003D62FE3697982D70294FE2
              8440E810D0860076CC191F73853E677BBB9227614220840868430037DA99175D
              E12FD83C57F2244C087888805FAAB52100BF0022BBD143A0E4588741E55805AB
              1E0D08DC0E35948508209469A5A064215076867E0644700AD41A2130C13E2D4B
              7710F4100104210BE4833608940AD6654806872C1A9B034EFF0754AD0B1180D6
              E923E7FD42209BCD4E00112C85CA19AB1E033383EDDDFAE2A71C11809FE893ED
              50205072861E8299C17CC1E2FB42407F80AA4D2102D02655E468D011283BA9CD
              30237865D9B97053D07DADFB4704504782B68440041120028860D229E4E020E0
              B727912280FEFE3573FD069CEC1302414240370278D60D78DB62D523DCC8932C
              21103604B42200C1D8C36E1230119B38CE8D3CC912026143402B02806BADAE08
              800BF6FEB02590E2D117812078AE1501F09878D0156882BDC7953C0913022143
              402B02603C76972BFC398B33FA230408815D08684500A5D1B4567759ED429976
              94206098F9371BA6FDA18469F71B66EE72236517930323771803B9DB9203F63A
              C31CB928618E2493A67DF2D9A9D1FD94381570235A1140C0B124F7142170B639
              7C2C0CEE7B0CD3168D95B1CAFF800B1B39636B18E317C29A9121B83889717EAA
              E06C2563E232CEC406584CFE6655549F6B9485FDE71203B9CCD2A5B72A9925B2
              80FC458E008C55236F0F08F6E4469B0824CDD1C36180DE09B536E0AB2CF67D18
              DCEF6C53BCDD66FB71CE87FB0EFEFDC4949D678C81DC39ED0AEBDA2E72042062
              E213BA262B4A7E9F61E55E620CD8B57779C1AABF85D8DF0B55653900660E574F
              92C1C896642A77AA4AE3AA6C6947009CF107DC800397023FE6469E64BD450006
              DC72A8A26782FF857126FB5DBE4BE7459F10FC36F40B48E9FE2E9504524C3B02
              10427CDB1592C020AEE449D8130412B5853B5B80F22F420D6EE1ECB81A11A4EC
              87962CC9F6B02EFE8224A21D01C426D8F54102907C71874062D5F0BFE080E2B5
              853B77BA944A0B76F4616FEA1B37CC115C78546A5AA631ED0860C33AEB49B700
              24CDDC896E7590BC3B0496A646E71B297B338FC5BEE14E93DFD2022F3DC2E2E4
              F0B97E7BD28D7DED08A09B209B65048B9DDF7C8C5EAB43C030ED9BFB44752BAC
              E4EFA3CEAAD79662EB21AEF18FA6ED03BCB62453BF9E042084CBE7AF890FC804
              9174B587C0D2A5D95E1824F839FFA3ED4968D7AA675E853D639823562BCF8376
              5C4B0210317663D080247F6646E02C33F7BEBE83FB76CCDC2A2C6745CE30EDDF
              E9108D96041013ACE416DC442AF7AF6E75907C7B08C067FD07628C7FBDBDD6A1
              69752890805811F08F04311DE12E3A991FBAF59B0B76A55B1D243F3B0230089E
              618245F6EECB71F848F0F1C191D7CE8E943F2DB424003950F123E5E8212DAD10
              80C15F81735A2D8A81BFD2CB44553C76F6807DBC74C51214EA4B00823DEA36FE
              152BB20BDCEA20F9E91180C18F8B7DFAF6AFE9C3EAFA6895B3EF19E648E02E15
              6A9B20CEAA9FEA3A1B5382E30BFAE8A6A2292C646E0CD3C6C12F5365487489F5
              09D3EE0F5230DA1240B130F49F1280FC90041DA4A20181200C7ECED8ADB0EE70
              B1E062598CC74E6642E0A02B809B7F84EA6B01DFD60469015A5B029095C5A0AF
              D2CA8A53859EC440EE791576F6B4C1B77226DE5D72ACDA2FF8161DEBB452C1FA
              6C399FB979437EF0CE522173159C33A11E0C958BCD63F3396777EFA9C7BB238D
              9AB9E05F4BA4EDD735C591E27100001000494441541EF36B5F6B028079A6BB67
              0402EAE313F06E015B2AEE108077FEC739E7F8DB78EE1475222DC456DE5BD9BB
              E4A417169D4CDB8F8B2B97B3DB8B79EB442403C6C4573B3129AB2DAFB047CE4C
              8D1E2C4B5FB77AB426002ED867BA0D7C975C60BE72BACB23ED7660F03BE0F4AB
              A0AA2B829F01EFEC0B8BC3ABB7B8315A72321F848F09FBBBD1D1AD6C5C549FEA
              5656969CD604502A58DF920184610EBF59869E28EA586EE50E83B807A02A2B15
              1E7B79A990BE4996C10DF9C1E74BF0F101F4C1A412FE2B2C409E7F57686E0F53
              5A1300462398D8895B7735E6DBE741777EFB2F5D99E04FA8F40207EA0DF9C1A7
              BDB009BA713C48E84FBB7B37CBABBD81047CF918827E61C0B8D5B8724B82F38B
              24E8889C0AE8B8CFA80C1A3EEB7BDE5F8104FCF8FDC853CE4A8DBE5E2596755B
              9E035A37E4D5B6EC586B65E84E0CD8B7CAD013151D530FCC5476975FBC527905
              63B0EAC3BCFF3B64D1D81CEFADEC6E2126AABFDCFD889A57DA13802C9838674B
              65E98A841ECEAF5617A7B8EBBAB5AB952D9865B3D90921584E5D7C9396920323
              774CEEA9FB1F0A02E08C4BF9624FD2B44F5607BDBE9660EAFF3395DE979CCCBB
              55DA435BE58235845BB7B51379C1C5498995C32FED44C66DDB5010C096A77F74
              915B20501E9680BF865BAAAD1158DE7FE5CBE1EC1BA1AA299C5FA5C6D09E56E0
              8DE5D23D8F7A7B84F7C6942EAA868200366EDC88DF3A9391999EE5039FFB0719
              8AC2AAA3128FBB7E266327D894F269BC8DB71311696D8B4EDAFD7D269D7B33DF
              30F3CA2E4B8782006A187391AC6D5DFEABF0B90FBB54115A71FC851E082E3C7D
              06820966A9287BD270689259CA675C3F2568AA33EC77FAB957A8BDA575CA70D0
              378255957EF68785B82FFB8D891B1FDCF8AE6A3D2A34048060C367F89FE3D66D
              9D3B6F0ECD029A409C22C5BD9A0E7BFA32C6C51A4F0DB4A1DC2F1FA02F2B598F
              0A1501547A849CD562C15E7A86955BD846FF884C93B973E7FCAFEA607BE2FC37
              AA6D36DBF3D1879E44363BAFD91FD9AF43450037DA99BFCA02A867824B994DC8
              F227007A5EA1DA876B47AC6755DB6CB6E7A70F7C739FE73F9A122A02C0E4C1A5
              1B592BB7872F5DB9AE0F7546BD2652C327451D834EE397D4FE5D92F4B454133A
              02804B37D2AEDDF6F56EDBD412B9289DA8C66EF6235CD537C54C17A3DF3E2407
              473CBDE72274043095C4DBA7B66E37FB9F19E0473ABB0DAE5D79CE992F574544
              2F53FB8C816900F1DB0751AD16A7714BDAA1501240C9B14E918550BC2A1E93A5
              4B473D0933B7C42FBFE32CA6F43903D3C5E9BF0FDCD39B8262D3051D8E6342DA
              0AB261DA117E7828BFC4AFFE0097C27CFF8256373EC8C66B85993F48B6CEBABE
              D012C0D8D6CA5BEA414AD86E94A0434B159CB1E3B5743C444E8F8BCA4AAFC209
              2D016CBCF6027CD4D28BB2804BA6EC75B274919EF61180D9D717DB6F2DB76562
              C0BE42AEC62EB571714E9792B38A85960030F2788FF847DCCAA842B09551BB39
              C8CFCFFF0D395BDEB0AF749773768152832D8DF1035B9E727922D404709D9DF9
              1D0CDCBFB9C4689778CF38F3FDC6945DCE28D88909EEFB67700C136601CA9F99
              6798B9CBD076A755B7F6A126805A3278FCF0DA56C63FCEE719293B2543950E3A
              6001ECBD01F1F314A3FF72CFDE05A78F914B79C6C4F4BA3B3FBAD2A39BD2424F
              006527B519E0FE2D543945B051398A34D0C2FDBF0EBF0BA578AFB4DBBC77E96C
              B103330E59CF976861A1F3C35BE76E7D67E752B34B849E001082B1A77F7C046E
              65D58469FBFE1B73B262D1498FA1E04747C1C6E38049E0C605AF722200484C57
              059F1804D3D9FBBA129E46082E8D1D9448D99E5D9A99C6241D9A420006E8C4D4
              AEF40DE87E1094767DF721C87A5762CC931BB202C774CCA3BFB2632D96A99A0B
              B66E59FF9ABD65EA245D6D211087812A96A646E7B7D5BACD46A013BFF721F3DE
              91362DB7D94CB0A3DB6CD951B3C810400D15C13E5DDB4AFAD71BDF89F71A48D2
              466A3A41A04F54B71A03C3762732D3B54DAC1A7E0D0C7E9820B243A63B1FF663
              91228052C1927E69073A8FD2C76485BD4376141F8FA5017F61A4468D8EE4A0B1
              D1BFE64090DDC463B15FC3CBC89648110066994F5464FF24F31B8D8191D35077
              986A7FFF9AB9DAC423AA4518CC2239603F01DB96370E19FDF651707E2354C1E2
              3BF1AA82B4777D6DB06A7234720450BC6A35ACE0F3879A7070F7928B2F27CCFC
              22774A8225FDA2D8B67FB03C9ADD1BC1D961D0EA8B065C2D98AEB238FB159C8F
              F017BB20FAA6123902C0F84B4EFA18DCCAAC9C55A4DD7128D3AF6E75F13973B6
              772B4B72FA20104902984ACFC7A7B6D236F0AEF38234653E2BDA901F0C15A1F9
              0C6760CD4796004A8E751D64E539A832CB5E8901FB273215FAA80B57C67D34AF
              8F699D3D8D2C0160D280040EC0ADCCCA393B0648E0933275922E420010A84295
              5E224D008826E742FA0A3E90C0E712A9E177A07EAA84800C04603AF617197A9A
              75449E008AF9CCAD4C88A79A8171FB9A8BD87DC901E708B77A489E1040043863
              D26E65477DF51A790240204A858C273F7A21F8C4A3CB267F4E1BCD500D2102CA
              42E2EC0E2F6C1101D4518DF163EBBB32B7BDF1F81F9666B3BD3275AAD205D3CE
              6DAA6C919D9911D85EDD71E7CC2DBA3B4B0430855B6934FD03D8BD07AAF4D2B7
              B96F8774A50A14C2B4D393771D05AE87CEC42D858B680DC0EBACC25581139860
              9EDC00639836BCA17A1D815CFD82F16FC8D548DA828600CD009A32522A5852BF
              66DAA81E4960C58A6BE6341E0BF27ED9497BFAAB349263C7CB64BF029DDF817A
              3D63FC0AC1D82AACB8CF1883630CCF611B6C0B87DC1585D29EF94B04304D162B
              E3FC88690E4B3934BE60CBCE44C8BE37200598769508F628137C60CEDC894530
              63E30D350EFB6F80FA1EA8899293FE64D9B1D662C5FDC963169EC336D876972C
              EA629C0D0AC1E43D3AAEDD78DA69C7F955ED34EBA60D11C034A8DDB02EFD6BB8
              969F9BE6949443F8BD813353A3B2BF9528C5B73D95F027F63CA6EE080CCABB63
              7176280CE0C9015BB08E2C15D26BAEBDF20269CF62405DA5BC952F17AC57D7ED
              5484C01FE50CC457BD454FC5B3DF27200268D1978B796B084EFD11AA27252EAA
              4F2506ECE03E81A61EB56017D777D56DC55777EC18DF0F07230CCA13378C584F
              AAB33D69E98642E6E760FF68A89C8BCAEB6041141F17367952F1FF726EE8CF5E
              99240298015948BEA7EFD230CB783099B2D333B8E0FB2978B7BD499113CFE2BB
              2E600EEFF4990FDEFC850B03F365A46261F56345C77A2BFA2662FC7D80C70EA8
              6A0A679E2C4AD79D2702A823D1628B496F714ACA6121986D98365E8294A2CF0B
              25E023ACA579A19931C1590E31867A20BEEB7A63459ED6F268FA9BE0EBBC523E
              1D835981E7BF1909D82F93E7FD9E9A8800F6C4648F23633BC7F6DAE3A0DC036F
              0312F0E43AAF0C3739AF9E27434F938E611848BC3CF951ABE994062F3917302B
              F830C600EC58F6CA6358C4BCCD2BDDA89708005198A56E5C9F1DABF28937CCD2
              CCEDE997000988D3CFBD625FB78A64CB979CA12FC8D3C9AFC1410375B53C9DFE
              6A82416A403C5C3611803ECF9F574804D066DFB93E7FC1AF84E01F6EB379D7CD
              E6CE9DF37C2298BF3920E561273B76ECBCB06B700222D8CA8D9D3BC6075B9DEB
              E6784CF49CD28D5C273244001DA0552EA437C2F5E2CF7620D25553782B5907B3
              8147BB12F64848B0385E1673AD1D09CEB592802A901D5BB1603EE675A844001D
              220CD78B2FE64C5CD9A15837CD8F0012108980DC34547652F8C319527E95C730
              6D2DBF1B31531265C704571BDE36933D59E78800BA40B2E8642E6082E5BB10ED
              5884B3CADFA0735DD3B1A02702D5B74A52DB0B3105E2261B19F1402C3F053D52
              BFF109571B7E043A3D2F44005D425C2A58834288F55D8A772AB6023A99583EE0
              FC43A78232DB979C21998F537FA361E61E96E99F0A5DCD368C01FB1770EC4D50
              A5959860527FC66E26C788006642679673E542062F8FE1C345676929E774854F
              FC3961DAFF25475B775A449C1DD99DE47452FC4820B6DF4C77468763E0FBAF61
              4D48EED52121B66F2858F7A98A9F08C025D270F9E7E38C09D7BF51D7AE1B9CB1
              0F42C713C955F671EDCAC86C571EB1607152C81CB4AF86780273D75FBB5881CF
              CF42DBD740955AE6CCABBC54AAC259941101CC02503BA74B4E26C3B9FC878BCE
              645BC4D8FDD0099FF3E3694310EF6B67F2AD8B738B2016B17465B6AF0B59A522
              F8252EF4158CEE0F5576F9167E3149B6D299F41101CC844E07E78AF870D10A7B
              7D0722329AEE874F1B4A98F64D329475A24308861F7F3A1199B56D5F6FDF96E4
              AADCA9B336F4A98191B23F855FE2F2CA7CC9B14EF24A772BBD4400AD90E9E278
              69ADF5705CF4289DC2A19BF0B16019BE2BC1A2DA65F85A452D172C5C00C569B0
              547322C66F8385B52D2B57AE0BCC6C60D7BBBE60974A0D76376571E93F57B79B
              FA162F88005A00D3EDE1EB0AE65FC4A231CF9E2A34B35FFCA229225072B71DBC
              631D38B33F5D9EE5AC6F5BEFB62DF08E7B7B971AA4890119FDC2CB777D745430
              7163C949C9BCC2826ADBAA44006DC1D459A37236BB1D0607BC31B3E73B9394D5
              9A5F8E449018B03D7B9044DDD3788F38BCBE2F7D2BD8FB310E1884F767B35965
              7DF5CCF32EDF1FC86713DA96BECADF049260EC85B29339B3E9B0B297CA405516
              51800C0109E042D12D7EB9C439BB003B71D21CF9FED2AC378F26BFCECEFC0EE2
              2B40F5AE7076DC939BFB2A10CB843130728E478678C2CCE5C18688CFE97D9609
              7648A31DAFF6CB8EB58F57BADBD14B04D00E4A2EDA00099C1EABF2135DA8702D
              0A53CC6371B1103AF7D859660E1F68E15A67A30288D1648C6F62DEFFC5191757
              431C026B722077879B9F603BCBB471EDE417A80B6A95330E71781F44DD029FA8
              78FAC099BA9D99B6440033A123E9DC8635E9BB277A441016B516C618FF3A7476
              01570E7E7956FFF0AB2485C84A4EFA30D0F522546545707E1217B1FB309E69EA
              7688F18F8639F257C3B471F650230DD8DFB58D3186574FE4DEC8D366F4551E7B
              43F1AAD59E3D72AE4D371860D06E536AE706811BEDCC8BF04EC941C70FA1FA5E
              C091D7C7E2B1C7619D40DA730921BE20905C1DDBB910E3418C8903E140A0FAB9
              E0E294EBF383F8787270CDDF122860FC85428D7518246FC767DFA9B136BB1558
              277870F656EDB780F860DCB5DF5E8796327D148CA7CBF98CEF5737EA311101D4
              9150B8C567DF4D0D94C7159A6D692A618EE45B9EECE2C4546C5D48865B04DEF9
              97959DF46890A22402F0311B30505E53AD54DFEBA30B35D39C093321F9B90310
              1BCE0494AE09D48209E83FC163FF04EFFC3707CD3D22009F3372FDDAA16F4F0D
              967BFC7485B38AF42FE4405CB826A0E2EA809FD0CD6A7B9CC55F56CE0FE2D786
              676DABBA0111806AC45BD883C17202EFADEC0DA7B740F5A518A67DAF6CC31017
              5E1DF0F4C9B6B27D6ED4E7761FAFFEDCE4A4FEE4568F57F244005E21DB85DEE2
              F0EA2D30608004C4095D88CB10599234ED9365286AD40131FD7B95557DF9FA72
              A31F8AF71F83B8395EFD516CB7237344001DC1A5A671C9C9DC53722C0E2BC659
              3516FFDF8A60EC9BC9A12BA5FF0EC2F5CED003634FFFB8072C55A186BA08CE4C
              C8DFEB7408920820C0598215E34BA023292702B1332EE511E0CDD06EDCB8B102
              F1C4E1F8AD50C35704AB6C8FB303CB79CBDB5BA32522470420114CAF54F94104
              C994EDD9179980044EDB59E9DD87096F7FF7CE6D3E5978F1D400000327494441
              543A91AFBDEB17AC9E5B462CE95F91EEC48F4EDB1201748A988FEDEB44C08558
              EEB51B42B07D8D01DBB3BBD5BEB476D50BA582359FB1EA4AAF63F156BF780408
              0D7FE24C9B77FD463C88001AD1D064BF58C86CC04EC72ABD2F0197653E9F0FD4
              3514CE8E4A9A239F6F38227DB7E40C7D0163E18C5F225DB9970A057B748CC716
              949CCC515E9AF15A371180D7087BA8BFB476D53325C77A2D549814304F06AA60
              62B531307ABE8761D454179D7416E3605CF4D70E04F59F603F403F61F672E4C6
              FCE0B6A0BAD9AE5F4400ED2215F076E582752176CCF93BE7EFC53897FCE8F0EA
              2255E197F299AB308E39D59E43608DE0A7AAEC36DB697ABD031FFA8A7EC1C03F
              B6E99CD62F8900B44EDF9ECEAF5F7FDE58299FFE37ECAC95F17907408BBBA076
              5E38FB3B089D8E7AA0D32B7BD620D8AC956BD798BF07BB6F46FB8CC5F1BE8827
              6A27D4FDDBC919FF0CDA873AAFF6D05775B6955922025006B57A4337AC3BFF39
              E8BCEF86CA0F5934360756AA2F022F669AB6DE8EDF54C4F6A5BCB508B6B7407B
              DF4BC949E17D11AF027F385670E81C981DFC19B6728B6079C1E2FBA20DA8738B
              4EFA52B90682A78D08207839F1C4A36C363B01D7A72F878E0D0B5716C7054421
              F80620851C1CAB0D2CD89E82DF54F4C401894AC1CF6B617670106CEB7E730103
              9709FE1130B31AD62D1CD87E453086BFB0038BA4E227F0FA6B8CF16B04E359C6
              D83971163FAA51BEB65FB006CB4E6A339C8F4C894526520A7437047001B15C48
              2F075218DAED84A62F70E0960AE9AFC0401E2E3B99146C3F5276ACC5B08545D2
              CC5B60FB819293FEC4D4A5D46BAF73528FB40A354AC78900A2946D8A95106842
              8008A009107A4908440901228028659B6225049A1020026802845E461B81A845
              4F0410B58C53BC8440030244000D60D02E211035048800A296718A9710684080
              08A0010CDA8D3602518C9E08208A59A798098129048800A680A00D2110450488
              00A298758A991098428008600A08DA441B81A8464F0410D5CC53DC8400204004
              0020502104A28A00114054334F71130280001100804025DA0844397A22802867
              9F628F3C02440091EF020440941120028872F629F6C823400410F92E106D00A2
              1EFDFF010000FFFF0302791600000006494441540300601140970EB21CC80000
              000049454E44AE426082}
          end>
      end
      item
        Name = 'Fertilise'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC5D0B94245579BE7FCFEC02CB2EAC10250A82A028
              288948A239C74788AF784CA21C8DF864A16B167605DDEDEA9D9E5D054CC6072C
              BBDD33DD330B0A7B96E9E12C4864833127C4937812E4A89144932051D720282F
              11243C1676D8859D99BEF9FF7E8C3D3D5DDDF5B8B7EA56D5DFA76E57D5AD7BFF
              C7F7FFF7EB7A7746F087116004528B0013406A43CF8E33024230017016300229
              46800920C5C167D7D38D0079CF044028706104528A0013404A03CF6E33028400
              1300A1C085114829024C00290D3CBB9D6E045ADE3301B490E039239042049800
              5218747699116821C004D04282E78C400A1160024861D0D9E57423D0EE3D1340
              3B1ABCCC08A40C01268094059CDD6504DA1160026847839719819421C00490B2
              80B3BBE946A0D37B26804E44789D114811024C00290A36BBCA087422C004D089
              08AF3302294280092045C16657D38D4037EF9900BAA1C2758C404A1060024849
              A0BBB939B479DBAA4B2EB96665B76D5C970E049800D211E7AE5ECA4303CF1E5C
              7E707FD78D5C990A0498005211E6A54E5A7649B66ADB975B753C4F16024EDE30
              01382193E07A1CF0339DEE61DD139D75BC9E7C049800921FE3451EE2407F002B
              8EC4D2391D6BD9C5BD9D95BC9E6C04B410403E3F7E44B2618BA77738C0EF40CB
              4FC2E230C1E94810D7396CE4EA081158B76E74850EF55A08609FACEDB57263E7
              E9309865FA43C0CA6D2F0901678BFE9F7559BBB4A17F336E11160243B9EDE7CF
              AE58F953BFFA7AF5D3420075852077E3AFC9FFD497F92B52042EC817D70AC80C
              BB35028498CCDADBCF74DB9EDBE94300C7D04F24646ED0A5411F01342CFE3D74
              409ECB87040D3422F8CE6EDC7E6A46C22EAFAA4164EEBA3077C571823F9120B0
              A6503C92C60E2A7F1D166D936E02A81BBE52D60E6437163F5E5FE1AFD01018DA
              BC6D1564323FF7AB701E0E7BCC6F5FEEE71F81A15C71EDE01C2CB952E35FA273
              CF500880D443066EB2F2A51FD132977010A01B7D826A6AFE0A0515C3FD5D2280
              276AFF5782F73D3627F1FDEA432380BA2152BC9E122A3B3A7A787D9DBFB42130
              6497665509C79382BF56258BE5744780F6D6686C0801AF11217EC22580A663B0
              6FE5C1B5F9E2479BAB3C538C8065977E2585185425164F0ABE1465FEBD2A792C
              673102D98DA54FAAD85B5B2CD5DD5AC65D33F5AD6A126EC6A4BA4BBDE4744BCC
              DA63FF8C081C8F45F5F47E2B57DCA85A68DAE5E118F83964C457A2C221320268
              3A7C260220B3A3553E246802126466D9639781907F1A4446CFBE00136BF3E3AF
              EAD98637BA4260DDBAAB8EB61ACF639CEAAA838F466EBA444D00751B61DF9307
              ADDCD847EA2BFCE50B810B73C5DF17427EC957670F9D6AB276EF860D938779E8
              C24D3B1018B2C73E35BB62705F477524AB461040DD73907F63E54AFF5D5FE62F
              4F08D033FDF300777BEA14A0F1CCC0A1E703744F7557CCF1FBA490579B028239
              044088807803ED16F18D430486FB12C533FD43F9D253EE2DE4961FBF78EB8B28
              B70588579A84865904D044866E1C1ACA173FDC5CE5590F0430A99EEDB159DB26
              290525F40FB4294890E06CBE943BECB065A112A65BF88C2400325E4AF89A6517
              FF8B96B9744700073FDD58B5AAFBD6506ADF88366C0E45534C956473A55F8214
              1561E8C7580268E005676182F1B3040D30167D67EDE217B0E2F558A29EB6ADE5
              2B034B6270FEA7AE3C967217409CBC64A3411586134003293A24B8800F091A60
              E0B76597CF02019FC3452326BA3270EEB9B70C18618C01465C902B0D0F2C5B1E
              8B372CC5820028A699FA2141E93F6939CD259BA5DBA8E78D3B345A79FC437369
              8E4BCB77CB1EBB3F03A2D45A8F62EE45676C08A0E9D41F587629D58704B07AE5
              C12616C6CD3036BF32CEA8900CB2365CF962F45F0A215F11924A256AE2460075
              A7E99020BB69ECDCFA4A8ABE30C1540FB03B113E2A3853321D8F364E2B911423
              21D95C718B1858FE788C4C5E3035960440D6434DDE92B5D3734830942BD1FDE2
              2AEFF17FAE5A29BC990AE2F91C1655D30518970FAA1266BA1CCB1E7B1000AE32
              DD4E27FB624B00E41008918A43023CE3FF2712C427C967550507FEC23F02B52F
              AB908F71B9754DA1F81215B24C957161AE729C8587A3B8CB7FA249367AB525D6
              04D072B67E48904BE621013D270E02BEDDF255C5FC8517668FE994D3ADAEB38D
              97F5C139F88D97F6716A3B942F5D3A0F738FC5C966275B134100E41C80BCC5B2
              C77E48CB492AAA9F13AF09F9175FFDCA679FEEC488EA685B677D9075CB2E19F1
              C04B101F3AFBA24F0F4B29AEE8AC8FEB7A6208A01100F98718A0C45C25405F1E
              6AF8A5E65B0A317D4365E41F9DA4D1366AE3B4DD47FDD1965DDCE3A39F715DCE
              B3CBF4521484479C609C71010C4A1801349048C22181952F7D11BD7939162513
              66EEA3D39582D54F18B5A1B6FDDAB9DF0E1F5ABB71EC9DEEDB9BD732BBB1F8D7
              CBC4BCF1AF45F3835C22098080681C1214637948B0E6D3C593851497931FAA0A
              0EEC97B995E5A5AD1B99B58CFC97B83EE169E54A8F400646DDF819C736892580
              4630209687048383F0CB86FD6ABE971D36B7DAAB2429065EE4B54FAFF6B457D6
              6BBB69DBCECF8FD33D0D5280704D9CA6F9E0C69E84134003024ABE6C6E7B2C6E
              1CC2E3FEFD0DABD57C4B21FE72E7B6CF3CE355DA7425BF4FCA9AD247B22D7BEC
              175EED88A23D5E76FDC280ACA9BEE92A0A57FAEA4C0501100A0019BC4A60F621
              01EE6ED29B775792BD4A8A94DFC4DDF9AFFB95353DB1798F14F02DBFFD97F693
              A7E025B4CF2CAD37A766C82EFD1A0C7AD0CA2D327EDBA586001A00350E09D6AD
              1B5DD15837E7DBCA15FF488078BF428BF6572746FE3CA8BCE9CAF07B5086B23B
              05F112DAD68F0D977E07651A35599BC65E6ED925344FBCD428C3341B93320268
              A039BB62E57318EC0F35D60CF906F8779596542B85A354C94359EAF64AD0A8C3
              E7C5FFE1CC98C9B2C7AE1435A9F492AB31CEF531C4500280037DEC56B1798F65
              978C78A515DAA1F47FE006E6E7955D3E6C019D19104A9F72C35DED7B84011FCB
              1E7B4C08F959FDA68492D39EDD309200A43844FF88AAED2F91DB50A2575AC928
              0F09B276A98AF61C8945D1242FDDB5638BF21358D78F151EC481A2EC0E3829C4
              AB87E86FCB1579ED55CCDAE1D24916EEF2A34F61FC03F20DCD9CF66AA6ABF641
              1A194900E410EE7666C5BC2022A055AD25AA438235F6B6D34188AC50F7F945B5
              32B2559DB8C59250F6E5424A6537C44809BBD6148A0AC96FB1BD4E6B965D2CD6
              E6C503228C0FE670B552501963A5561B4B00E4657547612F8287634428DD4526
              D95DCA1E3C0B1FEA21C1A018D8DBC50EDF5588D5AB7C7776D9114F2C1EEFB2A9
              AB66837310466C176CC15F7D3CFF0085850A7D0B33180FA01CD6A722B864A309
              A0E51E02496FBEDDD95AD7360711DA210126A2D277C6CD4026B42B1B73CF4BA5
              BBCD48BCB76B8B6953F079976C7D15628E471E228C2B103B9B39DBD46EEE2C16
              0440F021A0EB656DD9AB695977D17D4890B58BF442CF6355F901507BCF9EF2A6
              D05E15B6FBDA91C7F192E52655F6A3ACB75F901FD776B867E5C726962D5F76AF
              327B7B08A21CA55CEDD144E9A6A0C2624300E4E8F464EE5E041730613CDFD946
              FD3D963D59BBF41F1EFBF46D9EB5CBABD1812FF46DE8B601C86F4E95372BBC59
              C79DE26AB9509652DCEFAE75FF561959FB49FF56DE5B5876E9493C6FB1D17B4F
              8F3D403C43B94939EAB167A4CD6345002DA430F956E3BEDC35AD755D7310E24D
              98404AAF1280985FF22CBE7FFB61BE5A0E7EB38F5FFDD3138553FCF6EDD60FB1
              5676622EFBE9D269280FD3442C79F94937DD41EA50C935D572C1F3F3164174AA
              EA1B4B0220E7A72B854FD7E66BDA4F7A912E55870498904A7FA9971D587904D9
              17659915032A1F9639299B2F7E34A83F43F9D2576050FC2CA81C37FD29072917
              DDB435B14D6C0980C0BC61C766BCEC5500DC1555F8AB4A92BB96408704E7D7FF
              BE5BBCBBAB641F9550931FDCB973FDAC8FAE4ABBDC58C93F8AF85FA94A2848B8
              39882CCB2E3D8DF6287D7F62377B50C7D3B4CB4F39D86D7B18752A74C49A005A
              00E0AEE8315240A5B5AE6B0E0B8704D7793EE33E0070B732BBA4B86B6A72E4EF
              94C90B2808F1BF0C8FB39F0C2866A13B0EE26717565C2EACDD583C03FB496CAE
              7D575C62AEA1CFDA0F2DD017ED53220880509AAE0CE7E7E6A4D2635292DBADCC
              AED8EFE959023CEBFF6037397EEBAA1385B3FCF6D5D5AF3A31A2F2F2DA2ACB2E
              5EE6D6562B5F9AAA65E0C76EDB0769473946B9164486497D13430004EAEEAB47
              EEA7DD3295BF4624D7A1B83A2418B24BEF0501273AC8F05CEDE7E51E9E95F8EC
              001938D367D72EDDE04BE7BAF8BF41FCD57F4648D1F755675D1478AB92F249CA
              2DCA316F1DCD6E9D280268414DBF4600A2D85AD7350717870452886FAAD22F05
              8CFA79B9872AFDFDE44C8D0FDF8DC7C6FFDAAF9DDBED2B8F7FC8F131E4ACBDFD
              4C1CFC1265297BEA1165759D289728A7BA6E8CA85295DA4412008133552E6C9E
              AB0D9E44CBBA0B1D12747BE390557FD24C99F67DB8EBF97965D23409C263E377
              29147D58D62E2EB967C2CA156F0291B94B84F0A11CA25C0A4155242A124B0084
              E6EE49FB21DA6DC3E5C7B1689D80DE38942B2E3C4B30941FFF8010EA6E99453F
              94BEA34F271852E1FB04A1F1761E68D96BD9A5FD02E0E3AD758DF3C71173A01C
              D2A82372D189268016BA18C8E370306A7B4AAEA50713F38D98A072DDE8752BA4
              ACF97E15D782BCD68284F7B516E3309FAEE4F7E17139DDEEACC4DC6CAE348FA5
              8E2D0A54FA721294D765925B1B39D36553C2AA52410014B36A65E4521D2FCA20
              D99D6576DF7EC763D7CEB62ED67F599D18BECD453BA39A54270A5F4283F66309
              3CE1313800881F0416E44200E508E58A8BA6913551A938350440A0D18B32AA95
              02E0AFD363B41E8782F6BE320E7676B3B15A1E3EBA5BBD9175523C865803E588
              91F669322A5504D0C2107F9D5E8A2C60FC09353CA3FEA696CDB19C034809C216
              867F281728270C37538B79A924004272AA3232AAF83E7612ABB2FC08CFA8C7F2
              9F8DDA41982E172670FD292C464E9403940B461A178251A92500C296EE63A7DD
              3E5C7E048B5113DAF506A30C0A600CFAA2ECDD0701CCE8ECFA08DA0594039D1B
              4C5E576D5BAA09A0052626C209789540E97FF1B564FB99CF89F9D7FAE967769F
              DA45E6D8272F6FC4DC1C8BA2B28409A0897CB5327285EA575D35457B9B81B86B
              77654B288FB27A332C58EB6A65F32E94A0F4356828CFF34431A6587BEE98D00E
              4C006D81A5575D55E92A81100FB75587BA582D9BF7A08F2A0010DB17AB92E543
              CEC3A81F28C63EFA26B60B134097D062A29C28048C88B03F35784BD82AC3D717
              C5A1008C34621ABEB72A35EA90C504E0806AB5325CCA4026C49357F0407572F8
              FB0EE624A63AEC43018A21C53231002A768409A007A0D797373D85BF1C80D7B2
              95BDFCD2491D26E9C94EDB92568F986A3F14A098A11EA018260D3F95FE3001B8
              4013AF659F22A4CCB968EAAB0964C0AC3F2AF5E585C74E20D4BD56BC5335C6AA
              1EB3CE7A5E5F820013C01248BA575427462635BD8CE389A9F1E15BBB6B4D6E2D
              9EEC2CA377CAFFCB806244B142D9899A7439C304E001597A1907ED566297FBB0
              2899509EF6DD6125866A10B26CF52A95AF11BB0FB1048A910653132B9209C047
              6831D14EC563CC8B7D74EDE802977654A46A75E7E8FA0320C48EA04E532C2826
              41E5A4B13F1380CFA8DFA700890000100049444154E331E6B5338766E83F0B7D
              4A10B378E24FFF3B0AFC5A1752BFA94A21D0BFF6500C281621999B38354C0001
              42BAE7CBA3F57F801542DEE355CCA1F91995BBBF5ED51BD51E96CF1FEFDD2079
              0FFEEA03C5C07BDF78F5D0692D13800274AB9591D304C821B7A2A4945FBD69C7
              A8E777DFBB951FB77653DBB7FC1A04FC9B6BBB11EB3AE6AE3B7043270498009C
              90F1585F2D8F546720E3EA0F43A627463EE1517CE29B4F5586DFEAC649C298B0
              76D396DBF4478009A03F46AE5BEC296F3A586D3C4BF053A74E528A78BFE4C3C9
              3105F50099F7F410F353C29630EED1863779448009C023606E9A63A29E216BB2
              DBAFFC23D31385D8BFE4C30D067EDA4C95377D0BFB3D8E65D1445812A68B2A53
              B2A2DB4D26004D084F4F8E7C75D98155CBDBC563129FD0BECECB4B119879E4C4
              97B5D7128684657B1D2FAB438009401D964B24EDDCB91E2FF5154048719714F2
              8B4B1A70C51204F6ECF9F0BC1070056186840984A1E08F36049800B441FB5BC1
              D589C259D39591BFFA6D0D2FF542A05A19BE9C30EBD586B7A9418009400D8E2C
              8511508E4018029900C240997530028622C004606860D82C46200C049800C240
              997530028622C004606860D8AC74231096F74C006121CD7A1801031160023030
              286C12231016024C006121CD7A1801031160023030286C52BA1108D37B268030
              D1665D8C8061083001181610368711081301268030D1665D8C80610830011816
              103627DD0884ED3D1340D888B33E46C0200498000C0A069BC208848D001340D8
              88B33E46C0200498000C0A069B926E04A2F09E09200AD45927236008024C0086
              0482CD6004A2408009200AD45927236008024C00860482CD4837025179CF0410
              15F2AC971130000126000382C02630025121C0041015F2AC9711300001260003
              82C026A41B8128BD670288127DD6CD08448C001340C40160F58C409408300144
              893EEB66042246800920E200B0FA742310B5F79A08000E06716C501C7E84E00F
              239020040603E774B031251C3E7A0840CAA71DF4B9AAAED5E68F75D5901B3102
              314120704E071C534E30E921800C3CE5A4D04DBD149209C00D50DC26360804CE
              E98063CA09282D040041D96A401CE36430D73302B144A04B4E7BF123F0987250
              A685006450029019DE0370081857C7148180391D784C39C0A687002013EC1040
              F2218043BCB83AA608E0000EF4A326038E2927D8B41000C85AA09380007C08E0
              1430AE8F270241733AE89872424D0F0164C4634E0ADDD5C36BDCB5E3568C405C
              10589CD35EAD86C063AABB462D04509B97777557E7B216E4992E5B723346201E
              0804CCE9C063CA01252D04303DB9F95E077DEEAAA538DA5D436EC508C4048180
              391D784C39C0A485001C74713523C008188600138061016173928F80491E3201
              98140DB685110819012680900167758C804908E82300299F0FE2A8B561FBD941
              FA735F46C0140402E772C0B1D40B077D0490117FDB4B71DF6D03F0B1BE6DB801
              23100704DA72D997B941C7520FA5FA0800325FEBA1D7C5262600172071935820
              103097038F256790B41140757CF83667B5AEB61CE5AA15376204CC4720502E2B
              184B8E08692300478DBC811160048C41C0680258B7EEBA65C620C58630023E10
              68CF611FDDB577D14B00209E09E2C1EC91CFAE0FD29FFB32025123103887038E
              A17EFE6B2500591337F733A0E7F61A5CD6733B6F64044C4720600E071E437DF0
              D14A00F372706B1FFDBD3783F8DDDE0D782B23603802017338F018EA038F5602
              D83D693FD4473F6F66045281805F27758F21AD04E0D7E9F67E965DE21B82DA01
              E1E5D8201087DC0D8300FE2158C4E4E782F5E7DE8C40540804CEDD8063A7BFDF
              FA09A00657F537A3570B38BDD756DEC608988B40C0DC0D3C76FA23A39D00AA93
              C3DFEF6F46EF166BF3E3FC3F01BD21E2AD8621D09EB37E4D533176FAE9D64E00
              FD0C70B3BD26E5949B76DC8611300581B8E46C28042085B8295860E439C1FA73
              6F46206C0482E56CF031E3CEDF500820F3ECFCC5EECC716E756E7E9CFF31D819
              1EDE6210022A7255C59871034928043035B565BF1B637AB53952C81DBDB6F336
              46C01404DA73D5AF4D2AC68C1BDDA11040C310797B63EEEF1BA45CEBAF27F762
              04C2452078AE061B2B5EBC0D8D00E6E6C4855E0CEBD6F682FCF8EBBAD5731D23
              600A022A7254C558718B476804B0FBEA91FBDD1AE5D42E236BDF71DAC6F58C80
              0908A8C8511563C52D16A11140D3A03B9B73BF33BE1FC02F72DC2F2C041672D4
              A7C2A063C493DA5009408A813FF3645D97C6566EECEB5DAAB98A11881C0115B9
              A9628C780122540298AEE4F77931AE6B5B901FE85ACF958C40D40828C84D2563
              C4030EA11240DD2E109BEAF3005F56AE940FD09DBB3202CA115092930AC68657
              C74227806AB950F66AE492F620C697D47105231025021D39E9C7142563C3A3E2
              D009A069DF7DCDB9EF593657BAC47767EEC808284440512E061E137E5C8A8400
              3203E25D7E8C6DEF0320AE695FE76546202A0454E4A28A31E1C7FF4808E0FAB1
              C2837E8CEDEC33942BF2DD819DA0F07AA808A8CA415563C2ABF3911000190935
              7807CD831409B02B487FEECB080445A05B0E7A95A9622C78D5D96A1F19014C4D
              0E7FBB654490F9903D16F08D4341B473DF3423A02AF7548D053FB1888C009AC6
              5ED49CFB9E4921B7F8EECC1D1981000828CABDC06320800B225202A8560A4A76
              E1AD5CF1E12020705F46C02B02AA724ED518F06A7FAB7DA404D0300282FD7908
              090138618DBD8D5F1E4A5870D18E403DD730E7BA29F256A720F7BD295CD23A72
              02A856862F5D62958F8A4131B0D74737EEC20878464055AEA9CA7DCF0EB47588
              9C00C816106223CD8316CB1EBB36A80CEECF08F44240558EA9CAF95EB6BAD966
              04014C550A8A5EF725D77F62C3B613DC38CE6D1801AF0834724B2AF9C76A7539
              EFD58BC5ED8D200032096AE26D340F5A960F0CF009C1A02072FFAE08F4CBADAE
              9DBA54AACAF52EA23D57194300539385EFA1F52F60093C59B9D28F030B61018C
              401B020A73EA8566AEB7498F6ED11802200866C5C0C9340F5C409C91CD95DE1D
              580E0B600410817A2E614EE162E049598E07B6A421C02802B8B1927F5408794F
              C3B460DF00E25B2801CFB5E0374F8C807F04001AB9E45FC2424F794F23C7172A
              225F308A00088D6A65E4349AAB28965DAAA990C332D28B80DB1C728390CADC76
              A3CF4D1BE308A069B4B2DB2331800F3465F28C11F08480E2DC5196D39E9CE8D3
              D84802A8D66F1186037D6C77BBF9240C64C56D636EC7081002CD9C3989968317
              38D0C8E9E092544B309200C8C99943FB8FA3B9A292CBE6C7955C6654640F8B31
              188166AEE45499A8389755995597632C01ECF9F2E88C007143DD4A055F206BDF
              39FF53571FAB40148B4830029423942B5E5CECD91673B89ECB3D1B45B7D15802
              2048AAE54216E7CA4EE40D2C7BFE896C76F47094C91323B00401CA0DCA91251B
              FC57D49A39EC5F82E69E461300F93EB37AE6089AAB2AB07AE54155B2584EB210
              509D1BAA735707DAC613C09ED1D1437831FF3C95CEE3091EA9521ECB8A3F02AA
              7382729672D774648C27000270AA52B809E74A6E104239F54975C0EB42F92B96
              0804C9050787EF69E6ACC36673AA6341000457B55250768310C9A3A221F02496
              4B8C10D091033A725517A4B1210002606E50AABC344822858E04A80BE62FE311
              D0117B1D39AA13C85811C0EED2C8E390810FA906444722A8B691E5A9454047CC
              29372947D55AAA575AAC0880A0981A1FBE5500DC48CB2A0B25C4BA75D72D5329
              9365998700C59862ADC2B245323027EBB9B9A8D2FC95D81100415A2D0FAFC1D3
              F88FD2B2CA32BB62FFA1B5F9F16354CA6459E62040B1A518ABB68872917252B5
              DC30E4C592000898E94AE16534575D6AB2F664F35650D5A2595E8408504C29B6
              3A4CD0958B3A6CED94195B022047961D58B59CE6AA0BDD0A8ABB89FC00916A60
              239247B1A498EA50AF2B0775D8DA4D66AC0960E7CEF5B3CF0F881777734C415D
              0E13871F2556006494229A3154F6604FCB179A53EE510ED2725C4BAC098040BF
              79ACF0446656BC42E8F99C840984877802F48867A91A118066EC143DD2BBD852
              CA39CABDC5B5F15B8B3D0110E4D75F537850CC8BD7D1B28E828954ABBF174E87
              7096A91C018A15C54CB9E09640CCB57ACEB5D6633C4F040110FED51D85BD528A
              37D1B28E42EF8553F866581D26B24C44806244B1C2452D13E518E59A16E11108
              4D0C011076D313851F4A21DF4ECB5A0A8833F0974536FE20428B0616EA13018A
              09C5060FD6CEF029A26F37CA2DCAB1BE0D63D420510440B84F5746EE800C9C49
              CBBA0AFD4184C57F43A60B5ECF7229161413CF1D3D74A09CA2DCF2D025164D13
              470084FAD4F8F0DD73B5412D277F487EA3C8F5965D926BEC6DA737D6F93B6C04
              087B8A811052C9DF7539D94FB94439E5B43DCEF58924000AC8EE49FBA1301ECC
              1814037BAD5CF161D2C9253C040873C25EB746CA21CA25DD7AA2929F58022040
              E9C10C29065E44CB5A0BC009F44B34648F5DA5550F0B178431612D1073DD7050
              EE500EB5EB49DA72A2098082355DC9EF0BEB6E2D3C49B485927328575C4BBAB9
              A8438030256C096375529D2551CE50EE38B748C696C413008589EED6AA560A20
              8550FE0011C9EF2C126017252B5E8FBEA4731BAF7B438030242C09536F3DFDB5
              A61CA15CA19CF127215EBD524100AD904CD30344A0FE51E296FCCE395E8FBE86
              92D7CA95F29DDB78BD37028419614718F66EA9702BE6463D47148A345D54AA08
              8082418F6DE2251DE52F1521D98E05C43825B3951BFBBA631BDE5047803022AC
              046256AF08E98B728272A397BA246E4B1D015010F192CEAD74769796432D203F
              40C98DE5C90BF2E3DA6E5D0ED52705CA080BC2048B14889102919E44502E504E
              78EA9490C6A924008A1D9DDDA5633D5C56FAB66194E7663A26236B3FA184CFE6
              C7769D9B1F3FC24DA724B5219FC977C280B040DFA27811CB3D9403940BA83F95
              536A09A0156D4C80D34008A5FF3BD092ED660E52AE5D296B07682058F6D837D6
              26F88D44E41BF968D925493E93EF6E30D2D186624EB1D7213B4E32534F0014AC
              A94AE1A699D53387E1720D4B84933C87DE5A4303C4CA957E66E58A9111932A10
              C887BA2F38E8C93721E439AA64FB9453A35853CCBDF44F6A5B26806664F78C8E
              1EC25F84013CF97443B32ADA1988D304C0EE3A19E0E0C1F96FB2766903BDD432
              5AC39CB5936D6423D98A4552211F04F9E2DC2DBC2D206EA01853ACC3536AB626
              26808EF8D09F39CE1C9A5925041C10667D5E82BBAD93F4524B1A58CDF28C6517
              AFB5366C3F3B6C5349675DB75D421B4AF5C14EB6918D68CB4BB01834C1018A29
              C5D620A38C308509A04B18E8EF9CAB95E12371D345584C9E8E1202D68B81CC1D
              4D42A80FC485E57C699F658FD1B6EBB2B9D2565C2E58F9A2656D2C9E33B4B1F4
              D60BEDF2E95468D9C2BAFA367BACD0685BBA0EDBDF61D5653406B8D5D813A9EB
              209D75DD42A00DC2E4CF45144B8AA9C94646651B13400FE47177711716FC5193
              515C29E86199CB4D521C8DC7DCB477B00E407C06978B42C294C8C03764467C77
              5ECCEFA542CB5457DF2664B1D156ACC3F6678BBA0C97FA8C6A26EB67F8317EBB
              829A95E4FE4C002EA25BAD8C9C362B06E835E42FB868CE4DA245E0058A15C52C
              5A33E2A19D09C0659C6EACE41FAD560A87434DBCCD65176E163202141B8A11C5
              2A64D5B155C704E03174539385EF6192E15EB2D8E855BB3A9200000326494441
              54B12B37D784001EA36DA498506C34A948AC5826009FA1C5EBC83B28E98480AD
              823F1121005B2906140B5D06245D2E1340C008E319E64B2909518CE9570CD0C4
              C44C7866BF00847D623C8AC811260045C02309D4AF18400DDEA148248BE94080
              B0459C71E01776756CE2559F083001F804CEA9DBD4E4F0B72949330382FEADE8
              3EC19FA008DC475812A6846D5061DC7F31024C008BF150B676FD58E1414CDA53
              B18000B14999E0B40842CC083B2CA7129651B89D069D4C002144B95A2E943191
              41365E507A67082AE3AAE24EC288B022CCE2EA449CEC660208315AF492494CEE
              376381B939798A10F2F610D51BAA4ADE4E58102658DE4C18196A6822CD620288
              28ACBBAF1EB9BF5A197967B552007876FE2829C44D119912BA5AF2957CAEA2EF
              55C480B008DD085658478009A00E43B45F53535BF64F570AE755EB03A200126A
              7F8C5FFF14AD55EAB4932FE453CB3FF2957C56A741BDA4B44864023030D2D3E5
              CDDF9D9A187E6F6BC0E071F1C9528A6BF164E233069ABBD82410CF90AD6473CB
              7EF2857C5ADC90D74C408009C08428F4B161BA927F607AA270319E185BDD1A54
              341719789F0079A390F2F93E22D46F269DA41B6D205B164AB9B09A6C259BD52B
              6589AA116002508D6888F2AAE3C3B755CB236BAA1323472C0CC0E66104ADCB5A
              EDD500F223481039296014E79320C46E01709B90E2FB42C0CFEA8596B1AEBE4D
              CA49D9689BA3BE2483642D29A49374A30D823FB145800920B6A1EB6FF8F4E4E6
              7BA7CA23B720414C4E57863F8FF3DC54A5707EB53CFCBEEA44E12DD5CAF06BEB
              8596B1AEBE6D6224D76C3B497D49467F4DC96A91266F9800D2146DF69511E840
              8009A003105E6504D2840013409AA2CDBE32021D0830017400C2ABE946206DDE
              3301A42DE2EC2F23D0860013401B18BCC808A40D012680B4459CFD6504DA1060
              0268038317D38D401ABD67024863D4D96746A08900134013089E310269448009
              208D51679F198126024C004D2078966E04D2EA3D13405A23CF7E330288001300
              82C013239056049800D21A79F69B114004980010049ED28D409ABD67024873F4
              D9F7D423C00490FA146000D28C0013409AA3CFBEA71E012680D4A740BA0148BB
              F7FF0F0000FFFF9A94CA0F00000006494441540300665AF688688125FE000000
              0049454E44AE426082}
          end>
      end
      item
        Name = 'Water'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC5D6B945B57753E471A8F814C8C79A42CD23C782D
              5248C3020A94A4346441812E206D1734401362EB8E13929078A4B1241BAF5218
              166D882DC9A3B1C110C7192935C5C0B09A1F8496B6C98290F22AD0F02694D296
              04A79486C4214EE2C78C0E7B4B776C8DACC7BDF7EC735F67CFBA6774EFB97B7F
              67EF6FEFFB49A3D76404FF3003CC80B50CB000585B7A4E9C1910820580BB8019
              B0980116008B8BCFA9DBCD0066CF02802CF060062C658005C0D2C273DACC0032
              C002802CF060062C658005C0D2C273DA7633B09C3D0BC032137CCB0C58C8000B
              808545E7949981650658009699E05B66C0420658002C2C3AA76C3703DDD9B300
              74B3C1FBCC80650CB0005856704E9719E8668005A09B0DDE67062C638005C0B2
              8273BA7633D09B3D0B402F237CCC0C58C4000B8045C5E65499815E0658007A19
              E16366C0220658002C2A36A76A3703FDB26701E8C70ACF31039630C0026049A1
              FBA579F954FD2C1CFDCEF19C1D0CB000D851E793B2CCE56B978C65167F8603F7
              4F32E0092B186001B0A2CC2B93CC152AB352AA4F2FCFE23ECE2D1FF36DFA1818
              94110BC02066523AEF14AADF9542167AD3933087E77AE7F938DD0CB000A4BBBE
              2BB2830BFC204C9C0763D0769E6B33E83CCFA78C011680941574503A70612B38
              F76418A3B627BBB6A3ECF87C0A18600148411187A570D9C69D6B825CD0E883BE
              C3B0F95C32181816250BC03076127E2E57987DF178F6E8C341D3405FC408EACF
              7EF167800520FE350A14A153A8FEB9144B770772EE72420CC4EA9AE2DD1431C0
              0290A2622EA7E2146AD7C3FE020CAA6DC1C5A4C2639C9830C002109342508501
              AFE7FF93106A2B15DE091CB5B5837D6286F7E2CFC0A8085900463194A0F3CE74
              F507F07AFEEB4D858CD8B886297CC60D9F011680F03937B2A253A83E249478A1
              11F06E5058A3BD56F71CEF2796011680C496EE44E07041E26BFC6B4FCC18DF5B
              EBAE697C215EC02C032C0066F9358E1EE58518E5DAC6894DC1025E526001F0C2
              524C6DE27001C621869896271161B10024A24C2B83C477E8C5E9C2C35830A695
              51F25112186001484295BA627436D5CEC477E8754DC5621763C2D862110C07E1
              99011600CF54456F989BDE719E68A97BA38F644004105B3BC601A7793A3C06BC
              AEC402E095A988ED26A7AAAF92AAF5DD88C318B93CC688B18E3464835830C002
              108B320C0FC2C9D7DEAE32E2AEE156F1398BB162CCF189882319C4000BC02066
              62320F4FB06D16527D3226E1780F03626EC7EEDD832D236080052002D2BD2EE9
              4C55F0433DDBBCDAFBB55B1C531338FCFAF9B0DFE6E6E0C3854D7519F0E3CF02
              E087AD106D73F9CAACC848031FEAE924D1A897E4BE6AF9511CB8DF9935F01B72
              68E762009A21F5196001D0E7901CC1C9573E26A53CE98B3B89167AB4DF05EFCE
              3D4AB4C60A18CC05735A31C907B16080052016653811045C28B70829AF3A3143
              B7A784380017FAC420443C873683CE6BCD434EEDDCB440D8999A0116006A4635
              F026F3D54FC3C5BF4E0362A02B5CD85F6AD64B670C34704FA00DDABA87B43752
              AE6BE7488BCA685D0CF8DD6501F0CB98217B275FFDAC92E21213F04AA83A5CD8
              AFF68A8DB6E8E3D5DE8F1DE688B9FAF1615B730CB00098E3D63332DC2BDE2EA4
              78B367077F869736EBE5697F2E42B83E97FAF5F3640FB9B673F664CC46261960
              0130C9AE076C67BAF239B8577CAD0753FF26B27511FC5DBFDFBF63C7A3ED0B18
              9D23DADF9833E64E8BCA687E196001F0CB18A17D2E5FDD2F947C2321E4712825
              5A2F69CC6EBEF3F844C01DC440AC80EEC3DD20F73607C3ADF8AC47068298B100
              04618DC0C729546F9452BC8300EA24082932CF6DD6377F5B10FD2096044C61E0
              0739402E0C4033A4070658003C90446DE2142A15C07C170CF2ED70569C365FDF
              F45FD4C08889D8D4B82EDEBB5C4EDC43BE098B011680B09876D771A6ABEF1542
              9684819F43070EADDE5F2B3D6000BA0D89D8B846FB80FC972C75B8210766C021
              0CB0000C2187FA9493AF4C09253E488D8B78F0849D5C5898398AFB2607AE816B
              195903B8697364043CDDA041B3630108CA9C4FBFC97C6D9D9072CEA79B277363
              17E490D58DAD091CB5B91AB2369FA2638005808ECB8148CE54ED0225D52D030D
              344E18BB103DC4646A6DE40A39F310029B6832C002A049E028F70DD33B9E2732
              EACBA3EC829C377501FA89C5580CC0599B3B3FC1B0AD6F0658007C53E6DDE1B2
              8D336B5AAAF513EF1EDE2D8D5D78DE43386E692A16E40E393CBE10EFF4654067
              92054087BD11BEE3D989874798043A6DEA820B148CEB642A26531CBA615B7FC3
              0260A8059C425599803675A151C46A2A36535C52E49C740C1600031534D5B0A6
              2E304A0A4CC5688A53CADC9388C502405C35538D6AEAC2224EBF0D672A5653DC
              B6834EE82FDDB059007419ECF28706BDA7EB906CD7D4054516601F2053319BE2
              B84F0A564CB1001095D999AEED03A87360906EA62E24D2200780198AFD1C97EB
              01ABF2B41F065800FCB035C0D62954AF104ABD73C0E9C0D3862EA0C0F1047134
              920370DDE63C4840ECB3820116801574F83F58776DEDF9E075130CD2EDD081AF
              8F910246086628979B5CEE23CC2CDAA529566701D0603157985D9B5DA57EAC01
              D1D7558E2FAD59585858EA7B328193980BE6441D3A728F35A0C6B5098F0540A3
              DA522C3DA4E1DED735BBA89E33BF7DCB237D4F26781273C2DCA853305103EA18
              E38CC70210B03A4EA1D60AE83AD04D0A75C1DE0F97FF7BA041C24F606E982375
              1A266A411D635CF158000254C62954E122553280EB4097965257CCD7CB5F1D68
              9092139823E64A9B8E929D9AD0A2C6198D2A3616009F4CE6F2D58F80CBB360D0
              6D4A7EF896B9F2CD7480F1466AE70A391347F92CB736C4B0E9866301F051DFDC
              D4F6374A29DEEDC3C583A9BAB33157DCE8C13055269D9C95F6B716779382B5C1
              1A75CFF1FE7006580086F373FCACB3F1FAD36426F3B9E313043B4A88FF68D4CB
              17114025120273470E2883C71A61AD2831D38CC502E0B5BAD9F15F7A35F56877
              AC592F9DE3D136B5662E07C74813A4AF156978BA6094FE2C001ED8740AD5C31E
              CC7C9934EAA5715F0E293636C185899AA5B1042C0023AA0A8DF47930590D836C
              8386277D05812CB008810C70B2DAAD5D8459C57F6916802135720A95D7C0E937
              C020DB8E89ECE96460290332C0CD1BDC1AA68C29BA7458000670393333332684
              BC4350FE64E4C51FAF4FFF2F25649AB0DADC0047B439C93B3AB5A4458D0A8D7A
              5D1680018CFEECE0A947079C0A340D2F51551A3B8AB70572B6C8093942AE2853
              A6AE25656C5163B100F4A98093AF7E550845F777BA523F999F2D6DEEB3144FF5
              61A0CD1570D6E754C029253B350DE89E623716809EE2AECF6F7FAB90E2953DD3
              3A87ADC65C193F32AC83619DAFCB19DDE72DA0A6EDDA5AC7E4F0845900BAF999
              99C96464E633DD53BAFBF0EC765617C3567F6AEEDAB5851A27954F1371B30074
              B1EA1C3C85F463B88B8BEA395DF0BC1B80016A0EA96B1C20A558B9B000B8E580
              BF11AB42C82709BA9F2DFB52FCD15E3A9A8623B91C6E196EE5E7AC7C52A7D67E
              7CD26BCB0200B5BDBC54F92DF8BBBF08BB349B1477C3C3D7ED34608CD2E61238
              2563428A62BBE66480C905620180DA8D2DCAFF831BAAADD5982DBD940A8C713A
              0CB89C923D29485CF34E90067F9B82B65E009CE9EA9729C93D7BED21D2B70D53
              C696742C6A6EA96B9F447EAD168075F9CA8B84121790154EC98B67666616C9F0
              186805036D6E81E315933A0750FB760FE86024DCD76A01C84AF91DC2FA7DBD31
              C7EFF423E4B32F94CBF1D7FB9E0C3049DC03012288D6C55A0170A66B5FA4A41E
              9EA87A25251E630D66809A6BEA5E181C79B03326BDAC14006753ED4CA1D4ABA9
              885DF5D8A153A8B018C71B03A49C432FB47BC2DBD2A9B2B25200444BDD4B5645
              A926F7EC99798C0C8F813C31D0E61CB8F764ECC588B227BCAC17131BEB04C0C9
              D7FE8E90FB9F3766CB0D423C86F2C180CBFDCF7DB80C3525EE8DA16BC5E5A455
              02902BCCAE15525D4A457EA35E3A930A8B718231405A03E88D768F040BC58897
              6950AB04408A25B27B8B4C46F29B7D4C77A7477CCA5A50F688C7F02335B34600
              72F9EAEB80699A27EB94F8CACD3B8A77031E6F3160A05D0BA8095128A7B8BD42
              04176F186B04404AF1CF54A568CC95FE800A8B716818A0AC0965AFD064670EC5
              0A01700A95DD5414AA55AD675261310E2D0394B5A1EC99A05986E16785000821
              AF11043F4A882F352B9B7F4100C5100618C0DA608D68A0697A8626167328A917
              00A750257BCDBF592F91BD79C85C49ED46A6AC1165EFC4B52AA91680BF28569F
              0EC4D3BC542733D6FE0F3FE030591B5DADCE747B2859F9FB8836E3C33671A6AB
              97C44F498296E2178DD94DA4FFC996242E06E9CB40BB5650B3BE277D4E92F590
              CF75C3324FAD00ACDB547BBE14620D05918DD9123FF147416488185435C31EC2
              5E0A31F450974AAD00645BEA47144C4AA13E4881C318E13340553BAA5E0A9F81
              D12BA652009CE91DF8641D496EF3F5F2FB46D3C816716480B07619B7A7E298A6
              564C2417895604269C558BE4B3FE6A499E6F223CC60C8F01B21A12F59497CCC3
              B4499D006CC8572F2422F0607357F16B44580C1311036E0D0F522C4FD85B14E1
              9060A44E005A5292DCFB1F3AFA449A970F49CAC4203A0C50D592AAB77472A1F6
              4D9500E40A1F7A961014FFD453DDB9B0FBDA43D464335E340C746AA9085EC655
              B2D363D1E46162D554098014AB483EA1D7A897F94D3F26BA2D424CAA9A52F5D8
              202AC29E4F8D004C4E6E3B15C85B0B4377FBAC2E00FBC796018ADAAE757B2DB6
              49FA092C3502A0D664BFE127F141B68D7AE94F069DE3F9643340555BAA5E8B03
              9BA9110020F31C18BA1BC53D846E0CEC6F96018A1A53F49AD92C3DA2A742009C
              7C95E4CD3A54F7101EB967B30818A0AA3155CF755310C57E2A044048F1016DF2
              94B84D1B830192C10045AD297A2E066C255E00260B3B9E43C16363AE7431050E
              63C49F01AA5A53F55E948C255E00945A22787D97E863C3515692D7F6CB80F647
              C5897ACF6FDCA4F689170021E519BA8C28917D992E06FB278B01929A13F4DE32
              6B51DD265A009C7CEDEDDAC44971B8599F2679AFB8762C0C101A03ED9A43ED75
              1724E941DD2034FC132D0042AABD1AB9B75D554B507D78A88DC7BF92C30049ED
              097A304AC6922D00424CE892D79C2B91BC8148370EF60F9F01A2DA6BF760F899
              9F5831B1023099AF51BC63EF3327A8E03D4B19D0EE01DD5E8C92F7C40A404BA8
              A62E71BF581A7FA72E06FB279B018A1EA0E8C5A8584CAC0048299EA24BDA3FEE
              9A3AA28BC1FEC96680A207287A312A16132900975F5779B62E6150B4ADBA18EC
              9F0E06287A81A227A3603391023036263FA44BD6FC6CE9065D0CF64F070314BD
              10B427A36630910200A4E9BFFE0F20BC3103840C24B227932A005A755342D6B5
              00D839750CD8DA13891380F504DFFAFBE88147B6A4AE8339212D06287A82A237
              B59208E09C3801C848F1EE0079AE7059589839BA62820FAC6780A227FCF6661C
              484F9C00006997C0D0D8D45D1ACEEC9A6A06B47B43B337C327378902A019B3DC
              193ECDBC623218D0EE0DCDDE0C9FA5C405AC4B51A35ED27EEBA76E0CEC1F4F06
              6CEC8D4409C0FAE91DE7C6B375382A66A0C380D71EED5847FF3B5102205B2D7E
              EF7EF43DC3110C6120693D9A28018067592F18C2FDC85352894F8E346203AB19
              D0ED11DD1E0D9BFC44D61F59A80000100049444154098012E27C1D8294509FD3
              F167DFF433A0DB23BA3D1A36C38912002067158CC0DBE131F9F9C0CEEC680503
              043D32B247E34464D204408BBBFDB5D2035A00EC9C7A066CEB11AB0420F5DDCB
              0932033E196001F049189B330369628005204DD5E45C62CF40DC026401885B45
              381E66204406122300333333898935C4FAF15231642049BD9A988BEAC7F74F3C
              55B3D60F6AFAB3BB3D0C68F50A41AF86C674620460D52999D59AAC3CAEE9CFEE
              F630A0D52B837A358EF4254600C6561DFBB526816B35FDD9DD1E06B47A85A057
              43633A310230BF7DCB239AAC9CA2E9CFEEF630A0D52B04BD1A1AD3891180D018
              E18598018B1860012028F6FA7CB53859A83DE214AA0AC63D4EA1F21A02588648
              1103714D850540A332EBAEBDFE6970C1AB8C145525D4840B758E10F20E07C4E0
              B28DDBCE10FCC30CC4980116008DE264578D0FFD70D178367BDF15856D2FD058
              825D9901A30CB00004A417EEE1FFC58BEB92C8FED08B1DDB30035130C002109C
              F53FF2EA0A62B1CDAB2DDBA58F813867C402104E753687B30CAFC20CF863C02A
              01D830BD43F7EDC4FED865EBC431605B8F244D00FE53A7A3945A7AA98EBF8EEF
              E553379CA5E3CFBEE13040D0235A3D1A4E9627564994004821EE3E11BAFFBD96
              92AFF5EF45E331961D9BA2416214930CE8F6486F8F9A8C95023B5102D052EA1B
              3A494B292ED3F15FE1ABC4BFAE381E75A0C4D5A34CF87CF40CE8F6886E8F86CD
              40A20460F1D8E2AD9A049DA9E97FDCBD25C5EEE307DE76B4DE5FEE6D09B62260
              40AB47087A942005EF108912808FEFDE1A9BBFAF6EA997F67BA7B963094F303D
              AFB3C7BFD3CA409C7AD40BC78912002F09C5D966492D7D24CEF1716CB40C2401
              CD3A0170A62A7F4A5718F5233F5852C8D7FBB167DB7019A0ED8D70630FBA5A12
              0540EFCF808CDC1A94AC5EBF562BB3B1776ED4B1B3F1FAD346D9F0F98818D0EF
              0DBDDE8C20EDC40980524AF789C0DFA7E2F9969DC53B7C6365C7FDFBF85E841D
              0232A0D51B04BD1930ECE06E891380CCEA27D483A76BC4B3E513F53C9FF66C9E
              1006BA7B3321218BC409C0FCF68DF7EB924BF9B79E1222277CFE38852A7F36C0
              2767A6CD297A82A2374DE7D98B9F3801E84D20D071467E30905F1FA766BDB4AF
              CFF4A829FE74E02886C23E4FD8136187AEB35E5205E08B3A49832FF5C3F09F02
              A6AFCD2954FCBE91C8173E1BFB6640B727747BD277C0140EC91400256BBAC9AF
              DFB8FDB9BA18CBFE2A2BDEBCBCEFFD565EE3DD962D4D3240D20B5D3D6932566A
              EC440A4063AE789B2E11329BF9942EC6B27FB356BA6779DFCF2D3C1770AF1F7B
              B635C300452F50F4A499EC86A326520086A7E4EDAC14E2F7BC597AB39252BDC5
              9BE50AAB33270B15CFDF2CB4C2930FC818A0EE05B2C042004AB200FCBD2E3F4E
              6196ECFB01E667CB81DE9FA084F4F4DD82BAB9B27F7F06887A40BB17FB47677E
              36B10270382BAED2A54709ED4F17AE084109F5BE15131E0F260BD5631E4DD98C
              98018A1EE8EE45E2F08CC3255600F6D74A43BF92DB0B735248D26FE969D6CB81
              5E5E54428C39F9EA012F31B30D2D03143D40D18BB4597947CB78378DA1A5D2FB
              8620CC28375DDB8BB76463499C1B084B8AD39D42ED4B817CD929100324B527E8
              C140C11339255A00E09E53FBCF00A9D406222EDB308D5DA51F425C01EFCDD51F
              3A85EAF7DB40FCCB380314B5875A6BF7A0F144872C90680168CE95BE312437CF
              A79C7C2DC0EBF883E19BF592CEBF043B3757A86ABFDD7970747C0619A0AA7977
              0F226ED246A20500C906050EF2565C743D31A4FAEC8903A23D99B928289214E2
              99F04840E5366E7B65500CF61BC10041CD497A6F4498A64F674C2F601A1FEE6D
              D751ACB17EAA46FA8DC18DD94D77425C5A8F506436FB55275FF5F5A523B0266F
              2318A0AA3555EF8D08D7E8E9C40B80CBCE23EE6DE09B4C46DD1ED8798063A35E
              7AC58053DEA7A5F81D7C343059A8DDE0DD892D873140546BED9E1B166358E7D2
              210019F9C71484C185F62E0A9C6E0C10017844DF3D136C5F09B505E2534EA1F2
              9A6008EC850C00873435EEE939C44EE2488500347614BF4244FE8D44382B608E
              1C3946F82FC9E41DD0C42004DB4B2B16E103AF0C90D498B0E7BCC66DC42E1502
              80CC4821A7F15677E4F2953DBA18BDFE9FF8E8D68794CCBCA8775EEF38534121
              80783F93CBCD3C410FCB0E6FE08AA4B654BD1607D6532300F3F522C957854929
              AFBCF49A0F3D85BA38CDD94DDF5B3CAC9E418D0BF1BE55AE9D78BC2D0685CAFB
              A9F1D382873505AEAEA4C887AAD72862D1C5488D007488907FD3B9D5FBBD7AF5
              AA07F510FA7BEFFB58F997AB1E3BD5D87F08827BA6191482CEA87C6572AAFAAA
              FE91D8374B57D3937B2CC96CA64A001AF5E27BA98AE1E4B757A9B0BA71F6ECB9
              EA317C62105E437EBC7B9E7E5F9EAF32E2AE8E1854E13983F6F835BCACF86527
              5FD93759A8CC38D3D5F5B942F5CF36E4AB17D2AF1F1F4487B096943D16078652
              250048A892F266BCD51E3253BCE4DD3313DA3803009AF5D293E0D47E18616EA7
              0A292E1052BE5309F97EA144530A716B4B8A3B9D42755924FEFF8A8D3BCF1029
              F969D7106A49910E596F51044384913A0168CE16AF20E2464C8C4F187DAD171E
              095C2A338B2FA68A9708E7E94BD9A3F78120FC1B115EA4309435A4ECAD4849E9
              5A3C7502D0CE4DAAC9F62DC12F7898FC0302988110F33BDEF31D100229A4FA87
              8146D19C78F964A1FAB7D12C4DB32A69ED06F4144DA4D1A1A452001AB3E50619
              A54ABC7072BA7A3519DE002088F94DEEFB0562F3E5204A88CB07841BFBE976CD
              A0765481427DE87A8A2A28029C540A00F2A2C4B167E32DC5504A7C145F46A2C0
              1A8681EF17804703E3B2A5827CBFE030E8C0E772D3958B033B47E488B5C29A51
              2D4FD94B543151E1A456009AF5ADFF032405FC5C3E78F66C742F23F500F7399C
              DF59BE1584402A2137F4391DEA5446C9D785BA20C162C4B53AE0F6124164F183
              48AD0020D57011913E9B0D4F8C29C40D6B34EBC579C8410AA57CFF1762AA1895
              52469F03A18A731987BA46C0FFC01E5A5E33C9B7A91600B73097BAB724374EA1
              F63009900F90C65CF9C3D088521CC5EF3094A1FE2F8143F79FBDD747A8919A1A
              A80D69EF444ACE80C5532F0070E1EC87D7BB09BF6147AD8167C77F3C804FA3D3
              8DDDC5FB1AF5E2D9909314429685102D18C63629C5430B0B6F5B32B6002170A7
              266A0D19A412F703CF61BF4F832C7CAF40A9170024A23157FA6DBCA51AF077C0
              F373852A7EE10715A46F1C10822A34681686CC48712D88DC61DF20C31D8ECDCF
              96083FC5387C319DB3580BAC890E46AF2F75CFF4E2C7E5D80A0140B2E10F69D2
              27B3E02EF84278C8F92DC48E7ADC3C5BDA0D0DFB4414031CAAA52E8398827F1B
              911439C019078CD86F5803AC0565A05E7A8572BD28B1AC1180F97AF97621E437
              05E98F7A69E7A12729A836587367F9137001BF0286EC1E2A2B5E80CD2D8574E0
              11C35F09A16E8497CB6E104A5EBD28965E78DC76B6748B7610210074B85764FF
              DDA913B2FC66A7573A4769FF6D8D006021E161F3CBE1761106D9860F3DE12128
              E1730C64A19D0484FFC4149B7BBE5E6CC22386BF6ED4CB5737E74A5B1B73C51B
              F7D5B724EABB079173E4FEA424F52616DD1ED1434990B75502807569D44BABF0
              967248D1FE16DF2394988C359801A7503D829C0FB60876C6446F048B243C2FEB
              0400A9C587C2784B3CC6A131556E86BF9D8798D7E370C82D720C13E4CF4FF8E9
              09583F359B9502800F8595141513559407271EDFB0A9F61213D8366322A7C8AD
              090EB017B0274C60C71DD34A01C0A234674B9BE1D6C8BBDC5A2DF5EF704FB50D
              F079236000B9444E09A0FA41FCC0ED857EE7523F67AD006065E16FBEDF852792
              7E89FB06C666275FC5EF13803F570DA0DB01295D0E51ACC933C6DA630F900327
              08D06A01C03A35EBA567C0154AFACA00E2B687141370EFD5CA156A64DF4FD0C6
              B5E0177286DC09E0D044BA5873ACBD5FECB4D95B2F0058D07903AF0C20EEF280
              D7DE6F866626FB64E2326E5A6F912BE4CC647EA66B6E32764A6C1600974D7828
              08770AEE81999BD3A1B155AE50DD69063EF9A8C80D7204999C0EC3D81642AD8D
              C54E0DCC02D0C568188D012AB3119B3C375D7947D7D256EF2217C80972639A88
              306A6C3A074A7C16801E36C36A10A9E47E6CFAF529FF4AEE1E7A571C62EEC801
              72B1E284A103DDDA1A0A2B525816803EF487D92899135FC94DF66DC67D528AD5
              145CF457C050987B58818559D3B072A258870560008B6EC31C1A70DAC4F44D78
              51C048EDFB07303718F0EA9BB8C9048103300FB9B51C70DAEE69168021F587C6
              39154E87FD91DFCD78913885CA91DC54F29F27C01C3017CC09B834F27A3EE00E
              DABEE5D670D079EBE7590046B40034D0CB94127F39C2CCC069392E339DE709E0
              D9F1FB73F9DA250616310289B162CC78D1630E4248F2F7EE8B113F5833ACDD08
              33CFA7D36AC802E0A1B2CDB9D2F54AB4227B7F3F3C3BFE4C29D5A7F182C20117
              D76D93F96DE778083D14138C056372DC7F2F86B162CCA12CDE6711AC15D6ACCF
              299EEA618005A087904187CDFAE66F2B917DCAA0F361CEC3C5F52625B3F72C5F
              704EBE7AC099AE7EC0D9543BD3741CB8467B2D5CD3BDE031168CC9F4DA5EF0B1
              46582B2FB66C23040B808F2E68D6A70FC2C34A092EF7C188CF26C5E94289F789
              96BAF7B828B817271C3F0CF7CE5FC8E5AB1FED5CB895EB26A72B6FCB152A17AD
              9FBEE15C1CB88F734EBE729D034282B6E883BE3096FF6968FB16D768AF856BC6
              87018CE43EAC0DD6080F7878638005C01B4F2BACA0D1CE124AE5574CC6F7608D
              14E22229C5D59D0B57EE524A7E4A0AF9858C1AFB3E0EDCC73921E52E014282B6
              127C841074DFB20B60C636A845BB26861648332C0B40C0EA36E6CA3B17C7D444
              4077762362006B80B52082B30E860540A3E4FBAAE547E19E07EE30E582060CBB
              0660400AB980DC630D02B8B38BCB000B804B84CECD7CBDF8B689A5F12700C6AF
              60F06696815F21D7C8B9D965EC40670120AAF3AE5D5347E01EE9E92A23CF2782
              64981E06905BE418B9EE3965EC30EDC02C00C4156EEE287E0D9A540AA1AAC4D0
              16C329FC2F4812B9B5980423A9B30018A1558846BD5C6ED44B5209F111434BA4
              1E16B9430E1BC065EA938D28411600C3C437EBA5EB1A2004B04C62FECB2EC41A
              F5B6173943EEA20E24EDEBB30084546168E82B61C023023913D292895B460939
              831CC1B8320EC1DB10030B40C8556ED68B1F8006974A665EA4947A28E4E563B7
              1C72805C2027C84DEC024C79402C001115B839BBE97BCDB9F253B1F185941F8F
              288CE896859C3177E400B9882E10BB5766018841FD1BB3C5CBF16258F5D8A9E3
              5289DD3108C94808981BE688B962CE461661505F0CB000F8A2CBACF19E3D571D
              9B9F2B5DDBBE40E089437878FC1E58F1411849DD1EC41C96F3C1DC30C7242463
              4B8C2C0031AE343C3CDE0617CFD360481C10EA5530E2F5494408A86BC3D8AEC2
              58DDF134CCA1EB3CEFC68C01168098156458387051ED8171168CB620E0AD14EA
              754A898F81DF0330C2DA1EC035716D8CA16B606C7BC20A82D7D1678005409FC3
              4811E6EBE5DB9B73A56BE0223C0DC67161C0FDB3D71ECA2AD17A09BCBCE60821
              CBF0701CBF7074AF50F25621D45D428A1FB607EEB7E7C4DE8E0DD80AE9A02F62
              2056CF380DD7C4B505FF249A01168044976F78F0333333AD667DF3B7E1E5B566
              A35EAC36E7CAEF810BF9CAC65CF12D8D7AF9C2C66CBF1B6E4F000000E6494441
              54E9DCF6C0FDF65CE9CA8E0DD8D68B4DF4458CE1ABA4EFAC4D19B100D8546DCE
              9519E8618005A087103E64066C628005C0A66A73AECC400F032C003D84F0A1DD
              0CD8963D0B806D15E77C99812E065800BAC8E05D66C0360658006CAB38E7CB0C
              7431C002D04506EFDACD808DD9B300D85875CE9919701960017089E01B66C046
              0658006CAC3AE7CC0CB80CB000B844F08DDD0CD89A3D0B80AD95E7BC99016080
              050048E08D19B0950116005B2BCF793303C0000B0090C09BDD0CD89C3D0B80CD
              D5E7DCAD678005C0FA1660026C668005C0E6EA73EED633C002607D0BD84D80ED
              D9FF060000FFFFE6E8875E000000064944415403002AA5F479FF57569E000000
              0049454E44AE426082}
          end>
      end
      item
        Name = 'Sales'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9D7B8C5C5519C0CFD9ED2EB65D40140C82243521
              1114953FC037BE1321D1C4601A15D36666D11AA8EDCEB6DB160CEA2A5A6877B6
              3B6DB1891576B6C4442541138841A3D14423286024515063228F221A542CD094
              DA76E778EF740ADB61E7791EF79C7B7ECDDEB933F79EF39DEFFB7DB3BFEEEEDD
              9D1910FC830004A2258000A26D3D8543400804C0B300021113400011379FD2E3
              2690568F00520A6C108894000288B4F1940D819400024829B0412052020820D2
              C65376DC044E548F004E90600F8108092080089B4EC910384100019C20C11E02
              1112400011369D92E326B0B07A04B09006F721101901041059C32917020B0920
              808534B80F81C8082080C81A4EB9711368AE1E013413E1310422228000226A36
              A542A09900026826C263084444000144D46C4A8D9BC062D52380C5A8700C0291
              10F04E0085D2F44C24EC29333202A3A5F2ED2B57DE31E853D9DE08A0589ADA57
              2C959514AA54286DBFD82748E4020113049410AB46CE7DE258F23CFFF3CAF11D
              4B4DC4D48D91B900121877255BC246AE7EA998817B5FBACF3D08844F60B4343D
              BDA08A378CA8DAA1E479FFE49A35379FBEE0B8B5BBAD02672680E258F9E70980
              E4135F7CAC393929C4D295D74E8E341FE731044225A084DAB048EEE71E5DB6E4
              40F279F0AFE2BAAD672D72DEFA21A702989C9C1C488ABD3FD99490E203EDAA5B
              3E3CF29B76E73907815008144AE52B3BE47AA6181C7E3AF9BC78B678EDF4791D
              C61A3DED4400EBD6ED3AA53056FED3E30746E693EC2F4DB68E1FC957016FEA38
              880110088040F25CBEB3CB344F13C3EA89E278F98555A56D177639476B985501
              8C6EDE766AF2A5FEFE8383470E4B292EE835D304C46CAF73180F019F08144A33
              2B7ACE4789572C11838F144BE5F9D1F11D97F43CBF6942BB87D604502C4D3FAD
              8E0C3E27A4785DBB04DA9E53A2D8F63C2721E0390129E67FA791E28052B5078A
              C9D5B1D12F6C3B47234ECBA9D60420847AA6E5AA3D9C181D9BBABA87E10C8580
              37041AD7FC5F6522A1D95BB63C65224E730C6B0290C3F35D7DAFDF9C50F36325
              E5ADCDC7780C8110088C9CBBFF1766F2949BCCC47979146B0298DDBEE579A5D4
              7F5FBE64EF47568F4DBDA5F759CC8040D604D4652632A8563696FB8DD3699E35
              01A40BCBC181B7A67BDD6D5088FB7463301F022E092457BD6E32B15E720561B7
              8938AD6258154075C7C6FD4901C75A2DDEF5712997AD5933B9ACEBF10C8440C6
              0492AB5ED7994861B632B1DE449C5631AC0AE0F8A2EABDC7F77AB74797F18B41
              7A0499ED8A40617CEA65BFDDDAE7DA3FE9735ED7D3AC0B60B6B2C9D497EF6FEE
              BA2A064220430252C9BB4C2C5FAD4C5CAE13A79BB9D605902621A5FA64BAD7DD
              92EBA1DFD28DC17C08D82460EA7ABD12E2619B799E88ED4400B3339BEE38B1A0
              E67E8DE67CA643C02A01B564C9432616183E74EADB4CC4E914C38900D2249490
              5F4EF7BA5BA1545EA51B83F910B047409D6520F6BFF7EEFDFC2103713A867026
              80B9CAC61B3B66D3C580E4AAC2ED5D0C6308049C13181D2FFFCCC4A26AA8A6FD
              F3AE6EF37026807A424A54EB7BCD9BCF3AFA4B29CD34991E1901A5C487B44B56
              627E6E6AF33FB5E37419C0A900AA3B2746BBCCABEDB07931F840DB019C848063
              02C5B1B299AF7007E6DFE13275A702480B5342FC32DD6B6ECB574E4E0E6BC660
              3A04CC1190E20613C16667B63C68224EB7319C0B60AE32F1BE6E936B376EE4C0
              C8FDEDCE730E02AE0814C67718B95E9FFCE7F8091339F712C3B9001AC9FDADB1
              D7D919F93B039D04980B81948054B57BD2BDEE96FCE7F803DD18BDCECF440072
              78FEE25E135D6CFCE858F99B8B1DE718045C11583531F51A136B4929AE3711A7
              D718990820FD53E124D167934DEB434971AD560026434093C0E031F907CD10F5
              E9B3331337D7EF38BEC94400F51A8F4823D73A474BE5CFD4E37103810C084821
              B4BF0248BEF737F6DA97BD22C84C00D53D1BF727D74D93DA7B4DF9E4F14980EF
              9C7C8447107043A0582AFFD8C44AC9F7FE579B88D34F8CCC049026AB64EDB274
              AFBB5D3DBEE37CDD18CC87401F043ED2C79C93A72861E865C34E0EDBEDA34C05
              B0AFB2F9D7DD26DA6E5CAD56FB7DBBF39C8380690285F5535F3111B3BA73E283
              26E2F41B2353013492BEAAB1EF7F27C548FAAE43FD076026047A232007E4646F
              33161B2D4D5C0E7F31703F77321740B532F1DD7E126F9EF3F881E5BF6D3EC663
              08D820305A9AFAB089B84B8FBC22F3DF65C95C0075904A18F8724A5E528FC50D
              042C135042FED4C012CFEDD9B3F6A081385A21BC1040F27DD0D7B4AA684C2E96
              CA95C65D7610B04260F5DAADAF361178707EDE8BF7BEF4420075A05298F853E1
              B17A2C6E206089C0E0F0F01F4D84BE75F796274DC43911A3DFBD3702A8CE4C18
              F953E1E2D8B491D71FEC1728F3724E4089B3752BAC89DA7B7463989AEF8D00D2
              829450BF4AF75A9B54DFD39ACF6408B420501C9FBEBBC5A99E0E9BBAFCDDD3A2
              2D067B2580B9CA2623EF2150DC307D5E8B7A390C81FE0928F5D1FE271F9FA944
              AD78FC9E1FB75E09A081E4F1C6BEFF5D4D397949E5FE13646668040AE3E52F9A
              C879AEB279CE449C853174EE7B2780A14307DFA8535063EEA98D3D3B08182120
              95F8866E2025D48DBA314CCFF74E007BF74EA62F87FCBC6EA1C925C17B756330
              1F0229814269EAFDE95E774BBEC535F2D2F8BA792C9CEF9D00D2E4E6E5C085E9
              5E737BA7E67CA643A04E400A69E20F76BE5F0FE6D98D9702B87D66C3DF4D702A
              8E95CB26E210235E02575D73D31926AAAF56263E65224E730CDDC75E0A202D4A
              0AF5AE74AFB549B1516B3E93A327307CCA90F60F949510DEBE80ADB70298AD6C
              BACFC4B3AF502A5F69220E31E224208578AD6EE5739589B7EBC6B035DF5B01A4
              050FC8814FA77B9D2D69E09D3AF3991B2F81D152F987DAD52BE1EC5D7EFAC9D5
              6B01DC36B3C1C86FF5997ACBE67E0033275C02C997EE1FD7CD7EE8856317E8C6
              6835DFC471AF05502F50892FD5F71A376AC9A0F6F7711ACB33354002C965E4CD
              06D23EB277EF75DAAF7E6D208F9621BC174075E7C4D75B66DFFD8957763F9491
              10A813D856BFD5B851B5DA451AD39D4CF55E000D0AB736F67DEF12A39BB896DB
              F7FA4C0C8740617CBB9117AB9DDBB5F9AFBE571D8400926BA89F3300D2C86F73
              19C883109E13906A40FB0D6C931F605F61B34C53B1831040BD5825B4FF072F96
              A6B6D6637103811604D66CB9F9F416A77A3A9CFC00DBC87B06F4B4681F838311
              40F2B300032F9F2C3379FFB53EFAC2948C081C3DBCE411EDA5D5C03AED188E02
              042380E33CE463C7F7FDDF16C7B66BFF4D77FFAB33D37B02529CA39B6375E786
              5B7463B89A1F940046E687F4AFA9CA81BB0BA572950D06CDCF81E407C5DA6F30
              A394FD57A4322987A004B07BF7FAFF99285E0A51608341F373400871B1D0FD27
              E561DD102EE70725009760580B02311040003174991A21D0820002680186C310
              F09180E99C108069A2C483404004104040CD225508982680004C13251E040222
              8000026A16A9C64DC046F508C006556242201002082090469126046C10400036
              A81213028110400081348A34E32660AB7A04608B2C7121100001041040934811
              02B60820005B64890B810008C42700290A820D062D9E0352C88AF0EC9FCD74A2
              13407566621F1B0C5A3D0794540FD9FC84F32D767402F0AD01E403812C092080
              2CE9B3360432268000326E00CB43A01D01DBE710806DC2C48780C7041080C7CD
              213508D82680006C13263E043C2680003C6E0EA9C54DC045F508C00565D68080
              A7041080A78D212D08B82080005C50660D08784A000178DA18D28A9B80ABEA11
              802BD2AC03010F0920000F9B424A1070450001B822CD3A10F0900002F0B029A4
              14370197D5230097B4590B029E1140009E35847420E092000270499BB520E019
              0104E0594348276E02AEAB4700AE89B31E043C2280003C6A06A940C0350104E0
              9A38EB41C0230208C0A366904ADC04B2A81E0164419D3521E0090104E0492348
              0302591040005950EF62CD42E9A615A3E3D3F7144B6515F876A4509ADAD045C9
              0CC9800002C8007AA7250B6353CF4831F4A852EAF24E6303383F24859CAE4B6C
              AC7C6300F9669262568B2280ACC82FB2EE15EB769D927EA24829CF58E474F887
              A4B821A9EFD1F00BC94F0508C0A35E9E3D78E4B047E9D84A6545B134BDD55670
              E2F6460001F4C6CBDAE8E278B96C2DB87781D5F5DEA514694208C097C62BB1D1
              97545CE4917C15B0C7C53A21AC91658E08204BFA2FAEADE48B77A3B9A3AE89A6
              548F0B45001E34A7B07EEA7C0FD22085080920000F9AAE86064EF3200D528890
              0002F0A0E9CB5F58FA170FD220850C0864BD2402C8BA03C9FA7BF6AC3D98ECA2
              FA5042FC28AA823D2D1601F8D398A7FC49C57E26837260B5FD5558A1130104D0
              8990A3F3F2B9F90B1C2DE5C132EAC1DB66363CE34122D1A780003C790ACCCE6E
              793EB918B8D69374ACA651AD6CBAD4EA028104F7214D04E043171A39CCCD4CEC
              1135F9EEC6C3DCED92EFFBFF51AD4C44F83B0FFEB6120178D69BEAAE8DF7A69F
              244AA96F7B969A4E3AFFA9C96317CD5526CED109C25CF304108079A64622CEED
              DCB42615414EB633F7CD5CF7B0113004314A000118C54930087447C0975108C0
              974E900704322080003280CE9210F0850002F0A513E401810C0820800CA0B364
              DC047CAA1E01F8D40D728180630208C031709683804F0410804FDD2017083826
              80001C0367B9B809F8563D02F0AD23E403018704108043D82C0501DF082000DF
              3A423E10704800013884CD527113F0B17A04E06357C809028E08200047A05906
              023E1240003E76859C20E088000270049A65E226E06BF508C0D7CE9017041C10
              40000E20B304047C2580007CED0C7941C0010104E000324BC44DC0E7EA1180CF
              DD213708582680002C03263C047C2680007CEE0EB941C0320104601930E1E326
              E07BF508C0F70E911F042C12400016E1121A02BE134000BE7788FC2060910002
              B00897D0711308A17A04104297C81102960820004B60090B811008208010BA44
              8E10B044000158024BD8B80984523D0208A553E409010B04108005A884844028
              041040289D224F08582080002C402564DC0442AA1E0184D42D728580610208C0
              3050C2412024020820A46E912B040C1340008681122E6E02A1558F0042EB18F9
              42C0200104601026A120101A0104105AC7C817020609200083300915378110AB
              470021768D9C216088000230049230100891000208B16BE40C01430410802190
              84899B40A8D52380503B47DE10304000011880480808844A000184DA39F28680
              010208C0004442C44D20E4EA1140C8DD237708681240009A00990E8190092080
              90BB47EE10D02480003401323D6E02A1578F0042EF20F94340830002D080C754
              08844E000184DE41F28780060104A0018FA97113C843F508200F5DA40608F449
              203A01144BE547D960D0EA392094981411FD8B4E00496F57B0091888B60C442C
              FF6214402CBDA54E8B04F2121A01E4A593D401813E0820803EA0310502792180
              00F2D249EA80401F0410401FD0981237813C558F00F2D44D6A81408F0410408F
              C0180E813C11400079EA26B540A0470208A047600C8F9B40DEAA470079EB28F5
              40A0070208A007580C8540DE082080BC75947A20D0030104D0032C86C64D208F
              D523803C76959A20D02581E004A0C4D1D7B3C1C0D7E7801047BFDAE5E79E17C3
              8213C05CE5FAC7D8602731EF800000019249444154E0F373C08BCFEC2E93084E
              005DD6C53008182590D7600820AF9DA52E08744100017401892110C82B010490
              D7CE521704BA208000BA80C490B809E4B97A0490E7EE521B043A1040001D0071
              1A0279268000F2DC5D6A8340070208A003204EC74D20EFD52380BC7798FA20D0
              8600026803875310C83B010490F70E531F04DA1040006DE0702A6E0231548F00
              62E8323542A0050104D0020C872110030104104397A911022D0820801660381C
              378158AA4700B1749A3A21B0080104B008140E412016020820964E5327041621
              80001681C2A1B809C4543D0288A9DBD40A81260208A009080F21101301041053
              B7A915024D04104013101EC64D20B6EA11406C1DA75E082C20800016C0E02E04
              6223800062EB38F54260010104B0000677E3261063F50820C6AE5333041A0410
              4003043B08C4480001C4D8756A864083000268806017378158AB4700B1769EBA
              219010400009043E20102B0104106BE7A91B020901049040E0236E0231578F00
              62EE3EB5474F000144FF140040CC041040CCDDA7F6E8092080E89F02710388BD
              FAFF030000FFFF3171CD200000000649444154030065F1C2881433CB66000000
              0049454E44AE426082}
          end>
      end
      item
        Name = 'Up'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC94E9AE5D4711854F6C088AC40C79803C1ABF1148
              202348DE0004C222224848E00804BC567E330F4122762C53AB728FEFB967DC43
              D7EEA1BEC82777EFDEDDD555DFAA5A8F76FC070108A4258001A4959EC221B0DB
              61007401041213C000128B4FE9B909A87A0C4014F8412029010C20A9F0940D01
              11C00044811F049212C000920A4FD9B909ECABC700F624F80B818404308084A2
              533204F60430803D09FE422021010C20A1E8949C9BC061F518C0210D9E21908C
              0006904C70CA85C021010CE09006CF1048460003482638E5E626705C3D06704C
              8477082422800124129B5221704C00033826C23B041211C00012894DA9B9099C
              AB1E033847853508242180012411FA5C99DFFACE2FDED6EFDC37D67210C00072
              E87C52A50FFEE3E77FDED9CF9F4F76B0908100069041E5A31A7DE06DF05F2FDB
              B3AFBD5EE061340297EAC1002E911974DD07DD06FEA43C5BF36F271F58189900
              0630B2BA47B5F980DBA01F2DDFBFDA37DF73BFC2D3E0043080C105DE97E7836D
              03BE7FBFF8D7F6F8DE8B1BF83012010C6024352FD4E2036D837DE1F3E9B2EDF5
              33A75F58E990C0B59431806B7406F8E6836C033DBB143BE367671FE4404F0430
              809ED49A99AB0FB00DF2CC63F7DBEDACC7B85FE169300218C06082EECBF1C1B5
              01DEBF2FFE6B313CD6E2001C6C990006D0B23A0B73F381B5C15D78FCF498C5F2
              98A75F58699CC0ADF430805B843AFBEE836A035B3C6D8BE9B18B0726604D0218
              404DFA85EFF601B5412D1CF63E9CC5F63BEE5778EA9C0006D0B980FBF47D306D
              40F7EF617FED0EBF2BEC02026F490003D89276D05D3E90369841E14FC3DA5D7E
              E7E917561A223025150C600AA586F7F820DA406E9EA2DDE9776F7E3117962480
              0194A4B9712C1F401BC48DAFBDBFCEEEF61CEE5778EA8C0006D09960FB747DF0
              6C00F7EFD5FE5A0E9E4BB504B8780D010C600DBD4A677DE06CF02A5D7F7AADE5
              E2399D7E61A51281A9D76200534935B2CF07CD06AE9174EED3B09C3CB7FB159E
              3A2080017420D23E451F301BB4FD7B737F2D37CFB1B9C448E812010CE01299C6
              D67DB06CC01A4BEB341DCBD1733DFDC24A830430800645394EC907CA06EB78BD
              D977CBD5736E36C1B1139B531D0630875685BD3E48365015AE5E77A5E5ECB9AF
              8BC2E96002184030E035E17D806C90D6C4A87AD672F71AAA26C1E5D7086000D7
              E854FCE683630354318532575B0D5E4B996844294C0003280CB444381F181B9C
              12B19A8861B5784D4D2433761273ABC300E6120BDEEF836203137CCDF6E1AD26
              AF6DFB9BB9F10A010CE00A9CAD3FF980D8A06C7DEF66F7596D5EE3661772D12D
              0218C02D421B7DF7C1B001D9E8BA7AD7588D5E6BBD0CB8F98000067000A3D6A3
              0F840D46ADFB37BFD76AF59A37BF78EC0B975487012CA156F08C0F820D44C190
              AF43BDDABD78E7F5CBC2871231CE5E6D357BED673FB2B815010C602BD267EEF1
              01B04138F369F59206F7C3A7EF7EB436906228D6DA3867CF5BEDCEE0EC4716B7
              2080016C41F9CC1DDEF83600673EAD5ED2C06A705707BA0BA0588A79F75AF68F
              31701665A3126D22010C6022A892DBBCE1ADF14BC6DCC7D2A06A60F7EFA5FE2A
              A662978AF7208EB170260F1679994360E95E0C6029B985E7BCD1ADE1171EBF7A
              4C03AA41BDBA69C547C5D61D2B425C3E6A4C9CCDE51D7C092080010440BD14D2
              1BDC1AFDD2F735EB1A4C0DE89A1853CEEA0EDD3565EFEC3DC6C619CD3EC881A5
              043080A5E4669EF3C6B6069F796CD2760DA40673D2E6029B7497EE2C10EA3484
              317256A75F580920800104403D0EE90D6D8D7DBC5EE25D83A8812C116B4E0CDD
              A9BBE79C99BCD75839B3C907726F5C533D06B086DE84B3DEC8D6D013B6CEDEA2
              01D420CE3E58E880EE560E85C23D0C63CC9CDDC355DE0A13C0000A033D0CE70D
              6C8D7CB856EA5983A7012C156F691CE5A05C969EBF7ACED839C3AB9BF8B88600
              06B086DE95B3DEB8D6C057B62CFEA481D3E02D0E50F8A072514E85C37E16CE18
              3ACBCFDEF87F6102184061A00AE70D6B8DABE7D23F0D9A06AE74DCB5F1949372
              5B1BE7EC7963E94CCF7ECCBDB8B67A0C602DC1A3F3DEA8D6B047CB455E35601A
              B422C102822837E518107AB733A6CE362478DEA0184041EDBD41AD510B867C1D
              4A83A5017BBDD0E8837254AE21E9195B671C123C67500CA090EEDE98D6A085C2
              3D08A381D2603D586CF845B92AE790148DB1B30E099E2F28065040736F486BCC
              02A14E4268903450271F1A5F50CECA3D244D63EDCC4382F713B444A618C04A8A
              DE88D6902BC39C3DAE01D2209DFDD8C1A272570D21A91A73671F123C4F500C60
              85D6DE80D6882B425C3CAAC1D1005DDCD0C907D5A05A42D235F6AE4148F01C41
              3180853A7BE359032E3C7EF598064683737553471F558B6A0A49D934702D4282
              8F1F140358A0B1379C35DE82A3378F68503430373776B64135A9B690B44D0BD7
              2424789B414B658501CC24E98D660D37F3D8A4ED1A100DCAA4CD1D6E526DAA31
              2475D3C4B509093E6E500C6086B6DE60D668338E4CDEAAC1D0804C3ED0E946D5
              A85A43D2376D5CA390E06306C50026EAEA8D650D3671FBAC6D1A080DC6AC431D
              6F56ADAA39A404D3C8B50A093E5E500C6082A6DE50D65813B6CEDEA241D040CC
              3ED8F901D5ACDA43CA30AD5CB390E0F58396CC0003B841D31BC91AEAC6B6459F
              35001A8445870738A4DAC520A414D3CCB50B093E4E500CE08A96DE40D64857B6
              2CFEA4C6D7002C0E30C84131108B90724C3BD73024F8184131800B3A7AE35803
              5DF8BC6A590DAFC65F1564A0C362212621259986AE6548F0FE8362006734F486
              B1C639F369F5921A5D0DBF3AD06001C4446C42CA322D5DD390E0DB062D7D1B06
              7044D41BC51AE668B9C8AB1A5C8D5E24D88041C4468C424A334D5DDB90E0FD06
              C5000EB4F306B14639582AF6A8C65683170B3868203112AB90F24C5BD7382478
              9F4131803BDDBC31AC41EE5E8BFE5143ABB18B061D38985889594889A6B16B1D
              12BCBFA0188069E60D618D618FC5FFA991D5D0C5030F1E50CCC42EA44CD3DA35
              0F091E173422727A03F046B0868880AB06562347C4CE1053ECC430A456D3DCB5
              0F09DE4FD0D406E00D608D1021971A570D1C113B534C3114CB909A4D7BEF8190
              E07D044D6B002EBC3540844C6A58356E44EC8C31C5524C436AB71EF05E0809DE
              7ED09406E0829BF011F2A851D5B011B133C71453B10D6160BDE03D1112BC4CD0
              A828E90CC08536C12380AA41D5A811B189B9DB89AD1887B0B09EF0DE0809DE6E
              D05406E0029BD01172A831D5A011B189794F408CC5FA7EA5E093F586F748C190
              AD874A63002EAC091C21881A528D19119B98A704C45ACC4FBF1458B11EF15E29
              10AA8710290CC005356123045123AA21236213F332013117FBCB3B567CB15EF1
              9E5911A2E4D1C858C31B800B698246405403AA11236213F33601B19706B7772E
              D8613DE3BDB3E0684F4786360017D0848C10448DA7068C884DCCE904A481B498
              7E62C64EEB1DEFA119477ADB3AAC01B870266084206A38355E446C62CE27202D
              A4C9FC93134E580F792F4DD8DAE396210DC00533E1220451A3A9E12262137339
              0169226D9647B872D27AC97BEACA96A84FD171873480DDEEE3106E6A30355A48
              7082AE26206DA4D1EA406703C4F4D4D9AB365C1CD2009EBDFFDE5FFEF778F776
              498E6A2C3558C998C42A4F401A49AB9291D54BEAA992315B8935A40108EE9F7E
              F6E4AF2F5F3CFFA69ED7FED4506AACB57138BF0D016925CD4ADCA61E522F9588
              D5628C610D40B07FF7CBF7FEF6E88D47DFD0F3D29F1A490DB5F43CE7EA109066
              D26ECDEDEA1DF5D09A186BCE6E7176680310C0DFFCFCFB7FFFE493175FD7F3DC
              9F1A488D34F71CFBDB2020EDA4E1926CD433EA9D25677B3A33BC01488C3FFEEA
              DD7FBCDA3DFE9A9EA7FED4386AA0A9FBD9D7260169282DE764A75E51CFCC39D3
              EBDE140620713E7CFABD7F7EFE0B9F7E55CFB77E6A1835CEAD7D7CEF8380B494
              A653B2558FA857A6EC1D614F1A039058BFFEF18FFEF5FCE59B5FD1F3A59F1A45
              0D73E93BEB7D1290A6D2F65AF6EA0DF5C8B53D5B7DDBEA9E540620A87F78FFBB
              FF7EE3CD975FD6F3F14F0DA246395EE77D0C02D2561A9FAB463DA1DE38F76DE4
              B5740620317FFB931FFEE7ADE76F7D49CFFB9F1A430DB27FE7EF9804A4B1B43E
              AC4EBDA09E385CCBF29CD20024EE071F7CFBE34F3FF7EA8B7A5643A831F4CC6F
              7C02D25A9AAB52F5807A41CF197F690D4062FFFEA73FF8EFB3A74FDE5043E89D
              5F1E02D25CDAAB075AAB7ACB7C521BC096A0B90B022D12C0005A54859C20B011
              010C6023D05C0381160960002DAA424E69096C5D3806B03571EE834043043080
              86C42015086C4D0003D89A38F741A0210218404362904A6E0235AAC7006A50E7
              4E0834420003684408D280400D0218400DEADC0981460860008D08411AB909D4
              AA1E03A8459E7B21D000010CA00111480102B5086000B5C8732F041A20800134
              200229E42650B37A0CA0267DEE8640650218406501B81E023509600035E97337
              042A13C0002A0BC0F5B909D4AE1E03A8AD00F743A022010CA0227CAE86406D02
              18406D05B81F021509600015E173756E022D548F01B4A0023940A012010CA012
              78AE85400B0430801654200708542280015402CFB5B909B4523D06D08A12E401
              810A0430800AD0B91202AD10C0005A51823C205081000650013A57E626D052F5
              18404B6A900B04362680016C0C9CEB20D012010CA02535C805021B13C0003606
              CE75B909B4563D06D09A22E403810D0960001BC2E62A08B4460003684D11F281
              C0860430800D6173556E022D568F01B4A80A394160230218C046A0B906022D12
              C0005A54859C20B011010C6023D05C939B40ABD56300AD2A435E10D8800006B0
              0164AE8040AB0430805695212F086C400003D8003257E426D072F51840CBEA90
              1B0482096000C180090F81960960002DAB436E10082680010403267C6E02AD57
              8F01B4AE10F94120900006100897D010689D0006D0BA42E4078140021840205C
              42E726D043F518400F2A912304820860004160090B811E0860003DA8448E1008
              2280010481256C6E02BD548F01F4A2147942208000061000959010E8850006D0
              8B52E4098100021840005442E626D053F518404F6A912B040A13C0000A03251C
              047A228001F4A416B942A030010CA03050C2E526D05BF518406F8A912F040A12
              C0000AC22414047A238001F4A618F942A020010CA0204C42E526D063F518408F
              AA9133040A11C0000A81240C047A248001F4A81A3943A010010CA01048C2E426
              D06BF51840AFCA9137040A10C0000A402404047A258001F4AA1C7943A000010C
              A0004442E426D073F51840CFEA913B045612C0005602E438047A268001F4AC1E
              B9436025010C6025408EE726D07BF51840EF0A923F045610C00056C0E328047A
              278001F4AE20F9436005010C60053C8EE6263042F518C0082A5203041612C000
              1682E31804462080018CA02235406021010C6021388EE526304AF518C0284A52
              07041610C0001640E30804462180018CA22475406001010C6001348EE4263052
              F518C0486A520B046612C0006602633B04462280018CA426B5406026010C6026
              30B6E726305AF518C0688A520F046610C00066C0622B04462380018CA628F540
              6006010C60062CB6E6263062F518C088AA5213042612C0002682621B04462480
              018CA82A35416022010C602228B6E526306AF518C0A8CA5217042610C0002640
              620B04462580018CAA776664A90000016E494441542C75416002010C600224B6
              E4263072F518C0C8EA521B046E10C0006E00E23304462680018CAC2EB541E006
              010CE006203EE726307AF518C0E80A531F04AE10C000AEC0E11304462780018C
              AE30F541E00A010CE00A1C3EE52690A17A0C2083CAD408810B0430800B605886
              40060218400695A911021708600017C0B09C9B4096EA31802C4A532704CE10C0
              00CE4061090259086000E32BFD9195B8E667C7F9372A010C605465EFEA7AF6F4
              C93B6B7E776152FDC9542C0690496D6A85C011010CE00808AF10C8440003C8A4
              36B542E0880006700484D7DC04B2558F0164539C7A21704000033880C12304B2
              11C000B2294EBD10382080011CC0E03137818CD563001955A76608DC11C000EE
              40F00702190960001955A76608DC11C000EE40F0273781ACD563005995A76E08
              18010CC020F00F02590960005995A76E0818010CC020F02F3781CCD5630099D5
              A7F6F4043080F42D0080CC043080CCEA537B7A021840FA16C80D207BF5FF0700
              00FFFFD223B5EA0000000649444154030017737C3DF6F9A8AA0000000049454E
              44AE426082}
          end>
      end
      item
        Name = 'Down'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC99EBCA65471186774C32118C67CDEFDC968A9228
              084622238ADE41A2382828FEF6D27201F1AC108C4EC67A6BBE99D9B3BF7D5887
              3E54773D326B66EDD5DDD555CF5BF522E47307FE070108A4258001A4959EC221
              703860007401041213C000128B4FE9B909A87A0C4014782090940006905478CA
              8680086000A2C00381A4043080A4C253766E02CFAAC7009E91E05F0824248001
              24149D9221F08C0006F08C04FF422021010C20A1E8949C9BC071F518C0310DDE
              21908C0006904C70CA85C031010CE09806EF1048460003482638E5E626705A3D
              06704A84DF1048440003482436A542E0940006704A84DF1048440003482436A5
              E62670AE7A0CE01C15BE412009010C6072A1DF7DF8E8A33DCFE478D2978701CC
              DF026F5B897B1E3BCE9F59096000B32A4B5D10382270E91503B84486EF104840
              00034820322542E012010CE01219BE432001010C2081C894989BC0B5EA31806B
              745883C0E4043080C905A63C085C2380015CA3C31A04262780014C2E30E5E526
              70AB7A0CE01621D6213031010C606271290D02B7086000B708B10E8189096000
              138B4B69B9092CA91E035842893D109894000630A9B0940581250430802594D8
              038149096000930A4B59B9092CAD1E03584A8A7D109890000630A1A8940481A5
              043080A5A4D8078109096000138A4A49B909ACA91E0358438BBD10988C000630
              99A09403813504308035B4D80B81C908600093094A39B909ACAD1E03584B8CFD
              1098880006309198940281B5043080B5C4D80F818908600013894929B9096CA9
              1E03D8428D3310988400063089909401812D0430802DD4380381490860009308
              4919B9096CAD1E03D84A8E731098800006308188940081AD043080ADE4380781
              0908600013884809B909ECA91E03D8438FB310189C000630B880A40F813D0430
              803DF4380B81C1096000830B48FAB909ECAD1E03D84B90F3101898000630B078
              A40E81BD043080BD04390F8181096000038B47EAB90994A81E03284191181018
              94000630A870A40D8112043080121489018141096000830A47DAB90994AA1E03
              28459238101890000630A068A40C8152043080522489038101096000038A46CA
              B90994AC1E032849935810188C0006309860A40B81920430809234890581C108
              6000830946BAB90994AE1E03284D94781018880006309058A40A81D2043080D2
              4489078181086000038945AAB909D4A81E03A84195981018840006308850A409
              811A0430801A54890981410860008308459AB909D4AA1E03A84596B810188000
              06308048A408815A0430805A64890B81010860000388448AB909D4AC1E03A849
              97D810084E0003082E10E941A026010CA0265D62432038010C20B840A4979B40
              EDEA3180DA84890F81C0043080C0E2901A046A13C0006A13263E040213C00002
              8B436AB909B4A81E036841993B2010940006105418D282400B0218400BCADC01
              81A0043080A0C290566E02ADAAC7005A91E61E08042480010414859420D08A00
              06D08A34F7402020010C20A028A4949B40CBEA318096B4B90B02C1086000C104
              211D08B4248001B4A4CD5D1008460003082608E9E426D0BA7A0CA03571EE8340
              200218402031480502AD096000AD89731F040211C0000289412AB909F4A81E03
              E8419D3B2110840006104408D280400F0218400FEADC09812004308020429046
              6E02BDAAC7007A91E75E08042080010410811420D08B0006D08B3CF742200001
              0C208008A4909B40CFEA31809EF4B91B029D0960009D05E07A08F4248001F4A4
              CFDD10E84C0003E82C00D7E726D0BB7A0CA0B702DC0F818E0430808EF0B91A02
              BD096000BD15E07E08742480017484CFD5B90944A81E0388A0023940A013010C
              A01378AE8540040218400415C801029D0860009DC0736D6E0251AAC700A22841
              1E10E8400003E8009D2B2110850006104509F280400702184007E85C999B40A4
              EA3180486A900B041A13C0001A03E73A08442280014452835C20D0980006D018
              38D7E52610AD7A0C209A22E403818604308086B0B90A02D1086000D114211F08
              342480013484CD55B90944AC1E0388A80A3941A01181D406F0DD9FFFE60BEF3E
              7CF4E49D871FBEDD8837D7042120CDA5BD7A20484A5DD2486B00EFBDF7C7375F
              FBDF2BFF16F5570EAF7FA486D03BCFFC04A4B53457A5EA01F582DE333E290DE0
              FBBFF8F5173F79F0C9BF8E055743A8318EBFF13E1F01692CAD8F2B532FA8278E
              BF957E8F1A2F9D017CE7FDDF7FE9C9A7AFFEF39C206A0C35C8B935BE8D4F40DA
              4AE37395A827D41BE7D666FE96CA007EF8CB5F7DF9C1AB9FFEE39AA06A1035CA
              B53DAC8D47409A4ADB6B99AB37D423D7F6CCB696C600DE79F8BBAFFCF73FAFFD
              7D89806A1435CC92BDEC894F405A4AD32599AA47D42B4BF6CEB02785017CFB47
              1F7EF595C3E3BFAD114C0DA3C6597386BDF108484369B92633F58A7A66CD996B
              7B23AF4D6F003FF8E96FBFF6C61BAFFF758B086A1C35D096B39CE94F40DA49C3
              2D99A867D43B5BCE8E74666A03F8DE8F3FF8FA674F3EFBCB1E41D4406AA43D31
              38DB9E803493767B6E56EFA887F6C4887E765A03F8D6CF1E7DE3D5D71FFCB984
              006A2435548958C4A84F405A49B31237A987D44B2562458C31A501BCFBFE07DF
              FCFCE3C3C72581ABA1D458256312AB3C016924AD4A46562FA9A7B6C48C7E664A
              03381CDEACC25D8DA506AB129CA0BB09481B69B43BD0D900757AEAEC550D3F4E
              69007FFAC34F3E3E3C7EF0560D8E6A30355A8DD8C4DC4E409A489BED11AE9CB4
              5EF29EBAB265D4A5290D4062B860269CDE4B3F6A34355CE9B8C4DB46405A4893
              6DA76F9CB21EF25EBAB16DD4E5690D4082B87026A0DE4B3F6A38355EE9B8C45B
              47401A488B75A716EEB6DEF11E5AB8FD74DB08BFA7360009E0029A907A2FFDA8
              F1D480A5E3126F1901B19706CB76AFDC653DE3BDB3F2D868DBA7370009E2429A
              A07A2FFDA801D588A5E312EF3A013117FBEBBB36AE5AAF78CF6C3C3ED2B11406
              20415C501356EFA51F35A21AB2745CE29D2720D6627E7E75E757EB11EF959D61
              46399EC60024880B6B02EBBDF4A3865463968E4BBC970988B158BFFCB5D02FEB
              0DEF9102E1460991CA00248A0B6C42EBBDF4A3C65483968E4BBCA704C4568C9F
              FE2AFCB7F584F746E1B0D1C3A5330009E2429BE07A2FFDA841D5A8A5E3668F27
              A6625B8583F582F74495E0B183A6340049E2829BF07A2FFDA851D5B0A5E3668D
              2796625AA57EEB01EF852AC1E3074D6B0092C685B706D07BE9470DABC62D1D37
              5B3C3114CB2A759BF6DE0385838F142EB50148286F006B04BD977ED4B86AE0D2
              71B3C4133B31AC52AF69EEDA57093E4ED0F40620A9BC11AC21F45EFA5103AB91
              4BC79D3D9E98895D953A4D6BD7BC4AF0B1826200777A79435863DCFD2CFA8F1A
              590D5D34E8C4C1C44ACCAA94681ABBD655828F17140338D2CC1BC31AE4E853B1
              5735B41ABB58C049038991585529CFB4758DAB047F1A74B4BF318013C5BC41AC
              514E3E17F9A9C656831709366110B111A32AA599A6AE6D95E0E306C500CE68E7
              8D620D736669F72735B81A7D77A0C9028889D85429CBB4744DAB041F3B280670
              413F6F186B9C0BCBBB3EABD1D5F0BB824C74582CC4A44A49A6A16B5925F8F841
              31802B1A7AE358035DD9B279490DAFC6DF1C60928362201655CA31ED5CC32AC1
              EF071DF10B067043356F206BA41BDB362DABF135009B0E4F7048B58B4195524C
              33D7AE4AF0798262000BB4F446B2865AB075F5160D800661F5C1C10FA866D55E
              A50CD3CA35AB127CAEA018C0423DBDA1ACB1166E5FB54D83A081587568E0CDAA
              55355729C13472ADAA049F2F2806B042536F2C6BB01547166FD5406830161F18
              74A36A54AD55D2376D5CA32AC1AF071D75150358A99C379835DACA638BB66B30
              34208B360FB849B5A9C62AA99B26AE4D95E0F306C5003668EB8D660DB7E1E8CD
              231A100DCACD8D836D504DAAAD4ADAA6856B5225F8DC4131808DFA7AC359E36D
              3C7EF5980645037375D3408BAA45355549D934702DAA049F3F2806B043636F3C
              6BC01D212E1ED5C068702E6E18644135A8962AE91A7BD7A04AF0E54147DE8901
              EC54CF1BD01A716798B3C735381AA0B38B037C54EEAAA14AAAC6DCD957099E27
              280650406B6F446BC802A1EE85D0006990EE2D04FFA09C957B95348DB533AF12
              3C57500CA090DEDE90D69885C2BD144683A4817AE963E01FCA55395749D1183B
              EB2AC1F305C5000A6AEE8D690D5A30E4F3501A280DD6F30F415F94A372AD929E
              B175C655826F0B3AFA290CA0B082DEA0D6A885C37A380D9606CC7F04FC4BB929
              C72AA91953675B2578DEA0184005EDBD51AD612B843E68C034683562EF89A99C
              94DB9E1817CF1A4B677A71030B5B0960005BC9DD38E70D6B8D7B63DBA6650D9A
              066ED3E10A87948B72AA10FA703086CEB24A70826200157BC01BD71AB8C6151A
              380D5E8DD86B622A07E5B2E6CCE2BDC6CE192E3ED076E30CB761009555F406B6
              46AE718D064F035823F69298BA5B392CD9BB7A8F317376AB0F72600D010C600D
              AD8D7BBD91ADA1371EBF7A4C03A841BCBAA9C2A2EED4DD1542F37FFBAB403D1F
              140338CFA5F8D7994C80E12FDE1EDD0262000DD1CF60020CFFD38699E56F0CA0
              B192239B00C3DFB8591A5C870134807C7AC58826C0F09FAA38C76F0CA0938E23
              9900C3DFA9491A5C8B0134807CE98A114C80E1BFAFDE4C5F3080CE6AD63681BD
              E5F19FFAF6128C7D1E0308A04F4D130850DEFD141E3F78CB6BBEBFC297C60430
              80C6C02F5DE703618371697D9AEF56A3D73A4D416317820104D2CF07C3062450
              4A6553B1DABCC6B2519B469BED320C2098A23E203628C1D2DA9F8ED5E4B5ED8F
              44848204308082304B85F241B1812915AF7B1CABC56BEA9E08099C12C0004E89
              04F9ED03638313249DED69580D5ECBF6089CAC480003A808776F681F1C1BA0BD
              71BA9DB7DCBD866E0994BD78C668184070557D806C9082A7793F3DCBD973BFBF
              C2974004308040625C4AC507C906EAD27AB8EF96ABE71C2E31123A2580019C12
              09FADB07CA062B687A2FD2B21C3DD7175F780B4C0003082CCE696A3E583660A7
              DFC3FCB6DC3CC73009954B64D64818C060CAFA80D9A0854BDB72F2DCC2254642
              D7086000D7E8045DF341B3810B939EE5E239854988449612C00096920AB6CF07
              CE06AF7B5A9683E7D23D1112D8420003D8422DC8191F3C1BC06EE9D8DD9E43B7
              04DA5C3CF32D18C0E0EAFA00DA20362FC3EEF4BB9B5FCC85250960002569768A
              E5836803D9EC7ABBCBEF6C762117D5228001D422DB38AE0FA40D66F56BED0EBF
              ABFA455CD0820006D08272A33B7C306D40AB5D67B1FD8E6A17C40B3C7B4618C0
              640AFB80DAA0162FCB627AECE28109D8930006D0937EA5BB7D506D608B85B758
              1EB3584002452180014451A2701E3EB036B8BBC35A0C8FB53B10012212C00022
              AA5228271F5C1BE0CDE1ECACC7D81C60EC8319B2C7002657D907D80679759976
              C6CFAE3EC8819108600023A9B531571F641BE8C5C76DAF9F597C808DA312C000
              46556E65DE3ED036D8378FD91EDF7B73231B66208001CCA0E2C21A7CB06DC02F
              6EB735DF7371439E852C9562005994BEABD307DC06FDEEE78B7FEC9BAFBDF8C2
              5B0202184002914F4BF441B7817FFEDDDEFDDBF30FBC642180016451FAA44E1F
              781BFC833DFE7EB2CECF1C0430801C3A9FAD5283AFE7EC62E28F994AC70032A9
              4DAD10382180019C00E127043211C00032A94DAD10382180019C00E1676E02D9
              AAC700B2294EBD1038A7A7FF640000008C494441542280011CC1E01502D90860
              00D914A75E081C11C0008E60F09A9B40C6EA31808CAA533304EE0860007720F8
              0702190960001955A76608DC11C000EE40F04F6E0259ABC700B22A4FDD103002
              188041E00F04B212C000B22A4FDD103002188041E04F6E0299ABC70032AB4FED
              E9096000E95B00009909600099D5A7F6F4043080F42D901B40F6EAFF0F0000FF
              FFF6D895F300000006494441540300A1DD9C2EC7C67BB40000000049454E44AE
              426082}
          end>
      end
      item
        Name = 'Add'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9D0B985C5595EFD7AEAAEE60D2818020F290C7A0
              F252D4EF5EAF8F016194F15E654451DB07215055844481749DEAAE4A401D6E71
              414852A7D25549046993AE0A89A0C4F10EFAC9780761400545EFF70D0EF80067
              2610410579046803A4BBCE9AB53B5DB1D3DDF5DC7B9F479DD5DFD97D4E9DB3F7
              DA6BFDF6DEFF3AAF3A2702FCC70498406809B00084B6E939702600C002C0BD80
              098498000B40881B9F430F3701193D0B80A4C089098494000B40481B9EC36602
              92000B80A4C089098494000B40481B9EC30E37815AF42C0035123C67022124C0
              0210C246E79099408D000B408D04CF99400809B00084B0D139E47013981E3D0B
              C0741ABCCC044246800520640DCEE13281E9045800A6D3E065261032022C0021
              6B700E37DC046646CF023093087F66022122C00210A2C6E65099C04C022C0033
              89F067261022022C00216A6C0E35DC04E68A9E05602E2ABC8E098484000B4017
              37F4D215EB8F8EA7F31FB9C85A7B5922657F89D2BAA4659713967D7BC22AFC30
              61D90FC72DFB115AFF135ABE8396B72552850D89B47D75D2CA5B9477F145E975
              A77631A2D087C60210E02E90B0F2EFA7F4D584653F4F0967A66A74CFEF048AEF
              4420B211045C43298D007100381700CFA0F9A902E0CDB4FEDDB4FC215A5E0C02
              2F0784AB10C430026C8BA0F370C2B267D9A675138954FEDB24189FEEEFCFF552
              799E0248800520008DB66CD9EA8392566175DCB27F4F036FDF60041077515A0E
              008BC0FDBF2808711E09C637FA8EEA7B759A5FAF24D285AD170FE4DFE2BE4B5C
              633D02F5D6B300D423E3E1FA646ACD8934A02A942607FBF8FCD82E045C45DFD0
              4778E856AB55CF03C40B9C8878A8E67F3C65FF20417B2BAD1AE07CEE11600170
              8F75C39AE2563E571B3028A2BFA1CC1751EA8A4908F800D0DE4A2D3E9AFFC3F9
              9FBFFE60E03FCF09B00078D404F15CF98064BA30428361F25B5E80F8DF1EB9E2
              45B51F9F37AFE7B9C9D8D3F67D4BAD35277BE104D709C002E0722FA05DE11B64
              C717BB9E7D19112F71B97AFF5587F0DE2A447F2599507A70D9907DA8FF9C0CB6
              478DBC6701684447D3B6C48AB56752E77E91129D58179FD764B61BCDBC6DBC0A
              7F929CE269FB8A6E0CD06F31B100186A9165CB6EEAA18E4CD7DB6D8468E41EAA
              6621259E5A242010AE277EF2F0E8DF2F1EB28F6DB118676B9340A4CDFC9CBD09
              01B90B9BB00A7F1C9FFFD21ECA4AD7DBE93F4F2A044E70AAF058C2B23169E5CF
              5631C4656713600198CDA4A335F1F4BAB7262C7BB7DC8505C0C33B32C2851A12
              4010771263A4C38354C38CBC711F81660B2C00CD0835D91E1F287C58764A81CE
              BF51D6D750E2C930013A3C284AE671CBDE68B8AAAE37CF02D061132F4DE54F93
              9D5044F07B1D9AE0628A0404C065B20D1269FB4B8AA6425B9C05A0CDA6DF7B8C
              6FBF5415E2176D16E5ECA608205C2385203E58F8B0A92ABAD52E0B408B2D7B56
              2E174B5885C7F71EE3431FF09FEF080807BF97A09385F181B56FF29D731E38D4
              4A952C002D504AA4ECD1E377F58DD3C9BD635AC8CE593C26202291471396FD3B
              8FDD0844F52C000D9A497E935047A293CF906890CDCF9BFE8C80F791839B1071
              0DA59514CCC520F063C28133A2103D4526B90C0E7E8CD627014416115603C008
              80B81704BC00C1FC3B5AB61D9D1F4807D37D77BC8EB8534DF06AA16FFD87E437
              89CF3DDF03286E7100FFAE5CCC8839525FA5983D9DD65F522965AFA094AF1487
              46CBC3D9DB47D7677EBCA998FEB54C72B9BC3E7B3BAD2F978B4376A594B992CA
              2CA7E5B3CAC39945B43CCB36549DB3688FE826E2F32225FF4E08EB48085E59BC
              2277A07F9DF4CE33168019ECA9B37C921282007FFD9E1DF115F2E9DA9EDD13D3
              07E4BC726968F19662D6F52B11E50D2BEF2D17B39F2B173307519A14889EDD0B
              7B692F620520FC710656AF3FCEEB8DF6BD40970D6FF6DA11B7EA6FB51E168069
              A4E2A9FCBFD3C7ED94FC303D0320B2638BC6E64D0EB052F635F46DFCF7232357
              F876977C6464F9787938BBB15CCA1C31E933ED9500C0F9B4A7F06B9A7B3ED165
              C32524EED5FE1C3FC1A8D6182C004462F18A3593C78B428813E8A387133E2822
              E2ED5383E730DA05B7B7E772F296620F7D52AB9A62B9B55CCC9E5226311887E8
              9164ED0794BC9C227DBBFA5E4D5AF6622F9DF04BDDA11700FA4628F646A39E9D
              3146801F4663F8577280948BD9778CAE1BEADAFB0BB615D37F2817337F4B49F4
              44E13081F87DAF060271DF466D2F1FBCE2950BBEA837D402401D608C5AC193FB
              CA11C5A7E440A81433676EB2B33BC88F504D2385CC33A3A5EC8724031091B368
              40BEEC0100F9E8355C92C9BFCE83BA8D55D98EE1500AC09281D5C7D0E0A73E07
              0BDA81A521EF43AFBE3A7E88ECF495D2905FCE3568084BCD447978F05E12C2F9
              3B168DF500E21D6AD6DA2F1D9B104F25070B9F68BF64F04B844E0012A9C2402C
              127BDCCDA623A5A994E91898D269B7DC78E5F36ED61DA4BAEEC9E526CAA5EC39
              C449D0958441377D4707BF954817B6BA59A71FEA0A9500C4ADFC8FE93255C92D
              F0B5814FDF6E09B7EAEC967ACAA5CCB0140244B8CCB598102FA04B85BF77AD3E
              1F54141A01A05DFE170588BF7683390F7C7D942BA5CC0D5208E884E1527D56EB
              5B120047505F41F944A7FAB9FCBBA55DCF422100B241098C1B8FE47A487656FE
              C627DA9A273A61B859B2050105CDA6E734279FE8F4D921BBEB1F50DAD502D0DF
              DF1F9D1AFC7336B2CE9562A27A1475D0D374DA645BB30994873399727128427B
              594FCFDEAA77CD0155F8D3C59775F7F308BB560092C9350BFB8E7AD784DE2E31
              DB1A020ED1C017A31B5785EAD871360937D708A4BDACC3C1317F48E7F4C06389
              15F6296E46E7665D5D2900F2BA2E1E1835FD239527E4C0AF14B3EBDC6C30AEEB
              2F04CAEB87EE976D4022FCCF7F596B60290ABF8CA7EC771AB0ACD56427C6BA4E
              00E423A4E575DD4E60B451663975BC37B4919FB31A244022FC3F05564F325805
              08013FA3AB486799ACC30BDB5D250017A7D71D221F216D10E41EF98B371AFC23
              06EB60D31D10182DAD7A84DA854EE283FC415707169A171120FE253958785BF3
              9CC1C9D1350290CBE5620E3ACF9A432F6EA20E364FFEE2CD5C1D6C599500B5D1
              9B22807FA76AA75E7974F0C12503C5AE793254D708C0E3938FECAAD76C6AEBAB
              1171229D79FE9C9A152EED1681CDC5ECF748088CF5ED5864E271799EC9AD785A
              A9A7D33CC62075EA5027E54C5EEADBB168ACE7E675438F76E21797F19400968B
              19411E18B9ED5B9E678A5BC38BC87EA0A7C00B40C2B2E992B09136983CCB7F4F
              2E67FC52A211EFD9E824011281E368C1C8EDDF02AACF07FD8EC1400B000DFE57
              A9714D4C23D471F82CBF09B21ED8A4B6B45044DE67A26A79C7A009BB6ED90CAC
              00D0E0FFFF04A99792DEC981387598E57A8DB235AF095486077FF44A140E33E1
              87D73F20528929900290B00A190AFABF51D23A09117967797D668B56A36CCC37
              046E2D649E19DB33A6FD372174A2E188A0FE94387002B0C45A733200E675F7AA
              EAB83871747850EE55E836CDF67C4460FB0DB931DAC3A331ABD929C40B92017C
              A848A004802EBD2C8841F4579A9B0EE4537A6EFE0A9FE9D7CDD5CFF64C88003A
              F82DEAA3817ABC58A004802EBDC867F869ED57B223F0537AB4220D8C31D9F6BA
              9DA53EFA946E9B8DECA96E0B8C00D071FF3DAAC1CE2C6FA203CCAC833FFB9B80
              893E90B0ECC03C6D38100290B4F2EFA1E3FE337576A5BE6AEF013AEDB1ADE012
              3020022706E5BD038110000471BFCEEE151191D76ED83060EA1E029DAEB22D97
              081CBB682CAAB32A04D8D61F803710F95E001296ADF755581171CCE6E1C1E774
              3636DB0A3E815C2EE7F4CC9BD07A6B6FDFAE3EA3EF3AD041DDD70290B0F2D752
              900752D2324D40F594F2BA21CFDE02A4250836628CC0C89A2B5E88567B75DE01
              1A49A4ED8A31873518F6AD002C5BB6AC07407C1134FDA1802F6E2DAEF2C54B2A
              3585C4660C10D8B461E009327B3E253D13C245FD97E6FAF418D36FC5B70230BE
              E0CD7FD218EE2F2AC399EB34DA63535D4C804E0ADE4AE17D8B9296A9AF77A16F
              2F0DFA5200E2562109080769A10FF03235E8DB35D962332121407DA69F42D5F4
              E4619C4FE7B296923D6D932E43BE140001B8595780D490F375D9623BE122407D
              E7708D117F4DA32D6DA67C2700A4943B754517C5D8EB75D9623BE124D0B37B4C
              DB0B64E9A4B6EF6E10F29500C407D6BE89BAD91B28294F0878CDA692E5DB632F
              E500DB3010B7AE3F4E25B55155D7651D19C9ED16282ED2139838F1026BF8083D
              B6F458F19500884844D7A3B75EA814B357E941147C2B027A76A8A4E013508B60
              B434743359789C92F2D403D51DAA467496F78D00C4070B1FD615181DBB69BDA1
              43975F6C27B804A84FC9478BE908605E72C03E5D87211D367C2300C2C1EFE908
              48006813121DFEB08DEE21A0EBE52318811FF9858A2F042091B6BFA40588805F
              8D1633FFA4C5161B61023308C8978FD0AAEF50529E9296BD42D9880603BE1000
              40B846432C501ECE9CAAC30EDB6002F508D0A1C047EB6D6B673D02AC6F277F2D
              AFEEB9E70210B7EC8D3A82420717EBB0C3369840530288EF6E9AA7850C09ABE0
              F9DDA99E0B001DB35FD602AB26597077657DF6962699783313D042A05CCA3E00
              801A6E55C72BB538A460C4530188A7ED9482EFFB8A8A5EE7F5FB3EF002137081
              C08E457F3E52473509CBF6F416614F0540201441F94FDC3EBA76D54BCA66D800
              136883C03D7BDF18B5A98D22F5B2B67C8B703D032AEB3D1380A4953F5BC5F15A
              D97271E863B5659E33013709948B994B74D4971C28FC8D0E3B9DD8F04C0010C4
              9D9D383CBD0C026AB97A30DD262F338176083808F22535ED149995172378F7AC
              952EADF044002E1EB28FD5111FDFEEAB8322DB5021B0A59429A894AF95D53526
              6AF65A9D7B22004E15EE6AD5C1FAF9C4F5F5B7F11626E01E011D7B0134267ED0
              C86353DB3C11000AE6044A4A131DFB7F41C9001766029A0868DA0B78A32677DA
              32E3BA00D0A5BF2BDAF270CECC68CFB99A5732018F08E8D80B48A4EDB4DBEEBB
              2E0074E94F79D7BD5CCC66DD06C5F531814604B4EC0520AC6B5487896DAE0AC0
              B221FB500D413CA0C1069B6002FA09A0F8BFAA46E3D6F0AC9FB2ABDA6C54DE55
              0118AF82F2898EB13D635AEE1F680485B731814E08944B431FEFA4DCF43202AA
              774CFF6C7AD95501A060DE4649659AD87E436E4CC5009765028609A8BE75EA3D
              86FDDBCFBC6B02B0D45A73F27E3577F0C111CE391D14E3224CC035028E88BC4F
              B5B22597E78F57B5D16A79D704A02AA2CAF74D6F195EF9CFAD06C6F998801704
              B60C0FFE52B5DE580CF68D15555BCDCABB260080F0DE66CE34DA2E10BFDF683B
              6F63027E21804228BED742BCDFAD585C1180F33F7FFDC1AA01C5626289AA0D2E
              CF04DC20F06710CA8FFB4A26D72C74C357570460DEBC1EE55D9A9142E6193780
              701D4C4095C0F6E1C197556D3807466F54B5D14A795704801C51BD3CA27CF990
              7CE08909B84840DCAE52990058AC52BED5B26E0940ABFECC996F1CA217CEB981
              5732019F12880891F4A96BFBB9655C0092E9B51FDCAFC60E3E6C2BA6FFD04131
              2EC2043C23B0797850F57E0048A4D79E693A00E3020018F9A2521008BE7BA1A2
              523C5C383C0454FBAEEAD86981B471014000C51B23F0CB2DC4C15998800F0974
              DE77A782F9DBA9B9B199710150F5BC5CCA6E53B5C1E59980170482D0778D0AC0
              D254FE342FC0739D4CEB9EFF6E0000100049444154A05B0824536B4E34198B51
              01981062A5A2F34F2B96E7E24CC06B024A7D184554750C358CDFA800D0B5CC4F
              36ACBDC9463A7F706D932CBC9909F89A40277D78BF80103FB3DF67CD1F8C0A00
              F93A8F52C753EFEE855FEDB8301764023E20D0BBFB51B53E2CC47C9361981600
              25DF4746968F2B19E0C24CC06302232323BEEEC3C604A0BF3FD7EB317BAE9E09
              740581FEFEDBA2A6023126007D472E3C4FD1E91715CB737126E00B0202E1F956
              1D992BDF82A3767E74AEF53AD619130000E7D36A0EE2AD6AE5B93413F0070147
              C02D2A9ED0C9F44FA9946F54D69C0008716EA38A9B6EABB2003465C419024140
              384249002848D5BD693231F7644E0000948E5BCA1B56DE3BB7CBBC9609048B40
              79FDD0FD8A1E1B3B9F6652001463E6E24C205C04BC889605C00BEA5C2713F009
              0116009F3404BBC104BC20C002E00575AE9309F884801101B828BDEE54A5F804
              BCA0549E0B3301FF1168F884A066EEC687EC939AE5E964BB110188A2F3F64E9C
              D95706C583FB96798109740701A53E2DAAF00E13188C0800001EA6E62C3EA256
              5E7FE9B875FD7109CBC62026551A418B59B6956ACCFACB8BDFAAD844075EA752
              BE5E592302804228BD080411947697EA05CBEB9980570404E2B32A754722A834
              A6EAD56D4400C01187D4ABB095F542082558ADD4C17998809B049C067DBA153F
              1C501B53F5EA3022002814D54A382C00F55A8CD70794405569AF56A008CE1E80
              0050DA03802A28C10A680F61B7BB99405575AFD6511B5375D81AD903000425B5
              12A00AAB4EB4BC9A097844408888DA5EAD08D01E000AB53D804824AA06CBA346
              E66A99403D02424CCCD9A7EBE59FB55EF14B7596BDA91546F6000480AF1F8334
              153BCF98806B04C631D2A35899A3587ECEE246040040281DC33B4EF5B5C07F4C
              A08B08F40AB5B3F874625DE9A942F5501A1200547216A3C80250AFC5787D2009
              6024A2D4A785E2976A3D6846044080DA597C443558F582E5F54CC02B0288CE2C
              0168D317A5BDEA7A751911004450DA03007558F5E2E5F54CC01302886A7BB508
              A836A6EA446D4400A82E55B552554B72812726E0270242A94F4720A23AA6E684
              6144001CE128A995106AB0E68C945732010F0908014A0280A836A6EA856E4400
              84103BEB55D8CA7ADADD39B9957C9C87090488C05BA7FBDAEE320AF144BB655A
              C96F44006213F3FEB595CAEBE51120D49E2750CF30AF6702DE1150EAD3D12828
              8DA97A611B11804D1B0654D56A413D87BD5A5F295EF958B99811414CAACC8216
              B36C2BD5980D9457BA11687321F3B8019FC088009870946D320126A09F000B80
              7EA66C91093424E0A78D2C007E6A0DF68509B84C8005C065E05C5DF808F4F7DF
              16F56BD4260560974AD01759F97354CA735926E017020B8EFCDDC7157D511A4B
              8DEA362800F8CD461537DB16C1C8F9CDF2F0762610040202E0B3353F3B9BAB8D
              A546751A1400B8AD51C54DB709FC64D33C9C8109048180C08F2ABAA936961A54
              6E4C00CAC5ECDD0DEA6D65536F2B99380F13080001A571A6612CD545A4E4585D
              ABBC810930814010F0B5002C5BB6FAA04050642799401D028915D7ED7B4B569D
              2C9EAE362A0008F00795E8C617C4322AE5B92C13F09C40B467A58A0FAA63A859
              DD46052002E2E6660E34DCEE200B404340BCD1FF04444AC547BA82B055A57CB3
              B291661954B6C7768F5FAF521E843840A93C176602DE1350FA111042546D0C35
              89DFA8008C8C5CF14293FA9B6EEECFE5F86A40534A9CC18F04D2E975AFA9F9D5
              E9BC524C1BBB0948FA6454006405AAA96FD7C201551B5C9E0978416097E30C79
              516F3B75BA21005BDA7168765E5C357B1DAF610201202020ABE425E22D4AE55B
              286C5C000456558F610E6D210ECEC204FC48E04015A72208AA63A769F5C60560
              B4B4EA91A65E34C99048E5DFD5240B6F6602BE22104FAF3DA3E650A7F3CDEBB3
              0F775AB6D572C605A055471AE613625BC3EDBC9109F88C80C0A8DA257097E271
              450010F06AC578DEA8589E8B33019709E0718A15AE552CDF52715704A052CCE6
              5AF2A641263E0C68008737F98A407CB0F06E5587C69E7CE00BAA365A29EF8A00
              B4E248D33C7C18D0141167F00701E1E0BEBBF73AF568FBF6EDD54ECBB653CE35
              0110427CAD1DC7E6C8CB87017340E155BE24A0DA576F752B2AD704C039E810E5
              1B7AE229DB95DD22B7E0733DDD472099CE6755A312BDD5E5AA365A2DEF9A0054
              7289575A75AA5E3E21E0CBF5B6F17A26E007028842F9E4DDE8DA552FB9158B6B
              02B03720BC71EFBCF3FFC9D49A133B2FCD259980390289C1C21BA65BEF641901
              BEDE49B94ECBB82A00E562F6D24E1DAD954311FD716D99E74CC057041CFC91AA
              3F9562E602551BED94775500A61C53DDBDE15B83A740F2CC77048E55F30877AB
              956FBFB4FB0250753ED2BE9BFB974858F6BFECBF863F31016F0924ACFC3FAA7A
              E04422E7AADA68B7BCEB0250DEB0F2DE769D9C23FF5973ACE3554CC0430262BF
              477F77E2C89675437775524EA58CEB0230E5EC77A6E61DCF782FA063745C5033
              01EA8B4A2FC19972E7BB537357679E0840CFEE853A5EFAC17B01AE7615AEAC01
              814F35D8D6D2261A139F6829A3E64C9E08C0C8C8F27100F11428FE91F2F2B900
              45865C5C8D40D2B275FCEAEFE9BD6342CD974E4A7B2200D2D19E28BE45CE1513
              EF052802E4E26A04E8BAFD929916DAFD3C11C3B7B65B46577ECF0460A4907986
              82789992D294B00A7F5432C085994087041229FBD71D169D5E6CCF563BFBF4F4
              156E2E7B2600324814110D4FFAC1C39356FE3DD21E2726E01681B8357C1C0838
              49B53E44385DD5864A794F05A0323CF8908AF3B5B208E2FEDA32CF99801B0404
              5477E8A8A752CAFC5C879D4E6D782A00D26974C43972AE9AE296CD8F0D5385C8
              E55B2290B00AD7D6CBD8CE7A14F8D976F29BC8EBB90054D60FDDA1233001B058
              C78B1874F8C236BA9D007E51478495E1EC3774D851B1E1B90048E7A3886F9373
              D5B40B9D17556D707926D088403C957FAED1F656B76155F8E2BC952F04605329
              FB6F046E8C92EA14A34381CDAA46B83C13988B40C2CA5F29843878AE6D6DAE7B
              B9B261E8A76D963192DD17022023EB89C2F172AE9AE85020A9E377D9AA7E70F9
              EE22B024935F0020AE83067FAD6E8A624C4B5F6FB5BE46F97C23007BEF0B103B
              1B39DBF23607F5D869B942CED8ED04621342D7E1E5939B4A96F25DB0BA78FB46
              0064403B16BD74829CEB4889B4FD4B1D76BAC106C2F8F12AA91B18A8C490B06C
              7958A965ACF4EC7ED437DFFE928996A0A4211DE99E5C6E4220AA3E3D78AF2B08
              A72453F98BF77E08F7FF4AF1CAC7545298E95D38587833C59FA4A43E21944746
              46C6D50DE9B3E02B0190618D96B2CBE45C474221365D985E77940E5B6C237C04
              CECAE56251075B7AB725B4F0572E65F408490B75B59AC57702201D8F56ABCA0F
              579476648AA2F3849C736202ED12387E579FB66F6B741CB927D1AE0BC6F3FB52
              00366D582507ADB6877F262C7B8F71925C415711A03EF33B6D01213C5C59BFF2
              B7DAEC6934E44B0190F1958B9933E45C53EA89A7B4FC724B933B6CC6CF0468F0
              DF44FE1D4D49CB44BBFE6FD562C88011DF0AC064AC88CA2F599CB443FF848093
              E25661981679620275092406F209DAD8D67928CADF68EA6FB4D1EB6DBE168072
              29FB8000719F2E4802D04AA4ECAB74D9633BDD4520B162ED991011A31AA37A84
              F664BFA5D19E7653BE160019ED6871E87439D796045C1D4FE52FD1668F0D7505
              818BD2AB4F8568E41E9DC1D0E0577E5E804E7FE6B215996BA5DFD6214475DC7F
              BD2F2C21C4487CB0A0EDF0629F615E08240179EB7804630FEB743E8AB1D7EBB4
              67CA562004A0524CEF1202AED4094138F893C40AFB149D36D956F008F4A7D7BD
              06146E1D9F336201D76EF2D1EDBE73FA38B5321002207D1D1DCEACA6B9DE7BA8
              A3F0CB4BF6DEE945A6790A1B81FE5CAEB70F1DBDAFE3427CB63C9CF9FBA0B00C
              8C0048A0744CA57DB76AC2C14792E975FF5DDAE7141E02E75F71FDC17DBBFA5E
              D51D319DB80ED4BB2B032500B2B12222F25A39D799109D9FC707F29FD169936D
              F997C0D215EB8F9EF74A8F96077B4C8FB2270A874DFF1C84E5C009C0E6E1C1E7
              1C843375C31511716BDC2A0CEAB6CBF6FC45207EB97D5235BA47CB5D7ED32313
              E87C72EF4FDAA7AFF5FF72E0044022DD52CAFC1001745EAF9566410016E256BE
              30F981FF751D81A4953F5BC440C7B3FC67B2F9E66869E53FCC5C1984CF811400
              09B652CCC89FFA3E269775260162906F1BD649D41FB6A4B023883B0D78F3349D
              9B0AECE16360054036248137F27005BAE47852827F40241177458AA7EDFF94C2
              6E2218EA83879BB0EB96CD400B8084440D20E4DC40EA2111407E9E8001B22E9A
              946D2810B47F51C8100CF63D69DE9514780190944C36847C9E4032C54F16929C
              8394965C9E3F5E0E7E533E9BEC73A67C9ECB6E5708800CCC6483C8270BF13306
              25E560A4B8656F8CC5C47F9AF2766CD1D83C53B6DDB6DB350220C19914014038
              457EA3C8FBC6655D9CFC47E0AC5C2E466DF40A1D135E0686FEAAE3071CBA3D97
              EB9A07CC749500C836372A02B2020777D237CC66B9C8C93F04E2562179FCDE47
              7819FB768E8CC371377FE5F267FD13B5BA275D270012896911A06F9864C2B2C7
              F95D8492B6F789DA62A700342ACA7BAABD076DFE4AE671EFA3D5EB41570A8044
              645A04A88ED82E7476C72D7B1B2DF3E40101BAB66FD1E047AA5ADB4364C9D6AC
              69ECC963625FDF30A0EBC520B3EC7BB9A26B05404275410480F60616CB4E98B4
              F2BE78D9A38CBBDB5362C5758725ACC2840061FC116FB20F6DDFFEA96AB732ED
              6A01908D261B50CE4D2704713F75CA3F9AAE27ECF61329FB4710ED7D1A00A3A6
              59CCD5774CD7E9B6FDAE17000974AA21B5FF0044DADE3FE1E109CB463A2CB877
              FFF5FC4995005D86B5255BDAE5D2FB88B8B91D7B76AACFCCBDB58BD686420064
              7B51831E23106E90CBA69300789FECAC092B7FBFE9BABADDFEBE818F30E446AC
              02C5F7A9AF04EA37FD2A5C42230012D26829731902FE8D5C762789F7EC1502FB
              67EED4D73DB5B83DF027C9217E6EB434F4A1C9E590FC0B9500C836AD14B3F7E8
              7EC8A8B4DB24BD734A089EBF30953FAD49DED06EEEBF34D7479C7E4A8974DA9D
              6FFC1AEC0927766CB994952F04A9AD9A35EFC615A11300D988F221A3B49B477B
              EAA0F71983D278E3B4282AC42F64078F5B85C03C37AE7148EA5B2F4AAFFD2031
              19EFEBED7B89ACBD8B929BD3CBB22F6C5D6FED74B352BFD4154A01A8C1A7867F
              BDD0FCB4E19AED667301F87FA8D323A5DF86F111E5CB86EC4393A9FC3F51FC18
              C1C8FF235E314A6E4FA3D407E6BB5DA99FEA0BB500C886181DCEACF6E0904056
              5D4B6F9C7C44395D3D4858851DF1F4DA336A1BBA6D7E81357C44C2B2EFA484E3
              55F8130AF1BFBC8A5140E4041AFCF2A13210E6BFD00B806CFCDA2181D0F81A32
              69B7FD84C7098CFC500E104A2F2652F6554B32F905EDDBF14F89442A7F01C5F1
              6B8A077BA0FA7BF2EC6C4A5E4EBFA7812F468B836DFD5AD04B874DD6CD02308D
              EEA87C0D19A25FDE18B490AE795F1D9B106372F0501A9F3C33BEE23ADF3E7976
              D9B2653D71CB5E41BE3E45491EDE2008B11504F8E41559E2521AFC474D6BF2D0
              2FB200CCE8027426F801EA248256FF98929FA618C86BE1D1DEA76B838BE6D544
              AAF0ED78AAD0DFDF7F9BF13BE3A6C3480C14DE4B837D6332653F477E4C0EF6F1
              F96FDE43E0D653BED751F2D12476CA362D17876EF4D3C7B15D000004AF494441
              549153BE7025E20B2F7CE804759833A2D5AAD11F9968083B0202CF13026FEB3B
              6AE7446D204E9BEFA1E59F51DA1C4FD96BE3A9FC2A5A5E9A4CAF3BEFE294FDBE
              2503F9B724536B4E9C1CCC2BF21F895B6BE371AB304883FACB09ABF0D58465DF
              45E9594A93037CFA1C22781F0DF6CB5080D6F7366A60B2BF09DAA3A3817FECFE
              2BF9538D40A4B6C0F3D904366D58F50409018D2FFCDAECAD8158D3435EBE9352
              92AE76648510AB69F96B88CEB71D01F7C622E22114D1DF4C0EE6A8F88E804899
              AE4E1468507F01009703C0FB291D422988D3DDB2EDE41E9DAAF3DD5C9E05A085
              D61D2D6597F5EC7EB497B23E4989273F13407C56BC583D9006FF07FCECA65F7C
              630168B125464646C6A9531D1DC5987C3FE1CB2D16E36CAE1110E8549D37D237
              FEA1A3A3ABE40D45AED51CE48A5800DA6CBD4D25EB291282F95815FCFBFF36D9
              99CA8EC2F9101DE747B66C58F91FA6EAE856BB2C001DB66C65C3D04F4908040A
              FC6C8726B8983201475ED61395E195DF573655C740B7AF6601506CE1CA70F61B
              934280F03FC854D73C2D9662F1ED148988B325F37271255FD6536C2516004580
              B5E29552E6E7D429E74DC450BE2AEAE9DA7A9E6B233026B07A1231169BD70DDD
              A5CD6AC80DB10068EE005BEDAC7C59E4E13DBB17CAAB06DFD56C3E7CE610EE17
              BD9367F5178E96563D123E006623660130C4776464B9BC6A70AEFCC672689795
              AEABEF365455579A45800B25BB7229F3D7A36BBD39ABDF95606704C502300388
              898F5B6897B55CCC2E281733823AF6D74DD4D11536FFF26D2F2AC5CCD6AE88C9
              E741B000B8DC40D4B12F289310C8DD5AAAFA564A219FF0EE8909FC2BC984BFED
              DDEF0A2C00EE339FAC51EED652A73F9F92187BF201F9308CB5931B42F04FEE05
              4DDDAD27CAC5EC07B66ECCEE0841D8BE0C9105C007CDB27DFBF66AB998594589
              06843C4C70DE416EDD46A95BA63B413867D5E2937B417EBF5BAF5BC0378B8305
              A019210FB6578A2B1FA4C1F2694A938270C001F3E50F72D6D237E71F3C70A7BD
              2A11E5C9CED1DA25BBA9183E581E5EC9EF4A688FA42BB959005CC1AC56C98DAB
              2F7D9E06D22AFAE63C92E693A220E77465E103946E22EBBB28B93DC99B9EBE49
              A2F489B1278F89497F265369F264E7C5A37CC9CEEDF6E8A83E16808EB0F9A350
              B998BD9BD2E7CAC5CCC194F609436D391285E368809E07882B0488AB10B0489E
              6FA1F45D5ABE0F107E45E937F4F92794E70E40B10D013608C0ABD1010B00CEC7
              289C5CB337633E8F3E7F8644E9DBDDFCEE3C62D0D5130B401737EFE642E6711A
              A0FF582E65378E1687AEA914B3691AB4714AE7D2F2E9E552E6544A7280BFB75C
              CA9E532E0D2DA9143303A3C56CAEB23E53A27CB7560A1929105D4C697668615A
              C30210A6D6E65899C00C022C003380F047261026022C00616A6D8E9509CC20C0
              023003087F0C3781B045CF0210B616E77899C034022C00D360F02213081B0116
              80B0B538C7CB04A611600198068317C34D208CD1B30084B1D539662630458005
              600A04CF98401809B00084B1D539662630458005600A04CFC24D20ACD1B30084
              B5E5396E264004580008024F4C20AC045800C2DAF21C371320022C000481A770
              130873F42C00616E7D8E3DF404580042DF0518409809B00084B9F539F6D01360
              01087D17083780B047FF5F000000FFFFC43456D7000000064944415403008F5D
              D8A61168392A0000000049454E44AE426082}
          end>
      end
      item
        Name = 'Cash'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9D5F8C5C551DC7CFD94AB1D8625F344202691FF0
              4DDF140224A88FC2839800092AEC341104829DA5B3185013129146BA656725FC
              4F3A8B080990880FE2A3480204F44DDFF4A10D2462F405DA4A6D4BF7FAFBCDCE
              C8763AB333F7DE73EF3D7F3E9B397B67EEBDE7777EDFCFEFDCEFCEDC99BD3367
              F881000492258001245B7A8443C0180C805900818409600009171FE9691350F5
              188052A0412051021840A285473604940006A0146810489400069068E1919D36
              81A17A0C60488225041224800124587424436048000318926009810409600009
              161DC96913D8A81E03D84883FB10488C00069058C1910B818D0430808D34B80F
              81C408600089151CB9691318558F018C12E131041222800124546CA442609400
              06304A84C710488800069050B1919A368171EA31807154580781440860008914
              1A9910184700031847857510488400069048A19199368149EA31804964580F81
              04086000091419891098440003984486F5104880000690409191983681CDD463
              009BD1611B0422278001445E60E44160330218C06674D80681C8096000911718
              79691398A61E03984688ED1088980006107171910681690430806984D80E8188
              09600011171769691398453D06300B25F68140A4043080480B8B2C08CC420003
              988512FB402052021840A4854556DA0466558F01CC4A8AFD201021010C20C2A2
              220902B31248C600BEDBFEF945F3EDFDBB6830F07D0EE85C9DF5002EBB5F9406
              D06A1FB86FBEBDF451ABBD940DDB79E6FC7F5873DE611A0C7C9F033A5787F3B6
              BFDC7BE03F3AA7673DD8F3EC17950108ACB7A565C6D887AC31DB0C3F10888180
              B5171899D33AB7A5BD6D1CFE446100F2D7FE7B02460E7C73B943368482808F04
              2ED7B9AE73DE4572C11B80C07851FEDAFFCA050C62402014023AE7F7B4977E57
              36DFA00D400EFEC302E04669DC20901C0179CA7BEDE018F8BFF6BC7782358081
              FBEDCA2B98FD211019815D62022F16D514A401E8EB1F75BFA2A2E90781C808DC
              A8C744114D411A80BEFE2922963E10889540D16322380390A73B4EDF06897542
              A02B3D02458E8DE00C40CACA5B7D02811B04C610C87D6C046500ADF681FBC688
              66150420302090F71809CA004C667E32D0C902021018432033F6A763564F5C15
              9601F43F1239510B1B20902C81A170391998EB23F06119C050254B0840C00901
              0CC009468240204C02C118409DFF23EDA094472406CD98D81898107EF21C2BC1
              18C0A7CCDCF921C0D71CB79DDAF6A55EB7B39B160F037BF4CC97B5B63EB6D19C
              F21C2BC118C0A8489F1F3FFEF85DC77DCE8FDCF2133874E847C7F2F7F2BF0706
              E07F8DC810029511C0002A434B6008F84F0003F0BF466408818904CA6EC000CA
              123CB7FFD17357B1260E02D98771E8F8440506F0090B27F7ACB5852FCEE02401
              82544820BEDA62008EA7CBB193C7EE711C92709E10387EEAF83E4F5271960606
              E00CE57AA0971F7F80B700D75144F7DBB7DABA008C01B8A038889159FBCCE02E
              8B4809C456630CC0E1445D5DDE779BC37084F290406C35C6005C4D326BDE7215
              8A389E1388A8D61880A3B9D65BEE5CE52814613C27E043AD5D21C2005C90B4F6
              05176188111081486A8E01389873BDE57DDF71108610011188A5E6331BC07C7B
              79E77C7BFFAE322DA0FACE9EEA99539F9F7D67F68C8A4004B59FD9008CF9EF4E
              6BCE3B5CA2BD1655F1454C66CD5DBD47EFFFB7DCE5962001ADBDB5A653B77497
              E3E5300097C3861F2BCBB21756973B8F87AF040565081C5AEE1C34997DA54C8C
              26FB6200C5E81F595D59E4757F3176D1F5EAADECFBB688D2CB9FC922AC1B0690
              B75EE2F67AA9AFBCDDD83F6E023A27F45961682A31801C15D3D77B03B7CFD18B
              5D5321A0CF0AF5BC50957A5DC7C60066252A677CFBAFF766DD3FA2FDF6DC73F0
              EBF3EDA55FB6DA4BEF4ACBA6B477755FED13118299A5F4CF0BC95C99B943C33B
              6200D30A60ED0BF2F4CEEA19DF69BBC6B2FDD6F6F255ADBD4B7F1A1EE8D95AF6
              076BCCDDA2EF1269D36E97E8BEDA67D85F62BD796BFBE1ABA6758C65BBCE159D
              3346E68EEF9A30804915B2E62D2D622C1FF8982473E3FAF9BD4B4FE8413B67CE
              BC61ACF9CAC66DA5EE5B73E59C997B4363EB18A56205D459E78ECE2161E9EDFF
              89600023132AB3F6192D5A4C9FF71E9178CEC356FBC01FF5E094731C3F3867A3
              E3153A868EA5633A0EED6D389D4B3AA7746E9549B28ABE1880C9F43A6F4F1F3F
              757C871629B67FF7DC6CD2C85FE387F56034C65E636AFFB1D7E8D89A43ED4337
              34A0CE2D9D633AD7ACFCA191348E4A6BF49692011CB147CF5CA80538BB2DEE94
              C7B7C778B5974933EB868547B6E9C167AD599CB44F5DEB3507CD4573AA6BCCA6
              C7D1B9766879DF6D32EF3E2BCD6E6CDB4E6DDB21F9D5F69982940CC0C4FAED2E
              326166BEB5F61EBC7D7BB6F6D1CC1D6ADA5173D2DC6A1ACEDB61EAFE56A9A40C
              C0DBAAD794586BEF81578DCD9EAC69B8FCC3486E299D1BC803A8AA7D3180AAC8
              7A16570EFEBF196BBFE9595A63D29173037B97DE1FB381551510C0002A80EA5B
              487D8D2D07FF65BEE535311F6BBED0CF79E20E6C704500037045D2D338AD80FF
              9AF69FB578CA3596B43080582A394647FFF5B4FC351DB3298C55D65E2626F06A
              18C9569765959131802AE93618BB2567FB4D23EFEF1BB73F72DE625D8BDBB044
              5B278001AC7388EAF70DF23EBFD767FBF3D2967707FA9AF2F663FFA9043080A9
              88C2DB41DF530F2FEBCD338E51D3E68AEBD98A01D4C3B9B65162FE686DCCDA26
              4D90AAD763005513AE39BE7EB4B6E6216B1B2E666DB5411C190803180112F2C3
              FE59FF9005CC907B0A1A67C0E06C170CC0194A1F0235F15F7D75EB4E41637D4C
              3180FA58573A92BC3E7EA2D2013C0A9E8AD63A9063007550AE610C797D5CF9C5
              3C6A9031D31029699D0948899D308012F07CE99AD2F5F686CCF5BA85C3FB2C8B
              13C0008AB3F3A6E75C36F7B037C9D494C85C7666B9A6A1A21E060388A1BCD65C
              19838C5C1A5C5EB434D7C0F5EC5CD72818405DA41907021E12C0003C2C4A9E94
              52FD020E6594B276D5EFA261002E283618636D2DBBBEC1E11B1D3A65EDAEC063
              00AE483614C71AF32D93E84FACDAEB2C27065027ED6AC69AE5EBBAAA19B9F9A8
              296B77421F037082912010089300061066DDC81A024E0860004E301204026E08
              D41D0503A89B38E341C02302188047C5201508D44D0003A89B38E341C0230218
              8047C52095B40934A11E036882BADB31DF731B2EA868296B7752280CC009C6E6
              8264C6FCD624FA93B2765725C7005C916C28CEDC9C7DA5A1A11B1F3665EDAEE0
              6300AE483614E7D023FB5E6B68E8C6878D497B53303180A6C8332E043C208001
              785084D22964E6ADD231420B90993F8796B28FF962003E5625674E6B76EDDE9C
              5D82DF7DCD6E59085E84070230000F8A50368567BBF7BE59364668FD9FED2E44
              A3B949F6184093F41D8E9D65E64987E1BC0E9592D6AA0B8101544DB8A6F8AB2B
              9D3B6A1AAAF16152D25A356C0CA06AC2B5C6CF5EAF75B846064B41637D603180
              FA58573E52AFBBF8B5CA07697880D834368CD360004D57C0F1F8F2FAF880E390
              DE848B595B53903180A6C85734AEBC3E8EF62DC198B555341DA686C500A6220A
              6F87E376EE82F0B2DE3CE318356DAEB89EAD18403D9C6B1DE5E5E57B4E98CCC6
              F375E1A2A5AFA9568AD50FE6C30818800F55A82087DECABEA78C89E08C7996FD
              7E5D4B059008C949C098E740FF8C7966FE19ACC62CFB7B6F65F1DA60F30F2071
              9E010450A43229F6563A1795E9DF64DFDECAE2179B1C3F85B1318004AADCEB76
              AC91BFA6C14895672DFD9C8349387FA2BEF4C0007CA944C579F4FF9ACAEBE98A
              8771103E7BBD17F0B31607006A0D8101D48ABBD9C17AFA7A5ACEA8379BC526A3
              4B6EBD043ECDB80981DA372565007BF6FC6247ED843D1B50CFA8FBF89EBAE6A4
              B97986ABF674EEBCF3B1ED750E9A9201ECCA2EDC72B4D55ECACE6E073E90C74F
              DD70E703B582AFB3C8A363BDBC7CCF899E9C17F0E1A3B59A83E6A2398DE619EB
              639D6B7B160E3E2DF3EE436967CDC7135B4F1C13DDBBA4D5724BC9002600B59F
              950DB76DDFBAFD9816635E0A238F93B8E9476BF5E06BE6F302F25A5F4C487348
              02B688D4B9A5734CE75A9665DF9755174A6BF486018CE0B752182D526B612999
              2BCEF4E475774F0E46F96B5CF94545740C1DAB27638EA08FF6A1CE259D533AB7
              7C1389014CAA4866AED4A2B5160E3E3F6997D8D6CB5FE33B7A62046B66CBD526
              7378D1CDCCBCB566D6AED6D83A466CDC26E9D1B9A37348585E39699FA6D76300
              D32A9065376B115B773FF4B969BBC6B2FDD9EEC29BBD95CE57F580D566E7EC37
              32631E157DB37C15D77BBAAFF6D1BEFDB6D2B9EAD984AE5BA87345E78C91B923
              CCCEBAF9F6000398B5225BB6FE6BCFC2D2BE59778F693FFD028ED56EE7877230
              5F2ACD4E6997EABEDA272606B36A995F58BAD3C85C9975FFA6F7C3007254405E
              BF2EB5F61EFC4D8E2EEC9A1081F9BD079EB799792C24C91840DE6AD9EC7A797A
              77386F37F68F9B80CE096BEDCDA1A9C4008A556C97BA7DB1AEF48A8DC0E059E1
              D4F7EE7DD48D0114AC8ABA7DFFF55EC1FE748B8340FFBC903C2B0C550D0650A2
              72FA7A4FCFF8960841D7800968EDF5BC50C012B82048E9E20574C6B7B456029C
              4D2082DAF30CE0EC92167AA41FF828D4914EC112C85B735F8562002E2A13C007
              3E5CC824C6060291D41C03D850D332775B09FDEF40194E31F48DA9D61880AB19
              99196F3FEFED4A2271060422AA350630A8A98BC57C42FF4AEC825788318AD4D8
              679D1880C3EAD8ACFF3FDE0E2312CA3702B1D51803703CC3F46A2F8E4312CE13
              0231D61603703CB9769CBFE311C72109E70981ED5BB71FF4241567696000CE50
              AE07CAB2ECA6F57BFC8E8F40FEDAFACE0003705FA1C6AFF3E65E1211D70958BD
              7EE4FADD487E630091141219102842000328428D3E108884000610492191E11F
              811032C2002AA852DDDFEE528104428E1088F55BA58231808FCDDAC9919A78FB
              F0C4D6137FD54B44D1960EC7C220BB70CB5FBC9D702389E539568231805F777F
              FCFE884E9F1FEAE5A168C6C4C6C084F093E75809C60042004F8E101812086589
              01845229F284400504C232802CFBA80206848440340432634EE41113960158F3
              601E71EC0B81D4085893FD2C8FE6A00CA0D75DDC9F471CFB42A009024D8E99F7
              1809CA000660DF192C594000026713C87D6C046700BD6EE78AB335F308021050
              02458E8DE00C4085CA898E5B7449830004D609143D26823480D56EE7396BCCAB
              EBD2F90D017F083494C94B7A4C14193B480350A187BA9DEB6479441A3708A44C
              E0883CF52F7C119A600D402B2EC277CBF22569DC20901C017D163C38060A6B0F
              DA0054B500B8A9E8EB1FED4F8340880474CE0F9E05974A3F780350F5FAFA478C
              400CD1E47E1B44FBD320E082404D31DED1B9AE73DEC5785118C0108480B9429A
              184176BF3864AE8F440E63B084807704FA1F81CFEED7B92DCDE9DBE05119C0B0
              70BDEEE27E71C80B7ADD8E1DB6D3E6E4C59939BD9B0603DFE780CED5E1BCED2F
              57163FD393393D9CDF2E97511AC03840FA3FD2ABDDFB8ED060E0FB1CD0B93A6E
              0E57B12E1903A8021E3121302410EA120308B572E40D01070430000710090181
              50096000A1568EBC21E0800006E0002221D22610B27A0C20E4EA913B044A12C0
              004A02A43B0442268001845C3D728740490218404980744F9B40E8EA3180D02B
              48FE102841000328016DCB8581000002FD494441548FAE10089D0006107A05C9
              1F022508600025E0D1356D0231A8C70062A8221A205090C0CC06F0B1593B5970
              8C61B79DADF6D2611A0C629F03F3EDFDBB8693DEF7E5CC06E0E07F94770A0C05
              43330606713330A1FCCC6C00A108224F08D4412096313080582A890E08142090
              CF00FA17272C300A5D2000012F09E433006B1EF45205494100028508E43280AA
              AE4C5A28733A41A02102310D9BCB0006C2F9F28D01081610089D406E03E8753B
              4EBF98207480E40F819009E43600159B19738B2E69108040D8040A19C06AB7F3
              9C35E6D5B0A5933D04F21388AD472103500887BA9DEB6479441A370840205002
              850D40F5CAF980DDB27C491A370840204002A50C40F58A09DCC4390125418340
              78044A1B804AD673026204725AC0F016A102A145492046514E0C6008464CE00A
              696204D9FDF2ACE0C4703D4B0840C04F024E0D6028B1D75DDC2FCF0A2EE8753B
              76D84E9B931767E6F46E1A0C629F03C67CFA83E1B1E0FBB2120318275AAF27B0
              DABDEF080D06F1CF81050C609C09B00E02A1128835EFDA9E01C40A105D100899
              00061072F5C81D02250960002501D21D022113C00042AE1EB9D74220E6413080
              98AB8B36084C2180014C01C46608C44C000388B9BA6883C0140218C014406C4E
              9B40ECEA3180D82B8C3E086C420003D8040E9B20103B010C20F60AA30F029B10
              C0003681C3A6B409A4A01E0348A1CA6884C0040218C00430AC86400A04308014
              AA8C46084C2080014C00C3EAB409A4A21E0348A5D2E884C0180218C01828AC82
              402A043080542A8D4E088C2180018C81C2AAB409A4A41E0348A9DA6885C00801
              0C6004080F219012010C20A56AA315022304308011203C4C9B406AEA3180D42A
              8E5E086C2080016C80C15D08A446000348ADE2E885C0060218C00618DC4D9B40
              8AEA318014AB8E66080C08600003102C209022010C20C5AAA31902030218C000
              048BB409A4AA1E0348B5F2E8868010C00004023708A44A000348B5F2E8868010
              C0000402B7B409A4AC1E0348B9FA684F9E000690FC140040CA04308094AB8FF6
              E4096000C94F81B401A4AEFE7F000000FFFF8931CEE900000006494441540300
              2F32F9E2E2A63C580000000049454E44AE426082}
          end>
      end
      item
        Name = 'Staff'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9D0B905BD579C7CFB9EB5D3B666D0C059C908457
              294D6060929434B4864E289319986908A5D08697AD2B8A49095E49BBD202814E
              7786628C25ED6A6D1C838B57024AD384504A325398292519200D244C691A0343
              5ACA634248783AB679ADBD3AF98EBC4BD6F26A25DD73EEBDE7DCF3D7DCB392EE
              3DDFEBF7DDF3D76B57EB315C4000049C25000170B6F5281C04188300E02C0001
              870940001C6E3E4A779B80AC1E022029608080A30420008E361E658380240001
              90143040C051021000471B8FB2DD2630533D04608604AE41C041021000079B8E
              924160860004608604AE41C041021000079B8E92DD2630BB7A08C06C1AB80D02
              8E11800038D670940B02B309400066D3C06D10708C0004C0B186A35CB7093457
              0F01682682FB20E01001088043CD46A920D04C0002D04C04F741C02102100087
              9A8D52DD263057F51080B9A8601F0838420002E048A3512608CC450002301715
              EC0301470840001C6934CA749B40ABEA2100ADC8603F0838400002E040935122
              08B4220001684506FB41C001021000079A8C12DD26305FF51080F9E8E0180824
              9C000420E10D467920301F0108C07C74700C04124E000290F006A33CB709B4AB
              1E02D08E108E83408209400012DC5C940602ED084000DA11C271104830010840
              829B8BD2DC26D049F510804E28610E082494000420A18D455920D00901084027
              94300704124A000290D0C6A22CB709745A3D04A0535298070209240001486053
              511208744A0002D02929CC03810412800024B0A928C96D02DD540F01E88616E6
              8240C208400012D650940302DD10800074430B73412061042000096B28CA719B
              40B7D54300BA2566D17C3F5BFE9B54B6F8682A53AAFBD992E866481B69EB67CA
              975B543252ED920004A04B60264FF773C52FF9D9E2AB330B9D31F175CEF80A4E
              3FBACD5BDA90D90AC6C52D33FE52D9D2AF648C6E7D61BEB9042000E6F6A6A3CC
              52B9F5A7F9D9F22F7D7A846782FF2B63FC5016D2853376988C2163F91433951B
              3D2DA450701B1101084044A07587490D142FF469D173E13D4C8FF4CB75FB6FEF
              4F2CE7A2FEB0CC81C65FB79F8F19611308E21F0210845A8C36F434FC5C5A7082
              7BFCAE18D3680EFD0F32A754A67C59F301DC379B0004C0ECFE7C905D7AF8A625
              B4C876D1D3F07B3ED869D80DCEC5163F577A77F5EA75071A961AD269410002D0
              028C49BBD3B9F21631D9B383723A8086D99B608B762F5EB05DE66C76A2C84E12
              8000480A060F7AD4DF2184B0EEA9B5CC59E66E30DA44A516B4180840507221DB
              F96B4AC7D302121466090D5B37F9B245F843A5E36D2D20E97943000CEC707AA0
              F8E7AC873D65606AC1529A624FA533E595C18C611526010840987403F84E658B
              59E1F17F09606AB489E0E2763F53BADEE8241D4C0E026050D3E51B679CF13183
              52D29B0A67D7A532A5CD7A9DC29B0A0108800A3D8DB67EB67C8D7CE34CA34B23
              5D71CEBEE2674BAB8D4CCEC1A4200006343D952D9DC398586B402A51A570EBAA
              C1F2195105439CD6042000ADD94472C41F2C7F9C33766F24C10C0AE2D5C583B2
              7683527232150840DC6DAF8B97E24E21B6F82ED7AE09BAAA1B08802A41057B7A
              2DFC9A8279C7A682B14D827B27552B79DEC9907319E737771C406162540C1452
              4CB4290420A6F6FAD96291421F42239C8DB3F2CC62AF55F257D6C6067FDA6920
              39B73A36B466C69E91AF4E6D03CC3B649A45005398A8128000A8120C6CCFF381
              4DE733A4C5DA58B863796DFEABE44BFA0C4F081A2CE8AD90F90AC3B130084000
              C2A0DAC6A79F2D3FDF664A90C3AFCB452A176B10E34E6CA46F1983E6BE4E43EB
              E6674BAF6875E880331D2542007450ECC2C7855F2D1D491FF91DD585490753EB
              97D1C20CED9B809A13D81BABAEFB0F9496A732A5CF36C7C2FD70094000C2E5BB
              9FF785BDEC99FD762AEC10ACE7E86A65F8360517814C65CC3D6C4AEB1FF970CE
              7E1428191805260001088CAE7BC38BB3631F21AB0FD1D0B2EDE2DEE25A25F782
              1667019CDC59B9EA19DE37B53480694B93955F2D1FD7F2200E68270001D08EB4
              B5C35E36F574EBA3DD1DD9B3402CBF7B6CF0DDEEACF4CF9E587FD5CEC9A93E6D
              DF00D4D32B9ED09F65F23CEAAA0802A08B641B3FAB57DFDA4B5396D150DEBCBA
              38F1CE52E15565479A1CDCB57160C794C77F5F93BB25D3AC34B9839BF9084000
              E6A3A3F1D8E4E29D5B74B81382ADDDBAA1B04D872F9D3EEE181DFA99CC4D874F
              5DAC74E492741F1080883A4C1F72A7544309C6DEAD8DE7AF55F51396BDCC4DE6
              A8EA5F072BD51C5CB1870044D069F98DBE3AC2F4BDB344DB6B6D1DF9CCE54357
              8EBA98CD95A3EDFB74E60F01D049B385AFFAA4A7FEA8CDD9635BB65CBEBB4508
              63763772A45C551312933DD7A9FA807D7B021080F68C946770C1D6A83AA98E0E
              FDB1AA8FA8EC75E44A2F2594994555AFCD71200051748FF3C58A617ECE38C988
              A293C8CCF7E6FA739578F43E80B6DF9750C923E9B610000B3ACCEBEC020BD2DC
              27451B73DEA70043EFE84E0B02A09B6893BF55D9F52B9A76757D776243FED1AE
              8D6236D091B30E763163303E3C0420E416798C9FA5164244F2A5216A39B6B2E6
              4AB9ABB36B9517F6CF10F0666EE03A34024A022018FF56689985EEB8FE6DC510
              4AEC14633B610E0108BDCDFC332A213CEED554ECE3B41553DE1D6AF1D5D8A9C5
              36CF3A8C8CBC309CC2A73E02136383D6FE714C6DE3D063FA48C0531804200061
              50854F10B0840004C09246214D1008830004200CAAF009029A0984E50E021016
              59F805010B0840002C6812520481B0084000C2220BBF206001010880E14DBA68
              CD88D62FDD8CB2DCF357AF33FEFB0BA2E41134569876108030E9EEF5BD63EF55
              B09F7DDE12EBFE1068A6D2FEC5BD17CEDC0E78ADC42E604CA7CC2000E1B7FB7E
              951082D72F51B18FD756A8E6AEC42EDEDAED880E0108BB4F9C299DC49C71E5BF
              260CBBC479FCFFD13CC7DA1F5264D73E00664000423E07DEABBFFF806A88356B
              362C54F511B5BD8E9C75B08BBA6EDDF1C2F607010899F037C6AFFD956A885D3D
              EF6BF94A71D53CBAB1D791B30E76DDE4ECE25C0880155DE72BAD48739F246DCC
              799F029CB8030188A0CD82B18755C3A433656B44404BAE82FDA72A33D8B72700
              0168CF487D0617255527828BDB557D4465AF2357E1897551E56B6A9C28F28200
              4440B93656F8AE8E307EA6A42C243AF298CF87AE1C75319B2F571C630C0210DD
              59F0867228CE862ECD8D1EACEC2724078DDC28470DEED5596948C20517108088
              BAEC79FCAF7484AA8BBAB18B43576EBA58E9E09D741F1080883ABC7574E83F74
              854A654A6FEAF2A5CB8F9F2DBDACCB974E56BA728ADA4F54F1200051916EC411
              3734AE147F70CE0EA205F7A4A21B6DE6E96CF9717276380DF54DB0317527F0D0
              29010840A7A434CCAB560A3AFFE1E5A7E80DB7FFD29096920B3F5B7C5A30F187
              4A4E661957C7F383B3EEE266C80420002103DECFBD60E5FDF605DDC1D9A7E999
              80B6A7DEDDA641B15F638C7F9269BBF0FBB4B982A38E0840003AC2A46F123DC2
              E5F5796B783A9C16A24867478F69DC8BE0878C256352A8436868DBAA95A173B4
              39B3D85194A94300A2A43D1D6BAA3EF5A7D337B55D09567F8E9E8EFF589BC316
              8E640C19ABC5E1E0BBB987C51F9C5E604B2FB0250C0313B863C355DF23E39D34
              346FFC64F9C84CE33B9A1D33E99386608C9FCCF45F7655C706F1F45F3FD7B61E
              21006D118533E1C865BB9685E3B9E1F58B72B1D2D84EE3BCC69E003FA42D0DE9
              83163EFB6200171D99100B7C755847A4F44F8200E867DA91C79191917A9DD54F
              ED6872F0497261DD4D8B584C8FFFF3B3EBF3A9DCFA3357E5464FB868CD86A572
              C8DB725F3A571A4A654BCF4ECF1514F66E1AD2075D85B34906924538DEEDF31A
              75C61080A889CF8A777B65F8074C887B67ED0AFBE6EF32E615B9F0EEF7447D5B
              5FCFE4AFE590B7E53E21588933765CD8497CE09F6A6F30F860076E444D000210
              35F1A678D5F1C2B98C71E52F0D61F65D5EDE5BBB7D89272963088001DDA48FBF
              3ECC98D863402A51A5F07EB592FF5854C110A7350108406B36911EA9560ABD91
              068C3158B5925F1463786343C7911804200EEA2D62D2C2A097E02D0E2664B70B
              35DAD42A088061DD9A5E20BB0D4B4B3D1DC1A6A66B53F7050FDA084000B4A1D4
              E788164A1F797B9D4652B637ABE3F905492926497540000CED2689C0A1F4C6E0
              6643D3EB222DB1996AF99D2E0C9C9C1A57D11080B8C87710B75A295CE1F5B0A3
              98A51799BBACC1D2F49D481B0260789BB796F32F562B79CEECFA9AECC765CE32
              77C3F13A9F1E04C09253805E43AF6053938751BA53348CDD7A59CFE1B4F84F31
              364124B60F0108C03E38CCBE53DDF8B5D768712D10F5FA59A665CA053F8F72E3
              5B2AB9574CCBCDF47CE2CC0F021027FD80B16B1B861F908BCDF3F86718679301
              DDE830DBCDB9F75999CBC4F8D03D3A1CC247B4042000D1F2D61A6DEBE8D093D5
              B1FC42B90039631BB53A9FC7998C2563D2E89B181B7C629EA9386438010880E1
              0DEA34BD894A7E801624974330EED34788CF766ADBC1BC6D82B195D2B71C3256
              0736986201010880054DEA36C55A65A856AD143E51A54F0F6646BDF1DD03E286
              C69F1F7326FFF1E673E477D7F4788EC97D42DC4BC271839C3B63377D7D62AD92
              BF93E662D34C206E771080B83B1051FCDB2BC33FA8560AD755C70BE7D2CB8615
              D54AFE581A4BA6C7B18D7DF218CD9173234A0B616226000188B901080F027112
              8000C4491FB1412066021080981B80F0EE1230A1720880095D400E2010130108
              404CE01116044C20000130A10BC801046222000188093CC2BA4DC094EA2100A6
              74027980400C042000314047481030850004C0944E200F10888100042006E808
              E9360193AA870098D40DE4020211138000440C1CE140C02402100093BA815C40
              20620210808881239CDB044CAB1E02605A4702E6B332533C299D59FF17E981D2
              D57EB6B4D5CF161FF633A557E8B65019A96CF1C574AE7C3FF91A4D658A97ADCA
              8EADB834377A70C034616618010880610D6995CEC5D9B18FD062CCD242BC8F16
              F78EE645DDC3F94F04F7BE2D3C7623F94833C64F639C7D98295E38E3470821CE
              245F39CEF9168F4D3D5A17F5379AE3534E4FA732A54DB4FFBCD5AB6FED550C0B
              F3880840002202DD4D985583E5336841DD4E8BE97D1A8D47F05E36F50B5A8C63
              B410CF668C2F61C65DF827396757505A77EF5EBC7372266F3F5B7E9144EBFAD4
              C0FADFA363D80C23000188B921175E7DE341B448D6A6B2A577FC6CA9B1D8BDBA
              789031BE923126FF49285DD9BC892348B4AEE39EF7B399FA48101E490F964FB7
              B9AA20B99B68030188B82B970CAC3B8216C23D341A8B7DE17BBD6F3226AEE18C
              7D28E254E20BC7D9A9A22E1E9A6140D7DFA3F72E4E8D2F217723430022E8BD9F
              295F4E27F94E1A6281B7E0450A792E0D6CBF25F0797AEFE211C987C6949F295D
              7FFEF9230978F6F3DB024DBD050108A133A92B4B9F4867CAF7D3C9DC7894675C
              DC4261FA69606B4FC0932F19FA3FDA3FFDFE47F9C77876D01E5AD0195E5043D8
              ED4B20951B3D915EC7FF442E7ABE803D23B83873DF19B8178C803879E6D901F1
              FD358D7382F989D7CAD4E8100085CEECB3E845FD7FE875FC490AEE60DA8600F1
              5D4AE35E29B234DEF233E53F6B6382C36D084000DA006A3E7C696EF4587A14DA
              FB488F45DF8C27CAFBCBE8A5D5774908E4CBAC37D2D9D25951064F4A2C084087
              9DA413AC2A4FB6BAA84FE2EFD1000008C349444154FF2F3D0AE191BE436E114D
              3B5830F66FB23F529CE5272D11C5B53E0C04609E16A673C5BFA485BF5B9E5874
              82A5E6998A43861090E22C3F69913DA3511B191989FD1C3704CD9C69004E1396
              0B32372CA713671B0D2104FF262DFC054D5370D71E02AB5EDCDE3F257B99CA14
              2FB327EDE83285004CB34ED3A3BD3C5116F185BFA45D27D0C09620029CF32DB2
              BF7EA6F8587AF826037F953A1ED8CE0B403A53FA863C31E4A37D3C2D40D44809
              70FE3931D9B3837A5E4F656F72FE23452705C01F2C7FDC9FFE5359C1D997233D
              0111CC14029CB39EBD1F29664AF7317A0460215C4C77E99400AC1A28FD0129BF
              6075F112E34CF94F650D6BEECB94CF83F49EC5263A9933A25E3FAB678F38A65A
              C97395217D485F0D9F8C6D923168C8587495908DB3B3FD5CB94EE7C6CBE9B45B
              2F0F9C10809599E249D45CE179EC098B4FD9B76971DFC504BF644F7DCF91732C
              EA8FD1BE2FD42AF92BABE3850DB50DC30FDC7673E179D57AA50FE9ABE1B342BE
              2BF92F501C196B1F619139C9DCE89DD37FA698BB69D8B81D2E96365E1EBC9C4A
              8D2CB2B1806E734EBC00F8D9E293F2CB32BA0513E77C7A6EFA75C1C4E9B4D066
              2FB27E5ADC1757C787FEF1CE0D57BF14677E73C59639C9DC6AE3850B28EF3E1A
              8DDCF99EA98F92700D30C66D12DFC3F9B2FE7753D9E2084BF825B102B02AB7EE
              04F9A8CF18FF14B3EC5217BB8BB54AE1FB96A53D67BA13375FF58B5A25BF51B0
              C9F3E79C60F04ECEF8DFF999E2BB9F1F1909F45130B3E0924801F073A59C2716
              6CB3803F52349D00E78B8EDEDEBF7BE560F938D3530D925FE20480DEDDFF2113
              6C34080CD880402B023D75F1ECAA4CF1D256C76DDD9F2801A047FEA7E8DDFD53
              6C6D06F2369B80C7F96DA95CE92B6667D95D768911003F5BBA9B1EF98FEFAE7C
              DDB3C5437CC7D452F2FA020D6C7A09BC40E2FEB77A5D76EF8D0BB6D9CF942F6E
              6769CBF14408407AA07435013F8F46E41BBD63FF96E0F53FD9FBAE77E18C8989
              AB76469E842301AB63F9BF979C27A7761D489F2CC4F726291777A606CB8978A6
              69BD00F86BD61E2ABCC677E147BA0C84606BE5C93831963FB83636FC48A4C11D
              0F76D7C6911DB54ABEF1312963E20CC211B9E8F2BAF821C5B57EB35E00584FDF
              AB51758116FDF30B1788E572E1D7C6F3D7461517715A13A8560A0F552BF9A534
              38635CFE531416D5259529BE1955ACB0E2582D00F2977CC20233DB2F3DDDACC9
              138C16FD31B7940A9109CEEC1C70BB3D816A65E86BB24F5E5D9C48CF0CDE686F
              A13683737E109D83D7347BB1E9BEB5027049BE78000BFB977C04FFB23CA1E8E9
              A6CF70B186C0D60D856DD54AE1906A25CF99E0FF146EE27C6DB8FEC3F56EAD00
              2CD8C3FF3F24346F0BBEE72479F254C787BE19520CB88D8800F5F022D94BCEF8
              9561854C654AD6BE1F60A500D0A3FF61D44C39E84ADBF6F6E454DF8174B2F4D7
              C6AEFEA936AF7064048189CAD026EA2DF7B8F739DD0971CE4E393F376AE57F76
              B252007AF6F0C73537F1723A39FAEFDA38B043B35FB8338CC0D6B1C11F51AF39
              BD47F0DF3A533B40887F97FE6C1B560A0075EF285DA005EB39884E882DBAFCC1
              8F1D04AA95C2A7B910C3BAB2A5371B56E8F215A51FEB04805E6F6DD605A84A6F
              12D52AB9EDBAFCC18F5D0426C60B45C1C4E9BAB24EE71ABF90A6CB5D247EAC13
              007ABDA5E577B17B972DA14F1122611C2048CFB254F6C6A3923418EB59160044
              E826B54AE1FB9C7B5AFE59AB10D1FF429A2A20EB0440B560692F58DDDF3272F9
              3BF2B6898333EF49CE7A9F4FD6F09E64865E26C606EFA5D4BE434369B3D1D82A
              014867CA676B80BCBD5619AE69F003170922402F07BFA4A31CDFB2FF57689500
              08CEF2AA4D5AB468F131AA3E609F4C023DAC47FDAF49391BB6898E6753B2F4D1
              CD694AF972F6DEE67557BCA5E403C68925705B25F78C7A7142ED1C554FA02B0F
              96094057B5ED37993EAA59B5DF4EEC0081590438E3817EED7B960BAB6E3A2500
              1363856F59D51D241B398189CA9053EF0F392500919F4D0808028613800018DE
              20A407026112B04600AEB86253BF1208218CFDDC5FA92E18EB27D0E5B9D29C80
              F2B9DAEC30C4FBD608C03B7D3B0E51E2C039BEC84309A043C68AE78AF2B91A21
              6A6B04204226080502CE10800038D36A140A02FB138000ECCF047B40A06302B6
              4F8400D8DE41E40F020A0420000AF0600A02B6138000D8DE41E40F020A042000
              0AF060EA368124540F014842175103080424E092002CF3B3A5E7A318D40B23BF
              FE8AF2B27943FF42E89E530240FCE4B70947312000045BF3269946D13B1943C6
              D29CBE99EE5C1200333B80ACAC249094A4210049E924EA00810004200001A0C1
              04049242000290944EA20E100840000210001A4CDC2690A4EA210049EA266A01
              812E094000BA0486E9209024021080247513B58040970420005D02C374B70924
              AD7A0840D23A8A7A40A00B0210802E60612A08248D000420691D453D20D00501
              084017B030D56D0249AC1E0290C4AEA22610E890804502B068BB60BB8FC60003
              D3CF01C6166DEF70FDC53ECD1A01A85572DB6B956B5EC00003F3CF811C042076
              69430220A09140525D59F30C20A90D405D2010270108409CF4111B0462260001
              88B901080F0271128000C4491FB1AD2090E424210049EE2E6A0381360420006D
              00E130082499000420C9DD456D20D0860004A00D201C769B40D2AB870024BDC3
              A80F04E621000198070E0E8140D209400092DE61D40702F3108000CC030787DC
              26E042F5100017BA8C1A41A0050108400B30D80D022E108000B8D065D408022D
              0840005A80C16EB709B8523D04C0954EA34E1098830004600E28D80502AE1080
              00B8D269D4090273108000CC0105BBDC26E052F5100097BA8D5A41A0890004A0
              0908EE82804B0420002E751BB58240130108401310DC759B806BD543005CEB38
              EA058159042000B360E02608B8460002E05AC7512F08CC22000198050337DD26
              E062F5100017BB8E9A41609A0004601A04AE40C04502100017BB8E9A41609A00
              04601A04AEDC26E06AF51000573B8FBA41800840000802361070950004C0D5CE
              A36E10200210008280CD6D022E570F0170B9FBA8DD79021000E74F0100709900
              04C0E5EEA376E70940009C3F05DC06E07AF5BF010000FFFF49C912FC00000006
              494441540300E71744971EDD2BFC0000000049454E44AE426082}
          end>
      end
      item
        Name = 'Plant'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9D0B705C5779C7CFB9929D3476123740A7032989
              49032529A553FA24B4C6D014A6F435D384694B1D6B651A67DAD85A4957760CA6
              6C19F2B256D2CA14423CB1567686D08C3B2D9D0943DB498A4A1E257D041AD242
              4C8B4D5AD30E2D89094A886D690FDF915766BDD63EEE3DE79EF3DD3DFFCDBDB9
              77EF3DDFEBF79DFBD7EAEE6A1D093C4000048225000108B6F5281C0484800060
              168040C004200001371FA5874D40570F01D014B08240A004200081361E658380
              260001D014B08240A004200081361E65874D60B97A08C032096C412040021080
              009B8E924160990004609904B6201020010840804D47C9611368AC1E02D04803
              FB201018010840600D47B920D0480002D04803FB201018010840600D47B96113
              68AE1E02D04C04CF412020021080809A8D5241A0990004A099089E8340400420
              0001351BA5864D60A5EA21002B51C13110088440F002502896BF303054BEAB30
              34BE756078F20D81F43DD832758F977AAD7B5E2C7F315810F5C2831700E2704A
              4A719390F2E352D59E2441500DEB4BB43FBB79FBC4DB691C961C11286CDBB361
              A058DE5F182E7F977A78A6A7BAC74BBDD63DC77762E24B41694E7F81D656CB79
              74627314A907CF4CA2E1F2A383C377FE341DC7C288C0E6E1C9AB0787CB67FA24
              FAA23929C4A050E2FCD669AA2FB73ED75B675A5513B53A11CA719A244F25AA55
              89372BD5F74F4B823034FEC2C0F63DEF4C648FC1D6086C1E2AFF52A1387E5CF7
              2252B5A79412895EA951EF2100D6BA9153473519A5FF3D50CA0B64147D464F40
              5A1F1E284EADCB2986DCA4BD291E5F33509CF89B42B1AC2229FE5E0879B148F9
              50423E9DD2B467CCA29EA9246521AB5F58F3F994A6CD666F9162F1393D310746
              267EB5F9249E9B11D85CDC738D66DBBF20E7A550BF62E6EDB4F5AA5AFFA3A7F7
              C2FD7FF002B06FDFD653B6DB2F6BEAD37AB20E6C2FDF64DB7768FEB614C7DFA5
              5946227AC476EDFBF6169FB1ED93A3BF7639052F00EDE0989E9391B84B4FDE42
              71E2FDA6BE42B32F14CBD7D1AA6A423E105AED2EEB8500106D29E43C6D325CD4
              87F5641EDC36F1C60C83F484EB2DC39397E8B7EEA89843B462C998000480002B
              A1FE8C36992FAA4F7D91EE5A7FF3FA526975E6C1721860B038F1484DD5BED5FE
              AD3B5B85A9076D79CAB31F080075EFC429F161DA385AE42BD61E5F7BA2501CFF
              B8A380ECC3D0ABA3A597FB24C4D7B84AB6568BEE7015CB679C4EB1210044E8BE
              8FC65FA78DE3456EA589AFDEB36DEF458E03B30A4742F85F9490F397FB07F68E
              3E4471835F2000CB5340A99796775D6E57F79DFC76A138719BCB981C629DFE10
              4F5909212F15787823000158462FC5879677DD6FD5AEFA8D2FF7A13D442C14CB
              5F39FD211E0FC12924FDAAF169DA602102100082A09723EB5E18D75B6FAB12E7
              D385A136DD3CBEDE5B0E0E02EB1A29CCEB68F5B7C8BE5DFE82BB8BDC4D240840
              9DD25CA9B450DFF5BAE9EF975FA3DF8B7B6E826EDEB6E78A4251BFE4F78A7729
              F8ECD4C8979676F03F0101689C04527CA0F1A9BF7D795B61A8FC6FFEE2DB8D3C
              385CBE25EA8BFEC3AED774DEE8A6C33FA6B3EC4D2B0840435FAB53B1C3B7031B
              02AFB42BC555F413D3CB8DC995D2497B8C5ECDCC29256E4F6B6FDB6EB15FFD8E
              6D9F79F6070168EE9E129C2EBAF34804E887567392F9784EB91F16426E108C1E
              F796C78E304A27B354BA750C0168224540DED174C8FB53BA90D48D3BEF48FD67
              AF3E0AA09CFF8FE25E492B9F45892A9F64786442F39D47225CB2D83F1D7F8E4B
              2E8D799C3AD17F7C2027DF594817BF7ED5F2F2C6FC39EC57A7E3410E7970CA01
              02B042376A4AC42B1CF67E487F9F9DFE008DF744DA2450BFF8DB8CF0754A3DE1
              2B32E7B8108015BA73603A9E58E1308B43FA033485ED136F66914C53127C2F7E
              21D4BA973BFB3B83262CCE9F26090801684DEB9ED6A73C9F89D4A3370CDFF9B3
              9EB3382B3CE78B9F12FDE66CA9C0E9E62EA5C4638100B4E843B512FF418B532C
              0EF7A9BEC70BC53D3FC52119BAF84F72C8A3550E0BFDEA35ADCE857E1C02D076
              06C8B1B6A7BD9F8CFE65D3F63B5EED330DBAF8F5DDFE553E73681F5B3D416FFD
              BDD07E4CB86721006D7A5FAD8C96DB9C6671AA3FEAF7F0A7CCA74B2F0C95FF8E
              F6D8DDEDA79CCE2CD5CAD89BCE3C096027698910800EC4A450D77618E2FD34FD
              14D66FBB39CDA3A0BFE7508A8D4E83260CA694BA2FA14970C321001D5A3E5319
              7B90EE217FABC330EFA70BC5F2F3AE9218B8B9FC63C484CFC7A65B143E3B3DF6
              9E16A770B84E00025007D16E432F235FD1EE3C937317168A13730E7291B25FB0
              FF1775FA70E3AFABA90001E80A9350F4DF07BB1BEA7394DA30581CFF852C3328
              0C975FCCD2BF25DFFF704F809FF94FC30E02D025B5EA74ACBF31A8D6E5706FC3
              94908F6515BC502CCF92109E9F957F5B7EAB9598E507A56CD567D30F0420014D
              7A3F39175FE04917EAB71394D5D5D02DC3933F4A0337D3CA7AA92DD6749EAC73
              E4941C04204137F4FBC94A881B1298F81A7A51A13861F5265D4DD5BEEAAB98AE
              E32AB5F7C04776FC67D7E33110DF0894740ECC56E27BE986C09349EDDC8F57EF
              BFF1C6BBAD7C40A7502CE7E15B749EAD4E8F0DB9E7CC2362DA2CF00A2005B9D9
              CAD81B539839373979C177FEDF34E8963F2A5F463E7E8656D60BFDDEFF32D609
              324D0E0290B231743F606D4A53676652888B068727B79804ACAD124705F307DE
              F24BDF2008404A76FA7EC062245F97D2DC999952B5D47FD5582896EF769668CA
              4052AAF7E22DBF94F0C80C024010D22E0727470F93ED565A592F7421DF9F32C1
              1B53DA39319352EE9F991ADBEF2418E32026A941004CE8912DFDEEB98F369FA4
              95F3F2EEA4C91586CA7F95D4C6E97829FE7D666AF4BD4E63F66030088085A692
              08FC1EB9F9575AD92EF42AE0AF132527C56F241AEF7030BD15FB7C752ABEDA61
              C89E0D0501B0D45A12819F14527CC592BB2CDC74FD6DC7F4D35FFF996F1639D8
              F07962B612E7EA1B926D149D950F088045B2F453E9F5E48EED5DF38162B9BBDF
              9719FF992F092DFB8F22D31C70B69806820098126CB2A709BA9E5EA2FE4FD361
              164FE96DC18E5F8B5D284EB0FD7709892D95C00265CF240101C8A095F412F595
              E4F6595AD92D03C393EF6C9F94BAADFD793F6771F167C31D02900D574113567F
              328DDD3FF02955ED8156256F1E9EE47863ED3BC4123FF95B35CDF03804C01060
              3B739AB83F4E33F713EDC67838D7D72A66A4544B71686593F1F1A7AA9538177F
              8199318715DDDB380801B041B18D8F994AFCFBF4EEC0489B21CE4F0D14C7F577
              1BAC10575DBEC2412F879410B374F1BFC14BF0808242001C34BB3A154F29A1D8
              7C81A614F203CD65DF3032F1DAE6631E9FEFA4FB28058FF183090D0170D4EAD9
              CAD85C24237D5FC051C46461FA6AB57DC92CB2192D457405FDE4DF23F0704200
              02E004F3E920FBA7469EA5C92DE9D93768F5BA0C0C97FFF0EC04E486B39F3B7F
              B674B36FA632F235E7917318D056CA10005B2413F8211178955062228189F5A1
              520936F72548110F1113DCECB3DEE5CE0E21009D196532A23A1DC78BA7BCFE39
              F115CB856D199978FBF2BEF3AD523F4F374A13FFB192F33C7B342004C063630F
              7E74F430FDE493528A873CA621D4622D761F5F3DA16BAF4E8F3DEE3E36222E13
              80002C93F0B89D998A7FF9E4E2E28FB84E617371CF353AA692B2C3A703F5287B
              ABEA13AFAFE2DFEC4B0DD4A62104C0264D035F9FF8C8CEFFAE56622994FC5303
              37894CA590D72532301FFC495DE3EC44CCF9AF26CDABCC91070800B36655A747
              B7E98B4428F1D9AC53230170F30F9F4AF198AE8956FDBD09599705FF09084000
              12C07239B43A1DBF6DFED8E3FD4A892319C6BD7A533CFE43D9F997472F5B37BF
              AA3A152FFDAA915D1C784E4B000290969C03BB43870E2DCE4EC7AF993FF6EAFE
              AC6E14F62DC8AEBF28A4DB9275AE3AE76A65747DA9545AE8D60EE33A13B03D02
              02609B6806FE0E1D7AF7A2BE51482FA1A51072B7B0F8904A59FC88B2DCAD73D4
              B9EA9C2DA60957191180006404362BB7F453F5567D912DCAE8528A3147ABD1A2
              84F801230742CCE95C744E3A37435F30774C0002E018B8AD7007A7468ED145B7
              9156A92F40F29B4A0CE825C579649B7469B8E8E38D3A97A40E309E070108008F
              3E1865A12F4012822531A02DFD0AAEAEA59FEC9FEBCAA91497741AA77D49A1AE
              D5BEEB2B2EFA4ED032389F854B084016543DFB9CA98C3D385B8937E88BB5732A
              F2CA7663B40FED4BFB6C370EE7F249000290CFBED9CCFA95369DC157BE084000
              F2D52F640B0256094000ACE2843310C88640565E21005991855F10C801010840
              0E9A841441202B021080ACC8C22F08E480000420074D428A6113C8B27A084096
              74E11B0498138000306F10D203812C094000B2A40BDF20C09C0004807983905E
              D804B2AE1E02903561F80701C60420008C9B83D440206B021080AC09C33F0830
              26000160DC1CA416360117D543005C50460C10604A0002C0B431480B045C1080
              00B8A08C1820C09400048069639056D8045C550F0170451A71408021010800C3
              A620251070450002E08A34E2800043021000864D414A611370593D04C0256DC4
              02016604BC0B40A1583E82353B06A6F30DBDC9AE379AAD697F4CEDBD0B001570
              395691250361F8C83237F8366C8EA939070130AD01F620D033045C170201704D
              1CF1408011010800A366201510704D0002E09A38E281002302100046CD402A61
              13F0513D04C00775C40401260420004C1A813440C0070108800FEA8809024C08
              400098340269844DC057F510005FE4111704181080003068025200015F042000
              BEC8232E083020000160D004A41036019FD543007CD2476C10F04C20F702A0C4
              A9F558C1C0D71CF07CFD1A87CFBD00CC56761DC50A06BEE680F115E8D941EE05
              C0333F8407012302BE8D2100BE3B80F820E0910004C0237C840601DF042000BE
              3B80F820E0910004C0237C840E9B0087EA21001CBA801C40C01301088027F008
              0B021C084000387401398080270210004FE011366C025CAA870070E904F20001
              0F0420001EA023240870210001E0D209E401021E0840003C4047C8B00970AA1E
              02C0A91BC805041C13800038068E7020C0890004805337900B0838260001700C
              1CE1C226C0AD7A0800B78E201F1070480002E01036428100370210006E1D413E
              20E0900004C0216C840A9B00C7EA21001CBB829C40C01101088023D00803021C
              0940003876053981802302100047A011266C025CABCFBD00148A6585150C7CCD
              01AE1776B779E55E00BA2D14E3400004CE2500013897098E80403004BC0B8014
              E253020F10E86102AD4AE330F7BD0B80AAC9F15680701C047A990087B9EF5D00
              AA7B471FEBE526A33610684580C3DCF72E00753873F52D3620100A0116739E85
              005CB66EFEDA50BA8E3AC322D0AA5A2E739E8500944AA50521E4ED020F100882
              80BCFDF49CF75F2C0B01D018AA95D1F709A15ED4FB5841A07709A8174FCF751E
              15B211008DA35A195BA3B75841A05709709BE3AC044037BD5A89E9ED51BD8715
              04F24DA0397B8E739B9D0068687550CFEB7DAC20907B024A2CD6E734BB52580A
              80A644C02E16B83128F0C837012964A53A1DF773AD82AD006860FA6609BD5DB2
              8AF6E768C50202792230B7EAC5C3AB672AA3C39C93662D001A5C89DE22A45703
              1B6995B24FFCA290E2017D1C2B08B023407353CF513D5769DDB86FDFBE53EC72
              6C4A88BD0034E63B333D25CC7A000007B049444154113F529D8A7F9DE0CA6E56
              7A5BF1E946FB34FBDDC4C198B8AB7EF8E094A6E767DBA8A7BBCE9BE6A69EA367
              DBF37E962B01488C52451F4C6C0303106824D0E373A8A705A03A3D7A7F632FD3
              EC178AE36F4B63071BFF046CF4CEC61CF24FA275063D2D00ADCB4E7246FE4992
              D118CB89809FDE7122D029971004E04B9D207438FF960EE7719A2F01D3DE99CE
              1DBE64EA99F5BC004889FB00F55E639390400873A7E70560666AE42F13F6FD9C
              E185A1F23BCE398803AC09D8E8998DB9C31A1225D7F30240359A2F52E03E8039
              45B71EA4F2D233B7459A470B4400D41386A87ECED01EE6CE0948C39E19CF19E7
              15A709188600F4F87BB9691A0F9B0E04029933410800BD976BFCF1E1C2D09E5F
              EB3065709A09812DC5F17799A66263CE98E6E0C23E0801B0025246252B7EE024
              730235E1E7FDFFCC0BCB204094814F9E2E95F8BC61626F32B487B93B0266BD32
              9F2BEE2A358C148C00C8A886BF0B309C2CA19887345782118099A91D7F6B3A81
              078AE5DF32F501FB6C09D8E8918DB9926D95F6BC0723009690E1BD654B20B373
              E3E7FDFFECEAC9D6736002A01E36C12985F809137BD8664F400A69D823B33992
              7D8576230425008B35DC07B03B7D7ACF5B687324280138B877E7674DA7ECC0D0
              9EEB4D7DC03E1B028562F93A53CF36E688690E2EED8312001B606514E1F30036
              4066E1C3D3DF6C64518A2B9F91AB405CE228291E32CA4589AB8CEC619C1D01C3
              DE18CF8DEC2ACBCC737802A0701F20B3D99473C72AC0B9119C001CA8EC78D474
              9ED2EF9ABF6BEA03F67609D8E8898DB961B7AAECBD05270076902A7C1EC00E48
              8B5EFCF4C462015E5C852A009F31A32DAF34B387B57D02C63D319C13F62B72E1
              3148019032FA6353B8A552294876A6DCB2B0B7D10B1B73228BDAB2F619E4249E
              991AF96753B0CF1CBFF006531FB0B743E0A8855ED8981376AA71EB254801B081
              B82695F1AB081B79C00711F0D40B8A9CFB25580150427C4A183CA412EB0DCC61
              6A9180692F4CE782C5529CBB0A56006A4A197F3FC05B4BA57E818757026FB5D0
              031B7341E4F411AC001C9C1E7BD2B467EB9F5BB3C5D407ECCD08D8E8818DB960
              56853FEB6005C00A7229765BF10327E90978EA41FA847959862E00F79BB5435E
              6A660F6B7302C63D309C03E615F8F410B4002C46D2F84EFEF5A5D26A9F0D0C39
              B60DF636E6409E7B10B4001C9C1C3D6CDABC0B9E5B7393A90FD8A723B0E6F8DA
              ADE92CBF6F65630E7CDF5BFEF68216001BED8A22B9CB861FF8484E404AF1BEE4
              56E616BDE4010220C401A3862AF1C346F6304E4FC09CBD59EFD367CEC6327801
              88FA84F1E701064AD5F3D9743490446C30B7D1FBBCE30E5E00F64FC45F376DA2
              3CFEECCDA63E609F8C800DE6367A9F2C6B7EA38317807A4B6AF56DCA4DED9694
              86304B4DC09879AA9EA74E97A9210460A931EAEEA54DEAFFC997A53685614A02
              A6CC4D7B9E326D666610006A883AA93E441BA365533CBEC6C8018CBB266083B5
              8D9E779D30E38110006ACEECC776FC2F6D8C96FE85A868E400C65D13B0C1DA46
              CFBB4E98F1C088716EAE533B6516508D99D9C3BA7B02C6AC53F5BAFBFCF23312
              02B0DC2B29F62EEFA6DC5E9CD20E66C90998B136EF75F28C995A4000EA8D39F1
              D2A95BEBBBA937833BEEBC30B5310CBB226083B18D5E77956C0E064100EA4DBA
              EFAE5DCFD577536F6A2723FC1A909A5E77863618DBE87577D9F21F050168EC91
              122F353E4DBA1F896838A90DC6272360CC38658F9365999FD11080C65E45A2DC
              F834E9BE126A6D521B8C4F46C098B1618F9365CB7F3404A0A147F327E6EF6C78
              9A6A77CBF0E425A90C61D491800DB6367ADC31D11C0D80003434EBD0C74AF30D
              4F53EDD6546DE740F1F6CBB1DA67A0D9A66A4A83918D1E37B8CBFD2E04A0A985
              52485311D821C5AA2358ED33A056EDA035F592B6B7A903E6C01002D0D424A594
              F1AF014D2EF1940901F4F6DC4640009A98A81F9C37BA11D8E40E4F1911406FCF
              6D0604A089C96CA964F45660933B3C654400BD3DB71910807399D011F930FD0F
              4B4F1148D7D39E42B04231108015A09C3871F23757388C433926809EAEDC3C08
              C00A5CEA1F155D58E1140EE593C042BDA7F9CC3EC3AC21002DE02ED416AE6871
              0A87734600BD6CDD3008400B36F7EEBDE5193A758C562CF92670ACDECBC45584
              60000168D3E56A25C6BFFDD7864F1E4EA187EDBB040168CF47D004921D86E034
              5302E85DE7C640003A33820874C188DB105CFCDD750402D01DA7D322A0C437BA
              1C8E61BE08508F6C5CFCBED2771D1702908078753A7E9554B5CD094C30D42101
              DD1BDD238721731F0A0290B08533D33B0EEA9F304A88DF4E688AE11911D0BDD0
              3DD1BDC92844CFBA8500A46CED6C25FE0B3DE9F4DA2716AF1242ED26577F4EEB
              57693D8A5564C140B325C66AB766AED9EB55F742E0918A00042015B6B38DEEA9
              ECFC72B532766BB5125F4FEB6B695D8F35CE8281664B8CC76ED5CCCFEE82BD67
              2179820084D46DD40A024D0420004D40F014044222000108A9DBA815049A0840
              009A80E069D80442AB1E02105AC7512F083410800034C0C02E0884460002105A
              C7512F083410800034C0C06ED80442AC1E021062D7513308D4094000EA20B001
              811009400042EC3A6A06813A0108401D0436611308B57A0840A89D47DD204004
              200004010B08844A0002106AE75137081001080041C012368190AB870084DC7D
              D41E3C010840F05300004226000108B9FBA83D78021080E0A740D80042AFFE7B
              000000FFFFB2D88DE3000000064944415403007FC14AC483CC86F50000000049
              454E44AE426082}
          end>
      end
      item
        Name = 'Save'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600000FD9494441547801EC9D5B8C64451980AB7A258644311A940710C19068
              34B218501E340A31261A6F912804A232BD92A821ECF4B2DD72498CFB6062DCE9
              DD3D030809C6E90EBAFBC01A3581177D61134C3480896C34F14505C11B0644DC
              07D9DD99B28ED39D9D9DE99EBE9C4BFD55FF373935A7FBF4A9AAFFFFFE3A5FF7
              F44C7A1A862F0840402D0104A0B6F4240E01631000AB00028A092000C5C52775
              DD04F2EC11404E810601A5041080D2C293360472020820A74083805202084069
              E1495B378161F6086048823D04141240000A8B4ECA10181240004312EC21A090
              000250587452D64D6063F60860230D6E4340190104A0ACE0A40B818D0410C046
              1ADC86803202084059C149573781CDD92380CD44B80F0145041080A262932A04
              361340009B89701F028A08200045C52655DD0446658F004651E1180494104000
              4A0A4D9A10184500018CA2C231082821800094149A34751318973D02184786E3
              10504000012828322942601C0104308E0CC721A080000250506452D44D60BBEC
              11C07674780C0289134000891798F420B01D0104B01D1D1E8340E2041040E205
              263DDD0426651F9500BEB4B8747973F1C0E166ABEB6830D86E0DEC6A751F9DB4
              F879DC982804D06C2D2DE5C5DE61EDD3C6BA9B281C04261170C67C6217129884
              49B600165A4BD7E417BE31B66DF882C08C0490C06460625F012CB4BA4F5B631F
              9B9C026740603C01CD12184FE5CC232205E09FF5FF6D8DB9FC4C98DC82C0FC04
              90C07876E204E02FFE7FF870CFF38D0D02A5114002A3518A1280BFF89FF061BE
              C5373608944E00096C452A4600F91B7E3EBCF7F9C60681CA086891C0B400C508
              C0F286DFB435E3BC820490C019802204D0F4BFE73F1312B720503D0124B0CE58
              84000CBFE7377CD54F000998F07F08B4D0DA7F45FDA5674608AC13485102EB99
              4DF73DF82B006B1A7719BE201090806609041780AFFBF5BEB141202801AD1290
              2080A0856772080C096894000218569F3D043C81D825E05398698B5E00BDAC6D
              693A1958E7EE9F69B54F79B22609442F80296BCA6909125859EEDC8A048A1516
              0114E347EFC0049040B102208062FCE82D800012582FC23CDF11C03CD4E8238E
              001298AF2408603E6EF412480009CC5E1404303B337A08268004662B0E02988D
              1767474040A304E62D0B0298971CFD44134002D39507014CC789B32224800426
              170D014C66C41911134002DB170F016CCF8747132090BA048A94080114A147DF
              68082081D1A54200A3B97034410248606B51D50AA0C97F180EF61F96175ADD60
              FFF20D099C2D01B502381B03F7341148490245EB86008A12A47F940490C07AD9
              10C03A07BE2B248004047C2CB8C27547CA8208689700AF00042D464209432056
              0994410B0194419131A227A055020820FAA54B026511D028010450D6EA619C24
              08689300024862D99244990462904059F92280B248324E5204B448000124B56C
              49A64C021A248000CA5C318C951C81AA25101A1802085D01E6174FA04A09CC93
              7C997D10409934192B5902A94A000124BB6449AC6C02294A000194BD4A182F69
              02A949000124BD5C49AE0A02212550763E08A06CA28CA782402A1240002A962B
              49564120974015E3D6392602A8933673414018010420AC208403817104AA388E
              00AAA0CA98108884000288A4508409812A0820802AA832260422218000222914
              61EA265055F608A02AB28C0B8108082080088A448810A88A0002A88A2CE34220
              02020820822211A26E0255668F00AAA4CBD810104E0001082F10E141A04A0208
              A04ABA8C0D01E1041080F002119E6E0255678F00AA26CCF810104C0001082E0E
              A141A06A0208A06AC28C0F01C1041080E0E2109A6E027564AF5600BDAC6D6961
              18F4B3F6B5752C6EE6984C40AD0026A3E10C08A44F0001A45F633284C0580208
              602C1A1E8040380275CD8C00EA22CD3C1010480001082C0A2141A02E0208A02E
              D2CC030181041080C0A210926E0275668F00EAA4CD5C1010460001082B08E140
              A04E0208A04EDACC050161041080B082108E6E0275678F00EA26CE7C10104400
              01082A06A140A06E0208A06EE2CC070141041080A062108A6E0221B2470021A8
              33270484104000420A4118100841000184A0CE9C101042000108290461E82610
              2A7B04108A3CF3424000010420A0088400815004104028F2CC0B010104108080
              2210826E0221B3470021E933370402134000810BC0F4100849000184A4CFDC10
              084C0001042E00D3EB26103A7B0410BA02CC0F818004104040F84C0D81D00410
              40E80A303F040212400001E133B56E0212B2470012AA400C10084400010402CF
              B4109040000148A80231402010010410087C88699B7B0E7EA6D9EA1EF1ED57CD
              D6D20B7EEFF2B6B0D87DC9B7A776B5BA0F2FEC3E78D335FBF6BDC6F055290129
              8323002995A8208E85C5A54E7E810F9B716B3FF5D3DCE8DBD5C6D8379BC197B5
              E68DBE5DE98CF9BC6DAC1DBEF4E5D79D6AB6BAEB72682DED1B9CC62E41020820
              B1A2EEDADDFDE0F0E2B5D6EE2F9A9E35F69BC3F1FC2B880F171D8FFEB2082000
              59F5983B9A5D7B0E5E955FA8AE611E9F7B90491DDDDAB17C0E443009543C8F23
              80786A3536527F513EE7DCDA93634F28FB81FF8BE0C0DFCB1E56CB7892F24400
              92AA31632CCDC5039FF417BFFFD1DD5C3463D7124E7717E473FB370F3F5AC260
              0C118800020804BEE8B4FEE23B6AAC7BA4E83845FB5B6B7EEE633952741CFA87
              218000C2702F346BB3B5F49C1FE073BE49D96E5C682D3D2B2518E2989E000298
              9E958833FDB3ED69636C8097FC66DB2FFFDB828B7D6CF98F23DB9EA7FD4169F9
              23006915D9261E7F81FDD63FBCC337B15B734FF777628323B02D0410C0162432
              0FF837DB1EF091BDDB37D99B33EFF2A2FA9EEC20896E4800010C4908DEDFDCDA
              FF01FF66DB570587B839B45BFC7B02D76C3EC87D79041080BC9A6C89A8611ABF
              D87250F801FF9EC063C243AC3D3C891322008955D910937F39FDFC86BB51DDF4
              B1FF29AA8015068B000417FDE6DDDD2B7D7817FA16EB76C997F71CBC2CD6E035
              C48D000457B9D1304F090E6FAAD0D6DCDAF1A94EE4A42004104010EC93271D3C
              FB4F3E51FE19E7DE72DB3DE2FE6EA16E6C52E74300422BE39FFD7F2934B499C3
              5ADD7192BF0D98995A3D1D10403D9CE799E59C793A09ED739ED0B8D487850004
              2E81666BFFD704865528A48556F7BA4203D0B9120208A012AC45076D2C171D41
              5A7F6B4C4F5A4C75C523791E0420B33A29BDFC1F12E6C7802109417B0420A818
              840281BA092080BA894F98EFE6DD073E32E194681F6E2E2E5D1D6DF089068E00
              8415B661DDC78585545A38D6363E5BDA60910C243D4C0420AE42F6EDE2422A2D
              2097706EA541AA752004502BEE2926B3E95E246BCE20802996409DA720803A69
              4F3757CA1749CAB94D575D61672100610531C6FD575C4804341781183A210071
              55B27F1417527901A59C5B79946A1C0901D4087BCAA992BD481AD6249BDB94B5
              15771A0210571297F04592F4AB1B712B699A8010C034946A3CC7EDB03FAC71BA
              7AA7B2F647F54E186EB658664600C22AD53FD0FEBDB0904A0B67E5D0EDD17FC2
              516930840C840084148230201082000208417DC29CCE98BF4C3825C6875F8931
              E8D4634600222BECBE2032AC024179A9350B748FAA6B4CC1220081D5EA679D63
              02C32A14523F6BFFB8D00074AE840002A8046BF1419D717F2E3E8A981178F92F
              A61467078200CEE621E6DEA9D5D7BE474C30050339C7EC7867C121E85E110104
              5011D8A2C31EBE77B77FD674FF2C3A8E80FEFF7930DBF3370171D412426C9320
              00C1156BD8F89F39FDB3FF3B0423561F1A0210BC04BE7FE8F6977C78D1BE2168
              8D7D82677F5F41C11B02105C9C3CB45ED6BE36DFC7D856B2BD7C06A0F0C22100
              E105CAC373E6D4A5F93EA6767AEDF4DB628AB78C58631C03014450B57E76D733
              C6996F4410EA204477F70FEEB933A55F630EF24A6F870022A9696FB9FD2D1FEA
              CF7C93BE3DD2CB3ADF961E24F1AD134000EB1CA2F8DECBDA1FF381FEC137A9DB
              333EC64F4B0D8EB8B61240005B99883EE22FB0CB8C95F79901D698A33EB6E8DE
              AB28ABD8B18E830022AC5CEFD0DE2F1AE76E1313BAB38B2B59FB7A31F110C8D4
              0410C0D4A8649DD85BEEDC674FAF5E183AAA93ABAB6FED2DEFBD27741CCC3F1F
              0104301F3711BD56EEBBE3AFFE65B77FF5ED1EAF3D206B1ECDE73E7CEF1DCFD7
              3E371396460001948632DC40BDACF3A1D55327CFF73F16BC584314CF9E3879E2
              F5BD43ED4FD530571453C41C240288B97A1B627FE8BB77BFE87F2C383F1781AB
              E01385FC98C7DDCB27CEED65ED4B8EDEBFEFC486A9B9193101041071F146859E
              8BA09FB52FF217AA75C65DEB2FDCB93F5ECCF73DBEEADCCE7C2C3FE6CE7E7F1F
              FFB56814F4888F2180888B3729F47ED639D61FC820BF884DC35EECACB9D53873
              C038FB13DFFF69E7CCAFFD9B0847ADB1DFF1F7BFF2EAABA7DE949F9B37DF77E7
              43CB9DE3FE385BA2041040A2851D9556EFE0DEE7FA87DAF7F796DB6DFFCEFD75
              FE22BFA2BFDCBE6AC5FF0A6F25DB7BA7BFFFE09107EEFAD7A8BE1C1B4D20F6A3
              0820F60A123F040A10400005E0D11502B1134000B15790F8215080000228008F
              AEBA09A4903D0248A18AE400813909208039C1D10D02291040002954911C2030
              270104302738BAE926904AF60820954A920704E6208000E680461708A4420001
              A45249F280C01C0410C01CD0E8A29B404AD9238094AA492E1098910002981118
              A7432025020820A56A920B04662480006604C6E9BA09A4967DF40268B6BA8E06
              83506B207621442F80D80B40FC100849000184A4CFDC10084C20BC009C3D1298
              01D343602A02A59F2460ED0717C0AA59CB3F8DB674B60C0801E90424ACFDE002
              E063A7A52F53E2AB8A8084B51F5C00EB705D777DCF770868212063CD8B10402F
              EB74B4949D3CE3245076D452D6BC0801E470F37F6395EF6910489D80A4B52E46
              00FDAC732CFF5F74A9179FFC7413C8D778BED6A5501023801C483F6BEFF4FB57
              7C6383408A045E19AC7131B98912404EA597B5DFE0F72FF8C6060111044A0AE2
              85C1DA2E69B872861127803C2D0FEA02BF7FD2373608A440E0C9C19A16978B48
              01E4943CB0F74B7AB3248F8906815909E46B385FCBB3F6ABEB7CB102C801F4FD
              1B831E9E3546C6EF4CF3986810988E80EBE66B375FC3D39D1FE62CD1021822E9
              659D4E2F6B5B67D6DEEB8F3DEC1B1B046A2130E3240FE76B345FAB3DBF6667EC
              1BE4F428043024D3CFBEFE9B5ED6BEC1374B6BC3C03F29085B0737E46B74B85E
              63D847258018801223046222800062AA16B142A0640208A064A00C970E010D99
              20000D552647088C218000C680E13004341040001AAA4C8E10184300018C01C3
              61DD04B4648F00B4549A3C21308200021801854310D042000168A93479426004
              010430020A877413D0943D02D0546D7285C0260208601310EE4240130104A0A9
              DAE40A814D0410C02620DCD54D405BF608405BC5C917021B0820800D30B80901
              6D041080B68A932F04361040001B60705337018DD923008D552767080C082080
              01087610D048000168AC3A3943604000010C40B0D34D406BF608406BE5C91B02
              9E0002F010D820A0950002D05A79F286802780003C0436DD0434678F0034579F
              DCD5134000EA970000341340009AAB4FEEEA092000F54B403700EDD9FF0F0000
              FFFFA63E2CDF0000000649444154030008F83188ED3F6D490000000049454E44
              AE426082}
          end>
      end
      item
        Name = 'Load'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC9D698C24E759C7DFB767661DEF0E64250BC960E3
              78E32501BE20105F38428282028140027841C85EBB6B6C564861B66B76C7EBD8
              041820B677A77B0E6F901006ED6C888884CD1144382222634C404888285F7228
              A7AF3852940F4EBCB19DDD9DAEBC35DBB3EEEDEDA3AAFAA9AAF7F8B5AAA6EB78
              DEE7F83DD5FF99AE79A7A7A178400002C1124000826D3D854340290480AB0002
              01134000026E3EA5874D20AD1E014829B0422050020840A08DA76C08A4041080
              94022B040225800004DA78CA0E9BC06EF508C02E099E211020010420C0A65332
              0476092000BB2478864080041080009B4EC96113E8AF1E01E8A7C13604022380
              0004D670CA85403F0104A09F06DB10088C00021058C329376C0283D523008344
              D8874040041080809A4DA910182480000C12611F0201114000026A36A5864D60
              58F508C0302A1C834020041080401A3DACCC43871E9D49D761E7381606010420
              8C3E0FAD72FE86672EA6EBD0931C0C82000210449BAF2EB2D9EA7C61F7681477
              3EBFBBCDB39F04465585008C22E3F1F1E652E77EADD52D7D251E342270A26F9F
              CD4008200081347AB7CCC3474FDEA413F5C0EE7EDFF3A93B96D66FE8DB673300
              020840004DEE2F71B631FB74FF7EFFF64CD27DAE7F9F6DFF092000FEF7F87285
              E6C7FC972EEF8CD830362F8E38C56147098C4B1B011847C7A373CD56FB5F4D39
              D79A75D2326F44E0B149469CF7830002E0471FC7567147DC79BBD6FA17C61A5D
              79F2D6E6D2FA9BAE3CC49E8F0410001FBBDA57D3A1A5F56B6794FA97BE439936
              75D27DF2D0A147CDD04CE618394A000170B47159D39E4FBA13DFF78FF2C524A1
              5164DC393E29530460122187CF47F1DAC83BFE59CB8A98249415959376088093
              6D9B9CF442AB637ED79FDC34D972A2C5417303F1DE8956183849000170B26DE3
              93BE7371F59644ABFBC75B653F6B6E209EBC6DF1D48DD94760E90A0104C0954E
              E5C8B331D3B83CCF3FC7B0B1A67B66669E1D6BC049EB0864490801C842C9219B
              A8D5B95856BAE67E009384CA825B935F04A026F06584352FD0FF525A95F9ABBB
              79733FE06F150F6F0820009EB4D2BCF87FCB94F2D3662D7531F7037EFDCE56E7
              674A0D82F3CA08200095A12E2FD06D8BA7BFDB78FF90592B591A5AFDE75B5656
              66150F6B09644D0C01C84ACA62BB3D33E7BF51757A075E98BF50754CE2C91340
              00E49956EA316AB5BF5A69C0BE60119384FA68B8B98900B8D9B79DACCD0B7053
              697DFDCE4E3D5F0E36973AEFA92734512508200012146BF071383EF543266CCB
              ACB52E3A510FDDCD24A15A7B30183CCF3E0290879645B6B36AE6D3B6A4B3CD24
              215B5A913B0F042037B2FA07981FFD93FAB3B8328385788D4942572271620F01
              70A24DAF26192D753EF1EA9E3D5B894AD24F12FA3B7B3222932C0410802C942C
              B15938B6F6DB2A513F6A493AC3D2F8B56871F5CDC34E70AC1A0279A320007989
              D5647FC7BBFFF4BAA49B3C2219FE9C6EEC4D57499F6AA6F1C40A9384449196E9
              0C012893AEA0EF99B957BE2EE84EA986FEE5C7368EBD9CAEE9B6A4EFA7992424
              89B3545F0840A978659C47715BF6C5AFD4E35BEBC73FB29B5D6FFBF1DD7D8967
              73A3927F372601B2641F0840C980A7756F5E487FA194BE4EC93DCE6F6D2EBF75
              D05DEFD8F9C1E353EC1F5C6092D014F8F20F2D3202012842ADA23151BCFA6326
              D4DD66155BCC0BFD9A51CEC69D1B3566DCF1844942E3F058710E01B0A20DA392
              68FCFFA833458E6BD5E8FF87A06AD84367B051391E4C12CA01AB065304A006E8
              59429A1FFD8527FB240F9CD93CF6A549B12FD9240F4CB2CB73DED4722E8F3DB6
              D5114000AA639D3952D4EA7C26B3712643FDCCD6E63DEFCD646A8C2ED9EA67CC
              A6D4B22F6AB5FF5ECA197EAE2650F4080250945C49E316E2B55869F58392EEB7
              368FBF2EAFBF2263C6C6D0FA57A3A57526098D8554FD4904A07AE62323DE1E6F
              7C6FA2928D9106054ECCBD746E5F81613B43A619BBE360F04BD27DE2C8913F9F
              1B3CCC7E7D041080FAD85F15794E6D3F7FD5C1690EE8C6BB1E7964A5F0BF06DB
              196B7C4C93C2E0D80B7B5F94FC55E3A07BF67312400072022BCBDCDC2813FD58
              2F7307F189AD8D63FF386DBEA98FD4D7B47EFAC7375B1DF1FF5BD0EF3FB4ED69
              EA4500A6A12734D6BCF8FFC6B84A3FD8D33C892C17CE6E2EFFAC8827E3A4E74B
              EC3300B556B74471FB3EE39AA566020840CD0D682EADBEC9A4F01B66155BB636
              97F78839EB3992F7A91FBC7BF1F48D3DF73CD5440001A8097C1AF6C89123733A
              693C996E4BADDDEDEE41295F837EA47D6FCF9CE7DF8D0D42AE781F01A818787F
              B80B7BDF207A43CCFC68FDE007DE7FE28BFD3124B753DF690C499FE6ED0F9384
              A6003AED5004605A8205C79B0B5FFA46D8B36736967FAF603A9987F562487EE7
              DED78C3BFF9039010C45092000A238B3398BE2B5F4853A715E7E366F97ACCC7B
              F49B2E6D95FF553A9656EA5DCDB8FD96F23327C2200104609048C9FB878F6E9A
              176AF23EC93017679379497F597C49C7D44AFFC7A1432BE2372FB3D412B20D02
              5071F7671B179F960CA993EEAD1FECDCF32D499F597CA531D3D8596CB3DACCDF
              30FFEDACB6D82925C1000190A098D147D46ABF9CD1349359A2D493671E3E51DB
              27F1A6B1D31C32259BD1288A9924941195881902208271B213F31EF7A34AEBD7
              4CB6CC6C71F1ECE672ED7F5CD3CBE162E6AC271BDED26C75EE9F6C8685040104
              4082E2041F516BF51DE63DEEDB2698E53A6D6EC459F34735D2B9985F353E101D
              5BFBFE5C40302E44000128842DFBA0234756F62ADDF8A7EC23265B76E7CA9BEC
              3339FA700BF19CBA89E4E7110C4FDAE1A352A92300522447F8B9B0775EF4065D
              92A8931F689F286DB2CF8832261E4E734A739B6898C3C0DC0F6092500E5E454C
              118022D4328E3117B0F477B1E7CE3EBC6CED1FD1F4727B2E239E2C66FBA278ED
              C3590CB12946000128C66DE2A8286E3F688C44DFC79AF7DAA2FE4C7EE28B7C8E
              C93B178EAD89FD65A378C18E3B44004A68E0ED4BEB0795D2A2DFA9F537B725FF
              5C5895F990CE35E9268F1F5A6192D06ECF249F1100499A3D5F734957F4BFE268
              9DFCE69933F7BED8736FFD539A6B9AB364A2F32F30494892E7AE2F04609784D0
              731477247F279E66F5F1331BF73C9A6EB8B4F672FEB864CE86AD75373F25EBAB
              C3170220483D5AEAFCB771376356992551DBE63D75FA812132FE2AF6B293BBA9
              4130ECEBA3B89DFE2195A0CBB05D210042FD8F5AEDDB55A27E52C8DD8E9BAD87
              976777361CFE225F837E5FC89384A42F05044080E8917B4FBE5669FD41015797
              5D24DDEE1B2EEF38BE215E0B9384C4AE08044000E5856FCFBE20E0A6DFC5EAD9
              D327446F24F63BAF7ABB57CBAA645CF31397E8042BC9DC5CF285004CD9ADA8D5
              F9EA942E06877FC5BC77BE77F0A0EBFBBD9ABE225687D67BCD4DC1A93FF65C2C
              1F471D210053342E5A6A3FACB4BA7E0A17570D352F146F3F29B784DA7EE5CEA3
              6B6FBD0AA2A707CA280B012848355AECFCB04AF4D182C3870E3BBFBDE7B5434F
              787450BAC64623F9D8DB174F5FE311A24A4B41008AE29E519F2A3A74D8B8A49B
              DCF6D7EF3FFACD61E77C3A96D698D62A59D3F533E75F91F417922F04A040B7CD
              7BCFA4C0B0D14312F53F674FDFF3A1D1067E9DD9A9D5D42C5995E90993840A00
              450072423317DA27730E9964DE35BF2BFFA94946BE9DEFD5DC15ACEBF5E686EC
              7B05FD59E5AAAC6410801C6417963ABF63CC7FC4AC628BB931263773502CAB6A
              1C89D7AED59F1C3E7AF2A66AB2F7230A0290B18FD1E283DF9324EACF329A6732
              DB6EE8376632F4D8489AC16C6356F453973D46BF531A02B08321C397993D5FCB
              6095DD24516B7FB57EFC73D907F869B9C3C0B090AC2E8ADB4C12CA081401C800
              2A8A3B5FCF6096C7E479F31E7839CF009F6D7B2C9E97AB51EF35F703443F8751
              2EB7FC9ECA1C81004CA0DB6CB5FFD2985C6756B1C5BCF7BD41CC99278EC49968
              F58E85B8FD739EE029AD0C04600CDA85A5F51FD75ADF35C624F7A9B96B2EEECF
              3D289001D26C12A5FF7D71914942E32E1F0460341D9D24DDFF1B7D3AFF9944A9
              3B1E39F59E6FE41F19C688944DCA48B2DA734C121A8B13011881278A3B92BFA3
              564AEBFF3DBBB92CFA27C3CAC3C70E23C34AB2B466ABF325497F55FA2A3B1602
              3084B079F17F76C8E1690E75B7368EFFC4340E421ADB632526C05AAB03CD78ED
              F7436298B556046080D442AB73DC1C7AA3592597461477923256C9248BF82AA3
              A6D4A7C945F4DAD42AF9E3BBDEDD799DF1CBD2474014729F5F2737177EF7D4F7
              255A759C4C9EA42712E8CEA9A7148F2B0820007D3892D919B90FACE8F3CBA63D
              04A278CD994942555043007A94A3B8E3FD9FE2F64A0DFC29D9DB8C3B1F091CC2
              E5F2110083C2BCF81F334FDF655696000868A57EE9CEC5D5B70550EAC4128317
              806869FDCD86D2AD666509884063A6F1D16673E53501953CB4D4A00560E7FFCD
              25DD278692E1A0F704F4FEF9976D2DB2AABC821600FEDF5C559799BD719A4B61
              4F120A5600981D66EF8BB2CACC74A20E44ADCE1F5419D3A658410A40DAF07476
              984D8D20971A0968F547771D0F7392507002D08C1FBA599986D778B911DA4202
              DD6D65CD242155E1233801D06AEECB15F2259443049A71E72587D21549352801
              88963AC1DFF515B96A3C75A295BA366AB5FFD9D3F28696158C00989B7E1F5389
              0AFEF7BE43AF020EBE4A40EB5F34F7887EFED5037E6F052100D152FB9DE6A61F
              FF43CEEF6B59AE3AADFEADB952CF2421B922B279F25E000E2FB7F7A9447F381B
              0EAC207089807E218C4942DE0BC0EC457DEE524BF90A817C04A2B8E3FD0D63AF
              05C034F0D97C2DC71A025710B8B919AFFDE115473CDBF15600CC8BFF94E9D58D
              6665814061025A252B3B73470A7BC83EB00E4B2F05A07974F5070CCC13666581
              C0D4047C9E3BE2A500A8C6F685445D38E0C23AF5D5E9B803177A94E6E8EB4F01
              5E0AC0D9CDFB9E726575FCF53B75FAAEF429CD73EA622D74E0A50058C8999420
              3096405D271180BAC8131702161040002C68022940A02E0208405DE4890B010B
              08200016348114C2265067F508409DF4890D819A092000353780F010A8930002
              50277D6243A066020840CD0D207CD804EAAE1E01A8BB03C487408D0410801AE1
              131A0275134000EAEE00F12150230104A046F8840E9B800DD523003674811C20
              50130104A026F08485800D0410001BBA400E10A8890002501378C2864DC096EA
              11005B3A411E10A88100025003744242C0160208802D9D200F08D4400001A801
              3A21C3266053F508804DDD201708544C0001A81838E12060130104C0A66E900B
              042A268000540C9C706113B0AD7A04C0B68E900F042A24800054089B5010B08D
              0002605B47C80702151240002A844DA8B009D8583D02606357C8090215114000
              2A024D1808D8480001B0B12BE404818A0820001581264CD8046CAD1E01B0B533
              E405810A08200015402604046C258000D8DA19F28240050410800A2013226C02
              36578F00D8DC1D728340C90410809201E31E02361340006CEE0EB941A0640208
              40C980711F3601DBAB47006CEF10F941A0440208408970710D01DB092000B677
              88FC2050220104A044B8B80E9B800BD523002E74891C2150120104A024B0B885
              800B04100017BA448E1028890002501258DC864DC095EA1100573A459E102881
              00025002545C42C0150208802B9D224F089440000128012A2EC326E052F50880
              4BDD225708081340004204B5F00000034D494441548481E20E022E1140005CEA
              16B94240980002200C1477611370AD7A04C0B58E0DE41BC59DA4CE75201D761D
              23800038D630D28580240104409226BE20E0180104C0B18691AEBD045CCC0C01
              70B16BE40C01210208801048DC40C0450208808B5D236708081140008440E226
              6C02AE568F00B8DA39F286800001044000222E20E02A0104C0D5CE9137040408
              200002107111360197AB47005CEE1EB943604A0208C09400190E01970920002E
              778FDC2130250104604A800C0F9B80EBD523003577706B735987BCD68C3FF8F0
              0840F09700004226800084DC7D6A0F9E000210FC250080A2047C188700F8D045
              6A80404102084041700C83800F0410001FBA480D102848000128088E616113F0
              A57A04C0974E5207040A1040000A406308047C218000F8D249EA804001020840
              01680C099B804FD523003E75935A2090930002901318E610F0890002E05337A9
              0502390920003981611E3601DFAA47007CEB28F5402007010420072C4C21E01B
              0104C0B78E520F047210400072C0C2346C023E568F00F8D8556A824046020840
              46509841C0470208808F5DA526086424800064048559D8047CAD1E01F0B5B3D4
              05810C0410800C90308180AF049C118066BCB1BF193F74332B0CECBF0636F6BB
              2218CE088052AFECD76AEECBAC30A8FA1AC81B2FBD56110057089027040226E0
              D04F00017789D22150120104A024B0B885800B04100017BA448EB511F03D3002
              E07B87A90F026308200063E0700A02BE1340007CEF30F541600C0104600C1C4E
              854D2084EA118010BA4C8D1018410001180186C31008810002104297A9110223
              08200023C070386C02A1548F0084D269EA84C0100208C010281C824028045C13
              80A74C6358958281DD0C942B0F6704E0ECE67D4F6D6D2E1F608541D9D7C0B4FE
              D36B15017085007942206002CEFC0410708F281D02A51140004A438B6308D84F
              0001B0BF4764582181D0422100A1759C7A21D0470001E883C126044223800084
              D671EA85401F0104A00F069B611308B17A0420C4AE5333047A0410801E089E20
              1022010420C4AE5333047A0410801E089EC226106AF50840A89DA76E08180208
              8081C0028150092000A1769EBA216008200006024BD80442AE1E0108B9FBD41E
              3C010420F84B00002113400042EE3EB5074F000108FE12081B40E8D57F070000
              FFFF2AEC415C000000064944415403009D40C979BA337A480000000049454E44
              AE426082}
          end>
      end
      item
        Name = 'Clone'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600000D34494441547801ECDB51885C571DC7F173B7CD069A0616450914EB46
              4BF5415F6CA020F850B0A00FFAB605FB948D9282D4B8CDCE2AA118A60A09B85B
              77764B852EA4B3F4C13EEC9B3EE4C182E0431F4AE38B3E5834245A84405142DD
              04B361F77AEE7616A7C3AC3377EEB9F7FCFFE7FF5DE6E4CECCDE7BEEFFFFF9CF
              FEB26DE994E30B0104CC0A100066474FE308384700F02940C0B000016078F8B4
              6E5BA0E89E0028145808181520008C0E9EB6112804088042818580510102C0E8
              E069DBB6C041F704C0810447040C0A100006874ECB081C08100007121C113028
              4000181C3A2DDB16E8EF9E00E8D7E03902C60408006303A75D04FA0508807E0D
              9E23604C8000303670DAB52D30D83D013028C26B040C09100086864DAB080C0A
              10008322BC46C09000016068D8B46A5B6058F704C03015DE43C08800015072D0
              7373EDE9F985E50BF30B2BBF9AFFE1CABBFE7883B59298C1F29FFD8C7FEDD7F2
              99855F7CAEE44744D5E904C018E33A7BF6B523FEC3F05BFF839E3FFCC8C3F79C
              CB2E39E7BEE332F7843FCEB25C6206D9179CCBBEE5572B777BD7E7175672BFFE
              F9DD73CB5F72897D11002306EAFF96FFEBFD87FEBDE35CF675C79765814FEC4D
              657FF44190CF7FFFE5CF688338AC5E02E01099D32FFCFC6BC5B0FDDFF29F3FE4
              14DEB62A309DFFDD7F36DE4DA17D0260C814E75F58B998E553BF1FF22DDE42E0
              40E0091F021F1EBCD07A24000626E77FF85F72B97B69E06D5E22304CE0B80F81
              7CD837B4BC4700F44DCAFFDAFF0DFFC37FB1EF2D9E223052E0CCC2CA7B234F8A
              78C2FFBB3501D0D3F9E60FD68F66F9D4D5DE4B0E088C2DE07F0578FCF4C2F24F
              C6BE40D08904406F18271ED8B9D57BCA0181D20299CB7EDA6EB7D5FD3CA92BB8
              F464C6B860FEDCCB5FF5A7CDF8C503818905FE76FB98BABF44088062DC53F9EF
              8A030B816A02D9A7AA5D1FFEEA513B9A0F80B3EDD71EF248D37EF140A0B280FF
              AF02572A6FD2E006E60360E7F6878B0D7A73ABF405CE686AD17C00F87F79F363
              4D03A35604420A980F008F79CC2F1E082427304E4304C0384A9C83400981B9B9
              B9074A9C1EF55402A0227FEEEE9F64A565E03F1237FD9AF871EC91AFA8F9BF05
              098089C7FCD1859B9D0B375969197C34591B7F120036E64C97C604C66D970018
              578AF310485080004870A8B484C0B80204C0B8529C8740820204408243A525DB
              0265BA2700CA68712E0289091000890D9476102823400094D1E25C0412132000
              121B28EDD81628DB3D0150568CF31148488000486898B48240590102A0AC18E7
              239090000190D03069C5B6C024DD130093A8710D028908440F80F985951B5556
              2273A00D04A208440F00DFF56CC5E52FE7810002930848088049EAE61A0410E8
              1398F4290130A91CD7219080000190C0106901814905088049E5B80E81040408
              800486480BB605AA744F0054D1E35A04940B1000CA0748F90854112000AAE871
              2D02CA050800E503A47CDB0255BB2700AA0A723D028A050800C5C3A37404AA0A
              10005505B91E01C5020480E2E151BA6D8110DD13002114D90301A5020480D2C1
              51360221040880108AEC818052010240E9E028DBB640A8EE09805092EC838042
              010240E1D0281981500204402849F64140A10001A07068946C5B2064F7044048
              4DF64240990001A06C60948B4048010220A4267B21A04C8000503630CAB52D10
              BA7B0220B428FB21A048800050342C4A4520B40001105A94FD1050244000281A
              16A5DA16A8A37B02A00E55F64440890001A064509489401D0204401DAAEC8980
              12010240C9A028D3B6405DDD130075C9B22F020A0408000543A24404EA122000
              EA92655F04140810000A864489B605EAEC9E00A85397BD11102E4000081F10E5
              2150A7000150A72E7B23205C8000103E20CAB32D5077F70440DDC2EC8F806001
              0240F070280D81BA050880BA85D91F01C1020480E0E1509A6D8126BA27009A50
              E61E0808152000840E86B210684280006842997B2020548000103A18CAB22DD0
              54F7044053D2DC070181020480C0A15012024D0910004D49731F04040A100002
              874249B6059AEC9E0068529B7B21204C8000103610CA41A0490102A0496DEE85
              8030010240D84028C7B640D3DD13004D8B733F04040910008286412908342D40
              00342DCEFD1010244000081A06A5D81688D13D0110439D7B2220448000103208
              CA402086000110439D7B2220448000103208CAB02D10AB7B0220963CF7454080
              00012060089480402C010220963CF7454080000120600894605B2066F704404C
              7DEE8D4064010220F200B83D023105088098FADC1B81C8020440E401707BDB02
              B1BB2700624F80FB23105180008888CFAD11882D4000C49E00F74720A2000110
              119F5BDB1690D03D0120610AD4804024010220123CB7454082000120610AD480
              4024010220123CB7B52D20A57B0240CA24A803810802044004746E8980140102
              40CA24A803810802044004746E695B4052F70480A469500B020D0B10000D8373
              3B042409100092A6412D08342C4000340CCEED6C0B48EB9E00903611EA41A041
              0102A0416C6E858034010240DA44A807810605088006B1B9956D0189DD130012
              A7424D08342440003404CD6D1090284000489C0A3521D0900001D01034B7B12D
              20B57B0240EA64A80B81060408800690B9050252050800A993A12E041A102000
              1A40E616B60524774F00489E0EB52150B30001503330DB2320598000903C1D6A
              43A0660102A06660B6B72D20BD7B0240FA84A80F811A0508801A71D91A01E902
              0480F409511F02350A100035E2B2B56D010DDD13001AA6448D08D4244000D404
              CBB60868102000344C891A11A8498000A809966D6D0B68E99E00D03229EA44A0
              060102A00654B644408B0001A06552D489400D0204400DA86C695B4053F70480
              A669512B0281050880C0A06C878026010240D3B4A81581C00204406050B6B32D
              A0AD7B0240DBC4A8178180020440404CB642409B0001A06D62D48B4040010220
              20265BD916D0D83D01A0716AD48C40200102201024DB20A0518000D038356A46
              209000011008926D6C0B68ED9E00D03A39EA46208000011000912D10D02A4000
              549CDCE985CBB3ACB40C2A7E24545D4E00541C57E68EDC60A565E03F12B37E8D
              FD183CF1CE3FFEF0FEE07B525F13005227435D6A05B6B6B676B5144F0038B7AD
              6558D489406801F3019065EE726854F643408B80F90078F0CE7647CBB0A8539E
              C0604579965D197C4FF26BF301B0B1D1BEEB07B4E3170F042A0B6CAE2E7EAFF2
              260D6E603E00F6ADF7B2A7F68FFC81402581FC834A9747B89800F0E8DDF5C5B7
              FDE1B65F3C109858E0B333774E4C7C71A40B09801EFCADDD6975C3EB95CE2192
              40FF6D73975F6CB7DB7BFDEF69784E00F4A674F59573F7F23C7BA6F792030265
              04DEDFEC2CFDACCC0552CE2500FA26B1B9B6B8E572B7DAF7164F111829D0EDB4
              1E1D7992D013088081C174D75AE733973D3FF0362F111822907DE07FF8B321DF
              50F31601306454AF77165FDDCDA69E1CF22DDE42605F2077EE5AB7B3F8E9FD17
              8AFF20000E19DE1BABE7DFD94FF7DC5D3FE414DEB62AB0933DBAD9699D4AA17D
              0260C414FD3F123C76E4EEF169E7F2B7469CCAB7D316F8D7D45EFEE5E22F85EE
              2F17D5FCDF7EA34642008C12F2DFDFD878EE7EB7B3F474B7D3CAB667B68FE6B9
              7BD1BFFDA6CBDD357FBCC9728919E4EFF9C0FF8D5F2BF9DEDEE3C5DCFDFAE495
              F5A53FB9C4BE08809203DD6AB77736D75A97FC07E259FFDBC1297F3CC96A2566
              B0F4C56E67E9DB7E2D6DAEFFE82F831F91945E1300294D935E10282940009404
              E3740452122000529A26BD20505280002809C6E9B60552EB9E00486DA2F48340
              090102A00416A722909A000190DA44E9078112020440092C4EB52D9062F70440
              8A53A52704C6142000C684E2340452142000529C2A3D2130A60001302614A7D9
              1648B57B0220D5C9D21702630810006320710A02A90AA80F80D30B976759187C
              FC33B03A93EA0F6CE8BED40740E68EDC6061D0FF1970EE3F410320F40F9DA4FD
              D40780244C6A41409B808400D8D68646BD08A422103D00B2CC5D4E05933E10D0
              26103D001EBCB3DDD18646BD760452EF347A006C6CB4EF7AE41DBF78208040C3
              02D10360BFDFBDECA9FD237F208040A3022202A0BBBEF8B6EFFAB65F3C1040A0
              4101110150F47B6B77FA447164212045C0421D6202E0EA2BE7EEE579F68C0574
              7A44408A809800284036D716B75CEE568BE72C0410A85F40540014ED76D75AE7
              33973D5F3C67218040BD02E202A068F7F5CEE2ABBBD9D493C57316023104ACDC
              53640014F86FAC9E7FA7DB69652E77D78BD72C0410082F2036000E5AF5FF48F0
              D891BBC7A79DCBDF3A788F2302088411101F00459B1B1BCFDDEF76969EEEFADF
              08B667B68FE6B97BD1BFFFA6FFEDE09A3FDE64390CDCC70C1C5FE309A80880FE
              56B6DAED9DCDB5D6251F06CFFADF0E4EF9E349560B83CEFF0C363B178A40ECFF
              D8947A6EE9647501606938F48A40DD020440DDC2EC8F8060010240F070280D81
              BA050880BA85D95F9580B56209006B13A75F04FA0408803E0C9E22604D8000B0
              3671FA45A04F8000E8C3E0A96D018BDD130016A74ECF08F40408801E0407042C
              0A100016A74ECF08F40408801E0407DB0256BB2700AC4E9EBE11F002048047E0
              8180550102C0EAE4E91B012F400078041EB6052C774F00589E3EBD9B172000CC
              7F0400B02C4000589E3EBD9B172000CC7F046C0358EFFEBF000000FFFF7ACF66
              1A00000006494441540300B53F5A8810CEC9A70000000049454E44AE426082}
          end>
      end
      item
        Name = 'Next'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC7D0D941C5775E6BD3D33B2B0C7B66C93D80E602C
              3031123967371B126230207B93B39B600ED90D4A36C8B2BB5AB658C09AAE99E9
              9664EF060F2CC692BA5BD33D02B308ABBB890C6C62367FFC24E7240139FE2121
              90E49C049B04908C21C440B0657B2C2C69BA5FEE9B1FBBA7D5D5F5F3DEABDFDB
              A7DED4CFBBEFBE7BBF77EF37555DD5AF72C01F468011C82C024C00991D7A769C
              11006002E0286004328C00134086079F5DCF3602D27B26008902174620A30830
              016474E0D96D464022C0042051E0C20864140126808C0E3CBB9D6D0456BC6702
              584182D78C4006116002C8E0A0B3CB8CC00A024C002B48F09A11C820024C0019
              1C747639DB08F47ACF04D08B066F330219438009206303CEEE3202BD083001F4
              A2C1DB8C40C6106002C8D880B3BBD946A0DF7B26807E44789F11C810024C0019
              1A6C769511E8478009A01F11DE6704328400134086069B5DCD360283BC670218
              840A1F630432820013408A07BA60DFF98AC254EDD7F376758755ACBED7B2AB75
              DAFE1DDAFE0C95072DBBF6F06229561FB4266B9F29D855AAAB34F276ED76AB58
              99284C567E233FB1EF55298628F3AE3101243804F2766553BE58FD4861B2FA84
              6557457F1130F62DD1159F46803940781FB95AA4EDAD80701D95D703880D8B05
              E1F520C4750280EA700241CC00624308FC5DCCE5FED91AA09B08E2C7D664E5B0
              3555BB8EF4F29250049800123070DB673E7AB635B9EF7D94F0DFEE4D4604FC22
              22FC4F21E082D0DD405C0B02AF87AEF84CAF4DD664F5B824A5AD13F5CB42B789
              3B7444C0A98209C00999088FE7EDD9CBF3C5CA416BF93FEFE9E3CF3C0B22F75E
              4AF8F8279580F325298DE6167AC9EA8FAD891A9D7144082A773D1001268081B0
              847F90127E9765D7162C4A7A84CE3144BC397C2B8CF5F856C88907A56FB2E4ED
              EA3D85C2DE738DF5C68A3D23C004E0192ABD829B6666460B76A56651C2CB4209
              BF07408C40063E08B0459C37F2B4F4DBB22B7FB1F596CAFA0CB81D4B17990042
              1E96825DDB23037FFDF1F1D302702AE4EE63D81D5E3B3A8A47AD25227C286FCF
              AE8BA19189366998F14C00C3D0D1545798DCFF5ACBAEFE880A7D5F277669529B
              46355721749E9438D19789936974306E3E3101181C116BB2F60919CC4274FF86
              BAB9900A2F5E1110B05F6247E51BDBA6AB2FF7DA8CE5FC21C004E00F2F57E93C
              9DC25A76ED9845A7B4746FFD1DAE0D58C00D812BBA1D7854E25998A85DE326CC
              F5FE106002F08797A3F4567BEF06BABE7F469EC20288CB1D05B92230022227BE
              208980CA4D819564ACA19BBB4C006E08B9D4E727F6FD2A05A418859187058871
              1771AED683C0C724E6965DFBA01E75D9D5C2041070ECAD1DD58D169DE6632EF7
              B9802AB8993202E256390605BBBA43595546153001F81CF8FCE2357EE5388CC0
              D77C36657143080880398BC8B83051BDDA5017A955CB04E063682DBBF630D26D
              2A003C1FF8133B04440EEEB7ECEA73D7DBB397C6CEB8080CF2D22513800794AC
              62B54A8145FF68E4AFE73C3460912811386B0C3ADFB3ECCAD7A33422297D3301
              0C19296BAAF6B2C5C447981E2216E7AA67E98BC907C9C0BB85107BA9EC1480DB
              00C5AF6117DE3802231B6591DBD015BF46C70B00581602F600C04101F097B47E
              9A4A0217BC528E1D15BE633064F47243EA325D65D9B5AF52523C1673104E81C0
              4F76415CD7AA977040196FD7CB57D3F19BDB8DF26E2A95767DBAD99A2DFF5173
              AEF4C0DDF5C9476491DBADB9F21FD1F156AB3E5D6D374AB7529B77B6EBA537D3
              FA7C2A67E84610BF4CD83401F004C4FB43770C6ACF6E7EF70CDFA119304E4C00
              7DA05876F5ED54E89F9FF84F7D55D1EE0AF11C207C60ECC4C2BA9E843CABD598
              DEF2F17A39F43B11CD7AF9CFC98E6D4418E7D07A9120C63B6BD6026019119E84
              587DC4D9E36BC69FB126ABED589965D018AFAA99007A90CA172BDFA4DD7BA9C4
              61F937A0649A5F377FD6628235CA2F6ACD967EFBE0C1DD4F414C3F070E4C9C24
              42A836674B172EDA4C672502D022738F52897E117023917B67F3CCCC9AE88D89
              87054C00340E5B76EC7D29058640C457D26E94CB3741885F5C4E9E9F90C974EF
              CCCCA9280D52ED9B2E39DAE4CF2BA92042EE950828BF9380083FB9F1E3E3270B
              76754B8436C4A6EBCC1300257E7DCDC8C877221C91DEA47F55AB51FEEB086D31
              DA75B33E75B4599F96DF4920E4F03200711F44F41100F7D0D867FE4E41A60980
              02609EE2AF4825FC05614AFE57A492EAA47702B6B57FFA3BAD7A79534B5E2674
              F12D24B74025EC65F14EC1D652E527C3EED8647F7E74679200B64EECB98C929F
              FE09C0397EC0529615F0F5855171B10C7ABA9E9F55D6971205EDB9E9CF132663
              F3983B9B5C3A4225D4657401BF2FA74F0FB5D39874963902B08AB589D1DCE8B7
              C3C49F98465E0763AB51DA70B85AFE41987D27A9AF7B67A77E4C44700D15BACB
              08B78769BB9C3EDD9AAC1D0EB3CF38F4952902C8DB95070045232CE057129FEE
              A7CB6FC2C3EA3615FD1059BE7F9108006F0BCD2121AECFDBD5EF85D65F0C3ACA
              0C01D029FFD3F40DF41BC2C09C135F1FCA7427E44E4904F229467D5A9D3521C0
              A5142B62FBF68F8E394BC5B7C6AF6599200039A0048CF969A8E91A5F062BFFC7
              27B4352FED46B922B125720DE534FDF4D9CF9CFAADE9EA8B35BB113B75A92680
              CD9B378F2C27BF71E0058CACA7D3D60DC63BCA780744AE372C7F5968FC81A8B5
              1DF8E1B6F7A47B3EC2D412807CF1C4F84B5E17C2AD25BC43FE676AD7271FCD78
              6E86E6FEF29785EB7220AE33DD69770C1E9593BF98EE272AFDA92400795F57BE
              78C224A8744DFAA44C7CBA46FDDF26FB61DDCE081CAA973F27C7802E0BBEEA2C
              A5A16604BE962F567F5E8326A32A82284F1D01C829A4E57DDD2060786F236EA3
              6B529EE6DB3B604625E9B2E0B5A2D3B9CA642788F065BA8BB4C9641F51E84E15
              016C9BDC7FA19C42DA2090DD855131DEAA97EF34D807AB0E8040FBC0AEBF6AD5
              4BF2F90163B7F110F08B85A9DA7F08605E6C9BA4860066666646BBA2FB238348
              3729C0460E57CBCF1AEC83552B22405FC4BE0485B849518D6373D1157FBF75A2
              7E99A340C22A524300DF3E3E7EDA14F69D1C5E49C9BFCD947ED6AB178166A37C
              68ECC4BCB1C7BCE5ABCFE5F74C7AAD56D316B4752A08C0E4ADBE63EBE6C77E67
              FFF43F070598DB4583C0C18333275AF29200C0C8A3D7F27BA6BC3DBB2E1AEFF4
              F59A7802B0EC2A7D09AC0F901E4DDF950174646626845B893DBDF2A65604680C
              2F26859FA6A27D41E83C99F42706134D0094FC27B58FEA92C28314382F5BDAE4
              BF494780C67233F960E43D8DF28941D29DD825B10440C9FF15425DFFD44E5D51
              A0807927E9E6254508D0987E6AA1BB60E42DC351FF80486598124900965D2B91
              D33F4745EFD2E96E6ACD955B7A95B2B6B82070786EF7632362F412DDF6A0FC01
              51427F4A9C3802D86AEFDD00202ABA07B18B0B3FD33AB033B229AA74FBC3FA06
              237077C3FEFED88973F5DF2110E2FAC254EDD707F71ADFA3892200BAF572CE28
              8C3CAC1DCE1C5EF6F1D9DDFCAE3FEDC0C653E1C183EF5CB943A0D540D1159FA6
              184DD4F462892200BAF522E7F0D33A68F29765727E3AAD4A59592210A0EF05E8
              EC5DAFA914A3DFD7AB71B836D5DAC410005DF71F5175B6BFBD9C735FFEB2ACFF
              38EF670701132460D9D5C4CC369C080228D895ABE8BAFFCD3AC3F2E4DAD31726
              7DCE7D9D786459970112B83229EF1D48040108C0877406E84867CDCB3EB9E7D6
              98BDBE4AA787ACCB2F028F2FBED6CC6F2B677901704F12DE40147B02B0ECAAD6
              995FC4026CB8FBC0C4779D878E6BB288C09F1C983899C3DC453A7D1F3F3EFE63
              9DFAFA75E9D88F35015893D5FF434E9E4745CB82207EB9FDA15262AECFB438CD
              4A3C23706876EA89A53716796EE22698A3186EBB0945591F5B0290F3F981006D
              B3ED0810FB9BF5F29F470936F71D7F0496EF08E97B6C58C08D9BDF3D331E57CF
              634B00E7FCD42FFC50176802E158BB5E9ED6A58FF5A41B01FA52F053E4A1B61F
              108DAF3937B6B706634900F9626D33225E4083A06569CF965EA145112BC90C02
              4402F207449A7E4A2CCEA6EFB2B44E52A26B2062490088E2F774394803A9FD61
              0F5DB6B19E782340B1237F4AACCBC88FE952A4534FEC08C0B22BDA1EF55D5810
              FC9F5F67B4645097CE998528B663F70574AC08E07A7BF65200DC001A3E741FF6
              C3873F543EA64115ABC830027266217D730CE2954B311E1F4063450063D0D195
              B027DBF5D22DF181992D493202CD46F910DD91D232DBB08E18D789656C08A030
              51BD9A1C3B8B8AF2726CDD7C6C6FBB283BC70A224140CE36ACA9E3B396635D93
              3A3535B121009183FBD55C596A2D00B71DE179FC96C0E0BF5A11D0F5F2115DB1
              AEC3B9581040C1AEEED0E10CE9F84EBB3EDDA4352F8C807604E4CB47048096D7
              90698C79253F63410004EA9C9217CB8D5BF5526A5ED8B0EC12AF6286007DB7F4
              5A1D26058D791D7DF7EA889C002CBBF6C15E83826E0B109341DB723B46C00F02
              3910D7F9917792D515FB4EFABD1C8F9C0000C4AD5E0C1D2E839D76BD5C1F2EC3
              B58C801E040ED5CB9F234D1A7EA5AA23F6C91285255202B0ECAA9EC7233B272F
              55C0809B3202BE1198C79C9698D39603BE3D586A1029019009EA8F470A78A075
              E0366D3F1C229B7861045C119053C9D175FC6157417701CF39E0AECABF446404
              5098A85DE3DFDC335BD0FDD9379E79948F3002E61168D74B37E8E845572E04B1
              2532021039F1852006F7B569F4EDF32E23102A0242889DAA1D6ACA8540664442
              00DBA6AB5A5ED144B7FDEC405E732346401302ED4659CB4B6A74E5845FB72221
              806E0734CCCC831FF1EB2CCB33026610C0DB54F5BAE584AA7EA7F69110001973
              0515A5A5559F7EB792026ECC0868428062F14E0DAA947322880DA113803559D5
              F1C00E3FEE1B64B4FBDAE48BD577CBD2779877832020E0F620CD7ADB68CA8D5E
              95AEDBA1130008D8EF6A958B005DFB6F7311E16A170464E223C2876591DB2EE2
              5CED8200DD8D7ABF8B887BB586DC70EF64B544A80490B767D7ADEE3ED0DE3F06
              6AC58D9E474026BC4CFC9503725B1E5BD9E77560048E046EB9DC70508E2C5719
              59854A00089DCFAB7AB176EDE937A9EAC8727B99E832E1FB3190C7645DFF71DE
              F78EC03CE67ED5BBF460491D393258F3E0A3A1120099701515A5E5237BF8955E
              410194092E13DDA9BDAC93324EF57C7C3802F2E9409258A0A2B228E7889FCE43
              2380ADB754D6FB316C902C76C57F1F749C8FB92320135B26B89BA49491B26E72
              5C3F1801D1C5B70DAEF17E5447AE78ED2D3402181D85BBBD1AE524D79C2BFF81
              531D1F77464026B44C6C6789D5355256B6597D94F7BC20D09E9B56BECCEDCD15
              2F7DAAC884460000782D287DC47D4ACD33DA5826B24C68BFEECB36B2ADDF762C
              2F11508D55D55C9136782BA11040A1B0F75C6FE60C91CAE5B60EA9E5AA0108C8
              0496893CA0CAD321D956EAF024CC422F20A02156B5E4CC0B16396E854200DDF3
              46941FDB5D7E69A3A3235CB11A0199B83281571FF5BF2775485DFE5B66B7858E
              58D591335E4620140240802D5E8C719241C0079DEAF8F89908C88495897B664D
              B0235297D419AC75365BA9C62C026C0903B9500840DD11D4F2BB6B753B92A141
              26AC6E4BA54E26013FA82623668D13407E729FF2841DCDFAD4513FD0675DB655
              2FD13F10FD28300978C75447CCEAC81D378B8D1340AE3BA2F453492140D7EBC2
              DCB048553D9340F4C3BB6EBF160000100049444154A91ABBAAB9E30501E30420
              50FC572F8638C9E440DCE154C7C78723C024301C1FD3B52AB12B6D53CD1DA9C3
              AD1827003703DCEA9B8DF2213719AE77468049C0191BD33549885DA30490B767
              2F370D32EB77478049C01DA3B84A98CE21A30400A2B34B11580D2F5F50B42025
              CD9904221B48B51856CFA1A18E1B2500CCC16F0DEDDDB5B2ABE5B561AEDD6444
              8049208A81F61FC3BD56AAE750AFB633B78D12000838FFCC2EBD1F19EFACE569
              BFBDC3E5499249C0134CDA849463583187DC1C314B006EBDBBD41F383071D245
              84AB0320C0241000B4804DE21EC3B12680809873330F0830097800290322C608
              C09AAA29BE42194F6400FF485D6412080B7EEFB13CC822F55C1AA475E9983102
              00D1FDCDA52E82FE15FF2F684B6EE71D012601EF580597548C65E55C72B6DC1C
              0174E1EDCEDDBAD720884FB94BB1840E04980474A0E8AC4339961573C9D93200
              730480B87658C76E75CD7A59C3EBC3DC7AE1FA150498045690D0BF568E65C55C
              1AE691390218D62BD7C5120126816887258ADE9900A2403DC67D3209C478700C
              98C6046000D4A4AB641248FA087AB79F09C03B5699926412C8C6701B2180FCC4
              BE5729C2F7B4627B6EAE010126010D20BEA062684CBF2036784B434E0D546C84
              007223F8B3037BF3785000FC3DA4E463D95591E4626A1810E1C3599A635035A6
              5573CA691C8D1080E8C2254E1D7A398E005FF722C732C946204B24A01AD3AA39
              E5142966080073173875E8E5B810F084173996493E02592101D598168A39E514
              2946080045F742A70EBD1C47C41F7991639974208019B81CC02131ED65145573
              CAA90F330480A8740600D86502701AB1941EC7B49380624CA36A4E39C48D1102
              10AAC676F812C061BC527D18D34C028A31AD9C530E91638400A02BD42E01802F
              011CC62BF587D34A02A81AD38A39E51438660840F10C20971BE14B00A711CBC0
              F1349280534C7B1E4EC59C72EAC70C0138F5C6C7190146205608982100219E54
              F1B2DBED5CA4D29EDB261B0121E03DED46E9AE647BB1DA7AE59856CCA9D5D6BC
              B067860040ED4B3C312298005E18A34C6DA531F9E5006A886923CFC618210081
              A0740620448E0940464DC64A5A935F0EE3A09896C7BD16D59C72EAC70801A0E2
              1900882E1380D388A5F4789A937F71C814635A39A7168D38F38F110200F54779
              9900CE1CABD41E497DF22F8D9C5A4CABE7D492157D7F8D1080EAE90A22AA81D5
              E724EFC617818C243FA8C6B46A4E3945801102C8E5F07B4E1D7A392E406CF022
              C732C946202BC92F47A93FA6E5313F4535A79CFA324200D03DF5774E1D7A398E
              80FFD18B5C1264E4A41A492EA630CE52F24B0C5135A615734ADA30A818218066
              FDD6A3833AF371EC1C1FB22C6A080139918909D5594BFE650C95625A434E2D9B
              B17A6584005677C17B494480933F89A3E6DF662600FF98A5BE0527BFD9218E93
              762680388D460C6CE1E48FC12084680213408860C7BD2B4EFEB88F907EFB8C11
              002A3E0E7CA35D798B7E7759A313029CFC4EC8A81F578D65D55C1AE6813102E8
              76E1778775EC569713B977B8C970BD1E0438F9F5E0E8A4A537969D64861D57CD
              A561BA8D1100A05022006AFFF66186739D1E0438F9F5E038540B0AB55856CDA5
              21C619238076BD7C6448BF5EAAD678116299E00870F207C7CE674BA558D6904B
              8EE61A2300C71EB922160870F2C76218223722D604B07DFB9EF3234728850670
              F28737A8BD311C5EAFDE7B324A0002C463DE4D3953F2F439A3A5338FF2111504
              38F955D0F3DF5635865573C8CD62A3048028DA6E060CADEF0A2680A100F9ABE4
              E4F787971669C51856CE2117278C12C0D8F9E7EF75E97F7835E2DAE1025CEB15
              014E7EAF486996538C61E51C7271C728011C9C79E70997FE5DAB37CFCC287D83
              EADA41060438F9A319E4DED80D6A818E1C1AD6B7510218D6B1D7BAF1E3E74E78
              9565B93311E0E43F1393B08E2421768D138010E2636A808B5D6AEDB3DB9A933F
              EAB1578B5DF5DC71F7DF3801008E7ED0DD8CA1122F1E5ACB950311E0E41F084B
              D807D562573D775CFD354E00EDFAE4A3AE56B80858C5CAEB5C44B8BA07014EFE
              1E3022DAEC8DD9A026E8C81DB7BE8D13C09201D8595A07FC8B784FC096996C26
              A7DCD2EDB8D499B6D775E9C668953EE59855CC9955C638EF8442004274FF97B3
              099E6AAEF024C5428B08C8449509BBB8A3E18FD425756A509525154A31AB2167
              3C611D0A01B41B65B5E701C8151DA754A426334BBB51BA4B26AEAAC35287D4A5
              AA274BED75C46A5B43CE78C13C1402F06288AB8CF229956B0FA913682B920027
              7FC090E889D5801A426B161A012088FD8A5E299D5229F69DD8E6414980935F69
              C895625543AE78363E340238BAEE59E5FBF9F962F536CF9EB1E0F308F825014E
              FEE7A1F3BD614D56277D37EA6BA02357FA543AEE864600476666161CADF05881
              0877781465B13E04BC9200277F1F707E7705A89EE9828E5CF16A766804200D42
              40E52F030BC5BD574A5D5CFC23E046029CFCFE31ED6DB1B554F9C9DEFD20DB3A
              72C44FBFA11240B33EBDDB8F718364058E3C30E8381FF38680130970F27BC36F
              98D4E869BC6F58BD973A1D39E2A59F1599500960B9D32796D741576A8F5706ED
              3545EDFA4980935FD3E022BC5A51936A6EF8EE3E740240CCFD17DF56F635B0EC
              EA17FB0EF1AE4F0456488093DF27700EE279BBDA72A8F27C58476E78EE6C5930
              740268CE4E7D65B96F95D52695C6DC7609014902B22CEDF15F150410200F3D9F
              209B9A72C357D7A113C0A275889F5C5C2BFCE1B30005F0B8A9560474FCF7070D
              3911C4A94808A0353BBD2588B17D6DF82CA00F10DE8D06011DFFFD35E5846F00
              222180252B51FD67C2FC5DC01294FC373204B4FCF707F55C080A4064042020F7
              B3418DEE69C767013D60F066F808E0806B7FBF5668CA05BFDD2ECA474600EDFA
              E471049C5FB442E18F65D71E5768CE4D1981C00858C5EA23811B2F3794392073
              617937F4556404203D3D0D0BBF20D76A455C5CB02B57A9E9E0D68C803F04F2F6
              ECE5A07EDF1FF4E4803FDB7BA5232580C3F55DCA0C2A9D11800FC9351746202C
              04103AC774F4A52B0782DA12290148A345B7FB16B9562DF465CC3DAA3AB83D23
              E00501CBAE7DC049CECF715DB1EFA7CF7ED9C809A03DB7F3F3FD4605D947802D
              9393FB5F14A42DB76104FC212054A7B85BEC4E57EC2F2A0BF827720258B4BB03
              AF595C2BFE392EBA4F2BAAE0E68CC05004F2C58A9EE7F535C5FC50633D54C682
              005A074A0F0388A73CD8EB26324A970287DC84B89E1108828065576E45C40B82
              B45DDD463CB514F3AB8F46B1170B02908E0B18BD5CAE550B5D0A14ACA9DACB54
              F5707B46A01781ADA5CA390038F42537E0F1A32BD63D7637542C3604D0AE4F1E
              07402D7705A02B1E03FE30021A11185D404D9797F8C852AC6B344E41556C0840
              FAD0AA4F6F946B1DC59AAC7E4D871ED6C1085876555E566AC9159D31AE6364B4
              38A5C3901E1DFB7AB6836F0AD8582856B60557C02D1901801BA66A3F4D3814A8
              A82F026AEA4AF46A881D01B4EA25E5D9835720128877DF30B9FF252BFBBC6604
              FC20B069666674A42BFE093C7CBC88B41AA59217B93065624700D27971AA7BA9
              5CEB2823A2FB5D1D7A5847F610587F7CFCB436AF737899365D1A15C59200DA77
              ED7C1C04689BF6CBB2ABA73462C6AA328000C5CC77F4B9897FDBDA3FAD519F3E
              CB624900D23D3A5DBA56AE3595B17C51FD975B9A6C613531478092FFA364E24B
              A96859E88BBF9FD3A2C88092D81280F43587B9D7C9B58E8208AFCEDBB5591DBA
              58477A11B0262A1679B79D8AE7C54570B34B7DA4D5B1268043B3535F46C00775
              2184206CAB587DAF2E7DAC275D08583BF6BD1972D8D4E59510E25BF4A5F6A775
              E933A127D604201D6ED6A7AF966B6D05E17DF962E5666DFA58512A10B87172CF
              6B60247744A733ED46F90A9DFA4CE8CA9950AA5BA780110DCF5FBF6015221ECC
              4FD57EF18523BC956504E4A3E33931FA8F3A3138D5E924E271F44410807C7412
              116ED53940D8155FB2765437EAD4C9BA9287C066F913728547C71D3C6E7CE2C0
              AE44DC7E4E040148909BB3A53DB4FE3E157DCB087CEDE6A527BDF4E9644D8941
              60F3CCCC9A71D13DA1D9E067E9BADFD6ACD398BAC41080448080BD44AE759685
              AEF8A7C2E4FED7EAD4C9BAE28FC03B76DF79C1F8F1F193BA2DA5181DD7ADD3A4
              BE441180042287B98BE45A6711A2FB37F989CAFFD0A99375C517819B76CCBDF4
              ACE7C6F44CECD1E3E64277E1E53DBB89D84C1C011C9A9D7AA22BE0CDBAD1C51C
              7E2A6FD7A674EB657DF142207F4BF5D59D91535A9ECA5BE599C0E2E1B9DD89FB
              197AE2084082FEF146E92F0580B6FBB552A72C08A296B72BB1FBC596B48D8B3A
              0205BBF24B380A7AE69CE831478078B0D5989EEB399498CD44128044B75D2FC9
              9FFA3E2AB77516049CE2C78675221A0F5D92D805E09F19B0E69976BDACF75915
              03463AA94C2C014887E80B97F572ADBBD02DC7575BFC0322DDB046A62F3F593D
              2A89DD84011483E799D01B96CE44138004890600E5DA40192312103C9F800164
              435429C7100568FF47215D30187B527D2825F1042051323910723E8142916716
              923827A96CBDA5B25E26BF299BE7FFE5AF474DE90E536F2A084002669204E4CC
              423CC7A0443919256F573F343A8A474D598B4F77CEBBF7DE7B3BA6F487A93735
              0420413349022060A3FC8F229F1B977D71891F029B666646698C9EA36BC2F780
              A1CFC2A8B8B8D9DCF58C21F5A1AB4D150148F48C9280ECA02B1EA3FF30729658
              B9C7252608E4ED5A61FDD2145E679932293702971FAE967F604A7F147A534700
              1244D32440FF610A965D3DCDEF229468475F682C1E43104649593E817AA856FA
              76F4DEEAB52095042021324D02D4C7E871D13D91B7ABF7D0362F112040F7F66D
              4A7E415D1BFDE9EDCBD7CD8FC92750A99FD42DA925003952219000D0D9C01619
              8405BB7295EC938B7904AC1D1FFC09CBAE2D20A0F129DE640CCDCCCC2C98F72A
              9A1E524D0012523980726DBA08C08728281F37DD4FD6F55BC5EAFD30B2E60700
              62C434168362C7749F61EB4F3D014840970752FF0F40A4F255455C6CD9554145
              DB94E6ABD467788730AD53219E85301EBB3DB51C33A9473C130420479106F432
              147097DC0EA16C92C14A858940116CCBAEDD6511A9929A22953096AF52AC18BB
              931086037EFAC80C0148509A8DD27B04886BE4764885892020D094F487A8083A
              D57F574015019A6199923F5393C3648A006444B4EBE52342F324A352AF4B5921
              821F168A7BAF7491CD6CF5BB76DF79816557FF810A253EE87921A7473417A0B3
              B1559FAE0E134F635DE608400EA29C6494981E695BEF1C83A4D06579B1C091AF
              CB00CF17ABB7B9C866A6BA3051F96F1293E79666E9F999B01D5F1815E387EBBB
              B4CF1310B61F41FACB2401AC00452470096A9E6D7845B7DB9AFABD43063D956F
              58C58AB63720B9F51B977AF948B565578E90FF42E4F0F7A3B10BEFA318C0C3D5
              F2B3D1F41F7DAF992600097F73B6B427824B02D9F54AB90210FF4A2602955493
              41C1DEFF8A825D7B80FC14D0158F01A0F6A9DDC0E30741BC9E4EF93779144FAD
              58E609408E6CBB3E795CFE27408DAF21937A03942B9E278362E5DF285176FECA
              8EB9447F235D2856B6D1E5CE51F24550D67F4B807843005C7436795A8E75B35E
              FE921FA569956502E81959F91AB21CE6E2713A8E781199B6F7929153CFC9E4B1
              26AB3FA644BA63FBF63DE7D3F1582E3B88AC2C7BDF271408E800000515494441
              544EB2F73815F93C84108877D3E58E9109397C8380F0014AFED8E2E7DB1F0D0D
              9800FA403C343BF5650A123A438478DDC317B09612E9B6D3678F3E9F5C946427
              AD62ED1337DA95B7F4B9617CB760577EC9B2AB74ABAEF62CAD17937D9EC80A20
              B7973A8F559209219E941378B4664BBF4DB6F1D2830013400F18BD9BAD46E95A
              71AA7B69EFB1186EAF0114EFC8017E762509FBD6F379BB22AFB93F962F56F650
              29E7ED5AC19AACBCAD3051BDFA267B76832C72DB9AA8BC8D8E5B965D2BD199C6
              9D965DFD68DEAEDE47EBA7A82C2678EF5A2C4DB049B7EAC4D931C4E57993E814
              E437DA8DF2856999C0E379C7346DE434E949A59AF65D3B1F5F3C1B00D8975007
              CF414079CD7D1322EEA2B28F4E6D0E81C03F1439B8BF039D876591DB90C33FA4
              E34D00514184DDE4EF76047813AD133AE9A578448E5DBB317D2FF9A0B4A4B931
              138087D1A540DA4585F2013379AFD80344711239791A467EAA552F6F8C935171
              B58509C0C7C8D06DA38D4BB70CC5533E9AB16848086017DED8AA97D6DE539FFC
              D790BA4C7C374C003E8770E99661791D74E0353E9BB2B82104E8D46C82121F9B
              73A5070C75915AB54C000187B675A0F4B00C3AD1ED86FE0D7C409353D80CEF94
              63D0AC970E98722EED7A99001447B83DB7F3F33208E58F4910705E511D37F786
              C0CD1273BA24E3DF5378C3CB518A09C0111A7F1587EBBB1E69D6A7CF5DFA8E00
              1FF5D79AA5BD20805DBC7629F14B777B91671977049800DC31F225D15E7CAC78
              7ABD0C5440FCA4AFC62C3C08816FCAE9B8259ECDB9E92F0E12E063C111600208
              8E9D6BCBD6ECF41619B888B99F27E127A8F0E215018429891D955745351DB757
              53932CC70410C2E83567A7BE42817C11154440F9A86C08BD26B28B2FC94B2889
              536BB6647CC6DF4422A4D9682600CD80BAA9A3EF0976CB003FB66E7E0C41EC77
              934F7FBDF8C2C2827845AB5E422AAF979750E9F7393E1E320144341647666616
              9AF5F23405BD0C7C1442EC06C054BC70125C3E02E013F2059B4BBE97FFF3E10F
              958FB934E16A430830011802D6AFDA76A3BCB7559F1E9549D11DEB5E41ED9B54
              52B1A0C03F15D87D93F44D9676BD747DDC5FB0990AE03D38C104E001A4B0453E
              5ED9F92D4A946D5416CF0EE64FCD9F0B08EF17201E0BDB16DFFD213C2504FC5F
              01238B7742A40FCDC6F4AFB46777DEEF5B1737308E0013807188D53BB8F7AE99
              79FA52ECF676BDFC7299502B8508E11A996CF4CDE293EABDF8D420C47380E21E
              C8E15B5B4BD7EF8B644576AE6B374AEFA26B797E16C227A4518833014481BAA6
              3E89108EC8646BCE962E5C9584CB098970FA9598C3B7D335F70408B89DBA6DD0
              F66110F0592A0F01C85F375211F010207E1601A84ECC09C01910A288287E5374
              BB3FDD5AD6B76ADD28BFA8355BDEDADA3FFD59E04F6211600248ECD0B91BDEAC
              DF7AB4B97FFAFFB7EBA503AD46E9FD94C0366DDF40DB6FA5F206FACE41CE85BF
              71717B76FAADCD7A89EACAC5767DFA7DAD4679AE395BFEBDF6DCCE6FB8F7942E
              892C79C30490A5D1665F19813E049800FA00E15D46204B0830016469B4D95746
              A00F0126803E407837DB0864CD7B2680AC8D38FBCB08F420C004D003066F3202
              59438009206B23CEFE32023D083001F480C19BD946208BDE33016471D4D96746
              6019012680652078C50864110126802C8E3AFBCC082C23C004B00C04AFB28D40
              56BD6702C8EAC8B3DF8C0021C0044020F0C2086415012680AC8E3CFBCD081002
              4C0004022FD94620CBDE33016479F4D9F7CC23C00490F9106000B28C00134096
              479F7DCF3C024C00990F816C039075EFFF1D0000FFFFCF0D44E0000000064944
              415403003FF360B5775E62B40000000049454E44AE426082}
          end>
      end
      item
        Name = 'Refund'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC7D09BC5C5599E7F755BD1722BC40D8F725ECA0BF
              B1DBA6B5710D4E3B330AFE6C5B63770B81BA150415F2EABEF7AA92408FF2B055
              92D4ADD4AD17400DA4AA20A8D3A28E0BD0F39BE9D1208BB64BDB3D2D882C6155
              7608F008595EDD33DF794BACBCBCAABAF79E73EE7AEA774FDDED9C6FF99FF3FD
              EF76EEB919D03F8D804620B5086802486DD56BC73502009A00742BD008A41801
              4D0029AE7CED7ABA11E0DE6B02E028E8A4114829029A00525AF1DA6D8D004740
              13004741278D404A11D00490D28AD76EA71B8119EF3501CC20A1E71A811422A0
              09208595AE5DD608CC20A0096006093DD708A410014D0029AC74ED72BA1168F7
              5E13403B1A7A59239032043401A4ACC2B5BB1A8176043401B4A3A19735022943
              401340CA2A5CBB9B6E04667BAF096036227A5D239022043401A4A8B2B5AB1A81
              D9086802988D885ED708A408014D0029AA6CED6ABA1198CB7B4D0073A1A2B769
              045282802680045774DEBCE6C4FC70E56339D35A6E14ACCF1BA665D3F2CDB4FC
              434AF71866E5FEC954B0EE31862A3FCC9B16ED2BD77266E52AA3501ECC0F953F
              911B5C7B4A82214ABD6B9A0062DC0472667971AE607D253F64BD6498169B9D18
              F43FC21CF66D04180384ABC9D5022D2F0584F328BD13809D319910DE098C9DC7
              00681F0E22B05140AC3186FF8899CC83C61CB28920DE3086CA9B8CE1CA792457
              4F31454013400C2AEE92D1AFED6B0CADBD9A02FEF1F66044C01F23C2A7198303
              037703713E30BC001CF6C3769B8C216B2B27A5A583F67181DBA4157644A0D30E
              4D009D9009717BCEAC9E902B943718D347DE5D5B5F7B1D58E6F314F0D10F2A06
              077052EACB4CB493D50F8CC10A9D718408AA563D27029A00E68425F88D14F02B
              0DB3326150D023B41E45C44F056F85328D1F860CBB87FBC653CEB46EC9E7D72C
              50A64D0B768D802600D750C9CDB87874B42F6F962B06053C4F14F0AB01581652
              F04380F3D9FED957B9DF8659FEBF4B2F2F2F4A81DB9174511340C0D592372BAB
              79C35FB4756017031C0E587D04D5E1FBFBFA708B314584F7E6CCEAC2081A196B
              93BA19AF09A01B3A92F6E587D69D6598D68B94E87E1D5B29496C12C59C8DD07A
              99E34437138792E860D47CD204A0B0468CA1CAD7796366CCF905A93988929EDC
              22C0601DC78ED243CB46ACE3DD16D3F9BC21A009C01B5E3D73E7E814D6302B8F
              1A744A4BCFD63FD9B380CED00B81939D163CC6F1CC0F56CEE99559EFF7868026
              006F7875CCBDD45C73065DDFBFC64F6101D8091D33EA1DBE116019F6234E0494
              2EF62D2465057BB9AB09A017423DF6E706D77E881A24EB83ECFD0CD8408FEC7A
              B71C046EE0981B66E5CB72C4A5578A26009F756F2CB7CE34E8341F3399DB7D8A
              D0C584116057F03AC89BD67261512915A009C063C5E726AFF1CB5B210BF7792C
              AAB32B4280018C1944C6F941EBDD8A542456AC26000F556B9895FB911E5301E0
              01A07F91438065E02EC3B4B65F60568F8C9C712118E446A5260017281905CBA2
              8645071AFEF69C8B023A4B9808ECD30FAD3F1866F981308D888B6E4D005D6ACA
              18AE1C3B19F808235DB24579D7EB7463F21E32F046C6D81A4A2B18E03240F657
              E8C07BB2903D9327BE0C0EFB2BDA9E07C01263B01A003630809FD0FC554A319C
              F0345E7794F413832EB597E9B22FD5BB0CB3F22B0A8A27220EC24E60F80D07D8
              790DBB8873A481A65D7A376DFF54B3565A45A9DCB447EA8D6AE9FBF5B1E2DD37
              DA43BFE5892F37C64ADFA7ED8D863D62356BC52BA8CCA54DBBF83E9A1F40692F
              D908EC03844D1D00B741B47FF4C4A0F2FA92CF8EEA273473D493268059A018A6
              F5714A74F0636F9BB52BDC55C6B603C217FBB74D2C6C0BC87D1AB591F36FB24B
              813F89A8DBA57F263B961161EC47F349821868CD9B0F802544781922F563FB0E
              CC1B78CD18B29A91324BA1316E456B0268432A57283F4CABB7528AC2F4025030
              8D2F1CDF6732C06AA53735AAC5CF6DD8B0EA1588E86FFDFAC11D440856BD5A3C
              68D2663A2B61800699BB8552F813838B88DC5B4B4647E7856F4C342CD00440F5
              70FEF235C750C360887812AD86393D0C8CFDC574F01CCA83E9D6D1D19D611A24
              AA9B2E399AE4CF49941021731202F27B1210E22F33B0756047DEB4CE0FD186C8
              A84E3D0150E0DBF3B2D92743AC91F6A03FA5512BFD4B88B628555DB787B7D4ED
              117E4F022183C701B03B21A41F03B885EA3EF54F0A524D00D400C6A9FD152805
              3F210CF3A322A544077D27601BEB469E6CD8A5C50D7E99E0E0B9946F8252D0D3
              E49382A5C5F261412B56A9CF8BEC5412C0D2C1D5C751F0D34100F6F30296705E
              060F4CF4B1C379A3A7EBF9AAB0BC8408688E8DDC4198F48F63665F726933A540
              A7BE097C960F9F1EA8D288284B1D011885CA605FA6EFF120F127A6E1D7C1D8A8
              15CFD864959E0B52779C74DD5A1D7E8388E01C4AF49411AE0AD2763E7CBA3154
              D914A4CE28E84A1501E4CCF2DD80AC1614F033814FCFD3F99DF0A0D426420F91
              E517268900F0CAC01C62EC829C69FD21307D1150941A02A053FE57E90EF4BB82
              C05C07BE3C94E949C8359C08782F4679523B4B428023A9ADB04B2EF95A7FE75C
              D1DDE3D5B2541000AF500246FD30D4748DCF1BAB3EE213DA92A766AD54E6D812
              B906729ABE6BDFD776FEDD887588643722272ED104B064C992EC74F02B079E41
              76119DB69EA15C51CA1510B95E387DB3507987A8F92D787ED965C91E8F30B104
              C03F3C3170F43B0278B4845FE247A6A63DF458CA633330F7A76F162ECC003B4F
              B552A71F1EE383BFA8D61396FC4412007FAECB3F3CA11254BA267D99073E5DA3
              FE77957AB4ECCE086CB44BB7F33AA0CB825F75CE25614F16EECB15AC3F972049
              A9083FC21347007C0869FE5CD70F18EECBB02BE99A540FF3ED1E30A539E9B2E0
              2CD66A9DAD520922FC9C9E222D56A9230CD98922806543EB0EE243482B04D299
              E863030DBB748D421D8189CE9B562330658A1535D7AFFC59C32EF2FE03CA1EE3
              21E08FF3C395B72A762550F1892180D1D1D13E87392F2A44AF4E0D2CBBC92ABD
              AE504760A28D21EB313A75CE1109DC1698D20014D18DD8A391B18B55A9620EFB
              B7A583F671AAE4072D373104F0F8D6815DAAC06B65F0340AFE65AAE4072D979E
              8C3C010C26BFB64324706ED248A05E2B6DECDF36AEAC9B37FFF439BFCF1474BD
              75D3E7775F2208801A34B563BF10742FF7E8C2F1FE9BD78D3CD83D577CF61256
              FCCDC763DB2D26F01247021B368C6E6BF04B0200255DAFF97DA69C595DD88E63
              1C97634F00866951FB5502FD53BC016D1E1D0DE051A212FBF7126A14ACDFD3C6
              6328ED351188892301EE24D5E1E134FF3625E91342EBE5B8F7188C350150F0EF
              905EAB53023750C3D9E32839B539BEFF937DDC118EEAE64182496009F9ADE43B
              8DBCC720C98EED145B02A0E0FF25A12E7F682787E529F82F25D9899908AB6710
              C0D558F90926816F4E381393F73D6457EC24B9CA16EA419E48D658128061568A
              E4F49F51923BB59CC58DB152621E8D71700CD37A96E6FC349866EEA6A492C0A6
              B1554F6459DF11EE50709F8B93AB11D357896347004BCD356700B0B2FBEA7197
              D3C189B734D6AF086D882A77567ACB6598157E03CCD768374925811B6BE6B3FD
              DB16C87F42C0D805F9E1CAC7BCD550F8B9634500F4E865BF3EC8DE2F1DB60C1E
              77537555A2BEF56714CA2F10511E2A8255524960C3864B679E1088C0B35759E6
              B06F531BF545B87B090B6843AC08A06F02F9187E52A1E16F96F1F1E9A40A0D59
              98615A2F02E2C132CC482A09706CE85E0F9DBDF3257989DA28BFE49227B08724
              D1DDB12100C3AC6C16757676793EE63E7FB36CF6F638AF1BA6C53FCA21F53D85
              2912A824EADEC84C1DAB2001AA83D88C361C0B02C89BE5B3E974F67D33952663
              BE63FEAE83E23EE6FE6C1C0CD3DA4ADB54744E79AA6E8F18243B91930212382D
              1F93EF0EC4820018E0BD325B5EB635EFD86FACBE821F29658A0D5516053F1F20
              E300E946203C430192A83E117361F4CCE467CDE6DAE36F1B03B865490CBE4014
              7902986ED8FE6A618E526C02CEB871FDE05373EC8AED26C2E835327E7F4AB2A7
              171AD5E291B2854651DE3FAD1FDC91C18C94FB2633FE0D6C1D78636659C55C86
              CC4813803164FD033929AD6123B00F34AF2DC6E6FA8C7CEF3951F0F31BA3033D
              337ACFB0958EFC877A2F16DF121BABC32F4D7DB1489A0F196AC34D69D214088A
              2C01F0F1FC8081B4D17618B07575BBF4CF0A300C4D64CEB4B69172E9CFB41170
              9C82FF40929DBA69FA8990BC6EC30C2E5AF2D95115042DA56E224B00FB1DF5F6
              E7A578484218C2A34DBB34428B89998C82F50602BC4981433BE8869FFA119415
              182E4B2491DF374996B4178806E62D88ECA3C1481240AE50598288D28E40CD6A
              F144AAD0C44C74DABF1D10E64B7788418B1ABF7CB9D20D552F9070E02F10F19E
              941294B17DA9CEA40E5222C1A8491191240044F6AD49EB24FC5145D2815282A0
              8888A086B4934CD98792F4A9512BF649171A6381D4763CBD43D1C3D51B7AEC0F
              6577E408C030CBD2BAFA4E4CB0A41DF9F9A847FD2A5A0A35F64411A52C8C648E
              2C446D3B7237A02345001798557AE48467C8A83C7A0E7BDDA66B4B8FCA901505
              1974E46F911D4A8ED03AF809D90E131F5948DE188378DA541BEFA02C84CD9122
              807E68C90AD81D4DBB787908782A5149C1EF9060657545F2D91CE9915CC1FA4A
              7EB0FCD1A5C5B2F4270DE44F6CA67AADB4919E4849196D58461B97099CB246E5
              D5C8FCA0F56E2A23E5DAF6D185E3917DEC423E7A9A78605281304ECF4F44844F
              B30C7EB76F02C7B91D53A9F22B7AFCF8D76453AAA646AD78B42487F7996EEB92
              C48989890C01B00CDC25E6CA546906B86CF3E86822C6F1E30137E55594FED9DB
              888DBEC36D9B4E77F0EF3144C94255B6C8FAF80893D4D665F8190902C89BD672
              19CE908C279BF6489DE6B19F7870C5C4890FF2EF31707B29259A0CF8C7471880
              94CF90496CF342CD24120440A08E0979315DB8611713F1C1060A248264DAA978
              CD7693416EA8FCE17899EECE5ABAB77496BB9CDD735105FB6AF3DDA57ADF1B3A
              011866E5CBDECDDEBB040336B4F7D6F86D31D40D731E2818C8F007DC17BA9198
              88CFA8B5839701765EFBBADF654352DBF7AB9F970B9D0000D815DC10B184ADA6
              5DB2C564845FDA4848F0B7234937125771BFF285CA85EDDBE3BCBCD12EDD4EF6
              F3D7AF692632C968FB22FA014225006A1872BA47B6761C290643F8A5090B3A2B
              0CDF0E5516306437711F970EAE4EC465DA3866A4B439C2444E0CF8ACB8500980
              6C16EF1EC9E0EEC6FA2BA5BD384436053E5123E0AFF406AE370C857D99BEC7C9
              5FA903BC84E1071F4A8E187B9304DDAE634082AEBD44844600F9C1CA397B59E3
              63033D9F7D8F8F62912A42372F79BF85D49000817F36910033CCEADB6839B653
              D32E4AB9AC91150B7E800C8D005886FDC88FC1B3CAD466ADC776954880BF82CB
              47F689AD0FDE0D6FFD8A8820D6F76E18632BBCFBBD670949B1B0A750976BA110
              C0B2114BCA279A28684C977EC6221BF9C3473F7A3516C6CA33B2402410DB21DA
              9AB592948FD4C88A09AFD5120A01382D9030320F7EC5ABB371C84F247000D929
              E10E334989CF743491005D52C7C7E03D2DC52BF75CF7BED62B26BC4B74572214
              0220D34EA6243435EC91CF0A0988706122013EB4371FE23BC256CA378D93C092
              A1752A4639926F6C9B446A8B32FA3A08C7449B49AE1703270063C892D1612711
              DD7DBBD51291C081748B90BAD300001000494441547DF972B73C49DC37C09C6D
              B9CFAE95FE014FE55831B84A5487A4D8F06446E004000CD679B2708ECC141CCB
              E6D89CB84D747DC9BFF0F39232C7187B91643B942235E1BCCCD3175EF665A943
              74AB76909E467D41588784D8F06A43A0049033ABFCD4D6AB8DB3F3FF66F68624
              AF13D91D0C53812ADF4D9C1CFD374B3AB03D2DC4CCBE74F6710991F523F295BA
              9398ED9FF7C29225A3F3DCE58E4CAECDA296CC1523A232BB950F9400105A7774
              33C6CDBEF9F377BDD74DBE24E569D44A8700A08ACE4EC7E7CCF2E330EB57AD0E
              BF41671F37346AC59367880190E501181F867C566E75AB03470FEC50275DBEE4
              71CC7C48542A4A88112F36044A0064D8D99484A6AFAC4ED627BDDC8241379A0E
              A3BCCF51923A21E0718659D98B04662B69544B8D865DDAAF61179139CEB9B43F
              904B072346EF47F0DE81848BE85814C2314236B89E022380A5979717B9B6AA43
              467458EA46A269878282EF70005430C63C2312B09E0097BFE6D88A3BC8966C6B
              D7CE43180359C3B875D44E24E0DAB68E4202DAC11CFC88A82A19B1E2D686C008
              A0AF0F6E746B54A77CF5B1D2FFECB42F2DDBE94CE00840784681BFC752A03DE9
              45EECDD75DF962B3563CB17FDB8279F410FF692F653DE625DB2A5FF4582694EC
              CDB111E1CBDCF65851ED4460040080EF07A11FBB53A878820A37AAC523114045
              C01D4324E0B957DE860D97EE6ADAC5A376B65AC712CC7CF4629AC99ED8DFE7CD
              753119E65DB4AD8AC68A7BEC0321807C7E0DEFE7EEDEAAB97266324BE7DA9CD6
              6D750A38F25DCA48B524A77DE2BDF27EDFBEC1EDF2D7D7AF7CAA614F7E5C44C9
              3B1A0C9CD09E4AB8C560329F84B62A2566268DE9FE17080138FB6785BBED4E7F
              B4B1BB3721EF5DB2E45BD9204DA060E323D5FA0AD61E761E95332DDFE4427699
              2DCC1CD34387AFDD46C1FADFBE0A065848465B9511336E5C0E8400E874F57C37
              C674CA8380F774DA17A5ED03473F31717151FC66A7179F28D878A0793E6DEFA5
              03018EA460F37D99717375F8F7641BD2FD0AFE29B35EEADCEF47F840FEF23547
              B92F104E4E725CA8CD22C0F941581E0801883B8252DEBB16B7A3B304BA76FE35
              DFDB9AC02D172D5F7B125F0E2A51A0F16B6F4F37F05CD9867004F92574C391EE
              57F06F3D487DCD99F565559CF5B882C47DA6E8B759EE8B7202C80DAD151EB0A3
              6E0F6FE1C646355D38B48E9F8AFFC98C7D996CE6E1DCE0DA5366D6839813091C
              C780A9785C76385D0E083D7A24DBF86BCE8FC9C4E122D3123AAB9469CB5CB264
              B45919B133976DEDDB941340C6C90ABD2A19C473E67640FC2C6799B3D7293866
              320FE60B6B4EF323CF6F99A65DE2E32CF4ECD4E3553E9D8E1E962F94AFF35AAE
              3D3F9100EF07F242FB3691656AB8B788940FA2AC68DB158D1D373E128E6EB2F9
              CFC390FD37FFA50132C0BE24525E75D9DCD0BA8E67380CB30F2C35D748F9D8A9
              5B3F28D04EA0BC528FB6C8D8F5F55AE932922B34916D870263DB8584B415CE15
              AC48B70D91B6CBDD148D1D2EA357524E00BD0CE8B59F1ADEC65E79C2DC8FCCF9
              4937FD7D90BDFFA2A1D56FEE9647F63E0AB445A2479F199B5052F0CFC86BD44A
              D2DEF74704A1B3CB199B54CDA3DE76B9DF4A09206756F9D188EB49645A669679
              9FF89EBE6558DF6F960D96DFD233A3C40CBC871E8913BA77223BF8C99EA9A935
              8FBFD730B52CF89F33AD44770F571D434A0900586BA560FD467A682C07F036B7
              FE3919FC8F8B0BE5FFE436BF8C7C7426701230F0D57906251FF9DBFD69AC1F7C
              9E8EDE123E0803F49411BE03D1FE89B561F118EA8A8E5202C00CFC5D57ED3D77
              3A523E1BD6538D8F0CD377FE3D956C21FE7BCE5CBBFB6981A7C23E33376A453E
              D4D4C35E8AAB0CFE193BEAD5E26A5AE60392D04C6C5A5A2C4B3BA310B364AED2
              DEDB70BB14F1186A97B6F7B25202A0A30F1FE0726FAD2EB70CB4E6D75C660D3C
              5B8639FFEA472942E6D78193805D3C05803D042E7E4104FF8C1903AD79FCF1E9
              CCAAEF79DF04FC93EFC28A0B0AB761064231D4CB3DB504D04B7B8FFDEBD70F46
              76400804F07DD4C15048A0742A037810BAFC820C7E6E06AF5FBAD32DE1141E23
              FB8111EE23F735AA29D2041055D0647CE812890420E05FD32E9E466702BF9B4B
              6DD0C13F6343B35AFAF8CCB2C8DC2894DF21523EAD65951180315C11FC843206
              3AFC949706C0C0117EB989F485D29DB561974E07060F90FEDD5358C1BFDB00C6
              C6762FFB5D40BCD56F51F5E5DCB7E5B96C118FA5B9A44E6D534600C09CBF9952
              E1F79FFD0FBF25959743DC5754476BD7FCB78ACAF05B9E6E0C9E41B7CFEFE7E5
              430F7E32A2512B1568263AF1F7214465282A2FD8968563A9B35BEA08C001A153
              3B04F6CDCE6687B7E7C2E56BDE2E43FBCDD75D2EE50EB85F5B1AD5E29B19B0AB
              EB127AF8F9B5A1BD1C03147ECD37BF7C7568A4DAEECBEC65E1B62C184BB3ED69
              5F57470088F3DB15795DAEDB25099F0FF3AAB577FE6CB64FB8F71903F8586F4D
              EA7334EDD2A87A2D2E356C7D4D782C3D26A16E5C5AEB299B705B168CA56EC6AA
              23806E5A63BD8F0937D4A65DFC6EAC2150607CB339BA5D82D84F4890119A8830
              146B020818753AFABF1AB0CAD8A8638CD9B1313621866A02F050913246A24180
              547CD6CC03ACBBB3366B25E1EF46C6ED9362BB9D0F6941138017E0FBB3825D9B
              011A76F1DB5E54EABCDE10E8EBDFE76FBD9548776E25042061349C489E263306
              827D1BD2DDD85C79CF4068083206F001577A82CFD4B54DF73247424CCDA94209
              0164B2F8A7736A73B9912AF1DF5C660D3ADB621185748D2BA1DBAB8805D12F4B
              247BB5A095912400D1362D1A539D30554200CC81233A2974B39DAE93F7E8A9E6
              A64C2CF2388E150B3BC334F2A0F1A6987A26DC494B4CFFDCA545DBB4684CCD6D
              15801A02C0CC819D14BAD94E478197DCE48B5B9EE6FA953F8B9BCD41DBDB1C95
              F2383068B37BEA136DD34C30A63A19A884009039077552E8663B2286DA4BCE8D
              8D3A8F46C00B02DDDAB41B39A231D549871A0240143A030074340174AA31BD3D
              9E0808B669148DA90EA8292100266A6C0B127909D0A10EF4E6342020D8A68563
              AA03C64A08001C26760900D1BB0458BC78B40FF42F1004E88EF91B81280A5009
              8AB669C198EAE4AA1A02103C03C864B291BB0438F6ACFD84488D2A602B253DB9
              4340E80CF0C2CBAE3DD89D9AE072756AD3AE2D108CA94E7AD41040276D31DE9E
              DDC684B0A2A3DAEB31763F50D311603F1185EC4D6F6445CAA7A9AC50A3EE0814
              632F77DCE76287E3B422C7E070D836D123B8E819840BE4129365A188274FFEF2
              75A1330811DD9DCA0AB769C198EA64971A0200B19B782CCB224700A2CFA7E9A8
              26ED8B389D2A536F9F4260F3E6D189A9A5E8FC4B68D34A484D09013004A13300
              C632912380E834256D491C1198AB4D7BF14334A63AE952420074B413632BE668
              02E854637A7B3C11106CD3C231D501352504004CEC12806CD5044020E8295108
              88B569F1989A134C2504207ABA82886260CDE96AF81B73A3A342E32486EF817A
              0BF243EBCE52AF25780DA26D5A34A63A79AC84003219FC4327856EB6336067B8
              C917421E474427BEBCDF4522E5D3509631A798443F67B769AF3E8AC654277D4A
              08009C9DBFEEA4D0CD7604FC1337F982CE439578BB904EC4CF09954F4761C1EF
              49C06688E00F45DBB4604C7582440901D4ED2BB67452E872BB504710973ABC67
              CB64BEEABDD01E25A47C0C730F897A650F0410E1B63D36446745A84D4B88A939
              91504200736A4AC0C6E6BA913B12E046645D304C4BE86332DCB13E96FD069FEB
              E40E014D00EE7092962B572857A5094B982006B051D4A50DF6D0D3A23254978F
              927C4D001E6B831AA9D09B6A88687A54999AEC08B07F6A9C8D88A39A003C5704
              13FE34582EA71F07CE863D5F582BFCB934864C0FBA3A1BD81EEBCA080005BB03
              5F6496CFED617B28BB9B7649FCEB350B177C3F14E3E7509A33CBA3736C0E7C13
              C38CF0F71232E0AC0EDC70170A45DBB2682C7533511901380EFC6337C5BDF665
              58E693BDF2C4753F02FB2F51B03D5F285F8780571943D67D61DA7371C13E5C86
              FE7A75E52F65C8912DA3BD2DFB912D1A4BDD742A230040264400545EF88E7037
              C7C5F6A1F011DC28946B62368895E6C1CF103F3B2985C19946C1FAEDE472087F
              2D9CF87761B58C6D1396A14A0032B1B62C1A4B5DFC52460074AA2CDA21635E17
              BB43DD358E28FC8930401C0CCB893C1DF97707FF8C1108A71B6639ACEF31089F
              0120643E03D1FD09B56509B1D411196504D051630276DC5A1D167A123003416E
              A82C7CDD3B23CBED7CCEE0DF5D184FCB99D6EF76AF06B4D062ECADA2AAEAB591
              9B4565A4B17CA409E0924B561F10D54AA16BE7CF8BDA860C3FB67CF9D83EA272
              DC96EF1EFC535210E0543A1378706A2D98FF9B6BA5FFE7E0C45BFC6AA347B3CF
              F92DABBA5C7B1B56ADCB8F7CA504C0803DE1C7A89932BBF6EB8BEC8B21757BE4
              1F66EC14998F6777FE5EA4BCDBB26E82FF8FB2F014C3B41EFAE3BAFAA59BAAAB
              EE6359F0F512988399B7A9B7D09F06D1362C1A43BDAC564A00884CEC3B6F0E8B
              2C014C037BF7F45C6476707EC85A2522A057596FC1BF5BDAC946C17A78F75A00
              0BCD4AF101E638A77A55757375381012F56AD7647EC1362C1C43934674FE534A
              00FD071CB0A6B36A177B1023FDFEFCA30BC7CF71E145CF2C8CC135C6F2B1437B
              66F491213FD70D3FB772104EA2338147DC669791AF39B6E221A7E59CEC565606
              D8796EF386924FB00D0BC7500FA79512C086D14B851FCD2C191D15BA83DAC37F
              A1DD9B4727079F9473FD99DD29474E9B4742C1FF473927E60A96E8DB9D7F94E6
              62E9A6F52B1E61B06B918BACB0D12E89BDA2ED4689CF3C4BDADAAE4F11202386
              BAE9564A00DD14BBDD37B07541688FCBDCD8D8BFCF84E753D64E728D216B47A7
              7D5EB74B0AFE49B588B088CE041E9D5C09E8AF695FF1582F126098796F40E6F8
              5213F5B6CB9D524E008CB11BB822FF89ADF45F567DC90D6B56BD02C0E474A261
              308F02ED5551AB65067F9B2D27906D8FB5AD2B5FEC4502CDEAF05DCA8D1052C0
              84DAAE78ECF4365E390100F67DB9B7195D731CD2756F047636ECD29912CD5840
              812674B4ADD74A973100E99714E4E3F18659799CE6814D9D4860C299383E3023
              FC2B126BBBE2B1D3D372E504D0B487848F1A46A1FC8E9E9E849C8102EE7B124D
              E0475BA12F1135EDE2E164CFB394244FEC38C3B4841EEF7A3568360910D60F6E
              1A5B15A80D5E6D6E6FB35ECBCEE497113B33B23ACD9513C094626C4DCD7DFE23
              DEE2B36460C528E03E2A59D9011468D4D6FD4B6DD8C52380C133FE25742C792C
              D9F664C7BD0A76B49300617D9A021572450AB759C19871E94D2004C098F3F72E
              EDE994CDF563A14E0282D8CE763A47CAD6639816BB78F9D8317EE5366AC52389
              45548C92730CD9F6945FBBFC94E324F0E8C2F17E3F65432823D46625C48C2B97
              03218066AD24D61F805C91714A4562944ECDEB573C43C126D6F9690E0B5BD99D
              4F1A66B93CC72E579BE888791465141AAA9DCACF351D4D241068279CE947AF73
              D912996D32DAAA8C987103482004E0C6909E79844FA97A6A90928182CD201290
              F2B2D09E066131675AAFE457AC59B0E776776B0DBBC847245611AC47E54D4B05
              B9B8732C8AB9DADA6A14CD6BB72930024060EBDA15FB583ED94799508A1009EC
              AB423102ECCF76665F35CCF24FFCC82712E09712D24FDB89F08E34862C159719
              7EDC8C429993458C90102BAED50746005B16BE2EF4EF947F0100001000494441
              544C947B942B58C2E3F17139412484CC49A0EC87EFA1536F46C9F3E50691C0B1
              6496FC1B780C8EA03314054F1DC8DA184D448443A2E6CA8815B73604460032AE
              DD10E14B6E1D0B3B5FDD1EDE424C7EB5623B2E2212202228FF62C9D0BA37B9D5
              4524701C004A7F8C4667288719665945FF0388CD8F81E8992EC88815B7780546
              00DC200414BE19982FAC398DCB8A43AADBA551602C800F55E05903CCD966D013
              03BA01757BAEB4F6885EF834EC11DE914641A71E3C94EC78BE97FE24EE5F5A2C
              1FD6EE979F651931E2456FA00450B747845F7B659895F10AAE178C84F2366AA5
              F34980F8987724C4D584F821DC95799A8290CE0C2C9EBEB3AC60BD3797DB7B28
              723A13380100853B6AC1DEBF4388885ED87B73B2B7F4EDC23B453D9411235E6C
              089400A60D7B697AEE7726D6BDD2AF5681721468FC63A72A02CD8D557FED20DC
              890B07DE6823054E0C9309801109B811E3310FE2C1A4EF458FA5E29D1DE17441
              074463C3B3FAC0090031F35F3D5B39AB0035AC1FCFDA14F9552201FE7AEB2F22
              6FA85C030FCA15CA81376AB92EB8934637401BEE7276CE2523363A4B9F7B4FE0
              0450AF0ECB18BB7DF1DCEE447B2B91C0DBE988FBB5685B29D73A443C9008FB65
              B952A3270D0172D0F6F3B32829363CA90E9C0026AD43FCC6E45CE08F1A55ECCE
              02B8BB0DBBF4690638CA97539416527D09BDDC1465AC641CFD41424CF8C12814
              02685447F88D313FF6B69789E5590077A0698F5CDD97C1D3F8728AD2018669BD
              92447F51C2D15F524C788637140298B212856F8A51838AE55900F7FF8675230F
              36EC22D2B243292DD3FE5467C2039E44092C29477F354F625CC1141A0130C8FC
              A92B0BBB678AED59C08C5B4402595AFE01A5B44C7CC093D792E22C31F85ED7FE
              5E7D93140B5ED54EE60F8D009AF6D056041C9FB442E0CF302B2ADE7717B0C87B
              5122818FE0448BBFACE3BD703C4B0C18A6255CF761BB6E48F89E228F011E0B61
              F9121A01708777C104DD15E74B22891D9E37CB678B488842D9FAB52BFF404480
              00988A4F5C91AF0310E35FCEAC9E00E2CFFD414E0CF807325402D864AF943298
              26DD55BFD73F04D12AD9B0472EA2E020228040BFCC13240AD3FE05A952BA2E84
              96D0B88D3306C98A8119795EE7A11200379639CEB97C2E9AE866CC2DA232A254
              9E82E4D489ED8C8FEB97A88E34E41727B72841EDD916C3AC7CB153212FDB65B5
              7D2F3A67E70D9D009A632BEE986D949F756A55E70F797823CE8F8EA0CB6CFA6A
              E9390A9883FBB72D9847BA63F50E04D9BBD744BE5035EDB539861B98E8107793
              3ECB6AFB93C27CFE854E009376B7E0CD9373C1BFADCC49D423A61938366CB874
              1705CF7B28A103CEE533DBE334E7B6C7C9DE4EB64AEBDA2CA9CD77B2D3EDF648
              1040637DF17E0026A393481F5D0A6C74EB7C1CF3DD64AFB88E0713DD2BC830C6
              62E12BB7378E58CFB6D930CB57F0AECDB3B77B5F67AF4CB579EF256597880401
              70A718F49DC0E7A289CE31F3C670858F7A232A2AE2E591356BA58B7970F1C400
              2E0440E9837C80E08FDB26282212C59716CBFB0160D78FDC80CB9FACB6EE525D
              D76C912180A63DB41500A53C150087452E1040F1AF691737D159C1F13CE07862
              2DA447A3CC620CA4DCADF6613EE376F82817C9227D1328E9F2127F3BD5D6A3E1
              66640880C3410D58DA27B68C21EB3E2E33ADA9B97EE4670DBB546AD68A2736EC
              22CE4EE398E103970A77C7EE80AF43FA22D5B63AD8E96AB3615AFC524B8A3F32
              DBB82BE37B6492E2540F1D5E77AFF55A60CEFC0CCECC17CACBE6DCA737C20073
              E8BE0B48B9EC823D7F1314FCBC7BF39E5B63BA76E170E554323D4F497C625011
              17225742E408801A8FF0E8C1331031C41B2F1C5A97A62EB633AE779DD3118D5F
              16A8087EFEB4222E5FEEE98A11DFB97874B42FEBB0DF818B9F9B2C8D5AB1E826
              5F9079224700DC79999FD8CA3247FA38F8DCC6B82685C1BF83C89BF757882B34
              7BD9BD68EBC0AEBD36FADD90C1E3FC1655592E9204C03FB1050CA4BDEA6B98D6
              4E9520C64536E1A0E6C8CF603B05FFFCB8E0E0C64EC24AE2B713F05F1BEB4624
              CA73E381BB3C9124006E3A9D2EBD9FCF25A5FE5CC192F384419241418BA106AD
              24F8E9F1E31B5457AEBF4910B4DF7EF411565FA372FC2B4A34139FE8C6DF9F89
              4B512321B204C0DDCD60E61D7C2E2321C2E939B35295212B6E32A8412B097EC2
              E1757AFCC89F26D062322663B06C90279750723DF5C8B8A4C7FE5077479A0036
              56877F8E80F7C84208819946C1FABC2C797190A330F8C7E9B43FD6AFF4CEAE3F
              63F9DAF74106EBB3B7FB5D678C3D42187DDB6FF920CA459A003800757BE4DD7C
              2E2D215C9D2B943F254D5E8405290CFE57A9612F88B0EB9E4DBB6868F59B219B
              D9ECB9609702CD5AE9E42EBB23B12B13092B7A18C1207B608F2C9E7623E286DC
              70E52F3C158A596685C1FF0A05FF013183A3ABB9BCEB7886F5FDA66B268F3B77
              B65AB1E88E1E0B02E05D2711E10A8F75D0353B3AECA7C672EBCCAE9962BA3367
              5A0D325DFA737EAA839729F81792ECC44C931F5515E83ADE0188DAD7D7AF8CC5
              E3E758100007B95E2DAEA6F9B394E44D59B8EF53533DBDE4C98C8024BA316720
              C0ED924D7989EAE020C9324315B7647474DE0073B64936E275224953B24C65E2
              6243001C0102F6083E9799261CF6BBFCD0BAB364CA8C82ACBA5D3C4F1A0930F6
              22617F7014FC9265C327575D73E0C0D6811DB2E4CDC8219C627563345604C041
              CE60467A4364CCF9456EB0FCB75C7E92921C12C0E71BB552EC3EC8DAAD1E2F5E
              3E76CC3EDBFBA50FB536E14C1CDF4D6F14F7C58E003656875F7218BC4F369898
              C16FE6CCCAB06CB961CB13210106F05CC31E392C6C1F64EACF5D6E9DDECAEE94
              D22B6F0FBB1816368DAD8ADD6BE8B123000EFA4DB5E24FA8714A7B5ECB65F284
              C02A39B31CB937B6B86D22C91709203C43F712F8A0A422AA2355366F96FF12FB
              407A8F5006EC9E466D642C52CEBA34269604C07DA3C6C95FF57D8C2FCB4C0838
              9CC46EC35E4880C8F5E946B578A44C5CC396C5899D01FE1F0576BCD6B44B72FB
              AA2830B293C8D8120077886EB82CE273D9891E779D6E24F005225724C0D81F9A
              76F128D99886292F37646DE1C4AEC2066A83FBAB901B94CC58130007892A00F9
              5C41EA271260491B4FA007093C4537FC12357E02AF436420FD40C1DB9BC2B6C7
              C50792624F001C259515C1C713C8179235B25007127892708C45EF355EE7BDD2
              D2CBCB8B78F0F7CAE777FFF8EFFFA5CF6FD928954B04017040A9F1AA3A13003E
              B250D2C618DC8304101E27FC22396005AF5BAF29675AD7F6F5E116AFE5DCE6C7
              575BFBDF7AEBAD2DB7F9A39C2F3104C041A646AC8C0480C199FC88C2FB8D735D
              4948D324D0A41B7ED2BB0D8781CFE2D1D13EAAA3EDD4082E0345BF893E7678BD
              BEF23545E203179B2802E0E8292501AEC0614FD011868F12CBD7629F8804F8FB
              EFB1F7236756F28BA686F0DA479533992C9CB0C92A3DA74A7E18721347001C44
              D524404798BC615ABB92F62D428E5D1C13D5C513084C2929F31EA81B2BC5C7E3
              884F379B134900DC61D524403AFAB632675BCEB46EA1653D8580003DDB3729F8
              19A9567AF3F2F885E3FDBC072AE949DC945802E035150009009D0D9CCF1B61DE
              2C9FCD75EAA41E0163F9970F35CCCA04022A1FE28DB7A1D1D1D109F55E85A321
              D104C021E515C8E7AA1303BC971AE533AAF5A45DBE51B0EE82ECBCE70098F28F
              8FCCD57692867FE2098057D87445CA7F01840BDF23B1C30DD36294A40D69BE87
              F814AF10A63625E25908A2DBEDCEE9369378C4534100BC16A9428F4306D7F3E5
              00D262DE582969221004DB302BD71B44AA24A6402988E957D456943D4908C201
              2F3A5243001C947AAD781903760E5F0E286922F0093405FD464A8C4EF53FE353
              848F6258A2E04FDCE030DD8048150170209A766933933CC82897DB23CD10C1F3
              F9C29AD37AE44DEDEECFACBAE640C3B4FE8312053EC8F920A74B3427A07566C3
              1EB1BA654FE2BED41100AF443EC828313DD2B2DC310649608FE91086D9077803
              CF15AC2B7BE44DCDEEFC60F9A31C93ED53A3F4BC2568C727FAD8C0267BA5F471
              0282F6C38FBE5412C00C50440247A0E4D1866764F79A93DE2FF1464FE921A350
              96F605A45E7AA3B29F77A936CCF266F29FB10C7E371CBBF04E6A03B8C92ABD1E
              8EFEF0B5A69A0038FCF56A71750897045CF54C3A19107FC6038152A2C9206FAE
              3B316F56EE263F1938EC0900943EB41BB8FC21B077D229FF6297D9139B2DF504
              C06BB6690F6DE5470294F819322ED7473A79371914CA2F50A0ACF8E0F2B158DF
              91CE17CACBE872670BF9C228EA1F61C0DEE503179945F8578DB06E977EEA4568
              52F36A0268AB59FE19B20C66A2713A8E783099B6E688ECCEED3C788C21EB0D0A
              A42F5D72C9EAC87E956739919561AE5D41F66EA5C4FB43308678235DEE281990
              83F0F136217C91883EB2F87973464E6E4D00B370DC581DFE3935123A4384683D
              C367309F02E9CA5DFBF6ED0E2E0AB21D46A1F2F58BCCF2B9B3DC50BE9A37CB7F
              6998163DAAABBC4EF3C9601F27B202C8AC21E5910A32C6D8CB7C008F46B5F839
              B24D4F6D0868026803A37DB1512BBE9FED74A23E30E63C40F6C90CE06D334138
              6B3E9E33CBFC9AFB865CA1BC9A52296756F2C650F923F941EBDD179BD53378E2
              CBC660F923B4DD30CC4A91CE34AE314CEB6B39D3BA93E6AF509A0CF0F6399B1A
              60931ED5B17DDB718BDA329D827CA2592B1D9494013C64E39B912D3049F29AD7
              AF7866F26C00606D4CFDDA0F01F935F7C588B892D25A3AB5D9080CBFC7327057
              0B5AF7F3C4972183DFA3ED750056468455E4EF2508F05E9AC774D04BF65B5E77
              CDDAC8ADE483D094E4C29A005CD42E35A49594281E3095CF8A5D4014A52C3B76
              41F6A8865D3A334A4645D5164D001E6A861E1B9D39F5C890BDE2A198CE1A1002
              E8C07B1A7671FE2DF6D0D301A98CBD1A4D001EAB70EA91616921B4E0CD1E8BEA
              EC8A10A053B3410A7CAC8F15EF56A422B1623501F8ACDAC6FAE2FDBCD131C709
              FC0EBC4F9313580CAFE17550B78BEB55399774B99A00046BB839B6E20EDE08F9
              CB2408382E284E177787C0A738E67449A6DFA7708757C75C9A003A42E36DC726
              7BE56FEBF6C882A97B04F898B7D23AB71B04D0C1F74F057EF14637F9759EDE08
              6802E88D91A71CCDC96EC5238B784305C46F782AAC33CF85C0C37C386E8E677D
              6CE4C77365D0DBFC23A009C03F763D4B36AA23E7F3868B98F973CAFC12253DB9
              450061986347E994B086E3766B6A9CF3690208A0F6EAD5E15F52433E98122220
              EF2A1B80D658AAF829BF84E23835AA45E523FEC61221C9466B02900C682F7174
              9F60156FE08F2E1CEF4760EB7AE54FFE7EF6A389097662C32E22A577F24BA8E4
              FB1C1D0F35018454179B474727EA7669841A3D6FF8C8185B058089F8E024F4F8
              3180AFF30F6C4EF95EFACF9BAE2D3DDAA388DEAD08014D008A80F52AB6592BAD
              69D8237D3C289C7EE7642A5FA794880919FE2F86CE7BB96F3C35EDE20551FFC0
              66228077E18426001720059DE5A6F28A47285096519A3C3B18DF39BE0010BEC0
              803D11B42D9EF521BCC2187C954176F24908F7A15E1BF960B3BAE22ECFB27401
              E5086802500EB1B8825BAF1F1DA79B625735EDD2F13CA0661211C2393CD8E8CE
              E2CBE25A3C4A606C3B20BB0532F8E1C6D4F5FB2459919D0B9BB5E267E85A5EF7
              85F0086918D935018481BA249D44089B79B0D5ABC583F608C2E98044D8751266
              F0E78D006B0000016749444154E374CD3D080CAE22B5355ADE040C6EA3742F00
              7FBB9112837B01F13604A07D6C8C018E02630544F637CC714E6D4CCBDB635E2B
              BDA9512D2D6DAC1BB90DF42FB6086802886DD5F536BC6E5FB1A5BE6EE43B4DBB
              B8BE512B7E8102D8A4E50B69F9C394DE45F71CF858F8674E2E57473E5CB78BB4
              AF5468DA2357376AA5B17AB5F4ADE6D88A877A6B4A568E3479A309204DB5AD7D
              D508CC424013C02C40F4AA46204D08680248536D6B5F3502B310D004300B10BD
              9A6E04D2E6BD2680B4D5B8F65723D0868026803630F4A246206D086802485B8D
              6B7F35026D0868026803432FA61B81347AAF09208DB5AE7DD6084C23A009601A
              083DD308A411014D0069AC75EDB346601A014D00D340E859BA1148ABF79A00D2
              5AF3DA6F8D0021A0098040D0934620AD086802486BCD6BBF3502848026000241
              4FE94620CDDE6B024873ED6BDF538F802680D437010D409A11D00490E6DAD7BE
              A71E014D00A96F02E90620EDDEFF7F000000FFFFD41BA01C0000000649444154
              03002FF650E20BC505640000000049454E44AE426082}
          end>
      end
      item
        Name = 'Clear'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600000998494441547801ECD45B6A54591480E1B2A1A11F1D829999CE200DBE
              38025F84CE0C74667108FDD8D00F5A81048AA22EE7B2AF6B7D62614C4E9DB3D7
              B72AFF1F077F0810482B200069576F7002878300F81410482C200089976FF4DC
              022FD30BC08B821781A402029074F1C626F02220002F0A5E04920A0840D2C51B
              3BB7C0DBF402F026E15F0209050420E1D28D4CE04D4000DE24FC4B20A1800024
              5CBA91730B9C4E2F00A71ABE26904C4000922DDCB8044E0504E054C3D7049209
              0840B2851B37B7C0F9F402702EE2FF0412090840A2651B95C0B980009C8BF83F
              814402029068D946CD2D70697A01B8A4E27B049208084092451B93C0250101B8
              A4E27B049208084092451B33B7C0B5E905E09A8CEF134820200009966C4402D7
              0404E09A8CEF134820200009966CC4DC02B7A617805B3A7E4620B88000045FB0
              F108DC1210805B3A7E4620B88000045FB0F1720BDC9B5E00EE09F93981C00202
              1078B94623704F4000EE09F93981C002021078B946CB2DB0647A0158A2E41A02
              41050420E8628D45608980002C51720D81A002021074B1C6CA2DB0747A01582A
              E53A0201050420E0528D4460A980002C95721D818002021070A946CA2DB0667A
              0158A3E55A02C1040420D8428D43608D8000ACD1722D81600202106CA1C6C92D
              B0767A01582BE67A0281040420D0328D4260AD8000AC15733D81400202106899
              46C92DB0657A01D8A2E63D048208084090451A83C0160101D8A2E63D04820808
              4090451A23B7C0D6E90560AB9CF7110820200001966804025B050460AB9CF711
              0820200001966884DC027BA617803D7ADE4B60720101987C818E4F608F8000EC
              D1F35E02930B08C0E40B74FCDC027BA71780BD82DE4F606201019878798E4E60
              AF8000EC15F47E02130B08C0C4CB73F4DC0225A61780128AEE41605201019874
              718E4DA08480009450740F02930A08C0A48B73ECDC02A5A617805292EE436042
              01019870698E4CA09480002C94FCF8F8CFFB8F8F5F3F783128F91958F8F1AB76
              99002CA6FDEFFDBBC39FCF5E0C4A7E06167FFC4E2E2CF9A50094D4742F029309
              08C0640B735C02250504A0A4A67B11984C4000265B98E3E616283DBD00941675
              3F02130908C044CB725402A50504A0B4A8FB1198484000265A96A3E616A831BD
              00D450754F02930808C0248B724C02350404A086AA7B129844400026599463E6
              16A835BD00D492755F02130808C0044B724402B50404609DECCFE3E55E870383
              7206879E7F0460A1FE8FA72F3FBF3F7D7EF06250F233B0E4E357F31A01A8A9EB
              DE0406171080C117E478046A0A08404D5DF72630B880000CBE20C7CB2D507B7A
              01A82DECFE04061610808197E368046A0B08406D61F72730B080000CBC1C47CB
              2DD0627A0168A1EC1904061510804117E358045A0808400B65CF2030A880000C
              BA18C7CA2DD06A7A016825ED3904061410800197E248045A0908402B69CF2130
              A080000CB81447CA2DD0727A0168A9ED590406131080C116E238045A0A08404B
              6DCF22309880000CB610C7C92DD07A7A01682DEE7904061210808196E128045A
              0B08406B71CF23309080000CB40C47C92DD0637A01E8A1EE9904061110804116
              E118047A0808400F75CF24308880000CB208C7C82DD06BFA9001F8F4F8EDF9F8
              FAE5F58DC1633183E75EBFA4359F1B320035C1DC9B4024010188B44DB3105829
              20002BC15C4EA0B440CFFB09404F7DCF26D05940003A2FC0E309F41410809EFA
              9E4DA0B38000745E80C7E716E83DBD00F4DE80E713E82820001DF13D9A406F01
              01E8BD01CF27D05140003AE27B746E8111A6178011B6E00C043A09084027788F
              25308280008CB0056720D04940003AC17B6C6E8151A60F1980EF4F9F1F8EAF77
              5E9F193C15337818E597B6E4394206A024907B11882C200091B76B3602770404
              E00E901F13282D30D2FD0460A46D380B81C60202D018DCE3088C242000236DC3
              590834161080C6E01E975B60B4E90560B48D380F81860202D010DBA3088C2620
              00A36DC479083414108086D81E955B60C4E90560C4AD381381460202D008DA63
              088C282000236EC599083412108046D01E935B60D4E90560D4CD381781060202
              D000D923088C2A2000A36EC6B9083410108006C81E915B60E4E90560E4ED381B
              81CA02025019D8ED098C2C2000236FC7D90854161080CAC06E9F5B60F4E90560
              F40D391F818A02025011D7AD098C2E2000A36FC8F908541410808AB86E9D5B60
              86E90560862D3923814A02DD03F0E9F1DBB31783929F818F8F5F3F54FA7D0977
              DBEE01388ABE2CCBEB706050CEE0E0CF32811102B0ECA4AE223091C02C471580
              5936E59C042A0808400554B724308B8000CCB229E724504140002AA0BA656E81
              99A6178099B6E5AC040A0B08406150B72330938000CCB42D6725505840000A83
              BA5D6E81D9A61780D936E6BC040A0A0840414CB722309B8000CCB631E7255050
              40000A62BA556E8119A7178019B7E6CC040A09740FC0AFC3FF0F5E0C4A7E060E
              87BFFE2DF4FB11FE36DD03F0E3E9CB4F2F06653F037F0BC0C274750FC0C273BA
              8CC0D002B31E4E0066DD9C7313282020000510DD82C0AC020230EBE69C9B4001
              01012880E816B905669E5E0066DE9EB313D82920003B01BD9DC0CC020230F3F6
              9C9DC04E0101D809E8EDB905669F5E0066DFA0F313D82120003BF0BC95C0EC02
              0230FB069D9FC00E0101D881E7ADB905224C2F0011B66806021B050460239CB7
              118820200011B66806021B050460239CB7E5168832BD0044D9A439086C101080
              0D68DE42208A800044D9A439086C1010800D68DE925B20D2F40210699B6621B0
              5240005682B99C4024010188B44DB310582920002BC15C9E5B20DAF402106DA3
              E621B04240005660B9944034010188B651F310582120002BB05C9A5B20E2F402
              1071AB6622B05040001642B98C4044010188B8553311582820000BA15C965B20
              EAF4021075B3E622B04040001620B9844054010188BA597311582020000B905C
              925B20F2F4021079BB662370474000EE00F93181C802021079BB662370474000
              EE00F9716E81E8D30B40F40D9B8FC00D0101B881E34704A20B0840F40D9B8FC0
              0D0101B881E347B905324C2F0019B66C4602570404E00A8C6F13C820200019B6
              6C4602570404E00A8C6FE716C832BD0064D9B439095C1010800B28BE45208B80
              0064D9B439095C1010800B28BE955B20D3F4029069DB6625702620006720FE4B
              2093800064DAB659099C0908C01988FFE616C836BD0064DBB879099C0808C009
              862F09641310806C1B372F8113010138C1F0656E818CD30B40C6AD9B99C0AB80
              00BC42F88740460101C8B8753313781510805708FFE416C83ABD0064DDBCB909
              1C0504E088E02F81AC02029075F3E626701410802382BFB905324F2F0099B76F
              F6F4020290FE230020B3800064DEBED9D30B0840FA8F406E80ECD3FF060000FF
              FFEDDEBAD700000006494441540300412D608823C1E1300000000049454E44AE
              426082}
          end>
      end
      item
        Name = 'Switch'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600000D74494441547801EC9D4B6E1CD71540AB29CB1F29063CCA22E29DC459
              4498410264C4445C801740251C0548066116117927F6223C1220FF69B3FD2EBB
              0B5DECAE5F57BD57753F47E8DBF57FFDEEB9EF1E340489BCA8F8030108842580
              00C2969EC42150550880550081C0041040E0E2937A6C02923D02100A04048212
              4000410B4FDA1010020840281010084A0001042D3C69C72650678F006A126C21
              109000020858745286404D0001D424D8422020010410B0E8A41C9B40337B04D0
              A4C13E0482114000C10A4EBA10681240004D1AEC432018010410ACE0A41B9BC0
              71F608E09808C71008440001042A36A942E09800023826C2310402114000818A
              4DAAB109B4658F00DAA8700E02410820802085264D08B41140006D5438078120
              041040904293666C025DD923802E329C87400002082040914911025D04104017
              19CE432000010410A0C8A4189B405FF608A08F0ED720E09C0002705E60D28340
              1F0104D047876B10704E0001382F30E9C52630943D021822C47508382680001C
              1797D420304400010C11E23A041C1340008E8B4B6AB1098CC91E018CA1C43D10
              704A0001382D2C6941600C0104308612F740C0290104E0B4B0A4159BC0D8EC11
              C05852DC070187041080C3A2921204C61240006349711F041C1240000E8B4A4A
              55F5A7AB9BFF5F5EDD6C23B238276704700E2DEE3541409A3F75FE6732592420
              14BA030174B3E18A4102CDE6AFA78F046A12A75B0470CA84334609B4357F9D0A
              12A8493CDD2280A73C38324AA0AFF9EB942248A0CE75EC16018C25C57D6A098C
              69FE7AF248A026B1DB22801D07DE8D1238A7F9EB1491404DA2AA10C081057BC6
              084C69FE3A4524B0238100761C783746604EF3D7A97A93409DD7395B04700E2D
              EE55412047F3D78944970002A857025B130472367F9D70640920807A15B03541
              E0E162F3AF12138D2A010450623531663102FFFBC7AB2FB6179BC77FE69BFB43
              2C4B602A0B0430951CCFAD460009E4438F00F2B164A4050920813CB011401E8E
              8CB2020124301F3A0298CF901156248004AA6A0E7E0430871ECFAA208004A697
              01014C67C7938A08208169C54000D3B8F194420248E0FCA22080F399F1846202
              D12430B71408602E419E574700098C2F090218CF8A3B0D114002E38A8500C671
              E22E830490C070D110C03023EE304CC0B30472940501E4A0C818AA092081EEF2
              20806E365C71440009B4171301B473E1AC430248E0B4A808E09409671C13F022
              815C254200B948328E190248E0502A047060C15E20024860576C04B0E3C07B40
              0248805F0C1270D993729380450934E73F779F6F007309F2BC790291258000CC
              2F5F12C84120AA0410408ED5C3182E084494000270B17449221701ED12C89567
              3D0E02A849B085C09E40240920807DD1D940A049208A041040B3EAEC43A04120
              82041040A3E0EC42E0988026091CCF2DC73102C84191315C13F02C0104E07AE9
              925C2E025E25800072AD10A5E35C5EDD6C893C0C360FDB37A5CA2C352A3576DF
              B808A08F0ED720B020813E09949A060228459671213081C0D2124000138AC423
              10284960490920809295646C084C24B0940410C0C402F118044A13A82550F273
              104049BA8C0D8199044A4B0001CC2C108F43A0348192124000A5ABC7F810C840
              E0F2D5CDEF320C733204023841C20908E821F0389367D5A777AFAFBF7ADCCFFC
              86003203653808642550B0F9659E0840281010D048A070F34BCA0840281010D0
              466081E697941180502020A089C0BEF9979812025882329F0181B104166C7E99
              1202100A0404341058B8F925650420141CC7DDEDF586C8C3E0F9271FBF2CB654
              56687EC90501080502020304FEFCF9BF5FDCBF7DF7EDC06DD32EB734FFB481CE
              7F0A019CCF8C278211F0DAFC524604201408087410F0DCFC923202100A04045A
              08786F7E491901080502024704D66CFEA3A9143D440045F132B84502519A5F6A
              8300840201813D8148CD2F292300A1D013A5FE1F76CF4772692502D19A5F3023
              00A1D0118FCDFF4BF5E5E5D5CD43C72D9C7642404BF32F8D13017410AF9B7F7F
              799324F0CB7E9F8D3302519B5FCA880084C2511C357F7DF52249E0E7FA80AD0F
              02919B5F2A88008442233A9ABFBEE35992C07D7DC0D63681E8CD2FD543004261
              1F03CDBFBFAB7A2F49E0A7FA80AD4D021A9B7F0D9208604F7D64F3EFEFAE9E27
              09FC581FB0B54580E63FD40B01241667367F7AE2F1F57E92C00F8F7BBC992140
              F33F2D5578014C6CFE9AE207977FBBF9BE3E60AB9B00CD7F5A9FD00298D9FC3B
              9ADBEAC3F44DE0BBDD01EF5A09686FFEB5B885154096E63F54EDA3CBABD7657E
              58C4E133D89B4880E6EF06175200999B7F4F77FBE2F2EAE69BFD011B250468FE
              FE4284134099E6DF417EFEC9C7BFDDEDF1AE8100CD3F5C85500228DCFC2FFFF3
              F95FF8BB80E135B7C81D969A7F11201D1F124600347FC70A70789AE61F5FD410
              02A0F9C72F08EB77D2FCE755D0BD0068FEF31684E5BB69FEF3ABE75A0034FFF9
              0BC2EA13569B7F6DDE6E0540F3AFBDB496FB7C9A7F3A6B9702A0F9A72F086B4F
              D2FCF32AE64E0034FFBC0561E9699A7F7EB55C0980E69FBF20AC8CE0A1F935B0
              7623009A5FC3725A660E347F3ECE2E0440F3E75B10DA47A2F9F356C8BC0068FE
              BC0B42FB68F76FDF7D5D648ECFAA4FEF5E5F7F55646CC5839A1600CDAF786515
              9ADADDEDF56FAA6A93F7FF5CACD0FC95923F660540F32B59412B4CE3EEF6D5CB
              F4B1797E1253E0E64F0C2B9302A0F9A574B1237D1378516DAA793F933178F3CB
              0A3227009A5FCA460881BB7F5E7F94B6D37E3A33CD9FD055B6BE01D0FC8F35E3
              AD41207D13F8301D9EF77B1A566EFE345F352F33DF00687E356B46DD4492043E
              4893BA4F31FCA2F99F303221009AFF49CD3868219024F07E3ADDFFBB1B69FE84
              E8E94BBD0068FEA705E3A89B4092C0F374B5FDB738D3FC09CDE94BB50068FED3
              8271A69F4092C07BE98E87148797A2E63F4C4AC79E5A01D0FC3A1688C5592409
              3C4BF3DEA6A82A9AFF1143D79B4A01D0FC5DE5E2FC580249021734FF302D7502
              A0F9878BC61DE30844FCB7FDE3C81CEE5225009AFF5018F6FC11D098911A01D0
              FC1A970773F24E408500687EEFCB8CFCB412585D0034BFD6A5C1BC2210585500
              347F8425468E42406BAC26009A5FEB92605E9108AC22009A3FD2122357CD0416
              1740C9E617D0F76FDF7D7B7975B325F23010A6845F028B0AA074F3FB2D139959
              26A079EE8B0980E6D7BC0C985B54028B0880E68FBABCC85B3B81E202A0F9B52F
              01E61799405101D0FC919716B90B01ED514C0034BFF6D2333F0854657E2A30CD
              CFD282800D0245BE01F0FFB06D149F5942A0880004EBDDEDF546B60404A212B0
              9077310148F24840281010D04BA0A800246D2420140808E824505C0092361210
              0A0404F411584400923612100A44140256F25C4C00020409080502027A082C2A
              00491B09080502023A082C2E0049BBA404B6179BCF647CE27A938381D48BF04B
              601501084E599CB2CD1D9B87ED9B3FFEFDF5EF738FCB7810184BC0D27DAB0940
              202101A14040603D02AB0A40D24602428180C03A04561780A48D0484020181E5
              09A81080A48D048402619D80B5F9AB1180804302428180C07204540940D24602
              428180C03204D40940D246024281804079022A0520692301A14058226071AE6A
              0520309180502020508E806A0148DA4840281010284340BD00246D2420140808
              E427604200923612100A84560256E765460002180908050202F908981280A48D
              04840201813C04CC0940D24602428180C07C02260520692301A140682060790E
              660520D09180502020309D80690148DA48402810109846C0BC00246D24201408
              089C4FC08500246D24201488A50958FF3C370290422001A14040603C01570290
              B49180502020308E803B0148DA48402810101826E05200923612100A4449021E
              C6762B00290E12100A0404BA09B81680A48D04840201817602EE0520692301A1
              4040E09440080148DA48402810B9087819278C00A46048402810103810082500
              491B09080502023B02E10420699792C0C5C3F6AF323E01012B04420A408A935B
              029BAA7AF3DFDBEB3FC8D8846F029EB20B2B0029622E09D0FC4293B04820B400
              A460732540F30B45C22A81F00290C24D9500CD2FF408CB0410C0BE7AE74A80E6
              DF830BB6F1962E02685474AC0468FE0634764D13400047E51B9200CD7F048C43
              D30410404BF9BA2440F3B7C0E294690208A0A37CC712A0F93B40053AED315504
              D053D55A02347F0F242E9926800006CA2712E05FF80D40E2B2590208C06CE998
              3804E6134000F319324200025E5344005E2B4B5E10184100018C80C42D10F04A
              000178AD2C794160040104300212B7C426E0397B04E0B9BAE406810102086000
              109721E0990002F05C5D7283C0000104300088CBB10978CF1E0178AF30F941A0
              870002E881C3250878278000BC5798FC20D0430001F4C0E1526C0211B2470011
              AA4C8E10E82080003AC0701A02110820800855264708741040001D60381D9B40
              94EC1140944A9327045A08208016289C8240140208204AA5C913022D0410400B
              144EC52610297B0410A9DAE40A81230208E0080887108844000144AA36B942E0
              8800023802C2616C02D1B24700D12A4EBE10681040000D18EC42201A010410AD
              E2E40B81060104D080C16E6C0211B3470011AB4ECE10D81340007B106C201091
              00028858757286C09E0002D88360139B40D4EC1140D4CA9337041201049020F0
              8240540208206AE5C91B02890002481078C52610397B0410B9FAE41E9E000208
              BF040010990002885C7D720F4F0001845F02B10144CFFE57000000FFFF3B0692
              6600000006494441540300DC32186AD2734CAE0000000049454E44AE426082}
          end>
      end
      item
        Name = 'Cancel'
        SourceImages = <
          item
            Image.Data = {
              89504E470D0A1A0A0000000D49484452000001000000010008060000005C72A8
              6600001000494441547801EC7D0D941C5775E6BD3D33B2B0C7B66C93D80E602C
              3031923967371B126230207B93B39B600ED90D4A36C8B2BB5AB658C09AA999E9
              9664EF060F2CC692BA5BDD3362CD22ACEE2632B089D9CD0F3FC93949408E7F48
              08243927FE210124630831106CD91E0B4B9AEE97FBA6A7506BD4D555D5EFBDFA
              BD7DEACDAB7E3FF7DDFBBD7BBFA9BF7E9503FE30028C4066116002C8ECD4B3E1
              8C000013007B01239061049800323CF96C7AB61190D633014814383102194580
              0920A313CF663302120126008902274620A30830016474E2D9EC6C23E058CF04
              E020C1392390410498003238E96C3223E020C004E020C1392390410498003238
              E96C72B611E8B59E09A0170DDE67043286001340C6269CCD65047A116002E845
              83F719818C21C00490B1096773B38DC04AEB99005622C2DF19810C21C00490A1
              C96653198195083001AC4484BF330219428009204393CDA6661B817ED63301F4
              4385CB18818C20C00490E2892ED877BDAA305DFD8DBC5DD9664D56DE6FD9953A
              EDFF2EED7F96D243965D7D6C294D561EB2A6AA9F2DD815AA2BCFE5EDEA1DD664
              79A23055FECDFCC49ED7A418A2CC9BC604906017C8DBE50DF9C9CA470B5395A7
              2DBB2256260163DF121DF119049807840F90A993B4BF1910AEA7F44600B16E29
              21BC1184B85E00501D4E208859409C13027F0F73B97FB2FAC82682F8B135553E
              684D57AF27B9BC2514012680044CDCD6D98F9D6D4DEDF90005FCB77B831101BF
              8408FF5D08B8207433105783C01BA0233EDBAB933555392A4969F344FDB2D075
              E2015D1170AB6002704326C2F2BC5DBB3C3F59DE6F2DFFE73D79F4F91740E4DE
              4F011FFFA01270BE24A5D1DC622F59FDB13551A5238E0841E5A1FB22C004D017
              96F00B29E077587675D1A2A047681F41C45BC2D7C2D8886F879C7848DA2653DE
              AEDC5B28EC3ED7D8682CD837024C00BEA1D2DB70C3ECEC68C12E572D0A789928
              E077018811C8C007013689F3469E93765B76F92F36DF5A5E9B01B36369221340
              C8D352B0ABBBA4E3AF3D3A7E52004E873C7C0C87C3EB4647F1B0D525C287F376
              6D4D0C954CB44A8394670218848EA6BAC2D4DED75B76E54794E87A9DD8A1496C
              1AC55C8DD07E46E2441713A7D26860DC6C6202303823D654F593D29985E8FC0D
              0D732125DEFC222060AFC48ED237B6CC545EE9B71BB70B8600134030BC3C5BE7
              E910D6B2AB472C3AA4A57BEBEFF2ECC00DBC10B8A2D38627249E8589EAB55E8D
              B93E18024C00C1F0726DBDD9DEBD8ECEEF9F9787B000E272D7865C3134022227
              BE288980D2CD430BC958472F739900BC10F2A8CF4FECF9357248310A238F0910
              E31ECDB95A0F021F97985B76F5C37AC465570A13C090736F6DABACB7E8301F73
              B9CF0F2982BB2923206E937350B02BDB94456554001340C089CF2F9DE3978FC2
              083C1AB02B373784800098B7888C0B13956B0C0D915AB14C0001A6D6B2AB8F21
              DDA602C0F3813FB14340E4E001CBAEBC78835DBB3476CA45A0909F2199007CA0
              644D562AE458F48F46FE7ACE47076E122502678D41FB7B965DFE7A944A24656C
              26800133654D575FB114F80833039AC5B9EA05BA30F91029788F106237A5ED02
              700BA0F875ECC09B476064BD4C721F3AE2D7A9BC00802521601700EC17007F49
              F9739412B8E19572EE28F11D8301B3971B5097E92ACBAE7E8D82E2C998837002
              047EAA03E2FA66BD887DD278AB5EBA86CA6F69CD9576522AB7EA338D66ADF447
              8DF9E283F7D4A71E9749EE37E74B7F44E5CD667DA6D29A2BDE467DDEDDAA17DF
              4AF9F994CE908D207E85B06900E03188F787EE18545FD8F8DE59BE43D3679E98
              00568062D9957752A27F7EE23FACA88AF6AB102F02C287C68E2DAEE909C8B39A
              73339B3E512F857E27A2512FFD39E9B18508E31CCA970862BCBD6A35009610E1
              1988D5479C3DBE6AFC796BAAD28A955A0695F12B9A09A007A9FC64F99BF4F53E
              4A71D8FE15289816D62C9CB5146073A597346BC5DFD9BF7FE7B310D3CFBE7D13
              C789102A8D5AF1C2259DE9A844005AA4EE614AD16F026E22726F6F9C9D5D15BD
              32F1D0800980E661D3B6DD2F27C71088F86AFA1AE5F64D10E2979683E7A76430
              DD373B7B224A8554C7A6538E16D9F36A4A88907B3502CA6B1210E127377E74FC
              78C1AE6C8A5087D80C9D7902A0C0AFAF1A19F94E8433D21BF4AF69CE95FE3A42
              5D8C0EDDA84F1F6ED467E43509841C5E0620EE87883E02E05E9AFBCCDF29C834
              0190032C90FF4D520A7F439896FF1529A53AE8DD806DEE9DF94EB35EDAD094A7
              091D7C1BB55BA414F6B674A76073B1FCD3610F6C72BC20B23349009B27765D46
              C14FFF04E09C206029B715F0F5C55171B1747A3A9FAF29CB4B8980D6FCCC1708
              93B105CC9D4D261DA214EA36BA88DF97CBA7873A684C06CB1C015893D589D1DC
              E8B7C3C49F98469E076373AEB8EE60A5F48330C74ED258F7D5A67F4C44702D25
              BACB087784A9BB5C3EDD9AAA1E0C73CC388C952902C8DBE50701C55C58C03B81
              4FF7D3E595F0B0864DC53844961F5C2202C0DB433348881BF276E57BA18D1783
              8132430074C8FF1C5D817E53189873E0EB4399EE84DC2589403EC5A84FAABB24
              04B8947C456CDDFAB131F756F1AD09AA592608404E2801637E196A3AC797CECA
              FFF1096DCD5B6BAE5496D812B98672987EF2ECE74FFCF64CE5A59ACD889DB854
              13C0C68D1B479683DF38F00246D6D261EB3AE303657C0022D71B972F161A7F20
              6A751B7EB8E57DE95E8F30B504205F3C31FEB23784706B09EF94FF995AF5A927
              321E9BA199BF7CB1704D0EC4F5A607ED8CC11372F117D3E344253F950420EFEB
              CA174F980495CE499F91814FE7A8FFD3E4382CDB1D8103F5D2E7E51CD069C1D7
              DC5B69A8198147F393955FD020C9A8886184A78E00E412D2F2BEEE3060F8EF23
              6EA773525EE6DB3F60465BD269C1EB45BB7DB5C94110E12B74176983C931A290
              9D2A02D832B5F742B984B441203B8BA362BC592FDD65700C163D0402AD7D3BFE
              AA592FCAE7078CDDC643C02F15A6ABFF6E08F562DB253504303B3B3BDA119D1F
              1944BA410E3672B0527AC1E0182C5A1101BA10FB3214E2664531AEDD4547FCFD
              E689FA65AE0D1256911A02F8F6D1F193A6B06FE7F04A0AFE2DA6E4B35CBD0834
              E64A07C68E2D187BCC5BBEFA5C5E67D2ABB59AB4617BA782004CDEEA3BB26661
              EC77F7CEFCD3B00073BF6810D8BF7FF658539E12001879F45A5E67CADBB535D1
              58A76FD4C413806557E822B03E407A247D573AD0A1D9D9106E25F68CCABB5A11
              A039BC98047E8692F60DA1FD4CD29F184C340150F01FD73EAB5D81FBC9715ED1
              DDE5BF494780E67223D960E43D8DF28941929DD82DB10440C1FF55425DFFD24E
              1D5120877937C9E62D4508D09C7E7AB1B368E42DC351FF8048659A124900965D
              2D92D13F4F49EFD6EE6C68CE979A7A85B2B4B82070707EE7932362F412DDFAA0
              FC0151427F4A9C3802D86CEF5E0720CABA27B1838BAF6BEEDB1ED91255BAED61
              79FD11B867CEFEFED8B173F5DF2110E286C274F537FA8F1ADFD2441100DD7A39
              6714461ED30E670E2FFB446D27BFEB4F3BB0F114B87FFFBB9D3B045A15141DF1
              19F2D1442D2F962802A05B2F720D3FAD93267F5926D7A7D32A9485250201BA2E
              4047EF7A55251FFDBE5E8983A5A9D6268600E8BCFF90AAB12BFBCB35F7E52FCB
              5696F3F7EC206082042CBB9298D58613410005BB7C359DF7BF55A75B1E5F7DF2
              C2A4AFB9AF138F2CCB3240025726E5BD0389200001F8B04E071D69AF7AC5A776
              DD16B3D757E9B490650545E0A9A5D79A05EDE5DE5E00DC9B843710C59E002CBB
              A275E517B108EBEED937F15DF7A9E39A2C22F027FB268EE73077914EDBC78F8E
              FF58A7BC95B2747C8F3501585395FF45469E4749CB86207EA5F5916262CECFB4
              18CD427C2370A036FD74F78D45BEBB7835CC910FB7BC1A45591F5B0290EBF981
              006DABED08107B1BF5D29F4709368F1D7F0496EF08E97B6C58C04D1BDF3B3B1E
              57CB634B00E7FCCC2FFE50176802E148AB5E9AD1258FE5A41B01BA28F869B250
              DB0F88C6579D1BDB5B83B12480FC647523225E4093A0656BD58AAFD222888564
              06012201F903224D3F251667D3B52CAD8B94E89A88581200A2F87D5D06D2446A
              7FD843976E2C27DE0890EFC89F12EB52F2E3BA04E994133B02B0ECB2B6477D17
              1705FFE7D7E92D1994A5736521F2EDD85D808E1501DC60D72E05C075A0E143F7
              61FFF7C18F948E6810C522328C805C5948DF1A837865D7C7E30368AC08600CDA
              BA02F678AB5EBC353E30B3264946A031573A4077A4B4AC36ACC3C77562191B02
              284C54AE21C3CEA2A4BC1D59B310DBDB2ECAC6B180481090AB0D6B1AF8AC655F
              D7244E4D4C6C0840E4E0013553BABD05E096433159C7CFB2AB8FC8D4D58CFF06
              4540622753D07EA6DAEB7AF9882E5FD761672C08A06057B6E93086647CA7559F
              69501EF9D6755C711580B8AABB1FB94A8952A08B59BCF0932F1F11005A5E43A6
              D1E795E635160440A0CE2B59B1DCB9592FC6E2850DA79C775931260107085F79
              9CF1A36B4BAFF7658447A3617DDE436CE0EAC8098026FBC381B5EED3418098EA
              531C7A11D9F388FCAF7FE6C07C2470262667962401BF1C88EBCFD43C7809D9AA
              C5F7838F7CAA47E40440C172DB297586DDC376AB5EAA0FDB5B573F9A5097E077
              4660127090E8972705BF03F5D2E7497F0DBF52151A7C9F3451D8222500CBAEE8
              793CB27DFC52050CB474B5E8821F91199DF37B896312E88750D2F05BC09C169F
              B374C5403F507D94454A00A49FFAE391021E6CEEBB5DDB0F8748A7C09BE53BF8
              1DD14C020E12324F227E7229393A8F3F28F5574CBE6340719CBEDD232380C244
              F5DABE1A052CA4FBB36F0ED8456BF3E0CEEB0CCF24209148327EAD7AF1466983
              6AD2150BC3E8111901889CF8E2300AAFE833B7E27BA85F87775E47CD6C93401A
              F013426C776673D85C532C0C357C2404B065A6A2E5154D74DBCF1ECA6A0D9DD4
              9DD751229B249016FC5A73252D2FA9D115138E57F9CD2321804E1B34ACCC831F
              F56BA4EE76FA9CD7D12C5B24903EFCF076672687CDBD626258B95EFD22210052
              EA0A4A4A5BB33EF35E2501B1EB9C0D12D01FFCD14F24F9E25D1AB4508E896174
              089D00ACA98A8E0776227DDC9726FC750068E05562E9260173C18F8F76E704A2
              FB08B84375704DB111488DD0090004EC0DA4619FC674EEBFA54F71A8455D8763
              12F00B7AAA839F40A0BB511FA44C6DD3101B4115089500F2766D4D5005FBB47F
              A44F5924454C02FE60B7023F27E14F2ED05158770E202E9F43AA8AE4FBC488AA
              CC41FD43250084F6170629E3A76EF5EA936FF1D32EAC365D07E4230137BCADEC
              043F2C60EED7DC70F05BAE2346FC8E25DB854A0034E0D59494B68FEE8ADF2BBD
              9804FA4F6996825F22209F0EA47C9192CAA61C2341060F8D0036DF5A5E1B44B1
              7E6DB123FE6BBFF2389431099C3E0B590B7EC77AD1C17738FBC3E63A62C5EFD8
              A111C0E828DCE35729B7768DF9D21FB8D5C5A19C49A03B0B590D7E697D6B7E46
              F934B73756A44C9329340200C0EB40E923EE57EA1E52E7AC93409683FF948BA9
              FAAA6AAC9CD2C46B2F14022814769FEBA588677D2EB7D9B34D4C1A64950438F8
              971D5083AF6A899965750665A11040E7BC11E5C776975FDA38C89658D5658D04
              38F84FB99F0E5FD51133A73472DF0B8500106093BB0ADE3508F89077ABF8B5C8
              0A0970F09FE97BAA3E8B009BCE94AABF24140250571BB5FCEE5A5D8FE012D24E
              021CFC6E3E910C9F35BC2D916200001000494441544E00F9A93DCA0B7634EAD3
              87DD604E42795A498083DFDDFB74F8AC8ED871D7B05B639C00729D11A59F4A0A
              01BA5E17D6B538A2BF6923010E7E6F4752F55DD5D8F1D610C038010814FFD98F
              226E6D7220EE74AB4B5A795A488083DF9FE7A9F8AE1C413576A40CAF649C00BC
              14F0AA6FCC950E78B549527DD2498083DFBFB725C1778D1240DEAE5DEE1FAEEC
              B44C2A095819FA614F5CBC316F38868C120088F60E452035BC7C41510343DD93
              46021607FFB09EA0E6C3EA3134506FA3048039F8ED81A37B5676227F7592A78A
              0A0D9242021CFC0A930CC17DB87734F518EA9576E6BE51020001E79F39A4FF92
              F1F6EA4897FDF6AFE9F02DE34E021CFCC3CFADECA9ECC38A3124751894CC12C0
              A0917DD4EDDB3771DC47B3C437892B0970F0ABBB56DC7D38D604A00E7F7224C4
              8D0438F893E33B2A9A1A23006BBAAAF80A653CA6625812FBC6850438F8757B8F
              7F5FEE37B27A2CF593DA2D334600203ABFD51D62D8BFE2FF0EDB33C9FDA22601
              0E7E13DEA3E8CBCAB1E46E933902E8C03BDD87F5AE41109FF66E95CE16519100
              07BF197F52F665C5581A64953902405C3D6860AFBA46BDA4E1F5615EA3C4B73E
              6C12E0E037E70BCABEAC184B832C3347008346E53A5F088445021CFCBEA6C378
              A3280660028802F500639A26010EFE009391C2A64C0009985493240020AED20F
              410CDED5A7DFA8544A640248C8B49A2301DD0070F0EB46D4A43C2304909FD8F3
              1A45A59F53EC9FCAEEF127010EFE018E37D0A707F45BAAD210534B7256FE3142
              00B911FCB9950305F92E00FE1EF8D31781F89200077FDF095B2E54F569D5985A
              56E38CCC0801880E5C72C648010A10E0EB019A67AE69FC488083DFCB09557D5A
              35A6DCF433430098BBC06D403FE542C0D37EDA65B94D7C488083DF8F1FAAFAB4
              508C29371D8D10008ACE856E03FA2947C41FF96997F536D1930007BF5F1F1CE4
              D37E64A8C694DB1866080051E90800B0C304E036632BCAA323010EFE155331F8
              ABA24FA36A4CB96867840084AAB26D3E057099AFBEC5E19300077FDF891854A8
              E8D3CA31E5A29B1102808E503B05003E0570992FD7E2F0488083DF75120654A0
              AA4F2BC6949B6A660840F10820971BE15300B7191B506E9E0438F807C03FB0CA
              CDA70776EAAD548CA95E51BDFB6608A07704DE67041881D822608600847846C5
              E24EA77D914AFFACF635F7C31E07517155770CE73BE77E1150F669C59872D3D3
              0C0180DA453C31229800DC66CCA5BC1B98267ED8B3724026819588F8F9AEC1A7
              8D3C1B6384000482D21180103926003F5EB5DC26BCE05F1E1098041C24FCE6FD
              7CDA6F5FD94E35A6A48C7EC90801A0E21100880E1340BFD9EA53167EF03B4A30
              093848F8CA157D5A39A65C94344200A0FE282F1380CB84F5164717FC8E164C02
              0E123E72359F568FA9BE2A1A2100D5C315445403ABAFA9E92A8C3EF81D3C9904
              1C2406E5AA3EAD1A536EBA1921805C0EBFE736A09F7201629D9F76596D139FE0
              77668049C041C22D5FE9D36EEDDCCA5563CA55AE5B855279E7C4DFA9F447C07F
              AFD23FCD7DE317FC0EDA4C020E12FD7254F569C598EAA7932C337204D0A8DF76
              580A5748E728F44D6DD7F806BF0339938083449F5CC9A735C4541F95008C1040
              DF91B8500981F807BF631E938083441272268004CC92B9E0C747016402CD1F26
              814180C6A98E09204EB3D1471793C12F7F3C2413300940563F4C00319E79D3C1
              EF98CE24E02091BDDC1801A0E2E3C037D9E5B7656F3A4E591C56F03B23320938
              48E8CF557D5935960659648C003A1DF8BD41037BD5E544EE5D5E6DD25A1F76F0
              3B3832093848E8CD7B7D7918C9AAB134684C63040028940880FABF7390E269AD
              8B2AF81D3C99041C2434E628D47C5935960698628C005AF5D2A101E3FAA95AE5
              A7519ADA441DFC0E964C020E12DA72255FD6104BAE86182300D711B9A22F0271
              097E47392601078974E7B12680AD5B779D9F6EF8BBD6C52DF8BB5A0130093848
              0C9FF7FAF0F052CCF5344A0002C4932AAA9F3C67B4A8D23F097DE31AFC0E764C
              020E12C3E5AA3EAC1A435E5A1B250044D1F25260607D47A49A00E21EFCCEDC30
              0938480C912BFAB0720C79A86C9400C6CE3F7FB7C7F883AB11570F6E90DCDAA4
              04BF833093808344C05CD1879563C8435DA304B07FF6DDC73CC6F7ACDE383BAB
              7405D57380081A242DF81D8898041C24FCE5BDBEEBAFC799AD74C4D099524F95
              18258053C30CBF377EF4DC89E17BC7AF675283DF419249C041C23B4F82EF1A27
              0021C4C7BDA11AD442EC18549BA4BAA407BF83359380838457AEE6BBEAB1E3A5
              5F18EB01E0E887BDD518D8E2A5036B13529996E077E0661270901898ABF9AE7A
              EC0C544E561A3F0268D5A79E9003A9246BB2FC0695FE51F74D5BF03B78320938
              489C99F7FAEC99B5FE4A74C48ED748C609A0AB00B6BBF9907F11EF1DB267E4DD
              D21AFC0EB04C020E122B72659F558C9915EAB87D0D850084E8FC0F37057C965F
              E1B35DAC9AA53DF81DB099041C244ECB957C5643CC9CA68CDB975008A0355752
              7B1E80B4D77148456242DBB212FC0EA04C020E12003A7C5547CC9CD2C87D2F14
              02701F3E408DF2215580B1149B662DF81DB898049691E8F1D5E592D866A11100
              82D8AB8882D22195E2D8BEBB6735F81D809804969050F2550DB1B2A4849F3FA1
              11C0E1352F28DFCFCF4F566EF76354546DB21EFC0EEE5926016BAA32E5E0306C
              AE2356FC8E1D1A011C9A9D5DF4AB945B3B44B8D3AD2EEA720EFED36720B32420
              40F5481774C4CAE9B3E1FE2D3402902A20A0F2C5C0C2E4EE2BA5AC3825CBAE3E
              0220AED2AF133EDA0D24FD92C390D8D53D3BEF1DD85C2CFF742FAEC3ECEB8891
              20E3864A008DFACCCE20CAF56B2B70E4C17EE5519571F00F463E4B24307A12EF
              1F8C8677AD8E18F11EE5548B50096079D8A797F36133B5C72B871DB54F3F0EFE
              3EA0F429CA0C0920BCB68FF9418A546323C8584B6D432700C4DC7F5A1A59E18F
              6557BEA4D05D4B578B0FFB03E1987612C8DB95662040FA34D6111B7DC40E2C0A
              9D001AB5E9AF0ED4C85FE5067FCDCCB4E2E01F0ED734930002E4A1E733CCAEA6
              D8083474E804B0A41DE2A79672853F560C8E0214D4EFD335D917FCFA18D4B7A8
              599F791D1879172144F6D1F1DF1F34C4C43000444200CDDACCA661945DD127B2
              A300FD4E9C8DE077E62F6DF8E9F8EFAF29261C887DE7911040573B54FF997084
              4701FA9C385BC1DF9D7B9D4B8E478B9F96FFFEA01E0B0EAE41F3C8084040EEE7
              822ADBA77D6447015217751288D679A50D51A634E0877DCEFD8362AA2916820E
              BBD43E320268D5A78E22E0C292160A7F2CBBFA944277E5AEC33B71B683DF013E
              C9F8599395C71D3B86CD650CC85818B6BF6ABFC808402A7E12167F51E66A495C
              5CB0CB57ABC950EB1DDC8939F87B114F227E79BB7639A8DFF7073D31D08B66B0
              FD4809E0607D8732834A7305E0C3328F32F977620EFE7EF39434FC10DA47FAD9
              11B44C570C041DD7691F2901482544A7F33699AB26BA1873AFAA0CD5FEDE4ECC
              C13F08E3A4E067D9D50FB9D911A45C97EF07197365DBC809A035BFFD0B2B951A
              E63B026C9A9ADAFB9261FAEAECE3EEC41CFC7E704E067E427589BB252874F9FE
              92B021FF444E004B7AB741CB2FE98E8ACE734BF222FE73A61373F007999238E3
              979F2CEB795E5F93CF07C1B55FDB581040735FF13100F16C3F0503968DD2A9C0
              81807D8C343FE5C41CFCC3001C47FC2CBB7C1B225E308C3DA7F711CF767DFEF4
              D228BEC58200A4E102462F97B96AA2538182355D7D85AA1C1DFDA513CBA44356
              166548EC648A83ED9B8BE5730070E04B6EC0E74797AFFB1C6E60B3D81040AB3E
              751400B5DC15808E7812F8C3086844607411359D5EE2E35D5FD7A89C82A8D810
              80B481D87EBDCC75246BAAF2A80E392C8311B0EC8A3CADD4122B3A7D5CC7CC68
              314A87223D32F6F4EC0FBF2B607D61B2BC657801DC931100B871BAFAB3844381
              92FA26A0AA2E44AF84D81140B35E545E3DD8814820DE73E3D4DE9739DF396704
              8220B061767674A423FE117C7CFC3469CE158B7EDA85D9267604208D17273A97
              CA5C471A119DEFEA90C332B287C0DAA3E327B5599DC3CBB4C9D228289604D0BA
              7BFB532040DBB25F965D39A1113316950104C867BEA3CF4CFCDBE6DE198DF2F4
              69164B0290E6D1E1D27532D794C6F293EABFDCD2A40B8B89390214FC1F23155F
              4E49CB4617FE7E5E8B200342624B00D2D61CE6DE20731D09115E9BB7AB351DB2
              58467A11B026CA1659B79592EFCDA3E1468FFA48AB634D00076AD35F41C08774
              2184206C6BB2F27E5DF2584EBA10B0B6ED792BE4B0A1CB2A21C4B7E8A2F66774
              C9332127D604200D6ED467AE91B9B684F081FC64F9166DF258502A10B8696AD7
              5530923BA4D398D65CE90A9DF24CC8CA9910AA5BA680110DCF5F9FD20A11F7E7
              A7ABBF74AA84F7B28C807C743C27461FD189C189763B168FA37BD9940802908F
              4E22C26D5EC604A9C78EF8B2B5ADB23E481F6E9B3E0436CA9F902B3C3AEE82C8
              DC27F7ED48C4EDE744108004B9512BEEA2FCFB94F46D23F0E82DDD27BDF4C964
              49894160E3ECECAA71D139A659E117E8BCDFD62CD398B8C41080448080BD44E6
              3AD36247FC63616AEFEB75CA6459F147E05D3BEFBA60FCE8F871DD9A928F8EEB
              9669525EA208400291C3DC4532D79984E8FC4D7EA2FCDF74CA6459F145E0E66D
              F32F3FEBC5313D0B7BF498B9D8597C65CFD744EC268E000ED4A69FEE0878AB6E
              7431879FCEDBD569DD72595EBC10C8DF5A796D7BE48496A7F24EB34CE0E4C1F9
              9D89FB197AE2084082FE89B9E25F0A006DF76BA54C991044356F9763F78B2DA9
              1B2775040A76F9977114F4AC39D1A38E00F150736E66BEA72831BB892400896E
              AB5E943FF57D42EEEB4C0838CD8F0DEB44341EB224B10BC03F33A0CDF3AD7A49
              EFB32A069474139958029006D10597B532D79DE896E36B2DFE01916E58239397
              9FAA1C96C46E4201F2C1F34CC80D4B66A2094082441380323790C6880404AF27
              6000D91045CA394401DAFF5148130CFA9E141F4A4A3C0148944C4E845C4FA030
              C92B0B499C939436DF5A5E2B83DF94CE0BFFFCD7A3A664872937150420013349
              027265215E6350A29C8C94B72B1F191DC5C3A6B4C5E7DAE7DD77DF7D6D53F2C3
              949B1A0290A099240110B05EFE4791CF8DCBB138C50F810DB3B3A334472FD239
              E1FBC0D06771545CDC68EC78DE90F8D0C5A68A00247A4649400ED0114FD27F18
              B94AACFCC6292608E4ED6A616D7709AFB34CA9941B81CB0F564A3F30253F0AB9
              A9230009A26912A0FF3005CBAE9C8CC3BB08A5BD594F34174F2208A3A42C9F40
              3D502D7E3B6D58A79200E4249926011A63F4A8E81CCBDB957B699FB70810A07B
              FB3605BFA0A18DFEF4F6956B16C6E413A8344EEAB6D412809CA9104800E86860
              9374C2825DBE5A8EC9C93C02D6B60FFF9465571711D0F8126FD28766676717CD
              5B15CD08A9260009A99C40999B4E02F06172CAA74C8F9375F9D664E5011859F5
              030031621A8B7EBE637ACCB0E5A79E0024A0CB13A9FF072052F869495C6CD915
              4149DB92E6A789CFF017C2B44E897816C278ECF6C4B2CFA41EF14C10809C459A
              D0CB50C0DD723F84B4413A2B25260245B02DBB7AB745A44A62262985B17D8D7C
              C5D89D84300C08324666084082D2982BBE4F80B856EE8794980886049A82FE00
              254187FAEF1952C410DDB044C19FA9C561324500D2235AF5D221A179915129D7
              233944F0C3C2E4EE2B3DDA66B6FA3D3BEFBAC0B22B4BABE3180000065A494441
              54FF4089021FF4BC90D3279A8BD05EDFACCF5406354F635DE608404EA25C6494
              981E695FEF1A8324D0637BA9C091AF4B07CF4F566EF7689B99EAC244F9BF484C
              5EECAED2F3BAB00D5F1C15E307EB3BB4AF1310B61DC38C97490270802212B804
              35AF36ECC8F6CA69DC3BA5D353FA863559D6F60624AF71E3522F1FA9B6ECF221
              B25F881CFEFF68F4C2FBC907F060A5F44234E3473F6AA60940C2DFA815774570
              4A208776D21580F857321028A59A0C0AF6DE5715ECEA8364A7808E781200B52F
              ED063E3F08E28D74C8BFC167F3D436CB3C01C8996DD5A78ECAFF04A8F1356452
              EE10E98A9F90C164F95F2950B6FFEAB6F9445F912E4C96B7D0E9CE61B24550D4
              7F4B8078D310B8E8ECF29C9CEB46BDF4E52042D3DA9609A06766E56BC872988B
              C7E138E245A4DAEE4B464EBC2883C79AAAFC9802E9CEAD5B779D4FE5B1DCB611
              5959F69EEDA4EF514AF279082110EFA1D31D230B72040601E14314FCB1C52FB0
              3D1A3A3001AC00F1406DFA2BE424748408F1BA872F603505D2ED27CF1EFD4970
              51901DB726AB9FBCC92EBF6D8519C6BF16ECF22F5B76856ED5555FA07C29D817
              88AC0072BB69F058059910E219B98047B356FC1DD28DB71E0498007AC0E8DD6D
              CE15AF13273A97F696C5707F15A078570EF0734E10AEC817F276599E737F3C3F
              59DE45A994B7AB056BAAFC8EC244E59A9BEDDA3A99E4BE35517E07955B965D2D
              D291C65D965DF958DEAEDC4FF9B3949602BC3717DD0536E9569D383B86B8FC44
              253A04F9CDD65CE9C2B42CE0F113C334EDE434C949A598D6DDDB9F5A3A1A00D8
              935003CF414079CE7D3322EEA0B4870E6D0E80C03F143978A00DEDC76492FB90
              C33FA4F206802823C24EB2772B02BC85F2842E7A291E9773D79A9BB98F6C50DA
              D2DC9909C0C7EC9223EDA044F18099BC57EC03A23835397E12467EA6592FAD8F
              935271D5850920C0CCD06DA3F5DD5B86E2D900DDB86948086007DEDCAC1757DF
              5B9FFA9790864CFC304C0001A7B07BCBB0B406DA7055C0AEDCDC100274683641
              818F8DF9E283868648AD58268021A7B6B9AFF898743AD1E9847E057E489553D8
              0DEF9273D0A817F799322EED7299001467B835BFFD0BD209E58F49107041511C
              77F787C02D12733A25E3DF53F8C3CBB51513802B34C12A0ED6773CDEA8CF9CDB
              BD46804F04EBCDADFD20801DBCAE1BF8C57BFCB4E736DE083001786314A8456B
              E9B1E299B5D25101F153813A73E37E087C532EC72DF16CCCCF7CA95F032E1B1E
              012680E1B1F3ECD9ACCD6C928E8B98FB056AFC3425DEFC2280302DB1A3F49AA8
              96E3F6AB6A92DB310184307B8DDAF457C9912FA28408281F950D61D4440EF165
              790A25716AD68AC657FC4D24429A956602D00CA89738BA4EB0533AF891350B63
              0862AF57FBF4D78B2F2E2E8A5735EB45A4F446790A957E9BE363211340447371
              687676B1512FCD90D34BC74721C44E004CC50B27C1E323003E295FB0D9B5BDF4
              1F0F7EA474C4A30B571B428009C010B041C5B6E64ABB9BF5995119149DB1CE15
              D4BF4129151B0AFC53819DB748DB646AD58B37C4FD059BA900DE87114C003E40
              0ABBC927CADBBF4581B285D2D2D1C1C289857301E18302C49361EB12783C8467
              8580FF236064E94E88B4A13137F3ABADDAF60702CBE20EC6116002300EB1FA00
              F7DD3DBB4017C5EE68D54BAF9401E52422846B65B0D195C567D4470928418817
              01C5BD90C3B737BBE7EF4B64457AAE69CD15DF43E7F2FC2C444048A368CE0410
              05EA9AC62442382483AD512B5E785A102E0724C2C957630EDF49E7DC1320E00E
              1A768EF60F8280CF517A1840FEBA9192808701F173084075625E00CE82109388
              E2B744A7F3B3CD6579A7E573A597346BA5CDCDBD339F03FE2416012680C44E9D
              B7E28DFA6D871B7B67FE5FAB5EDCD79C2B7E9002D8A6FD1B69FFED94DE44D71C
              E45AF8EB97F66B336F6FD48B54579A6CD5673ED09C2BCD376AA5DF6FCD6FFF86
              F748E96A91256B9800B234DB6C2B23B0020126801580F05746204B0830016469
              B6D956466005024C002B00E1AFD946206BD63301646DC6D95E46A0070126801E
              30789711C81A024C00599B71B69711E8418009A0070CDECD360259B49E09208B
              B3CE363302CB0830012C03C119239045049800B238EB6C3323B08C0013C03210
              9C651B81AC5ACF0490D59967BB19014280098040E08D11C82A024C00599D79B6
              9B11200498000804DEB28D4096AD6702C8F2ECB3ED9947800920F32EC0006419
              0126802CCF3EDB9E7904980032EF02D90620EBD6FF1B000000FFFFBBA9049400
              000006494441540300F1C82DD328F404D50000000049454E44AE426082}
          end>
      end>
    Left = 608
    Top = 16
  end
  object vrtlmglstMain: TVirtualImageList
    Images = <
      item
        CollectionIndex = 0
        CollectionName = 'Messages'
        Name = 'Messages'
      end
      item
        CollectionIndex = 1
        CollectionName = 'Log'
        Name = 'Log'
      end
      item
        CollectionIndex = 2
        CollectionName = 'Send'
        Name = 'Send'
      end
      item
        CollectionIndex = 3
        CollectionName = 'Greenhouse'
        Name = 'Greenhouse'
      end
      item
        CollectionIndex = 4
        CollectionName = 'Inventory 1'
        Name = 'Inventory 1'
      end
      item
        CollectionIndex = 5
        CollectionName = 'Inventory 2'
        Name = 'Inventory 2'
      end
      item
        CollectionIndex = 6
        CollectionName = 'System Admin'
        Name = 'System Admin'
      end
      item
        CollectionIndex = 7
        CollectionName = 'Fertilise'
        Name = 'Fertilise'
      end
      item
        CollectionIndex = 8
        CollectionName = 'Water'
        Name = 'Water'
      end
      item
        CollectionIndex = 9
        CollectionName = 'Sales'
        Name = 'Sales'
      end
      item
        CollectionIndex = 10
        CollectionName = 'Up'
        Name = 'Up'
      end
      item
        CollectionIndex = 11
        CollectionName = 'Down'
        Name = 'Down'
      end
      item
        CollectionIndex = 12
        CollectionName = 'Add'
        Name = 'Add'
      end
      item
        CollectionIndex = 13
        CollectionName = 'Cash'
        Name = 'Cash'
      end
      item
        CollectionIndex = 14
        CollectionName = 'Staff'
        Name = 'Staff'
      end
      item
        CollectionIndex = 15
        CollectionName = 'Plant'
        Name = 'Plant'
      end
      item
        CollectionIndex = 16
        CollectionName = 'Save'
        Name = 'Save'
      end
      item
        CollectionIndex = 17
        CollectionName = 'Load'
        Name = 'Load'
      end
      item
        CollectionIndex = 18
        CollectionName = 'Clone'
        Name = 'Clone'
      end
      item
        CollectionIndex = 19
        CollectionName = 'Next'
        Name = 'Next'
      end
      item
        CollectionIndex = 20
        CollectionName = 'Refund'
        Name = 'Refund'
      end
      item
        CollectionIndex = 21
        CollectionName = 'Clear'
        Name = 'Clear'
      end
      item
        CollectionIndex = 22
        CollectionName = 'Switch'
        Name = 'Switch'
      end
      item
        CollectionIndex = 23
        CollectionName = 'Cancel'
        Name = 'Cancel'
      end>
    ImageCollection = imgclctnMain
    Left = 648
    Top = 16
  end
  object dlgOpenLoadInventory: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <
      item
        DisplayName = 'Inventory File'
        FileMask = '*.txt; *.csv'
      end>
    OkButtonLabel = 'Load'
    Options = []
    Title = 'Load Inventory File'
    Left = 528
    Top = 16
  end
  object dlgSaveSaveInventory: TFileSaveDialog
    FavoriteLinks = <>
    FileTypes = <
      item
        DisplayName = 'Inventory Text File'
        FileMask = '*.txt'
      end
      item
        DisplayName = 'Inventory CSV File'
        FileMask = '*.csv'
      end>
    OkButtonLabel = 'Save'
    Options = []
    Title = 'Save Inventory to File'
    Left = 752
    Top = 16
  end
end
