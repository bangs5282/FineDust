// SecondTab.cpp: 구현 파일
//

#include "stdafx.h"
#include "Fine Dust.h"
#include "SecondTab.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// CSecondTab 메시지 처리기
