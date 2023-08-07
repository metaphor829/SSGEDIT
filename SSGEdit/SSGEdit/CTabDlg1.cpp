// CTabDlg1.cpp: 实现文件
//

#include "pch.h"
#include "SSGEdit.h"
#include "SSGEditDlg.h"
#include "afxdialogex.h"
#include "CTabDlg1.h"


// CTabDlg1 对话框

IMPLEMENT_DYNAMIC(CTabDlg1, CDialogEx)

CTabDlg1::CTabDlg1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_DIALOG1, pParent)
	, m_rebarcover(0)
	, m_colcover(0)
	, m_slabcover(0)
	, m_wallcover(0)
	, m_congravity(0)
	, m_stellgravity(0)
	, m_accgravity(0)
	, m_beamlinkspace(0)
	, m_slabdethickness(0)
	, m_walldethickness(0)
	, m_beamrebardiameter(0)
	, m_colrebardiameter(0)
	, m_slabrebarratio(0)
	, m_wallrebarratio(0)
	, m_beamrebarratio(0)
	, m_colrebarratio(0)
	, m_name(_T(""))
	, m_edgerebar(_T(""))
	, m_linkrebar(_T(""))
	
{

}

CTabDlg1::~CTabDlg1()
{
}

void CTabDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CODETYPE, m_codetype);
	DDX_Text(pDX, IDC_EDIT_PROJECTNAME, m_name);
	DDX_Text(pDX, IDC_EDIT_REBARCOVER, m_rebarcover);
	DDX_Text(pDX, IDC_EDIT_COLCOVER, m_colcover);
	DDX_Text(pDX, IDC_EDIT_SLABCOVER, m_slabcover);
	DDX_Text(pDX, IDC_EDIT_WALLCOVER, m_wallcover);
	DDX_Text(pDX, IDC_EDIT_CONGRAVITY, m_congravity);
	DDX_Text(pDX, IDC_EDIT_STEELGRAVITY, m_stellgravity);
	DDX_Text(pDX, IDC_EDIT_ACCGRAVITY, m_accgravity);
	DDX_Text(pDX, IDC_EDIT_BEAMLINKSPACE, m_beamlinkspace);
	DDX_Text(pDX, IDC_EDIT_SLABDETHICKNESS, m_slabdethickness);
	DDX_Text(pDX, IDC_EDIT_WALLDETHICKNESS, m_walldethickness);
	DDX_Control(pDX, IDC_COMBO_WALLSEISGRADE, m_wallseisgrade);
	DDX_Control(pDX, IDC_COMBO_COLSEISGRADE, m_colseisgrade);
	DDX_Control(pDX, IDC_COMBO_SLABSEISGRADE, m_slabseisgrade);
	DDX_Control(pDX, IDC_COMBO_SEISDETAILGRADE, m_seisdetailgrade);
	DDX_Control(pDX, IDC_COMBO_FORTICATEGORY, m_forticategory);
	DDX_Control(pDX, IDC_COMBO_FIELDCLASS, m_fieldclass);
	DDX_Control(pDX, IDC_COMBO_FIELDGROUP, m_fieldgroup);
	DDX_Control(pDX, IDC_COMBO_EQGRADE, m_eqgrade);
	DDX_Control(pDX, IDC_COMBO_EQGRADEPROBILITY, m_eqgradeprobility);
	DDX_Text(pDX, IDC_EDIT_BEAMREBARDIAMETER, m_beamrebardiameter);
	DDX_Text(pDX, IDC_EDIT_COLREBARDIAMETER, m_colrebardiameter);
	DDX_Text(pDX, IDC_EDIT_SLABREBARRATIO, m_slabrebarratio);
	DDX_Text(pDX, IDC_EDIT_WALLREBARRATIO, m_wallrebarratio);
	DDX_Text(pDX, IDC_EDIT_BEAMREBARRATIO, m_beamrebarratio);
	DDX_Text(pDX, IDC_EDIT_COLREBARRATIO, m_colrebarratio);
	DDX_Text(pDX, IDC_EDIT_EDGEREBAR, m_edgerebar);
	DDX_Text(pDX, IDC_EDIT_LINKREABR, m_linkrebar);
	DDX_Text(pDX, IDC_EDIT_BEAMREBARRATIO2, m_colrebarratio);
}


