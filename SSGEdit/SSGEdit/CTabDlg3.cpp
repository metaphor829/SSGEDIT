// CTabDlg3.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "afxdialogex.h"
#include "SSGEditDlg.h"
#include "CTabDlg3.h"


// CTabDlg3 对话框

IMPLEMENT_DYNAMIC(CTabDlg3, CDialogEx)

CTabDlg3::CTabDlg3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG3, pParent)
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

CTabDlg3::~CTabDlg3()
{
}

void CTabDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM2, m_Grid_Column);
}


BEGIN_MESSAGE_MAP(CTabDlg3, CDialogEx)
	ON_MESSAGE(NM_A, OnUpDate)
	ON_MESSAGE(NM_D, OnWriteDate)
	ON_MESSAGE(NM_I, OnSearchID)
	ON_MESSAGE(NM_J, OnShowAll)
END_MESSAGE_MAP()


// CTabDlg3 消息处理程序






void CTabDlg3::SetColumnData(Column& column, CDataFile& fin)
{
	column.ID = fin.GetInt();
	column.iPKPM = fin.GetInt();
	column.iLine = fin.GetInt();
	column.iType = fin.GetInt();
	column.iSection = fin.GetInt();
	column.iSubType = fin.GetInt();
	column.bArtiNode1 = fin.GetInt();
	column.bArtiNode2 = fin.GetInt();
	column.iConcMat = fin.GetInt();
	column.iRebarMat = fin.GetInt();
	column.iStirrupMat = fin.GetInt();
	column.iSteelMat = fin.GetInt();
	column.iBottomStory = fin.GetInt();
	column.iStory = fin.GetInt();
	column.iStage = fin.GetInt();
	column.iTower = fin.GetInt();
	column.fRotateAng = fin.GetFloat();
	column.fOffsetX1 = fin.GetFloat();
	column.fOffsetY1 = fin.GetFloat();
	column.fOffsetZ1 = fin.GetFloat();
	column.fOffsetX2 = fin.GetFloat();
	column.fOffsetY2 = fin.GetFloat();
	column.fOffsetZ2 = fin.GetFloat();
	column.fConnerArea = fin.GetFloat();
	column.fBsideArea = fin.GetFloat();
	column.fHsideArea = fin.GetFloat();
	column.fStirrupArea_D = fin.GetFloat();
	column.fStirrupArea_UD = fin.GetFloat();
	column.fForce = fin.GetFloat();
	column.iMidPerformType = fin.GetInt();
	column.iSeverePerformType = fin.GetInt();
	column.iStructType = fin.GetInt();
	column.iMidNormSectPerformObject = fin.GetInt();
	column.iMidDiagSectPerformObject = fin.GetInt();
	column.iRareNormSectPerformObject = fin.GetInt();
	column.iRareDiagSectPerformObject = fin.GetInt();
	column.iParaNumbers = fin.GetInt();
	if (column.iParaNumbers == 8)
	{
		column.fAxisFactor = fin.GetFloat();
		column.fMomentFactor = fin.GetFloat();
		column.fShearFactor = fin.GetFloat();
		column.iAppendMat = fin.GetInt();
		column.iNode1Sec = fin.GetInt();
		column.iNode2Sec = fin.GetInt();
		column.iShearNonlinear = fin.GetInt();
		column.fColumnSpan = fin.GetFloat();
	}
	if (column.iParaNumbers == 9)
	{
		column.fAxisFactor = fin.GetFloat();
		column.fMomentFactor = fin.GetFloat();
		column.fShearFactor = fin.GetFloat();
		column.iAppendMat = fin.GetInt();
		column.iNode1Sec = fin.GetInt();
		column.iNode2Sec = fin.GetInt();
		column.iShearNonlinear = fin.GetInt();
		column.fColumnSpan = fin.GetFloat();
		column.iReinforcedSec = fin.GetInt();
	}
}

