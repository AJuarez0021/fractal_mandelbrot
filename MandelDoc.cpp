// MandelDoc.cpp : implementation of the CMandelDoc class
//

#include "stdafx.h"
#include "Mandel.h"

#include "MandelDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMandelDoc

IMPLEMENT_DYNCREATE(CMandelDoc, CDocument)

BEGIN_MESSAGE_MAP(CMandelDoc, CDocument)
	//{{AFX_MSG_MAP(CMandelDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMandelDoc construction/destruction

CMandelDoc::CMandelDoc()
{
}

CMandelDoc::~CMandelDoc()
{
}

BOOL CMandelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMandelDoc serialization

void CMandelDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMandelDoc diagnostics

#ifdef _DEBUG
void CMandelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMandelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMandelDoc commands
