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
  object lblCustomerSelectionHeading: TLabel
    Left = 445
    Top = 55
    Width = 113
    Height = 21
    Caption = 'Select Customer'
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
    OnChange = cmbItemSelectionChange
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
    TabOrder = 1
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
    Text = 'Customer'
    OnChange = cmbCustomerSelectChange
  end
  object btnAddToOrder: TBitBtn
    Left = 11
    Top = 127
    Width = 173
    Height = 33
    Caption = 'Add to Order'
    Enabled = False
    ImageIndex = 12
    ImageName = 'Add'
    Images = frmMain.vrtlmglstMain
    TabOrder = 4
    OnClick = btnAddToOrderClick
  end
  object btnProcessPayment: TBitBtn
    AlignWithMargins = True
    Left = 445
    Top = 126
    Width = 173
    Height = 33
    Caption = 'Process Payment'
    Enabled = False
    ImageIndex = 13
    ImageName = 'Cash'
    Images = frmMain.vrtlmglstMain
    TabOrder = 5
    OnClick = btnProcessPaymentClick
  end
end
