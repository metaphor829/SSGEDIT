#pragma once
#include "afxdialogex.h"


// CTabDlg5 对话框

class CTabDlg5 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlg5)

public:
	CTabDlg5(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDlg5();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
