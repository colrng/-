#include "pch.h"
#include "framework.h"
#ifndef SHARED_HANDLERS
#include "quiz2-3.h"
#endif

#include "quiz2-3Doc.h"
#include "quiz2-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cquiz23View

IMPLEMENT_DYNCREATE(Cquiz23View, CView)

BEGIN_MESSAGE_MAP(Cquiz23View, CView)
    ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
    ON_WM_MOUSEMOVE() // OnMouseMove 메시지 핸들러를 추가합니다.
END_MESSAGE_MAP()

// Cquiz23View 생성/소멸

Cquiz23View::Cquiz23View() noexcept
{
    // TODO: 여기에 생성 코드를 추가합니다.
}

Cquiz23View::~Cquiz23View()
{
}

BOOL Cquiz23View::PreCreateWindow(CREATESTRUCT& cs)
{
    return CView::PreCreateWindow(cs);
}

// Cquiz23View 그리기

void Cquiz23View::OnDraw(CDC* pDC)
{
    Cquiz23Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);
    if (!pDoc)
        return;

    // 사각형 및 텍스트 그리기
    pDC->Rectangle(pnt.x - 150, pnt.y - 150, pnt.x + 150, pnt.y + 150);
    POINT points[3];
    points[0] = CPoint(pnt.x, pnt.y - 150); // 윗 꼭지점
    points[1] = CPoint(pnt.x + 150, pnt.y + 150); // 오른쪽 아래 꼭지점
    points[2] = CPoint(pnt.x - 150, pnt.y + 150); // 왼쪽 아래 꼭지점
    pDC->Polygon(points, 3);
    pDC->TextOut(pnt.x - 30, pnt.y, L"ANU");
}

// Cquiz23View 인쇄

BOOL Cquiz23View::OnPreparePrinting(CPrintInfo* pInfo)
{
    return DoPreparePrinting(pInfo);
}

void Cquiz23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cquiz23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
    // TODO: 인쇄 후 정리 작업을 추가합니다.
}

// Cquiz23View 진단

#ifdef _DEBUG
void Cquiz23View::AssertValid() const
{
    CView::AssertValid();
}

void Cquiz23View::Dump(CDumpContext& dc) const
{
    CView::Dump(dc);
}

Cquiz23Doc* Cquiz23View::GetDocument() const
{
    ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cquiz23Doc)));
    return (Cquiz23Doc*)m_pDocument;
}
#endif //_DEBUG

// Cquiz23View 메시지 처리기

void Cquiz23View::OnMouseMove(UINT nFlags, CPoint point)
{
    pnt = point; // Update the point
    Invalidate(1); // Trigger a redraw
    CView::OnMouseMove(nFlags, point);
}
