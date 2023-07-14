// CTabDlg4.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "afxdialogex.h"
#include "SSGEditDlg.h"
#include "CTabDlg4.h"


// CTabDlg4 对话框

IMPLEMENT_DYNAMIC(CTabDlg4, CDialogEx)

CTabDlg4::CTabDlg4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG4, pParent)
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

CTabDlg4::~CTabDlg4()
{
}

void CTabDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM3, m_Grid_Wall);
}


BEGIN_MESSAGE_MAP(CTabDlg4, CDialogEx)
	ON_MESSAGE(NM_A, OnUpDate)
	ON_MESSAGE(NM_E, OnWriteDate)
END_MESSAGE_MAP()


// CTabDlg4 消息处理程序

void CTabDlg4::SetWallData(Wall& wall, CDataFile& fin)
{
	wall.ID = fin.GetInt();
	wall.iPKPM = fin.GetInt();
	wall.nLine = fin.GetInt();
	for (int i = 0; i < wall.nLine; i++)
	{
		wall.iNode[i] = fin.GetInt();
	}
	wall.iType = fin.GetInt();
	wall.iSection = fin.GetInt();
	wall.iSubType = fin.GetInt();
	wall.nRebarLayer = fin.GetInt();
	wall.iConcMat = fin.GetInt();
	wall.iRebarMat = fin.GetInt();
	wall.iSteelMat = fin.GetInt();
	wall.iBottomStory = fin.GetInt();
	wall.idmStory = fin.GetInt();
	wall.iStage = fin.GetInt();
	wall.iTower = fin.GetInt();
	wall.fOffset = fin.GetFloat();
	wall.fHRebarArea = fin.GetFloat();
	wall.fAngle1 = fin.GetFloat();
	wall.fVRebarArea = fin.GetFloat();
	wall.fAngle2 = fin.GetFloat();
	wall.iMidPerformType = fin.GetInt();
	wall.iSeverePerformType = fin.GetInt();
	wall.iStructType = fin.GetInt();
	wall.iMidNormSectPerformObject = fin.GetInt();
	wall.iMidDiagSectPerformObject = fin.GetInt();
	wall.iRareNormSectPerformObject = fin.GetInt();
	wall.iRareDiagSectPerformObject = fin.GetInt();
	wall.iParaNumbers = fin.GetInt();
	wall.fAxisFactor = fin.GetFloat();
	wall.fMomentFactor = fin.GetFloat();
	wall.fShearFactor = fin.GetFloat();
}

void CTabDlg4::GetWallData(CGridCtrl& m_Grid_Wall, int iRow)
{
	vWall[iRow].ID = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 0));
	vWall[iRow].iPKPM = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 1));
	vWall[iRow].nLine = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 2));
	vWall[iRow].iNode[0] = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 3));
	vWall[iRow].iNode[1] = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 4));
	vWall[iRow].iNode[2] = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 5));
	vWall[iRow].iNode[3] = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 6));
	vWall[iRow].iNode[4] = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 7));
	vWall[iRow].iNode[5] = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 8));
	vWall[iRow].iType = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 9));
	vWall[iRow].iSection = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 10));
	vWall[iRow].iSubType = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 11));
	vWall[iRow].nRebarLayer = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 12));
	if (m_Grid_Wall.GetItemText(iRow + 1, 13) != _T("0"))//ComboBox需转换为序号
	{
		vWall[iRow].iConcMat = GetComboBoxIndex(m_Grid_Wall.GetItemText(iRow + 1, 13));
	}
	else
	{
		vWall[iRow].iConcMat = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 13));
	}
	if (m_Grid_Wall.GetItemText(iRow + 1, 14) != _T("0"))//ComboBox需转换为序号
	{
		vWall[iRow].iRebarMat = GetComboBoxIndex(m_Grid_Wall.GetItemText(iRow + 1, 14));
	}
	else
	{
		vWall[iRow].iRebarMat = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 14));
	}
	if (m_Grid_Wall.GetItemText(iRow + 1, 15) != _T("0"))//ComboBox需转换为序号
	{
		vWall[iRow].iSteelMat = GetComboBoxIndex(m_Grid_Wall.GetItemText(iRow + 1, 15));
	}
	else
	{
		vWall[iRow].iSteelMat = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 15));
	}
	vWall[iRow].iBottomStory = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 16));
	vWall[iRow].idmStory = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 17));
	vWall[iRow].iStage = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 18));
	vWall[iRow].iTower = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 19));
	vWall[iRow].fOffset = _ttof(m_Grid_Wall.GetItemText(iRow + 1, 20));
	vWall[iRow].fHRebarArea = _ttof(m_Grid_Wall.GetItemText(iRow + 1, 21));
	vWall[iRow].fAngle1 = _ttof(m_Grid_Wall.GetItemText(iRow + 1, 22));
	vWall[iRow].fVRebarArea = _ttof(m_Grid_Wall.GetItemText(iRow + 1, 23));
	vWall[iRow].fAngle2 = _ttof(m_Grid_Wall.GetItemText(iRow + 1, 24));
	vWall[iRow].iMidPerformType = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 25));
	vWall[iRow].iSeverePerformType = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 26));
	vWall[iRow].iStructType = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 27));
	vWall[iRow].iMidNormSectPerformObject = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 28));
	vWall[iRow].iMidDiagSectPerformObject = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 29));
	vWall[iRow].iRareNormSectPerformObject = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 30));
	vWall[iRow].iRareDiagSectPerformObject = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 31));
	vWall[iRow].iParaNumbers = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 32));
	vWall[iRow].fAxisFactor = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 33));
	vWall[iRow].fMomentFactor = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 34));
	vWall[iRow].fShearFactor = _ttoi(m_Grid_Wall.GetItemText(iRow + 1, 35));
}

