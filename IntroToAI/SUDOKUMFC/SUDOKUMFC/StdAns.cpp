// StdAns.cpp : 实现文件
//

#include "stdafx.h"
#include "SUDOKUMFC.h"
#include "StdAns.h"
#include "afxdialogex.h"


// CStdAns 对话框

IMPLEMENT_DYNAMIC(CStdAns, CDialogEx)

CStdAns::CStdAns(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStdAns::IDD, pParent)
{
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
}

CStdAns::~CStdAns()
{
}

void CStdAns::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ECA12, m_editA1);
	DDV_MinMaxInt(pDX, m_editA1, 1, 9);
	DDX_Text(pDX, IDC_ECA22, m_editA2);
	DDV_MinMaxInt(pDX, m_editA2, 1, 9);
	DDX_Text(pDX, IDC_ECA32, m_editA3);
	DDV_MinMaxInt(pDX, m_editA3, 1, 9);
	DDX_Text(pDX, IDC_ECA42, m_editA4);
	DDV_MinMaxInt(pDX, m_editA4, 1, 9);
	DDX_Text(pDX, IDC_ECA52, m_editA5);
	DDV_MinMaxInt(pDX, m_editA5, 1, 9);
	DDX_Text(pDX, IDC_ECA62, m_editA6);
	DDV_MinMaxInt(pDX, m_editA6, 1, 9);
	DDX_Text(pDX, IDC_ECA72, m_editA7);
	DDV_MinMaxInt(pDX, m_editA7, 1, 9);
	DDX_Text(pDX, IDC_ECA82, m_editA8);
	DDV_MinMaxInt(pDX, m_editA8, 1, 9);
	DDX_Text(pDX, IDC_ECA92, m_editA9);
	DDV_MinMaxInt(pDX, m_editA9, 1, 9);
	DDX_Text(pDX, IDC_ECB12, m_editB1);
	DDV_MinMaxInt(pDX, m_editB1, 1, 9);
	DDX_Text(pDX, IDC_ECB22, m_editB2);
	DDV_MinMaxInt(pDX, m_editB2, 1, 9);
	DDX_Text(pDX, IDC_ECB32, m_editB3);
	DDV_MinMaxInt(pDX, m_editB3, 1, 9);
	DDX_Text(pDX, IDC_ECB42, m_editB4);
	DDV_MinMaxInt(pDX, m_editB4, 1, 9);
	DDX_Text(pDX, IDC_ECB52, m_editB5);
	DDV_MinMaxInt(pDX, m_editB5, 1, 9);
	DDX_Text(pDX, IDC_ECB62, m_editB6);
	DDV_MinMaxInt(pDX, m_editB6, 1, 9);
	DDX_Text(pDX, IDC_ECB72, m_editB7);
	DDV_MinMaxInt(pDX, m_editB7, 1, 9);
	DDX_Text(pDX, IDC_ECB82, m_editB8);
	DDV_MinMaxInt(pDX, m_editB8, 1, 9);
	DDX_Text(pDX, IDC_ECB92, m_editB9);
	DDV_MinMaxInt(pDX, m_editB9, 1, 9);
	DDX_Text(pDX, IDC_ECC12, m_editC1);
	DDV_MinMaxInt(pDX, m_editC1, 1, 9);
	DDX_Text(pDX, IDC_ECC22, m_editC2);
	DDV_MinMaxInt(pDX, m_editC2, 1, 9);
	DDX_Text(pDX, IDC_ECC32, m_editC3);
	DDV_MinMaxInt(pDX, m_editC3, 1, 9);
	DDX_Text(pDX, IDC_ECC42, m_editC4);
	DDV_MinMaxInt(pDX, m_editC4, 1, 9);
	DDX_Text(pDX, IDC_ECC52, m_editC5);
	DDV_MinMaxInt(pDX, m_editC5, 1, 9);
	DDX_Text(pDX, IDC_ECC62, m_editC6);
	DDV_MinMaxInt(pDX, m_editC6, 1, 9);
	DDX_Text(pDX, IDC_ECC72, m_editC7);
	DDV_MinMaxInt(pDX, m_editC7, 1, 9);
	DDX_Text(pDX, IDC_ECC82, m_editC8);
	DDV_MinMaxInt(pDX, m_editC8, 1, 9);
	DDX_Text(pDX, IDC_ECC92, m_editC9);
	DDV_MinMaxInt(pDX, m_editC9, 1, 9);
	DDX_Text(pDX, IDC_ECD12, m_editD1);
	DDV_MinMaxInt(pDX, m_editD1, 1, 9);
	DDX_Text(pDX, IDC_ECD22, m_editD2);
	DDV_MinMaxInt(pDX, m_editD2, 1, 9);
	DDX_Text(pDX, IDC_ECD32, m_editD3);
	DDV_MinMaxInt(pDX, m_editD3, 1, 9);
	DDX_Text(pDX, IDC_ECD42, m_editD4);
	DDV_MinMaxInt(pDX, m_editD4, 1, 9);
	DDX_Text(pDX, IDC_ECD52, m_editD5);
	DDV_MinMaxInt(pDX, m_editD5, 1, 9);
	DDX_Text(pDX, IDC_ECD62, m_editD6);
	DDV_MinMaxInt(pDX, m_editD6, 1, 9);
	DDX_Text(pDX, IDC_ECD72, m_editD7);
	DDV_MinMaxInt(pDX, m_editD7, 1, 9);
	DDX_Text(pDX, IDC_ECD82, m_editD8);
	DDV_MinMaxInt(pDX, m_editD8, 1, 9);
	DDX_Text(pDX, IDC_ECD92, m_editD9);
	DDV_MinMaxInt(pDX, m_editD9, 1, 9);
	DDX_Text(pDX, IDC_ECE12, m_editE1);
	DDV_MinMaxInt(pDX, m_editE1, 1, 9);
	DDX_Text(pDX, IDC_ECE22, m_editE2);
	DDV_MinMaxInt(pDX, m_editE2, 1, 9);
	DDX_Text(pDX, IDC_ECE32, m_editE3);
	DDV_MinMaxInt(pDX, m_editE3, 1, 9);
	DDX_Text(pDX, IDC_ECE42, m_editE4);
	DDV_MinMaxInt(pDX, m_editE4, 1, 9);
	DDX_Text(pDX, IDC_ECE52, m_editE5);
	DDV_MinMaxInt(pDX, m_editE5, 1, 9);
	DDX_Text(pDX, IDC_ECE62, m_editE6);
	DDV_MinMaxInt(pDX, m_editE6, 1, 9);
	DDX_Text(pDX, IDC_ECE72, m_editE7);
	DDV_MinMaxInt(pDX, m_editE7, 1, 9);
	DDX_Text(pDX, IDC_ECE82, m_editE8);
	DDV_MinMaxInt(pDX, m_editE8, 1, 9);
	DDX_Text(pDX, IDC_ECE92, m_editE9);
	DDV_MinMaxInt(pDX, m_editE9, 1, 9);
	DDX_Text(pDX, IDC_ECF12, m_editF1);
	DDV_MinMaxInt(pDX, m_editF1, 1, 9);
	DDX_Text(pDX, IDC_ECF22, m_editF2);
	DDV_MinMaxInt(pDX, m_editF2, 1, 9);
	DDX_Text(pDX, IDC_ECF32, m_editF3);
	DDV_MinMaxInt(pDX, m_editF3, 1, 9);
	DDX_Text(pDX, IDC_ECF42, m_editF4);
	DDV_MinMaxInt(pDX, m_editF4, 1, 9);
	DDX_Text(pDX, IDC_ECF52, m_editF5);
	DDV_MinMaxInt(pDX, m_editF5, 1, 9);
	DDX_Text(pDX, IDC_ECF62, m_editF6);
	DDV_MinMaxInt(pDX, m_editF6, 1, 9);
	DDX_Text(pDX, IDC_ECF72, m_editF7);
	DDV_MinMaxInt(pDX, m_editF7, 1, 9);
	DDX_Text(pDX, IDC_ECF82, m_editF8);
	DDV_MinMaxInt(pDX, m_editF8, 1, 9);
	DDX_Text(pDX, IDC_ECF92, m_editF9);
	DDV_MinMaxInt(pDX, m_editF9, 1, 9);
	DDX_Text(pDX, IDC_ECG12, m_editG1);
	DDV_MinMaxInt(pDX, m_editG1, 1, 9);
	DDX_Text(pDX, IDC_ECG22, m_editG2);
	DDV_MinMaxInt(pDX, m_editG2, 1, 9);
	DDX_Text(pDX, IDC_ECG32, m_editG3);
	DDV_MinMaxInt(pDX, m_editG3, 1, 9);
	DDX_Text(pDX, IDC_ECG42, m_editG4);
	DDV_MinMaxInt(pDX, m_editG4, 1, 9);
	DDX_Text(pDX, IDC_ECG52, m_editG5);
	DDV_MinMaxInt(pDX, m_editG5, 1, 9);
	DDX_Text(pDX, IDC_ECG62, m_editG6);
	DDV_MinMaxInt(pDX, m_editG6, 1, 9);
	DDX_Text(pDX, IDC_ECG72, m_editG7);
	DDV_MinMaxInt(pDX, m_editG7, 1, 9);
	DDX_Text(pDX, IDC_ECG82, m_editG8);
	DDV_MinMaxInt(pDX, m_editG8, 1, 9);
	DDX_Text(pDX, IDC_ECG92, m_editG9);
	DDV_MinMaxInt(pDX, m_editG9, 1, 9);
	DDX_Text(pDX, IDC_ECH12, m_editH1);
	DDV_MinMaxInt(pDX, m_editH1, 1, 9);
	DDX_Text(pDX, IDC_ECH22, m_editH2);
	DDV_MinMaxInt(pDX, m_editH2, 1, 9);
	DDX_Text(pDX, IDC_ECH32, m_editH3);
	DDV_MinMaxInt(pDX, m_editH3, 1, 9);
	DDX_Text(pDX, IDC_ECH42, m_editH4);
	DDV_MinMaxInt(pDX, m_editH4, 1, 9);
	DDX_Text(pDX, IDC_ECH52, m_editH5);
	DDV_MinMaxInt(pDX, m_editH5, 1, 9);
	DDX_Text(pDX, IDC_ECH62, m_editH6);
	DDV_MinMaxInt(pDX, m_editH6, 1, 9);
	DDX_Text(pDX, IDC_ECH72, m_editH7);
	DDV_MinMaxInt(pDX, m_editH7, 1, 9);
	DDX_Text(pDX, IDC_ECH82, m_editH8);
	DDV_MinMaxInt(pDX, m_editH8, 1, 9);
	DDX_Text(pDX, IDC_ECH92, m_editH9);
	DDV_MinMaxInt(pDX, m_editH9, 1, 9);
	DDX_Text(pDX, IDC_ECI12, m_editI1);
	DDV_MinMaxInt(pDX, m_editI1, 1, 9);
	DDX_Text(pDX, IDC_ECI22, m_editI2);
	DDV_MinMaxInt(pDX, m_editI2, 1, 9);
	DDX_Text(pDX, IDC_ECI32, m_editI3);
	DDV_MinMaxInt(pDX, m_editI3, 1, 9);
	DDX_Text(pDX, IDC_ECI42, m_editI4);
	DDV_MinMaxInt(pDX, m_editI4, 1, 9);
	DDX_Text(pDX, IDC_ECI52, m_editI5);
	DDV_MinMaxInt(pDX, m_editI5, 1, 9);
	DDX_Text(pDX, IDC_ECI62, m_editI6);
	DDV_MinMaxInt(pDX, m_editI6, 1, 9);
	DDX_Text(pDX, IDC_ECI72, m_editI7);
	DDV_MinMaxInt(pDX, m_editI7, 1, 9);
	DDX_Text(pDX, IDC_ECI82, m_editI8);
	DDV_MinMaxInt(pDX, m_editI8, 1, 9);
	DDX_Text(pDX, IDC_ECI92, m_editI9);
	DDV_MinMaxInt(pDX, m_editI9, 1, 9);
	//DDX_Control(pDX, IDC_INPUT_COMBO, m_comboInput);
	DDX_Control(pDX, IDC_ECA12, m_cA1);
	DDX_Control(pDX, IDC_ECA22, m_cA2);
	DDX_Control(pDX, IDC_ECA32, m_cA3);
	DDX_Control(pDX, IDC_ECA42, m_cA4);
	DDX_Control(pDX, IDC_ECA52, m_cA5);
	DDX_Control(pDX, IDC_ECA62, m_cA6);
	DDX_Control(pDX, IDC_ECA72, m_cA7);
	DDX_Control(pDX, IDC_ECA82, m_cA8);
	DDX_Control(pDX, IDC_ECA92, m_cA9);
	DDX_Control(pDX, IDC_ECB12, m_cB1);
	DDX_Control(pDX, IDC_ECB22, m_cB2);
	DDX_Control(pDX, IDC_ECB32, m_cB3);
	DDX_Control(pDX, IDC_ECB42, m_cB4);
	DDX_Control(pDX, IDC_ECB52, m_cB5);
	DDX_Control(pDX, IDC_ECB62, m_cB6);
	DDX_Control(pDX, IDC_ECB72, m_cB7);
	DDX_Control(pDX, IDC_ECB82, m_cB8);
	DDX_Control(pDX, IDC_ECB92, m_cB9);
	DDX_Control(pDX, IDC_ECC12, m_cC1);
	DDX_Control(pDX, IDC_ECC22, m_cC2);
	DDX_Control(pDX, IDC_ECC32, m_cC3);
	DDX_Control(pDX, IDC_ECC42, m_cC4);
	DDX_Control(pDX, IDC_ECC52, m_cC5);
	DDX_Control(pDX, IDC_ECC62, m_cC6);
	DDX_Control(pDX, IDC_ECC72, m_cC7);
	DDX_Control(pDX, IDC_ECC82, m_cC8);
	DDX_Control(pDX, IDC_ECC92, m_cC9);
	DDX_Control(pDX, IDC_ECD12, m_cD1);
	DDX_Control(pDX, IDC_ECD22, m_cD2);
	DDX_Control(pDX, IDC_ECD32, m_cD3);
	DDX_Control(pDX, IDC_ECD42, m_cD4);
	DDX_Control(pDX, IDC_ECD52, m_cD5);
	DDX_Control(pDX, IDC_ECD62, m_cD6);
	DDX_Control(pDX, IDC_ECD72, m_cD7);
	DDX_Control(pDX, IDC_ECD82, m_cD8);
	DDX_Control(pDX, IDC_ECD92, m_cD9);
	DDX_Control(pDX, IDC_ECE12, m_cE1);
	DDX_Control(pDX, IDC_ECE22, m_cE2);
	DDX_Control(pDX, IDC_ECE32, m_cE3);
	DDX_Control(pDX, IDC_ECE42, m_cE4);
	DDX_Control(pDX, IDC_ECE52, m_cE5);
	DDX_Control(pDX, IDC_ECE62, m_cE6);
	DDX_Control(pDX, IDC_ECE72, m_cE7);
	DDX_Control(pDX, IDC_ECE82, m_cE8);
	DDX_Control(pDX, IDC_ECE92, m_cE9);
	DDX_Control(pDX, IDC_ECF12, m_cF1);
	DDX_Control(pDX, IDC_ECF22, m_cF2);
	DDX_Control(pDX, IDC_ECF32, m_cF3);
	DDX_Control(pDX, IDC_ECF42, m_cF4);
	DDX_Control(pDX, IDC_ECF52, m_cF5);
	DDX_Control(pDX, IDC_ECF62, m_cF6);
	DDX_Control(pDX, IDC_ECF72, m_cF7);
	DDX_Control(pDX, IDC_ECF82, m_cF8);
	DDX_Control(pDX, IDC_ECF92, m_cF9);
	DDX_Control(pDX, IDC_ECG12, m_cG1);
	DDX_Control(pDX, IDC_ECG22, m_cG2);
	DDX_Control(pDX, IDC_ECG32, m_cG3);
	DDX_Control(pDX, IDC_ECG42, m_cG4);
	DDX_Control(pDX, IDC_ECG52, m_cG5);
	DDX_Control(pDX, IDC_ECG62, m_cG6);
	DDX_Control(pDX, IDC_ECG72, m_cG7);
	DDX_Control(pDX, IDC_ECG82, m_cG8);
	DDX_Control(pDX, IDC_ECG92, m_cG9);
	DDX_Control(pDX, IDC_ECH12, m_cH1);
	DDX_Control(pDX, IDC_ECH22, m_cH2);
	DDX_Control(pDX, IDC_ECH32, m_cH3);
	DDX_Control(pDX, IDC_ECH42, m_cH4);
	DDX_Control(pDX, IDC_ECH52, m_cH5);
	DDX_Control(pDX, IDC_ECH62, m_cH6);
	DDX_Control(pDX, IDC_ECH72, m_cH7);
	DDX_Control(pDX, IDC_ECH82, m_cH8);
	DDX_Control(pDX, IDC_ECH92, m_cH9);
	DDX_Control(pDX, IDC_ECI12, m_cI1);
	DDX_Control(pDX, IDC_ECI22, m_cI2);
	DDX_Control(pDX, IDC_ECI32, m_cI3);
	DDX_Control(pDX, IDC_ECI42, m_cI4);
	DDX_Control(pDX, IDC_ECI52, m_cI5);
	DDX_Control(pDX, IDC_ECI62, m_cI6);
	DDX_Control(pDX, IDC_ECI72, m_cI7);
	DDX_Control(pDX, IDC_ECI82, m_cI8);
	DDX_Control(pDX, IDC_ECI92, m_cI9);
}


