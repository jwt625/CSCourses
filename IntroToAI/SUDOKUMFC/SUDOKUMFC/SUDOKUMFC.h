
// SUDOKUMFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"	// ������


// CSUDOKUMFCApp:
// �йش����ʵ�֣������ SUDOKUMFC.cpp
//

class CSUDOKUMFCApp : public CWinApp
{
public:
	CSUDOKUMFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSUDOKUMFCApp theApp;