// CTabDLG6.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "afxdialogex.h"
#include "SSGEditDlg.h"
#include "CTabDlg6.h"


// CTabDLG6 对话框

IMPLEMENT_DYNAMIC(CTabDlg6, CDialogEx)

CTabDlg6::CTabDlg6(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG6, pParent)
{

}

CTabDlg6::~CTabDlg6()
{
}

void CTabDlg6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM5, m_Grid_Coor);
}




BEGIN_MESSAGE_MAP(CTabDlg6, CDialogEx)
	ON_MESSAGE(NM_A, OnUpDate)
END_MESSAGE_MAP()


// CTabDLG6 消息处理程序


BOOL CTabDlg6::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Coor.GetClientRect(&cr);
	m_Grid_Coor.SetColumnCount(20);//设置列数
	m_Grid_Coor.SetFixedRowCount(1);//设置表头
	m_Grid_Coor.SetItemText(0, 0, _T("ID"));
	m_Grid_Coor.SetItemText(0, 1, _T("X坐标"));
	m_Grid_Coor.SetItemText(0, 2, _T("Y坐标"));
	m_Grid_Coor.SetItemText(0, 3, _T("Z坐标"));
	m_Grid_Coor.SetItemText(0, 4, _T("恒载Fx"));
	m_Grid_Coor.SetItemText(0, 5, _T("恒载Fy"));
	m_Grid_Coor.SetItemText(0, 6, _T("恒载Fz"));
	m_Grid_Coor.SetItemText(0, 7, _T("恒载Mx"));
	m_Grid_Coor.SetItemText(0, 8, _T("恒载My"));
	m_Grid_Coor.SetItemText(0, 9, _T("恒载Mz"));
	m_Grid_Coor.SetItemText(0, 10, _T("活载Fx"));
	m_Grid_Coor.SetItemText(0, 11, _T("活载Fy"));
	m_Grid_Coor.SetItemText(0, 12, _T("活载Fz"));
	m_Grid_Coor.SetItemText(0, 13, _T("活载Mx"));
	m_Grid_Coor.SetItemText(0, 14, _T("活载My"));
	m_Grid_Coor.SetItemText(0, 15, _T("活载Mz"));
	m_Grid_Coor.SetItemText(0, 16, _T("楼层"));
	m_Grid_Coor.SetItemText(0, 17, _T("施工阶段"));
	m_Grid_Coor.SetItemText(0, 18, _T("塔号"));
	m_Grid_Coor.SetItemText(0, 19, _T("固定方式"));
	
	// TODO:  在此添加额外的初始化
	//设置列宽，并将部分列隐藏
	m_Grid_Coor.SetColumnWidth(0, 50);
	m_Grid_Coor.SetColumnWidth(1, 60);
	m_Grid_Coor.SetColumnWidth(2, 60);
	m_Grid_Coor.SetColumnWidth(3, 60);
	m_Grid_Coor.SetColumnWidth(4, 60);
	m_Grid_Coor.SetColumnWidth(5, 60);
	m_Grid_Coor.SetColumnWidth(6, 60);
	m_Grid_Coor.SetColumnWidth(7, 60);
	m_Grid_Coor.SetColumnWidth(8, 60);
	m_Grid_Coor.SetColumnWidth(9, 60);
	m_Grid_Coor.SetColumnWidth(10, 60);
	m_Grid_Coor.SetColumnWidth(11, 60);
	m_Grid_Coor.SetColumnWidth(12, 60);
	m_Grid_Coor.SetColumnWidth(13, 60);
	m_Grid_Coor.SetColumnWidth(14, 60);
	m_Grid_Coor.SetColumnWidth(15, 60);
	m_Grid_Coor.SetColumnWidth(16, 60);
	m_Grid_Coor.SetColumnWidth(17, 60);
	m_Grid_Coor.SetColumnWidth(18, 60);
	m_Grid_Coor.SetColumnWidth(19, 60);
	
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

LRESULT CTabDlg6::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	
	return LRESULT();
}
