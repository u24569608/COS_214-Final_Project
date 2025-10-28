object frmSales: TfrmSales
  Left = 0
  Top = 0
  Width = 640
  Height = 761
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
  object lblBuildOrderHeading: TLabel
    Left = 11
    Top = 8
    Width = 195
    Height = 37
    Caption = 'Build your Order'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 9203809
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    StyleElements = [seClient, seBorder]
  end
  object lblItemSelectionHeading: TLabel
    Left = 11
    Top = 57
    Width = 76
    Height = 21
    Caption = 'Select Item'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 9203809
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    StyleElements = [seClient, seBorder]
  end
  object lblCheckoutHeading: TLabel
    Left = 11
    Top = 202
    Width = 251
    Height = 37
    Caption = 'Complete your Order'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 9203809
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    StyleElements = [seClient, seBorder]
  end
  object lblOrderSummaryHeading: TLabel
    Left = 11
    Top = 253
    Width = 96
    Height = 21
    Caption = 'Order Receipt'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 9203809
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    StyleElements = [seClient, seBorder]
  end
  object cmbItemSelection: TComboBox
    Left = 11
    Top = 84
    Width = 195
    Height = 29
    TabOrder = 0
    Text = 'Item'
    OnChange = cmbItemSelectionChange
  end
  object pnlAddToOrder: TPanel
    Left = 11
    Top = 128
    Width = 606
    Height = 49
    ParentBackground = False
    TabOrder = 1
    object btnAddToOrder: TBitBtn
      Left = 440
      Top = 8
      Width = 156
      Height = 33
      Caption = 'Add to Order'
      Enabled = False
      ImageIndex = 12
      ImageName = 'Add'
      Images = frmMain.vrtlmglstMain
      TabOrder = 0
      OnClick = btnAddToOrderClick
    end
  end
  object redtOrderDetails: TRichEdit
    Left = 11
    Top = 280
    Width = 238
    Height = 241
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    PlainText = True
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 2
    StyleElements = [seClient, seBorder]
  end
  object lbledtCustomerName: TLabeledEdit
    Left = 11
    Top = 558
    Width = 238
    Height = 29
    EditLabel.Width = 114
    EditLabel.Height = 21
    EditLabel.Caption = 'Customer Name'
    Enabled = False
    TabOrder = 3
    Text = ''
    TextHint = 'Enter your name'
    OnChange = lbledtCustomerNameChange
  end
  object pnlProcessPayment: TPanel
    Left = 11
    Top = 608
    Width = 606
    Height = 49
    ParentBackground = False
    TabOrder = 4
    object btnProcessPayment: TBitBtn
      Left = 440
      Top = 8
      Width = 156
      Height = 33
      Caption = 'Process Payment'
      Enabled = False
      ImageIndex = 13
      ImageName = 'Cash'
      Images = frmMain.vrtlmglstMain
      TabOrder = 0
    end
  end
  object btnRefund: TBitBtn
    Left = 451
    Top = 672
    Width = 156
    Height = 33
    Caption = 'Refund Order'
    Enabled = False
    ImageIndex = 13
    ImageName = 'Cash'
    Images = frmMain.vrtlmglstMain
    TabOrder = 5
  end
end
