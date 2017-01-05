#pragma once
#include "afxwin.h"


// CSudokuQuit 对话框

class CSudokuQuit : public CDialogEx
{
	DECLARE_DYNAMIC(CSudokuQuit)

public:
	CSudokuQuit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSudokuQuit();
	CFont m_editFont;	//*&&*

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cAskQuit;
	CString m_vAskQuit;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
