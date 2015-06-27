#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class CMimicLoop
{
public:
	CMimicLoop(void);
public:
	~CMimicLoop(void);
	int BeginGrNo;
	int EndGrNo;
	int ShowGrIdx;
	vector<CString> LoopList;

	enum LoopDirection
	{
		NEXT, PREV
	};
	CString GetShowGrName() const { return LoopList[ShowGrIdx]; }
	void SetShowGrNo(int val) { ShowGrIdx = val; }
	int GetBeginGrNo() const { return BeginGrNo; }
	void SetBeginGrNo(int val) { BeginGrNo = val; }
	int GetEndGrNo() const { return EndGrNo; }
	void SetEndGrNo(int val) { EndGrNo = val; }
	void LoopDisplay(LoopDirection Driection);
	CString GetCurGrName(LoopDirection Driection);
	int GetFileList(IN vector<CString>& FileList);
	int Find(vector<CString>& vFindList, CString Find);
};
