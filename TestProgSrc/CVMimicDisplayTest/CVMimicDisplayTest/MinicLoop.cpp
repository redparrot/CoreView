#include "StdAfx.h"
#include "MinicLoop.h"
#include "Mimic.h"

CMimicLoop::CMimicLoop(void)
{
	BeginGrNo = -1;
	EndGrNo = -1;
	ShowGrIdx = -1;
}

CMimicLoop::~CMimicLoop(void)
{
}

void CMimicLoop::LoopDisplay(LoopDirection Driection)
{
	//获取当前显示的图号
	CString GrName;
	GrName = GetCurGrName(Driection);

	//显示指定系统图
	CMimic Mimic;
	Mimic.Start(GrName);
}

CString CMimicLoop::GetCurGrName(LoopDirection Driection)
{
	if (Driection == NEXT)
	{
		ShowGrIdx++;
		if (ShowGrIdx >= LoopList.size())
			ShowGrIdx = 0;
	}
	else
	{
		ShowGrIdx--;
		if (ShowGrIdx < 0)
			ShowGrIdx = LoopList.size() - 1;
	}

	TRACE("Show:%s\n", LoopList[ShowGrIdx]);

	return LoopList[ShowGrIdx];
}

int CMimicLoop::GetFileList(IN vector<CString>& FileList)
{
	CString Name;
	CMimic Mimic;
	LoopList.clear();
	for (int i = BeginGrNo; i <= EndGrNo; i++)
	{
		Name = Mimic.GetGrName(i);

		int pos = Find(FileList, Name);
		if (pos >= 0)
		{
			LoopList.push_back(Name);
		}
	}

	return (int)LoopList.size();
}

int CMimicLoop::Find(vector<CString>& vFindList, CString Find)
{
	vector<CString>::iterator iter;

	iter = find(vFindList.begin(), vFindList.end(), Find); 

	if (iter == vFindList.end()) 
	{ 
		return -1; 
	} 
	else
	{ 
		return int(iter - vFindList.begin()); 
	} 

	return -1;
}

