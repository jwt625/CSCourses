
// SUDOKUMFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SUDOKUMFC.h"
#include "SUDOKUMFCDlg.h"
#include "afxdialogex.h"
#include "DataStruct.h"
#include "GameState.h"
#include "methods.h"
#include "graph.h"
#include "generatePuzzle.h"
#include "SudokuQuit.h"
#include "StdAns.h"

#include "conio.h"
#include <io.h>  
#include <fcntl.h>  

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSUDOKUMFCDlg 对话框




CSUDOKUMFCDlg::CSUDOKUMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSUDOKUMFCDlg::IDD, pParent)
	, m_editA1(0)
	, m_sInputFile(_T(""))
	, m_Inputnum(0)
	, m_ProSolveRes(_T(""))
	, m_ProDesignRes(_T(""))
	, m_VPDR(_T(""))
	, m_EditDisplay(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_editA2 = 0;
	m_editA3 = 0;
	m_editA4 = 0;
	m_editA5 = 0;
	m_editA6 = 0;
	m_editA7 = 0;
	m_editA8 = 0;
	m_editA9 = 0;
	m_editB1 = 0;
	m_editB2 = 0;
	m_editB3 = 0;
	m_editB4 = 0;
	m_editB5 = 0;
	m_editB6 = 0;
	m_editB7 = 0;
	m_editB8 = 0;
	m_editB9 = 0;
	m_editC1 = 0;
	m_editC2 = 0;
	m_editC3 = 0;
	m_editC4 = 0;
	m_editC5 = 0;
	m_editC6 = 0;
	m_editC7 = 0;
	m_editC8 = 0;
	m_editC9 = 0;
	m_editD1 = 0;
	m_editD2 = 0;
	m_editD3 = 0;
	m_editD4 = 0;
	m_editD5 = 0;
	m_editD6 = 0;
	m_editD7 = 0;
	m_editD8 = 0;
	m_editD9 = 0;
	m_editE1 = 0;
	m_editE2 = 0;
	m_editE3 = 0;
	m_editE4 = 0;
	m_editE5 = 0;
	m_editE6 = 0;
	m_editE7 = 0;
	m_editE8 = 0;
	m_editE9 = 0;
	m_editF1 = 0;
	m_editF2 = 0;
	m_editF3 = 0;
	m_editF4 = 0;
	m_editF5 = 0;
	m_editF6 = 0;
	m_editF7 = 0;
	m_editF8 = 0;
	m_editF9 = 0;
	m_editG1 = 0;
	m_editG2 = 0;
	m_editG3 = 0;
	m_editG4 = 0;
	m_editG5 = 0;
	m_editG6 = 0;
	m_editG7 = 0;
	m_editG8 = 0;
	m_editG9 = 0;
	m_editH1 = 0;
	m_editH2 = 0;
	m_editH3 = 0;
	m_editH4 = 0;
	m_editH5 = 0;
	m_editH6 = 0;
	m_editH7 = 0;
	m_editH8 = 0;
	m_editH9 = 0;
	m_editI1 = 0;
	m_editI2 = 0;
	m_editI3 = 0;
	m_editI4 = 0;
	m_editI5 = 0;
	m_editI6 = 0;
	m_editI7 = 0;
	m_editI8 = 0;
	m_editI9 = 0;
	m_VFileInput = _T("");
	//  m_VManualInput = _T("");
	//  m_VManualInput = 0;
	m_VPSR = _T("");
	nUpOrDown = 0;
	nLeftOrRight = 0;
	m_VManualInput = 0;
	m_Val = 0;
	//  m_Difficulty_Lavel = 0;
	m_Difficulty_Level = 0;
}

void CSUDOKUMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ECA1, m_editA1);
	DDV_MinMaxInt(pDX, m_editA1, 1, 9);
	DDX_Text(pDX, IDC_ECA2, m_editA2);
	DDV_MinMaxInt(pDX, m_editA2, 1, 9);
	DDX_Text(pDX, IDC_ECA3, m_editA3);
	DDV_MinMaxInt(pDX, m_editA3, 1, 9);
	DDX_Text(pDX, IDC_ECA4, m_editA4);
	DDV_MinMaxInt(pDX, m_editA4, 1, 9);
	DDX_Text(pDX, IDC_ECA5, m_editA5);
	DDV_MinMaxInt(pDX, m_editA5, 1, 9);
	DDX_Text(pDX, IDC_ECA6, m_editA6);
	DDV_MinMaxInt(pDX, m_editA6, 1, 9);
	DDX_Text(pDX, IDC_ECA7, m_editA7);
	DDV_MinMaxInt(pDX, m_editA7, 1, 9);
	DDX_Text(pDX, IDC_ECA8, m_editA8);
	DDV_MinMaxInt(pDX, m_editA8, 1, 9);
	DDX_Text(pDX, IDC_ECA9, m_editA9);
	DDV_MinMaxInt(pDX, m_editA9, 1, 9);
	DDX_Text(pDX, IDC_ECB1, m_editB1);
	DDV_MinMaxInt(pDX, m_editB1, 1, 9);
	DDX_Text(pDX, IDC_ECB2, m_editB2);
	DDV_MinMaxInt(pDX, m_editB2, 1, 9);
	DDX_Text(pDX, IDC_ECB3, m_editB3);
	DDV_MinMaxInt(pDX, m_editB3, 1, 9);
	DDX_Text(pDX, IDC_ECB4, m_editB4);
	DDV_MinMaxInt(pDX, m_editB4, 1, 9);
	DDX_Text(pDX, IDC_ECB5, m_editB5);
	DDV_MinMaxInt(pDX, m_editB5, 1, 9);
	DDX_Text(pDX, IDC_ECB6, m_editB6);
	DDV_MinMaxInt(pDX, m_editB6, 1, 9);
	DDX_Text(pDX, IDC_ECB7, m_editB7);
	DDV_MinMaxInt(pDX, m_editB7, 1, 9);
	DDX_Text(pDX, IDC_ECB8, m_editB8);
	DDV_MinMaxInt(pDX, m_editB8, 1, 9);
	DDX_Text(pDX, IDC_ECB9, m_editB9);
	DDV_MinMaxInt(pDX, m_editB9, 1, 9);
	DDX_Text(pDX, IDC_ECC1, m_editC1);
	DDV_MinMaxInt(pDX, m_editC1, 1, 9);
	DDX_Text(pDX, IDC_ECC2, m_editC2);
	DDV_MinMaxInt(pDX, m_editC2, 1, 9);
	DDX_Text(pDX, IDC_ECC3, m_editC3);
	DDV_MinMaxInt(pDX, m_editC3, 1, 9);
	DDX_Text(pDX, IDC_ECC4, m_editC4);
	DDV_MinMaxInt(pDX, m_editC4, 1, 9);
	DDX_Text(pDX, IDC_ECC5, m_editC5);
	DDV_MinMaxInt(pDX, m_editC5, 1, 9);
	DDX_Text(pDX, IDC_ECC6, m_editC6);
	DDV_MinMaxInt(pDX, m_editC6, 1, 9);
	DDX_Text(pDX, IDC_ECC7, m_editC7);
	DDV_MinMaxInt(pDX, m_editC7, 1, 9);
	DDX_Text(pDX, IDC_ECC8, m_editC8);
	DDV_MinMaxInt(pDX, m_editC8, 1, 9);
	DDX_Text(pDX, IDC_ECC9, m_editC9);
	DDV_MinMaxInt(pDX, m_editC9, 1, 9);
	DDX_Text(pDX, IDC_ECD1, m_editD1);
	DDV_MinMaxInt(pDX, m_editD1, 1, 9);
	DDX_Text(pDX, IDC_ECD2, m_editD2);
	DDV_MinMaxInt(pDX, m_editD2, 1, 9);
	DDX_Text(pDX, IDC_ECD3, m_editD3);
	DDV_MinMaxInt(pDX, m_editD3, 1, 9);
	DDX_Text(pDX, IDC_ECD4, m_editD4);
	DDV_MinMaxInt(pDX, m_editD4, 1, 9);
	DDX_Text(pDX, IDC_ECD5, m_editD5);
	DDV_MinMaxInt(pDX, m_editD5, 1, 9);
	DDX_Text(pDX, IDC_ECD6, m_editD6);
	DDV_MinMaxInt(pDX, m_editD6, 1, 9);
	DDX_Text(pDX, IDC_ECD7, m_editD7);
	DDV_MinMaxInt(pDX, m_editD7, 1, 9);
	DDX_Text(pDX, IDC_ECD8, m_editD8);
	DDV_MinMaxInt(pDX, m_editD8, 1, 9);
	DDX_Text(pDX, IDC_ECD9, m_editD9);
	DDV_MinMaxInt(pDX, m_editD9, 1, 9);
	DDX_Text(pDX, IDC_ECE1, m_editE1);
	DDV_MinMaxInt(pDX, m_editE1, 1, 9);
	DDX_Text(pDX, IDC_ECE2, m_editE2);
	DDV_MinMaxInt(pDX, m_editE2, 1, 9);
	DDX_Text(pDX, IDC_ECE3, m_editE3);
	DDV_MinMaxInt(pDX, m_editE3, 1, 9);
	DDX_Text(pDX, IDC_ECE4, m_editE4);
	DDV_MinMaxInt(pDX, m_editE4, 1, 9);
	DDX_Text(pDX, IDC_ECE5, m_editE5);
	DDV_MinMaxInt(pDX, m_editE5, 1, 9);
	DDX_Text(pDX, IDC_ECE6, m_editE6);
	DDV_MinMaxInt(pDX, m_editE6, 1, 9);
	DDX_Text(pDX, IDC_ECE7, m_editE7);
	DDV_MinMaxInt(pDX, m_editE7, 1, 9);
	DDX_Text(pDX, IDC_ECE8, m_editE8);
	DDV_MinMaxInt(pDX, m_editE8, 1, 9);
	DDX_Text(pDX, IDC_ECE9, m_editE9);
	DDV_MinMaxInt(pDX, m_editE9, 1, 9);
	DDX_Text(pDX, IDC_ECF1, m_editF1);
	DDV_MinMaxInt(pDX, m_editF1, 1, 9);
	DDX_Text(pDX, IDC_ECF2, m_editF2);
	DDV_MinMaxInt(pDX, m_editF2, 1, 9);
	DDX_Text(pDX, IDC_ECF3, m_editF3);
	DDV_MinMaxInt(pDX, m_editF3, 1, 9);
	DDX_Text(pDX, IDC_ECF4, m_editF4);
	DDV_MinMaxInt(pDX, m_editF4, 1, 9);
	DDX_Text(pDX, IDC_ECF5, m_editF5);
	DDV_MinMaxInt(pDX, m_editF5, 1, 9);
	DDX_Text(pDX, IDC_ECF6, m_editF6);
	DDV_MinMaxInt(pDX, m_editF6, 1, 9);
	DDX_Text(pDX, IDC_ECF7, m_editF7);
	DDV_MinMaxInt(pDX, m_editF7, 1, 9);
	DDX_Text(pDX, IDC_ECF8, m_editF8);
	DDV_MinMaxInt(pDX, m_editF8, 1, 9);
	DDX_Text(pDX, IDC_ECF9, m_editF9);
	DDV_MinMaxInt(pDX, m_editF9, 1, 9);
	DDX_Text(pDX, IDC_ECG1, m_editG1);
	DDV_MinMaxInt(pDX, m_editG1, 1, 9);
	DDX_Text(pDX, IDC_ECG2, m_editG2);
	DDV_MinMaxInt(pDX, m_editG2, 1, 9);
	DDX_Text(pDX, IDC_ECG3, m_editG3);
	DDV_MinMaxInt(pDX, m_editG3, 1, 9);
	DDX_Text(pDX, IDC_ECG4, m_editG4);
	DDV_MinMaxInt(pDX, m_editG4, 1, 9);
	DDX_Text(pDX, IDC_ECG5, m_editG5);
	DDV_MinMaxInt(pDX, m_editG5, 1, 9);
	DDX_Text(pDX, IDC_ECG6, m_editG6);
	DDV_MinMaxInt(pDX, m_editG6, 1, 9);
	DDX_Text(pDX, IDC_ECG7, m_editG7);
	DDV_MinMaxInt(pDX, m_editG7, 1, 9);
	DDX_Text(pDX, IDC_ECG8, m_editG8);
	DDV_MinMaxInt(pDX, m_editG8, 1, 9);
	DDX_Text(pDX, IDC_ECG9, m_editG9);
	DDV_MinMaxInt(pDX, m_editG9, 1, 9);
	DDX_Text(pDX, IDC_ECH1, m_editH1);
	DDV_MinMaxInt(pDX, m_editH1, 1, 9);
	DDX_Text(pDX, IDC_ECH2, m_editH2);
	DDV_MinMaxInt(pDX, m_editH2, 1, 9);
	DDX_Text(pDX, IDC_ECH3, m_editH3);
	DDV_MinMaxInt(pDX, m_editH3, 1, 9);
	DDX_Text(pDX, IDC_ECH4, m_editH4);
	DDV_MinMaxInt(pDX, m_editH4, 1, 9);
	DDX_Text(pDX, IDC_ECH5, m_editH5);
	DDV_MinMaxInt(pDX, m_editH5, 1, 9);
	DDX_Text(pDX, IDC_ECH6, m_editH6);
	DDV_MinMaxInt(pDX, m_editH6, 1, 9);
	DDX_Text(pDX, IDC_ECH7, m_editH7);
	DDV_MinMaxInt(pDX, m_editH7, 1, 9);
	DDX_Text(pDX, IDC_ECH8, m_editH8);
	DDV_MinMaxInt(pDX, m_editH8, 1, 9);
	DDX_Text(pDX, IDC_ECH9, m_editH9);
	DDV_MinMaxInt(pDX, m_editH9, 1, 9);
	DDX_Text(pDX, IDC_ECI1, m_editI1);
	DDV_MinMaxInt(pDX, m_editI1, 1, 9);
	DDX_Text(pDX, IDC_ECI2, m_editI2);
	DDV_MinMaxInt(pDX, m_editI2, 1, 9);
	DDX_Text(pDX, IDC_ECI3, m_editI3);
	DDV_MinMaxInt(pDX, m_editI3, 1, 9);
	DDX_Text(pDX, IDC_ECI4, m_editI4);
	DDV_MinMaxInt(pDX, m_editI4, 1, 9);
	DDX_Text(pDX, IDC_ECI5, m_editI5);
	DDV_MinMaxInt(pDX, m_editI5, 1, 9);
	DDX_Text(pDX, IDC_ECI6, m_editI6);
	DDV_MinMaxInt(pDX, m_editI6, 1, 9);
	DDX_Text(pDX, IDC_ECI7, m_editI7);
	DDV_MinMaxInt(pDX, m_editI7, 1, 9);
	DDX_Text(pDX, IDC_ECI8, m_editI8);
	DDV_MinMaxInt(pDX, m_editI8, 1, 9);
	DDX_Text(pDX, IDC_ECI9, m_editI9);
	DDV_MinMaxInt(pDX, m_editI9, 1, 9);
	//DDX_Control(pDX, IDC_INPUT_COMBO, m_comboInput);
	DDX_Control(pDX, IDC_ECA1, m_cA1);
	DDX_Control(pDX, IDC_ECA2, m_cA2);
	DDX_Control(pDX, IDC_ECA3, m_cA3);
	DDX_Control(pDX, IDC_ECA4, m_cA4);
	DDX_Control(pDX, IDC_ECA5, m_cA5);
	DDX_Control(pDX, IDC_ECA6, m_cA6);
	DDX_Control(pDX, IDC_ECA7, m_cA7);
	DDX_Control(pDX, IDC_ECA8, m_cA8);
	DDX_Control(pDX, IDC_ECA9, m_cA9);
	DDX_Control(pDX, IDC_ECB1, m_cB1);
	DDX_Control(pDX, IDC_ECB2, m_cB2);
	DDX_Control(pDX, IDC_ECB3, m_cB3);
	DDX_Control(pDX, IDC_ECB4, m_cB4);
	DDX_Control(pDX, IDC_ECB5, m_cB5);
	DDX_Control(pDX, IDC_ECB6, m_cB6);
	DDX_Control(pDX, IDC_ECB7, m_cB7);
	DDX_Control(pDX, IDC_ECB8, m_cB8);
	DDX_Control(pDX, IDC_ECB9, m_cB9);
	DDX_Control(pDX, IDC_ECC1, m_cC1);
	DDX_Control(pDX, IDC_ECC2, m_cC2);
	DDX_Control(pDX, IDC_ECC3, m_cC3);
	DDX_Control(pDX, IDC_ECC4, m_cC4);
	DDX_Control(pDX, IDC_ECC5, m_cC5);
	DDX_Control(pDX, IDC_ECC6, m_cC6);
	DDX_Control(pDX, IDC_ECC7, m_cC7);
	DDX_Control(pDX, IDC_ECC8, m_cC8);
	DDX_Control(pDX, IDC_ECC9, m_cC9);
	DDX_Control(pDX, IDC_ECD1, m_cD1);
	DDX_Control(pDX, IDC_ECD2, m_cD2);
	DDX_Control(pDX, IDC_ECD3, m_cD3);
	DDX_Control(pDX, IDC_ECD4, m_cD4);
	DDX_Control(pDX, IDC_ECD5, m_cD5);
	DDX_Control(pDX, IDC_ECD6, m_cD6);
	DDX_Control(pDX, IDC_ECD7, m_cD7);
	DDX_Control(pDX, IDC_ECD8, m_cD8);
	DDX_Control(pDX, IDC_ECD9, m_cD9);
	DDX_Control(pDX, IDC_ECE1, m_cE1);
	DDX_Control(pDX, IDC_ECE2, m_cE2);
	DDX_Control(pDX, IDC_ECE3, m_cE3);
	DDX_Control(pDX, IDC_ECE4, m_cE4);
	DDX_Control(pDX, IDC_ECE5, m_cE5);
	DDX_Control(pDX, IDC_ECE6, m_cE6);
	DDX_Control(pDX, IDC_ECE7, m_cE7);
	DDX_Control(pDX, IDC_ECE8, m_cE8);
	DDX_Control(pDX, IDC_ECE9, m_cE9);
	DDX_Control(pDX, IDC_ECF1, m_cF1);
	DDX_Control(pDX, IDC_ECF2, m_cF2);
	DDX_Control(pDX, IDC_ECF3, m_cF3);
	DDX_Control(pDX, IDC_ECF4, m_cF4);
	DDX_Control(pDX, IDC_ECF5, m_cF5);
	DDX_Control(pDX, IDC_ECF6, m_cF6);
	DDX_Control(pDX, IDC_ECF7, m_cF7);
	DDX_Control(pDX, IDC_ECF8, m_cF8);
	DDX_Control(pDX, IDC_ECF9, m_cF9);
	DDX_Control(pDX, IDC_ECG1, m_cG1);
	DDX_Control(pDX, IDC_ECG2, m_cG2);
	DDX_Control(pDX, IDC_ECG3, m_cG3);
	DDX_Control(pDX, IDC_ECG4, m_cG4);
	DDX_Control(pDX, IDC_ECG5, m_cG5);
	DDX_Control(pDX, IDC_ECG6, m_cG6);
	DDX_Control(pDX, IDC_ECG7, m_cG7);
	DDX_Control(pDX, IDC_ECG8, m_cG8);
	DDX_Control(pDX, IDC_ECG9, m_cG9);
	DDX_Control(pDX, IDC_ECH1, m_cH1);
	DDX_Control(pDX, IDC_ECH2, m_cH2);
	DDX_Control(pDX, IDC_ECH3, m_cH3);
	DDX_Control(pDX, IDC_ECH4, m_cH4);
	DDX_Control(pDX, IDC_ECH5, m_cH5);
	DDX_Control(pDX, IDC_ECH6, m_cH6);
	DDX_Control(pDX, IDC_ECH7, m_cH7);
	DDX_Control(pDX, IDC_ECH8, m_cH8);
	DDX_Control(pDX, IDC_ECH9, m_cH9);
	DDX_Control(pDX, IDC_ECI1, m_cI1);
	DDX_Control(pDX, IDC_ECI2, m_cI2);
	DDX_Control(pDX, IDC_ECI3, m_cI3);
	DDX_Control(pDX, IDC_ECI4, m_cI4);
	DDX_Control(pDX, IDC_ECI5, m_cI5);
	DDX_Control(pDX, IDC_ECI6, m_cI6);
	DDX_Control(pDX, IDC_ECI7, m_cI7);
	DDX_Control(pDX, IDC_ECI8, m_cI8);
	DDX_Control(pDX, IDC_ECI9, m_cI9);
	DDX_Text(pDX, IDC_EDIT3, m_sInputFile);
	DDX_Text(pDX, IDC_EDIT4, m_Inputnum);
	DDV_MinMaxInt(pDX, m_Inputnum, 1, 9);
	//DDX_Text(pDX, IDC_EDIT5, m_ProSolveRes);
	//DDX_Text(pDX, IDC_EDIT1, m_ProDesignRes);
	DDX_Control(pDX, IDC_COMBODIFFICULTY, m_Difficulty);
	DDX_Control(pDX, ID_DESIGNPRO, m_ProDesign);
	DDX_Control(pDX, IDB_FINISH2, m_Finish2);
	DDX_Control(pDX, IDB_STDANSWER, m_StdAnswer);
	DDX_Control(pDX, IDC_EDITPDR, m_CPDR);
	DDX_Text(pDX, IDC_EDITPDR, m_VPDR);
	DDX_Control(pDX, IDB_FINISH1, m_Finish1);
	DDX_Control(pDX, IDC_EDITFILEINPUT, m_CFileInput);
	DDX_Text(pDX, IDC_EDITFILEINPUT, m_VFileInput);
	DDX_Control(pDX, IDC_EDITMANUALINPUT, m_CManualInput);
	//  DDX_Text(pDX, IDC_EDITMANUALINPUT, m_VManualInput);
	//  DDX_Text(pDX, IDC_EDITMANUALINPUT, m_VManualInput);
	//  DDV_MinMaxInt(pDX, m_VManualInput, 1, 9);
	DDX_Control(pDX, IDC_EDITPSR, m_CPSR);
	DDX_Text(pDX, IDC_EDITPSR, m_VPSR);
	//  DDX_Control(pDX, IDC_SPINLR, m_SPINLR);
	DDX_Control(pDX, IDC_SPINLR, m_SpinLR);
	DDX_Control(pDX, IDC_SPINUD, m_SpinUD);
	DDX_Control(pDX, IDC_CHECKPS, m_PS);
	DDX_Control(pDX, IDC_CHECKPE, m_PE);
	DDX_Control(pDX, IDC_FILEINPUT, m_FileInput);
	DDX_Control(pDX, IDC_MANUALINPUT, m_ManualInput);
	DDX_Text(pDX, IDC_EDITMANUALINPUT, m_VManualInput);
	DDX_Control(pDX, IDC_DISPLAY, m_cDisplay);
	DDX_Text(pDX, IDC_DISPLAY, m_EditDisplay);
	DDX_Control(pDX, IDB_FILEIN, m_FileIn);
	DDX_Control(pDX, IDB_RESET1, m_Reset1);
}

