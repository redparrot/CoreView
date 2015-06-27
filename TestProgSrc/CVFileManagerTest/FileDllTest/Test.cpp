#include "StdAfx.h"
#include "Test.h"
#include "io.h"
#include "psapi.h"


CTest::CTest(void)
{
	LoopTestFlag = FALSE;
	OKTimes = 0; 
	ErrTimes = 0;
}

CTest::~CTest(void)
{
}

void CTest::ShowTestMsg(CString Msg)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int ItemCount = m_TestList->GetItemCount();

	m_TestList->InsertItem(ItemCount, Msg);
	m_TestList->EnsureVisible(ItemCount, FALSE);
}

BOOL CTest::MyCreateFile(CString FileName, size_t FileSize)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFile f;

	//f.Open();
	BOOL b = f.Open(FileName, 
		CFile::modeCreate | CFile::modeReadWrite | CFile::typeBinary);

	if (b)
	{
		char* pBuf;

		pBuf = new char[FileSize];
		memset(pBuf, 0xFF, FileSize);

		f.Write(pBuf, (UINT)FileSize);

		f.Close();

		delete pBuf;

		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL CTest::CreateDirectorys(CString szDir)
{
	int			nStart = 0;
	int			nIndex = 0;
	CString		s;
	BOOL		b = FALSE;
	BOOL		ret = TRUE;

	size_t size = strlen(szDir);

	CString Dir;
	Dir.Format("%s", szDir);

	//assert(!Dir.IsEmpty());

	if (Dir.IsEmpty())
	{
		return -1;//参数错误
	}

	nIndex = Dir.Find(":\\",nStart);
	nStart = nIndex + 2;
	if (nIndex != -1)
	{
		while (nIndex < Dir.GetLength() - 1)
		{
			nIndex = Dir.Find("\\",nStart);
			if (nIndex > 0)
			{
				s = Dir.Left(nIndex);
				b = ::CreateDirectory(s,NULL);
				if (b == FALSE)
				{
					ret = FALSE;
				}
			}
			else if (nIndex == -1)
			{
				b = ::CreateDirectory(Dir,NULL);
				if (b == FALSE)
				{
					ret = FALSE;
				}
				break;
			}
			nStart = nIndex + 1;
		}
	}
	else
	{
		nIndex = Dir.Find("$\\", nStart);
		nStart = nIndex + 2;
		if (nIndex != -1)
		{
			while (nIndex < Dir.GetLength() - 1)
			{
				nIndex = Dir.Find("\\", nStart);
				if (nIndex > 0)
				{
					s = Dir.Left(nIndex);
					b = ::CreateDirectory(s,NULL);

					if (b == FALSE)
					{
						ret = FALSE;
					}
				}
				else if (nIndex == -1)
				{
					b = ::CreateDirectory(Dir,NULL);
					if (b == FALSE)
					{
						ret = FALSE;
					}
					break;
				}
				nStart = nIndex + 1;
			}
		}
		else
		{
			ret = FALSE;
		}
	}

	return ret;
}

BOOL CTest::IsFileExist(char* ExistingFileName = NULL)
{
	//assert(strlen(ExistingFileName) != 0);

	if (strlen(ExistingFileName) == 0)
	{
		return -1;//参数错误
	}

	FILE *p1 = NULL;
	FILE *p2 = NULL;
	int filehandle = 0;
	_finddata_t fileinfo;
	//_sopen_s(&filehandle, ExistingFileName, O_RDONLY | O_, _SH_DENYNO, _S_IWRITE | _S_IREAD);
	_findfirst(ExistingFileName, &fileinfo);
	//BOOL Ret = CopyFile(ExistingFileName, NewFileName, KeepExist);

	return TRUE;
}

void CTest::TestResult(CString FuncName, BOOL TestResult)
{
	CString s;

	if (TestResult)
	{
		s.Format("%s功能通过。", FuncName);
		WriteEventLog(s);
		if (LoopTestFlag == FALSE)
		{
			ShowTestMsg(s);
		}
	}
	else
	{
		s.Format("%s功能失败！！！", FuncName);
		WriteEventLog(s);
		if (LoopTestFlag == FALSE)
		{
			ShowTestMsg(s);
		}
	}
}

BOOL CTest::WriteEventLog(LPCTSTR EventText)
{
	CStdioFile	f;
	BOOL b = FALSE;

	char* FileName = LogFileName.GetBuffer();
	LogFileName.ReleaseBuffer();

	CString csFileName(FileName);
	CString csEventText(EventText);

	if (csFileName.IsEmpty() || csEventText.IsEmpty())
	{
		return -3;
	}

	CString FilePath = FileName;
	int pos = FilePath.ReverseFind('\\');
	if (pos >= 0)
	{
		FilePath = FilePath.Left(pos);
	}
	CreateDirectorys(FilePath.GetBuffer());
	FilePath.ReleaseBuffer();

	b = f.Open(csFileName, 
		CFile::modeReadWrite|CFile::modeCreate
		|CFile::modeNoTruncate|CFile::typeText, 
		NULL);
	if (b == FALSE)
	{
		return -1;
	}

	ULONGLONG FileSize = f.GetLength();
	if (FileSize > 1024 * 100)
	{
		CString NewFileName;

		NewFileName = csFileName.Left(csFileName.GetLength() - 3) + "bak";
		f.Close();
		CopyFile(csFileName, NewFileName, FALSE);

		b = f.Open(csFileName, 
			CFile::modeReadWrite|CFile::modeCreate
			|CFile::typeText, 
			NULL);
		if (b == FALSE)
		{
			return -2;
		}
	}

	f.SeekToEnd();

	f.WriteString(csEventText);

	pos = csEventText.Find("结束");

	if (pos == -1)
	{
		pos = csEventText.Find("通过");
		if (pos >= 0)
		{
			OKTimes ++;
		}
		else
		{
			ErrTimes ++;
		}
	}

	CString s("\n");
	f.WriteString(s);

	f.Close();

	return TRUE;
}

BOOL CTest::DeleteFiles(char* strSrc, 
						HWND hWnd,
						BOOL KeepExist,
						BOOL ShowProcess)
{
	assert(strlen(strSrc) != 0);

	if (strlen(strSrc) == 0)
	{
		return -1;//参数错误
	}

	BOOL ret;
	int nOk;
	char  strTitle[] = "File Deleteing";
	SHFILEOPSTRUCT FileOp;
	FileOp.hwnd = hWnd;
	FileOp.wFunc = FO_DELETE;
	FileOp.pFrom = strSrc;
	FileOp.pTo = NULL;
	//FileOp.fFlags = FOF_ALLOWUNDO;
	if (ShowProcess == FALSE)
	{
		FileOp.fFlags |= FOF_SILENT;
	}
	if (KeepExist == FALSE)
	{
		FileOp.fFlags |= FOF_NOCONFIRMATION;
	}
	FileOp.hNameMappings = NULL;
	FileOp.lpszProgressTitle = strTitle;

	nOk = SHFileOperation(&FileOp);
	if(nOk)
		ret = FALSE;
	else
		ret = TRUE;

	return ret;
}
DWORD CTest::GetProcessId()
{
	DWORD dwProcessId = 0;
	HANDLE hProcess = NULL;

	dwProcessId = GetCurrentProcessId();
	if (dwProcessId != 0)
	{
		return dwProcessId;
	}

	return 0;
}

WORD CTest::GetMemoryInfo(DWORD processID)
{
	HANDLE hProcess;
	PROCESS_MEMORY_COUNTERS pmc;

	// Print the process identifier.

	//printf( "\nProcess ID: %u\n", processID );

	// Print information about the memory usage of the process.

	hProcess = OpenProcess(  PROCESS_QUERY_INFORMATION |
		PROCESS_VM_READ,
		FALSE, processID );
	if (NULL == hProcess)
		return 0;

	if ( GetProcessMemoryInfo( hProcess, &pmc, sizeof(pmc)) )
	{
		TRACE( "\tPageFaultCount: %d\n", pmc.PageFaultCount );
		TRACE( "\tPeakWorkingSetSize: %d\n", 
			pmc.PeakWorkingSetSize/1024 );
		TRACE( "\tWorkingSetSize: %d\n", pmc.WorkingSetSize/1024 );
		TRACE( "\tQuotaPeakPagedPoolUsage: %d\n", 
			pmc.QuotaPeakPagedPoolUsage/1024 );
		TRACE( "\tQuotaPagedPoolUsage: %d\n", 
			pmc.QuotaPagedPoolUsage/1024 );
		TRACE( "\tQuotaPeakNonPagedPoolUsage: %d\n", 
			pmc.QuotaPeakNonPagedPoolUsage/1024 );
		TRACE( "\tQuotaNonPagedPoolUsage: %d\n", 
			pmc.QuotaNonPagedPoolUsage/1024 );
		TRACE( "\tPagefileUsage: %d\n", pmc.PagefileUsage/1024 ); 
		TRACE( "\tPeakPagefileUsage: %d\n", 
			pmc.PeakPagefileUsage/1024 );
	}

	CloseHandle( hProcess );

	return (WORD)(pmc.WorkingSetSize/1024);
}







