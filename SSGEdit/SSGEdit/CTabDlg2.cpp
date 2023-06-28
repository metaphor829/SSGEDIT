// CTabDlg2.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "afxdialogex.h"
#include "SSGEditDlg.h"
#include "CTabDlg2.h"



// CTabDlg2 对话框

IMPLEMENT_DYNAMIC(CTabDlg2, CDialogEx)

CTabDlg2::CTabDlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG2, pParent)
{
	arrConcMat.SetSize(20);
	arrConcMat.SetAt(0,TEXT("C15"));
	arrConcMat.SetAt(1,TEXT("C20"));
	arrConcMat.SetAt(2,TEXT("C25"));
	arrConcMat.SetAt(3,TEXT("C30"));
	arrConcMat.SetAt(4,TEXT("C35"));
	arrConcMat.SetAt(5,TEXT("C40"));
	arrConcMat.SetAt(6,TEXT("C45"));
	arrConcMat.SetAt(7,TEXT("C50"));
	arrConcMat.SetAt(8,TEXT("C55"));
	arrConcMat.SetAt(9,TEXT("C60"));
	arrConcMat.SetAt(10,TEXT("C65"));
	arrConcMat.SetAt(11,TEXT("C70"));
	arrConcMat.SetAt(12,TEXT("C75"));
	arrConcMat.SetAt(13,TEXT("C80"));
	arrConcMat.SetAt(14,TEXT("C85"));
	arrConcMat.SetAt(15,TEXT("C90"));
	arrConcMat.SetAt(16,TEXT("C95"));
	arrConcMat.SetAt(17,TEXT("C100"));
	arrConcMat.SetAt(18,TEXT("C105"));
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

CTabDlg2::~CTabDlg2()
{
}

void CTabDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CUSTOM1, m_Grid_Beam);
}


BEGIN_MESSAGE_MAP(CTabDlg2, CDialogEx)
	ON_MESSAGE(NM_A, OnUpDate)
	ON_MESSAGE(NM_C, OnWriteDate)
END_MESSAGE_MAP()


// CTabDlg2 消息处理程序
void CTabDlg2::SetCellComboText(CGridCtrl& m_Grid, int nRow, int nCol, CStringArray& arrText, CStringArray& arrBeamInfo, int BeamInfoIndex)
{

	CGridCellCombo* pCell = (CGridCellCombo*)m_Grid.GetCell(nRow, nCol);
	pCell->SetOptions(arrText);
	int iBeamInfo = _ttoi(arrBeamInfo.GetAt(BeamInfoIndex));
	if (iBeamInfo < 100) {
	pCell->SetText(arrText.GetAt(_ttoi(arrBeamInfo.GetAt(BeamInfoIndex))));
	}
	else {
		pCell->SetText(arrText.GetAt(_ttoi(arrBeamInfo.GetAt(BeamInfoIndex)) - 101));
	}
}

void CTabDlg2::TrimArray(CStringArray& arr, int index)
{
	for (int i = 0; i <10; i++)
	{
		arr.RemoveAt(index);
	}
}

void CTabDlg2::ExpandArray(CStringArray& arr, int iColCount,int index)
{
	arr.SetSize(iColCount);
	for(int i=0;i<10;i++)
	{
	arr.InsertAt(index,_T("0"));
	}
	

	
}

CString CTabDlg2::GetComboBoxIndex(CStringArray& arr, int nCol)
{	
	for(int i=0;i< arrConcMat.GetSize();i++)
	{ 
		if(arrConcMat.GetAt(i)==arr.GetAt(nCol))
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
			String.Format(_T("%d"), i+101);
			return String;
		}
	}
}




