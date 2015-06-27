#include "StdAfx.h"
#include "MimicFile.h"
#include <io.h>

CMimicFile::CMimicFile(void)
{
}

CMimicFile::~CMimicFile(void)
{
}

#define MIMICSYSCONFINI		"C:\\CoreView\\FuncExec\\CVMimicExec\\Configure\\mimicsysconf.cyt"
int CMimicFile::GetMimicList(vector<CString>& MimicInfoList)
{
	DWORD t1 = GetTickCount();
	char				SrcfilePathFile[255];
	WIN32_FIND_DATA     FindFileData;
	HANDLE				handle;
	MimicInfoList.clear();

	//获取系统图存放路径
	char SrcfilePath[255];
	GetPrivateProfileString("Drawings Dir", "MimicPath", "C:\\Drawings", SrcfilePath, 255, MIMICSYSCONFINI);

	//判断路径是否存在
	if (_access(SrcfilePath, 0) == -1)
	{
		return -1;
	}
	sprintf_s(SrcfilePathFile, "%s\\*.grb", SrcfilePath);
	handle = FindFirstFile(SrcfilePathFile, &FindFileData);
	if (handle != INVALID_HANDLE_VALUE)
	{
		BOOL		bResult = TRUE;
		CString		csGrb;
		while (bResult)
		{
			csGrb.Format("%s", FindFileData.cFileName);
			if(csGrb.GetLength() != 12)
			{
				bResult = FindNextFile(handle, &FindFileData);
				continue;
			}
			csGrb.MakeUpper();
			csGrb = csGrb.Left(8);

			//检查图是否合法的图
			if(CheckGrbValid(csGrb) == TRUE)
			{
				MimicInfoList.push_back(csGrb);

				//修改文件名为全大写
				CString OriFile = FindFileData.cFileName;
				CString DstFile = OriFile;
				if (OriFile != DstFile.MakeUpper())
				{
					CString PathFile;
					PathFile.Format("%s\\%s", SrcfilePath, DstFile);
					BOOL b = MoveFile(PathFile, PathFile);
				}
			}
			bResult = FindNextFile(handle, &FindFileData);
		}
	}
	FindClose(handle);

	DWORD t2 = GetTickCount();
	TRACE("GetMimicInfoList()耗时=%dms\n", t2 - t1);

	return (int)MimicInfoList.size();
}

BOOL CMimicFile::CheckGrbValid(CString Grbiid)
{
	CString Grbtmp;

	Grbtmp = Grbiid.MakeUpper().Trim();
	if(Grbtmp.Left(2) != "GR")
		return FALSE;
	if(Grbtmp.GetLength() != 8)
		return FALSE;

	for(int i = 2; i < 8; i++)
	{
		if( Grbtmp.Mid(i, 1) < "0" || Grbtmp.Mid(i, 1) > "9" )
		{
			return(FALSE);
		}
	}

	return TRUE;
}

