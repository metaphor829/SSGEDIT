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
	typedef struct CoorStruc
	{
		int ID;
		float fCoordinationX;
		float fCoordinationY;
		float fCoordinationZ;
		float fForceX1;
		float fForceY1;
		float fForceZ1;
		float fMomentX1;
		float fMomentY1;
		float fMomentZ1;
		float fForceX2;
		float fForceY2;
		float fForceZ2;
		float fMomentX2;
		float fMomentY2;
		float fMomentZ2;
		int iStory;
		int iStage;
		int iTower;
		int iRigidBody;
	}Coor; 
	int iRowCount;
	int iColCount;
	int selCol;
	int selRow;
	float fTimes[2];
	POINT oldRectCoor;
	POINT newRectCoor;
	CGridCtrl m_Grid_Coor;
	void SetCoorData(Coor& coor, CDataFile& fin);
	void GetCoorData(Coor& coor, CGridCtrl& m_Grid_Coor,int iRow);
	void WriteCoorData(Coor& coor, CString& sNewLine);
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
	
};