BEGIN_MESSAGE_MAP(CSUDOKUMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()

	ON_WM_CTLCOLOR()	//*&&*

	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PROSOLVE, &CSUDOKUMFCDlg::OnBnClickedProsolve)
	ON_BN_CLICKED(IDC_PRODESIGN, &CSUDOKUMFCDlg::OnBnClickedProdesign)
	ON_BN_CLICKED(IDC_FILEINPUT, &CSUDOKUMFCDlg::OnBnClickedFileinput)
	ON_BN_CLICKED(IDC_MANUALINPUT, &CSUDOKUMFCDlg::OnBnClickedManualinput)
	ON_BN_CLICKED(IDC_CHECKPE, &CSUDOKUMFCDlg::OnBnClickedCheckpe)
	ON_BN_CLICKED(IDC_CHECKPS, &CSUDOKUMFCDlg::OnBnClickedCheckps)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPINUD, &CSUDOKUMFCDlg::OnDeltaposSpinud)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPINLR, &CSUDOKUMFCDlg::OnDeltaposSpinlr)
	ON_EN_CHANGE(IDC_EDITMANUALINPUT, &CSUDOKUMFCDlg::OnEnChangeEditmanualinput)
	ON_BN_CLICKED(IDB_FINISH1, &CSUDOKUMFCDlg::OnBnClickedFinish1)
	ON_BN_CLICKED(IDB_FILEIN, &CSUDOKUMFCDlg::OnBnClickedFilein)
	ON_EN_CHANGE(IDC_ECA1, &CSUDOKUMFCDlg::OnEnChangeEca1)
	ON_EN_CHANGE(IDC_ECA2, &CSUDOKUMFCDlg::OnEnChangeEca2)
	ON_EN_CHANGE(IDC_ECA3, &CSUDOKUMFCDlg::OnEnChangeEca3)
	ON_EN_CHANGE(IDC_ECA4, &CSUDOKUMFCDlg::OnEnChangeEca4)
	ON_EN_CHANGE(IDC_ECA5, &CSUDOKUMFCDlg::OnEnChangeEca5)
	ON_EN_CHANGE(IDC_ECA6, &CSUDOKUMFCDlg::OnEnChangeEca6)
	ON_EN_CHANGE(IDC_ECA7, &CSUDOKUMFCDlg::OnEnChangeEca7)
	ON_EN_CHANGE(IDC_ECA8, &CSUDOKUMFCDlg::OnEnChangeEca8)
	ON_EN_CHANGE(IDC_ECA9, &CSUDOKUMFCDlg::OnEnChangeEca9)
	ON_EN_CHANGE(IDC_ECB1, &CSUDOKUMFCDlg::OnEnChangeEcb1)
	ON_EN_CHANGE(IDC_ECB2, &CSUDOKUMFCDlg::OnEnChangeEcb2)
	ON_EN_CHANGE(IDC_ECB3, &CSUDOKUMFCDlg::OnEnChangeEcb3)
	ON_EN_CHANGE(IDC_ECB4, &CSUDOKUMFCDlg::OnEnChangeEcb4)
	ON_EN_CHANGE(IDC_ECB5, &CSUDOKUMFCDlg::OnEnChangeEcb5)
	ON_EN_CHANGE(IDC_ECB6, &CSUDOKUMFCDlg::OnEnChangeEcb6)
	ON_EN_CHANGE(IDC_ECB7, &CSUDOKUMFCDlg::OnEnChangeEcb7)
	ON_EN_CHANGE(IDC_ECB8, &CSUDOKUMFCDlg::OnEnChangeEcb8)
	ON_EN_CHANGE(IDC_ECB9, &CSUDOKUMFCDlg::OnEnChangeEcb9)
	ON_EN_CHANGE(IDC_ECC1, &CSUDOKUMFCDlg::OnEnChangeEcc1)
	ON_EN_CHANGE(IDC_ECC2, &CSUDOKUMFCDlg::OnEnChangeEcc2)
	ON_EN_CHANGE(IDC_ECC3, &CSUDOKUMFCDlg::OnEnChangeEcc3)
	ON_EN_CHANGE(IDC_ECC4, &CSUDOKUMFCDlg::OnEnChangeEcc4)
	ON_EN_CHANGE(IDC_ECC5, &CSUDOKUMFCDlg::OnEnChangeEcc5)
	ON_EN_CHANGE(IDC_ECC6, &CSUDOKUMFCDlg::OnEnChangeEcc6)
	ON_EN_CHANGE(IDC_ECC7, &CSUDOKUMFCDlg::OnEnChangeEcc7)
	ON_EN_CHANGE(IDC_ECC8, &CSUDOKUMFCDlg::OnEnChangeEcc8)
	ON_EN_CHANGE(IDC_ECC9, &CSUDOKUMFCDlg::OnEnChangeEcc9)
	ON_EN_CHANGE(IDC_ECD1, &CSUDOKUMFCDlg::OnEnChangeEcd1)
	ON_EN_CHANGE(IDC_ECD2, &CSUDOKUMFCDlg::OnEnChangeEcd2)
	ON_EN_CHANGE(IDC_ECD3, &CSUDOKUMFCDlg::OnEnChangeEcd3)
	ON_EN_CHANGE(IDC_ECD4, &CSUDOKUMFCDlg::OnEnChangeEcd4)
	ON_EN_CHANGE(IDC_ECD5, &CSUDOKUMFCDlg::OnEnChangeEcd5)
	ON_EN_CHANGE(IDC_ECD6, &CSUDOKUMFCDlg::OnEnChangeEcd6)
	ON_EN_CHANGE(IDC_ECD7, &CSUDOKUMFCDlg::OnEnChangeEcd7)
	ON_EN_CHANGE(IDC_ECD8, &CSUDOKUMFCDlg::OnEnChangeEcd8)
	ON_EN_CHANGE(IDC_ECD9, &CSUDOKUMFCDlg::OnEnChangeEcd9)
	ON_EN_CHANGE(IDC_ECE1, &CSUDOKUMFCDlg::OnEnChangeEce1)
	ON_EN_CHANGE(IDC_ECE2, &CSUDOKUMFCDlg::OnEnChangeEce2)
	ON_EN_CHANGE(IDC_ECE3, &CSUDOKUMFCDlg::OnEnChangeEce3)
	ON_EN_CHANGE(IDC_ECE4, &CSUDOKUMFCDlg::OnEnChangeEce4)
	ON_EN_CHANGE(IDC_ECE5, &CSUDOKUMFCDlg::OnEnChangeEce5)
	ON_EN_CHANGE(IDC_ECE6, &CSUDOKUMFCDlg::OnEnChangeEce6)
	ON_EN_CHANGE(IDC_ECE7, &CSUDOKUMFCDlg::OnEnChangeEce7)
	ON_EN_CHANGE(IDC_ECE8, &CSUDOKUMFCDlg::OnEnChangeEce8)
	ON_EN_CHANGE(IDC_ECE9, &CSUDOKUMFCDlg::OnEnChangeEce9)
	ON_EN_CHANGE(IDC_ECF1, &CSUDOKUMFCDlg::OnEnChangeEcf1)
	ON_EN_CHANGE(IDC_ECF2, &CSUDOKUMFCDlg::OnEnChangeEcf2)
	ON_EN_CHANGE(IDC_ECF3, &CSUDOKUMFCDlg::OnEnChangeEcf3)
	ON_EN_CHANGE(IDC_ECF4, &CSUDOKUMFCDlg::OnEnChangeEcf4)
	ON_EN_CHANGE(IDC_ECF5, &CSUDOKUMFCDlg::OnEnChangeEcf5)
	ON_EN_CHANGE(IDC_ECF6, &CSUDOKUMFCDlg::OnEnChangeEcf6)
	ON_EN_CHANGE(IDC_ECF7, &CSUDOKUMFCDlg::OnEnChangeEcf7)
	ON_EN_CHANGE(IDC_ECF8, &CSUDOKUMFCDlg::OnEnChangeEcf8)
	ON_EN_CHANGE(IDC_ECF9, &CSUDOKUMFCDlg::OnEnChangeEcf9)
	ON_EN_CHANGE(IDC_ECG1, &CSUDOKUMFCDlg::OnEnChangeEcg1)
	ON_EN_CHANGE(IDC_ECG2, &CSUDOKUMFCDlg::OnEnChangeEcg2)
	ON_EN_CHANGE(IDC_ECG3, &CSUDOKUMFCDlg::OnEnChangeEcg3)
	ON_EN_CHANGE(IDC_ECG4, &CSUDOKUMFCDlg::OnEnChangeEcg4)
	ON_EN_CHANGE(IDC_ECG5, &CSUDOKUMFCDlg::OnEnChangeEcg5)
	ON_EN_CHANGE(IDC_ECG6, &CSUDOKUMFCDlg::OnEnChangeEcg6)
	ON_EN_CHANGE(IDC_ECG7, &CSUDOKUMFCDlg::OnEnChangeEcg7)
	ON_EN_CHANGE(IDC_ECG8, &CSUDOKUMFCDlg::OnEnChangeEcg8)
	ON_EN_CHANGE(IDC_ECG9, &CSUDOKUMFCDlg::OnEnChangeEcg9)
	ON_EN_CHANGE(IDC_ECH1, &CSUDOKUMFCDlg::OnEnChangeEch1)
	ON_EN_CHANGE(IDC_ECH2, &CSUDOKUMFCDlg::OnEnChangeEch2)
	ON_EN_CHANGE(IDC_ECH3, &CSUDOKUMFCDlg::OnEnChangeEch3)
	ON_EN_CHANGE(IDC_ECH4, &CSUDOKUMFCDlg::OnEnChangeEch4)
	ON_EN_CHANGE(IDC_ECH5, &CSUDOKUMFCDlg::OnEnChangeEch5)
	ON_EN_CHANGE(IDC_ECH6, &CSUDOKUMFCDlg::OnEnChangeEch6)
	ON_EN_CHANGE(IDC_ECH7, &CSUDOKUMFCDlg::OnEnChangeEch7)
	ON_EN_CHANGE(IDC_ECH8, &CSUDOKUMFCDlg::OnEnChangeEch8)
	ON_EN_CHANGE(IDC_ECH9, &CSUDOKUMFCDlg::OnEnChangeEch9)
	ON_EN_CHANGE(IDC_ECI1, &CSUDOKUMFCDlg::OnEnChangeEci1)
	ON_EN_CHANGE(IDC_ECI2, &CSUDOKUMFCDlg::OnEnChangeEci2)
	ON_EN_CHANGE(IDC_ECI3, &CSUDOKUMFCDlg::OnEnChangeEci3)
	ON_EN_CHANGE(IDC_ECI4, &CSUDOKUMFCDlg::OnEnChangeEci4)
	ON_EN_CHANGE(IDC_ECI5, &CSUDOKUMFCDlg::OnEnChangeEci5)
	ON_EN_CHANGE(IDC_ECI6, &CSUDOKUMFCDlg::OnEnChangeEci6)
	ON_EN_CHANGE(IDC_ECI7, &CSUDOKUMFCDlg::OnEnChangeEci7)
	ON_EN_CHANGE(IDC_ECI8, &CSUDOKUMFCDlg::OnEnChangeEci8)
	ON_EN_CHANGE(IDC_ECI9, &CSUDOKUMFCDlg::OnEnChangeEci9)
	ON_BN_CLICKED(IDB_RESET1, &CSUDOKUMFCDlg::OnBnClickedReset1)
	ON_CBN_SELCHANGE(IDC_COMBODIFFICULTY, &CSUDOKUMFCDlg::OnCbnSelchangeCombodifficulty)
	ON_BN_CLICKED(ID_DESIGNPRO, &CSUDOKUMFCDlg::OnBnClickedDesignpro)
	ON_BN_CLICKED(IDB_FINISH2, &CSUDOKUMFCDlg::OnBnClickedFinish2)
	ON_BN_CLICKED(IDQUIT, &CSUDOKUMFCDlg::OnBnClickedQuit)
	ON_BN_CLICKED(IDB_STDANSWER, &CSUDOKUMFCDlg::OnBnClickedStdanswer)
	END_MESSAGE_MAP()


