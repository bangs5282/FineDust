// SETTING.cpp: 구현 파일
//

#include "stdafx.h"
#include "Fine Dust.h"
#include "SETTING.h"
#include "afxdialogex.h"
#include "Fine DustDlg.h"
#include "ShellAPI.h"

// SETTING 대화 상자

IMPLEMENT_DYNAMIC(SETTING, CDialogEx)

SETTING::SETTING(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SETTING, pParent)
	, m_nR(56)
	, m_nB(56)
	, m_nG(56)
{
	m_pwndShow = NULL;
}

SETTING::~SETTING()
{
}

void SETTING::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_B, m_nR);
	//  DDX_Control(pDX, IDC_EDIT_B, m_nB);
	DDX_Text(pDX, IDC_EDIT_B, m_nB);
	DDX_Text(pDX, IDC_EDIT_G, m_nG);
	DDX_Text(pDX, IDC_EDIT_R, m_nR);
	//  DDX_Control(pDX, IDC_COMBO_site, m_ctrlSite);
	DDX_Control(pDX, IDC_TAB_setting, m_Tab);
}


BEGIN_MESSAGE_MAP(SETTING, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON_LU, &SETTING::OnBnClickedButtonLu)
	ON_BN_CLICKED(IDC_BUTTON_RU, &SETTING::OnBnClickedButtonRu)
	ON_BN_CLICKED(IDC_BUTTON_LD, &SETTING::OnBnClickedButtonLd)
	ON_BN_CLICKED(IDC_BUTTON_RD, &SETTING::OnBnClickedButtonRd)
	ON_WM_MOUSEMOVE()
//	ON_WM_NCLBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_MESSAGE(WM_TRAY_NOTIFYICACTION, OnTrayNotification)
//	ON_COMMAND(ID_QKDTNGUS_EXIT, &SETTING::OnQkdtngusExit)
//	ON_COMMAND(ID_QKDTNGUS_SHOW, &SETTING::OnQkdtngus32772)
//	ON_UPDATE_COMMAND_UI(ID_QKDTNGUS_EXIT, &SETTING::OnUpdateQkdtngusExit)
//	ON_UPDATE_COMMAND_UI(ID_QKDTNGUS_SHOW, &SETTING::OnUpdateQkdtngusShow)
ON_BN_CLICKED(IDC_BUTTON1, &SETTING::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON3, &SETTING::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON_black, &SETTING::OnBnClickedButtonblack)
ON_BN_CLICKED(IDC_BUTTON_white, &SETTING::OnBnClickedButtonwhite)
ON_NOTIFY(NM_CLICK, IDC_TAB_setting, &SETTING::OnNMClickTabsetting)
END_MESSAGE_MAP()


// SETTING 메시지 처리기


BOOL SETTING::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(a,b,c));

	return TRUE;
}


void SETTING::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;  // 픽쳐 컨트롤의 사각형 영역 조사
	((CStatic*)GetDlgItem(IDC_STATIC_X))->GetWindowRect(&rt);
	ScreenToClient(&rt);
	if (rt.PtInRect(point))
	{

		ShowWindow(SW_HIDE);

	}

	((CStatic*)GetDlgItem(IDC_STATIC_FRAME))->GetWindowRect(&rt);
	ScreenToClient(&rt);
	if (rt.PtInRect(point))
	{
		if (point.y > 29)
			return;
		SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}

	/*
	CRect rtt;
	((CStatic*)GetDlgItem(IDC_STATIC_FRAME))->GetWindowRect(&rtt);
	ScreenToClient(&rtt);
	if (rtt.PtInRect(point))
	{

		clicked = 1;

	}
	*/
	CDialogEx::OnLButtonDown(nFlags, point);
}

//284 44

void SETTING::OnBnClickedButtonLu()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFineDustDlg *pDlg = (CFineDustDlg*)AfxGetMainWnd();
	pDlg->movewinLU();
}


void SETTING::OnBnClickedButtonRu()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFineDustDlg *pDlg = (CFineDustDlg*)AfxGetMainWnd();
	pDlg->movewinRU();
}


void SETTING::OnBnClickedButtonLd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFineDustDlg *pDlg = (CFineDustDlg*)AfxGetMainWnd();
	pDlg->movewinLD();
}


void SETTING::OnBnClickedButtonRd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFineDustDlg *pDlg = (CFineDustDlg*)AfxGetMainWnd();
	pDlg->movewinRD();
}

