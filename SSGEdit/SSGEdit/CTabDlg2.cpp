// CTabDlg2.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "afxdialogex.h"
#include "CTabDlg2.h"


// CTabDlg2 对话框

IMPLEMENT_DYNAMIC(CTabDlg2, CDialogEx)

CTabDlg2::CTabDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG2, pParent)
{

}

CTabDlg2::~CTabDlg2()
{
}

void CTabDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_beamlist);
}


BEGIN_MESSAGE_MAP(CTabDlg2, CDialogEx)
END_MESSAGE_MAP()


// CTabDlg2 消息处理程序


BOOL CTabDlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_beamlist.DeleteAllItems();
	m_beamlist.SetRedraw(FALSE);
	m_beamlist.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 50);
	m_beamlist.InsertColumn(1, _T("结构线编号"), LVCFMT_LEFT, 80);
	m_beamlist.InsertColumn(2, _T("截面类型"), LVCFMT_LEFT, 80);
	m_beamlist.InsertColumn(3, _T("子类型"), LVCFMT_LEFT, 80);
	m_beamlist.InsertColumn(4, _T("混凝土强度等级"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(5, _T("钢筋级别"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(6, _T("箍筋级别"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(7, _T("钢材型号"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(8, _T("楼层"), LVCFMT_LEFT, 50);
	m_beamlist.InsertColumn(9, _T("施工阶段"), LVCFMT_LEFT, 50);
	m_beamlist.InsertColumn(10, _T("塔号"), LVCFMT_LEFT, 50);
	m_beamlist.InsertColumn(11, _T("方向角（度）"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(12, _T("1点X方向偏移"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(13, _T("1点Y方向偏移"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(14, _T("1点Z方向偏移"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(15, _T("2点X方向偏移"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(16, _T("2点Y方向偏移"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(17, _T("2点Z方向偏移"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(18, _T("面筋配筋率"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(19, _T("底筋配筋率"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(20, _T("加密区箍筋面积"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(21, _T("非加密区箍筋面积"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(22, _T("恒荷载qx（kN/m）"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(23, _T("恒荷载qy（kN/m）"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(24, _T("恒荷载qz（kN/m）"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(25, _T("活荷载qx（kN/m）"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(26, _T("活荷载qy（kN/m）"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(27, _T("活荷载qz（kN/m）"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(28, _T("中震本构"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(29, _T("大震本构"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(30, _T("重要性分类"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(31, _T("中震正截面性能"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(32, _T("中震斜截面性能"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(33, _T("大震正截面性能"), LVCFMT_LEFT, 100);
	m_beamlist.InsertColumn(34, _T("大震斜截面性能"), LVCFMT_LEFT, 100);
	m_beamlist.SetRedraw(TRUE);
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
