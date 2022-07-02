object F_MathTest: TF_MathTest
  Left = 480
  Top = 248
  BorderIcons = [biSystemMenu]
  Caption = #51340#54364' '#44228#49328#44592' ( '#44033#46020#45716' 360'#46020' '#45800#50948' )'
  ClientHeight = 460
  ClientWidth = 639
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  KeyPreview = True
  OldCreateOrder = False
  Position = poMainFormCenter
  DesignSize = (
    639
    460)
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 8
    Top = 224
    Width = 627
    Height = 189
    Anchors = [akLeft, akTop, akRight, akBottom]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Times New Roman'
    Font.Style = []
    ImeName = 'Microsoft IME 2003'
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 353
    Height = 209
    Caption = 'Calc Rotation '
    TabOrder = 0
    object Label5: TLabel
      Left = 43
      Top = 92
      Width = 15
      Height = 24
      Caption = 'X'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 123
      Top = 92
      Width = 15
      Height = 24
      Caption = 'Y'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 206
      Top = 92
      Width = 52
      Height = 24
      Caption = 'Theta'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 43
      Top = 36
      Width = 30
      Height = 24
      Caption = 'CX'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 131
      Top = 36
      Width = 30
      Height = 24
      Caption = 'CY'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object E_X: TEdit
      Left = 40
      Top = 120
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 2
      Text = '0.0'
    end
    object E_Y: TEdit
      Left = 120
      Top = 120
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 3
      Text = '0.0'
    end
    object E_Th: TEdit
      Left = 208
      Top = 120
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 4
      Text = '0.0'
    end
    object Button3: TButton
      Left = 5
      Top = 152
      Width = 335
      Height = 41
      Caption = '(CX,CY)'#47484' '#51473#49900#51004#47196' (X,Y)'#47484' Theta'#54924#51204#49884#53416' '#50948#52824
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = Button3Click
    end
    object E_Cx: TEdit
      Left = 40
      Top = 64
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 0
      Text = '0.0'
    end
    object E_Cy: TEdit
      Left = 120
      Top = 64
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 1
      Text = '0.0'
    end
  end
  object GroupBox2: TGroupBox
    Left = 368
    Top = 8
    Width = 305
    Height = 209
    Caption = 'Calc Angle'
    TabOrder = 1
    object Label3: TLabel
      Left = 43
      Top = 84
      Width = 26
      Height = 24
      Caption = 'X2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 123
      Top = 84
      Width = 26
      Height = 24
      Caption = 'Y2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 43
      Top = 20
      Width = 26
      Height = 24
      Caption = 'X1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 131
      Top = 20
      Width = 26
      Height = 24
      Caption = 'Y1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object E_X2: TEdit
      Left = 40
      Top = 112
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 2
      Text = '0.0'
    end
    object E_Y2: TEdit
      Left = 120
      Top = 112
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 3
      Text = '0.0'
    end
    object B_2PCalc: TButton
      Left = 40
      Top = 152
      Width = 233
      Height = 41
      Caption = #46160#51216#51032' '#44033#46020' '#44228#49328
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = B_2PCalcClick
    end
    object E_X1: TEdit
      Left = 40
      Top = 48
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 0
      Text = '0.0'
    end
    object E_Y1: TEdit
      Left = 120
      Top = 48
      Width = 73
      Height = 21
      ImeName = 'Microsoft IME 2003'
      TabOrder = 1
      Text = '0.0'
    end
  end
  object B_Clear: TButton
    Left = 445
    Top = 422
    Width = 90
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Clear'
    TabOrder = 3
    OnClick = B_ClearClick
    ExplicitLeft = 483
    ExplicitTop = 442
  end
  object B_Close: TButton
    Left = 541
    Top = 422
    Width = 90
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Close'
    TabOrder = 4
    OnClick = B_CloseClick
    ExplicitLeft = 579
    ExplicitTop = 442
  end
end