BOOL CTabDlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Beam.GetClientRect(&cr);
	m_Grid_Beam.SetColumnCount(62);//设置列数
	m_Grid_Beam.SetFixedRowCount(1);//设置表头
	m_Grid_Beam.SetItemText(0, 0, _T("ID"));
	m_Grid_Beam.SetItemText(0, 1, _T("PKPM结构线编号"));
	m_Grid_Beam.SetItemText(0, 2, _T("结构线编号"));
	m_Grid_Beam.SetItemText(0, 3, _T("对象类型"));
	m_Grid_Beam.SetItemText(0, 4, _T("截面类型"));
	m_Grid_Beam.SetItemText(0, 5, _T("子类型"));
	m_Grid_Beam.SetItemText(0, 6, _T("梁1端连接形式"));
	m_Grid_Beam.SetItemText(0, 7, _T("梁2端连接形式"));
	m_Grid_Beam.SetItemText(0, 8, _T("混凝土强度等级"));
	m_Grid_Beam.SetItemText(0, 9, _T("钢筋级别"));
	m_Grid_Beam.SetItemText(0, 10, _T("箍筋级别"));
	m_Grid_Beam.SetItemText(0, 11, _T("钢材型号"));
	m_Grid_Beam.SetItemText(0, 12, _T("楼层"));
	m_Grid_Beam.SetItemText(0, 13, _T("施工阶段"));
	m_Grid_Beam.SetItemText(0, 14, _T("塔号"));
	m_Grid_Beam.SetItemText(0, 15, _T("方向角（度）"));
	m_Grid_Beam.SetItemText(0, 16, _T("1点X方向偏移"));
	m_Grid_Beam.SetItemText(0, 17, _T("1点Y方向偏移"));
	m_Grid_Beam.SetItemText(0, 18, _T("1点Z方向偏移"));
	m_Grid_Beam.SetItemText(0, 19, _T("2点X方向偏移"));
	m_Grid_Beam.SetItemText(0, 20, _T("2点Y方向偏移"));
	m_Grid_Beam.SetItemText(0, 21, _T("2点Z方向偏移"));
	m_Grid_Beam.SetItemText(0, 22, _T("面筋配筋面积"));
	m_Grid_Beam.SetItemText(0, 23, _T("面筋配筋面积"));
	m_Grid_Beam.SetItemText(0, 24, _T("面筋配筋面积"));
	m_Grid_Beam.SetItemText(0, 25, _T("底筋配筋面积"));
	m_Grid_Beam.SetItemText(0, 26, _T("底筋配筋面积"));
	m_Grid_Beam.SetItemText(0, 27, _T("底筋配筋面积"));
	m_Grid_Beam.SetItemText(0, 28, _T("加密区箍筋面积"));
	m_Grid_Beam.SetItemText(0, 29, _T("非加密区箍筋面积"));
	m_Grid_Beam.SetItemText(0, 30, _T("2"));
	m_Grid_Beam.SetItemText(0, 31, _T("0"));
	m_Grid_Beam.SetItemText(0, 32, _T("0"));
	m_Grid_Beam.SetItemText(0, 33, _T("恒荷载qz（kN/m）"));
	m_Grid_Beam.SetItemText(0, 34, _T("长度"));
	m_Grid_Beam.SetItemText(0, 35, _T("恒荷载qz（kN/m）"));
	m_Grid_Beam.SetItemText(0, 36, _T("1"));
	m_Grid_Beam.SetItemText(0, 37, _T("0"));
	m_Grid_Beam.SetItemText(0, 38, _T("活荷载qz（kN/m）"));
	m_Grid_Beam.SetItemText(0, 39, _T("长度"));	
	m_Grid_Beam.SetItemText(0, 40, _T("活荷载qz（kN/m）"));
	m_Grid_Beam.SetItemText(0, 41, _T("中震本构"));
	m_Grid_Beam.SetItemText(0, 42, _T("大震本构"));
	m_Grid_Beam.SetItemText(0, 43, _T("重要性分类"));
	m_Grid_Beam.SetItemText(0, 44, _T("中震正截面性能"));
	m_Grid_Beam.SetItemText(0, 45, _T("中震斜截面性能"));
	m_Grid_Beam.SetItemText(0, 46, _T("大震正截面性能"));
	m_Grid_Beam.SetItemText(0, 47, _T("大震斜截面性能"));
	m_Grid_Beam.SetItemText(0, 48, _T("地震等级"));
	m_Grid_Beam.SetItemText(0, 49, _T("轴力内力调整系数"));
	m_Grid_Beam.SetItemText(0, 50, _T("弯矩内力调整系数"));
	m_Grid_Beam.SetItemText(0, 51, _T("剪力内力调整系数"));
	m_Grid_Beam.SetItemText(0, 52, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 53, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 54, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 55, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 56, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 57, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 58, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 59, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 60, _T("待确定"));
	m_Grid_Beam.SetItemText(0, 61, _T("待确定"));
	//设置列宽，并将部分列隐藏
	m_Grid_Beam.SetColumnWidth(0,50);
	m_Grid_Beam.SetColumnWidth(1, 0);
	m_Grid_Beam.SetColumnWidth(2, 80);
	m_Grid_Beam.SetColumnWidth(3, 60);
	m_Grid_Beam.SetColumnWidth(4, 60);
	m_Grid_Beam.SetColumnWidth(5, 60);
	m_Grid_Beam.SetColumnWidth(6, 60);
	m_Grid_Beam.SetColumnWidth(7, 60);
	m_Grid_Beam.SetColumnWidth(23, 0);
	m_Grid_Beam.SetColumnWidth(24, 0);
	m_Grid_Beam.SetColumnWidth(26, 0);
	m_Grid_Beam.SetColumnWidth(27, 0);
	m_Grid_Beam.SetColumnWidth(30, 0);
	m_Grid_Beam.SetColumnWidth(31, 0);
	m_Grid_Beam.SetColumnWidth(32, 0);
	m_Grid_Beam.SetColumnWidth(34, 0);
	m_Grid_Beam.SetColumnWidth(35, 0);
	m_Grid_Beam.SetColumnWidth(36, 0);
	m_Grid_Beam.SetColumnWidth(37, 0);
	m_Grid_Beam.SetColumnWidth(39, 0);
	m_Grid_Beam.SetColumnWidth(40, 0);
	m_Grid_Beam.SetColumnWidth(52, 0);
	m_Grid_Beam.SetColumnWidth(53, 0);
	m_Grid_Beam.SetColumnWidth(54, 0);
	m_Grid_Beam.SetColumnWidth(55, 0);
	m_Grid_Beam.SetColumnWidth(56, 0);
	m_Grid_Beam.SetColumnWidth(57, 0);
	m_Grid_Beam.SetColumnWidth(58, 0);
	m_Grid_Beam.SetColumnWidth(59, 0);
	m_Grid_Beam.SetColumnWidth(60, 0);
	m_Grid_Beam.SetColumnWidth(61, 0);
	m_Grid_Beam.EnableHiddenColUnhide(FALSE);//使隐藏列不能显示



	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



