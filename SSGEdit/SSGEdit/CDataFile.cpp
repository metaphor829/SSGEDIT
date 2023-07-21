
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
    sData.TrimLeft();//去掉字符串左边的空格
    sData.TrimRight();
    
}

CString CDataFile::GetStr()
{
    
    if (sData.Right(1) != sSplitFlag) sData += sSplitFlag;
    CString sTemp;
    int iPos = -1;
    iPos = sData.Find(sSplitFlag, 0);//从头开始搜索分隔符
    sTemp = sData.Left(iPos);//截取分隔符前面的字符串
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
    iPos = sData.Find(sSplitFlag, 0);//从头开始搜索分隔符
    sTemp = sData.Left(iPos);//截取分隔符前面的字符串
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
    iPos = sData.Find(sSplitFlag, 0);//从头开始搜索分隔符
    sTemp = sData.Left(iPos);//截取分隔符前面的字符串
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


