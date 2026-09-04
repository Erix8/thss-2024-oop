#pragma once
#include "afxdialogex.h"


// CTriangleEditDialog 对话框

class CTriangleEditDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CTriangleEditDialog)

public:
	CTriangleEditDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTriangleEditDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CORRDINATES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	double x1, y1;
	double x2, y2;
	double x3, y3;
};
