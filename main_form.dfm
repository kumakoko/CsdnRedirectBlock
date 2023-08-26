object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'CSDN Offline Files Redirect Block'
  ClientHeight = 440
  ClientWidth = 620
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = _MainMenu
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
  object _CheckListBoxSelectedFiles: TCheckListBox
    Left = 8
    Top = 8
    Width = 608
    Height = 97
    ItemHeight = 15
    TabOrder = 1
  end
  object _OpenFileDialog: TOpenDialog
    Left = 472
    Top = 392
  end
  object _MainMenu: TMainMenu
    Left = 360
    Top = 392
    object _MenuFile: TMenuItem
      Caption = #25991#20214
      object _MenuItemSelectFiles: TMenuItem
        Caption = #36873#25321#25991#20214
        OnClick = _MenuItemSelectFilesClick
      end
      object _MenuItemSelectDirectory: TMenuItem
        Caption = #36873#25321#30446#24405
        OnClick = _MenuItemSelectDirectoryClick
      end
    end
  end
end
