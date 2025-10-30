object frmGreenhouseInformation: TfrmGreenhouseInformation
  Left = 0
  Top = 0
  Width = 640
  Height = 496
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
  object lblGrowthLabelHeading: TLabel
    Left = 438
    Top = 101
    Width = 85
    Height = 21
    Caption = 'Health Level'
  end
  object lblWaterLevelHeading: TLabel
    Left = 16
    Top = 101
    Width = 81
    Height = 21
    Caption = 'Water Level'
  end
  object lblNutrientLevelHeading: TLabel
    Left = 226
    Top = 101
    Width = 98
    Height = 21
    Caption = 'Nutrient Level'
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
    Top = 128
    Width = 180
    Height = 29
    Smooth = True
    TabOrder = 2
  end
  object rgWaterStrategy: TRadioGroup
    Left = 16
    Top = 192
    Width = 180
    Height = 227
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
    Top = 192
    Width = 180
    Height = 227
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
    Top = 192
    Width = 180
    Height = 227
    Caption = 'Care'
    TabOrder = 5
    object lblSelectStaffMemberHeading: TLabel
      Left = 16
      Top = 33
      Width = 151
      Height = 21
      Caption = 'Select a Staff Member'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 9203809
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      StyleElements = [seClient, seBorder]
    end
    object btnFertilise: TBitBtn
      Left = 16
      Top = 168
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
      Top = 120
      Width = 100
      Height = 33
      Caption = 'Water'
      Enabled = False
      ImageIndex = 8
      ImageName = 'Water'
      Images = frmMain.vrtlmglstMain
      TabOrder = 1
    end
    object cmbStaffMember: TComboBox
      Left = 16
      Top = 63
      Width = 150
      Height = 29
      TabOrder = 2
      Text = 'Staff Member'
    end
  end
  object pbWater: TProgressBar
    Left = 16
    Top = 128
    Width = 180
    Height = 29
    Smooth = True
    TabOrder = 6
  end
  object pbNutrients: TProgressBar
    Left = 226
    Top = 128
    Width = 180
    Height = 29
    Smooth = True
    TabOrder = 7
  end
  object lbledtSaleReadiness: TLabeledEdit
    Left = 438
    Top = 40
    Width = 180
    Height = 29
    EditLabel.Width = 103
    EditLabel.Height = 21
    EditLabel.Caption = 'Sale Readiness'
    ReadOnly = True
    TabOrder = 8
    Text = #8212
  end
end
