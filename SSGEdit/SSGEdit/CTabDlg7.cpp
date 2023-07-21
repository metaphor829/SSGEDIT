// CTabDlg7.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "afxdialogex.h"
#include "SSGEditDlg.h"
#include "CTabDlg7.h"


// CTabDlg7 对话框

IMPLEMENT_DYNAMIC(CTabDlg7, CDialogEx)

CTabDlg7::CTabDlg7(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG7, pParent)
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

CTabDlg7::~CTabDlg7()
{
}

void CTabDlg7::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM6, m_Grid_Brace);
}


BEGIN_MESSAGE_MAP(CTabDlg7, CDialogEx)
	ON_MESSAGE(NM_A, OnUpDate)
	ON_MESSAGE(NM_H, OnWriteDate)
	ON_MESSAGE(NM_I, OnSearchID)
	ON_MESSAGE(NM_J, OnShowAll)
END_MESSAGE_MAP()


// CTabDlg7 消息处理程序


void CTabDlg7::SetBraceData(Brace& Brace, CDataFile& fin)
{
	Brace.ID = fin.GetInt();
	Brace.iPKPM = fin.GetInt();
	Brace.iLine = fin.GetInt();
	Brace.iType = fin.GetInt();
	Brace.iSection = fin.GetInt();
	Brace.iSubType = fin.GetInt();
	Brace.bArtiNode1 = fin.GetInt();
	Brace.bArtiNode2 = fin.GetInt();
	Brace.iConcMat = fin.GetInt();
	Brace.iRebarMat = fin.GetInt();
	Brace.iStirrupMat = fin.GetInt();
	Brace.iSteelMat = fin.GetInt();
	Brace.iBottomStory = fin.GetInt();
	Brace.iStory = fin.GetInt();
	Brace.iStage = fin.GetInt();
	Brace.iTower = fin.GetInt();
	Brace.fRotateAng = fin.GetFloat();
	Brace.fOffsetX1 = fin.GetFloat();
	Brace.fOffsetY1 = fin.GetFloat();
	Brace.fOffsetZ1 = fin.GetFloat();
	Brace.fOffsetX2 = fin.GetFloat();
	Brace.fOffsetY2 = fin.GetFloat();
	Brace.fOffsetZ2 = fin.GetFloat();
	Brace.fConnerArea = fin.GetFloat();
	Brace.fBsideArea = fin.GetFloat();
	Brace.fHsideArea = fin.GetFloat();
	Brace.fStirrupArea_D = fin.GetFloat();
	Brace.fStirrupArea_UD = fin.GetFloat();
	Brace.iMidPerformType = fin.GetInt();
	Brace.iSeverePerformType = fin.GetInt();
	Brace.iStructType = fin.GetInt();
	Brace.iMidNormSectPerformObject = fin.GetInt();
	Brace.iMidDiagSectPerformObject = fin.GetInt();
	Brace.iRareNormSectPerformObject = fin.GetInt();
	Brace.iRareDiagSectPerformObject = fin.GetInt();
	Brace.iParaNumbers = fin.GetInt();
	Brace.fAxisFactor = fin.GetFloat();
	Brace.fMomentFactor = fin.GetFloat();
	Brace.fShearFactor = fin.GetFloat();
	Brace.iAppendMat = fin.GetInt();
	Brace.iNode1Sec = fin.GetInt();
	Brace.iNode2Sec = fin.GetInt();
	Brace.iShearNonlinear = fin.GetInt();
	Brace.fBraceSpan = fin.GetFloat();
	if (Brace.iParaNumbers == 9)
	{
		Brace.iReinforcedSec = fin.GetInt();
	}
}

