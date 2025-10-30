object frmAddPlant: TfrmAddPlant
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Plant Palace'
  ClientHeight = 292
  ClientWidth = 397
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  Position = poMainFormCenter
  TextHeight = 15
  object lblBuildOrderHeading: TLabel
    Left = 11
    Top = 8
    Width = 249
    Height = 37
    Caption = 'Add Plant to Registry'
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
    Top = 247
    Width = 397
    Height = 45
    Align = alBottom
    TabOrder = 0
    ExplicitTop = 139
    ExplicitWidth = 353
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
      Caption = 'Add Plant'
      Enabled = False
      ImageIndex = 12
      ImageName = 'Add'
      Images = frmMain.vrtlmglstMain
      TabOrder = 1
    end
  end
  object LabeledEdit1: TLabeledEdit
    Left = 11
    Top = 79
    Width = 180
    Height = 23
    EditLabel.Width = 62
    EditLabel.Height = 15
    EditLabel.Caption = 'Plant Name'
    TabOrder = 1
    Text = ''
  end
  object rgFertiliseStrategy: TRadioGroup
    Left = 206
    Top = 120
    Width = 180
    Height = 111
    Caption = 'Fertilising Strategy'
    Enabled = False
    Items.Strings = (
      'Liquid'
      'Organic'
      'Slow Release')
    TabOrder = 2
  end
  object rgWaterStrategy: TRadioGroup
    Left = 11
    Top = 120
    Width = 180
    Height = 111
    Caption = 'Watering Strategy'
    Enabled = False
    Items.Strings = (
      'Frequent'
      'Sparse'
      'Seasonal')
    TabOrder = 3
  end
end
