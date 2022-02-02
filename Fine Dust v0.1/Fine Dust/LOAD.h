#pragma once


// CLOAD 대화 상자

class CLOAD : public CDialogEx
{
	DECLARE_DYNAMIC(CLOAD)

public:
	CLOAD(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CLOAD();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CProgressCtrl m_prg_load;
	int nCurProgress;
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNMCustomdrawProgressLoad(NMHDR *pNMHDR, LRESULT *pResult);
};