// CSUDOKUMFCDlg 消息处理程序

BOOL CSUDOKUMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_editFont.CreatePointFont(300, _T("黑体"));	//*&&*修改字体   
	// 设置新字体
	m_cA1.SetFont(&m_editFont); 
	m_cA2.SetFont(&m_editFont); 
	m_cA3.SetFont(&m_editFont); 
	m_cA4.SetFont(&m_editFont); 
	m_cA5.SetFont(&m_editFont); 
	m_cA6.SetFont(&m_editFont); 
	m_cA7.SetFont(&m_editFont); 
	m_cA8.SetFont(&m_editFont); 
	m_cA9.SetFont(&m_editFont); 
	m_cB1.SetFont(&m_editFont); 
	m_cB2.SetFont(&m_editFont); 
	m_cB3.SetFont(&m_editFont); 
	m_cB4.SetFont(&m_editFont); 
	m_cB5.SetFont(&m_editFont); 
	m_cB6.SetFont(&m_editFont); 
	m_cB7.SetFont(&m_editFont); 
	m_cB8.SetFont(&m_editFont); 
	m_cB9.SetFont(&m_editFont); 
	m_cC1.SetFont(&m_editFont);
	m_cC2.SetFont(&m_editFont); 
	m_cC3.SetFont(&m_editFont); 
	m_cC4.SetFont(&m_editFont); 
	m_cC5.SetFont(&m_editFont); 
	m_cC6.SetFont(&m_editFont); 
	m_cC7.SetFont(&m_editFont); 
	m_cC8.SetFont(&m_editFont); 
	m_cC9.SetFont(&m_editFont); 
	m_cD1.SetFont(&m_editFont); 
	m_cD2.SetFont(&m_editFont);
	m_cD3.SetFont(&m_editFont);
	m_cD4.SetFont(&m_editFont);
	m_cD5.SetFont(&m_editFont);
	m_cD6.SetFont(&m_editFont);
	m_cD7.SetFont(&m_editFont);
	m_cD8.SetFont(&m_editFont);
	m_cD9.SetFont(&m_editFont);
	m_cE1.SetFont(&m_editFont);
	m_cE2.SetFont(&m_editFont);
	m_cE3.SetFont(&m_editFont);
	m_cE4.SetFont(&m_editFont);
	m_cE5.SetFont(&m_editFont);
	m_cE6.SetFont(&m_editFont);
	m_cE7.SetFont(&m_editFont);
	m_cE8.SetFont(&m_editFont);
	m_cE9.SetFont(&m_editFont);
	m_cF1.SetFont(&m_editFont);
	m_cF2.SetFont(&m_editFont);
	m_cF3.SetFont(&m_editFont);
	m_cF4.SetFont(&m_editFont);
	m_cF5.SetFont(&m_editFont);
	m_cF6.SetFont(&m_editFont);
	m_cF7.SetFont(&m_editFont);
	m_cF8.SetFont(&m_editFont);
	m_cF9.SetFont(&m_editFont);
	m_cG1.SetFont(&m_editFont);
	m_cG2.SetFont(&m_editFont);
	m_cG3.SetFont(&m_editFont);
	m_cG4.SetFont(&m_editFont);
	m_cG5.SetFont(&m_editFont);
	m_cG6.SetFont(&m_editFont);
	m_cG7.SetFont(&m_editFont);
	m_cG8.SetFont(&m_editFont);
	m_cG9.SetFont(&m_editFont);
	m_cH1.SetFont(&m_editFont);
	m_cH2.SetFont(&m_editFont);
	m_cH3.SetFont(&m_editFont);
	m_cH4.SetFont(&m_editFont);
	m_cH5.SetFont(&m_editFont);
	m_cH6.SetFont(&m_editFont);
	m_cH7.SetFont(&m_editFont);
	m_cH8.SetFont(&m_editFont);
	m_cH9.SetFont(&m_editFont);
	m_cI1.SetFont(&m_editFont);
	m_cI2.SetFont(&m_editFont);
	m_cI3.SetFont(&m_editFont);
	m_cI4.SetFont(&m_editFont);
	m_cI5.SetFont(&m_editFont);
	m_cI6.SetFont(&m_editFont);
	m_cI7.SetFont(&m_editFont);
	m_cI8.SetFont(&m_editFont);
	m_cI9.SetFont(&m_editFont);


	//初始化SUDOKUmap
	InitSUDOKUmap();

	//初始化BlankMAT & ProDesignSolMAT;
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			BlankMAT[i][j] = ProDesignSolMAT[i][j] = ProDesignAnsMAT[i][j] = 0;
		}
	}

	//上色
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			SetDlgItemInt((*(SUDOKUmap[i][j])).GetDlgCtrlID(), 0);
		}
	}

	//初始化CurrentBlankPos
	CurrentBlankPos[0] = 0;
	CurrentBlankPos[1] = 0;

	//初始化m_Val
	m_Val = 9999;

	// 为组合框控件的列表框添加列表项“Naive”   
    m_Difficulty.InsertString(0, _T("Naive"));   
    // 为组合框控件的列表框添加列表项“Easy”   
    m_Difficulty.InsertString(1, _T("Easy")); 
	// 为组合框控件的列表框添加列表项“Normal”   
    m_Difficulty.InsertString(2, _T("Normal")); 
	//为组合框控件的列表框添加列表项“Hard”   
	m_Difficulty.InsertString(3, _T("Hard")); 
	//为组合框控件的列表框添加列表项“Sometimes Naive”   
	m_Difficulty.InsertString(4, _T("Sometimes Naive")); 
    // 默认选择第一项   
    m_Difficulty.SetCurSel(0);  

	//初始化 m_Difficulty_Level
	m_Difficulty_Level = m_Difficulty.GetCurSel(); 

	// 默认选中“问题解决：”单选按钮   
    CheckDlgButton(IDC_PROSOLVE, 1);   
    OnBnClickedProsolve(); 
	OnBnClickedFileinput();
	OnBnClickedCheckps();  
    m_PS.SetCheck(1);   
    m_FileInput.SetCheck(1);    

	//初始化m_StdAns
	m_StdAns = NULL;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSUDOKUMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSUDOKUMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}





