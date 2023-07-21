
#include "CDataFile.h"
#include "afxdialogex.h"
#include "afxcmn.h"
#include "afx.h"
#include "pch.h"
#include "tchar.h"

IMPLEMENT_DYNAMIC(CDataFile, CStdioFile)

CDataFile::CDataFile()
{
    sSplitFlag=" ";
}

CDataFile::~CDataFile()
{
    
}


CString CDataFile::sData = " ";
CStringArray CDataFile::arrInfo = { };

void CDataFile::SetData(CString sLine)
{
    sData = sLine;
    sData.TrimLeft();//ȥ���ַ�����ߵĿո�
    sData.TrimRight();
    
}

CString CDataFile::GetStr()
{
    
    if (sData.Right(1) != sSplitFlag) sData += sSplitFlag;
    CString sTemp;
    int iPos = -1;
    iPos = sData.Find(sSplitFlag, 0);//��ͷ��ʼ�����ָ���
    sTemp = sData.Left(iPos);//��ȡ�ָ���ǰ����ַ���
    while (sTemp.IsEmpty() || sTemp == " ")
    {
        iPos++;
    }
    sTemp = sData.Left(iPos);
    if(!sTemp.IsEmpty() && sTemp != " ")
    {
        sData = sData.Right(sData.GetLength() - iPos - 1);
        SetData(sData);
        arrInfo.Add(sTemp);
        return (sTemp);
    }
    
}

int CDataFile::GetInt()
{
    if (sData.Right(1) != sSplitFlag) sData += sSplitFlag;
    CString sTemp;
    int iPos = -1;
    iPos = sData.Find(sSplitFlag, 0);//��ͷ��ʼ�����ָ���
    sTemp = sData.Left(iPos);//��ȡ�ָ���ǰ����ַ���
    while (sTemp.IsEmpty() || sTemp == " ")
    {
        iPos++;
    }
    sTemp = sData.Left(iPos);
    if (!sTemp.IsEmpty() && sTemp != " ")
    {
        sData = sData.Right(sData.GetLength() - iPos - 1);
        SetData(sData);
        arrInfo.Add(sTemp);
        return _ttoi(sTemp);
    }
}

float CDataFile::GetFloat()
{
    if (sData.Right(1) != sSplitFlag) sData += sSplitFlag;
    CString sTemp;
    int iPos = -1;
    iPos = sData.Find(sSplitFlag, 0);//��ͷ��ʼ�����ָ���
    sTemp = sData.Left(iPos);//��ȡ�ָ���ǰ����ַ���
    while (sTemp.IsEmpty() || sTemp == " ")
    {
        iPos++;
    }
    sTemp = sData.Left(iPos);
    if (!sTemp.IsEmpty() && sTemp != " ")
    {
        sData = sData.Right(sData.GetLength() - iPos - 1);
        SetData(sData);
        arrInfo.Add(sTemp);
        return _ttof(sTemp);
    }
}


