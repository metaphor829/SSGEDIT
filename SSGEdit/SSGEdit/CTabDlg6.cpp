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
	ON_MESSAGE(NM_G, OnWriteDate)
	ON_MESSAGE(NM_I, OnSearchID)
	ON_MESSAGE(NM_J, OnShowAll)
END_MESSAGE_MAP()


// CTabDLG6 消息处理程序


void CTabDlg6::SetCoorData(Coor& coor, CDataFile& fin)
{
	coor.ID = fin.GetInt();
	coor.fCoordinationX = fin.GetFloat();
	coor.fCoordinationY = fin.GetFloat();
	coor.fCoordinationZ = fin.GetFloat();
	coor.fForceX1 = fin.GetFloat();
	coor.fForceY1 = fin.GetFloat();
	coor.fForceZ1 = fin.GetFloat();
	coor.fMomentX1 = fin.GetFloat();
	coor.fMomentY1 = fin.GetFloat();
	coor.fMomentZ1 = fin.GetFloat();
	coor.fForceX2 = fin.GetFloat();
	coor.fForceY2 = fin.GetFloat();
	coor.fForceZ2 = fin.GetFloat();
	coor.fMomentX2 = fin.GetFloat();
	coor.fMomentY2 = fin.GetFloat();
	coor.fMomentZ2 = fin.GetFloat();
	coor.iStory = fin.GetInt();
	coor.iStage = fin.GetInt();
	coor.iTower = fin.GetInt();
	coor.iRigidBody = fin.GetInt();
}

void CTabDlg6::GetCoorData(Coor& coor, CGridCtrl& m_Grid_Coor, int iRow)
{
	coor.ID = _ttoi(m_Grid_Coor.GetItemText(iRow + 1, 0));
	coor.fCoordinationX = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 1));
	coor.fCoordinationY = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 2));
	coor.fCoordinationZ = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 3));
	coor.fForceX1 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 4));
	coor.fForceY1 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 5));
	coor.fForceZ1 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 6));
	coor.fMomentX1 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 7));
	coor.fMomentY1 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 8));
	coor.fMomentZ1 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 9));
	coor.fForceX2 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 10));
	coor.fForceY2 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 11));
	coor.fForceZ2 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 12));
	coor.fMomentX2 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 13));
	coor.fMomentY2 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 14));
	coor.fMomentZ2 = _ttof(m_Grid_Coor.GetItemText(iRow + 1, 15));
	coor.iStory = _ttoi(m_Grid_Coor.GetItemText(iRow + 1, 16));
	coor.iStage = _ttoi(m_Grid_Coor.GetItemText(iRow + 1, 17));
	coor.iTower = _ttoi(m_Grid_Coor.GetItemText(iRow + 1, 18));
	coor.iRigidBody = _ttoi(m_Grid_Coor.GetItemText(iRow + 1, 19));
}


void CTabDlg6::WriteCoorData(Coor& coor, CString& sNewLine)
{
	char temp[512];
	sprintf_s(temp, sizeof(temp), "%d ", coor.ID);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fCoordinationX);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fCoordinationY);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fCoordinationZ);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fForceX1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fForceY1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fForceZ1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fMomentX1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fMomentY1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fMomentZ1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fForceX2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fForceY2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fForceZ2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fMomentX2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fMomentY2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", coor.fMomentZ2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", coor.iStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", coor.iStage);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", coor.iTower);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d", coor.iRigidBody);
	sNewLine += temp;
}

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
	//设置列宽
	for (int i = 0; i < 20; i++)
	{
		m_Grid_Coor.SetColumnWidth(i, 60);
	}
	
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

LRESULT CTabDlg6::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	CDataFile fin;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	fin.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	fin.SeekToBegin();
	CString sLine;
	int iColCount = m_Grid_Coor.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		if (sLine.Find(TEXT("COOR NUMBER=")) != -1)
		{
			iRowCount = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			m_Grid_Coor.SetRowCount(iRowCount + 1);
			break;
		}
	}
	for (int i = 0; i < iRowCount; i++)
	{
		fin.ReadString(sLine);
		fin.SetData(sLine);
		Coor coor;
		SetCoorData(coor,fin);
		for (int j = 0; j < iColCount; j++)
		{
			//MessageBox(fin.arrInfo[j]);
			m_Grid_Coor.SetItemText(i + 1, j, (LPCTSTR)fin.arrInfo[j]);
		}
		for (int j = 0; j < 4; j++)
		{
			m_Grid_Coor.SetItemState(i + 1, j, GVIS_READONLY);
		}
		fin.arrInfo.RemoveAll();
	}
	return LRESULT();
}

LRESULT CTabDlg6::OnWriteDate(WPARAM wParam, LPARAM lParam)
{
	
	CDataFile fin;
	CDataFile fout;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	CString sNewPath = sPath.Left(sPath.ReverseFind('.')) + _T("(new)") + sPath.Mid(sPath.ReverseFind('.'));
	fin.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	fout.Open(sNewPath, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyNone);
	fin.SeekToBegin();
	fout.SeekToBegin();
	CString sLine;
	CString sNewLine;
	int iColCount = m_Grid_Coor.GetColumnCount();

	while (fin.ReadString(sLine))
	{
		fout.WriteString(sLine + _T("\n"));
		if (sLine.Find(TEXT("COOR NUMBER=")) != -1)//先定位至COORNUMBER所在行
		{
			for (int i = 0; i < iRowCount; i++)
			{
				fin.ReadString(sLine);
				Coor coor;
				GetCoorData(coor, m_Grid_Coor, i);
				WriteCoorData(coor, sNewLine);
				//MessageBox(sNewLine);
				fout.WriteString(sNewLine + _T("\n"));
				sNewLine.Empty();
				
			}
		}
	}
	fin.Close();
	fout.Close();
	fin.Remove(sPath);
	fout.Rename(sNewPath, sPath);
	return LRESULT();
}

LRESULT CTabDlg6::OnSearchID(WPARAM wParam, LPARAM lParam)
{
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	int ID = _ttoi(pParent->m_ID);//从父窗口得到ID序号
	if (ID != 0 && ID <= iRowCount)
	{
		for (int i = 1; i < iRowCount + 1; i++)
		{
			if (i != ID)
			{
				m_Grid_Coor.SetRowHeight(i, 0);
			}
		}
	}
	else
	{
		MessageBox(TEXT("请输入列表内的ID序号进行搜索"));
	}
	return LRESULT();
}

LRESULT CTabDlg6::OnShowAll(WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < iRowCount + 1; i++)
	{
		m_Grid_Coor.SetRowHeight(i, 25);
	}
	return LRESULT();
}