LRESULT CTabDlg2::OnUpDate(WPARAM wParam, LPARAM lParam)
{
	//MessageBox(TEXT("接受"));
	CStdioFile cFile;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	cFile.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
	cFile.SeekToBegin();// 将文件指针指向文件开始处
	CString sLine;
	static int iBeamNumbers=0;
	static CString sBeamNumbers;
	int iColCount = m_Grid_Beam.GetColumnCount();
	while (cFile.ReadString(sLine))
	{
		if (sLine.Find(TEXT("NBEAM NUMBER=")) != -1)
		{
			sBeamNumbers = sLine.Mid(sLine.Find(TEXT("=")) + 1);
			iBeamNumbers = _ttoi(sBeamNumbers);
			m_Grid_Beam.SetRowCount(iBeamNumbers+1);
			break;
		}
	}
	
	for (int i = 0;i < iBeamNumbers; i++)
	{
		cFile.ReadString(sLine);
		CSplitStr Split;
		Split.SetData(sLine);
		Split.SetSplitFlag(TEXT(" "));
		CStringArray arrBeamInfo;
		Split.GetSplitStrArray(arrBeamInfo);
		
		if (arrBeamInfo.GetSize() == iColCount)//将arrBeamInfo中的信息填入到网格中
		{
			for (int j = 0; j < arrBeamInfo.GetSize(); j++)
			{
				m_Grid_Beam.SetItemText(i + 1, j, (LPCTSTR)arrBeamInfo.GetAt(j));
			}
		}
		else//将arrBeamInfo中格式不统一的信息先进行处理再填入到网格中
		{
			ExpandArray(arrBeamInfo, iColCount,30);
			for (int j = 0; j < arrBeamInfo.GetSize(); j++)
			{
				m_Grid_Beam.SetItemText(i + 1, j, (LPCTSTR)arrBeamInfo.GetAt(j));
			}
		}

		//ComboBox内容的单独设置
		m_Grid_Beam.SetCellType(i + 1, 8, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Beam, i + 1, 8, arrConcMat, arrBeamInfo, 8);
		m_Grid_Beam.SetCellType(i + 1, 9, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Beam, i + 1, 9, arrRebarMat, arrBeamInfo, 9);
		m_Grid_Beam.SetCellType(i + 1, 10, RUNTIME_CLASS(CGridCellCombo));
		SetCellComboText(m_Grid_Beam, i + 1, 10, arrRebarMat, arrBeamInfo, 10);

		
	}

	return 0;
}
LRESULT CTabDlg2::OnWriteDate(WPARAM wParam, LPARAM lParam)
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
	 int iColCount = m_Grid_Beam.GetColumnCount();
	 CString sLine;
	 CString sNewLine;
	 static int iBeamNumbers = 0;
	 static CString sBeamNumbers;
	 while (cFile.ReadString(sLine))
	 {
		 cNewFile.WriteString(sLine + _T("\n"));
		 if (sLine.Find(TEXT("NBEAM NUMBER=")) != -1)//先定位至BEAM NUMBER所在行
		 {
			 sBeamNumbers = sLine.Mid(sLine.Find(TEXT("=")) + 1);
			 iBeamNumbers = _ttoi(sBeamNumbers);
			 for (int i = 0; i < iBeamNumbers; i++)
			 {
				 cFile.ReadString(sLine);
				 CSplitStr Split;
				 Split.SetData(sLine);
				 Split.SetSplitFlag(TEXT(" "));
				 CStringArray arrBeamInfo;
				 Split.GetSplitStrArray(arrBeamInfo);
				 CStringArray arrCellText;
				 for (int j = 0; j < iColCount; j++)
				 {
					 arrCellText.Add(m_Grid_Beam.GetItemText(i + 1, j));
				 }
				 //将ComboBox项的内容转换为索引号
				 arrCellText.SetAt(8, GetComboBoxIndex(arrCellText, 8));
				 arrCellText.SetAt(9, GetComboBoxIndex(arrCellText, 9));
				 arrCellText.SetAt(10, GetComboBoxIndex(arrCellText, 10));
				

				 if (arrCellText.GetSize() == arrBeamInfo.GetSize())//将arrCellText中的信息填入到NewLine进行替换
				 {
					 for (int k = 0; k < arrCellText.GetSize(); k++)
					 {
						 sNewLine += arrCellText.GetAt(k);
						 sNewLine += TEXT(" ");
					 }

				 } 
				 else//将arrCellText修建为arrBeamInfo一样的格式长度
				 {
					 TrimArray(arrCellText,30);
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
				 arrBeamInfo.RemoveAll();
			 } 
		 }
	 }
	 cFile.Close();
	 cNewFile.Close();
	 cFile.Remove(sPath);
	 cNewFile.Rename(sNewPath,sPath);
	 return 0;
}

 

