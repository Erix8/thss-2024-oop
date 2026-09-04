
// MFCApplication_OOP_Week_8View.h: CMFCApplicationOOPWeek8View 类的接口
//

#pragma once


class CMFCApplicationOOPWeek8View : public CView
{
protected: // 仅从序列化创建
	CMFCApplicationOOPWeek8View() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationOOPWeek8View)

// 特性
public:
	CMFCApplicationOOPWeek8Doc* GetDocument() const;
	int m_mode, m_clickCount;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplicationOOPWeek8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnResetTriangle();
	afx_msg void OnUpdateResetTriangle(CCmdUI* pCmdUI);
	afx_msg void OnEditVertex1();
	afx_msg void OnUpdateEditVertex1(CCmdUI* pCmdUI);
	afx_msg void OnEditVertex2();
	afx_msg void OnUpdateEditVertex2(CCmdUI* pCmdUI);
	afx_msg void OnEditVertex3();
	afx_msg void OnUpdateEditVertex3(CCmdUI* pCmdUI);
	afx_msg void OnEditCoordinates();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication_OOP_Week_8View.cpp 中的调试版本
inline CMFCApplicationOOPWeek8Doc* CMFCApplicationOOPWeek8View::GetDocument() const
   { return reinterpret_cast<CMFCApplicationOOPWeek8Doc*>(m_pDocument); }
#endif

