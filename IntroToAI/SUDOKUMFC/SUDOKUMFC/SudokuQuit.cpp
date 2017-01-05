// SudokuQuit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SUDOKUMFC.h"
#include "SudokuQuit.h"
#include "afxdialogex.h"


// CSudokuQuit �Ի���

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


// CSudokuQuit ��Ϣ�������


void CSudokuQuit::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CSudokuQuit::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


BOOL CSudokuQuit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_editFont.CreatePointFont(160, _T("���Ĳ���"));	//*&&*�޸�����   
	// ����������
	m_cAskQuit.SetFont(&m_editFont); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
