#pragma once


// CSecondTab 대화 상자

class CSecondTab : public CDialogEx
{
	DECLARE_DYNAMIC(CSecondTab)

public:
	CSecondTab(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSecondTab();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB_SECOND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonLu();
	afx_msg void OnBnClickedButtonRu();
	afx_msg void OnBnClickedButtonLd();
	afx_msg void OnBnClickedButtonRd();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
