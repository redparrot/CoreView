#include "StdAfx.h"
#include "Mimic.h"
#include "c:\coreview_src\funcsrc\cvmimicsrc\include\cvdisplaymanagecommdll.h"

CMimic::CMimic(void)
{
}

CMimic::~CMimic(void)
{
}

void CMimic::Start( CString GrName )
{
	CString MimicCmdLine = GrName;
	int TaskID = 121;//CVMimicDisplay_Im.exe对应的任务ID
	StartProgramFromOtherProc(TaskID, true, MimicCmdLine.GetBuffer());
	MimicCmdLine.ReleaseBuffer();
}

CString CMimic::GetGrNum( CString GrName )
{
	return GrName.Right(GrName.GetLength() - 2);
}

void CMimic::Close( CString GrName )
{
	//给管理程序发消息，试图关闭本系统图
	CString GrNum = GetGrNum(GrName);
	int Num = atoi(GrNum);
	CloseOneMimic(Num);
}

CString CMimic::GetGrName(int GrNum)
{
	CString GrName;
	GrName.Format("GR%06d", GrNum);

	return GrName;
}
