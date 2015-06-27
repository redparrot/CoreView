#include "StdAfx.h"
#include "WriteLogOper.h"

CWriteLogOper::CWriteLogOper(void)
{
}

CWriteLogOper::~CWriteLogOper(void)
{
}

int CWriteLogOper::Open()
{
    //打开LOG文件
    m_LogOpen = m_LogFile.Open(m_FileName,
                               CFile::modeReadWrite | CFile::modeCreate
                               | CFile::modeNoTruncate | CFile::typeText | CFile::shareDenyWrite,
                               NULL);

    return 0;
}

int CWriteLogOper::Colse()
{
    if (m_LogOpen)
        m_LogFile.Close();

    return 0;
}

int CWriteLogOper::Write(LPCSTR EventText, BOOL WithTime)
{
    BOOL b = TRUE;
    CString csTime;
    int nRet = 0;
    CString NewFileName;
    SYSTEMTIME t;

    CString s = EventText;
    s += "\n";
    TRACE(s);

    if (m_LogOpen)
    {
        m_Critical.Lock();

        CString csFileName(m_FileName);
        CString csEventText(EventText);
        csFileName.Replace('/', '\\');

        if (csFileName.IsEmpty() || csEventText.IsEmpty())
        {
            nRet = -3;//参数错误
        }

        if (m_FileSize > 1024 * m_MaxSize)//如果大于文件的最大值，则备份旧文件，产生一个新文件
        {
            m_FileSize = 0;//重新统计文件文件大小
            NewFileName = csFileName.Left(csFileName.GetLength() - 3) + "bak";
            m_LogFile.Close();
            CopyFile(csFileName, NewFileName, FALSE);

            m_LogOpen = m_LogFile.Open(csFileName,
                                       CFile::modeReadWrite | CFile::modeCreate | CFile::shareDenyWrite | CFile::typeText,
                                       NULL);
            if (m_LogOpen == FALSE)
            {
                nRet = -2;//打开文件失败
            }
        }

        if (m_LogOpen)
        {
            if (WithTime)
            {
                GetLocalTime(&t);
                csTime.Format("[%02d-%02d-%02d %02d:%02d:%02d:%03d] ",
                              t.wYear,
                              t.wMonth,
                              t.wDay,
                              t.wHour,
                              t.wMinute,
                              t.wSecond,
                              t.wMilliseconds);

                csEventText = csTime + csEventText;
            }
            else
            {
                csEventText = csEventText;
            }

            csEventText += "\n";
            m_LogFile.SeekToEnd();
            m_LogFile.WriteString(csEventText);
            m_FileSize += csEventText.GetLength();

            m_LogFile.Flush();
        }
        else
        {
            nRet =  -4;
        }

        m_Critical.Unlock();
    }

    return nRet;
}

