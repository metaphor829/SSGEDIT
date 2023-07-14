
// SSGEditDlg.h: 头文件
//

#pragma once
#include "CTabDlg1.h"
#include "CTabDlg2.h"
#include "CTabDlg3.h"
#include "CTabDlg4.h"
#include "CTabDlg5.h"
#include "CTabDlg6.h"
#include "CTabDlg7.h"
#include "resource.h"
#include "afxcmn.h"
#include "afxdialogex.h"
#include "afx.h"
#include <string>
#include <cstring>
#include <io.h>
#include <fstream> 
#include <iostream>
#include <vector>
#include <tchar.h>


//WM_USER 是用户自定义消息的一个起始值
//WM_USER+100是为了区分系统消息和用户消息，避免冲突
#define NM_A	(WM_USER + 100)
#define NM_B	(WM_USER + 101)
#define NM_C	(WM_USER + 102)
#define NM_D	(WM_USER + 103)
#define NM_E	(WM_USER + 104)
#define NM_F	(WM_USER + 105)
#define NM_G	(WM_USER + 106)
#define NM_H	(WM_USER + 107)

using namespace std;
// CSSGEditDlg 对话框
class CSSGEditDlg : public CDialogEx
{
// 构造
public:
	CSSGEditDlg(CWnd* pParent = nullptr);	// 标准构造函数
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SSGEDIT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabDlg1* cTabDlg1;
	CTabDlg2* cTabDlg2;
	CTabDlg3* cTabDlg3;
	CTabDlg4* cTabDlg4;
	CTabDlg5* cTabDlg5;
	CTabDlg6* cTabDlg6;
	CTabDlg7* cTabDlg7;
	CTabCtrl r_tab1;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton1();
	CString m_filename;
	
	afx_msg void OnBnClickedButton2();
	virtual void OnCancel();
};

