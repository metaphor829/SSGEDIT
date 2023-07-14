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
	typedef struct BeamStruc
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
		float fUpperRebarLeft;
		float fUpperRebarMid;
		float fUpperRebarRight;
		float fLowerRebarLeft;
		float fLowerRebarMid;
		float fLowerRebarRight;
		float fStirrupArea_D;
		float fStirrupArea_UD;
		int nForceParament;
		float fF1;
		float fLength;
		float fF2;
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
		float fBeamSpan;
		int iReinforcedSec;
	}Beam;
	std::vector<Beam>vBeam;
	void SetBeamData(Beam& beam, CDataFile& fin);
	void GetBeamData(CGridCtrl& m_Grid_Beam, int iRow);
	void WriteBeamData(int iRow, CString& sNewLine);
	void SetGridItemText(int iRow, int iColCount, CGridCtrl& m_Grid_Beam, CDataFile& fin, Beam& beam);
	int GetComboBoxIndex(CString sMat);
	void SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat);
	CGridCtrl m_Grid_Beam;
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnUpDate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWriteDate(WPARAM wParam, LPARAM lParam);
	
private:
	CStringArray arrConcMat;
	CStringArray arrRebarMat;
	CStringArray arrSteelMat;
};