void CTabDlg7::GetBraceData(CGridCtrl& m_Grid_Brace, int iRow)
{
	vBrace[iRow].ID = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 0));
	vBrace[iRow].iPKPM = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 1));
	vBrace[iRow].iLine = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 2));
	vBrace[iRow].iType = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 3));
	vBrace[iRow].iSection = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 4));
	vBrace[iRow].iSubType = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 5));
	vBrace[iRow].bArtiNode1 = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 6));
	vBrace[iRow].bArtiNode2 = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 7));
	if (m_Grid_Brace.GetItemText(iRow + 1, 8) != _T("0"))
	{
		vBrace[iRow].iConcMat = GetComboBoxIndex(m_Grid_Brace.GetItemText(iRow + 1, 8));
	}
	else
	{
		vBrace[iRow].iConcMat = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 8));
	}
	if (m_Grid_Brace.GetItemText(iRow + 1, 9) != _T("0"))
	{
		vBrace[iRow].iRebarMat = GetComboBoxIndex(m_Grid_Brace.GetItemText(iRow + 1, 9));
	}
	else
	{
		vBrace[iRow].iRebarMat = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 9));
	}
	if (m_Grid_Brace.GetItemText(iRow + 1, 10) != _T("0"))
	{
		vBrace[iRow].iStirrupMat = GetComboBoxIndex(m_Grid_Brace.GetItemText(iRow + 1, 10));
	}
	else
	{
		vBrace[iRow].iStirrupMat = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 10));
	}
	if (m_Grid_Brace.GetItemText(iRow + 1, 11) != _T("0"))
	{
		vBrace[iRow].iSteelMat = GetComboBoxIndex(m_Grid_Brace.GetItemText(iRow + 1, 11));
	}
	else
	{
		vBrace[iRow].iSteelMat = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 11));
	}
	vBrace[iRow].iBottomStory = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 12));
	vBrace[iRow].iStory = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 13));
	vBrace[iRow].iStage = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 14));
	vBrace[iRow].iTower = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 15));
	vBrace[iRow].fRotateAng = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 16));
	vBrace[iRow].fOffsetX1 = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 17));
	vBrace[iRow].fOffsetY1 = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 18));
	vBrace[iRow].fOffsetZ1 = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 19));
	vBrace[iRow].fOffsetX2 = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 20));
	vBrace[iRow].fOffsetY2 = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 21));
	vBrace[iRow].fOffsetZ2 = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 22));
	vBrace[iRow].fConnerArea = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 23));
	vBrace[iRow].fBsideArea = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 24));
	vBrace[iRow].fHsideArea = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 25));
	vBrace[iRow].fStirrupArea_D = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 26));
	vBrace[iRow].fStirrupArea_UD = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 27));
	vBrace[iRow].iMidPerformType = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 28));
	vBrace[iRow].iSeverePerformType = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 29));
	vBrace[iRow].iStructType = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 30));
	vBrace[iRow].iMidNormSectPerformObject = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 31));
	vBrace[iRow].iMidDiagSectPerformObject = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 32));
	vBrace[iRow].iRareNormSectPerformObject = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 33));
	vBrace[iRow].iRareDiagSectPerformObject = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 34));
	vBrace[iRow].iParaNumbers = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 35));
	vBrace[iRow].fAxisFactor = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 36));
	vBrace[iRow].fMomentFactor = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 37));
	vBrace[iRow].fShearFactor = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 38));
	vBrace[iRow].iAppendMat = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 39));
	vBrace[iRow].iNode1Sec = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 40));
	vBrace[iRow].iNode2Sec = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 41));
	vBrace[iRow].iShearNonlinear = _ttoi(m_Grid_Brace.GetItemText(iRow + 1, 42));
	vBrace[iRow].fBraceSpan = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 43));
	if (vBrace[iRow].iParaNumbers == 9)
	{
		vBrace[iRow].iReinforcedSec = _ttof(m_Grid_Brace.GetItemText(iRow + 1, 44));
	}
}

void CTabDlg7::WriteBraceData(int iRow, CString& sNewLine)
{
	char temp[512];
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].ID);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iPKPM);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iLine);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iSection);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iSubType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].bArtiNode1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].bArtiNode2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iConcMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iRebarMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iStirrupMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iSteelMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iBottomStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iStage);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iTower);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fRotateAng);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fOffsetX1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fOffsetY1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fOffsetZ1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fOffsetX2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fOffsetY2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fOffsetZ2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fConnerArea);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fBsideArea);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fHsideArea);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fStirrupArea_D);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fStirrupArea_UD);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iMidPerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iSeverePerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iStructType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iMidNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iMidDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iRareNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iRareDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iParaNumbers);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fAxisFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fMomentFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fShearFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iAppendMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iNode1Sec);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iNode2Sec);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iShearNonlinear);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vBrace[iRow].fBraceSpan);
	sNewLine += temp;
	if (vBrace[iRow].iParaNumbers == 9) {
		
		sprintf_s(temp, sizeof(temp), "%d ", vBrace[iRow].iReinforcedSec);
		sNewLine += temp;
	}
	sprintf_s(temp, sizeof(temp), "0 0 0 0 0");
	sNewLine += temp;
}


