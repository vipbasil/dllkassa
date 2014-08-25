object MainWnd: TMainWnd
  Left = 421
  Top = 287
  Width = 859
  Height = 343
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    object File1: TMenuItem
      Caption = 'File'
      object Close1: TMenuItem
        Caption = 'Close'
        OnClick = Close1Click
      end
    end
    object Channels1: TMenuItem
      Caption = 'Channels'
      object CH1: TMenuItem
        Caption = 'CH1'
        OnClick = CH1Click
      end
      object XML1: TMenuItem
        Caption = 'XML'
        OnClick = XML1Click
      end
      object Restoreposition1: TMenuItem
        Caption = 'Restore position'
        OnClick = Restoreposition1Click
      end
      object test1: TMenuItem
        Caption = 'test'
        OnClick = test1Click
      end
    end
    object Tools1: TMenuItem
      Caption = 'Tools'
      object Options1: TMenuItem
        Caption = 'Options'
      end
    end
  end
end