//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSUDOKUMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSUDOKUMFCDlg::OnBnClickedProsolve()
{
	// TODO: 在此添加控件通知处理程序代码

	InitAllCheckBoxStatus();

	m_Finish1.EnableWindow(TRUE);   
    m_PE.EnableWindow(TRUE);   
    m_PS.EnableWindow(TRUE);   
    m_CFileInput.EnableWindow(TRUE);   
    m_CManualInput.EnableWindow(TRUE);   
    m_CPSR.EnableWindow(TRUE);   
	m_FileInput.EnableWindow(TRUE);   
    m_ManualInput.EnableWindow(TRUE); 
	m_SpinLR.EnableWindow(TRUE);   
    m_SpinUD.EnableWindow(TRUE); 
	m_cDisplay.EnableWindow(TRUE);
	m_FileIn.EnableWindow(TRUE);
	m_Reset1.EnableWindow(TRUE);

	bSolveOrDesign = true;
}


void CSUDOKUMFCDlg::OnBnClickedProdesign()
{
	// TODO: 在此添加控件通知处理程序代码

	InitAllCheckBoxStatus();

	m_ProDesign.EnableWindow(TRUE);   
    m_Finish2.EnableWindow(TRUE);   
    m_StdAnswer.EnableWindow(TRUE);   
    m_Difficulty.EnableWindow(TRUE);   
    m_CPDR.EnableWindow(TRUE);  

	bSolveOrDesign = false;
}


void CSUDOKUMFCDlg::InitAllCheckBoxStatus()   
{   
    // 全部禁用   
	//第一模块
    m_Finish1.EnableWindow(FALSE);   
    m_PE.EnableWindow(FALSE);   
    m_PS.EnableWindow(FALSE);   
    m_CFileInput.EnableWindow(FALSE);   
    m_CManualInput.EnableWindow(FALSE);   
    m_CPSR.EnableWindow(FALSE);   
	m_FileInput.EnableWindow(FALSE);   
    m_ManualInput.EnableWindow(FALSE); 
	m_SpinLR.EnableWindow(FALSE);   
    m_SpinUD.EnableWindow(FALSE); 
	m_cDisplay.EnableWindow(FALSE);
	m_FileIn.EnableWindow(FALSE);
	m_Reset1.EnableWindow(FALSE);
	//第二模块
	m_ProDesign.EnableWindow(FALSE);   
    m_Finish2.EnableWindow(FALSE);   
    m_StdAnswer.EnableWindow(FALSE);   
    m_Difficulty.EnableWindow(FALSE);   
    m_CPDR.EnableWindow(FALSE);   
  
    // 全部非选中   
    m_PE.SetCheck(0);   
    m_PS.SetCheck(0);   
    m_FileInput.SetCheck(0);   
    m_ManualInput.SetCheck(0);    
}  


void CSUDOKUMFCDlg::OnBnClickedFileinput()
{
	// TODO: 在此添加控件通知处理程序代码

	InitInputCheckBoxStatus();

	m_CFileInput.EnableWindow(TRUE);
	m_cDisplay.EnableWindow(TRUE);
	m_FileIn.EnableWindow(TRUE);

	m_ManualInput.SetCheck(0); 
	bFileOrManual = true;
}


void CSUDOKUMFCDlg::OnBnClickedManualinput()
{
	// TODO: 在此添加控件通知处理程序代码

	InitInputCheckBoxStatus();

	m_CManualInput.EnableWindow(TRUE);   
	m_SpinLR.EnableWindow(TRUE);   
	m_SpinUD.EnableWindow(TRUE);   

	m_FileInput.SetCheck(0);  
	bFileOrManual = false;
	DisplayCurrentBlankPos();
}


void CSUDOKUMFCDlg::InitInputCheckBoxStatus()
{
	//第一模块
	m_CFileInput.EnableWindow(FALSE);  
	m_cDisplay.EnableWindow(FALSE);
	m_FileIn.EnableWindow(FALSE);

	//第二模块
	m_CManualInput.EnableWindow(FALSE);   
	m_SpinLR.EnableWindow(FALSE);   
	m_SpinUD.EnableWindow(FALSE);   
}


