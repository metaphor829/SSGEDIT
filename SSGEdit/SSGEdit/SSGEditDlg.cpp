
// SSGEditDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SSGEdit.h"
#include "SSGEditDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CSSGEditDlg 对话框



CSSGEditDlg::CSSGEditDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SSGEDIT_DIALOG, pParent)
	, m_filename(_T(" "))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSSGEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_CTRL, r_tab1);
	DDX_Text(pDX, IDC_EDIT1, m_filename);
}

BEGIN_MESSAGE_MAP(CSSGEditDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CTRL, &CSSGEditDlg::OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSSGEditDlg::OnBnClickedButton1)

	
	ON_BN_CLICKED(IDC_BUTTON2, &CSSGEditDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSSGEditDlg 消息处理程序

BOOL CSSGEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//tab控件初始化
	CRect tabRect;
	r_tab1.GetClientRect(&tabRect);
	tabRect.DeflateRect(2, 30, 5, 5);//tabrect范围
	r_tab1.InsertItem(0, L"项目总信息");
	r_tab1.InsertItem(1, L"梁构件");
	r_tab1.InsertItem(2, L"柱构件");
	r_tab1.InsertItem(3, L"墙构件");
	r_tab1.InsertItem(4, L"板构件");
	r_tab1.InsertItem(5, L"节点信息");
	cTabDlg1 = new CTabDlg1();
	cTabDlg2 = new CTabDlg2();
	cTabDlg3 = new CTabDlg3();
	cTabDlg4 = new CTabDlg4();
	cTabDlg5 = new CTabDlg5();
	cTabDlg6 = new CTabDlg6();
	cTabDlg1->Create(IDD_TAB_DIALOG1, &r_tab1);
	cTabDlg2->Create(IDD_TAB_DIALOG2, &r_tab1);
	cTabDlg3->Create(IDD_TAB_DIALOG3, &r_tab1);
	cTabDlg4->Create(IDD_TAB_DIALOG4, &r_tab1);
	cTabDlg5->Create(IDD_TAB_DIALOG5, &r_tab1);
	cTabDlg6->Create(IDD_TAB_DIALOG6, &r_tab1);
	cTabDlg1->MoveWindow(tabRect);
	cTabDlg2->MoveWindow(tabRect);
	cTabDlg3->MoveWindow(tabRect);
	cTabDlg4->MoveWindow(tabRect);
	cTabDlg5->MoveWindow(tabRect);
	cTabDlg6->MoveWindow(tabRect);
	cTabDlg1->ShowWindow(SW_SHOW);
	cTabDlg2->ShowWindow(SW_HIDE);
	cTabDlg3->ShowWindow(SW_HIDE);
	cTabDlg4->ShowWindow(SW_HIDE);
	cTabDlg5->ShowWindow(SW_HIDE);
	cTabDlg6->ShowWindow(SW_HIDE);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSSGEditDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSSGEditDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSSGEditDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSSGEditDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	switch (r_tab1.GetCurSel())
	{
	case 0:
		cTabDlg1->ShowWindow(SW_SHOW);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);
		cTabDlg4->ShowWindow(SW_HIDE);
		cTabDlg5->ShowWindow(SW_HIDE);
		cTabDlg6->ShowWindow(SW_HIDE);
		break;
	case 1:
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg2->ShowWindow(SW_SHOW);
		cTabDlg3->ShowWindow(SW_HIDE);
		cTabDlg4->ShowWindow(SW_HIDE);
		cTabDlg5->ShowWindow(SW_HIDE);
		cTabDlg6->ShowWindow(SW_HIDE);
		break;
	case 2:
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_SHOW);
		cTabDlg4->ShowWindow(SW_HIDE);
		cTabDlg5->ShowWindow(SW_HIDE);
		cTabDlg6->ShowWindow(SW_HIDE);
		break;
	case 3:
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);
		cTabDlg4->ShowWindow(SW_SHOW);
		cTabDlg5->ShowWindow(SW_HIDE);
		cTabDlg6->ShowWindow(SW_HIDE);
		break;
	case 4:
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);
		cTabDlg4->ShowWindow(SW_HIDE);
		cTabDlg5->ShowWindow(SW_SHOW);
		cTabDlg6->ShowWindow(SW_HIDE);
		break;
	case 5:
		cTabDlg1->ShowWindow(SW_HIDE);
		cTabDlg2->ShowWindow(SW_HIDE);
		cTabDlg3->ShowWindow(SW_HIDE);
		cTabDlg4->ShowWindow(SW_HIDE);
		cTabDlg5->ShowWindow(SW_HIDE);
		cTabDlg6->ShowWindow(SW_SHOW);

		break;

	}
	*pResult = 0;
}

void CSSGEditDlg::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE);//弹出打开文件对话框
	CString strFileName;
	CStdioFile cFile;
	if (dlg.DoModal() == IDOK)
		strFileName = dlg.GetPathName();
	else
		strFileName.Empty();
	BOOL ret=cFile.Open(strFileName, CFile::modeRead);
	CString sLine;
	int iVer = 0;
	while (cFile.ReadString(sLine))
	{
		if (sLine.Find(TEXT("VER=")) != -1)
		{
			iVer = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			if (iVer < 2020)
			{
				MessageBox(TEXT("请打开v2020以上的版本"));
			}
			break;
		}
	}
	if (ret==0)
	{
		MessageBox(TEXT("无法打开文件"));
	}
	else if(ret != 0&& iVer>=2020)
	{
		//向对话框发送消息
		::PostMessage(cTabDlg1->GetSafeHwnd(), NM_A, (LPARAM)0, (LPARAM)0);
		::PostMessage(cTabDlg2->GetSafeHwnd(), NM_A, (LPARAM)0, (LPARAM)0);
		::PostMessage(cTabDlg3->GetSafeHwnd(), NM_A, (LPARAM)0, (LPARAM)0);
		::PostMessage(cTabDlg4->GetSafeHwnd(), NM_A, (LPARAM)0, (LPARAM)0);
		::PostMessage(cTabDlg5->GetSafeHwnd(), NM_A, (LPARAM)0, (LPARAM)0);
		::PostMessage(cTabDlg6->GetSafeHwnd(), NM_A, (LPARAM)0, (LPARAM)0);
		m_filename = strFileName;
		UpdateData(FALSE);
	}
	cFile.Close();
	
	// TODO: 在此添加控件通知处理程序代码
}


void CSSGEditDlg::OnBnClickedButton2()
{	
	//向对话框发送消息
	switch (r_tab1.GetCurSel())
	{
	case 0:
		::PostMessage(cTabDlg1->GetSafeHwnd(), NM_B, (LPARAM)0, (LPARAM)0);
		break;
	case 1:
		::PostMessage(cTabDlg2->GetSafeHwnd(), NM_C, (LPARAM)0, (LPARAM)0);
		break;
	case 2:
		::PostMessage(cTabDlg3->GetSafeHwnd(), NM_D, (LPARAM)0, (LPARAM)0);
		break;
	case 3:
		::PostMessage(cTabDlg4->GetSafeHwnd(), NM_E, (LPARAM)0, (LPARAM)0);
		break;
	case 4:
		::PostMessage(cTabDlg5->GetSafeHwnd(), NM_F, (LPARAM)0, (LPARAM)0);
		break;
	case 5:
		::PostMessage(cTabDlg6->GetSafeHwnd(), NM_G, (LPARAM)0, (LPARAM)0);
		break;
	}
	// TODO: 在此添加控件通知处理程序代码
}
