#pragma once
#include "afxmt.h"

//Log处理类
class CWriteLogOper
{
public:
    CStdioFile m_LogFile;	/* Debug信息的记录文件 */
    int m_FileSize;			//LOG文件大小
    BOOL m_LogOpen;
    CCriticalSection m_Critical;
    CString m_FileName;		//LOG文件的名称和路径
    int m_MaxSize;			//LOG文件的限定大小
public:
    CWriteLogOper(void);
public:
    ~CWriteLogOper(void);
    int Write(LPCSTR EventText, BOOL WithTime = TRUE);
    void SetName(CString FileName)
    {
        m_FileName = FileName;
    }
    void SetMaxSize(int MaxSize)
    {
        m_MaxSize = MaxSize;
    }
    int Open();
    int Colse();
};
