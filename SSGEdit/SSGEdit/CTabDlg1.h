#pragma once
#include "afxdialogex.h"
#include "afxcmn.h"
#include "SSGEditDlg.h"
#include <string>
#include <cstring>
#include <io.h>
#include <fstream> 
#include <iostream>
#include <vector>
#include <tchar.h>


// CTabDlg1 对话框

class CTabDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTabDlg1)

public:
	CTabDlg1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTabDlg1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
public:
	
private:
	CComboBox m_codetype;
	CString m_name;
	float m_rebarcover;
	float m_colcover;
	float m_slabcover;
	float m_wallcover;
	float m_congravity;
	float m_stellgravity;
	float m_accgravity;
	CString m_edgerebar;
	CString m_linkrebar;
	float m_beamlinkspace;
	float m_slabdethickness;
	float m_walldethickness;
	CComboBox m_wallseisgrade;
	CComboBox m_colseisgrade;
	CComboBox m_slabseisgrade;
	CComboBox m_seisdetailgrade;
	CComboBox m_forticategory;
	CComboBox m_fieldclass;
	CComboBox m_fieldgroup;
	CComboBox m_eqgrade;
	CComboBox m_eqgradeprobility;
	float m_beamrebardiameter;
	float m_colrebardiameter;
	float m_slabrebarratio;
	float m_wallrebarratio;
	float m_beamrebarratio;
	float m_colrebarratio;
public:
	virtual BOOL OnInitDialog();
	afx_msg LRESULT UpdateTab(WPARAM wParam, LPARAM lParam);
};

