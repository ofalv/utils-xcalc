
#ifndef ICT_LOG_LIB_HEADER
#define ICT_LOG_LIB_HEADER

#ifndef __STDIO_H
#include <stdio.h>
#endif
// Type�� �ְ� �Ϲ� String �� ����

/*

<< ��ũ�� ���� >>

LOG_PRINTF				: Printf
LOG_STR					: Log ���ڿ��� �߰�
LOG_PRINTF_NOTYPE		: Type�� �ȵ� Printf ( Old ������Ʈ�� )
LOG_STR_NOTYPE			: Type�� �ȵ� LOG_STR ( Old ������Ʈ�� )


// �Ʒ� �ΰ��� �Լ� ��ũ�δ� Type�� ���� ���� XMachine.DLL�� Log �Լ���
// XfLogMsg, XfLogPrintf�� �����ϱ� ���� ����� �ξ���.
// �� �Լ��� Type �κп� "..." �� ���� �ȴ�.


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