void CTabDlg7::SetGridItemText(int iRow,CGridCtrl& m_Grid_Brace,Brace& brace)
{
	CString temp;
	temp.Format(_T("%d"), brace.ID);
	m_Grid_Brace.SetItemText(iRow + 1, 0, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iPKPM);
	m_Grid_Brace.SetItemText(iRow + 1, 1, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iLine);
	m_Grid_Brace.SetItemText(iRow + 1, 2, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iType);
	m_Grid_Brace.SetItemText(iRow + 1, 3, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iSection);
	m_Grid_Brace.SetItemText(iRow + 1, 4, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iSubType);
	m_Grid_Brace.SetItemText(iRow + 1, 5, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.bArtiNode1);
	m_Grid_Brace.SetItemText(iRow + 1, 6, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.bArtiNode2);
	m_Grid_Brace.SetItemText(iRow + 1, 7, (LPCTSTR)temp);
	if (brace.iConcMat != 0) {
		m_Grid_Brace.SetCellType(iRow + 1, 8, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Brace, iRow + 1, 8, arrConcMat, brace.iConcMat);
	}
	else
	{
		temp.Format(_T("%d"), brace.iConcMat);
		m_Grid_Brace.SetItemText(iRow + 1, 8, (LPCTSTR)temp);
	}
	if (brace.iRebarMat != 0)
	{
		m_Grid_Brace.SetCellType(iRow + 1, 9, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Brace, iRow + 1, 9, arrRebarMat, brace.iRebarMat);
	}
	else
	{
		temp.Format(_T("%d"), brace.iRebarMat);
		m_Grid_Brace.SetItemText(iRow + 1, 9, (LPCTSTR)temp);
	}
	if (brace.iStirrupMat != 0)
	{
		m_Grid_Brace.SetCellType(iRow + 1, 10, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Brace, iRow + 1, 10, arrRebarMat, brace.iStirrupMat);
	}
	else
	{
		temp.Format(_T("%d"), brace.iStirrupMat);
		m_Grid_Brace.SetItemText(iRow + 1, 10, (LPCTSTR)temp);
	}
	if (brace.iSteelMat != 0)
	{
		m_Grid_Brace.SetCellType(iRow + 1, 11, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Brace, iRow + 1, 11, arrRebarMat, brace.iSteelMat);
	}
	else
	{
		temp.Format(_T("%d"), brace.iSteelMat);
		m_Grid_Brace.SetItemText(iRow + 1, 11, (LPCTSTR)temp);
	}
	temp.Format(_T("%d"), brace.iBottomStory);
	m_Grid_Brace.SetItemText(iRow + 1, 12, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iStory);
	m_Grid_Brace.SetItemText(iRow + 1, 13, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iStage);
	m_Grid_Brace.SetItemText(iRow + 1, 14, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iTower);
	m_Grid_Brace.SetItemText(iRow + 1, 15, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fRotateAng);
	m_Grid_Brace.SetItemText(iRow + 1, 16, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fOffsetX1);
	m_Grid_Brace.SetItemText(iRow + 1, 17, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fOffsetY1);
	m_Grid_Brace.SetItemText(iRow + 1, 18, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fOffsetZ1);
	m_Grid_Brace.SetItemText(iRow + 1, 19, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fOffsetX2);
	m_Grid_Brace.SetItemText(iRow + 1, 20, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fOffsetY2);
	m_Grid_Brace.SetItemText(iRow + 1, 21, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fOffsetZ2);
	m_Grid_Brace.SetItemText(iRow + 1, 22, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fConnerArea);
	m_Grid_Brace.SetItemText(iRow + 1, 23, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fBsideArea);
	m_Grid_Brace.SetItemText(iRow + 1, 24, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fHsideArea);
	m_Grid_Brace.SetItemText(iRow + 1, 25, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fStirrupArea_D);
	m_Grid_Brace.SetItemText(iRow + 1, 26, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fStirrupArea_UD);
	m_Grid_Brace.SetItemText(iRow + 1, 27, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iMidPerformType);
	m_Grid_Brace.SetItemText(iRow + 1, 28, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iSeverePerformType);
	m_Grid_Brace.SetItemText(iRow + 1, 29, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iStructType);
	m_Grid_Brace.SetItemText(iRow + 1, 30, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iMidNormSectPerformObject);
	m_Grid_Brace.SetItemText(iRow + 1, 31, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iMidDiagSectPerformObject);
	m_Grid_Brace.SetItemText(iRow + 1, 32, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iRareNormSectPerformObject);
	m_Grid_Brace.SetItemText(iRow + 1, 33, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iRareDiagSectPerformObject);
	m_Grid_Brace.SetItemText(iRow + 1, 34, (LPCTSTR)temp);
	temp.Format(_T("%d"), brace.iParaNumbers);
	m_Grid_Brace.SetItemText(iRow + 1, 35, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fAxisFactor);
	m_Grid_Brace.SetItemText(iRow + 1, 36, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fMomentFactor);
	m_Grid_Brace.SetItemText(iRow + 1, 37, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fShearFactor);
	m_Grid_Brace.SetItemText(iRow + 1, 38, (LPCTSTR)temp);
	temp.Format(_T("%i"), brace.iAppendMat);
	m_Grid_Brace.SetItemText(iRow + 1, 39, (LPCTSTR)temp);
	temp.Format(_T("%i"), brace.iNode1Sec);
	m_Grid_Brace.SetItemText(iRow + 1, 40, (LPCTSTR)temp);
	temp.Format(_T("%i"), brace.iNode2Sec);
	m_Grid_Brace.SetItemText(iRow + 1, 41, (LPCTSTR)temp);
	temp.Format(_T("%i"), brace.iShearNonlinear);
	m_Grid_Brace.SetItemText(iRow + 1, 42, (LPCTSTR)temp);
	temp.Format(_T("%g"), brace.fBraceSpan);
	m_Grid_Brace.SetItemText(iRow + 1, 43, (LPCTSTR)temp);
	if (brace.iParaNumbers == 9) {
		temp.Format(_T("%d"), brace.iReinforcedSec);
		m_Grid_Brace.SetItemText(iRow + 1, 44, (LPCTSTR)temp);
	}
	for (int j = 0; j < 4; j++) //设置部分列仅可读不可编辑
	{
		m_Grid_Brace.SetItemState(iRow + 1, j, GVIS_READONLY);
	}
}

