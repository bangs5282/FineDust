// LOAD.cpp: 구현 파일
//

#include "Fine Dust.h"
#include "stdafx.h"
#include "Fine Dust.h"
#include "LOAD.h"
#include "afxdialogex.h"


// CLOAD 대화 상자

IMPLEMENT_DYNAMIC(CLOAD, CDialogEx)

CLOAD::CLOAD(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_LOAD, pParent)
{

}

CLOAD::~CLOAD()
{
}

void CLOAD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS_LOAD, m_prg_load);
}


BEGIN_MESSAGE_MAP(CLOAD, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS_LOAD, &CLOAD::OnNMCustomdrawProgressLoad)
END_MESSAGE_MAP()


// CLOAD 메시지 처리기


BOOL CLOAD::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(a,b,c));

	return TRUE;
}


BOOL CLOAD::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	/*
	CProgressCtrl m_progressCtrl;

	m_progressCtrl.SetBarColor(RGB(50, 0, 255));
	*/
	m_prg_load.SetState(PBST_PAUSED);
	nCurProgress = 0;
	m_prg_load.SetRange(0, 1000);	//범위
	m_prg_load.SetPos(nCurProgress);

	SetTimer(START_LOAD, 1, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CLOAD::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == START_LOAD) {

		if (m_prg_load.GetPos() >= 1000) {

			KillTimer(START_LOAD);
			ShowWindow(SW_HIDE);
			return;
		}

		nCurProgress += 10;

		m_prg_load.SetPos(nCurProgress);
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CLOAD::OnNMCustomdrawProgressLoad(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}
