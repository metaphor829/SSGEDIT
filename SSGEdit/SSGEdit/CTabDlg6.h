#pragma once
#include "afxdialogex.h"
#include "SSGEdit.h"
#include "pch.h"
#include "GridCtrl.h"
#include "GridCellCombo.h"
#include <SplitStr.h>
#include <string>
#include <cstring>
#include <io.h>
#include <fstream> 
#include <iostream>
#include <vector>
#include <tchar.h>
#include <sstream>
#include <stdio.h>
#include <direct.h>
#include <numeric>
#include <algorithm>


// CTabDlg6 对话框

class CTabDlg6 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlg6)

public:
	CTabDlg6(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDlg6();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CGridCtrl m_Grid_Coor;
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnUpDate(WPARAM wParam, LPARAM lParam);
};
