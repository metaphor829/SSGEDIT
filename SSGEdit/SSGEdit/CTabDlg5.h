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
public:
	typedef struct SlabStruc
	{
		int ID;
		int iPKPM;
		int nLine;
		int iNode[50];
		int iType;
		int iSection;
		int iSubType;
		int nRebarLayer;
		int iConcMat;
		int iRebarMat;
		int iSteelMat;
		int iStory;
		int iStage;
		int iTower;
		float fF1;
		float fF2;
		float fOffset;
		float fRebarRatio1;
		float fAngle1;
		float fRebarRatio2;
		float fAngle2;
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
	}Slab;
	int iRowCount;
	int iColCount;
	int selCol;
	int selRow;
	float fTimes[2];
	POINT oldRectCoor;
	POINT newRectCoor;
	std::vector<Slab>vSlab;
	CGridCtrl m_Grid_Slab;
	void SetSlabData(Slab& slab, CDataFile& fin);
	void GetSlabData(CGridCtrl& m_Grid_Slab, int iRow);
	void WriteSlabData(int iRow, CString& sNewLine);
	void SetGridItemText(int iRow,CGridCtrl& m_Grid_Slab,Slab& slab);
	int GetComboBoxIndex(CString sMat);
	void SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat);
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnUpDate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWriteDate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSearchID(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowAll(WPARAM wParam, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);
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