void CSUDOKUMFCDlg::OnBnClickedCheckpe()
{
	// TODO: 在此添加控件通知处理程序代码

	m_PS.SetCheck(0);
	bPEOrPS = true;
}


void CSUDOKUMFCDlg::OnBnClickedCheckps()
{
	// TODO: 在此添加控件通知处理程序代码

	m_PE.SetCheck(0);
	bPEOrPS = false;
}


void CSUDOKUMFCDlg::OnDeltaposSpinud(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
	if(pNMUpDown-> iDelta == 1) // 如果此值为1 , 说明点击了Spin的往下箭头 
	{  
		//增加编辑框中的数字值
		nUpOrDown = 1;
		GetCurrentBlankPos();
		nUpOrDown = 0;
		DisplayCurrentBlankPos();
    } 
	else if(pNMUpDown-> iDelta == -1) // 如果此值为-1 , 说明点击了Spin的往上箭头 
    { 
		//减少编辑框中的数字值 
		nUpOrDown = -1;
		GetCurrentBlankPos();
		nUpOrDown = 0;
		DisplayCurrentBlankPos();
    }
}


void CSUDOKUMFCDlg::OnDeltaposSpinlr(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
	if(pNMUpDown-> iDelta == 1) // 如果此值为1 , 说明点击了Spin的往右箭头 
	{  
		//增加编辑框中的数字值
		nLeftOrRight = -1;
		GetCurrentBlankPos();
		nLeftOrRight = 0;
		DisplayCurrentBlankPos();
    } 
	else if(pNMUpDown-> iDelta == -1) // 如果此值为-1 , 说明点击了Spin的往左箭头 
    { 
		//减少编辑框中的数字值 
		nLeftOrRight = 1;
		GetCurrentBlankPos();
		nLeftOrRight = 0;
		DisplayCurrentBlankPos();
    }
}


void CSUDOKUMFCDlg::DisplayCurrentBlankPos()
{
	CString sDisplay;

	switch(CurrentBlankPos[1])
	{
	case 0:
		sDisplay += _T("A");	break;
	case 1:
		sDisplay += _T("B");	break;
	case 2:
		sDisplay += _T("C");	break;
	case 3:
		sDisplay += _T("D");	break;
	case 4:
		sDisplay += _T("E");	break;
	case 5:
		sDisplay += _T("F");	break;
	case 6:
		sDisplay += _T("G");	break;
	case 7:
		sDisplay += _T("H");	break;
	case 8:
		sDisplay += _T("I");	break;
	}

	switch(CurrentBlankPos[0])
	{
	case 0:
		sDisplay += _T("1");	break;
	case 1:
		sDisplay += _T("2");	break;
	case 2:
		sDisplay += _T("3");	break;
	case 3:
		sDisplay += _T("4");	break;
	case 4:
		sDisplay += _T("5");	break;
	case 5:
		sDisplay += _T("6");	break;
	case 6:
		sDisplay += _T("7");	break;
	case 7:
		sDisplay += _T("8");	break;
	case 8:
		sDisplay += _T("9");	break;
	}

	// 将结果字符串显示于对应编辑框中   
    SetDlgItemText(IDC_DISPLAY, sDisplay); 
}


void CSUDOKUMFCDlg::GetCurrentBlankPos()
{
	if(CurrentBlankPos[0]+nUpOrDown >= 0 && CurrentBlankPos[0]+nUpOrDown <= 8)
	{
		CurrentBlankPos[0] += nUpOrDown;
	}
	if(CurrentBlankPos[1]+nLeftOrRight >= 0 && CurrentBlankPos[1]+nLeftOrRight <= 8)
	{
		CurrentBlankPos[1] += nLeftOrRight;
	}
}


void CSUDOKUMFCDlg::InitSUDOKUmap()
{
	SUDOKUmap[0][0] = &m_cA1;
	SUDOKUmap[1][0] = &m_cA2;
	SUDOKUmap[2][0] = &m_cA3;
	SUDOKUmap[3][0] = &m_cA4;
	SUDOKUmap[4][0] = &m_cA5;
	SUDOKUmap[5][0] = &m_cA6;
	SUDOKUmap[6][0] = &m_cA7;
	SUDOKUmap[7][0] = &m_cA8;
	SUDOKUmap[8][0] = &m_cA9;
	SUDOKUmap[0][1] = &m_cB1;
	SUDOKUmap[1][1] = &m_cB2;
	SUDOKUmap[2][1] = &m_cB3;
	SUDOKUmap[3][1] = &m_cB4;
	SUDOKUmap[4][1] = &m_cB5;
	SUDOKUmap[5][1] = &m_cB6;
	SUDOKUmap[6][1] = &m_cB7;
	SUDOKUmap[7][1] = &m_cB8;
	SUDOKUmap[8][1] = &m_cB9;
	SUDOKUmap[0][2] = &m_cC1;
	SUDOKUmap[1][2] = &m_cC2;
	SUDOKUmap[2][2] = &m_cC3;
	SUDOKUmap[3][2] = &m_cC4;
	SUDOKUmap[4][2] = &m_cC5;
	SUDOKUmap[5][2] = &m_cC6;
	SUDOKUmap[6][2] = &m_cC7;
	SUDOKUmap[7][2] = &m_cC8;
	SUDOKUmap[8][2] = &m_cC9;
	SUDOKUmap[0][3] = &m_cD1;
	SUDOKUmap[1][3] = &m_cD2;
	SUDOKUmap[2][3] = &m_cD3;
	SUDOKUmap[3][3] = &m_cD4;
	SUDOKUmap[4][3] = &m_cD5;
	SUDOKUmap[5][3] = &m_cD6;
	SUDOKUmap[6][3] = &m_cD7;
	SUDOKUmap[7][3] = &m_cD8;
	SUDOKUmap[8][3] = &m_cD9;
	SUDOKUmap[0][4] = &m_cE1;
	SUDOKUmap[1][4] = &m_cE2;
	SUDOKUmap[2][4] = &m_cE3;
	SUDOKUmap[3][4] = &m_cE4;
	SUDOKUmap[4][4] = &m_cE5;
	SUDOKUmap[5][4] = &m_cE6;
	SUDOKUmap[6][4] = &m_cE7;
	SUDOKUmap[7][4] = &m_cE8;
	SUDOKUmap[8][4] = &m_cE9;
	SUDOKUmap[0][5] = &m_cF1;
	SUDOKUmap[1][5] = &m_cF2;
	SUDOKUmap[2][5] = &m_cF3;
	SUDOKUmap[3][5] = &m_cF4;
	SUDOKUmap[4][5] = &m_cF5;
	SUDOKUmap[5][5] = &m_cF6;
	SUDOKUmap[6][5] = &m_cF7;
	SUDOKUmap[7][5] = &m_cF8;
	SUDOKUmap[8][5] = &m_cF9;
	SUDOKUmap[0][6] = &m_cG1;
	SUDOKUmap[1][6] = &m_cG2;
	SUDOKUmap[2][6] = &m_cG3;
	SUDOKUmap[3][6] = &m_cG4;
	SUDOKUmap[4][6] = &m_cG5;
	SUDOKUmap[5][6] = &m_cG6;
	SUDOKUmap[6][6] = &m_cG7;
	SUDOKUmap[7][6] = &m_cG8;
	SUDOKUmap[8][6] = &m_cG9;
	SUDOKUmap[0][7] = &m_cH1;
	SUDOKUmap[1][7] = &m_cH2;
	SUDOKUmap[2][7] = &m_cH3;
	SUDOKUmap[3][7] = &m_cH4;
	SUDOKUmap[4][7] = &m_cH5;
	SUDOKUmap[5][7] = &m_cH6;
	SUDOKUmap[6][7] = &m_cH7;
	SUDOKUmap[7][7] = &m_cH8;
	SUDOKUmap[8][7] = &m_cH9;
	SUDOKUmap[0][8] = &m_cI1;
	SUDOKUmap[1][8] = &m_cI2;
	SUDOKUmap[2][8] = &m_cI3;
	SUDOKUmap[3][8] = &m_cI4;
	SUDOKUmap[4][8] = &m_cI5;
	SUDOKUmap[5][8] = &m_cI6;
	SUDOKUmap[6][8] = &m_cI7;
	SUDOKUmap[7][8] = &m_cI8;
	SUDOKUmap[8][8] = &m_cI9;
}


void CSUDOKUMFCDlg::OnEnChangeEditmanualinput()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	// 将该控件中的数据保存到相应的变量 
    int n = GetDlgItemInt(IDC_EDITMANUALINPUT);  
	if(n >= 1 && n <= 9)	
	{
		//m_editA1 = n;
		BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
		SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
	}
	if(n == 0)	
	{
		//m_editA1 = n;
		BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
		SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
	}
	  
}


bool CSUDOKUMFCDlg::IsBlank(CWnd* pWnd)
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			if(BlankMAT[i][j] == 0)
			{
				if((*(SUDOKUmap[i][j])).GetDlgCtrlID() == pWnd-> GetDlgCtrlID())	return true;
			}
		}
	}
	return false;
}


