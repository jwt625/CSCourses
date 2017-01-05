// SudokuQuit.cpp : 实现文件
//

#include "stdafx.h"
#include "SUDOKUMFC.h"
#include "SudokuQuit.h"
#include "afxdialogex.h"


// CSudokuQuit 对话框

IMPLEMENT_DYNAMIC(CSudokuQuit, CDialogEx)

CSudokuQuit::CSudokuQuit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSudokuQuit::IDD, pParent)
	, m_vAskQuit(_T(""))
{
	
}

CSudokuQuit::~CSudokuQuit()
{
}

void CSudokuQuit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_cAskQuit);
	DDX_Text(pDX, IDC_EDIT1, m_vAskQuit);
}


BEGIN_MESSAGE_MAP(CSudokuQuit, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSudokuQuit::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSudokuQuit::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSudokuQuit 消息处理程序


void CSudokuQuit::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CSudokuQuit::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


BOOL CSudokuQuit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_editFont.CreatePointFont(160, _T("华文彩云"));	//*&&*修改字体   
	// 设置新字体
	m_cAskQuit.SetFont(&m_editFont); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
