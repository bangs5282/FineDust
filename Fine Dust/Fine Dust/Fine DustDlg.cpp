
// Fine DustDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "Fine Dust.h"
#include "Fine DustDlg.h"
#include "afxdialogex.h"
#include "LOAD.h"

#include <iostream>
#include <string>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	//	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFineDustDlg 대화 상자



CFineDustDlg::CFineDustDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINEDUST_DIALOG, pParent)
	, m_str_Finedust(_T("농도"))
	, m_str_good(_T("상태"))
	, m_str_site(_T("지역"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFineDustDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_X, m_pic_X);
	//  DDX_Text(pDX, IDC_STATIC_Finedust, m_str_Finedust);
	DDX_Text(pDX, IDC_STATIC_dust, m_str_Finedust);
	DDX_Control(pDX, IDC_STATIC_dust, m_ctr_Finedust);
	DDX_Text(pDX, IDC_STATIC_good, m_str_good);
	DDX_Control(pDX, IDC_STATIC_good, m_ctr_good);
	DDX_Text(pDX, IDC_STATIC_site, m_str_site);
	DDX_Control(pDX, IDC_STATIC_site, m_ctr_site);
}

BEGIN_MESSAGE_MAP(CFineDustDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_QKDTNGUS_EXIT, &CFineDustDlg::OnQkdtngusExit)
	ON_COMMAND(ID_QKDTNGUS_SHOW, &CFineDustDlg::OnQkdtngusShow)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CFineDustDlg 메시지 처리기

BOOL CFineDustDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	pSetting = new SETTING;
	pSetting->Create(IDD_DIALOG_SETTING);
	pSetting->ShowWindow(SW_HIDE);

	pLoad = new CLOAD;
	pLoad->Create(IDD_DIALOG_LOAD);
	pLoad->ShowWindow(SW_SHOW);

	SendRequestOpenAPI();

	cFont.CreateFont(30,                     // 글자높이
		12,                     // 글자너비
		0,                      // 출력각도
		0,                      // 기준 선에서의각도
		FW_HEAVY,              // 글자굵기
		FALSE,                  // Italic 적용여부
		FALSE,                  // 밑줄적용여부
		FALSE,                  // 취소선적용여부
		DEFAULT_CHARSET,       // 문자셋종류
		OUT_DEFAULT_PRECIS,    // 출력정밀도
		CLIP_DEFAULT_PRECIS,   // 클리핑정밀도
		DEFAULT_QUALITY,       // 출력문자품질
		DEFAULT_PITCH,         // 글꼴Pitch
		_T("Microsoft YaHei UI")           // 글꼴
	);
	m_ctr_Finedust.SetFont(&cFont);
	m_ctr_Finedust.SetTextColor(CR_WHITE);

	cFont2.CreateFont(30,                     // 글자높이
		12,                     // 글자너비
		0,                      // 출력각도
		0,                      // 기준 선에서의각도
		FW_HEAVY,              // 글자굵기
		FALSE,                  // Italic 적용여부
		FALSE,                  // 밑줄적용여부
		FALSE,                  // 취소선적용여부
		DEFAULT_CHARSET,       // 문자셋종류
		OUT_DEFAULT_PRECIS,    // 출력정밀도
		CLIP_DEFAULT_PRECIS,   // 클리핑정밀도
		DEFAULT_QUALITY,       // 출력문자품질
		DEFAULT_PITCH,         // 글꼴Pitch
		_T("굴림체")           // 글꼴
	);

	m_ctr_good.SetFont(&cFont);
	m_ctr_good.SetTextColor(CR_WHITE);
	m_ctr_site.SetFont(&cFont);
	m_ctr_site.SetTextColor(CR_WHITE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFineDustDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFineDustDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//HWND hWnd = pWnd->m_hWnd;
		//CWnd* pWnd = CWnd::FromHandle(HWND);
		/*
		if (GetDlgCtrlID() == CTLCOLOR_STATIC)
		{
			if (color == 0) {
				dc.SetTextColor(RGB(0, 0, 0));
			}
			if (color == 1) {
				dc.SetTextColor(RGB(255, 255, 255));
			}
			dc.SetBkMode(TRANSPARENT);
		}
		*/
	}
	CDialogEx::OnPaint();
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFineDustDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CFineDustDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(a, b, c));

	return TRUE;
}





void CFineDustDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;  // 픽쳐 컨트롤의 사각형 영역 조사

	((CStatic*)GetDlgItem(IDC_STATIC_X))->GetWindowRect(&rt);
	ScreenToClient(&rt);
	if (rt.PtInRect(point))
	{
		//PostQuitMessage(WM_QUIT);
		OnOK();
	}


	((CStatic*)GetDlgItem(IDC_STATIC_SET))->GetWindowRect(&rt);
	ScreenToClient(&rt);
	if (rt.PtInRect(point))

	{
		pSetting->ShowWindow(SW_SHOW);
	}

	((CStatic*)GetDlgItem(IDC_STATIC_left))->GetWindowRect(&rt);
	ScreenToClient(&rt);
	if (rt.PtInRect(point))
	{
		if (checksom == 1) {
			checksom = 0;
			CStatic *m_pPicture1 = (CStatic *)GetDlgItem(IDC_STATIC_left);
			CBitmap new_image;
			new_image.LoadBitmap(IDB_BITMAP5);
			HBITMAP h_old_bitmap = m_pPicture1->SetBitmap(new_image);
			if (h_old_bitmap != NULL) ::DeleteObject(h_old_bitmap);
			new_image.Detach();

			CRect window;
			GetWindowRect(window);
			MoveWindow(window.left, window.top, 196, 44);
		}
		else if (checksom == 0) {
			checksom = 1;
			CStatic *m_pPicture1 = (CStatic *)GetDlgItem(IDC_STATIC_left);
			CBitmap new_image;
			new_image.LoadBitmap(IDB_BITMAP4);
			HBITMAP h_old_bitmap = m_pPicture1->SetBitmap(new_image);
			if (h_old_bitmap != NULL) ::DeleteObject(h_old_bitmap);
			new_image.Detach();

			CRect window;
			GetWindowRect(window);
			MoveWindow(window.left, window.top, 284, 44);
		}
	}

	// y 좌표가 특정 수치 이하 일 경우, 다이얼로그 이동 가능

	if (point.y > 29)
		return;
	SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CFineDustDlg::movewinLU()
{
	if (checksom == 1) {
		MoveWindow(0, 0, 284, 44);
	}
	else if (checksom == 0) {
		MoveWindow(0, 0, 196, 44);
	}
}
void CFineDustDlg::movewinLD()
{
	if (checksom == 1) {
		int height = GetSystemMetrics(SM_CYSCREEN);
		MoveWindow(0, height - 44, 284, 44);
	}
	else if (checksom == 0) {
		int height = GetSystemMetrics(SM_CYSCREEN);
		MoveWindow(0, height - 44, 196, 44);
	}
}
void CFineDustDlg::movewinRU()
{
	if (checksom == 1) {
		int width = GetSystemMetrics(SM_CXSCREEN);
		MoveWindow(width - 284, 0, 284, 44);
	}
	else if (checksom == 0) {
		int width = GetSystemMetrics(SM_CXSCREEN);
		MoveWindow(width - 196, 0, 196, 44);
	}
}
void CFineDustDlg::movewinRD()
{
	if (checksom == 1) {
		int width = GetSystemMetrics(SM_CXSCREEN);
		int height = GetSystemMetrics(SM_CYSCREEN);
		MoveWindow(width - 284, height - 44, 284, 44);
	}
	else if (checksom == 0) {
		int width = GetSystemMetrics(SM_CXSCREEN);
		int height = GetSystemMetrics(SM_CYSCREEN);
		MoveWindow(width - 196, height - 44, 196, 44);
	}
}


//BOOL CAboutDlg::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//	// TODO:  여기에 추가 초기화 작업을 추가합니다.
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
//}


void CFineDustDlg::OnQkdtngusExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}


void CFineDustDlg::OnQkdtngusShow()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다
	ShowWindow(SW_SHOW);
	NOTIFYICONDATA nid;
	ZeroMemory(&nid, sizeof(nid));
	nid.cbSize = sizeof(nid);
	nid.uID = 0;
	nid.hWnd = GetSafeHwnd();
	BOOL bRet = ::Shell_NotifyIcon(NIM_DELETE, &nid);
	if (!bRet)
	{
		::AfxMessageBox(_T("트레이아이콘 제거실패"));
		//return -1;
	}
}