bool CSUDOKUMFCDlg::IsNumOccupied(CWnd* pWnd)
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			if(BlankMAT[i][j] == 1)
			{
				if((*(SUDOKUmap[i][j])).GetDlgCtrlID() == pWnd-> GetDlgCtrlID())	return true;
			}
		}
	}
	return false;
}


//*&&*****************************************************&&*
HBRUSH CSUDOKUMFCDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor); 

	if(IsBlank(pWnd)/*(pWnd-> GetDlgCtrlID() == IDC_ECA1)*/ && (nCtlColor == CTLCOLOR_EDIT)/* && bSolveOrDesign*/) 
	{
		COLORREF bkColor = RGB(255, 235, 205);	//空为白杏仁色
		BlankBrush.CreateSolidBrush(bkColor);

		//文本颜色设为白杏仁色 
		if(GetDlgItemInt(pWnd-> GetDlgCtrlID()) != 0)	pDC-> SetTextColor(RGB(0, 0, 0));
		else pDC-> SetTextColor(RGB(255, 235, 205)); 

		//文本背景模式设为透明   
		pDC-> SetBkMode(TRANSPARENT); 

		// Return handle to our CBrush object 
		hbr = BlankBrush; 
	}
	else if(IsNumOccupied(pWnd)/*(pWnd-> GetDlgCtrlID() == IDC_ECA1)*/ && (nCtlColor == CTLCOLOR_EDIT)/* && bSolveOrDesign*/)
	{
		COLORREF bkColor = RGB(240, 255, 255);	//已填处为天蓝色
		NumBrush.CreateSolidBrush(bkColor);

		//文本颜色设为黑色 
		pDC-> SetTextColor(RGB(0, 0, 0)); 

		//文本背景模式设为透明   
		pDC-> SetBkMode(TRANSPARENT); 

		// Return handle to our CBrush object 
		hbr = NumBrush;
	}
	else 
	{ 
		HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor); 
		return hbr; 
	} 
	return hbr; 
}


void CSUDOKUMFCDlg::OnBnClickedFinish1()
{
	// TODO: 在此添加控件通知处理程序代码

	iMAT ProMAT(9, 9);
	iMAT AnsMAT(9, 9);

	bFileOrManual = true;
	m_ManualInput.SetCheck(0);
	OnBnClickedFileinput();
	m_FileInput.SetCheck(1);

	//完成输入
	if(bFileOrManual)
	{
		for(int i = 0 ; i < 9 ; i++)
		{
			for(int j = 0 ; j < 9 ; j++)
			{
				int n = GetDlgItemInt(SUDOKUmap[i][j]->GetDlgCtrlID());
				if(n >= 1 && n <= 9)
				{
					ProMAT(i, j) = n;
					BlankMAT[i][j] = 1;
				}
				else
				{
					ProMAT(i, j) = 0;
					BlankMAT[i][j] = 0;
				} 
			}
		}
	}


	//完成输出
	if(bPEOrPS)
	{
		int numSol = GetNumSol(ProMAT);
		if(numSol <= 10)
		{
			CString cstr, cs;
			cstr += _T("有");
			cs.Format(_T("%d"),numSol);
			cstr += cs;
			cstr += _T("个解");
			SetDlgItemText(IDC_EDITPSR, cstr);
		}
		else
		{
			SetDlgItemText(IDC_EDITPSR, _T("解个数较多(>10)"));
		}
	}
	else
	{
		AnsMAT = GetAnsMAT(ProMAT);
		for(int i = 0 ; i < 9 ; i++)
		{
			for(int j = 0 ; j < 9 ; j++)
			{
				if(AnsMAT(i, j) == 0)	SetDlgItemText(IDC_EDITPSR, _T("无解"));
				SetDlgItemInt((*(SUDOKUmap[i][j])).GetDlgCtrlID(), AnsMAT(i, j));
			}
		}
		CString cstr;
		GetDlgItemText(IDC_EDITPSR, cstr);
		if(cstr != _T("无解"))	SetDlgItemText(IDC_EDITPSR, _T("有解"));
	}
}


iMAT CSUDOKUMFCDlg::GetAnsMAT(iMAT ProMAT)
{
	GameState gameState(ProMAT);
	GameState AnsGS = depthFirstSearchWithSweep2(gameState);
	return AnsGS.getCurrentState();
}


int CSUDOKUMFCDlg::GetNumSol(iMAT ProMAT)
{
	GameState gameState(ProMAT);
	return depthFirstSearchForJudge(gameState);
}


void CSUDOKUMFCDlg::OnBnClickedFilein()
{
	// TODO: 在此添加控件通知处理程序代码

	CString csFileName /*= _T("input.txt")*/;
	GetDlgItemText(IDC_EDITFILEINPUT, csFileName);

	int len = csFileName.GetLength();

	char* cFileName = new char[len+1];
	memset(cFileName, 0, len+1);

	WideCharToMultiByte(CP_OEMCP, NULL, (LPCWSTR)csFileName, -1,NULL, 0, NULL, FALSE);
	WideCharToMultiByte(CP_OEMCP, NULL, (LPCWSTR)csFileName, -1,(LPSTR)cFileName, len, NULL, FALSE);

	cFileName[len] = '\0';

	iMAT ProMAT(9, 9);
	ProMAT.getInputFromFile(cFileName);

	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			int n = ProMAT(i, j);
			if(n >= 1 && n <= 9)
			{
				SetDlgItemInt((*(SUDOKUmap[i][j])).GetDlgCtrlID(), n);
				BlankMAT[i][j] = 1;
			}
			else
			{
				SetDlgItemInt((*(SUDOKUmap[i][j])).GetDlgCtrlID(), 0);
				BlankMAT[i][j] = 0;
			} 
		}
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	//OnBnClickedManualinput();
	//m_ManualInput.SetCheck(1); 

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();
 

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEca9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECA9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 0;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcb9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECB9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 1;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcc9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECC9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 2;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcd9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECD9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 3;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEce9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECE9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 4;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcf9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECF9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 5;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEcg9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECG9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 6;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEch9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECH9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 7;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI1);  
		CurrentBlankPos[0] = 0;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI2);  
		CurrentBlankPos[0] = 1;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI3);  
		CurrentBlankPos[0] = 2;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI4);  
		CurrentBlankPos[0] = 3;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI5);  
		CurrentBlankPos[0] = 4;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI6);  
		CurrentBlankPos[0] = 5;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI7);  
		CurrentBlankPos[0] = 6;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI8);  
		CurrentBlankPos[0] = 7;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnEnChangeEci9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	if(m_Val == 9999 && !bFileOrManual)
	{
		int n = m_Val = GetDlgItemInt(IDC_ECI9);  
		CurrentBlankPos[0] = 8;
		CurrentBlankPos[1] = 8;
		DisplayCurrentBlankPos();

		if(m_Val >= 1 && m_Val <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n);
		}
		else if(m_Val == 0)	
		{
			//m_editA1 = n;
			BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 0;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), 0);
		}
		else if(m_Val/10 >= 1 && m_Val/10 <= 9)
		{
			//m_editA1 = n;
			if(bSolveOrDesign)	BlankMAT[CurrentBlankPos[0]][CurrentBlankPos[1]] = 1;
			m_Val = -9999;
			SetDlgItemInt((*(SUDOKUmap[CurrentBlankPos[0]][CurrentBlankPos[1]])).GetDlgCtrlID(), n/10);
		}
		else	m_Val = 9999;
	}
	else if(m_Val == -9999)
	{
		m_Val = 9999;
	}
}


void CSUDOKUMFCDlg::OnBnClickedReset1()
{
	// TODO: 在此添加控件通知处理程序代码

	SetDlgItemText(IDC_EDITPSR, _T(" "));
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			BlankMAT[i][j] = 0;
			SetDlgItemInt((*(SUDOKUmap[i][j])).GetDlgCtrlID(), 0);
		}
	}
}


void CSUDOKUMFCDlg::OnCbnSelchangeCombodifficulty()
{
	// TODO: 在此添加控件通知处理程序代码

	m_Difficulty_Level = m_Difficulty.GetCurSel(); 
}


void CSUDOKUMFCDlg::OnBnClickedDesignpro()
{
	// TODO: 在此添加控件通知处理程序代码
	bFileOrManual = false;
	generatePuzzle gP;
	iMAT gameSolMAT = gP.preGenerate();
	iMAT gameAnsMAT(9, 9);

	//生成ProDesignSolMAT & ProDesignAnsMAT
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			ProDesignSolMAT[i][j] = gameSolMAT(i, j);
		}
	}

	switch(m_Difficulty_Level)
	{
	case 0:
		gameAnsMAT = gP.generateNaive();
		break;
	case 1:
		gameAnsMAT = gP.generateEasy();
		break;
	case 2:
		gameAnsMAT = gP.generateNormal();
		break;
	case 3:
		gameAnsMAT = gP.generateHard();
		break;
	case 4:
		gameAnsMAT = gP.generateSometimesNaive();
		break;
	}

	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			ProDesignAnsMAT[i][j] = gameAnsMAT(i, j);
		}
	}

	//完成输出
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			int n = ProDesignAnsMAT[i][j];
			if(n >= 1 && n <= 9)
			{
				BlankMAT[i][j] = 1;
				SetDlgItemInt((*(SUDOKUmap[i][j])).GetDlgCtrlID(), n);
			}
			else
			{
				BlankMAT[i][j] = 0;
				SetDlgItemInt((*(SUDOKUmap[i][j])).GetDlgCtrlID(), 0);
			} 
		}
	}
}


