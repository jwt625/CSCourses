#pragma once


// CStdAns 对话框

class CStdAns : public CDialogEx
{
	DECLARE_DYNAMIC(CStdAns)

public:
	CStdAns(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStdAns();
	CFont m_Font;	//*&&*
	void InitSUDOKUmap();	//*&&*
	CEdit* SUDOKUmap[9][9];	//*&&*
	int BlankMAT[9][9];	//*&&*
	CBrush BlankBrush;	//*&&*
	CBrush NumBrush;	//*&&*
	bool IsBlank(CWnd* pWnd);	//*&&*
	bool IsNumOccupied(CWnd* pWnd);	//*&&*
	void UpdateStdAnsData();	//*&&*
	int* SUDOKUValmap[9][9];	//*&&*

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);//********************************************

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int m_editA1;
	int m_editA2;
	int m_editA3;
	int m_editA4;
	int m_editA5;
	int m_editA6;
	int m_editA7;
	int m_editA8;
	int m_editA9;
	int m_editB1;
	int m_editB2;
	int m_editB3;
	int m_editB4;
	int m_editB5;
	int m_editB6;
	int m_editB7;
	int m_editB8;
	int m_editB9;
	int m_editC1;
	int m_editC2;
	int m_editC3;
	int m_editC4;
	int m_editC5;
	int m_editC6;
	int m_editC7;
	int m_editC8;
	int m_editC9;
	int m_editD1;
	int m_editD2;
	int m_editD3;
	int m_editD4;
	int m_editD5;
	int m_editD6;
	int m_editD7;
	int m_editD8;
	int m_editD9;
	int m_editE1;
	int m_editE2;
	int m_editE3;
	int m_editE4;
	int m_editE5;
	int m_editE6;
	int m_editE7;
	int m_editE8;
	int m_editE9;
	int m_editF1;
	int m_editF2;
	int m_editF3;
	int m_editF4;
	int m_editF5;
	int m_editF6;
	int m_editF7;
	int m_editF8;
	int m_editF9;
	int m_editG1;
	int m_editG2;
	int m_editG3;
	int m_editG4;
	int m_editG5;
	int m_editG6;
	int m_editG7;
	int m_editG8;
	int m_editG9;
	int m_editH1;
	int m_editH2;
	int m_editH3;
	int m_editH4;
	int m_editH5;
	int m_editH6;
	int m_editH7;
	int m_editH8;
	int m_editH9;
	int m_editI1;
	int m_editI2;
	int m_editI3;
	int m_editI4;
	int m_editI5;
	int m_editI6;
	int m_editI7;
	int m_editI8;
	int m_editI9;
	CEdit m_cA1;
	CEdit m_cA2;
	CEdit m_cA3;
	CEdit m_cA4;
	CEdit m_cA5;
	CEdit m_cA6;
	CEdit m_cA7;
	CEdit m_cA8;
	CEdit m_cA9;
	CEdit m_cB1;
	CEdit m_cB2;
	CEdit m_cB3;
	CEdit m_cB4;
	CEdit m_cB5;
	CEdit m_cB6;
	CEdit m_cB7;
	CEdit m_cB8;
	CEdit m_cB9;
	CEdit m_cC1;
	CEdit m_cC2;
	CEdit m_cC3;
	CEdit m_cC4;
	CEdit m_cC5;
	CEdit m_cC6;
	CEdit m_cC7;
	CEdit m_cC8;
	CEdit m_cC9;
	CEdit m_cD1;
	CEdit m_cD2;
	CEdit m_cD3;
	CEdit m_cD4;
	CEdit m_cD5;
	CEdit m_cD6;
	CEdit m_cD7;
	CEdit m_cD8;
	CEdit m_cD9;
	CEdit m_cE1;
	CEdit m_cE2;
	CEdit m_cE3;
	CEdit m_cE4;
	CEdit m_cE5;
	CEdit m_cE6;
	CEdit m_cE7;
	CEdit m_cE8;
	CEdit m_cE9;
	CEdit m_cF1;
	CEdit m_cF2;
	CEdit m_cF3;
	CEdit m_cF4;
	CEdit m_cF5;
	CEdit m_cF6;
	CEdit m_cF7;
	CEdit m_cF8;
	CEdit m_cF9;
	CEdit m_cG1;
	CEdit m_cG2;
	CEdit m_cG3;
	CEdit m_cG4;
	CEdit m_cG5;
	CEdit m_cG6;
	CEdit m_cG7;
	CEdit m_cG8;
	CEdit m_cG9;
	CEdit m_cH1;
	CEdit m_cH2;
	CEdit m_cH3;
	CEdit m_cH4;
	CEdit m_cH5;
	CEdit m_cH6;
	CEdit m_cH7;
	CEdit m_cH8;
	CEdit m_cH9;
	CEdit m_cI1;
	CEdit m_cI2;
	CEdit m_cI3;
	CEdit m_cI4;
	CEdit m_cI5;
	CEdit m_cI6;
	CEdit m_cI7;
	CEdit m_cI8;
	CEdit m_cI9;
};
