#pragma once
#include "afxwin.h"


// CSudokuQuit �Ի���

class CSudokuQuit : public CDialogEx
{
	DECLARE_DYNAMIC(CSudokuQuit)

public:
	CSudokuQuit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSudokuQuit();
	CFont m_editFont;	//*&&*

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cAskQuit;
	CString m_vAskQuit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