void CTabDlg4::WriteWallData(int iRow, CString& sNewLine)
{
	char temp[512];
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].ID);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iPKPM);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].nLine);
	sNewLine += temp;
	for (int i = 0; i < vWall[iRow].nLine; i++)
	{
		sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iNode[i]);
		sNewLine += temp;
	}
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iSection);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iSubType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].nRebarLayer);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iConcMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iRebarMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iSteelMat);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iBottomStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].idmStory);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iStage);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iTower);
	sNewLine += temp;
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vWall[iRow].fOffset);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vWall[iRow].fHRebarArea);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vWall[iRow].fAngle1);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%.4f ", vWall[iRow].fVRebarArea);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vWall[iRow].fAngle2);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iMidPerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iSeverePerformType);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iMidNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iMidDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iRareNormSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iRareDiagSectPerformObject);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%d ", vWall[iRow].iParaNumbers);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vWall[iRow].fAxisFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vWall[iRow].fMomentFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "%g ", vWall[iRow].fShearFactor);
	sNewLine += temp;
	sprintf_s(temp, sizeof(temp), "0 0 0 0 0");
	sNewLine += temp;
}

void CTabDlg4::SetGridItemText(int iRow, int iColCount, CGridCtrl& m_Grid_Wall, CDataFile& fin, Wall& wall)
{
	for (int j = 0; j < iColCount; j++)
	{
		
		if (j < (wall.nLine + 3) && j < 9)
		{
			m_Grid_Wall.SetItemText(iRow + 1, j, (LPCTSTR)fin.arrInfo[j]);
		}
		if (j >= 9)
		{
			m_Grid_Wall.SetItemText(iRow + 1, j, (LPCTSTR)fin.arrInfo[(j - (6 - wall.nLine))]);
		}
	}
	fin.arrInfo.RemoveAll();

	//ComboBox内容的单独设置
	if (wall.iConcMat != 0) 
	{
		m_Grid_Wall.SetCellType(iRow + 1, 13, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Wall, iRow + 1, 13, arrConcMat, wall.iConcMat);
	}
	if (wall.iRebarMat != 0) 
	{
		m_Grid_Wall.SetCellType(iRow + 1, 14, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Wall, iRow + 1, 14, arrRebarMat, wall.iRebarMat);
	}
	if (wall.iSteelMat != 0)
	{
		m_Grid_Wall.SetCellType(iRow + 1, 15, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Wall, iRow + 1, 15, arrRebarMat, wall.iSteelMat);
	}
	
}

int CTabDlg4::GetComboBoxIndex(CString sMat)
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

void CTabDlg4::SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, int iMat)
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

