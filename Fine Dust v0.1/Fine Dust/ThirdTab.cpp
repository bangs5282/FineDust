// ThirdTab.cpp: 구현 파일
//

#include "stdafx.h"
#include "Fine Dust.h"
#include "ThirdTab.h"
#include "afxdialogex.h"


// CThirdTab 대화 상자

IMPLEMENT_DYNAMIC(CThirdTab, CDialogEx)

CThirdTab::CThirdTab(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TAB_THIRD, pParent)
{

}

CThirdTab::~CThirdTab()
{
}

void CThirdTab::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CThirdTab, CDialogEx)
END_MESSAGE_MAP()


// CThirdTab 메시지 처리기