void CFineDustDlg::ChangeColor()
{
	// TODO: 여기에 구현 코드 추가.
	SetBackgroundColor(RGB(a, b, c));
}
//multibyte
int CFineDustDlg::SendRequestOpenAPI()
{
	// TODO: 여기에 구현 코드 추가.
	CInternetFile* pFile = NULL;
	CInternetSession InetSession;

	try {
		pFile = (CInternetFile*)InetSession.OpenURL(
			//1.시군구별 실시간 평균정보 조회 X
			//_T("http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getCtprvnMesureSidoLIst?sidoName=경기&searchCondition=DAILY&pageNo=1&numOfRows=10&ServiceKey=3HMfkml15%2BiTgx4nIGPXPox6cyCGxZ2bYyA53Xw2HEDm2FU3Gp0b7X4hP7ewRueTgYqKKHr6o0aKibqrwj8YEA%3D%3D"));
			//2.시도별 실시간 평균정보 조회 
			_T("http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getCtprvnMesureLIst?itemCode=PM10&dataGubun=DAILY&searchCondition=MONTH&pageNo=1&numOfRows=10&ServiceKey=3HMfkml15%2BiTgx4nIGPXPox6cyCGxZ2bYyA53Xw2HEDm2FU3Gp0b7X4hP7ewRueTgYqKKHr6o0aKibqrwj8YEA%3D%3D"));
		//3.대기질 예보통보 조회
		//_T("http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getMinuDustFrcstDspth?&searchDate=2020-01-16&ServiceKey=3HMfkml15%2BiTgx4nIGPXPox6cyCGxZ2bYyA53Xw2HEDm2FU3Gp0b7X4hP7ewRueTgYqKKHr6o0aKibqrwj8YEA%3D%3D"));
		//4.시도별 실시간 측정정보 조회  X
		//_T("http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getCtprvnRltmMesureDnsty?sidoName=경기&pageNo=1&numOfRows=10&ServiceKey=3HMfkml15%2BiTgx4nIGPXPox6cyCGxZ2bYyA53Xw2HEDm2FU3Gp0b7X4hP7ewRueTgYqKKHr6o0aKibqrwj8YEA%3D%3D&ver=1.3"));
	//5.측정소별 실시간 측정정보 조회 X
	/*_T("http://openapi.airkorea.or.kr/openapi/services/rest/ArpltnInforInqireSvc/getMsrstnAcctoRltmMesureDnsty?stationName=천천동&dataTerm=DAILY&pageNo=1&numOfRows=10&ServiceKey=3HMfkml15%2BiTgx4nIGPXPox6cyCGxZ2bYyA53Xw2HEDm2FU3Gp0b7X4hP7ewRueTgYqKKHr6o0aKibqrwj8YEA%3D%3D"));*/
	}//numOfRows=10&pageNo=1&InformCode=PM10
	catch (CInternetException * pEx) {
		pFile = NULL;
		pEx = NULL;
		AfxMessageBox(_T("OpenURL Exception Error!"));
	}

	CString strData;	strData.Empty();
	//	m_strText.Empty();

	if (pFile) {
		CString strTemp;	strTemp.Empty();

		pFile->SetReadBufferSize(8192);

		while (true) {
			if (pFile->ReadString(strTemp)) {
				strTemp = UTF8toANSI((LPSTR)(LPCTSTR)strTemp);
				strData += strTemp;
				strData += "\r\n";
			}
			else
				break;
		}
	}
	else
		AfxMessageBox(_T("OpenURL pFile is NULL!!"));

	int temp = strData.Find(_T("<seoul>"));
	strData.Delete(1, temp);

	int test = pSetting->m_ctrlSite.GetCurSel();
	if (test != -1) {
		//서울
		//m_str_Finedust = strData.Mid(7, 2);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 0) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////부산
		//m_str_Finedust = strData.Mid(32, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 1) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////대구
		//m_str_Finedust = strData.Mid(56, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 2) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////인천
		//m_str_Finedust = strData.Mid(82, 2);	
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 3) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////광주
		//m_str_Finedust = strData.Mid(110, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 4) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////대전
		//m_str_Finedust = strData.Mid(138, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 5) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////울산
		//m_str_Finedust = strData.Mid(164, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 6) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////경기
		//m_str_Finedust = strData.Mid(191, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 7) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////강원
		//m_str_Finedust = strData.Mid(220, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 8) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////충북
		//m_str_Finedust = strData.Mid(7, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 9) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////충남
		//m_str_Finedust = strData.Mid(7, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 10) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////전북
		//m_str_Finedust = strData.Mid(7, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if(test == 11) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////전남
		//m_str_Finedust = strData.Mid(7, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 12) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);

		////제주
		//m_str_Finedust = strData.Mid(7, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 13) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);
		////세종
		//m_str_Finedust = strData.Mid(7, 2);
		temp = strData.Find(_T("<"));
		strData.Delete(0, temp);
		temp = strData.Find(_T(">"));
		strData.Delete(0, temp);
		temp = strData.Find(_T("<"));
		if (test == 14) {
			CRect rect;
			GetDlgItem(IDC_STATIC_dust)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_Finedust = strData.Mid(1, temp - 1);
		}
		strData.Delete(0, temp + 1);

		finedustint = _ttoi(m_str_Finedust);
		if (finedustint >= 0 && finedustint <= 30)
		{
			CRect rect;
			GetDlgItem(IDC_STATIC_good)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_good = _T("좋음");
		}
		else if (finedustint >= 31 && finedustint <= 80)
		{
			CRect rect;
			GetDlgItem(IDC_STATIC_good)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_good = _T("보통");
		}
		else if (finedustint >= 81 && finedustint <= 150)
		{
			CRect rect;
			GetDlgItem(IDC_STATIC_good)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_good = _T("나쁨");
		}
		else if (finedustint >= 151)
		{
			CRect rect;
			GetDlgItem(IDC_STATIC_good)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_good = _T("매우나쁨");
		}

		if (test == 0) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("서울");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("서울"));
		}
		else if (test == 1) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("부산");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("부산"));
		}
		else if (test == 2) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("대구");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("대구"));
		}
		else if (test == 3) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("인천");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("인천"));
		}
		else if (test == 4) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("광주");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("광주"));
		}
		else if (test == 5) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("대전");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("대전"));
		}
		else if (test == 6) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("울산");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("울산"));
		}
		else if (test == 7) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("경기");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("경기"));
		}
		else if (test == 8) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("강원");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("강원"));
		}
		else if (test == 9) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("충북");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("충북"));
		}
		else if (test == 10) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("충남");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("충남"));
		}
		else if (test == 11) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("전북");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("전북"));
		}
		else if (test == 12) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("전남");
			//GetDlgItem(IDC_STATIC_site)->SetWindowTextW(_T("전남"));
		}
		else if (test == 13) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("제주");
			//GetDlgItem(IDC_STATIC_good)->SetWindowTextW(_T("제주"));
		}
		else if (test == 14) {
			CRect rect;
			GetDlgItem(IDC_STATIC_site)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(rect);
			m_str_site = _T("세종");
			//GetDlgItem(IDC_STATIC_good)->SetWindowTextW(_T("세종"));
		}
	}
	UpdateData(false);
	return 0;
}


char* CFineDustDlg::UTF8toANSI(char* pszCode)
{
	// TODO: 여기에 구현 코드 추가.
	BSTR    bstrWide;
	char* pszAnsi;
	int     nLength;

	// Get nLength of the Wide Char buffer   
	nLength = MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, NULL, NULL);
	bstrWide = SysAllocStringLen(NULL, nLength);

	// Change UTF-8 to Unicode (UTF-16)   
	MultiByteToWideChar(CP_UTF8, 0, pszCode, strlen(pszCode) + 1, bstrWide, nLength);


	// Get nLength of the multi byte buffer    
	nLength = WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, NULL, 0, NULL, NULL);
	pszAnsi = new char[nLength];


	// Change from unicode to mult byte   
	WideCharToMultiByte(CP_ACP, 0, bstrWide, -1, pszAnsi, nLength, NULL, NULL);

	SysFreeString(bstrWide);

	return pszAnsi;
}

HBRUSH CFineDustDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.

	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		if (color == 0) {
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (color == 1) {
			pDC->SetTextColor(RGB(255, 255, 255));
		}
		pDC->SetBkMode(TRANSPARENT);
		hbr = (HBRUSH)GetStockObject(NULL_BRUSH);;
	}

	return hbr;
}
