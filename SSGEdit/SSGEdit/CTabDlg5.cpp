// CTabDlg5.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "afxdialogex.h"
#include "SSGEditDlg.h"
#include "CTabDlg5.h"


// CTabDlg5 对话框

IMPLEMENT_DYNAMIC(CTabDlg5, CDialogEx)

CTabDlg5::CTabDlg5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG5, pParent)
{
	arrConcMat.SetSize(20);
	arrConcMat.SetAt(0, TEXT("C15"));
	arrConcMat.SetAt(1, TEXT("C20"));
	arrConcMat.SetAt(2, TEXT("C25"));
	arrConcMat.SetAt(3, TEXT("C30"));
	arrConcMat.SetAt(4, TEXT("C35"));
	arrConcMat.SetAt(5, TEXT("C40"));
	arrConcMat.SetAt(6, TEXT("C45"));
	arrConcMat.SetAt(7, TEXT("C50"));
	arrConcMat.SetAt(8, TEXT("C55"));
	arrConcMat.SetAt(9, TEXT("C60"));
	arrConcMat.SetAt(10, TEXT("C65"));
	arrConcMat.SetAt(11, TEXT("C70"));
	arrConcMat.SetAt(12, TEXT("C75"));
	arrConcMat.SetAt(13, TEXT("C80"));
	arrConcMat.SetAt(14, TEXT("C85"));
	arrConcMat.SetAt(15, TEXT("C90"));
	arrConcMat.SetAt(16, TEXT("C95"));
	arrConcMat.SetAt(17, TEXT("C100"));
	arrConcMat.SetAt(18, TEXT("C105"));
	arrRebarMat.SetSize(15);
	arrRebarMat.SetAt(0, TEXT("HPB235"));
	arrRebarMat.SetAt(1, TEXT("HRB300"));
	arrRebarMat.SetAt(2, TEXT("HRB335"));
	arrRebarMat.SetAt(3, TEXT("HRB400"));
	arrRebarMat.SetAt(4, TEXT("HRB500"));
	arrRebarMat.SetAt(5, TEXT("CRB550"));
	arrRebarMat.SetAt(6, TEXT("CRB600H"));
	arrRebarMat.SetAt(7, TEXT("HTRB600"));
	arrRebarMat.SetAt(8, TEXT("HTRB630"));
	arrRebarMat.SetAt(9, TEXT("HRB635"));
	arrRebarMat.SetAt(10, TEXT("T63"));
}

CTabDlg5::~CTabDlg5()
{
}

void CTabDlg5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM4, m_Grid_Slab);
}

BEGIN_MESSAGE_MAP(CTabDlg5, CDialogEx)
	ON_MESSAGE(NM_A, OnUpDate)
	ON_MESSAGE(NM_F, OnWriteDate)
END_MESSAGE_MAP()

// CTabDlg5 消息处理程序

void CTabDlg5::TrimArray(CStringArray& arrText, CStringArray& arrInfo)
{
	int iTrimSize = arrText.GetSize() - arrInfo.GetSize();
	for (int i = 0; i < iTrimSize; i++)
	{
		arrText.RemoveAt(12 - iTrimSize);
	}
}

void CTabDlg5::ExpandArray(CStringArray& arr, int iCount)
{
	int iExpandSize = iCount - arr.GetSize();
	arr.SetSize(iCount);
	for (int i = 0; i < iExpandSize; i++)
	{
		arr.InsertAt(12 - iExpandSize, _T("0"));
	}

}

CString CTabDlg5::GetComboBoxIndex(CStringArray& arr, int nCol)
{
	for (int i = 0; i < arrConcMat.GetSize(); i++)
	{
		if (arrConcMat.GetAt(i) == arr.GetAt(nCol))
		{
			CString String;
			String.Format(_T("%d"), i);
			return String;
		}
	}
	for (int i = 0; i < arrRebarMat.GetSize(); i++)
	{
		if (arrRebarMat.GetAt(i) == arr.GetAt(nCol))
		{
			CString String;
			String.Format(_T("%d"), i + 101);
			return String;
		}
	}
	return CString();
}

void CTabDlg5::SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, CStringArray& arrInfo, int InfoIndex)
{
	CGridCellCombo* pCell = (CGridCellCombo*)m_Grid.GetCell(nRow, nCol);
	pCell->SetOptions(arrText);
	int iBeamInfo = _ttoi(arrInfo.GetAt(InfoIndex));
	if (iBeamInfo < 100) {
		pCell->SetText(arrText.GetAt(_ttoi(arrInfo.GetAt(InfoIndex))));
	}
	else {
		pCell->SetText(arrText.GetAt(_ttoi(arrInfo.GetAt(InfoIndex)) - 101));
	}
}

