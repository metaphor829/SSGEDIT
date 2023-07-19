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
	arrSteelMat.SetSize(20);
	arrSteelMat.SetAt(0, TEXT("Q235"));
	arrSteelMat.SetAt(1, TEXT("Q345"));
	arrSteelMat.SetAt(2, TEXT("Q390"));
	arrSteelMat.SetAt(3, TEXT("Q420"));
	arrSteelMat.SetAt(4, TEXT("Q460"));
	arrSteelMat.SetAt(5, TEXT("Q500"));
	arrSteelMat.SetAt(6, TEXT("Q550"));
	arrSteelMat.SetAt(7, TEXT("Q620"));
	arrSteelMat.SetAt(8, TEXT("Q690"));
	arrSteelMat.SetAt(9, TEXT("Q235GJ"));
	arrSteelMat.SetAt(10, TEXT("Q345GJ"));
	arrSteelMat.SetAt(11, TEXT("Q390GJ"));
	arrSteelMat.SetAt(12, TEXT("Q420GJ"));
	arrSteelMat.SetAt(13, TEXT("Q460GJ"));
	arrSteelMat.SetAt(14, TEXT("Q355"));
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
	ON_MESSAGE(NM_I, OnSearchID)
	ON_MESSAGE(NM_J, OnShowAll)
END_MESSAGE_MAP()

// CTabDlg5 消息处理程序


void CTabDlg5::SetSlabData(Slab& slab, CDataFile& fin)
{
	slab.ID = fin.GetInt();
	slab.iPKPM = fin.GetInt();
	slab.nLine = fin.GetInt();
	for (int i = 0; i < slab.nLine; i++)
	{
		slab.iNode[i] = fin.GetInt();
	}
	slab.iType = fin.GetInt();
	slab.iSection = fin.GetInt();
	slab.iSubType = fin.GetInt();
	slab.nRebarLayer = fin.GetInt();
	slab.iConcMat = fin.GetInt();
	slab.iRebarMat = fin.GetInt();
	slab.iSteelMat = fin.GetInt();
	slab.iStory = fin.GetInt();
	slab.iStage = fin.GetInt();
	slab.iTower = fin.GetInt();
	slab.fF1 = fin.GetFloat();
	slab.fF2 = fin.GetFloat();
	slab.fOffset = fin.GetFloat();
	slab.fRebarRatio1 = fin.GetFloat();
	slab.fAngle1 = fin.GetFloat();
	slab.fRebarRatio2 = fin.GetFloat();
	slab.fAngle2 = fin.GetFloat();
	slab.iMidPerformType = fin.GetInt();
	slab.iSeverePerformType = fin.GetInt();
	slab.iStructType = fin.GetInt();
	slab.iMidNormSectPerformObject = fin.GetInt();
	slab.iMidDiagSectPerformObject = fin.GetInt();
	slab.iRareNormSectPerformObject = fin.GetInt();
	slab.iRareDiagSectPerformObject = fin.GetInt();
	slab.iParaNumbers = fin.GetInt();
	slab.fAxisFactor = fin.GetFloat();
	slab.fMomentFactor = fin.GetFloat();
	slab.fShearFactor = fin.GetFloat();
}

void CTabDlg5::GetSlabData(CGridCtrl& m_Grid_Slab, int iRow)
{
	vSlab[iRow].ID = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 0));
	vSlab[iRow].iPKPM = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 1));
	vSlab[iRow].nLine = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 2));
	vSlab[iRow].iNode[0] = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 3));
	vSlab[iRow].iNode[1] = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 4));
	vSlab[iRow].iNode[2] = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 5));
	vSlab[iRow].iNode[3] = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 6));
	vSlab[iRow].iNode[4] = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 7));
	vSlab[iRow].iNode[5] = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 8));
	vSlab[iRow].iType = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 9));
	vSlab[iRow].iSection = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 10));
	vSlab[iRow].iSubType = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 11));
	vSlab[iRow].nRebarLayer = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 12));
	if (m_Grid_Slab.GetItemText(iRow + 1, 13) != _T("0"))//ComboBox需转换为序号
	{
		vSlab[iRow].iConcMat = GetComboBoxIndex(m_Grid_Slab.GetItemText(iRow + 1, 13));
	}
	else
	{
		vSlab[iRow].iConcMat = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 13));
	}
	if (m_Grid_Slab.GetItemText(iRow + 1, 14) != _T("0"))//ComboBox需转换为序号
	{
		vSlab[iRow].iRebarMat = GetComboBoxIndex(m_Grid_Slab.GetItemText(iRow + 1, 14));
	}
	else
	{
		vSlab[iRow].iRebarMat = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 14));
	}
	if (m_Grid_Slab.GetItemText(iRow + 1, 15) != _T("0"))//ComboBox需转换为序号
	{
		vSlab[iRow].iSteelMat = GetComboBoxIndex(m_Grid_Slab.GetItemText(iRow + 1, 15));
	}
	else
	{
		vSlab[iRow].iSteelMat = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 15));
	}
	vSlab[iRow].iStory = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 16));
	vSlab[iRow].iStage = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 17));
	vSlab[iRow].iTower = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 18));
	vSlab[iRow].fF1 = _ttof(m_Grid_Slab.GetItemText(iRow + 1, 19));
	vSlab[iRow].fF2 = _ttof(m_Grid_Slab.GetItemText(iRow + 1, 20));
	vSlab[iRow].fOffset = _ttof(m_Grid_Slab.GetItemText(iRow + 1, 21));
	vSlab[iRow].fRebarRatio1 = _ttof(m_Grid_Slab.GetItemText(iRow + 1, 22));
	vSlab[iRow].fAngle1 = _ttof(m_Grid_Slab.GetItemText(iRow + 1, 23));
	vSlab[iRow].fRebarRatio2 = _ttof(m_Grid_Slab.GetItemText(iRow + 1, 24));
	vSlab[iRow].fAngle2 = _ttof(m_Grid_Slab.GetItemText(iRow + 1, 25));
	vSlab[iRow].iMidPerformType = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 26));
	vSlab[iRow].iSeverePerformType = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 27));
	vSlab[iRow].iStructType = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 28));
	vSlab[iRow].iMidNormSectPerformObject = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 29));
	vSlab[iRow].iMidDiagSectPerformObject = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 30));
	vSlab[iRow].iRareNormSectPerformObject = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 31));
	vSlab[iRow].iRareDiagSectPerformObject = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 32));
	vSlab[iRow].iParaNumbers = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 33));
	vSlab[iRow].fAxisFactor = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 34));
	vSlab[iRow].fMomentFactor = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 35));
	vSlab[iRow].fShearFactor = _ttoi(m_Grid_Slab.GetItemText(iRow + 1, 36));
}

