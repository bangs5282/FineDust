
// Fine DustDlg.h: 헤더 파일
//

#pragma once
#include "SETTING.h"
#include "LOAD.h"
#include <afxinet.h>
#include "CColorText.h"

// CFineDustDlg 대화 상자
class CFineDustDlg : public CDialogEx
{
// 생성입니다.
public:
	CFineDustDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINEDUST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CStatic m_pic_X;
	afx_msg void OnStnClickedStaticX();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	SETTING *pSetting;
	CLOAD *pLoad;
	void movewinLU();
	void movewinLD();
	void movewinRU();
	void movewinRD();
	afx_msg void OnQkdtngusExit();
	afx_msg void OnQkdtngusShow();
	afx_msg void ChangeColor();
	//int ChangeColor();
	afx_msg char* UTF8toANSI(char* pszCode);
	afx_msg int SendRequestOpenAPI();
//	CString m_str_Finedust;
	CString m_str_Finedust;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CColorText m_ctr_Finedust;
	CFont cFont;
	CFont cFont2;
	CString m_str_good;
	CColorText m_ctr_good;
	CString m_str_site;
	CColorText m_ctr_site;
	CString m_strTest;
};
