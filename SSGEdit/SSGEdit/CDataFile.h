#pragma once
#include "afxdialogex.h"
#include "pch.h"
#include <io.h>
#include <fstream> 
#include <iostream>
#include <string>
#include <cstring>
#include <tchar.h>
#include <sstream>
#include <stdio.h>
#include <direct.h>

// CDataFile文件读写处理类

class CDataFile : public CStdioFile
{
	DECLARE_DYNAMIC(CDataFile);
private:
	
public:
	
	CDataFile();
	virtual ~CDataFile();
	
	void SetData(CString sData);
	CString GetStr();
	int GetInt();
	float GetFloat();
	static CStringArray arrInfo;
	static CString sData;
	CString sSplitFlag;
	

};
