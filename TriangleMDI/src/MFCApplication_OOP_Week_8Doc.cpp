
// MFCApplication_OOP_Week_8Doc.cpp: CMFCApplicationOOPWeek8Doc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication_OOP_Week_8.h"
#endif

#include "MFCApplication_OOP_Week_8Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplicationOOPWeek8Doc

IMPLEMENT_DYNCREATE(CMFCApplicationOOPWeek8Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCApplicationOOPWeek8Doc, CDocument)
END_MESSAGE_MAP()


// CMFCApplicationOOPWeek8Doc 构造/析构

CMFCApplicationOOPWeek8Doc::CMFCApplicationOOPWeek8Doc() noexcept:m_triangle(0,0,0,0,0,0)
{
	// TODO: 在此添加一次性构造代码

}

CMFCApplicationOOPWeek8Doc::~CMFCApplicationOOPWeek8Doc()
{
}

BOOL CMFCApplicationOOPWeek8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMFCApplicationOOPWeek8Doc 序列化

void CMFCApplicationOOPWeek8Doc::Serialize(CArchive& ar)
{
	int flag;
	CString cs;
	wchar_t* buf = NULL;
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		cs.Format(_T("#Triangle2D begin\n"));
		ar.WriteString(cs);
		cs.Format(_T("%g,%g,%g,%g,%g,%g\n"),
			m_triangle.vertex1.x, m_triangle.vertex1.y,
			m_triangle.vertex2.x, m_triangle.vertex2.y,
			m_triangle.vertex3.x, m_triangle.vertex3.y);
		ar.WriteString(cs);
		cs.Format(_T("#Triangle2D end\n"));
		ar.WriteString(cs);
	}
	else
	{
		// TODO: 在此添加加载代码
		flag = 0;
		while (ar.ReadString(cs))
		{
			cs.Trim();
			if (flag == 0)
			{
				if (cs.CompareNoCase(_T("#Triangle2D begin")) == 0)
					flag = 1;
			}
			else if (flag == 1)
			{
				buf = cs.GetBuffer();
				swscanf_s(buf, _T("%lf,%lf,%lf,%lf,%lf,%lf"),
					&(m_triangle.vertex1.x), &(m_triangle.vertex1.y),
					&(m_triangle.vertex2.x), &(m_triangle.vertex2.y),
					&(m_triangle.vertex3.x), &(m_triangle.vertex3.y));
				break;
			}
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMFCApplicationOOPWeek8Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMFCApplicationOOPWeek8Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMFCApplicationOOPWeek8Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCApplicationOOPWeek8Doc 诊断

#ifdef _DEBUG
void CMFCApplicationOOPWeek8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCApplicationOOPWeek8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCApplicationOOPWeek8Doc 命令
