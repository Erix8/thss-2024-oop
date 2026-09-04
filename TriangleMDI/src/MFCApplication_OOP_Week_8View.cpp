
// MFCApplication_OOP_Week_8View.cpp: CMFCApplicationOOPWeek8View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication_OOP_Week_8.h"
#endif

#include "MFCApplication_OOP_Week_8Doc.h"
#include "MFCApplication_OOP_Week_8View.h"
#include"TriangleDrawing.h"
#include"TriangleEditDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplicationOOPWeek8View

IMPLEMENT_DYNCREATE(CMFCApplicationOOPWeek8View, CView)

BEGIN_MESSAGE_MAP(CMFCApplicationOOPWeek8View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_TRIANGLE_2D, &CMFCApplicationOOPWeek8View::OnResetTriangle)
	ON_UPDATE_COMMAND_UI(ID_EDIT_TRIANGLE_2D, &CMFCApplicationOOPWeek8View::OnUpdateResetTriangle)
	ON_COMMAND(ID_EDIT_POINT_1, &CMFCApplicationOOPWeek8View::OnEditVertex1)
	ON_UPDATE_COMMAND_UI(ID_EDIT_POINT_1, &CMFCApplicationOOPWeek8View::OnUpdateEditVertex1)
	ON_COMMAND(ID_EDIT_POINT_2, &CMFCApplicationOOPWeek8View::OnEditVertex2)
	ON_UPDATE_COMMAND_UI(ID_EDIT_POINT_2, &CMFCApplicationOOPWeek8View::OnUpdateEditVertex2)
	ON_COMMAND(ID_EDIT_POINT_3, &CMFCApplicationOOPWeek8View::OnEditVertex3)
	ON_UPDATE_COMMAND_UI(ID_EDIT_POINT_3, &CMFCApplicationOOPWeek8View::OnUpdateEditVertex3)
	ON_COMMAND(ID_EDIT_DIALOG, &CMFCApplicationOOPWeek8View::OnEditCoordinates)
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplicationOOPWeek8View 构造/析构

CMFCApplicationOOPWeek8View::CMFCApplicationOOPWeek8View() noexcept:m_mode(0),m_clickCount(0)
{
	// TODO: 在此处添加构造代码

}

CMFCApplicationOOPWeek8View::~CMFCApplicationOOPWeek8View()
{
}

BOOL CMFCApplicationOOPWeek8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplicationOOPWeek8View 绘图

void CMFCApplicationOOPWeek8View::OnDraw(CDC* pDC)
{
	CMFCApplicationOOPWeek8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	DrawTriangle(*pDC, pDoc->m_triangle, PS_SOLID);
}


// CMFCApplicationOOPWeek8View 打印

BOOL CMFCApplicationOOPWeek8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplicationOOPWeek8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplicationOOPWeek8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplicationOOPWeek8View 诊断

#ifdef _DEBUG
void CMFCApplicationOOPWeek8View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplicationOOPWeek8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplicationOOPWeek8Doc* CMFCApplicationOOPWeek8View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplicationOOPWeek8Doc)));
	return (CMFCApplicationOOPWeek8Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplicationOOPWeek8View 消息处理程序


void CMFCApplicationOOPWeek8View::OnResetTriangle()
{
	// TODO: 在此添加命令处理程序代码
	m_mode = 0;
	m_clickCount = 0;

	CMFCApplicationOOPWeek8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	pDoc->m_triangle.vertex1.x = 0;
	pDoc->m_triangle.vertex1.y = 0;
	pDoc->m_triangle.vertex2.x = 0;
	pDoc->m_triangle.vertex2.y = 0;
	pDoc->m_triangle.vertex3.x = 0;
	pDoc->m_triangle.vertex3.y = 0;
	Invalidate();
	
}


void CMFCApplicationOOPWeek8View::OnUpdateResetTriangle(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck((m_mode == 0) ? 1 : 0);
}


void CMFCApplicationOOPWeek8View::OnEditVertex1()
{
	// TODO: 在此添加命令处理程序代码
	m_mode = 1;
}


void CMFCApplicationOOPWeek8View::OnUpdateEditVertex1(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck((m_mode == 1) ? 1 : 0);
}


void CMFCApplicationOOPWeek8View::OnEditVertex2()
{
	// TODO: 在此添加命令处理程序代码
	m_mode = 2;
}


void CMFCApplicationOOPWeek8View::OnUpdateEditVertex2(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck((m_mode == 2) ? 1 : 0);
}


void CMFCApplicationOOPWeek8View::OnEditVertex3()
{
	// TODO: 在此添加命令处理程序代码
	m_mode = 3;
}


void CMFCApplicationOOPWeek8View::OnUpdateEditVertex3(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck((m_mode == 3) ? 1 : 0);
}


void CMFCApplicationOOPWeek8View::OnEditCoordinates()
{
	// TODO: 在此添加命令处理程序代码
	CMFCApplicationOOPWeek8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CTriangleEditDialog d;
	d.x1 = pDoc->m_triangle.vertex1.x;
	d.y1 = pDoc->m_triangle.vertex1.y;
	d.x2 = pDoc->m_triangle.vertex2.x;
	d.y2 = pDoc->m_triangle.vertex2.y;
	d.x3 = pDoc->m_triangle.vertex3.x;
	d.y3 = pDoc->m_triangle.vertex3.y;

	if (IDOK == d.DoModal())
	{
		pDoc->m_triangle.vertex1.x = d.x1;
		pDoc->m_triangle.vertex1.y = d.y1;
		pDoc->m_triangle.vertex2.x = d.x2;
		pDoc->m_triangle.vertex2.y = d.y2;
		pDoc->m_triangle.vertex3.x = d.x3;
		pDoc->m_triangle.vertex3.y = d.y3;
		Invalidate();
	}
	GetParentFrame()->GetMessageBar()->SetWindowText(_T("设置端点坐标！"));
}


void CMFCApplicationOOPWeek8View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplicationOOPWeek8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	switch (m_mode)
	{
	case 0:
		m_clickCount++;
		switch (m_clickCount)
		{
		case 1:
			pDoc->m_triangle.vertex1.x = point.x;
			pDoc->m_triangle.vertex1.y = point.y;
			break;
		case 2:
			pDoc->m_triangle.vertex2.x = point.x;
			pDoc->m_triangle.vertex2.y = point.y;
			break;
		case 3:
			pDoc->m_triangle.vertex3.x = point.x;
			pDoc->m_triangle.vertex3.y = point.y;
			Invalidate();
			m_clickCount = 0;
			break;
		}
		break;
	case 1:
		pDoc->m_triangle.vertex1.x = point.x;
		pDoc->m_triangle.vertex1.y = point.y;
		Invalidate();
		break;
	case 2:
		pDoc->m_triangle.vertex2.x = point.x;
		pDoc->m_triangle.vertex2.y = point.y;
		Invalidate();
		break;
	case 3:
		pDoc->m_triangle.vertex3.x = point.x;
		pDoc->m_triangle.vertex3.y = point.y;
		Invalidate();
		break;
	}
	CView::OnLButtonDown(nFlags, point);
}

