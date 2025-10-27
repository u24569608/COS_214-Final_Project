object frmGreenhouseInformation: TfrmGreenhouseInformation
  Left = 0
  Top = 0
  Width = 640
  Height = 323
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
  object lblGrowthLabel: TLabel
    Left = 438
    Top = 13
    Width = 52
    Height = 21
    Caption = 'Growth'
  end
  object lbledtPlantName: TLabeledEdit
    Left = 16
    Top = 40
    Width = 180
    Height = 29
    EditLabel.Width = 81
    EditLabel.Height = 21
    EditLabel.Caption = 'Plant Name'
    ReadOnly = True
    TabOrder = 0
    Text = #8212
  end
  object lbledtPlantState: TLabeledEdit
    Left = 226
    Top = 40
    Width = 180
    Height = 29
    EditLabel.Width = 73
    EditLabel.Height = 21
    EditLabel.Caption = 'Plant State'
    ReadOnly = True
    TabOrder = 1
    Text = #8212
  end
  object pbGrowth: TProgressBar
    Left = 438
    Top = 40
    Width = 180
    Height = 29
    Smooth = True
    TabOrder = 2
  end
  object rgWaterStrategy: TRadioGroup
    Left = 16
    Top = 86
    Width = 180
    Height = 165
    Caption = 'Watering Strategy'
    Items.Strings = (
      'Frequent'
      'Sparse'
      'Seasonal')
    TabOrder = 3
    OnClick = rgWaterStrategyClick
  end
  object rgFertiliseStrategy: TRadioGroup
    Left = 226
    Top = 86
    Width = 180
    Height = 165
    Caption = 'Fertilising Strategy'
    Items.Strings = (
      'Liquid'
      'Organic'
      'Slow Release')
    TabOrder = 4
    OnClick = rgFertiliseStrategyClick
  end
  object grpAction: TGroupBox
    Left = 438
    Top = 86
    Width = 180
    Height = 165
    Caption = 'Care'
    TabOrder = 5
    object btnFertilise: TBitBtn
      Left = 16
      Top = 97
      Width = 100
      Height = 33
      Caption = 'Fertilise'
      Enabled = False
      ImageIndex = 7
      ImageName = 'Fertilise'
      Images = frmMain.vrtlmglstMain
      TabOrder = 0
    end
    object btnWater: TBitBtn
      Left = 16
      Top = 49
      Width = 100
      Height = 33
      Caption = 'Water'
      Enabled = False
      ImageIndex = 8
      ImageName = 'Water'
      Images = frmMain.vrtlmglstMain
      TabOrder = 1
    end
  end
end
