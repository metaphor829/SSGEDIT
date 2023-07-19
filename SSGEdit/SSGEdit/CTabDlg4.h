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
	typedef struct WallStruc
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
		int iBottomStory;
		int idmStory;
		int iStage;
		int iTower;
		float fOffset;
		float fHRebarArea;
		float fAngle1;
		float fVRebarArea;
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
	}Wall;
	int iRowCount;
	std::vector<Wall>vWall;
	CGridCtrl m_Grid_Wall;
	void SetWallData(Wall& wall, CDataFile& fin);
	void GetWallData(CGridCtrl& m_Grid_Wall, int iRow);
	void WriteWallData(int iRow, CString& sNewLine);
	void SetGridItemText(int iRow, int iColCount, CGridCtrl& m_Grid_Wall, CDataFile& fin, Wall& wall);
	int GetComboBoxIndex(CString sMat);
	void SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat);
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnUpDate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWriteDate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSearchID(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnShowAll(WPARAM wParam, LPARAM lParam);

private:
	CStringArray arrConcMat;
	CStringArray arrRebarMat;
	CStringArray arrSteelMat;
};
