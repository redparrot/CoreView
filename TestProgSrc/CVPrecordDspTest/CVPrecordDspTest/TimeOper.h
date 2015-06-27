#pragma once

class CTimeOper
{
public:
	CTimeOper(void);
public:
	~CTimeOper(void);
public:
	time_t GetCurTime(void);
	CString CTimeOper::GetYMD(time_t timer, BYTE Type = 0);
	void CTimeOper::GetYMD(time_t timer, BYTE Type, char* szYMD);
	CString CTimeOper::GetHMS(time_t timer);
	void CTimeOper::GetHMS(time_t timer, char* szHMS);
	time_t CTimeOper::GetTime_T(struct tm LocalTime);
	struct tm CTimeOper::GetTMStruct(time_t timer);
};
