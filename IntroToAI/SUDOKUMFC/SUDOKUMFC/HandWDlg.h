#pragma once


// CHandWDlg 对话框

class CHandWDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHandWDlg)

public:
	CHandWDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHandWDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStartwrite();
	afx_msg void OnDeltaposBrushspin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedImagestore();
	afx_msg void OnBnClickedStartclassify();
	afx_msg void OnBnClickedQuitwrite();
};
