
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
	DDX_Control(pDX, IDC_SLIDER_NORMAL, m_slider_normal);
	DDX_Control(pDX, IDC_SLIDER_THUMB, m_slider_thumb);
	DDX_Control(pDX, IDC_SLIDER_THUMB_ROUND, m_slider_thumb_round);
	DDX_Control(pDX, IDC_SLIDER_VALUE, m_slider_value);
	DDX_Control(pDX, IDC_SLIDER_BOOKMARK, m_slider_bookmark);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress1);
	DDX_Control(pDX, IDC_CHECK_ENABLE, m_check_enable);
	DDX_Control(pDX, IDC_SLIDER_STEP, m_slider_step);
	DDX_Control(pDX, IDC_SLIDER_STEPV, m_slider_stepv);
	DDX_Control(pDX, IDC_PROGRESS_MARQUEE, m_progress_marquee);
	DDX_Control(pDX, IDC_SLIDER_PROGRESS, m_slider_progress);
	DDX_Control(pDX, IDC_SLIDER_PROGRESS_LINE, m_slider_progress_line);
}

BEGIN_MESSAGE_MAP(CTest_SliderCtrlExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTest_SliderCtrlExDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTest_SliderCtrlExDlg::OnBnClickedCancel)
	ON_MESSAGE(Message_CSCSliderCtrl, &CTest_SliderCtrlExDlg::OnMessageSliderCtrlEx)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmark)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK_CLEAR, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkClear)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK_PREV, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkPrev)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK_NEXT, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkNext)
	ON_BN_CLICKED(IDC_BUTTON_BOOKMARK_ADD_RANDOM, &CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkAddRandom)
	ON_BN_CLICKED(IDC_CHECK_ENABLE, &CTest_SliderCtrlExDlg::OnBnClickedCheckEnable)
	ON_WM_HSCROLL()
	ON_WM_WINDOWPOSCHANGED()
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
	int max = 100;

	m_slider_normal.set_style(CSCSliderCtrl::style_normal);
	m_slider_normal.SetRange(0, max);
	m_slider_normal.SetPos(max / 2);
	//m_slider_normal.set_active_color(RGB(120, 215, 146));

	m_slider_thumb.set_style(CSCSliderCtrl::style_thumb);
	m_slider_thumb.SetRange(0, max);
	m_slider_thumb.SetPos(max / 2);
	//m_slider_thumb.set_active_color(RGB(120, 215, 146));

	m_slider_thumb_round.set_style(CSCSliderCtrl::style_thumb_round);
	m_slider_thumb_round.SetRange(0, max);
	m_slider_thumb_round.SetPos(max / 2);
	//m_slider_thumb_round.set_active_color(RGB(120, 215, 146));

	m_slider_value.set_style(CSCSliderCtrl::style_value);
	m_slider_value.SetRange(0, max);
	m_slider_value.SetPos(max / 2);
	//m_slider_value.set_active_color(RGB(120, 215, 146));

	m_slider_progress.set_style(CSCSliderCtrl::style_progress);
	m_slider_progress.SetRange(0, max);
	m_slider_progress.SetPos(max / 2);
	//m_slider_progress.set_active_color(RGB(120, 215, 146));

	m_slider_progress_line.set_style(CSCSliderCtrl::style_progress_line);
	m_slider_progress_line.SetRange(0, max);
	m_slider_progress_line.SetPos(max / 2);
	//m_slider_progress_line.set_active_color(RGB(120, 215, 146));

	m_slider_bookmark.use_bookmark();
	m_slider_bookmark.set_bookmark_color(deeppink);
	m_slider_bookmark.set_bookmark_current_color(lightpink);
	for (i = 0; i < 1; i++)
		m_slider_bookmark.bookmark(CSCSliderCtrl::bookmark_add, random19937(0, (int)max));
	m_slider_bookmark.use_tooltip(true);
	m_slider_bookmark.set_tooltip_format(CSCSliderCtrl::tooltip_time);

	//m_progress1.SetIndeterminate();
	//return TRUE;

	m_progress1.SetRange32(0, max);
	m_progress1.SetPos((m_progress1.get_upper() - m_progress1.get_lower()) / 2.0);
	m_progress1.set_text_color(black, white);
	m_progress1.show_text(true, CMacProgressCtrl::text_format_value);
	m_progress1.use_invert_text_color();
	m_progress1.set_style(CMacProgressCtrl::style_round_line);
	m_progress1.use_slider();

	//m_progress_marquee.SetMarquee(TRUE, 10);
	//m_progress_marquee.SetIndeterminate();

	m_slider_step.set_style(CSCSliderCtrl::style_step);
	m_slider_step.SetRange(0, 3);
	m_slider_step.set_step_image(-1, IDB_CHECKING_GRAY);

	m_slider_stepv.set_style(CSCSliderCtrl::style_step);
	m_slider_stepv.SetRange(0, 3);
	m_slider_stepv.set_step_image(-1, IDB_CHECKING_GRAY);


	RestoreWindowPosition(&theApp, this);

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
	m_slider_step.set_step_image(1, IDB_CHECK_OK);
	m_slider_step.set_step_image(2, IDB_CHECK_FAIL);
	m_slider_stepv.set_step_image(1, IDB_CHECK_OK);
	m_slider_stepv.set_step_image(2, IDB_CHECK_FAIL);
}


void CTest_SliderCtrlExDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

LRESULT CTest_SliderCtrlExDlg::OnMessageSliderCtrlEx(WPARAM wParam, LPARAM lParam)
{
	CSCSliderCtrlMsg *msg = (CSCSliderCtrlMsg*)wParam;
	m_slider_normal.SetPos(msg->pos);
	m_slider_thumb.SetPos(msg->pos);
	m_slider_thumb_round.SetPos(msg->pos);
	m_slider_value.SetPos(msg->pos);
	m_progress1.SetPos(msg->pos);
	return 1;
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmark()
{
	m_slider_bookmark.bookmark();
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkClear()
{
	m_slider_bookmark.bookmark(CSCSliderCtrl::bookmark_reset);
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkPrev()
{
	m_slider_bookmark.bookmark(CSCSliderCtrl::bookmark_move, false);
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkNext()
{
	m_slider_bookmark.bookmark(CSCSliderCtrl::bookmark_move, true);
}


void CTest_SliderCtrlExDlg::OnBnClickedButtonBookmarkAddRandom()
{
	int min = m_slider_bookmark.GetRangeMin();
	int max = m_slider_bookmark.GetRangeMax();
	m_slider_bookmark.bookmark(CSCSliderCtrl::bookmark_add, random19937(min, max));
}


void CTest_SliderCtrlExDlg::OnBnClickedCheckEnable()
{
	bool enable = m_check_enable.GetCheck();

	m_slider_normal.EnableWindow(enable);
	m_slider_thumb.EnableWindow(enable);
	m_slider_thumb_round.EnableWindow(enable);
	m_slider_value.EnableWindow(enable);
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
				m_slider_bookmark.set_repeat_start(-1);
			else
				m_slider_bookmark.set_repeat_start();
			return true;
		case VK_OEM_6 :
			if (IsShiftPressed())
				m_slider_bookmark.set_repeat_end(-1);
			else
				m_slider_bookmark.set_repeat_end();
			return true;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CTest_SliderCtrlExDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	SaveWindowPosition(&theApp, this);
}
