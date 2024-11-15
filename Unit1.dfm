object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsSingle
  Caption = #1054#1073#1088#1072#1073#1086#1090#1082#1072' wav '#1092#1072#1081#1083#1086#1074
  ClientHeight = 430
  ClientWidth = 489
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 47
    Width = 73
    Height = 13
    Caption = #1054#1090#1082#1088#1099#1090' '#1092#1072#1081#1083':'
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 129
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' WAV '#1092#1072#1081#1083
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 8
    Width = 129
    Height = 25
    Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100
    TabOrder = 1
  end
  object Button3: TButton
    Left = 346
    Top = 8
    Width = 129
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' WAV '#1092#1072#1081#1083
    TabOrder = 2
    OnClick = Button3Click
  end
  object GroupBox1: TGroupBox
    Left = 11
    Top = 101
    Width = 465
    Height = 316
    BiDiMode = bdLeftToRight
    Caption = #1058#1077#1089#1090#1086#1074#1099#1081' '#1089#1080#1075#1085#1072#1083
    ParentBiDiMode = False
    TabOrder = 3
    object Label2: TLabel
      Left = 11
      Top = 58
      Width = 99
      Height = 13
      Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' ('#1084#1089'):'
    end
    object Label6: TLabel
      Left = 11
      Top = 24
      Width = 72
      Height = 13
      Caption = #1063#1072#1089#1090#1086#1090#1072' ('#1043#1094'): '
    end
    object Label7: TLabel
      Left = 236
      Top = 24
      Width = 112
      Height = 13
      Caption = #1064#1072#1075' '#1074#1099#1073#1086#1088#1072' '#1095#1072#1089#1090#1086#1090#1099':'
    end
    object Label3: TLabel
      Left = 11
      Top = 133
      Width = 145
      Height = 13
      Caption = #1063#1072#1089#1090#1086#1090#1072' '#1076#1080#1089#1082#1088#1077#1090#1080#1079#1072#1094#1080#1080' ('#1043#1094')'
    end
    object Label4: TLabel
      Left = 11
      Top = 163
      Width = 67
      Height = 13
      Caption = #1052#1086#1085#1086'/'#1057#1090#1077#1088#1077#1086
    end
    object Label5: TLabel
      Left = 11
      Top = 192
      Width = 121
      Height = 13
      Caption = #1043#1083#1091#1073#1080#1085#1072' '#1079#1074#1091#1095#1072#1085#1080#1103' ('#1073#1080#1090')'
    end
    object Label8: TLabel
      Left = 80
      Top = 96
      Width = 294
      Height = 13
      Alignment = taCenter
      Caption = #1057#1086#1079#1076#1072#1085#1080#1077'  '#1086#1090#1076#1077#1083#1100#1085#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072' ('#1073#1077#1079' '#1076#1086#1073#1072#1074#1083#1077#1085#1080#1103' '#1082' '#1092#1072#1081#1083#1091')'
    end
    object Label9: TLabel
      Left = 11
      Top = 256
      Width = 120
      Height = 13
      Caption = #1055#1077#1088#1080#1086#1076' '#1089#1083#1077#1076#1086#1074#1072#1085#1080#1103'('#1084#1089')'
    end
    object Label10: TLabel
      Left = 8
      Top = 224
      Width = 242
      Height = 13
      Caption = ' '#1044#1083#1103' '#1089#1086#1079#1076#1072#1085#1080#1103' '#1090#1086#1085#1072#1083#1100#1085#1086'-'#1080#1084#1087#1091#1083#1100#1089#1085#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072': '
    end
    object Label11: TLabel
      Left = 11
      Top = 283
      Width = 101
      Height = 13
      Caption = #1044#1083#1080#1085#1072' '#1080#1084#1087#1091#1083#1100#1089#1072'('#1084#1089')'
    end
    object Button5: TButton
      Left = 320
      Top = 53
      Width = 115
      Height = 26
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100
      Enabled = False
      TabOrder = 0
      OnClick = Button5Click
    end
    object Edit1: TEdit
      Left = 116
      Top = 55
      Width = 89
      Height = 21
      TabOrder = 1
      Text = '20000'
    end
    object ComboBox3: TComboBox
      Left = 354
      Top = 21
      Width = 81
      Height = 21
      TabOrder = 5
      Text = '100'
      OnChange = ComboBox3Change
      Items.Strings = (
        '100'
        '200'
        '500'
        '1000'
        '2000'
        '5000')
    end
    object ComboBox: TComboBox
      Left = 173
      Top = 130
      Width = 89
      Height = 21
      TabOrder = 2
      Items.Strings = (
        '8000'
        '11025'
        '16000'
        '22050'
        '32000'
        '44100'
        '48000'
        '96000')
    end
    object ComboBox1: TComboBox
      Left = 173
      Top = 157
      Width = 89
      Height = 21
      TabOrder = 3
      Items.Strings = (
        #1052#1086#1085#1086
        #1057#1090#1077#1088#1077#1086)
    end
    object ComboBox2: TComboBox
      Left = 173
      Top = 192
      Width = 89
      Height = 21
      TabOrder = 4
      Items.Strings = (
        '8'
        '16')
    end
    object Edit3: TEdit
      Left = 173
      Top = 253
      Width = 89
      Height = 21
      TabOrder = 6
    end
    object Edit4: TEdit
      Left = 173
      Top = 280
      Width = 89
      Height = 21
      TabOrder = 7
    end
    object RadioGroup1: TRadioGroup
      Left = 282
      Top = 130
      Width = 180
      Height = 80
      Caption = #1058#1080#1087' '#1089#1086#1079#1076#1072#1074#1072#1077#1084#1086#1075#1086' '#1089#1080#1075#1085#1072#1083#1072
      Items.Strings = (
        #1090#1086#1085#1072#1083#1100#1085#1099#1081
        #1090#1086#1085#1072#1083#1100#1085#1086'- '#1080#1084#1087#1091#1083#1100#1089#1085#1099#1081' ')
      TabOrder = 8
      OnClick = RadioGroup1Click
    end
    object Button7: TButton
      Left = 307
      Top = 256
      Width = 128
      Height = 36
      Caption = #1057#1086#1079#1076#1072#1090#1100
      Enabled = False
      TabOrder = 9
      OnClick = Button7Click
    end
  end
  object Edit2: TEdit
    Left = 8
    Top = 66
    Width = 465
    Height = 21
    TabOrder = 4
    Text = #1055#1086#1082#1072' '#1085#1080#1095#1077#1075#1086' '#1085#1077' '#1086#1090#1082#1088#1099#1090#1086
    OnChange = Edit2Change
  end
  object SpinEdit2: TSpinEdit
    Left = 127
    Top = 122
    Width = 89
    Height = 22
    Increment = 100
    MaxValue = 16000
    MinValue = 100
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    Value = 5000
    OnChange = SpinEdit2Change
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '.wav'
    Filter = #1040#1091#1076#1080#1086' '#1092#1072#1081#1083#1099' '#1073#1077#1079' '#1089#1078#1072#1090#1080#1103'|*.wav'
    Title = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
    Left = 360
    Top = 40
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.wav'
    Filter = #1040#1091#1076#1080#1086' '#1092#1072#1081#1083#1099' '#1073#1077#1079' '#1089#1078#1072#1090#1080#1103'|*.wav'
    Title = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1092#1072#1081#1083' '#1082#1072#1082
    Left = 424
    Top = 40
  end
end
