object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'CSDN Offline Files Redirect Block'
  ClientHeight = 442
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object ButtonExecute: TButton
    Left = 32
    Top = 384
    Width = 75
    Height = 25
    Caption = #25191#34892
    TabOrder = 0
    OnClick = ButtonExecuteClick
  end
  object _OpenFileDialog: TOpenDialog
    Left = 272
    Top = 352
  end
end
