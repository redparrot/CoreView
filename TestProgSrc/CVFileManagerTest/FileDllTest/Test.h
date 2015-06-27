#pragma once

#include "assert.h"

class CTest
{
public:
	CTest(void);
public:
	~CTest(void);
public:
	void CTest::ShowTestMsg(CString Msg);
	BOOL CTest::CreateDirectorys(CString szDir);
	BOOL CTest::IsFileExist(char* ExistingFileName);
	BOOL CTest::MyCreateFile(CString FileName, size_t FileSize);
	BOOL CTest::WriteEventLog(LPCTSTR EventText);
	void CTest::TestResult(CString FuncName, BOOL TestResult);
	BOOL CTest::DeleteFiles(char* strSrc, HWND hWnd, BOOL KeepExist, BOOL ShowProcess);
	WORD CTest::GetMemoryInfo(DWORD processID);
	DWORD CTest::GetProcessId();

public:
	CString LogFileName;
	CListCtrl* m_TestList;
	BOOL LoopTestFlag;
	int OKTimes, ErrTimes;
};
