#pragma once

class CMimic
{
public:
	CMimic(void);
public:
	~CMimic(void);
public:
	void Start(CString GrName);
	void Close(CString GrName);
	CString GetGrNum(CString GrName);
	CString GetGrName(int GrNum);
};
