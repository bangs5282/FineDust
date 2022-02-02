#pragma once


// CFirstTab 대화 상자

class CFirstTab : public CDialogEx
{
	DECLARE_DYNAMIC(CFirstTab)

public:
	CFirstTab(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CFirstTab();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TAB_FIRST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	virtual BOOL OnInitDialog();
	CComboBox m_ctrlSite;
	CString m_strText;
};
