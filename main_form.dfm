object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'CSDN Offline Files Redirect Block'
  ClientHeight = 97
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ButtonExecute: TButton
    Left = 176
    Top = 8
    Width = 75
    Height = 25
    Caption = #25191#34892
    TabOrder = 0
    OnClick = ButtonExecuteClick
  end
  object ButtonSelectFile: TButton
    Left = 8
    Top = 8
    Width = 153
    Height = 25
    Caption = #36873#25321#35201#22788#29702#30340#32593#39029#25991#20214
    TabOrder = 1
    OnClick = ButtonSelectFileClick
  end
  object EditSelectedFilePath: TEdit
    Left = 8
    Top = 48
    Width = 612
    Height = 23
    ReadOnly = True
    TabOrder = 2
    Text = 'EditSelectedFilePath'
  end
  object _OpenFileDialog: TOpenDialog
    Left = 296
    Top = 8
  end
end
