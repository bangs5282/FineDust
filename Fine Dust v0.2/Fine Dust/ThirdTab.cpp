// ThirdTab.cpp: 구현 파일
//

#include "stdafx.h"
#include "Fine Dust.h"
#include "ThirdTab.h"
#include "afxdialogex.h"

#include "Fine DustDlg.h"
#include "SETTING.h"

// CThirdTab 대화 상자

IMPLEMENT_DYNAMIC(CThirdTab, CDialogEx)

CThirdTab::CThirdTab(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TAB_THIRD, pParent)
	, m_nR(56)
	, m_nG(56)
	, m_nB(56)
{

}

CThirdTab::~CThirdTab()
{
}

void CThirdTab::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_R, m);
	DDX_Text(pDX, IDC_EDIT_R, m_nR);
	DDX_Text(pDX, IDC_EDIT_G, m_nG);
	DDX_Text(pDX, IDC_EDIT_B, m_nB);
}


BEGIN_MESSAGE_MAP(CThirdTab, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CThirdTab::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_black, &CThirdTab::OnBnClickedButtonblack)
	ON_BN_CLICKED(IDC_BUTTON_white, &CThirdTab::OnBnClickedButtonwhite)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CThirdTab 메시지 처리기


void CThirdTab::OnBnClickedButton1()
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
	::SendMessage(g_hWnd, WM_GETAPI, NULL, NULL);
}


void CThirdTab::OnBnClickedButtonblack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	realchange = 1;
	color = 0;
	::SendMessage(g_hWnd, WM_GETAPI, NULL, NULL);
}


void CThirdTab::OnBnClickedButtonwhite()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	realchange = 1;
	color = 1;
	::SendMessage(g_hWnd, WM_GETAPI, NULL, NULL);
}


BOOL CThirdTab::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(a, b, c));

	return TRUE;
}
