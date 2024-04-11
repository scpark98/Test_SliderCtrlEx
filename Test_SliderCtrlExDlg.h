
// Test_SliderCtrlExDlg.h : header file
//

#pragma once
#include "afxcmn.h"

#include "../../Common/CSliderCtrl/SCSliderCtrl/SCSliderCtrl.h"
#include "../../Common/CProgressCtrl/MacProgressCtrl/MacProgressCtrl.h"
#include "afxwin.h"

// CTest_SliderCtrlExDlg dialog
class CTest_SliderCtrlExDlg : public CDialogEx
{
// Construction
public:
	CTest_SliderCtrlExDlg(CWnd* pParent = NULL);	// standard constructor

	LRESULT		OnMessageSliderCtrlEx(WPARAM wParam, LPARAM lParam);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_SLIDERCTRLEX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CSCSliderCtrl m_slider[4];
	CMacProgressCtrl m_progress1;
	afx_msg void OnBnClickedButtonBookmark();
	afx_msg void OnBnClickedButtonBookmarkClear();
	afx_msg void OnBnClickedButtonBookmarkPrev();
	afx_msg void OnBnClickedButtonBookmarkNext();
	afx_msg void OnBnClickedButtonBookmarkAddRandom();
	CButton m_check_enable;
	afx_msg void OnBnClickedCheckEnable();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CSCSliderCtrl m_slider_step;
	CSCSliderCtrl m_slider_stepv;
	CMacProgressCtrl m_progress_marquee;
};