int CTabDlg7::GetComboBoxIndex(CString sMat)
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

void CTabDlg7::SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat)
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

BOOL CTabDlg7::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Brace.GetClientRect(&cr);
	m_Grid_Brace.SetColumnCount(45);//设置列数
	m_Grid_Brace.SetFixedRowCount(1);//设置表头
	m_Grid_Brace.SetItemText(0, 0, _T("ID"));
	m_Grid_Brace.SetItemText(0, 1, _T("PKPM结构线编号"));
	m_Grid_Brace.SetItemText(0, 2, _T("结构线编号"));
	m_Grid_Brace.SetItemText(0, 3, _T("对象类型"));
	m_Grid_Brace.SetItemText(0, 4, _T("截面类型"));
	m_Grid_Brace.SetItemText(0, 5, _T("子类型"));
	m_Grid_Brace.SetItemText(0, 6, _T("斜撑1端连接形式"));
	m_Grid_Brace.SetItemText(0, 7, _T("斜撑2端连接形式"));
	m_Grid_Brace.SetItemText(0, 8, _T("混凝土强度等级"));
	m_Grid_Brace.SetItemText(0, 9, _T("钢筋级别"));
	m_Grid_Brace.SetItemText(0, 10, _T("箍筋级别"));
	m_Grid_Brace.SetItemText(0, 11, _T("钢材型号"));
	m_Grid_Brace.SetItemText(0, 12, _T("底部楼层"));
	m_Grid_Brace.SetItemText(0, 13, _T("楼层"));
	m_Grid_Brace.SetItemText(0, 14, _T("施工阶段"));
	m_Grid_Brace.SetItemText(0, 15, _T("塔号"));
	m_Grid_Brace.SetItemText(0, 16, _T("方向角（度）"));
	m_Grid_Brace.SetItemText(0, 17, _T("1点X方向偏移"));
	m_Grid_Brace.SetItemText(0, 18, _T("1点Y方向偏移"));
	m_Grid_Brace.SetItemText(0, 19, _T("1点Z方向偏移"));
	m_Grid_Brace.SetItemText(0, 20, _T("2点X方向偏移"));
	m_Grid_Brace.SetItemText(0, 21, _T("2点Y方向偏移"));
	m_Grid_Brace.SetItemText(0, 22, _T("2点Z方向偏移"));
	m_Grid_Brace.SetItemText(0, 23, _T("角筋面积"));
	m_Grid_Brace.SetItemText(0, 24, _T("B方向单边配筋面积"));
	m_Grid_Brace.SetItemText(0, 25, _T("H方向单边配筋面积"));
	m_Grid_Brace.SetItemText(0, 26, _T("加密区箍筋面积"));
	m_Grid_Brace.SetItemText(0, 27, _T("非加密区箍筋面积"));
	m_Grid_Brace.SetItemText(0, 28, _T("中震本构"));
	m_Grid_Brace.SetItemText(0, 29, _T("大震本构"));
	m_Grid_Brace.SetItemText(0, 30, _T("重要性分类"));
	m_Grid_Brace.SetItemText(0, 31, _T("中震正截面性能"));
	m_Grid_Brace.SetItemText(0, 32, _T("中震斜截面性能"));
	m_Grid_Brace.SetItemText(0, 33, _T("大震正截面性能"));
	m_Grid_Brace.SetItemText(0, 34, _T("大震斜截面性能"));
	m_Grid_Brace.SetItemText(0, 35, _T("性能化参数个数"));
	m_Grid_Brace.SetItemText(0, 36, _T("轴力内力调整系数"));
	m_Grid_Brace.SetItemText(0, 37, _T("弯矩内力调整系数"));
	m_Grid_Brace.SetItemText(0, 38, _T("剪力内力调整系数"));
	m_Grid_Brace.SetItemText(0, 39, _T("附加材料"));
	m_Grid_Brace.SetItemText(0, 40, _T("1端半刚性属性"));
	m_Grid_Brace.SetItemText(0, 41, _T("2端半刚性属性"));
	m_Grid_Brace.SetItemText(0, 42, _T("剪切属性"));
	m_Grid_Brace.SetItemText(0, 43, _T("构件跨度"));
	m_Grid_Brace.SetItemText(0, 44, _T("附加加固截面"));

	//设置列宽，并将部分列隐藏
	for (int i = 0; i < 45; i++)
	{
		m_Grid_Brace.SetColumnWidth(i, 60);
	}
	m_Grid_Brace.SetColumnWidth(1, 0);
	m_Grid_Brace.SetColumnWidth(12, 0);
	m_Grid_Brace.SetColumnWidth(35, 0);
	m_Grid_Brace.SetColumnWidth(44, 0);
	m_Grid_Brace.EnableHiddenColUnhide(FALSE);

	return TRUE;// TODO:  在此添加额外的初始化

	// return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