void CSUDOKUMFCDlg::OnBnClickedFinish2()
{
	// TODO: 在此添加控件通知处理程序代码

	bool b = true;
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			int n = GetDlgItemInt((*(SUDOKUmap[i][j])).GetDlgCtrlID());
			if(n != 0 && n != ProDesignSolMAT[i][j])
			{
				SetDlgItemText(IDC_EDITPDR, _T("填写有误"));
				b = false;
				break;
			}
		}
		if(!b)
		{
			break;
		}
	}
	if(b)	SetDlgItemText(IDC_EDITPDR, _T("已填写部分正确"));
}


void CSUDOKUMFCDlg::OnBnClickedQuit()
{
	// TODO: 在此添加控件通知处理程序代码

	INT_PTR nRes;             // 用于保存DoModal函数的返回值   
  
    CSudokuQuit SudokuQuit;           // 构造对话框类CSudokuQuit的实例   

	SudokuQuit.m_vAskQuit = _T("您真的要退出么？");
    nRes = SudokuQuit.DoModal();  // 弹出对话框   
    if(IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
        return;   
	else if(IDOK == nRes)
	{
		AfxGetMainWnd()->SendMessage(WM_CLOSE); 
	}
}


void CSUDOKUMFCDlg::OnBnClickedStdanswer()
{
	// TODO: 在此添加控件通知处理程序代码

	/*INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	CStdAns StdAns;           // 构造对话框类CSudokuQuit的实例 

	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			StdAns.BlankMAT[i][j] = BlankMAT[i][j];
		}
	}
	int* np = StdAns.SUDOKUValmap[0][0];
	*np = ProDesignSolMAT[0][0];
	//StdAns.UpdateStdAnsData();
	/*for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			*(StdAns.SUDOKUValmap[i][j]) = ProDesignSolMAT[i][j];
		}
	}

	nRes = StdAns.DoModal();  // 弹出对话框 */

	if (NULL == m_StdAns)   
    {   
        // 创建非模态对话框实例   
        m_StdAns = new CStdAns();   
        m_StdAns->Create(IDD_DIALOG2, this);   
    }   

	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			m_StdAns->BlankMAT[i][j] = BlankMAT[i][j];
		}
	}

	/*for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			*(m_StdAns->SUDOKUValmap[i][j]) = ProDesignSolMAT[i][j];
		}
	}*/

	m_StdAns->m_editA1 = ProDesignSolMAT[0][0];
	m_StdAns->m_editA2 = ProDesignSolMAT[1][0];
	m_StdAns->m_editA3 = ProDesignSolMAT[2][0];
	m_StdAns->m_editA4 = ProDesignSolMAT[3][0];
	m_StdAns->m_editA5 = ProDesignSolMAT[4][0];
	m_StdAns->m_editA6 = ProDesignSolMAT[5][0];
	m_StdAns->m_editA7 = ProDesignSolMAT[6][0];
	m_StdAns->m_editA8 = ProDesignSolMAT[7][0];
	m_StdAns->m_editA9 = ProDesignSolMAT[8][0];
	m_StdAns->m_editB1 = ProDesignSolMAT[0][1];
	m_StdAns->m_editB2 = ProDesignSolMAT[1][1];
	m_StdAns->m_editB3 = ProDesignSolMAT[2][1];
	m_StdAns->m_editB4 = ProDesignSolMAT[3][1];
	m_StdAns->m_editB5 = ProDesignSolMAT[4][1];
	m_StdAns->m_editB6 = ProDesignSolMAT[5][1];
	m_StdAns->m_editB7 = ProDesignSolMAT[6][1];
	m_StdAns->m_editB8 = ProDesignSolMAT[7][1];
	m_StdAns->m_editB9 = ProDesignSolMAT[8][1];
	m_StdAns->m_editC1 = ProDesignSolMAT[0][2];
	m_StdAns->m_editC2 = ProDesignSolMAT[1][2];
	m_StdAns->m_editC3 = ProDesignSolMAT[2][2];
	m_StdAns->m_editC4 = ProDesignSolMAT[3][2];
	m_StdAns->m_editC5 = ProDesignSolMAT[4][2];
	m_StdAns->m_editC6 = ProDesignSolMAT[5][2];
	m_StdAns->m_editC7 = ProDesignSolMAT[6][2];
	m_StdAns->m_editC8 = ProDesignSolMAT[7][2];
	m_StdAns->m_editC9 = ProDesignSolMAT[8][2];
	m_StdAns->m_editD1 = ProDesignSolMAT[0][3];
	m_StdAns->m_editD2 = ProDesignSolMAT[1][3];
	m_StdAns->m_editD3 = ProDesignSolMAT[2][3];
	m_StdAns->m_editD4 = ProDesignSolMAT[3][3];
	m_StdAns->m_editD5 = ProDesignSolMAT[4][3];
	m_StdAns->m_editD6 = ProDesignSolMAT[5][3];
	m_StdAns->m_editD7 = ProDesignSolMAT[6][3];
	m_StdAns->m_editD8 = ProDesignSolMAT[7][3];
	m_StdAns->m_editD9 = ProDesignSolMAT[8][3];
	m_StdAns->m_editE1 = ProDesignSolMAT[0][4];
	m_StdAns->m_editE2 = ProDesignSolMAT[1][4];
	m_StdAns->m_editE3 = ProDesignSolMAT[2][4];
	m_StdAns->m_editE4 = ProDesignSolMAT[3][4];
	m_StdAns->m_editE5 = ProDesignSolMAT[4][4];
	m_StdAns->m_editE6 = ProDesignSolMAT[5][4];
	m_StdAns->m_editE7 = ProDesignSolMAT[6][4];
	m_StdAns->m_editE8 = ProDesignSolMAT[7][4];
	m_StdAns->m_editE9 = ProDesignSolMAT[8][4];
	m_StdAns->m_editF1 = ProDesignSolMAT[0][5];
	m_StdAns->m_editF2 = ProDesignSolMAT[1][5];
	m_StdAns->m_editF3 = ProDesignSolMAT[2][5];
	m_StdAns->m_editF4 = ProDesignSolMAT[3][5];
	m_StdAns->m_editF5 = ProDesignSolMAT[4][5];
	m_StdAns->m_editF6 = ProDesignSolMAT[5][5];
	m_StdAns->m_editF7 = ProDesignSolMAT[6][5];
	m_StdAns->m_editF8 = ProDesignSolMAT[7][5];
	m_StdAns->m_editF9 = ProDesignSolMAT[8][5];
	m_StdAns->m_editG1 = ProDesignSolMAT[0][6];
	m_StdAns->m_editG2 = ProDesignSolMAT[1][6];
	m_StdAns->m_editG3 = ProDesignSolMAT[2][6];
	m_StdAns->m_editG4 = ProDesignSolMAT[3][6];
	m_StdAns->m_editG5 = ProDesignSolMAT[4][6];
	m_StdAns->m_editG6 = ProDesignSolMAT[5][6];
	m_StdAns->m_editG7 = ProDesignSolMAT[6][6];
	m_StdAns->m_editG8 = ProDesignSolMAT[7][6];
	m_StdAns->m_editG9 = ProDesignSolMAT[8][6];
	m_StdAns->m_editH1 = ProDesignSolMAT[0][7];
	m_StdAns->m_editH2 = ProDesignSolMAT[1][7];
	m_StdAns->m_editH3 = ProDesignSolMAT[2][7];
	m_StdAns->m_editH4 = ProDesignSolMAT[3][7];
	m_StdAns->m_editH5 = ProDesignSolMAT[4][7];
	m_StdAns->m_editH6 = ProDesignSolMAT[5][7];
	m_StdAns->m_editH7 = ProDesignSolMAT[6][7];
	m_StdAns->m_editH8 = ProDesignSolMAT[7][7];
	m_StdAns->m_editH9 = ProDesignSolMAT[8][7];
	m_StdAns->m_editI1 = ProDesignSolMAT[0][8];
	m_StdAns->m_editI2 = ProDesignSolMAT[1][8];
	m_StdAns->m_editI3 = ProDesignSolMAT[2][8];
	m_StdAns->m_editI4 = ProDesignSolMAT[3][8];
	m_StdAns->m_editI5 = ProDesignSolMAT[4][8];
	m_StdAns->m_editI6 = ProDesignSolMAT[5][8];
	m_StdAns->m_editI7 = ProDesignSolMAT[6][8];
	m_StdAns->m_editI8 = ProDesignSolMAT[7][8];
	m_StdAns->m_editI9 = ProDesignSolMAT[8][8];

	m_StdAns->UpdateStdAnsData();

	// 显示非模态对话框   
    m_StdAns->ShowWindow(SW_SHOW);

	


}
