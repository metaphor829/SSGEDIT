#pragma once
#include "afxdialogex.h"


// CTabDlg2 对话框

class CTabDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlg2)

public:
	CTabDlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_beamlist;
	virtual BOOL OnInitDialog();
};