void CTabDlg3::GetColumnData(CGridCtrl& m_Grid_Column, int iRow)
{
	vColumn[iRow].ID = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 0));
	vColumn[iRow].iPKPM = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 1));
	vColumn[iRow].iLine = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 2));
	vColumn[iRow].iType = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 3));
	vColumn[iRow].iSection = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 4));
	vColumn[iRow].iSubType = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 5));
	vColumn[iRow].bArtiNode1 = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 6));
	vColumn[iRow].bArtiNode2 = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 7));
	if (m_Grid_Column.GetItemText(iRow + 1, 8) != _T("0"))
	{
		vColumn[iRow].iConcMat = GetComboBoxIndex(m_Grid_Column.GetItemText(iRow + 1, 8));
	}
	else
	{
		vColumn[iRow].iConcMat = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 8));
	}
	if (m_Grid_Column.GetItemText(iRow + 1, 9) != _T("0"))
	{
		vColumn[iRow].iRebarMat = GetComboBoxIndex(m_Grid_Column.GetItemText(iRow + 1, 9));
	}
	else
	{
		vColumn[iRow].iRebarMat = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 9));
	}
	if (m_Grid_Column.GetItemText(iRow + 1, 10) != _T("0"))
	{
		vColumn[iRow].iStirrupMat = GetComboBoxIndex(m_Grid_Column.GetItemText(iRow + 1, 10));
	}
	else
	{
		vColumn[iRow].iStirrupMat = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 10));
	}
	if (m_Grid_Column.GetItemText(iRow + 1, 11) != _T("0"))
	{
		vColumn[iRow].iSteelMat = GetComboBoxIndex(m_Grid_Column.GetItemText(iRow + 1, 11));
	}
	else
	{
		vColumn[iRow].iSteelMat = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 11));
	}
	vColumn[iRow].iBottomStory = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 12));
	vColumn[iRow].iStory = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 13));
	vColumn[iRow].iStage = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 14));
	vColumn[iRow].iTower = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 15));
	vColumn[iRow].fRotateAng = _ttof(m_Grid_Column.GetItemText(iRow + 1, 16));
	vColumn[iRow].fOffsetX1 = _ttof(m_Grid_Column.GetItemText(iRow + 1, 17));
	vColumn[iRow].fOffsetY1 = _ttof(m_Grid_Column.GetItemText(iRow + 1, 18));
	vColumn[iRow].fOffsetZ1 = _ttof(m_Grid_Column.GetItemText(iRow + 1, 19));
	vColumn[iRow].fOffsetX2 = _ttof(m_Grid_Column.GetItemText(iRow + 1, 20));
	vColumn[iRow].fOffsetY2 = _ttof(m_Grid_Column.GetItemText(iRow + 1, 21));
	vColumn[iRow].fOffsetZ2 = _ttof(m_Grid_Column.GetItemText(iRow + 1, 22));
	vColumn[iRow].fConnerArea = _ttof(m_Grid_Column.GetItemText(iRow + 1, 23));
	vColumn[iRow].fBsideArea = _ttof(m_Grid_Column.GetItemText(iRow + 1, 24));
	vColumn[iRow].fHsideArea = _ttof(m_Grid_Column.GetItemText(iRow + 1, 25));
	vColumn[iRow].fStirrupArea_D = _ttof(m_Grid_Column.GetItemText(iRow + 1, 26));
	vColumn[iRow].fStirrupArea_UD = _ttof(m_Grid_Column.GetItemText(iRow + 1, 27));
	vColumn[iRow].fForce = _ttof(m_Grid_Column.GetItemText(iRow + 1, 28));
	vColumn[iRow].iMidPerformType = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 29));
	vColumn[iRow].iSeverePerformType = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 30));
	vColumn[iRow].iStructType = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 31));
	vColumn[iRow].iMidNormSectPerformObject = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 32));
	vColumn[iRow].iMidDiagSectPerformObject = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 33));
	vColumn[iRow].iRareNormSectPerformObject = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 34));
	vColumn[iRow].iRareDiagSectPerformObject = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 35));
	vColumn[iRow].iParaNumbers = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 36));
	if (vColumn[iRow].iParaNumbers == 8)
	{
		vColumn[iRow].fAxisFactor = _ttof(m_Grid_Column.GetItemText(iRow + 1, 37));
		vColumn[iRow].fMomentFactor = _ttof(m_Grid_Column.GetItemText(iRow + 1, 38));
		vColumn[iRow].fShearFactor = _ttof(m_Grid_Column.GetItemText(iRow + 1, 39));
		vColumn[iRow].iAppendMat = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 40));
		vColumn[iRow].iNode1Sec = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 41));
		vColumn[iRow].iNode2Sec = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 42));
		vColumn[iRow].iShearNonlinear = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 43));
		vColumn[iRow].fColumnSpan = _ttof(m_Grid_Column.GetItemText(iRow + 1, 44));
	}
	if (vColumn[iRow].iParaNumbers == 9)
	{
		vColumn[iRow].fAxisFactor = _ttof(m_Grid_Column.GetItemText(iRow + 1, 37));
		vColumn[iRow].fMomentFactor = _ttof(m_Grid_Column.GetItemText(iRow + 1, 38));
		vColumn[iRow].fShearFactor = _ttof(m_Grid_Column.GetItemText(iRow + 1, 39));
		vColumn[iRow].iAppendMat = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 40));
		vColumn[iRow].iNode1Sec = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 41));
		vColumn[iRow].iNode2Sec = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 42));
		vColumn[iRow].iShearNonlinear = _ttoi(m_Grid_Column.GetItemText(iRow + 1, 43));
		vColumn[iRow].fColumnSpan = _ttof(m_Grid_Column.GetItemText(iRow + 1, 44));
		vColumn[iRow].iReinforcedSec = _ttof(m_Grid_Column.GetItemText(iRow + 1, 45));
	}
}