// 322 250
BOOL SETTING::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	MoveWindow((width / 2) - 322, (height / 2) - 250, 322, 250);

	/*
	m_ctrlSite.AddString(_T("서울"));
	m_ctrlSite.AddString(_T("부산"));
	m_ctrlSite.AddString(_T("대구"));
	m_ctrlSite.AddString(_T("인천"));
	m_ctrlSite.AddString(_T("광주"));
	m_ctrlSite.AddString(_T("대전"));
	m_ctrlSite.AddString(_T("울산"));
	m_ctrlSite.AddString(_T("경기"));
	m_ctrlSite.AddString(_T("강원"));
	m_ctrlSite.AddString(_T("충북"));
	m_ctrlSite.AddString(_T("충남"));
	m_ctrlSite.AddString(_T("전북"));
	m_ctrlSite.AddString(_T("전남"));
	m_ctrlSite.AddString(_T("제주"));
	m_ctrlSite.AddString(_T("세종"));
	*/

	CString    strOne = _T("First");
	CString    strTwo = _T("Second");
	CString    strThree = _T("Third");
	m_Tab.InsertItem(1, strOne);
	m_Tab.InsertItem(2, strTwo);
	m_Tab.InsertItem(3, strThree);

	CRect Rect;
	m_Tab.GetClientRect(&Rect);
	m_Tab.SetCurSel(0);

	/*
	m_First.Create(IDD_DIALOG_TAB_FIRST, &m_Tab);
	m_First.SetWindowPos(NULL, 5, 25,
		Rect.Width() - 12, Rect.Height() - 33,
		SWP_SHOWWINDOW | SWP_NOZORDER);
	m_pwndShow = &m_First;
	*/

	CRect rect;
	m_Tab.GetWindowRect(&rect);

	m_First = new CFirstTab;
	m_First->Create(IDD_DIALOG_TAB_FIRST, &m_Tab);
	m_First->MoveWindow(0, 25, rect.Width(), rect.Height());
	m_First->ShowWindow(SW_SHOW);

	m_Second.Create(IDD_DIALOG_TAB_SECOND, &m_Tab);
	m_Second.SetWindowPos(NULL, 5, 25,
		Rect.Width() - 12, Rect.Height() - 33,
		SWP_NOZORDER);

	m_Third.Create(IDD_DIALOG_TAB_THIRD, &m_Tab);
	m_Third.SetWindowPos(NULL, 5, 25,
		Rect.Width() - 12, Rect.Height() - 33,
		SWP_NOZORDER);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
// 161 125

void SETTING::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*
	if (first_clicked == 1 && clicked == 1) {
		x = point.x;
		y = point.y;
		first_clicked = 0;
	}
	else if (clicked == 1) {
		CRect rect;
		GetWindowRect(rect);
		x2 = point.x;
		y2 = point.y;
		MoveWindow(rect.left + x2 - x, rect.top + y2 - y , rect.Width(), rect.Height());
	}
	*/
	CDialogEx::OnMouseMove(nFlags, point);
}


//void SETTING::OnNcLButtonUp(UINT nHitTest, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	
//	CDialogEx::OnNcLButtonUp(nHitTest, point);
//}


void SETTING::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*
	clicked = 0;
	first_clicked = 1;
	*/
	CDialogEx::OnLButtonUp(nFlags, point);
}


LRESULT SETTING::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	switch (lParam)
	{
	case WM_RBUTTONDOWN:
	{
		CPoint ptMouse;
		::GetCursorPos(&ptMouse);
		CMenu menu;
		menu.LoadMenu(IDR_TRAYMENU);
		CMenu *pMenu = menu.GetSubMenu(0); //활성화 할 메뉴 지정
		pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, ptMouse.x, ptMouse.y, AfxGetMainWnd());
	}
	break;

	case WM_LBUTTONDBLCLK:
	{
		NOTIFYICONDATA nid;
		ZeroMemory(&nid, sizeof(nid));
		nid.cbSize = sizeof(nid);
		nid.uID = 0;
		nid.hWnd = GetSafeHwnd();
		BOOL bRet = ::Shell_NotifyIcon(NIM_DELETE, &nid); //트레이아이콘 제거
		if (!bRet)
		{
			::AfxMessageBox(_T("트레이아이콘 제거실패"));
			return -1;
		}
		AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOW); //윈도우 활성화
		//KillTimer(TRAY_BALLOON);
	}
	break;
	}

	return 1;
}


//void SETTING::OnQkdtngusExit()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//	OnOK();
//}


//void SETTING::OnQkdtngus32772()
//{
//	// TODO: 여기에 명령 처리기 코드를 추가합니다.
//	AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOW);
//}


//void SETTING::OnUpdateQkdtngusExit(CCmdUI *pCmdUI)
//{
//	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
//	OnOK();
//}


//void SETTING::OnUpdateQkdtngusShow(CCmdUI *pCmdUI)
//{
//	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
//}


void SETTING::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	
	if (m_nR > 255) {
		m_nR = 255;
	}
	if (m_nB > 255) {
		m_nB = 255;
	}
	if (m_nG > 255) {
		m_nG = 255;
	}
	if (m_nR < 0) {
		m_nR = 0;
	}
	if (m_nB < 0) {
		m_nB = 0;
	}
	if (m_nG < 0) {
		m_nG = 0;
	}


	UpdateData(false);

	a = m_nR;
	b = m_nG;
	c = m_nB;

	SetBackgroundColor(RGB(a, b, c));
	((CFineDustDlg *)GetParent())->ChangeColor();
}


void SETTING::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	((CFineDustDlg *)GetParent())->SendRequestOpenAPI();
}


void SETTING::OnBnClickedButtonblack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	color = 0;
	((CFineDustDlg *)GetParent())->Invalidate(true);
}


void SETTING::OnBnClickedButtonwhite()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	color = 1;
	((CFineDustDlg *)GetParent())->Invalidate(true);
}


void SETTING::OnNMClickTabsetting(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_pwndShow != NULL)
	{
		m_pwndShow->ShowWindow(SW_HIDE);
		m_pwndShow = NULL;
	}

	int nIndex = m_Tab.GetCurSel();
	switch (nIndex)
	{
	case 0:
		m_First->ShowWindow(SW_SHOW);
		break;
	case 1:
		m_Second.ShowWindow(SW_SHOW);
		m_pwndShow = &m_Second;
		break;
	case 2:
		m_Third.ShowWindow(SW_SHOW);
		m_pwndShow = &m_Third;
		break;
	}

	*pResult = 0;
}
