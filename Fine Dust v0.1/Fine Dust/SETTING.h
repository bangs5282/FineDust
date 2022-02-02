#pragma once

#include "FirstTab.h"
#include "SecondTab.h"
#include "ThirdTab.h"


// SETTING 대화 상자

class SETTING : public CDialogEx
{
	DECLARE_DYNAMIC(SETTING)

public:
	SETTING(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SETTING();

// 대화 상자 데이터입니다.
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETTING };
	CFirstTab        *m_First;
	CSecondTab        m_Second;
	CThirdTab        m_Third;
	CWnd*        m_pwndShow;

//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtonLu();
	afx_msg void OnBnClickedButtonRu();
	afx_msg void OnBnClickedButtonLd();
	afx_msg void OnBnClickedButtonRd();
//	virtual BOOL OnInitDialog();
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int clicked = 0;
//	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int first_clicked = 1;
	int x, y;
	int x2, y2;
	afx_msg void OnBnClickedButtonmin();
	LRESULT OnTrayNotification(WPARAM wParam, LPARAM lParam);

//	afx_msg void OnQkdtngusExit();
//	afx_msg void OnQkdtngus32772();
//	afx_msg void OnUpdateQkdtngusExit(CCmdUI *pCmdUI);
//	afx_msg void OnUpdateQkdtngusShow(CCmdUI *pCmdUI);
//	int m_nR;
//	CEdit m_nB;
	int m_nB;
	int m_nG;
	int m_nR;
	afx_msg void OnBnClickedButton1();
//	CComboBox m_ctrlSite;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButtonblack();
	afx_msg void OnBnClickedButtonwhite();
	CTabCtrl m_Tab;
	afx_msg void OnNMClickTabsetting(NMHDR *pNMHDR, LRESULT *pResult);
};