void CTabDlg3::WriteColumnData(int iRow, CString& sNewLine)
{
	char temp[512];
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].ID);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iPKPM);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iLine);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iSection);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iSubType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].bArtiNode1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].bArtiNode2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iConcMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iRebarMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iStirrupMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iSteelMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iBottomStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iStage);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iTower);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fRotateAng);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fOffsetX1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fOffsetY1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fOffsetZ1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fOffsetX2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fOffsetY2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fOffsetZ2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fConnerArea);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fBsideArea);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fHsideArea);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fStirrupArea_D);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fStirrupArea_UD);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fForce);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iMidPerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iSeverePerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iStructType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iMidNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iMidDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iRareNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iRareDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iParaNumbers);
	sNewLine += temp;
	if (vColumn[iRow].iParaNumbers == 8) {
		sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fAxisFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fMomentFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fShearFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iAppendMat);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iNode1Sec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iNode2Sec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iShearNonlinear);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fColumnSpan);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "0 0 0 0 0");
		sNewLine += temp;
	}
	if (vColumn[iRow].iParaNumbers == 9) {
		sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fAxisFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fMomentFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fShearFactor);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iAppendMat);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iNode1Sec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iNode2Sec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iShearNonlinear);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%g ", vColumn[iRow].fColumnSpan);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "%d ", vColumn[iRow].iReinforcedSec);
		sNewLine += temp;
		sprintf_s(temp, sizeof(temp), "0 0 0 0 0");
		sNewLine += temp;
	}
}

