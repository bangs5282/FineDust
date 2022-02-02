#pragma once


// CThirdTab 대화 상자

class CThirdTab : public CDialogEx
{
	DECLARE_DYNAMIC(CThirdTab)

public:
	CThirdTab(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CThirdTab();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB_THIRD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
