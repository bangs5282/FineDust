// SecondTab.cpp: 구현 파일
//

#include "stdafx.h"
#include "Fine Dust.h"
#include "SecondTab.h"
#include "afxdialogex.h"

#include "Fine DustDlg.h"


// CSecondTab 대화 상자

IMPLEMENT_DYNAMIC(CSecondTab, CDialogEx)

CSecondTab::CSecondTab(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TAB_SECOND, pParent)
{

}

CSecondTab::~CSecondTab()
{
}

void CSecondTab::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSecondTab, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_LU, &CSecondTab::OnBnClickedButtonLu)
	ON_BN_CLICKED(IDC_BUTTON_RU, &CSecondTab::OnBnClickedButtonRu)
	ON_BN_CLICKED(IDC_BUTTON_LD, &CSecondTab::OnBnClickedButtonLd)
	ON_BN_CLICKED(IDC_BUTTON_RD, &CSecondTab::OnBnClickedButtonRd)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CSecondTab 메시지 처리기


void CSecondTab::OnBnClickedButtonLu()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFineDustDlg *pDlg = (CFineDustDlg*)AfxGetMainWnd();
	pDlg->movewinLU();
}

void CSecondTab::OnBnClickedButtonRu()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFineDustDlg *pDlg = (CFineDustDlg*)AfxGetMainWnd();
	pDlg->movewinRU();
}

void CSecondTab::OnBnClickedButtonLd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFineDustDlg *pDlg = (CFineDustDlg*)AfxGetMainWnd();
	pDlg->movewinLD();
}

void CSecondTab::OnBnClickedButtonRd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFineDustDlg *pDlg = (CFineDustDlg*)AfxGetMainWnd();
	pDlg->movewinRD();
}


BOOL CSecondTab::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(a, b, c));

	return TRUE;
}
