
// gProjectDlg.h : 헤더 파일
#include "DlgSetMenu.h"
#pragma once


// CgProjectDlg 대화 상자
class CgProjectDlg : public CDialogEx
{
	// 생성입니다.
public:
	CImage m_image;
	CImage m_buffer; //더블버퍼링용
	int m_nRadius;

	int m_nStartX;
	int m_nStartY;
	int m_nEndX;
	int m_nEndY;

	CgProjectDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	CDlgSetMenu *m_pDlgSetMenu;

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GPROJECT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
