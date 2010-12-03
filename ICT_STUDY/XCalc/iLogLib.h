
#ifndef ICT_LOG_LIB_HEADER
#define ICT_LOG_LIB_HEADER

#ifndef __STDIO_H
#include <stdio.h>
#endif
// Type만 있고 일반 String 만 저장

/*

<< 매크로 설명 >>

LOG_PRINTF				: Printf
LOG_STR					: Log 문자열만 추가
LOG_PRINTF_NOTYPE		: Type이 안들어간 Printf ( Old 프로젝트용 )
LOG_STR_NOTYPE			: Type이 안들어간 LOG_STR ( Old 프로젝트용 )


// 아래 두개의 함수 매크로는 Type이 없는 기존 XMachine.DLL의 Log 함수인
// XfLogMsg, XfLogPrintf를 포팅하기 쉽게 만들어 두었다.
// 두 함수는 Type 부분에 "..." 이 들어가게 된다.


*/





PACKAGE void AddIctLog(int line, char *func, char*file, AnsiString sType,  AnsiString sLogMsg);
PACKAGE void AddIctLogFormat( int line, char *func, char*file,AnsiString type, char * lpszFormat, ...);

PACKAGE void AddIctLogW(int line, char *func, char*file, String sType,  String sLogMsg);
PACKAGE void AddIctLogFormatW( int line, char *func, char*file,String type, wchar_t * lpszFormat, ...);

PACKAGE bool SendBuffLog(int iPeriod);
PACKAGE void ShowLogDlg(void);
PACKAGE void ClearLogDlg(void);
PACKAGE bool GetLogTheadSend();
PACKAGE bool SetLogTheadSend(bool bThreadSend);


#define LOG_PRINTF(...)			AddIctLogFormat(__LINE__, __FUNC__, __FILE__, __VA_ARGS__)
#define LOG_PRINTFA(...)		AddIctLogFormat(__LINE__, __FUNC__, __FILE__, __VA_ARGS__)
#define LOG_STR(p1,p2)			AddIctLog(__LINE__, __FUNC__, __FILE__, p1,p2)

#define LOG_PRINTFW(...)		AddIctLogFormatW(__LINE__, __FUNC__, __FILE__, __VA_ARGS__)
#define LOG_STRW(p1,p2)			AddIctLogW(__LINE__, __FUNC__, __FILE__, p1,p2)


#endif