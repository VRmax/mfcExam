#pragma once


// CDlgSetMenu ��ȭ �����Դϴ�.

class CDlgSetMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSetMenu)

public:
	CDlgSetMenu(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgSetMenu();

	CWnd* m_pParent;
	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETMENU_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDraw();
	int m_editStartX;
	int m_editStartY;
	int m_editEndX;
	int m_editEndY;
};
