
// Test_SliderCtrlExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test_SliderCtrlEx.h"
#include "Test_SliderCtrlExDlg.h"
#include "afxdialogex.h"

#include "../../Common/Functions.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTest_SliderCtrlExDlg dialog



CTest_SliderCtrlExDlg::CTest_SliderCtrlExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_SLIDERCTRLEX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_SliderCtrlExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_slider[0]);
	DDX_Control(pDX, IDC_SLIDER2, m_slider[1]);
	DDX_Control(pDX, IDC_SLIDER3, m_slider[2]);
	DDX_Control(pDX, IDC_SLIDER4, m_slider[3]);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress1);
	DDX_Control(pDX, IDC_CHECK_ENABLE, m_check_enable);
}

BEGIN_MESSAGE_MAP(CTest_SliderCtrlExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTest_SliderCtrlExDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTest_SliderCtrlExDlg::OnBnClickedCancel)
	ON_MESSAGE(MESSAGE_SLIDERCTRLEX, &CTest_SliderCtrlExDlg::OnMessageSliderCtrlEx)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmark)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK_CLEAR, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkClear)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK_PREV, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkPrev)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK_NEXT, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkNext)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK_ADD_RANDOM, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkAddRandom)
	ON_BN_CLICKED(IDC_CHECK_ENABLE, &CTest_SliderCtrlExDlg::OnBnClickedCheckEnable)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CTest_SliderCtrlExDlg message handlers

BOOL CTest_SliderCtrlExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	int i;
	int max = 100000;

	for (i = 0; i < 4; i++)
	{
		m_slider[i].SetRange(0, max);

		m_slider[i].SetStyle(i);
		m_slider[i].SetPos((m_slider[i].GetRangeMax() - m_slider[i].GetRangeMin()) / 2.0);
		m_slider[i].SetActiveColor(RGB(120, 215, 146));
	}

	m_slider[3].use_bookmark();
	m_slider[3].set_bookmark_color(deeppink);
	m_slider[3].set_bookmark_current_color(lightpink);
	for (i = 0; i < 1; i++)
		m_slider[3].bookmark(CSliderCtrlEx::bookmark_add, random19937(0, (int)max));
	m_slider[3].use_tooltip(true);
	m_slider[3].set_tooltip_format(CSliderCtrlEx::tooltip_time);

	m_progress1.SetIndeterminate();
	return TRUE;
	m_progress1.SetRange32(0, max);
	m_progress1.SetPos((m_progress1.GetRangeMax() - m_progress1.GetRangeMin()) / 2.0);
	m_progress1.SetGradient();
	m_progress1.SetColor(red, blue);
	m_progress1.set_text_color(black, white);
	m_progress1.show_text(true, CMacProgressCtrl::text_format_value);
	m_progress1.use_invert_text_color();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTest_SliderCtrlExDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTest_SliderCtrlExDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTest_SliderCtrlExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTest_SliderCtrlExDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CTest_SliderCtrlExDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

LRESULT CTest_SliderCtrlExDlg::OnMessageSliderCtrlEx(WPARAM wParam, LPARAM lParam)
{
	CSliderCtrlExMsg *msg = (CSliderCtrlExMsg*)wParam;
	for (int i = 0; i < 4; i++)
		m_slider[i].SetPos(msg->pos);
	m_progress1.SetPos(msg->pos);
	return 1;
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmark()
{
	m_slider[3].bookmark();
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkClear()
{
	m_slider[3].bookmark(CSliderCtrlEx::bookmark_reset);
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkPrev()
{
	m_slider[3].bookmark(CSliderCtrlEx::bookmark_move, false);
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkNext()
{
	m_slider[3].bookmark(CSliderCtrlEx::bookmark_move, true);
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkAddRandom()
{
	int min = m_slider[3].GetRangeMin();
	int max = m_slider[3].GetRangeMax();
	m_slider[3].bookmark(CSliderCtrlEx::bookmark_add, random19937(min, max));
}


void CTest_SliderCtrlExDlg::OnBnClickedCheckEnable()
{
	bool enable = m_check_enable.GetCheck();

	for (int i = 0; i < 4; i++)
	{
		m_slider[i].EnableWindow(enable);
	}
}


void CTest_SliderCtrlExDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL CTest_SliderCtrlExDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_OEM_4 :
			if (IsShiftPressed())
				m_slider[3].set_repeat_start(-1);
			else
				m_slider[3].set_repeat_start();
			return true;
		case VK_OEM_6 :
			if (IsShiftPressed())
				m_slider[3].set_repeat_end(-1);
			else
				m_slider[3].set_repeat_end();
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