BEGIN_MESSAGE_MAP(CTabDlg1, CDialogEx)
	ON_MESSAGE(NM_A, OnUpDate)
	ON_MESSAGE(NM_B, OnWriteDate)
END_MESSAGE_MAP()


// CTabDlg1 消息处理程序





BOOL CTabDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_codetype.InsertString(0,TEXT("国家规范"));
	m_codetype.InsertString(1,TEXT("广东省标准"));
	m_wallseisgrade.InsertString(0, TEXT("特一级"));
	m_wallseisgrade.InsertString(1, TEXT("一级"));
	m_wallseisgrade.InsertString(2, TEXT("二级"));
	m_wallseisgrade.InsertString(3, TEXT("三级"));
	m_wallseisgrade.InsertString(4, TEXT("四级"));
	m_wallseisgrade.InsertString(5, TEXT("不抗震"));
	m_colseisgrade.InsertString(0, TEXT("特一级"));
	m_colseisgrade.InsertString(1, TEXT("一级"));
	m_colseisgrade.InsertString(2, TEXT("二级"));
	m_colseisgrade.InsertString(3, TEXT("三级"));
	m_colseisgrade.InsertString(4, TEXT("四级"));
	m_colseisgrade.InsertString(5, TEXT("不抗震"));
	m_slabseisgrade.InsertString(0, TEXT("特一级"));
	m_slabseisgrade.InsertString(1, TEXT("一级"));
	m_slabseisgrade.InsertString(2, TEXT("二级"));
	m_slabseisgrade.InsertString(3, TEXT("三级"));
	m_slabseisgrade.InsertString(4, TEXT("四级"));
	m_slabseisgrade.InsertString(5, TEXT("不抗震"));
	m_seisdetailgrade.InsertString(0, TEXT("不改变"));
	m_seisdetailgrade.InsertString(1, TEXT("提高两级"));
	m_seisdetailgrade.InsertString(2, TEXT("提高一级"));
	m_seisdetailgrade.InsertString(3, TEXT("降低一级"));
	m_seisdetailgrade.InsertString(4, TEXT("降低两级"));
	m_forticategory.InsertString(0, TEXT("甲"));
	m_forticategory.InsertString(1, TEXT("乙"));
	m_forticategory.InsertString(2, TEXT("丙"));
	m_forticategory.InsertString(3, TEXT("丁"));
	m_fieldclass.InsertString(0, TEXT("I0"));
	m_fieldclass.InsertString(1, TEXT("I1"));
	m_fieldclass.InsertString(2, TEXT("II"));
	m_fieldclass.InsertString(3, TEXT("III"));
	m_fieldclass.InsertString(4, TEXT("IV"));
	m_fieldgroup.InsertString(0, TEXT("第一组"));
	m_fieldgroup.InsertString(1, TEXT("第二组"));
	m_fieldgroup.InsertString(2, TEXT("第三组"));
	m_eqgrade.InsertString(0, TEXT("6"));
	m_eqgrade.InsertString(1, TEXT("7"));
	m_eqgrade.InsertString(2, TEXT("7.5"));
	m_eqgrade.InsertString(3, TEXT("8"));
	m_eqgrade.InsertString(4, TEXT("8.5"));
	m_eqgrade.InsertString(5, TEXT("9"));
	m_eqgradeprobility.InsertString(0, TEXT("小震"));
	m_eqgradeprobility.InsertString(1, TEXT("中震"));
	m_eqgradeprobility.InsertString(2, TEXT("大震"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

LRESULT CTabDlg1::OnUpDate(WPARAM wParam, LPARAM lParam)
{		
		//MessageBox(TEXT("接受"));
		CStdioFile cFile;
		CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
		CString sPath = pParent->m_filename;	
		cFile.Open(sPath, CFile::modeRead | CFile::shareDenyNone);
		cFile.SeekToBegin();// 将文件指针指向文件开始处
		CString sLine;
		while (cFile.ReadString(sLine))
		{
			if (sLine.Find(TEXT("CodeType=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_codetype.SetCurSel(index);
			}
			if (sLine.Find(TEXT("Name=")) != -1)
			{
				CString temp = (sLine.Mid(sLine.Find(TEXT("\"")) + 1));
				m_name = temp.Left(temp.Find(TEXT("\"")));
			}
			if (sLine.Find(TEXT("BeamCover=")) != -1)
			{
				m_rebarcover = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("ColumnCover=")) != -1)
			{
				m_colcover = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}

			if (sLine.Find(TEXT("SlabCover=")) != -1)
			{
				m_slabcover = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("WallCover=")) != -1)
			{
				m_wallcover = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("ConcGravity=")) != -1)
			{
				m_congravity = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("SteelGravity=")) != -1)
			{
				m_stellgravity = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("AccelGravity=")) != -1)
			{
				m_accgravity = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("EdgeRebar=")) != -1)
			{
				CString temp = (sLine.Mid(sLine.Find(TEXT("\"")) + 1));
				m_edgerebar = temp.Left(temp.Find(TEXT("\"")));
			}
			if (sLine.Find(TEXT("LinkRebar=")) != -1)
			{
				CString temp = (sLine.Mid(sLine.Find(TEXT("\"")) + 1));
				m_linkrebar = temp.Left(temp.Find(TEXT("\"")));
			}
			if (sLine.Find(TEXT("BeamLinkSpace=")) != -1)
			{
				m_beamlinkspace = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("SlabDefaultThickness=")) != -1)
			{
				m_slabdethickness = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("WallDefaultThickness=")) != -1)
			{
				m_walldethickness = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("WallSeisGrade=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_wallseisgrade.SetCurSel(index);
			}
			if (sLine.Find(TEXT("FrameSeisGrade=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_colseisgrade.SetCurSel(index);
			}
			if (sLine.Find(TEXT("SlabSeisGrade=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_slabseisgrade.SetCurSel(index);
			}
			if (sLine.Find(TEXT("SeisDetailsGrade=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_seisdetailgrade.SetCurSel(index);
			}
			if (sLine.Find(TEXT("FortificationCategory=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_forticategory.SetCurSel(index);
			}
			if (sLine.Find(TEXT("FieldClass=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_fieldclass.SetCurSel(index);
			}
			if (sLine.Find(TEXT("FieldGroup=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_fieldgroup.SetCurSel(index);
			}
			if (sLine.Find(TEXT("EarthQuakeGrade=")) != -1)
			{
				CString temp = (sLine.Mid(sLine.Find(TEXT("=")) + 1));
				int index = m_eqgrade.FindStringExact(0, temp);
				m_eqgrade.SetCurSel(index);
			}
			if (sLine.Find(TEXT("EarthQuakeProbility=")) != -1)
			{
				int index = _ttoi(sLine.Mid(sLine.Find(TEXT("=")) + 1));
				m_eqgradeprobility.SetCurSel(index);
			}
			if (sLine.Find(TEXT("BeamRebarDiameter=")) != -1)
			{
				m_beamrebardiameter = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("ColumnRebarDiameter=")) != -1)
			{
				m_colrebardiameter = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("SlabRebarRatio=")) != -1)
			{
				m_slabrebarratio = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("WallRebarRatio=")) != -1)
			{
				m_wallrebarratio = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("BeamRebarRatio=")) != -1)
			{
				m_beamrebarratio = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			if (sLine.Find(TEXT("ColumnRebarRatio=")) != -1)
			{
				m_colrebarratio = _ttof(sLine.Mid(sLine.Find(TEXT("=")) + 1));
			}
			UpdateData(FALSE);
		}
	return 0;
}

LRESULT CTabDlg1::OnWriteDate(WPARAM wParam, LPARAM lParam)
{
	UpdateData(TRUE);
	CStdioFile cFile;
	CStdioFile cNewFile;
	CSSGEditDlg* pParent = (CSSGEditDlg*)GetParent()->GetParent();//需要调用两次GetParent()函数
	CString sPath = pParent->m_filename;
	CString sNewPath = sPath.Left(sPath.ReverseFind('.')) + _T("(new)") + sPath.Mid(sPath.ReverseFind('.'));
	cFile.Open(sPath, CFile::modeReadWrite | CFile::shareDenyNone);
	cNewFile.Open(sNewPath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate | CFile::shareDenyNone);
	cFile.SeekToBegin();// 将文件指针指向文件开始处
	cNewFile.SeekToBegin();
	CString sLine;
	CString sNewLine;
	while (cFile.ReadString(sLine))
	{
		
		if (sLine.Find(TEXT("CodeType=")) != -1)
		{	
			CString temp;
			temp.Format(TEXT("CodeType=%d"), m_codetype.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("Name=")) != -1)
		{
			CString temp;
			temp= _T("Name=\"")+m_name+ _T("\"");
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("BeamCover=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("BeamCover=%.0f"), m_rebarcover);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("ColumnCover=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("ColumnCover=%.0f"), m_colcover);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("SlabCover=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("SlabCover=%.0f"), m_slabcover);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("WallCover=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("WallCover=%.0f"), m_wallcover);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("ConcGravity=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("ConcGravity=%.0f"), m_congravity);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("SteelGravity=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("SteelGravity=%.0f"), m_stellgravity);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("AccelGravity=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("AccelGravity=%.0f"), m_accgravity);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("EdgeRebar=")) != -1)
		{
			CString temp;
			temp = _T("EdgeRebar=\"") + m_edgerebar + _T("\"");
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("LinkRebar=")) != -1)
		{
			CString temp;
			temp = _T("LinkRebar=\"") + m_linkrebar + _T("\"");
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("BeamLinkSpace=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("AccelGravity=%.0f"), m_beamlinkspace);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("SlabDefaultThickness=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("SlabDefaultThickness=%.0f"), m_slabdethickness);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("WallDefaultThickness=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("WallDefaultThickness=%.0f"), m_walldethickness);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("WallSeisGrade=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("WallSeisGrade=%d"), m_wallseisgrade.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("FrameSeisGrade=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("FrameSeisGrade=%d"), m_colseisgrade.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("SlabSeisGrade=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("SlabSeisGrade=%d"), m_slabseisgrade.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("SeisDetailsGrade=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("SeisDetailsGrade=%d"), m_seisdetailgrade.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("FortificationCategory=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("FortificationCategory=%d"), m_forticategory.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("FieldClass=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("FieldClass=%d"), m_fieldclass.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("FieldGroup=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("FieldGroup=%d"), m_fieldgroup.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("EarthQuakeGrade=")) != -1)
		{
			CString temp;
			m_eqgrade.GetLBText(m_eqgrade.GetCurSel(),temp);
			temp = TEXT("EarthQuakeGrade=") + temp;
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("EarthQuakeProbility=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("EarthQuakeProbility=%d"), m_eqgradeprobility.GetCurSel());
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("BeamRebarDiameter=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("BeamRebarDiameter=%.0f"), m_beamrebardiameter);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("ColumnRebarDiameter=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("ColumnRebarDiameter=%.0f"), m_colrebardiameter);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("SlabRebarRatio=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("SlabRebarRatio=%.2f"), m_slabrebarratio);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("WallRebarRatio=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("WallRebarRatio=%.2f"), m_wallrebarratio);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("BeamRebarRatio=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("BeamRebarRatio=%.1f"), m_beamrebarratio);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}
		if (sLine.Find(TEXT("ColumnRebarRatio=")) != -1)
		{
			CString temp;
			temp.Format(TEXT("ColumnRebarRatio=%.1f"), m_colrebarratio);
			sNewLine = temp;
			cNewFile.WriteString(sNewLine + _T("\n"));
			cFile.ReadString(sLine);
		}


		cNewFile.WriteString(sLine + _T("\n"));

	}
	cFile.Close();
	cNewFile.Close();
	cFile.Remove(sPath);
	cNewFile.Rename(sNewPath, sPath);
	return 0;
}







