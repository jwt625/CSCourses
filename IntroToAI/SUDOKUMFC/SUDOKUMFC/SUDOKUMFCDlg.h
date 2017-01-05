
// SUDOKUMFCDlg.h : ͷ�ļ�
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
#include "HandWDlg.h"
//#pragma comment (lib,"SUDOKUMFC.lib")


#ifndef OTHERSDEAL_H
#include "OthersDeal.h"
#endif

#ifndef MY_OCR_H
#include "My_OCR.h"
#endif

#ifndef PREPROCESSING_H
#include "preprocessing.h"
#endif

#ifndef IMAGECUT_H
#include "imagecut.h"
#endif

#ifndef PREFORLEARN_H
#include "preforlearn.h"
#endif


// CSUDOKUMFCDlg �Ի���
class CSUDOKUMFCDlg : public CDialogEx
{
// ����
public:
	CSUDOKUMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��
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

// �Ի�������
	enum { IDD = IDD_SUDOKUMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CFont m_editFont;  //*&&*�����С
//	int* SUDOKUmap[9][9];
	//*&&*�������ݵ�ַ
	int CurrentBlankPos[2];	//*&&*��ǰ������
	CEdit* SUDOKUmap[9][9];

	// ���ɵ���Ϣӳ�亯��
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
//	bool bFileOrManual;
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
	CButton m_ImageInput;
	CButton m_HandWInput;
	CButton m_PictInput;
	afx_msg void OnBnClickedImageinput();
	int bFileOrManual;
	afx_msg void OnBnClickedHandwinput();
	bool bHandWOrPict;
	afx_msg void OnBnClickedPictinput();
	int CSUDOKUMFCDlg::CreateBoard();
//	afx_msg void OnEnSetfocusEci9();
	afx_msg void OnEnKillfocusEci9();
	afx_msg void OnEnKillfocusEca1();
	afx_msg void OnEnKillfocusEca2();
	afx_msg void OnEnKillfocusEca3();
	afx_msg void OnEnKillfocusEca4();
	afx_msg void OnEnKillfocusEca5();
	afx_msg void OnEnKillfocusEca6();
	afx_msg void OnEnKillfocusEca7();
	afx_msg void OnEnKillfocusEca8();
	afx_msg void OnEnKillfocusEca9();
	afx_msg void OnEnKillfocusEcb1();
	afx_msg void OnEnKillfocusEcb2();
	afx_msg void OnEnKillfocusEcb3();
	afx_msg void OnEnKillfocusEcb4();
	afx_msg void OnEnKillfocusEcb5();
	afx_msg void OnEnKillfocusEcb6();
	afx_msg void OnEnKillfocusEcb7();
	afx_msg void OnEnKillfocusEcb8();
	afx_msg void OnEnKillfocusEcb9();
	afx_msg void OnEnKillfocusEcc1();
	afx_msg void OnEnKillfocusEcc2();
	afx_msg void OnEnKillfocusEcc3();
	afx_msg void OnEnKillfocusEcc4();
	afx_msg void OnEnKillfocusEcc5();
	afx_msg void OnEnKillfocusEcc6();
	afx_msg void OnEnKillfocusEcc7();
	afx_msg void OnEnKillfocusEcc8();
	afx_msg void OnEnKillfocusEcc9();
	afx_msg void OnEnKillfocusEcd1();
	afx_msg void OnEnKillfocusEcd2();
	afx_msg void OnEnKillfocusEcd3();
	afx_msg void OnEnKillfocusEcd4();
	afx_msg void OnEnKillfocusEcd5();
	afx_msg void OnEnKillfocusEcd6();
	afx_msg void OnEnKillfocusEcd7();
	afx_msg void OnEnKillfocusEcd8();
	afx_msg void OnEnKillfocusEcd9();
	afx_msg void OnEnKillfocusEce1();
	afx_msg void OnEnKillfocusEce2();
	afx_msg void OnEnKillfocusEce3();
	afx_msg void OnEnKillfocusEce4();
	afx_msg void OnEnKillfocusEce5();
	afx_msg void OnEnKillfocusEce6();
	afx_msg void OnEnKillfocusEce7();
	afx_msg void OnEnKillfocusEce8();
	afx_msg void OnEnKillfocusEce9();
	afx_msg void OnEnKillfocusEcf1();
	afx_msg void OnEnKillfocusEcf2();
	afx_msg void OnEnKillfocusEcf3();
	afx_msg void OnEnKillfocusEcf4();
	afx_msg void OnEnKillfocusEcf5();
	afx_msg void OnEnKillfocusEcf6();
	afx_msg void OnEnKillfocusEcf7();
	afx_msg void OnEnKillfocusEcf8();
	afx_msg void OnEnKillfocusEcf9();
	afx_msg void OnEnKillfocusEcg1();
	afx_msg void OnEnKillfocusEcg2();
	afx_msg void OnEnKillfocusEcg3();
	afx_msg void OnEnKillfocusEcg4();
	afx_msg void OnEnKillfocusEcg5();
	afx_msg void OnEnKillfocusEcg6();
	afx_msg void OnEnKillfocusEcg7();
	afx_msg void OnEnKillfocusEcg8();
	afx_msg void OnEnKillfocusEcg9();
	afx_msg void OnEnKillfocusEch1();
	afx_msg void OnEnKillfocusEch2();
	afx_msg void OnEnKillfocusEch3();
	afx_msg void OnEnKillfocusEch4();
	afx_msg void OnEnKillfocusEch5();
	afx_msg void OnEnKillfocusEch6();
	afx_msg void OnEnKillfocusEch7();
	afx_msg void OnEnKillfocusEch8();
	afx_msg void OnEnKillfocusEch9();
	afx_msg void OnEnKillfocusEci1();
	afx_msg void OnEnKillfocusEci2();
	afx_msg void OnEnKillfocusEci3();
	afx_msg void OnEnKillfocusEci4();
	afx_msg void OnEnKillfocusEci5();
	afx_msg void OnEnKillfocusEci6();
	afx_msg void OnEnKillfocusEci7();
	afx_msg void OnEnKillfocusEci8();
private:
	//CHandWInput* m_HWIDlg;
protected:
//	afx_msg LRESULT OnRedraw(WPARAM wParam, LPARAM lParam);
public:
	CHandWDlg* m_pHandWDlg;
protected:
	afx_msg LRESULT OnStartdraw(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnBrushspin(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnImagestore(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnStartclassify(WPARAM wParam, LPARAM lParam);
 	afx_msg LRESULT OnQuitdraw(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnBrushspinn(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSubwin1close(WPARAM wParam, LPARAM lParam);
//	afx_msg LRESULT OnQuitdraw(WPARAM wParam, LPARAM lParam);
};


