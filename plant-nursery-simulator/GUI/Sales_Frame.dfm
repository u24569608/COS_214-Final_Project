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
  DesignSize = (
    640
    761)
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
    Left = 258
    Top = 8
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
    Left = 258
    Top = 57
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
    Width = 173
    Height = 29
    TabOrder = 0
    Text = 'Item'
  end
  object pnlAddToOrder: TPanel
    Left = 11
    Top = 128
    Width = 614
    Height = 49
    Anchors = [akLeft, akTop, akRight]
    ParentBackground = False
    TabOrder = 1
    DesignSize = (
      614
      49)
    object btnAddToOrder: TBitBtn
      Left = 448
      Top = 8
      Width = 156
      Height = 33
      Anchors = [akTop, akRight]
      Caption = 'Add to Order'
      Enabled = False
      ImageIndex = 12
      ImageName = 'Add'
      Images = frmMain.vrtlmglstMain
      TabOrder = 0
      OnClick = btnAddToOrderClick
      ExplicitLeft = 440
    end
  end
  object redtOrderDetails: TRichEdit
    Left = 258
    Top = 84
    Width = 173
    Height = 120
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
  object btnRefund: TBitBtn
    Left = 445
    Top = 171
    Width = 173
    Height = 33
    Caption = 'Refund Order'
    Enabled = False
    ImageIndex = 20
    ImageName = 'Refund'
    Images = frmMain.vrtlmglstMain
    TabOrder = 2
  end
  object cmbCustomerSelect: TComboBox
    Left = 445
    Top = 84
    Width = 173
    Height = 29
    Enabled = False
    TabOrder = 3
    Text = ''
    TextHint = 'Enter your name'
    OnChange = lbledtCustomerNameChange
  end
  object btnAddToOrder: TBitBtn
    Left = 11
    Top = 608
    Width = 614
    Height = 49
    Anchors = [akLeft, akTop, akRight]
    ParentBackground = False
    TabOrder = 4
    DesignSize = (
      614
      49)
    object btnProcessPayment: TBitBtn
      Left = 448
      Top = 8
      Width = 156
      Height = 33
      Anchors = [akTop, akRight]
      Caption = 'Process Payment'
      Enabled = False
      ImageIndex = 13
      ImageName = 'Cash'
      Images = frmMain.vrtlmglstMain
      TabOrder = 0
      ExplicitLeft = 440
    end
  end
  object btnRefund: TBitBtn
    Left = 459
    Top = 672
    Width = 156
    Height = 33
    Anchors = [akTop, akRight]
    Caption = 'Refund Order'
    Enabled = False
    ImageIndex = 13
    ImageName = 'Cash'
    Images = frmMain.vrtlmglstMain
    TabOrder = 5
  end
end