void CTabDlg5::WriteSlabData(int iRow, CString& sNewLine)
{

	char temp[512];
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].ID);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iPKPM);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].nLine);
	sNewLine += temp;
	for (int i = 0; i < vSlab[iRow].nLine; i++)
	{
		sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iNode[i]);
		sNewLine += temp;
	}
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iSection);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iSubType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].nRebarLayer);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iConcMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iRebarMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iSteelMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iStage);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iTower);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fF1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fF2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fOffset);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fRebarRatio1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fAngle1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fRebarRatio2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fAngle2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iMidPerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iSeverePerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iMidNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iMidDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iRareNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iRareDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vSlab[iRow].iParaNumbers);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fAxisFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fMomentFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vSlab[iRow].fShearFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "0 0 0 0 0");
	sNewLine += temp;

	
}

void CTabDlg5::SetGridItemText(int iRow, int iColCount, CGridCtrl& m_Grid_Slab, CDataFile& fin, Slab& slab)
{
	for (int j = 0; j < iColCount; j++)
	{

		if (j < (slab.nLine + 3) && j < 9)
		{
			m_Grid_Slab.SetItemText(iRow + 1, j, (LPCTSTR)fin.arrInfo[j]);
		}
		if (j >= 9)
		{
			m_Grid_Slab.SetItemText(iRow + 1, j, (LPCTSTR)fin.arrInfo[(j - (6 - slab.nLine))]);
		}
	}
	fin.arrInfo.RemoveAll();

	//ComboBox内容的单独设置
	if (slab.iConcMat != 0) 
	{
		m_Grid_Slab.SetCellType(iRow + 1, 13, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Slab, iRow + 1, 13, arrConcMat, slab.iConcMat);
	}
	if (slab.iRebarMat != 0) 
	{
		m_Grid_Slab.SetCellType(iRow + 1, 14, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Slab, iRow + 1, 14, arrRebarMat, slab.iRebarMat);
	}
	if (slab.iSteelMat != 0)
	{
		m_Grid_Slab.SetCellType(iRow + 1, 15, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Slab, iRow + 1, 15, arrRebarMat, slab.iSteelMat);
	}
	
}

int CTabDlg5::GetComboBoxIndex(CString sMat)
{
	for (int i = 0; i < arrConcMat.GetSize(); i++)
	{
		if (arrConcMat.GetAt(i) == sMat)
		{
			return i+1;
		}
	}
	for (int i = 0; i < arrRebarMat.GetSize(); i++)
	{
		if (arrRebarMat.GetAt(i) == sMat)
		{
			return i + 101;
		}
	}
	for (int i = 0; i < arrSteelMat.GetSize(); i++)
	{
		if (arrSteelMat.GetAt(i) == sMat)
		{
			return i + 201;
		}
	}
}

void CTabDlg5::SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat)
{
	CGridCellCombo* pCell = (CGridCellCombo*)m_Grid.GetCell(nRow, nCol);
	pCell->SetOptions(arrText);
	if (iMat < 100)
	{
		pCell->SetText(arrText.GetAt(iMat));
	}
	else if (iMat < 200)
	{
		pCell->SetText(arrText.GetAt((iMat - 101)));
	}
	else if (iMat < 300)
	{
		pCell->SetText(arrText.GetAt((iMat - 201)));
	}
}