BOOL CTabDlg5::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Slab.GetClientRect(&cr);
	m_Grid_Slab.SetColumnCount(45);//设置列数
	m_Grid_Slab.SetFixedRowCount(1);//设置表头
	m_Grid_Slab.SetItemText(0, 0, _T("ID"));
	m_Grid_Slab.SetItemText(0, 1, _T("PKPM结构线编号"));
	m_Grid_Slab.SetItemText(0, 2, _T("线数目"));
	m_Grid_Slab.SetItemText(0, 3, _T("线编号1"));
	m_Grid_Slab.SetItemText(0, 4, _T("线编号2"));
	m_Grid_Slab.SetItemText(0, 5, _T("线编号3"));
	m_Grid_Slab.SetItemText(0, 6, _T("线编号4"));
	m_Grid_Slab.SetItemText(0, 7, _T("线编号5"));
	m_Grid_Slab.SetItemText(0, 8, _T("线编号6"));
	m_Grid_Slab.SetItemText(0, 9, _T("线编号7"));
	m_Grid_Slab.SetItemText(0, 10, _T("线编号8"));
	m_Grid_Slab.SetItemText(0, 11, _T("线编号9"));
	m_Grid_Slab.SetItemText(0, 12, _T("对象类型"));
	m_Grid_Slab.SetItemText(0, 13, _T("截面类型"));
	m_Grid_Slab.SetItemText(0, 14, _T("子截面类型"));
	m_Grid_Slab.SetItemText(0, 15, _T("钢筋层数"));
	m_Grid_Slab.SetItemText(0, 16, _T("混凝土材料等级"));
	m_Grid_Slab.SetItemText(0, 17, _T("钢筋等级"));
	m_Grid_Slab.SetItemText(0, 18, _T("钢材等级"));
	m_Grid_Slab.SetItemText(0, 19, _T("楼层"));
	m_Grid_Slab.SetItemText(0, 20, _T("施工阶段"));
	m_Grid_Slab.SetItemText(0, 21, _T("塔号"));
	m_Grid_Slab.SetItemText(0, 22, _T("F1"));
	m_Grid_Slab.SetItemText(0, 23, _T("F2"));
	m_Grid_Slab.SetItemText(0, 24, _T("偏移值"));
	m_Grid_Slab.SetItemText(0, 25, _T("面筋单向配筋率"));
	m_Grid_Slab.SetItemText(0, 26, _T("水平筋方向角"));
	m_Grid_Slab.SetItemText(0, 27, _T("底筋单向配筋率"));
	m_Grid_Slab.SetItemText(0, 28, _T("竖向筋方向角"));
	m_Grid_Slab.SetItemText(0, 29, _T("中震本构"));
	m_Grid_Slab.SetItemText(0, 30, _T("大震本构"));
	m_Grid_Slab.SetItemText(0, 31, _T("重要性分类"));
	m_Grid_Slab.SetItemText(0, 32, _T("中震正截面性能"));
	m_Grid_Slab.SetItemText(0, 33, _T("中震斜截面性能"));
	m_Grid_Slab.SetItemText(0, 34, _T("大震正截面性能"));
	m_Grid_Slab.SetItemText(0, 35, _T("大震斜截面性能"));
	m_Grid_Slab.SetItemText(0, 36, _T("地震等级"));
	m_Grid_Slab.SetItemText(0, 37, _T("轴力内力调整系数"));
	m_Grid_Slab.SetItemText(0, 38, _T("弯矩内力调整系数"));
	m_Grid_Slab.SetItemText(0, 39, _T("剪力内力调整系数"));
	m_Grid_Slab.SetItemText(0, 40, _T("待确定"));
	m_Grid_Slab.SetItemText(0, 41, _T("待确定"));
	m_Grid_Slab.SetItemText(0, 42, _T("待确定"));
	m_Grid_Slab.SetItemText(0, 43, _T("待确定"));
	m_Grid_Slab.SetItemText(0, 44, _T("待确定"));
	// TODO:  在此添加额外的初始化
	//设置列宽，并将部分列隐藏
	m_Grid_Slab.SetColumnWidth(0, 50);
	m_Grid_Slab.SetColumnWidth(1, 0);
	m_Grid_Slab.SetColumnWidth(2, 50);
	m_Grid_Slab.SetColumnWidth(3, 60);
	m_Grid_Slab.SetColumnWidth(4, 60);
	m_Grid_Slab.SetColumnWidth(5, 60);
	m_Grid_Slab.SetColumnWidth(6, 60);
	m_Grid_Slab.SetColumnWidth(7, 60);
	m_Grid_Slab.SetColumnWidth(8, 60);
	m_Grid_Slab.SetColumnWidth(9, 60);
	m_Grid_Slab.SetColumnWidth(10, 60);
	m_Grid_Slab.SetColumnWidth(11, 60);
	m_Grid_Slab.SetColumnWidth(36, 0);
	m_Grid_Slab.SetColumnWidth(40, 0);
	m_Grid_Slab.SetColumnWidth(41, 0);
	m_Grid_Slab.SetColumnWidth(42, 0);
	m_Grid_Slab.SetColumnWidth(43, 0);
	m_Grid_Slab.SetColumnWidth(44, 0);
	m_Grid_Slab.EnableHiddenColUnhide(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



LRESULT CTabDlg5::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	CStdioFile cFile;
	CStdioFile cNewFile;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	CString sNewPath = sPath.Left(sPath.ReverseFind('.')) + _T("(new)") + sPath.Mid(sPath.ReverseFind('.'));
	cFile.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	cNewFile.Open(sNewPath, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyNone);
	cFile.SeekToBegin();// 将文件指针指向文件开始处
	cNewFile.SeekToBegin();
	int iSlabCount = m_Grid_Slab.GetColumnCount();
	CString sLine;
	CString sNewLine;
	static int iSlabNumbers = 0;
	static CString sSlabNumbers;
	while (cFile.ReadString(sLine))
	{
		if (sLine.Find(TEXT("SLAB NUMBER=")) != -1)
		{
			sSlabNumbers = sLine.Mid(sLine.Find(TEXT("=")) + 1);
			iSlabNumbers = _ttoi(sSlabNumbers);
			m_Grid_Slab.SetRowCount(iSlabNumbers + 1);
			break;
		}
	}

	for (int i = 0; i < iSlabNumbers; i++)
	{
		cFile.ReadString(sLine);
		CSplitStr Split;
		Split.SetData(sLine);
		Split.SetSplitFlag(TEXT(" "));
		CStringArray arrSlabInfo;
		Split.GetSplitStrArray(arrSlabInfo);

		if (arrSlabInfo.GetSize() == iSlabCount)//将arrBeamInfo中的信息填入到网格中
		{
			for (int j = 0; j < arrSlabInfo.GetSize(); j++)
			{
				m_Grid_Slab.SetItemText(i + 1, j, (LPCTSTR)arrSlabInfo.GetAt(j));
			}
		}
		else
		{
			ExpandArray(arrSlabInfo, iSlabCount);
			for (int j = 0; j < arrSlabInfo.GetSize(); j++)
			{
				m_Grid_Slab.SetItemText(i + 1, j, (LPCTSTR)arrSlabInfo.GetAt(j));
			}
		}

		//ComboBox内容的单独设置
		m_Grid_Slab.SetCellType(i + 1, 16, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Slab, i + 1, 16, arrConcMat, arrSlabInfo, 16);
		m_Grid_Slab.SetCellType(i + 1, 17, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Slab, i + 1, 17, arrRebarMat, arrSlabInfo, 17);

	}
	return LRESULT();
}