void CTabDlg3::SetGridItemText(int iRow, int iColCount, CGridCtrl& m_Grid_Column, CDataFile& fin, Column& column)
{
	for (int j = 0; j < iColCount; j++)
	{
		if (j <=44)
		{
			m_Grid_Column.SetItemText(iRow + 1, j, (LPCTSTR)fin.arrInfo[j]);
		}
		if (column.iParaNumbers == 9 && j == 45)
		{
			m_Grid_Column.SetItemText(iRow + 1, 45, (LPCTSTR)fin.arrInfo[45]);
		}
	}
	fin.arrInfo.RemoveAll();
	//ComboBox内容的单独设置
	if (column.iConcMat != 0) {
		m_Grid_Column.SetCellType(iRow + 1, 8, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Column, iRow + 1, 8, arrConcMat, column.iConcMat);
	}
	if (column.iRebarMat != 0)
	{
		m_Grid_Column.SetCellType(iRow + 1, 9, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Column, iRow + 1, 9, arrRebarMat, column.iRebarMat);
	}
	if (column.iStirrupMat != 0)
	{
		m_Grid_Column.SetCellType(iRow + 1, 10, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Column, iRow + 1, 10, arrRebarMat, column.iStirrupMat);
	}
	if (column.iSteelMat != 0)
	{
		m_Grid_Column.SetCellType(iRow + 1, 11, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Column, iRow + 1, 11, arrRebarMat, column.iSteelMat);
	}
}

