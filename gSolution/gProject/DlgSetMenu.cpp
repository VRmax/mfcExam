// DlgSetMenu.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gProject.h"
#include "DlgSetMenu.h"
#include "afxdialogex.h"


// CDlgSetMenu ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgSetMenu, CDialogEx)

CDlgSetMenu::CDlgSetMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SETMENU_DIALOG, pParent)
	, m_editStartX(0)
	, m_editStartY(0)
	, m_editEndX(0)
	, m_editEndY(0)
{
	m_pParent = pParent;
}

CDlgSetMenu::~CDlgSetMenu()
{
}

void CDlgSetMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_START_POS_X, m_editStartX);
	DDV_MinMaxInt(pDX, m_editStartX, 0, 640);
	DDX_Text(pDX, IDC_EDIT_START_POS_Y, m_editStartY);
	DDV_MinMaxInt(pDX, m_editStartY, 0, 480);
	DDX_Text(pDX, IDC_EDIT_END_POS_X, m_editEndX);
	DDV_MinMaxInt(pDX, m_editEndX, 0, 640);
	DDX_Text(pDX, IDC_EDIT_END_POS_Y, m_editEndY);
	DDV_MinMaxInt(pDX, m_editEndY, 0, 480);
}


BEGIN_MESSAGE_MAP(CDlgSetMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_DRAW, &CDlgSetMenu::OnBnClickedBtnDraw)
END_MESSAGE_MAP()


// CDlgSetMenu �޽��� ó�����Դϴ�.

#include "gProjectDlg.h"
void CDlgSetMenu::OnBnClickedBtnDraw()
{

	CgProjectDlg *pMainDlg = (CgProjectDlg*)GetParent();

	CString strStartX, strStartY, strEndX, strEndY;
	GetDlgItem(IDC_EDIT_START_POS_X)->GetWindowText(strStartX);
	GetDlgItem(IDC_EDIT_START_POS_Y)->GetWindowText(strStartY);
	GetDlgItem(IDC_EDIT_END_POS_X)->GetWindowText(strEndX);
	GetDlgItem(IDC_EDIT_END_POS_Y)->GetWindowText(strEndY);

	int sx = _ttoi(strStartX);
	int sy = _ttoi(strStartY);
	int ex = _ttoi(strEndX);
	int ey = _ttoi(strEndY);

	if (sx < 0 || sx > 640 || sy < 0 || sy > 480 ||
		ex < 0 || ex > 640 || ey < 0 || ey > 480)
	{
		AfxMessageBox(_T("�Է� ���� ������ ������ϴ�."));
		return;
	}
	int nGray = 80;

	if (pMainDlg) {
		pMainDlg->ClearImage();
		unsigned char* fm = (unsigned char*)pMainDlg->m_image.GetBits();  // �̹����� ù��° ������

		pMainDlg->m_nStartX = _ttoi(strStartX);
		pMainDlg->m_nStartY = _ttoi(strStartY);
		pMainDlg->m_nEndX = _ttoi(strEndX);
		pMainDlg->m_nEndY = _ttoi(strEndY);

		pMainDlg->m_nRadius = rand() % 11 + 10;
		pMainDlg->drawCircle(fm, sx, sy, nGray);
		pMainDlg->UpdateDisplay();
	}
}
