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

// CTabDlg4 对话框

class CTabDlg4 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlg4)

public:
	CTabDlg4(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDlg4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CGridCtrl m_Grid_Wall;
	void TrimArray(CStringArray& arrText, CStringArray& arrInfo);
	void ExpandArray(CStringArray& arr, int iCount);
	CString GetComboBoxIndex(CStringArray& arr, int nCol);
	void SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, CStringArray& arrInfo, int InfoIndex);
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnUpDate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWriteDate(WPARAM wParam, LPARAM lParam);

private:
	CStringArray arrConcMat;
	CStringArray arrRebarMat;
};
