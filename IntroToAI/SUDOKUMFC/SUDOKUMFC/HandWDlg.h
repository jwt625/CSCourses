#pragma once


// CHandWDlg �Ի���

class CHandWDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHandWDlg)

public:
	CHandWDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHandWDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStartwrite();
	afx_msg void OnDeltaposBrushspin(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedImagestore();
	afx_msg void OnBnClickedStartclassify();
	afx_msg void OnBnClickedQuitwrite();
};
