// ProjectDocAutomationDoc.h : CProjectDocAutomationDoc ��Ľӿ�
//


#pragma once


class CProjectDocAutomationDoc : public CDocument
{
protected: // �������л�����
	CProjectDocAutomationDoc();
	DECLARE_DYNCREATE(CProjectDocAutomationDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CProjectDocAutomationDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


