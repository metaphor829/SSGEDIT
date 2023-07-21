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


// CTabDlg7 对话框

class CTabDlg7 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlg7)

public:
	CTabDlg7(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDlg7();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	typedef struct BraceStruc
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
		float fBraceSpan;
		int iReinforcedSec;
	}Brace;
	int iRowCount;
	std::vector<Brace>vBrace;
	void SetBraceData(Brace& brace, CDataFile& fin);
	void GetBraceData(CGridCtrl& m_Grid_Brace, int iRow);
	void WriteBraceData(int iRow, CString& sNewLine);
	void SetGridItemText(int iRow,CGridCtrl& m_Grid_Brace,Brace& brace);
	int GetComboBoxIndex(CString sMat);
	void SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat);
	CGridCtrl m_Grid_Brace;
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
