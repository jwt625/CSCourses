// HandWDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SUDOKUMFC.h"
#include "HandWDlg.h"
#include "afxdialogex.h"


// CHandWDlg �Ի���

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


// CHandWDlg ��Ϣ�������


void CHandWDlg::OnBnClickedStartwrite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CWnd* pCWnd = GetParent();
	::SendMessage(pCWnd->m_hWnd, WM_STARTDRAW, 0, 0);
}


void CHandWDlg::OnDeltaposBrushspin(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	if(pNMUpDown-> iDelta == 1) // �����ֵΪ1 , ˵�������Spin�����¼�ͷ 
	{  
		CWnd* pCWnd = GetParent();
		::SendMessage(pCWnd->m_hWnd, WM_BRUSHSPIN, 0, 0);
    } 
	else if(pNMUpDown-> iDelta == -1) // �����ֵΪ-1 , ˵�������Spin�����ϼ�ͷ 
    { 
		CWnd* pCWnd = GetParent();
		::SendMessage(pCWnd->m_hWnd, WM_BRUSHSPINN, 0, 0);
    }
}


void CHandWDlg::OnBnClickedImagestore()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CWnd* pCWnd = GetParent();
	::SendMessage(pCWnd->m_hWnd, WM_IMAGESTORE, 0, 0);
}


void CHandWDlg::OnBnClickedStartclassify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CWnd* pCWnd = GetParent();
	::SendMessage(pCWnd->m_hWnd, WM_STARTCLASSIFY, 0, 0);
}


void CHandWDlg::OnBnClickedQuitwrite()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CWnd* pCWnd = GetParent();
	::SendMessage(pCWnd->m_hWnd, WM_QUITDRAW, 0, 0);
	//AfxGetMainWnd()->SendMessage(WM_CLOSE);
	//::SendMessage(pCWnd->m_hWnd, WM_QUITDRAW, 0, 0);
	OnOK(); 
}
