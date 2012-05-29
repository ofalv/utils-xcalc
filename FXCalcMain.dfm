object F_XCalcMain: TF_XCalcMain
  Left = 0
  Top = 0
  ClientHeight = 505
  ClientWidth = 339
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object M_Sentence: TMemo
    Left = 0
    Top = 0
    Width = 339
    Height = 464
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = #46027#50880#52404
    Font.Style = [fsBold]
    ImeName = 'Microsoft Office IME 2007'
    Lines.Strings = (
      #44228#49328#49885#51012' '#51077#47141#54616#49464#50836)
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
    OnKeyDown = M_SentenceKeyDown
    OnKeyPress = M_SentenceKeyPress
  end
  object SB_Msg: TStatusBar
    Left = 0
    Top = 464
    Width = 339
    Height = 41
    Panels = <
      item
        Width = 50
      end>
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 24
    object AngleType1: TMenuItem
      Caption = '&Angle Type'
      object Radian1: TMenuItem
        Caption = '&Radian'
        OnClick = Radian1Click
      end
      object Degree1: TMenuItem
        Caption = '&Degree'
        Checked = True
        OnClick = Degree1Click
      end
    end
    object Help1: TMenuItem
      Caption = '&Help'
      OnClick = Help1Click
    end
    object Clear1: TMenuItem
      Caption = '&Clear'
      OnClick = Clear1Click
    end
    object Exit1: TMenuItem
      Caption = 'E&xit'
      OnClick = Exit1Click
    end
  end
end