BEGIN_MESSAGE_MAP(CStdAns, CDialogEx)

	ON_WM_CTLCOLOR()	//*&&*

END_MESSAGE_MAP()


// CStdAns 消息处理程序


BOOL CStdAns::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	m_Font.CreatePointFont(300, _T("黑体"));	//*&&*修改字体   
	// 设置新字体
	m_cA1.SetFont(&m_Font); 
	m_cA2.SetFont(&m_Font); 
	m_cA3.SetFont(&m_Font); 
	m_cA4.SetFont(&m_Font); 
	m_cA5.SetFont(&m_Font); 
	m_cA6.SetFont(&m_Font); 
	m_cA7.SetFont(&m_Font); 
	m_cA8.SetFont(&m_Font); 
	m_cA9.SetFont(&m_Font); 
	m_cB1.SetFont(&m_Font); 
	m_cB2.SetFont(&m_Font); 
	m_cB3.SetFont(&m_Font); 
	m_cB4.SetFont(&m_Font); 
	m_cB5.SetFont(&m_Font); 
	m_cB6.SetFont(&m_Font); 
	m_cB7.SetFont(&m_Font); 
	m_cB8.SetFont(&m_Font); 
	m_cB9.SetFont(&m_Font); 
	m_cC1.SetFont(&m_Font);
	m_cC2.SetFont(&m_Font); 
	m_cC3.SetFont(&m_Font); 
	m_cC4.SetFont(&m_Font); 
	m_cC5.SetFont(&m_Font); 
	m_cC6.SetFont(&m_Font); 
	m_cC7.SetFont(&m_Font); 
	m_cC8.SetFont(&m_Font); 
	m_cC9.SetFont(&m_Font); 
	m_cD1.SetFont(&m_Font); 
	m_cD2.SetFont(&m_Font);
	m_cD3.SetFont(&m_Font);
	m_cD4.SetFont(&m_Font);
	m_cD5.SetFont(&m_Font);
	m_cD6.SetFont(&m_Font);
	m_cD7.SetFont(&m_Font);
	m_cD8.SetFont(&m_Font);
	m_cD9.SetFont(&m_Font);
	m_cE1.SetFont(&m_Font);
	m_cE2.SetFont(&m_Font);
	m_cE3.SetFont(&m_Font);
	m_cE4.SetFont(&m_Font);
	m_cE5.SetFont(&m_Font);
	m_cE6.SetFont(&m_Font);
	m_cE7.SetFont(&m_Font);
	m_cE8.SetFont(&m_Font);
	m_cE9.SetFont(&m_Font);
	m_cF1.SetFont(&m_Font);
	m_cF2.SetFont(&m_Font);
	m_cF3.SetFont(&m_Font);
	m_cF4.SetFont(&m_Font);
	m_cF5.SetFont(&m_Font);
	m_cF6.SetFont(&m_Font);
	m_cF7.SetFont(&m_Font);
	m_cF8.SetFont(&m_Font);
	m_cF9.SetFont(&m_Font);
	m_cG1.SetFont(&m_Font);
	m_cG2.SetFont(&m_Font);
	m_cG3.SetFont(&m_Font);
	m_cG4.SetFont(&m_Font);
	m_cG5.SetFont(&m_Font);
	m_cG6.SetFont(&m_Font);
	m_cG7.SetFont(&m_Font);
	m_cG8.SetFont(&m_Font);
	m_cG9.SetFont(&m_Font);
	m_cH1.SetFont(&m_Font);
	m_cH2.SetFont(&m_Font);
	m_cH3.SetFont(&m_Font);
	m_cH4.SetFont(&m_Font);
	m_cH5.SetFont(&m_Font);
	m_cH6.SetFont(&m_Font);
	m_cH7.SetFont(&m_Font);
	m_cH8.SetFont(&m_Font);
	m_cH9.SetFont(&m_Font);
	m_cI1.SetFont(&m_Font);
	m_cI2.SetFont(&m_Font);
	m_cI3.SetFont(&m_Font);
	m_cI4.SetFont(&m_Font);
	m_cI5.SetFont(&m_Font);
	m_cI6.SetFont(&m_Font);
	m_cI7.SetFont(&m_Font);
	m_cI8.SetFont(&m_Font);
	m_cI9.SetFont(&m_Font);

	//初始化SUDOKUmap
	InitSUDOKUmap();

	//初始化BlankMAT
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			BlankMAT[i][j] = 0;
			SUDOKUValmap[i][j] = NULL;
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CStdAns::InitSUDOKUmap()
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


//*&&*****************************************************&&*
HBRUSH CStdAns::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


bool CStdAns::IsBlank(CWnd* pWnd)
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


bool CStdAns::IsNumOccupied(CWnd* pWnd)
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


void CStdAns::UpdateStdAnsData()
{
	UpdateData(FALSE);
}