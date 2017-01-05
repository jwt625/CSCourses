// HandWDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SUDOKUMFC.h"
#include "HandWDlg.h"
#include "afxdialogex.h"


// CHandWDlg 对话框

IMPLEMENT_DYNAMIC(CHandWDlg, CDialogEx)

CHandWDlg::CHandWDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHandWDlg::IDD, pParent)
{

}

CHandWDlg::~CHandWDlg()
{
}

void CHandWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHandWDlg, CDialogEx)
	ON_BN_CLICKED(IDC_STARTWRITE, &CHandWDlg::OnBnClickedStartwrite)
	ON_NOTIFY(UDN_DELTAPOS, IDC_BRUSHSPIN, &CHandWDlg::OnDeltaposBrushspin)
	ON_BN_CLICKED(IDC_IMAGESTORE, &CHandWDlg::OnBnClickedImagestore)
	ON_BN_CLICKED(IDC_STARTCLASSIFY, &CHandWDlg::OnBnClickedStartclassify)
	ON_BN_CLICKED(IDC_QUITWRITE, &CHandWDlg::OnBnClickedQuitwrite)
END_MESSAGE_MAP()


// CHandWDlg 消息处理程序


void CHandWDlg::OnBnClickedStartwrite()
{
	// TODO: 在此添加控件通知处理程序代码

	CWnd* pCWnd = GetParent();
	::SendMessage(pCWnd->m_hWnd, WM_STARTDRAW, 0, 0);
}


void CHandWDlg::OnDeltaposBrushspin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	if(pNMUpDown-> iDelta == 1) // 如果此值为1 , 说明点击了Spin的往下箭头 
	{  
		CWnd* pCWnd = GetParent();
		::SendMessage(pCWnd->m_hWnd, WM_BRUSHSPIN, 0, 0);
    } 
	else if(pNMUpDown-> iDelta == -1) // 如果此值为-1 , 说明点击了Spin的往上箭头 
    { 
		CWnd* pCWnd = GetParent();
		::SendMessage(pCWnd->m_hWnd, WM_BRUSHSPINN, 0, 0);
    }
}


void CHandWDlg::OnBnClickedImagestore()
{
	// TODO: 在此添加控件通知处理程序代码

	CWnd* pCWnd = GetParent();
	::SendMessage(pCWnd->m_hWnd, WM_IMAGESTORE, 0, 0);
}


void CHandWDlg::OnBnClickedStartclassify()
{
	// TODO: 在此添加控件通知处理程序代码

	CWnd* pCWnd = GetParent();
	::SendMessage(pCWnd->m_hWnd, WM_STARTCLASSIFY, 0, 0);
}


void CHandWDlg::OnBnClickedQuitwrite()
{
	// TODO: 在此添加控件通知处理程序代码

	CWnd* pCWnd = GetParent();
	::SendMessage(pCWnd->m_hWnd, WM_QUITDRAW, 0, 0);
	//AfxGetMainWnd()->SendMessage(WM_CLOSE);
	//::SendMessage(pCWnd->m_hWnd, WM_QUITDRAW, 0, 0);
	OnOK(); 
}
