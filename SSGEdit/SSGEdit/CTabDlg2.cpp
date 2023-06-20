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
	arrRebarMat.SetSize(120);
	arrRebarMat.SetAt(101, TEXT("HPB235"));
	arrRebarMat.SetAt(102, TEXT("HRB300"));
	arrRebarMat.SetAt(103, TEXT("HRB335"));
	arrRebarMat.SetAt(104, TEXT("HRB400"));
	arrRebarMat.SetAt(105, TEXT("HRB500"));
	arrRebarMat.SetAt(106, TEXT("CRB550"));
	arrRebarMat.SetAt(107, TEXT("CRB600H"));
	arrRebarMat.SetAt(108, TEXT("HTRB600"));
	arrRebarMat.SetAt(109, TEXT("HTRB630"));
	arrRebarMat.SetAt(110, TEXT("HRB635"));
	arrRebarMat.SetAt(111, TEXT("T63"));
		

		
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
	ON_MESSAGE(NM_B, OnWriteDate)
END_MESSAGE_MAP()


// CTabDlg2 消息处理程序


BOOL CTabDlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect cr;
	m_Grid_Beam.GetClientRect(&cr);
	m_Grid_Beam.SetColumnCount(34);//设置列数
	m_Grid_Beam.SetFixedRowCount(1);//设置表头
	m_Grid_Beam.SetItemText(0, 0, _T("ID"));
	m_Grid_Beam.SetItemText(0, 1, _T("结构线编号"));
	m_Grid_Beam.SetItemText(0, 2, _T("截面类型"));
	m_Grid_Beam.SetItemText(0, 3, _T("子类型"));
	m_Grid_Beam.SetItemText(0, 4, _T("混凝土强度等级"));
	m_Grid_Beam.SetItemText(0, 5, _T("钢筋级别"));
	m_Grid_Beam.SetItemText(0, 6, _T("箍筋级别"));
	m_Grid_Beam.SetItemText(0, 7, _T("钢材型号"));
	m_Grid_Beam.SetItemText(0, 8, _T("楼层"));
	m_Grid_Beam.SetItemText(0, 9, _T("施工阶段"));
	m_Grid_Beam.SetItemText(0, 10, _T("塔号"));
	m_Grid_Beam.SetItemText(0, 11, _T("方向角（度）"));
	m_Grid_Beam.SetItemText(0, 12, _T("1点X方向偏移"));
	m_Grid_Beam.SetItemText(0, 13, _T("1点Y方向偏移"));
	m_Grid_Beam.SetItemText(0, 14, _T("1点Z方向偏移"));
	m_Grid_Beam.SetItemText(0, 15, _T("2点X方向偏移"));
	m_Grid_Beam.SetItemText(0, 16, _T("2点Y方向偏移"));
	m_Grid_Beam.SetItemText(0, 17, _T("2点Z方向偏移"));
	m_Grid_Beam.SetItemText(0, 18, _T("面筋配筋面积"));
	m_Grid_Beam.SetItemText(0, 19, _T("底筋配筋面积"));
	m_Grid_Beam.SetItemText(0, 20, _T("加密区箍筋面积"));
	m_Grid_Beam.SetItemText(0, 21, _T("非加密区箍筋面积"));
	m_Grid_Beam.SetItemText(0, 22, _T("恒荷载qz（kN/m）"));
	m_Grid_Beam.SetItemText(0, 23, _T("活荷载qz（kN/m）"));	
	m_Grid_Beam.SetItemText(0, 24, _T("中震本构"));
	m_Grid_Beam.SetItemText(0, 25, _T("大震本构"));
	m_Grid_Beam.SetItemText(0, 26, _T("重要性分类"));
	m_Grid_Beam.SetItemText(0, 27, _T("中震正截面性能"));
	m_Grid_Beam.SetItemText(0, 28, _T("中震斜截面性能"));
	m_Grid_Beam.SetItemText(0, 29, _T("大震正截面性能"));
	m_Grid_Beam.SetItemText(0, 30, _T("大震斜截面性能"));
	m_Grid_Beam.SetItemText(0, 31, _T("轴力内力调整系数"));
	m_Grid_Beam.SetItemText(0, 32, _T("弯矩内力调整系数"));
	m_Grid_Beam.SetItemText(0, 33, _T("剪力内力调整系数"));
	m_Grid_Beam.SetColumnWidth(0, 50);
	m_Grid_Beam.SetColumnWidth(1, 80);
	m_Grid_Beam.SetColumnWidth(2, 80);
	m_Grid_Beam.SetColumnWidth(3, 80);

	



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
		CStringArray arrBeam;
		Split.GetSplitStrArray(arrBeam);
		m_Grid_Beam.SetEditable(TRUE); 
		m_Grid_Beam.SetItemText(i+1, 0, (LPCTSTR)arrBeam.GetAt(0));
		//m_Grid_Beam.SetItemState(i+1,0 ,GVIS_READONLY);//设置第一列只读
		m_Grid_Beam.SetItemText(i+1, 1, (LPCTSTR)arrBeam.GetAt(1));
		//m_Grid_Beam.SetItemState(i+1, 1,GVIS_READONLY);//设置第二列只读
		m_Grid_Beam.SetItemText(i+1, 2, (LPCTSTR)arrBeam.GetAt(4));
		m_Grid_Beam.SetItemText(i+1, 3, (LPCTSTR)arrBeam.GetAt(5));
		//combobox内容设置
		m_Grid_Beam.SetCellType(i+1, 4, RUNTIME_CLASS(CGridCellCombo));
		((CGridCellCombo*)m_Grid_Beam.GetCell(i + 1, 4))->SetOptions(arrConcMat);
		((CGridCellCombo*)m_Grid_Beam.GetCell(i + 1, 4))->SetText(arrConcMat.GetAt(_ttoi(arrBeam.GetAt(8))));
		m_Grid_Beam.SetCellType(i + 1, 5, RUNTIME_CLASS(CGridCellCombo));
		((CGridCellCombo*)m_Grid_Beam.GetCell(i + 1, 5))->SetOptions(arrRebarMat);
		((CGridCellCombo*)m_Grid_Beam.GetCell(i + 1, 5))->SetText(arrRebarMat.GetAt(_ttoi(arrBeam.GetAt(9))));
		m_Grid_Beam.SetCellType(i + 1, 6, RUNTIME_CLASS(CGridCellCombo));
		((CGridCellCombo*)m_Grid_Beam.GetCell(i + 1, 6))->SetOptions(arrRebarMat);
		((CGridCellCombo*)m_Grid_Beam.GetCell(i + 1, 6))->SetText(arrRebarMat.GetAt(_ttoi(arrBeam.GetAt(10))));
		m_Grid_Beam.SetItemText(i+1, 7, (LPCTSTR)arrBeam.GetAt(11));
		m_Grid_Beam.SetItemText(i+1, 8, (LPCTSTR)arrBeam.GetAt(12));
		m_Grid_Beam.SetItemText(i+1, 9, (LPCTSTR)arrBeam.GetAt(13));
		m_Grid_Beam.SetItemText(i+1, 10, (LPCTSTR)arrBeam.GetAt(14));
		m_Grid_Beam.SetItemText(i+1, 11, (LPCTSTR)arrBeam.GetAt(15));
		m_Grid_Beam.SetItemText(i+1, 12, (LPCTSTR)arrBeam.GetAt(16));
		m_Grid_Beam.SetItemText(i+1, 13, (LPCTSTR)arrBeam.GetAt(17));
		m_Grid_Beam.SetItemText(i+1, 14, (LPCTSTR)arrBeam.GetAt(18));
		m_Grid_Beam.SetItemText(i+1, 15, (LPCTSTR)arrBeam.GetAt(19));
		m_Grid_Beam.SetItemText(i+1, 16, (LPCTSTR)arrBeam.GetAt(20));
		m_Grid_Beam.SetItemText(i+1, 17, (LPCTSTR)arrBeam.GetAt(21));
		m_Grid_Beam.SetItemText(i+1, 18, (LPCTSTR)arrBeam.GetAt(22));
		m_Grid_Beam.SetItemText(i+1, 19, (LPCTSTR)arrBeam.GetAt(25));
		m_Grid_Beam.SetItemText(i+1, 20, (LPCTSTR)arrBeam.GetAt(28));
		m_Grid_Beam.SetItemText(i+1, 21, (LPCTSTR)arrBeam.GetAt(29));
		m_Grid_Beam.SetItemText(i+1, 22, (LPCTSTR)arrBeam.GetAt(33));
		m_Grid_Beam.SetItemText(i+1, 23, (LPCTSTR)arrBeam.GetAt(38));
		m_Grid_Beam.SetItemText(i+1, 24, (LPCTSTR)arrBeam.GetAt(41));
		m_Grid_Beam.SetItemText(i+1, 25, (LPCTSTR)arrBeam.GetAt(42));
		m_Grid_Beam.SetItemText(i+1, 26, (LPCTSTR)arrBeam.GetAt(43));
		m_Grid_Beam.SetItemText(i+1, 27, (LPCTSTR)arrBeam.GetAt(44));
		m_Grid_Beam.SetItemText(i+1, 28, (LPCTSTR)arrBeam.GetAt(45));
		m_Grid_Beam.SetItemText(i+1, 29, (LPCTSTR)arrBeam.GetAt(46));
		m_Grid_Beam.SetItemText(i+1, 30, (LPCTSTR)arrBeam.GetAt(47));
		m_Grid_Beam.SetItemText(i+1, 31, (LPCTSTR)arrBeam.GetAt(49));
		m_Grid_Beam.SetItemText(i+1, 32, (LPCTSTR)arrBeam.GetAt(50));
		m_Grid_Beam.SetItemText(i+1, 33, (LPCTSTR)arrBeam.GetAt(51));
		
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
	 CString sLine;
	 static int iBeamNumbers = 0;
	 static CString sBeamNumbers;
	 while (cFile.ReadString(sLine))//先定位至梁号所在行
	 {
		
		 cNewFile.WriteString(sLine+ _T("\n"));

		 if (sLine.Find(TEXT("NBEAM NUMBER=")) != -1)
		 {
			 sBeamNumbers = sLine.Mid(sLine.Find(TEXT("=")) + 1);
			 iBeamNumbers = _ttoi(sBeamNumbers);
			 for (int i = 0; i < iBeamNumbers-1; i++)
			 {
				 cFile.ReadString(sLine);
				 CSplitStr Split;
				 Split.SetData(sLine);
				 Split.SetSplitFlag(TEXT(" "));
				 CStringArray arrBeamInfo;
				 Split.GetSplitStrArray(arrBeamInfo);
				 static CStringArray arrCellText;
				 for (int j = 0; j < 34; j++)
				 {
					 arrCellText.Add(m_Grid_Beam.GetItemText(i + 1, j));
				 }
				 arrBeamInfo.SetAt(4, arrCellText.GetAt(2));
				 CString sNewLine;
				 for (int k = 0; k < arrBeamInfo.GetSize(); k++)
				 {
					 sNewLine += arrBeamInfo.GetAt(k);
					 sNewLine += TEXT(" ");
				 }
				 //MessageBox(sNewLine);
				 arrCellText.RemoveAll();
				 arrBeamInfo.RemoveAll();
				 cNewFile.WriteString(sNewLine +_T("\n"));
			 }
		 }
	 }
	cFile.Close();
	cNewFile.Close();
	return 0;
}