BOOL CTabDlg5::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Slab.GetClientRect(&cr);
	m_Grid_Slab.SetColumnCount(37);//设置列数
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
	m_Grid_Slab.SetItemText(0, 9, _T("对象类型"));
	m_Grid_Slab.SetItemText(0, 10, _T("截面类型"));
	m_Grid_Slab.SetItemText(0, 11, _T("子截面类型"));
	m_Grid_Slab.SetItemText(0, 12, _T("钢筋层数"));
	m_Grid_Slab.SetItemText(0, 13, _T("混凝土材料等级"));
	m_Grid_Slab.SetItemText(0, 14, _T("钢筋等级"));
	m_Grid_Slab.SetItemText(0, 15, _T("钢材等级"));
	m_Grid_Slab.SetItemText(0, 16, _T("楼层"));
	m_Grid_Slab.SetItemText(0, 17, _T("施工阶段"));
	m_Grid_Slab.SetItemText(0, 18, _T("塔号"));
	m_Grid_Slab.SetItemText(0, 19, _T("F1"));
	m_Grid_Slab.SetItemText(0, 20, _T("F2"));
	m_Grid_Slab.SetItemText(0, 21, _T("偏移值"));
	m_Grid_Slab.SetItemText(0, 22, _T("面筋单向配筋率"));
	m_Grid_Slab.SetItemText(0, 23, _T("水平筋方向角"));
	m_Grid_Slab.SetItemText(0, 24, _T("底筋单向配筋率"));
	m_Grid_Slab.SetItemText(0, 25, _T("竖向筋方向角"));
	m_Grid_Slab.SetItemText(0, 26, _T("中震本构"));
	m_Grid_Slab.SetItemText(0, 27, _T("大震本构"));
	m_Grid_Slab.SetItemText(0, 28, _T("重要性分类"));
	m_Grid_Slab.SetItemText(0, 29, _T("中震正截面性能"));
	m_Grid_Slab.SetItemText(0, 30, _T("中震斜截面性能"));
	m_Grid_Slab.SetItemText(0, 31, _T("大震正截面性能"));
	m_Grid_Slab.SetItemText(0, 32, _T("大震斜截面性能"));
	m_Grid_Slab.SetItemText(0, 33, _T("3"));
	m_Grid_Slab.SetItemText(0, 34, _T("轴力内力调整系数"));
	m_Grid_Slab.SetItemText(0, 35, _T("弯矩内力调整系数"));
	m_Grid_Slab.SetItemText(0, 36, _T("剪力内力调整系数"));
	// TODO:  在此添加额外的初始化
	//设置列宽，并将部分列隐藏
	for (int i = 0; i <37; i++)
	{
		m_Grid_Slab.SetColumnWidth(i, 60);
	}
	m_Grid_Slab.SetColumnWidth(1, 0);
	m_Grid_Slab.SetColumnWidth(33, 0);
	m_Grid_Slab.EnableHiddenColUnhide(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



LRESULT CTabDlg5::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	
	CDataFile fin;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	fin.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	fin.SeekToBegin();
	CString sLine;
	int iColCount = m_Grid_Slab.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		if (sLine.Find(TEXT("SLAB NUMBER=")) != -1)
		{
			iRowCount = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			m_Grid_Slab.SetRowCount(iRowCount + 1);
			//MessageBox(TEXT("ok"));
			break;
		}
	}
	for (int i = 0; i < iRowCount; i++)
	{
		fin.ReadString(sLine);
		fin.SetData(sLine);
		Slab slab;
		SetSlabData(slab,fin);
		vSlab.push_back(slab);
		SetGridItemText(i, iColCount, m_Grid_Slab, fin, slab);
		for (int j = 0; j < 10; j++)
		{
			m_Grid_Slab.SetItemState(i + 1, j, GVIS_READONLY);
		}

	}
	return LRESULT();
}

LRESULT CTabDlg5::OnWriteDate(WPARAM wParam, LPARAM lParam)
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
	int iColCount = m_Grid_Slab.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		fout.WriteString(sLine + _T("\n"));
		if (sLine.Find(TEXT("SLAB NUMBER=")) != -1)//先定位
		{
			for (int i = 0; i < iRowCount; i++)
			{
				fin.ReadString(sLine);

				GetSlabData(m_Grid_Slab, i);
				WriteSlabData(i, sNewLine);
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

LRESULT CTabDlg5::OnSearchID(WPARAM wParam, LPARAM lParam)
{
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	int ID = _ttoi(pParent->m_ID);//从父窗口得到ID序号
	if (ID != 0 && ID <= iRowCount)
	{
		for (int i = 1; i < iRowCount + 1; i++)
		{
			if (i != ID)
			{
				m_Grid_Slab.SetRowHeight(i, 0);
			}
		}
	}
	else
	{
		MessageBox(TEXT("请输入列表内的ID序号进行搜索"));
	}
	return LRESULT();
}

LRESULT CTabDlg5::OnShowAll(WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < iRowCount + 1; i++)
	{
		m_Grid_Slab.SetRowHeight(i, 25);
	}
	return LRESULT();
}



