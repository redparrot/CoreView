#include "StdAfx.h"
#include "TimeOper.h"

CTimeOper::CTimeOper(void)
{
}

CTimeOper::~CTimeOper(void)
{
}

time_t CTimeOper::GetCurTime(void)
{
	time_t timer;

	time(&timer);

	return timer;
}

void CTimeOper::GetYMD(time_t timer, BYTE Type, char* szYMD)
{
	struct tm LocalTime;

	localtime_s(&LocalTime, &timer);

	switch(Type)
	{
	case 0:
		sprintf_s(szYMD, 12, "%04d/%02d/%02d", LocalTime.tm_year + 1900, LocalTime.tm_mon + 1, LocalTime.tm_mday);
		break;
	case 1:
		sprintf_s(szYMD, 12, "%02d%02d%02d", LocalTime.tm_year + 1900 - 2000, LocalTime.tm_mon + 1, LocalTime.tm_mday);
		break;
	default:
		break;
	}

	return;
}

CString CTimeOper::GetYMD(time_t timer, BYTE Type)
{
	struct tm LocalTime;
	CString YMDStr;

	localtime_s(&LocalTime, &timer);
	switch(Type)
	{
	case 0:
		YMDStr.Format("%d/%02d/%02d", LocalTime.tm_year + 1900, LocalTime.tm_mon + 1, LocalTime.tm_mday);
		break;
	case 1:
		YMDStr.Format("%02d%02d%02d", LocalTime.tm_year + 1900 - 2000, LocalTime.tm_mon + 1, LocalTime.tm_mday);
	    break;
	default:
	    break;
	}

	return YMDStr;
}

struct tm CTimeOper::GetTMStruct(time_t timer)
{
	struct tm LocalTime;

	localtime_s(&LocalTime, &timer);

	return LocalTime;
}

void CTimeOper::GetHMS(time_t timer, char* szHMS)
{
	struct tm LocalTime;
	CString HMSStr;

	localtime_s(&LocalTime, &timer);
	sprintf_s(szHMS, 12, "%02d:%02d:%02d", LocalTime.tm_hour, LocalTime.tm_min, LocalTime.tm_sec);

	return;
}

CString CTimeOper::GetHMS(time_t timer)
{
	struct tm LocalTime;
	CString HMSStr;

	localtime_s(&LocalTime, &timer);
	HMSStr.Format("%02d:%02d:%02d", LocalTime.tm_hour, LocalTime.tm_min, LocalTime.tm_sec);

	return HMSStr;
}

time_t CTimeOper::GetTime_T(struct tm LocalTime)
{
	time_t time = mktime(&LocalTime);

	return time;
}

