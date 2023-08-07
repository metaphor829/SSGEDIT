#pragma once
#include "afxdialogex.h"
#include "SSGEdit.h"
#include "pch.h"
#include "GridCtrl.h"
#include "GridCellCombo.h"
#include "CDataFile.h"
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

	typedef struct ColumnStruc
	{
		int ID;
		int iPKPM;
		int iLine;
		int iType;
		int iSection;
		int iSubType;
		int bArtiNode1;
		int bArtiNode2;
		int iConcMat;
		int iRebarMat;
		int iStirrupMat;
		int iSteelMat;
		int iBottomStory;
		int iStory;
		int iStage;
		int iTower;
		float fRotateAng;
		float fOffsetX1;
		float fOffsetY1;
		float fOffsetZ1;
		float fOffsetX2;
		float fOffsetY2;
		float fOffsetZ2;
		float fConnerArea;
		float fBsideArea;
		float fHsideArea;
		float fStirrupArea_D;
		float fStirrupArea_UD;
		float fForce;
		int iMidPerformType;
		int iSeverePerformType;
		int iStructType;
		int iMidNormSectPerformObject;
		int	iMidDiagSectPerformObject;
		int	iRareNormSectPerformObject;
		int iRareDiagSectPerformObject;
		int iParaNumbers;
		float fAxisFactor;
		float fMomentFactor;
		float fShearFactor;
		int iAppendMat;
		int iNode1Sec;
		int iNode2Sec;
		int iShearNonlinear;
		float fColumnSpan;
		int iReinforcedSec;
	}Column;
	int iRowCount;
	int iColCount;
	int selCol;
	int selRow;
	float fTimes[2];
	POINT oldRectCoor;
	POINT newRectCoor;
	std::vector<Column>vColumn;
	void SetColumnData(Column& column, CDataFile& fin);//读取文本文件中的Column构件信息至Column结构体中
	void GetColumnData(CGridCtrl& m_Grid_Column, int iRow);//读取表格中的Column构件信息至Column的vector中
	void WriteColumnData(int iRow, CString& sNewLine);//将修改后的Column构件信息写入文本文件
	void SetGridItemText(int iRow, CGridCtrl& m_Grid_Column,Column& column);//将Column构件信息写入grid表格并显示
	int GetComboBoxIndex(CString sMat);//获得Combox选项的序号
	void SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat);//根据序号的值设置Combobox的内容
	CGridCtrl m_Grid_Column;
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnUpDate(WPARAM wParam, LPARAM lParam);//打开文件后立即更新grid表格显示
	afx_msg LRESULT OnWriteDate(WPARAM wParam, LPARAM lParam);//读取Gird中的信息写入文本文件
	afx_msg LRESULT OnSearchID(WPARAM wParam, LPARAM lParam);//搜索构件ID
	afx_msg LRESULT OnShowAll(WPARAM wParam, LPARAM lParam);//显示所有行列
	afx_msg void OnSize(UINT nType, int cx, int cy);//根据窗口调整大小，调整Grid控件大小
	void ReSize();
	void SetCtrlRect(int nID);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);//添加右键菜单并初始化
	afx_msg void OnSelChanged(NMHDR* pNMHDR, LRESULT* pResult);//获取所选单元格的行列信息
	afx_msg void OnHiddenColumn();//隐藏该列
	afx_msg void OnHiddenRow();//隐藏该行
	afx_msg void OnShowColumn();//仅显示该列
	afx_msg void OnShowRow();//仅显示该行
private:
	CStringArray arrConcMat;
	CStringArray arrRebarMat;
	CStringArray arrSteelMat;
};
