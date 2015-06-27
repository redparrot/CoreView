#pragma once
#include "cvtagcommondef.h"

const int AlarmMax = 5000;
const CString MemName = "AlmDispMem";

typedef struct AlarmShareMem
{
	time_t time;
	long IID;
	float value;
	float Limit;//限值或者突变前值
	char state;
	BYTE CurAlmChgFlg;
	time_t EscTime;
}SAlarmShareMem;


