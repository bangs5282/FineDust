// FirstTab.cpp: 구현 파일
//

#include "stdafx.h"
#include "Fine Dust.h"
#include "FirstTab.h"
#include "afxdialogex.h"
#include "Fine DustDlg.h"

// CFirstTab 대화 상자

IMPLEMENT_DYNAMIC(CFirstTab, CDialogEx)

CFirstTab::CFirstTab(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TAB_FIRST, pParent)
	, m_strText(_T("chicken is yummy"))
{

}

CFirstTab::~CFirstTab()
{
}

void CFirstTab::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_site, m_ctrlSite);
	//DDX_Text(pDX, IDC_STATIC_TEXT, m_strText);
	
}


BEGIN_MESSAGE_MAP(CFirstTab, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CFirstTab::OnBnClickedButton3)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CFirstTab 메시지 처리기


void CFirstTab::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	test = m_ctrlSite.GetCurSel();
	::SendMessage(g_hWnd, WM_GETAPI, NULL, NULL);
}


BOOL CFirstTab::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
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
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CFirstTab::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(a, b, c));

	return TRUE;
}
