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
public:
	CString GetComboBoxIndex(CStringArray& arr, int nCol);
	void SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, CStringArray& arrnfo, int InfoIndex);
	virtual BOOL OnInitDialog();
	CGridCtrl m_Grid_Column;
	afx_msg LRESULT OnUpDate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWriteDate(WPARAM wParam, LPARAM lParam);
private:
	CStringArray arrConcMat;
	CStringArray arrRebarMat;
};