BOOL CTabDlg4::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Wall.GetClientRect(&cr);
	m_Grid_Wall.SetColumnCount(36);//设置列数
	m_Grid_Wall.SetFixedRowCount(1);//设置表头
	m_Grid_Wall.SetItemText(0, 0, _T("ID"));
	m_Grid_Wall.SetItemText(0, 1, _T("PKPM结构线编号"));
	m_Grid_Wall.SetItemText(0, 2, _T("线数目"));
	m_Grid_Wall.SetItemText(0, 3, _T("线编号1"));
	m_Grid_Wall.SetItemText(0, 4, _T("线编号2"));
	m_Grid_Wall.SetItemText(0, 5, _T("线编号3"));
	m_Grid_Wall.SetItemText(0, 6, _T("线编号4"));
	m_Grid_Wall.SetItemText(0, 7, _T("线编号5"));
	m_Grid_Wall.SetItemText(0, 8, _T("线编号6"));
	m_Grid_Wall.SetItemText(0, 9, _T("对象类型"));
	m_Grid_Wall.SetItemText(0, 10, _T("截面类型"));
	m_Grid_Wall.SetItemText(0, 11, _T("子截面类型"));
	m_Grid_Wall.SetItemText(0, 12, _T("钢筋层数"));
	m_Grid_Wall.SetItemText(0, 13, _T("混凝土材料等级"));
	m_Grid_Wall.SetItemText(0, 14, _T("钢筋等级"));
	m_Grid_Wall.SetItemText(0, 15, _T("钢材等级"));
	m_Grid_Wall.SetItemText(0, 16, _T("底部楼层"));
	m_Grid_Wall.SetItemText(0, 17, _T("楼层"));
	m_Grid_Wall.SetItemText(0, 18, _T("施工阶段"));
	m_Grid_Wall.SetItemText(0, 19, _T("塔号"));
	m_Grid_Wall.SetItemText(0, 20, _T("偏移值"));
	m_Grid_Wall.SetItemText(0, 21, _T("水平筋配筋面积"));
	m_Grid_Wall.SetItemText(0, 22, _T("水平筋方向角"));
	m_Grid_Wall.SetItemText(0, 23, _T("竖向筋配筋面积"));
	m_Grid_Wall.SetItemText(0, 24, _T("竖向筋方向角"));
	m_Grid_Wall.SetItemText(0, 25, _T("中震本构"));
	m_Grid_Wall.SetItemText(0, 26, _T("大震本构"));
	m_Grid_Wall.SetItemText(0, 27, _T("重要性分类"));
	m_Grid_Wall.SetItemText(0, 28, _T("中震正截面性能"));
	m_Grid_Wall.SetItemText(0, 29, _T("中震斜截面性能"));
	m_Grid_Wall.SetItemText(0, 30, _T("大震正截面性能"));
	m_Grid_Wall.SetItemText(0, 31, _T("大震斜截面性能"));
	m_Grid_Wall.SetItemText(0, 32, _T("3"));
	m_Grid_Wall.SetItemText(0, 33, _T("轴力内力调整系数"));
	m_Grid_Wall.SetItemText(0, 34, _T("弯矩内力调整系数"));
	m_Grid_Wall.SetItemText(0, 35, _T("剪力内力调整系数"));
	// TODO:  在此添加额外的初始化
	//设置列宽，并将部分列隐藏
	for (int i = 0; i < 36; i++)
	{
		m_Grid_Wall.SetColumnWidth(i, 60);
	}
	m_Grid_Wall.SetColumnWidth(1, 0);
	m_Grid_Wall.SetColumnWidth(32, 0);
	m_Grid_Wall.EnableHiddenColUnhide(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

LRESULT CTabDlg4::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	CDataFile fin;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	fin.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	fin.SeekToBegin();
	CString sLine;
	int iWallNumbers = 0;
	int iColCount = m_Grid_Wall.GetColumnCount();
	while (fin.ReadString(sLine))
	{
		if (sLine.Find(TEXT("WALLC NUMBER=")) != -1)
		{
			iWallNumbers = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			m_Grid_Wall.SetRowCount(iWallNumbers + 1);
			//MessageBox(TEXT("ok"));
			break;
		}
	}
	for (int i = 0; i < iWallNumbers; i++)
	{
		fin.ReadString(sLine);
		fin.SetData(sLine);
		Wall wall;
		SetWallData(wall, fin);
		vWall.push_back(wall);
		SetGridItemText(i, iColCount, m_Grid_Wall, fin, wall);
	}
	return LRESULT();
}

LRESULT CTabDlg4::OnWriteDate(WPARAM wParam, LPARAM lParam)
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
	int iColCount = m_Grid_Wall.GetColumnCount();
	int iWallNumbers = 0;
	while (fin.ReadString(sLine))
	{
		fout.WriteString(sLine + _T("\n"));
		if (sLine.Find(TEXT("WALLC NUMBER=")) != -1)//先定位
		{
			iWallNumbers = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			for (int i = 0; i < iWallNumbers; i++)
			{
				fin.ReadString(sLine);

				GetWallData(m_Grid_Wall, i);
				WriteWallData(i, sNewLine);
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
