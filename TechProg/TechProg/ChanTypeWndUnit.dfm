object ChanTypeWnd: TChanTypeWnd
  Left = 494
  Top = 153
  Width = 374
  Height = 642
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object ListView1: TListView
    Left = 0
    Top = 0
    Width = 366
    Height = 586
    Align = alClient
    Checkboxes = True
    Color = clWhite
    Columns = <>
    ColumnClick = False
    RowSelect = True
    PopupMenu = PopupMenu1
    TabOrder = 0
    ViewStyle = vsReport
  end
  object PopupMenu1: TPopupMenu
    Left = 328
    Top = 8
    object N5: TMenuItem
      Caption = #1050#1072#1085#1072#1083#1099
      object N6: TMenuItem
        Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1077#1084#1099#1077' '#1082#1072#1085#1072#1083#1099
      end
    end
    object N7: TMenuItem
      Caption = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093
      object N8: TMenuItem
        Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 144
    Top = 120
    object N11: TMenuItem
      Caption = '1'
    end
  end
end