int CTabDlg3::GetComboBoxIndex(CString sMat)
{
	for (int i = 0; i < arrConcMat.GetSize(); i++)
	{
		if (arrConcMat.GetAt(i) == sMat)
		{
			return i + 1;
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

void CTabDlg3::SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat)
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

BOOL CTabDlg3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Column.GetClientRect(&cr);
	m_Grid_Column.SetColumnCount(46);//设置列数
	m_Grid_Column.SetFixedRowCount(1);//设置表头
	m_Grid_Column.SetItemText(0, 0, _T("ID"));
	m_Grid_Column.SetItemText(0, 1, _T("PKPM结构线编号"));
	m_Grid_Column.SetItemText(0, 2, _T("结构线编号"));
	m_Grid_Column.SetItemText(0, 3, _T("对象类型"));
	m_Grid_Column.SetItemText(0, 4, _T("截面类型"));
	m_Grid_Column.SetItemText(0, 5, _T("子类型"));
	m_Grid_Column.SetItemText(0, 6, _T("柱1端连接形式"));
	m_Grid_Column.SetItemText(0, 7, _T("柱2端连接形式"));
	m_Grid_Column.SetItemText(0, 8, _T("混凝土强度等级"));
	m_Grid_Column.SetItemText(0, 9, _T("钢筋级别"));
	m_Grid_Column.SetItemText(0, 10, _T("箍筋级别"));
	m_Grid_Column.SetItemText(0, 11, _T("钢材型号"));
	m_Grid_Column.SetItemText(0, 12, _T("底部楼层"));
	m_Grid_Column.SetItemText(0, 13, _T("楼层"));
	m_Grid_Column.SetItemText(0, 14, _T("施工阶段"));
	m_Grid_Column.SetItemText(0, 15, _T("塔号"));
	m_Grid_Column.SetItemText(0, 16, _T("方向角（度）"));
	m_Grid_Column.SetItemText(0, 17, _T("1点X方向偏移"));
	m_Grid_Column.SetItemText(0, 18, _T("1点Y方向偏移"));
	m_Grid_Column.SetItemText(0, 19, _T("1点Z方向偏移"));
	m_Grid_Column.SetItemText(0, 20, _T("2点X方向偏移"));
	m_Grid_Column.SetItemText(0, 21, _T("2点Y方向偏移"));
	m_Grid_Column.SetItemText(0, 22, _T("2点Z方向偏移"));
	m_Grid_Column.SetItemText(0, 23, _T("角筋面积"));
	m_Grid_Column.SetItemText(0, 24, _T("B方向单边配筋面积"));
	m_Grid_Column.SetItemText(0, 25, _T("H方向单边配筋面积"));
	m_Grid_Column.SetItemText(0, 26, _T("加密区箍筋面积"));
	m_Grid_Column.SetItemText(0, 27, _T("非加密区箍筋面积"));
	m_Grid_Column.SetItemText(0, 28, _T("荷载"));
	m_Grid_Column.SetItemText(0, 29, _T("中震本构"));
	m_Grid_Column.SetItemText(0, 30, _T("大震本构"));
	m_Grid_Column.SetItemText(0, 31, _T("重要性分类"));
	m_Grid_Column.SetItemText(0, 32, _T("中震正截面性能"));
	m_Grid_Column.SetItemText(0, 33, _T("中震斜截面性能"));
	m_Grid_Column.SetItemText(0, 34, _T("大震正截面性能"));
	m_Grid_Column.SetItemText(0, 35, _T("大震斜截面性能"));
	m_Grid_Column.SetItemText(0, 36, _T("性能化参数个数"));
	m_Grid_Column.SetItemText(0, 37, _T("轴力内力调整系数"));
	m_Grid_Column.SetItemText(0, 38, _T("弯矩内力调整系数"));
	m_Grid_Column.SetItemText(0, 39, _T("剪力内力调整系数"));
	m_Grid_Column.SetItemText(0, 40, _T("附加材料"));
	m_Grid_Column.SetItemText(0, 41, _T("1端半刚性属性"));
	m_Grid_Column.SetItemText(0, 42, _T("2端半刚性属性"));
	m_Grid_Column.SetItemText(0, 43, _T("剪切属性"));
	m_Grid_Column.SetItemText(0, 44, _T("构件跨度"));
	m_Grid_Column.SetItemText(0, 45, _T("附加加固截面"));
	
	//设置列宽，并将部分列隐藏
	for (int i = 0; i < 46; i++)
	{
		m_Grid_Column.SetColumnWidth(i, 60);
	}
	m_Grid_Column.SetColumnWidth(1, 0);
	m_Grid_Column.SetColumnWidth(12, 0);
	m_Grid_Column.SetColumnWidth(28, 0);
	m_Grid_Column.SetColumnWidth(36, 0);
	m_Grid_Column.SetColumnWidth(45, 0);
	m_Grid_Column.EnableHiddenColUnhide(FALSE);

	return TRUE;// TODO:  在此添加额外的初始化
	
	// return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

LRESULT CTabDlg3::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	CDataFile fin;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	fin.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	fin.SeekToBegin();
	CString sLine;
	int iColCount = m_Grid_Column.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		if (sLine.Find(TEXT("COLUMN NUMBER=")) != -1)
		{
			iRowCount = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			m_Grid_Column.SetRowCount(iRowCount + 1);
			break;
		}
	}
	for (int i = 0; i < iRowCount; i++)
	{
		fin.ReadString(sLine);
		fin.SetData(sLine);
		Column column;
		SetColumnData(column, fin);
		vColumn.push_back(column);
		SetGridItemText(i, iColCount, m_Grid_Column, fin, column);
		for (int j = 0; j < 4; j++)
		{
			m_Grid_Column.SetItemState(i + 1, j, GVIS_READONLY);
		}
	}
	return LRESULT();
}

LRESULT CTabDlg3::OnWriteDate(WPARAM wParam, LPARAM lParam)
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
	int iColCount = m_Grid_Column.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		fout.WriteString(sLine + _T("\n"));
		if (sLine.Find(TEXT("COLUMN NUMBER=")) != -1)//先定位
		{
			for (int i = 0; i < iRowCount; i++)
			{
				fin.ReadString(sLine);
				GetColumnData(m_Grid_Column, i);
				WriteColumnData(i, sNewLine);
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
	return LRESULT();
}

LRESULT CTabDlg3::OnSearchID(WPARAM wParam, LPARAM lParam)
{
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	int ID = _ttoi(pParent->m_ID);//从父窗口得到ID序号
	if (ID != 0 && ID <= iRowCount)
	{
		for (int i = 1; i < iRowCount + 1; i++)
		{
			if (i != ID)
			{
				m_Grid_Column.SetRowHeight(i, 0);
			}
		}
	}
	else
	{
		MessageBox(TEXT("请输入列表内的ID序号进行搜索"));
	}
	return LRESULT();
}

LRESULT CTabDlg3::OnShowAll(WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < iRowCount + 1; i++)
	{
		m_Grid_Column.SetRowHeight(i, 25);
	}
	return LRESULT();
}
