
// MFCApplication_OOP_Week7Doc.h: CMFCApplicationOOPWeek7Doc 类的接口
//


#pragma once
#include "Arc2D.h"
#include "Circle2D.h"
#include "Ellipse2D.h"

class CMFCApplicationOOPWeek7Doc : public CDocument
{
protected: // 仅从序列化创建
	CMFCApplicationOOPWeek7Doc() noexcept;
	DECLARE_DYNCREATE(CMFCApplicationOOPWeek7Doc)

// Data: the custom shapes that make up the picture
public:
	Circle2D face;                             // the round face
	Arc2D mouthArc1, mouthArc2;                // two arcs that form the smile
	Ellipse2D leftEyeWhite, rightEyeWhite;     // white eye bases
	Ellipse2D leftEyeBlue, rightEyeBlue;       // blue eye centres
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMFCApplicationOOPWeek7Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
