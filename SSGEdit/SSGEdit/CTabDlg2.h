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
	int iRowCount;
	int iColCount;
	int selCol;
	int selRow;
	float fTimes[2];
	POINT oldRectCoor;
	POINT newRectCoor;
	std::vector<Beam>vBeam;
	void SetBeamData(Beam& beam, CDataFile& fin);//读取文本文件中的beam构件信息至beam结构体中
	void GetBeamData(CGridCtrl& m_Grid_Beam, int iRow);//读取表格中的beam构件信息至Beam的vector中
	void WriteBeamData(int iRow, CString& sNewLine);//将修改后的beam构件信息写入文本文件
	void SetGridItemText(int iRow, CGridCtrl& m_Grid_Beam,Beam& beam);//将beam构件信息写入grid表格并显示
	int GetComboBoxIndex(CString sMat);//获得Combox选项的序号
	void SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat);//根据序号的值设置Combobox的内容
	CGridCtrl m_Grid_Beam;
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
