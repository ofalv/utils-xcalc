//---------------------------------------------------------------------------

#ifndef CalcModuleH
#define CalcModuleH
//---------------------------------------------------------------------------
enum CT_TYPE
{
	CT_NUM,
	CT_OPEN_BRACKET,
	CT_CLOSE_BRACKET,
	CT_OP, // 연산자
	CT_SIGN, // +- 부호표시
	CT_FUNC,

};


enum ANGLE_TYPE
{
	AT_RAD,
	AT_DEG,

};



extern String g_sErrMsg;

extern String asTypeStr[];

// 각각의 파싱한 아이템을 저장하는 클래스
class CalcItem
{
public:
	CalcItem(CT_TYPE type , String data)
	{
		m_eType = type;
		m_sData = data;
   }
	CT_TYPE m_eType;
	String m_sData;

};


extern void SetAngleType(ANGLE_TYPE type);

extern void LogSplitList(TList *pList, String sTitle="");

extern bool SplitSentence(String sSentence , TList *pList, /*OUT*/int &iErrIdx);
extern bool Calc(TList *pList , double &dResult);

extern String NumberToStr(double dNum , int prec);




#endif
