// MandelView.cpp : implementation of the CMandelView class
//

#include "stdafx.h"
#include "Mandel.h"

#include "MandelDoc.h"
#include "MandelView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMandelView

IMPLEMENT_DYNCREATE(CMandelView, CView)

BEGIN_MESSAGE_MAP(CMandelView, CView)
	//{{AFX_MSG_MAP(CMandelView)
	ON_WM_PAINT()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMandelView construction/destruction

CMandelView::CMandelView()
{
	Buffer=new char[SIZE];
	LoadPaleta("paleta.pal");
	REALMIN=-2.0; 
    IMAGMIN=-1.5; 
    REALMAX= 1.0; 
    IMAGMAX= 1.5; 
	DIVERGE=4.0;
	MAX=256;
}

CMandelView::~CMandelView()
{
	delete [] Buffer;
}

BOOL CMandelView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMandelView drawing

void CMandelView::OnDraw(CDC* pDC)
{
	CMandelDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
}

/////////////////////////////////////////////////////////////////////////////
// CMandelView diagnostics

#ifdef _DEBUG
void CMandelView::AssertValid() const
{
	CView::AssertValid();
}

void CMandelView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMandelDoc* CMandelView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMandelDoc)));
	return (CMandelDoc*)m_pDocument;
}
#endif //_DEBUG

void CMandelView::LoadPaleta(LPSTR Name)
{
	f.open(Name);
	for(i=0;i<256;i++){
		f.getline(Buffer,SIZE+1,'\n');
		sscanf(Buffer,"%d %d %d",&R,&G,&B);
		Paleta[i].Rojo= R;
		Paleta[i].Verde=G;
		Paleta[i].Azul= B;
	}
	f.close();
}
/////////////////////////////////////////////////////////////////////////////
// CMandelView message handlers

void CMandelView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	complex<double> Z,C;
	for(i=0;i<maxx;++i)
	  for(j=0;j<maxy;++j){        
			 //asignamos a C las coordenadas del plano complejo
		     C.real(((REALMAX-REALMIN)/(maxx)) * i + REALMIN);
			 C.imag(((IMAGMAX-IMAGMIN)/(maxy)) * j + IMAGMIN);
		     
			 Contador=0; //inicializamos el contador
			 //iniciamos Z=0+0i
			 Z.real(0.0);
			 Z.imag(0.0);
		   do{
		     Z=(Z*Z)+C; //ecuacion Z=Z²+C
		     Contador++;//incrementamos el contador			 
		     if(norm(Z)>DIVERGE) break;
		   }while(Contador<MAX);
		  
		  R=Paleta[Contador+5].Rojo;
		  G=Paleta[Contador+10].Verde;
		  B=Paleta[Contador+15].Azul;
		  if(Contador==MAX)
	        dc.SetPixel(i,maxy-j,RGB(0,0,0));
	      else              	          
		    dc.SetPixel(i,maxy-j,RGB(R,G,B));
		    
	  }
	// TODO: Add your message handler code here
	
	// Do not call CView::OnPaint() for painting messages
}

void CMandelView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	maxx=cx;
	maxy=cy;
}
