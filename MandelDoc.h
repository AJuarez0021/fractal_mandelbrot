// MandelDoc.h : interface of the CMandelDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANDELDOC_H__D85D36C4_5D14_41FA_86CD_1A983E475BBD__INCLUDED_)
#define AFX_MANDELDOC_H__D85D36C4_5D14_41FA_86CD_1A983E475BBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMandelDoc : public CDocument
{
protected: // create from serialization only
	CMandelDoc();
	DECLARE_DYNCREATE(CMandelDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMandelDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMandelDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMandelDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANDELDOC_H__D85D36C4_5D14_41FA_86CD_1A983E475BBD__INCLUDED_)
