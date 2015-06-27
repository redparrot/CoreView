#pragma once
#include <vector>
using namespace std;

class CMimicFile
{
public:
	CMimicFile(void);
public:
	~CMimicFile(void);
	int GetMimicList(vector<CString>& MimicInfoList);
	BOOL CheckGrbValid(CString Grbiid);
};
