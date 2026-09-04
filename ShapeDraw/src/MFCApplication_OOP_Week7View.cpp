
// MFCApplication_OOP_Week7View.cpp: CMFCApplicationOOPWeek7View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication_OOP_Week7.h"
#endif

#include "MFCApplication_OOP_Week7Doc.h"
#include "MFCApplication_OOP_Week7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include"DrawShapes.h"
// CMFCApplicationOOPWeek7View

IMPLEMENT_DYNCREATE(CMFCApplicationOOPWeek7View, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationOOPWeek7View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFCApplicationOOPWeek7View 构造/析构

CMFCApplicationOOPWeek7View::CMFCApplicationOOPWeek7View() noexcept
{
	// TODO: 在此处添加构造代码
	
}

CMFCApplicationOOPWeek7View::~CMFCApplicationOOPWeek7View()
{
}

BOOL CMFCApplicationOOPWeek7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationOOPWeek7View 绘图

void CMFCApplicationOOPWeek7View::OnDraw(CDC* pDC)
{
	CMFCApplicationOOPWeek7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	DrawCircle(*pDC, pDoc->face, PS_SOLID, 231, 108, 163);

	DrawEllipse(*pDC, pDoc->leftEyeWhite, PS_SOLID, 255, 255, 255);
	DrawEllipse(*pDC, pDoc->rightEyeWhite, PS_SOLID, 255, 255, 255);
	DrawEllipse(*pDC, pDoc->leftEyeBlue, PS_SOLID, 0, 159, 233);
	DrawEllipse(*pDC, pDoc->rightEyeBlue, PS_SOLID, 0, 159, 233);

	DrawArc(*pDC, pDoc->mouthArc1, PS_SOLID, 0, 0, 0);
	DrawArc(*pDC, pDoc->mouthArc2, PS_SOLID, 0, 0, 0);

	// TODO: 在此处为本机数据添加绘制代码

	

}


// CMFCApplicationOOPWeek7View 打印

BOOL CMFCApplicationOOPWeek7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationOOPWeek7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplicationOOPWeek7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplicationOOPWeek7View 诊断

#ifdef _DEBUG
void CMFCApplicationOOPWeek7View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationOOPWeek7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationOOPWeek7Doc* CMFCApplicationOOPWeek7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationOOPWeek7Doc)));
	return (CMFCApplicationOOPWeek7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationOOPWeek7View 消息处理程序
