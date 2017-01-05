
// SUDOKUMFCDlg.h : 头文件
//
#include "StdAfx.h"	//*&&*
#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "stdafx.h"
#include "DataStruct.h"
#include "GameState.h"
#include "methods.h"
#include "graph.h"
#include "generatePuzzle.h"
#include "SudokuQuit.h"
#include "StdAns.h"


// CSUDOKUMFCDlg 对话框
class CSUDOKUMFCDlg : public CDialogEx
{
// 构造
public:
	CSUDOKUMFCDlg(CWnd* pParent = NULL);	// 标准构造函数
	void InitAllCheckBoxStatus();	//*&&*
	void InitInputCheckBoxStatus();	//*&&* 
	void GetCurrentBlankPos();	//*&&*
	void InitSUDOKUmap();	//*&&*
	void DisplayCurrentBlankPos();	//*&&*
	iMAT GetAnsMAT(iMAT ProMAT);	//*&&*
	int BlankMAT[9][9];	//*&&*
	CBrush BlankBrush;	//*&&*
	CBrush NumBrush;	//*&&*
	bool IsBlank(CWnd* pWnd);	//*&&*
	bool IsNumOccupied(CWnd* pWnd);	//*&&*
	int GetNumSol(iMAT ProMAT);	//*&&*
	int ProDesignSolMAT[9][9];	//*&&*
	int ProDesignAnsMAT[9][9];	//*&&*
	CStdAns* m_StdAns;	//*&&*

// 对话框数据
	enum { IDD = IDD_SUDOKUMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CFont m_editFont;  //*&&*字体大小
//	int* SUDOKUmap[9][9];
	//*&&*数独数据地址
	int CurrentBlankPos[2];	//*&&*当前空坐标
	CEdit* SUDOKUmap[9][9];

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);//********************************************
	//HBRUSH m_brMine;

	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
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
	CComboBox m_comboInput;
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
	CString m_sInputFile;
	int m_Inputnum;
	CString m_ProSolveRes;
	CString m_ProDesignRes;
	afx_msg void OnBnClickedProsolve();
	CComboBox m_Difficulty;
	CButton m_ProDesign;
	CButton m_Finish2;
	CButton m_StdAnswer;
	CEdit m_CPDR;
	CString m_VPDR;
	afx_msg void OnBnClickedProdesign();
	CButton m_Finish1;
	CEdit m_CFileInput;
	CString m_VFileInput;
	CEdit m_CManualInput;
//	CString m_VManualInput;
//	int m_VManualInput;
	CEdit m_CPSR;
	CString m_VPSR;
//	CSpinButtonCtrl m_SPINLR;
	CSpinButtonCtrl m_SpinLR;
	CSpinButtonCtrl m_SpinUD;
	CButton m_PS;
	CButton m_PE;
	CButton m_FileInput;
	CButton m_ManualInput;
	afx_msg void OnBnClickedFileinput();
	afx_msg void OnBnClickedManualinput();
	afx_msg void OnBnClickedCheckpe();
	afx_msg void OnBnClickedCheckps();
	afx_msg void OnDeltaposSpinud(NMHDR *pNMHDR, LRESULT *pResult);
private:
//	bool bUpOrDown;
//	bool bLeftOrRight;
public:
	afx_msg void OnDeltaposSpinlr(NMHDR *pNMHDR, LRESULT *pResult);
private:
	int nUpOrDown;
	int nLeftOrRight;
public:
	afx_msg void OnEnChangeEditmanualinput();
	int m_VManualInput;
	CEdit m_cDisplay;
	CString m_EditDisplay;
private:
	bool bPEOrPS;
	bool bFileOrManual;
public:
	afx_msg void OnBnClickedFinish1();
private:
	bool bSolveOrDesign;
public:
	CButton m_FileIn;
	afx_msg void OnBnClickedFilein();
	afx_msg void OnEnChangeEca1();
	int m_Val;
	afx_msg void OnEnChangeEca2();
	afx_msg void OnEnChangeEca3();
	afx_msg void OnEnChangeEca4();
	afx_msg void OnEnChangeEca5();
	afx_msg void OnEnChangeEca6();
	afx_msg void OnEnChangeEca7();
	afx_msg void OnEnChangeEca8();
	afx_msg void OnEnChangeEca9();
	afx_msg void OnEnChangeEcb1();
	afx_msg void OnEnChangeEcb2();
	afx_msg void OnEnChangeEcb3();
	afx_msg void OnEnChangeEcb4();
	afx_msg void OnEnChangeEcb5();
	afx_msg void OnEnChangeEcb6();
	afx_msg void OnEnChangeEcb7();
	afx_msg void OnEnChangeEcb8();
	afx_msg void OnEnChangeEcb9();
	afx_msg void OnEnChangeEcc1();
	afx_msg void OnEnChangeEcc2();
	afx_msg void OnEnChangeEcc3();
	afx_msg void OnEnChangeEcc4();
	afx_msg void OnEnChangeEcc5();
	afx_msg void OnEnChangeEcc6();
	afx_msg void OnEnChangeEcc7();
	afx_msg void OnEnChangeEcc8();
	afx_msg void OnEnChangeEcc9();
	afx_msg void OnEnChangeEcd1();
	afx_msg void OnEnChangeEcd2();
	afx_msg void OnEnChangeEcd3();
	afx_msg void OnEnChangeEcd4();
	afx_msg void OnEnChangeEcd5();
	afx_msg void OnEnChangeEcd6();
	afx_msg void OnEnChangeEcd7();
	afx_msg void OnEnChangeEcd8();
	afx_msg void OnEnChangeEcd9();
	afx_msg void OnEnChangeEce1();
	afx_msg void OnEnChangeEce2();
	afx_msg void OnEnChangeEce3();
	afx_msg void OnEnChangeEce4();
	afx_msg void OnEnChangeEce5();
	afx_msg void OnEnChangeEce6();
	afx_msg void OnEnChangeEce7();
	afx_msg void OnEnChangeEce8();
	afx_msg void OnEnChangeEce9();
	afx_msg void OnEnChangeEcf1();
	afx_msg void OnEnChangeEcf2();
	afx_msg void OnEnChangeEcf3();
	afx_msg void OnEnChangeEcf4();
	afx_msg void OnEnChangeEcf5();
	afx_msg void OnEnChangeEcf6();
	afx_msg void OnEnChangeEcf7();
	afx_msg void OnEnChangeEcf8();
	afx_msg void OnEnChangeEcf9();
	afx_msg void OnEnChangeEcg1();
	afx_msg void OnEnChangeEcg2();
	afx_msg void OnEnChangeEcg3();
	afx_msg void OnEnChangeEcg4();
	afx_msg void OnEnChangeEcg5();
	afx_msg void OnEnChangeEcg6();
	afx_msg void OnEnChangeEcg7();
	afx_msg void OnEnChangeEcg8();
	afx_msg void OnEnChangeEcg9();
	afx_msg void OnEnChangeEch1();
	afx_msg void OnEnChangeEch2();
	afx_msg void OnEnChangeEch3();
	afx_msg void OnEnChangeEch4();
	afx_msg void OnEnChangeEch5();
	afx_msg void OnEnChangeEch6();
	afx_msg void OnEnChangeEch7();
	afx_msg void OnEnChangeEch8();
	afx_msg void OnEnChangeEch9();
	afx_msg void OnEnChangeEci1();
	afx_msg void OnEnChangeEci2();
	afx_msg void OnEnChangeEci3();
	afx_msg void OnEnChangeEci4();
	afx_msg void OnEnChangeEci5();
	afx_msg void OnEnChangeEci6();
	afx_msg void OnEnChangeEci7();
	afx_msg void OnEnChangeEci8();
	afx_msg void OnEnChangeEci9();
	CButton m_Reset1;
	afx_msg void OnBnClickedReset1();
	afx_msg void OnCbnSelchangeCombodifficulty();
//	int m_Difficulty_Lavel;
	int m_Difficulty_Level;
	afx_msg void OnBnClickedDesignpro();
	afx_msg void OnBnClickedFinish2();
	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedStdanswer();
};