LRESULT CTabDlg5::OnWriteDate(WPARAM wParam, LPARAM lParam)
{
	CStdioFile cFile;
	CStdioFile cNewFile;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	CString sNewPath = sPath.Left(sPath.ReverseFind('.')) + _T("(new)") + sPath.Mid(sPath.ReverseFind('.'));
	cFile.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	cNewFile.Open(sNewPath, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyNone);
	cFile.SeekToBegin();// 将文件指针指向文件开始处
	cNewFile.SeekToBegin();
	int iSlabCount = m_Grid_Slab.GetColumnCount();
	CString sLine;
	CString sNewLine;
	static int iSlabNumbers = 0;
	static CString sSlabNumbers;
	while (cFile.ReadString(sLine))
	{
		cNewFile.WriteString(sLine + _T("\n"));
		if (sLine.Find(TEXT("SLAB NUMBER=")) != -1)//先定位至COLUMN NUMBER所在行
		{
			sSlabNumbers = sLine.Mid(sLine.Find(TEXT("=")) + 1);
			iSlabNumbers = _ttoi(sSlabNumbers);
			for (int i = 0; i < iSlabNumbers; i++)
			{
				cFile.ReadString(sLine);
				CSplitStr Split;
				Split.SetData(sLine);
				Split.SetSplitFlag(TEXT(" "));
				CStringArray arrSlabInfo;
				Split.GetSplitStrArray(arrSlabInfo);
				CStringArray arrCellText;
				for (int j = 0; j < iSlabCount; j++)
				{
					arrCellText.Add(m_Grid_Slab.GetItemText(i + 1, j));
				}
				//将ComboBox项的内容转换为索引号

				arrCellText.SetAt(16, GetComboBoxIndex(arrCellText, 16));
				arrCellText.SetAt(17, GetComboBoxIndex(arrCellText, 17));

				if (arrCellText.GetSize() == arrSlabInfo.GetSize())//将arrCellText中的信息填入到NewLine进行替换
				{
					for (int k = 0; k < arrCellText.GetSize(); k++)
					{
						sNewLine += arrCellText.GetAt(k);
						sNewLine += TEXT(" ");
					}
				}
				else
				{
					TrimArray(arrCellText, arrSlabInfo);
					for (int k = 0; k < arrCellText.GetSize(); k++)
					{
						sNewLine += arrCellText.GetAt(k);
						sNewLine += TEXT(" ");
					}
				}

				//MessageBox(sNewLine);
				cNewFile.WriteString(sNewLine + _T("\n"));
				sNewLine.Empty();
				arrCellText.RemoveAll();
				arrSlabInfo.RemoveAll();
			}
		}
	}
	cFile.Close();
	cNewFile.Close();
	cFile.Remove(sPath);
	cNewFile.Rename(sNewPath, sPath);
	return LRESULT();
}



