object F_XCalcMain: TF_XCalcMain
  Left = 0
  Top = 0
  Caption = 'ICT '#44228#49328#44592'  ( Ver 1.02 )'
  ClientHeight = 235
  ClientWidth = 457
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
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
    Top = 31
    Width = 457
    Height = 185
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'Times New Roman'
    Font.Style = []
    ImeName = 'Microsoft Office IME 2007'
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
    OnKeyDown = M_SentenceKeyDown
    OnKeyPress = M_SentenceKeyPress
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 457
    Height = 31
    ButtonHeight = 30
    ButtonWidth = 30
    Caption = 'ToolBar1'
    Images = ImageList1
    TabOrder = 1
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      AllowAllUp = True
      Caption = 'T'
      ImageIndex = 0
      OnClick = ToolButton1Click
    end
    object RG_Angle: TRadioGroup
      Left = 30
      Top = 0
      Width = 95
      Height = 30
      Columns = 2
      ItemIndex = 1
      Items.Strings = (
        'rad'
        'deg')
      TabOrder = 0
      OnClick = RG_AngleClick
    end
  end
  object SB_Msg: TStatusBar
    Left = 0
    Top = 216
    Width = 457
    Height = 19
    Panels = <
      item
        Width = 50
      end>
  end
  object ImageList1: TImageList
    Left = 372
    Top = 18
    Bitmap = {
      494C010104000A00040010001000FFFFFFFFFF00FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000080800000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000BFBFBF00BFBFBF00BFBFBF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF00000000007F7F7F000000
      00000000000000000000000000000000000000000000BFBFBF00000000007F7F
      7F0000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000007F7F7F00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FF000000FF000000FF000000FF000000BFBFBF00BFBF
      BF00BFBFBF00BFBFBF00FFFFFF00000000000000000000000000000000000000
      0000BFBFBF00BFBFBF00FF000000FF000000FF000000BFBFBF00BFBFBF000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000080800000000000000000007F7F7F00000000007F7F
      7F000000000000000000000000000000000000000000BFBFBF00000000000000
      0000FFFFFF00FFFFFF00FFFFFF00BFBFBF000000000000000000000000000000
      000000000000000000000000000000000000000000007F7F7F007F7F7F00FFFF
      FF00FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000BFBFBF00BFBFBF00BFBFBF00000000000000000000000000000000000000
      0000BFBFBF00FF000000BFBFBF00BFBFBF00BFBFBF00FF000000BFBFBF000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000FFFF00000000007F7F7F0000000000000000000000
      00007F7F7F0000000000000000000000000000000000BFBFBF00BFBFBF000000
      0000000000000000000000000000FFFFFF00BFBFBF0000000000000000000000
      000000000000000000000000000000000000000000007F7F7F007F7F7F00FF00
      0000FF000000FF000000FF00000000808000FF000000FF000000FF000000FF00
      0000FF000000BFBFBF00BFBFBF0000000000000000000000000000000000BFBF
      BF00FF000000FF000000FF000000FF000000FF000000FF000000FF000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      00000080800000000000000000007F7F7F000000000000000000000000000000
      0000000000007F7F7F0000000000000000000000000000000000000000007F7F
      7F00FFFFFF00FFFFFF00FFFFFF0000000000BFBFBF00BFBFBF00000000000000
      000000000000000000000000000000000000000000007F7F7F007F7F7F00FF00
      0000FF000000FF000000FF00000000808000FF000000FF000000FF000000FF00
      0000FF000000BFBFBF00BFBFBF0000000000000000000000000000000000BFBF
      BF00FF000000FFFF0000FF000000FF000000FF000000FF000000FF000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      000000FFFF00000000007F7F7F00000000000000000000000000000000000000
      000000000000000000007F7F7F00000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00BFBFBF00000000000000000000FFFF0000FF
      FF0000FFFF00000000000000000000000000000000007F7F7F00FF000000FF00
      0000FF000000FF0000000080800000808000FF000000FF000000FF000000FF00
      0000FF00000000808000BFBFBF0000000000000000000000000000000000BFBF
      BF00FF000000FFFF0000FFFF0000FF000000FF000000FF000000FF000000BFBF
      BF00000000000000000000000000000000000000000000000000008080000000
      0000000000007F7F7F0000000000000000000000000000000000000000000000
      000000000000BFBFBF0000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000000000000000007F7F7F00FF000000FF00
      0000FF000000FF000000008080000080800000808000FF000000FF000000FF00
      0000FF00000000808000BFBFBF00000000000000000000000000000000000000
      0000BFBFBF00FF000000800000008000000080000000FF000000BFBFBF000000
      000000000000000000000000000000000000000000000000000000FFFF000000
      00007F7F7F00000000000000000000000000000000007F7F7F00000000000000
      0000BFBFBF000000000000FFFF00008080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000FFFF00BFBFBF00000000007F7F7F00FF000000FF00
      0000FF000000008080000080800000808000FF000000FF000000FF000000FF00
      0000FF00000000808000BFBFBF00000000000000000000000000000000000000
      0000BFBFBF00BFBFBF00FFFFFF00FFFFFF00FFFFFF00BFBFBF00BFBFBF000000
      0000000000000000000000000000000000000080800000000000000000007F7F
      7F0000000000000000000000000000000000000000000000000000000000BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF00000000000000000000000000000000007F7F7F00FF000000FF00
      0000FF00000000808000FF000000FF000000FF000000FF000000FF000000FF00
      00000080800000808000BFBFBF00000000000000000000000000000000000000
      000000000000BFBFBF00FFFFFF00FFFFFF00FFFFFF00BFBFBF00000000000000
      00000000000000000000000000000000000000FFFF00000000007F7F7F000000
      00000000000000000000000000007F7F7F000000000000000000BFBFBF000000
      000000FFFF0000808000000000000000000000000000000000000000000000FF
      FF0000FFFF0000000000000000000000000000000000000000000000000000FF
      FF00000000000000000000000000FFFFFF00000000007F7F7F007F7F7F00FF00
      00000080800000808000008080000080800000808000FF000000FF000000FF00
      000000808000BFBFBF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000BFBFBF00FFFFFF00BFBFBF0000000000000000000000
      000000000000000000000000000000000000000000007F7F7F00000000000000
      000000000000000000007F7F7F000000000000000000BFBFBF00000000000000
      000000000000000000000000000000000000000000000000000000FFFF000000
      00000000000000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000000000FF
      FF000000000000FFFF000000000000000000000000007F7F7F007F7F7F00FF00
      00000080800000808000008080000080800000808000FF00000000808000FF00
      000000808000FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000BFBFBF00FFFFFF00BFBFBF0000000000000000000000
      000000000000000000000000000000000000BFBFBF0000000000000000000000
      0000000000007F7F7F000000000000000000BFBFBF000000000000FFFF000080
      80000000000000000000000000000000000000000000000000000000000000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000000000FF
      FF000000000000FFFF000000000000000000000000007F7F7F007F7F7F007F7F
      7F00FF0000000080800000808000FF0000000080800000808000FF0000000080
      80007F7F7F00FFFFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000BFBFBF00FFFFFF00BFBFBF0000000000000000000000
      00000000000000000000000000000000000000000000BFBFBF00000000000000
      0000000000000000000000000000BFBFBF000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000000000FFFF000000
      000000FFFF00000000000000000000000000000000007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F00FF000000FF000000FF000000FF0000007F7F7F007F7F
      7F007F7F7F007F7F7F00FFFFFF00000000000000000000000000000000000000
      00000000000000000000BFBFBF00FFFFFF00BFBFBF0000000000000000000000
      0000000000000000000000000000000000000000000000000000BFBFBF000000
      00000000000000000000BFBFBF000000000000FFFF0000808000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF0000FFFF000000000000FFFF000000000000FF
      FF0000000000000000000000000000000000000000007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F00000000000000000000000000000000000000
      000000000000BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00000000000000
      000000000000000000000000000000000000000000000000000000000000BFBF
      BF0000000000BFBFBF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000FFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000BFBFBF000000000000FFFF00008080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFFC7FFF7F81FF8001F01FFF5F80FF
      8001E00FFD0F007F8001E00FFD07001F8001C007F40380078001C007F401E001
      8001C007D001F8008001E00FD004F8008001E00F4007E0008001F01F4013C000
      8001F83F001F80028001F83F004F80038001F83F807FC0038001F83FC13FE007
      8001F01FE1FFF00FFFFFF83FF4FFFC3F}
  end
end