LRESULT CTabDlg7::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	CDataFile fin;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	fin.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	fin.SeekToBegin();
	CString sLine;
	int iColCount = m_Grid_Brace.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		if (sLine.Find(TEXT("BRACE NUMBER=")) != -1)
		{
			iRowCount = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			m_Grid_Brace.SetRowCount(iRowCount + 1);
			break;
		}
	}
	for (int i = 0; i < iRowCount; i++)
	{
		fin.ReadString(sLine);
		fin.SetData(sLine);
		Brace brace;
		SetBraceData(brace, fin);
		vBrace.push_back(brace);
		SetGridItemText(i,m_Grid_Brace,brace);
	}
	return LRESULT();
}

LRESULT CTabDlg7::OnWriteDate(WPARAM wParam, LPARAM lParam)
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
	int iColCount = m_Grid_Brace.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		fout.WriteString(sLine + _T("\n"));
		if (sLine.Find(TEXT("BRACE NUMBER=")) != -1)//先定位
		{
			
			for (int i = 0; i < iRowCount; i++)
			{
				fin.ReadString(sLine);
				GetBraceData(m_Grid_Brace, i);
				WriteBraceData(i, sNewLine);
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

LRESULT CTabDlg7::OnSearchID(WPARAM wParam, LPARAM lParam)
{
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	int ID = _ttoi(pParent->m_ID);//从父窗口得到ID序号
	if (ID != 0 && ID <= iRowCount)
	{
		for (int i = 1; i < iRowCount + 1; i++)
		{
			if (i != ID)
			{
				m_Grid_Brace.SetRowHeight(i, 0);
			}
		}
	}
	else
	{
		MessageBox(TEXT("请输入列表内的ID序号进行搜索"));
	}
	return LRESULT();
}

LRESULT CTabDlg7::OnShowAll(WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < iRowCount + 1; i++)
	{
		m_Grid_Brace.SetRowHeight(i, 25);
	}
	return LRESULT();
}
