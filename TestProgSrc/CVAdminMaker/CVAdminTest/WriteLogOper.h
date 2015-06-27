#pragma once
#include "afxmt.h"

//Log������
class CWriteLogOper
{
public:
    CStdioFile m_LogFile;	/* Debug��Ϣ�ļ�¼�ļ� */
    int m_FileSize;			//LOG�ļ���С
    BOOL m_LogOpen;
    CCriticalSection m_Critical;
    CString m_FileName;		//LOG�ļ������ƺ�·��
    int m_MaxSize;			//LOG�ļ����޶���С
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
