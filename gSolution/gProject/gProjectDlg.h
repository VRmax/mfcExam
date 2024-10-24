
// gProjectDlg.h : ��� ����
#include "DlgSetMenu.h"
#pragma once


// CgProjectDlg ��ȭ ����
class CgProjectDlg : public CDialogEx
{
	// �����Դϴ�.
public:
	CImage m_image;
	CImage m_buffer; //������۸���
	int m_nRadius;

	int m_nStartX;
	int m_nStartY;
	int m_nEndX;
	int m_nEndY;

	CgProjectDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CDlgSetMenu *m_pDlgSetMenu;

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPROJECT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void CreateImage();
	void UpdateDisplay();
	afx_msg void OnBnClickedBtnSetImage();
	void moveCircle(int startX, int startY, int endX, int endY);
	void drawCircle(unsigned char * fm, int x, int y, int nGray);
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnDestroy();
	BOOL vaildImgPos(int x, int y);
	void clearImage();
	void saveImage(int nStep);
	void loadImege();
	CPoint findCircleCenter(CImage& image);
	void DrawX(CImage & image, CPoint center, int size);
	BOOL inInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);

	afx_msg void OnBnClickedBtnOpen();
};
