object frmAddItem: TfrmAddItem
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Plant Palace'
  ClientHeight = 221
  ClientWidth = 397
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 15
  object lblHeading: TLabel
    Left = 11
    Top = 8
    Width = 259
    Height = 37
    Caption = 'Add Item to Inventory'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 9203809
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    StyleElements = [seClient, seBorder]
  end
  object pnlBase: TPanel
    Left = 0
    Top = 176
    Width = 397
    Height = 45
    Align = alBottom
    TabOrder = 0
    object btnCancel: TButton
      Left = 173
      Top = 9
      Width = 100
      Height = 28
      Caption = 'Cancel'
      ImageIndex = 23
      ImageName = 'Cancel'
      Images = frmMain.vrtlmglstMain
      TabOrder = 0
      OnClick = btnCancelClick
    end
    object btnAdd: TButton
      Left = 286
      Top = 9
      Width = 100
      Height = 28
      Caption = 'Add Item'
      Enabled = False
      ImageIndex = 12
      ImageName = 'Add'
      Images = frmMain.vrtlmglstMain
      TabOrder = 1
      OnClick = btnAddClick
    end
  end
  object lbledtItemName: TLabeledEdit
    Left = 11
    Top = 74
    Width = 180
    Height = 23
    EditLabel.Width = 59
    EditLabel.Height = 15
    EditLabel.Caption = 'Item Name'
    TabOrder = 1
    Text = ''
    OnChange = lbledtItemNameChange
  end
  object lbledtItemPrice: TLabeledEdit
    Left = 11
    Top = 130
    Width = 180
    Height = 23
    EditLabel.Width = 53
    EditLabel.Height = 15
    EditLabel.Caption = 'Item Price'
    Enabled = False
    TabOrder = 2
    Text = ''
    OnChange = lbledtItemPriceChange
  end
end
