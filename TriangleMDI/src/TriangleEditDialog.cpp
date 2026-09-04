// CTriangleEditDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication_OOP_Week_8.h"
#include "afxdialogex.h"
#include "TriangleEditDialog.h"


// CTriangleEditDialog 对话框

IMPLEMENT_DYNAMIC(CTriangleEditDialog, CDialogEx)

CTriangleEditDialog::CTriangleEditDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CORRDINATES, pParent)
{

}

CTriangleEditDialog::~CTriangleEditDialog()
{
}

void CTriangleEditDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_POINT_1_X, x1);
	DDX_Text(pDX, IDC_POINT_1_Y, y1);
	DDX_Text(pDX, IDC_POINT_2_X, x2);
	DDX_Text(pDX, IDC_POINT_2_Y, y2);
	DDX_Text(pDX, IDC_POINT_3_X, x3);
	DDX_Text(pDX, IDC_POINT_3_Y, y3);
}


BEGIN_MESSAGE_MAP(CTriangleEditDialog, CDialogEx)
END_MESSAGE_MAP()


// CTriangleEditDialog 消息处理程序
