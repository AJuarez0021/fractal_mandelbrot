// MandelView.h : interface of the CMandelView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANDELVIEW_H__BE615C56_A891_4688_8143_ECFBB12B9567__INCLUDED_)
#define AFX_MANDELVIEW_H__BE615C56_A891_4688_8143_ECFBB12B9567__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <complex>
#include <fstream>
#define SIZE 255
using namespace std;

typedef struct{
	BYTE Rojo;
	BYTE Verde;
	BYTE Azul;
}Color;

class CMandelView : public CView
{
protected: // create from serialization only
	CMandelView();
	DECLARE_DYNCREATE(CMandelView)

// Attributes
public:
	CMandelDoc* GetDocument();

// Operations
public:
   void LoadPaleta(LPSTR);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMandelView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMandelView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
private:
    //coordenadas del plando complejo
    double REALMIN,IMAGMIN,REALMAX,IMAGMAX;
	float DIVERGE; //valor de divergencia
    int MAX;       //iteracion maxima
    int maxx,maxy;
	int i,j;
    int Contador;
	DWORD R,G,B;
	ifstream f;
	LPSTR Buffer;	
    typedef Color TipoPaleta[256];
    TipoPaleta Paleta;
protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMandelView)
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MandelView.cpp
inline CMandelDoc* CMandelView::GetDocument()
   { return (CMandelDoc*)m_pDocument; }
#endif


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANDELVIEW_H__BE615C56_A891_4688_8143_ECFBB12B9567__INCLUDED_)
