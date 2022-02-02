
// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 일부 CString 생성자는 명시적으로 선언됩니다.

// MFC의 공통 부분과 무시 가능한 경고 메시지에 대한 숨기기를 해제합니다.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 핵심 및 표준 구성 요소입니다.
#include <afxext.h>         // MFC 확장입니다.


#include <afxdisp.h>        // MFC 자동화 클래스입니다.



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Internet Explorer 4 공용 컨트롤에 대한 MFC 지원입니다.
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Windows 공용 컨트롤에 대한 MFC 지원입니다.
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC의 리본 및 컨트롤 막대 지원
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>




#define START_LOAD 72
#define WM_TRAY_NOTIFYICACTION WM_APP+10
enum {
	TRAY_BALLOON = 0
};
extern int a,b,c;
extern int color;
extern int checksom;
extern int finedustint;

//color
#define		CR_RED			RGB(255, 0, 0)
#define		CR_BLACK		RGB(0, 0, 0)		
#define		CR_GRAY			RGB(128, 128, 128)		
#define		CR_GRAY2		RGB(223, 223, 223)		
#define		CR_WHITE		RGB(255, 255, 255)		
#define		CR_WINDOW		RGB(58, 110, 165)	
#define		CR_ORANGE		RGB(255, 137, 20)
#define		CR_YELLOW		RGB(255, 255, 0)
#define		CR_CYAN		RGB(0, 255, 255)
#define		CR_PINK		RGB(255, 0, 255)
#define		CR_BLUE		RGB(0, 0, 127)

//파란색 계열. 참조.
#define		CR_BOX_COLOR	RGB(200, 213, 255)
#define		CR_TEXT_COLOR	RGB(33, 61, 151)
#define		CR_INBOX_COLOR	RGB(240, 243, 255)




#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


