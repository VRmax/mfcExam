#pragma once


// CDlgSetMenu 대화 상자입니다.

class CDlgSetMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSetMenu)

public:
	CDlgSetMenu(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgSetMenu();

	CWnd* m_pParent;
	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETMENU_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDraw();
	int m_editStartX;
	int m_editStartY;
	int m_editEndX;
	int m_editEndY;
};
