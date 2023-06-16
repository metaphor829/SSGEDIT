#pragma once
#include "afxdialogex.h"


// CTabDlg3 对话框

class CTabDlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlg3)

public:
	CTabDlg3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDlg3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
