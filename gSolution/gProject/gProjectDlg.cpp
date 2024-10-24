
// gProjectDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "gProject.h"
#include "gProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString g_strFileImage = _T("C:\\image\\save.bmp");
// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgProjectDlg ��ȭ ����



CgProjectDlg::CgProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CgProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SET_IMAGE, &CgProjectDlg::OnBnClickedBtnSetImage)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CgProjectDlg::OnBnClickedBtnAction)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_OPEN, &CgProjectDlg::OnBnClickedBtnOpen)
END_MESSAGE_MAP()


// CgProjectDlg �޽��� ó����

BOOL CgProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	//MoveWindow(0,0,1000,800);
	m_pDlgSetMenu = new CDlgSetMenu;
	m_pDlgSetMenu->Create(IDD_SETMENU_DIALOG, this);
	m_pDlgSetMenu->MoveWindow(660, 320, 400, 300);
	m_pDlgSetMenu->ShowWindow(SW_HIDE);

	CreateImage();

	//Invalidate(); // �߰�
	//UpdateWindow(); // �߰�
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CgProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CgProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}

	UpdateDisplay();
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CgProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CgProjectDlg::CreateImage()
{
	int nWidth = 640;	//����
	int nHeight = 480;	//����
	int nBpp = 8;	//8 ��� 16 �÷�

	m_image.Create(nWidth, -nHeight, nBpp);	//�̹��� ����

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	unsigned char* fm = (unsigned char*)m_image.GetBits();  // �̹����� ù��° ������

	memset(fm, 0xff, nWidth * nHeight);	//�޸��ʱ�ȭ
}

void CgProjectDlg::LoadImage()
{
	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Load(g_strFileImage);

	UpdateDisplay();
}

void CgProjectDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CgProjectDlg::moveCircle(int startX, int startY, int endX, int endY)
{

	int nStep = m_nRadius / 2;
	int nGray = 80;
	int nDistanceX = (endX - startX) / nStep; //������ �����ֱ�
	int nDistanceY = (endY - startY) / nStep;

	unsigned char* fm = (unsigned char*)m_image.GetBits();  // �̹����� ù��° ������
	if (!fm) {
		return;
	}

	int nCurrentX = startX;
	int nCurrentY = startY;

	for (int i = 0; i < nStep; i++) {
		drawCircle(fm, nCurrentX, nCurrentY, 0xff);

		nCurrentX += nDistanceX;
		nCurrentY += nDistanceY;

		drawCircle(fm, nCurrentX, nCurrentY, nGray);
		UpdateDisplay();
		Sleep(100);

		saveImege(i);
	}
}

void CgProjectDlg::drawCircle(unsigned char* fm, int x, int y, int nGray)
{
	int nRadius = m_nRadius;
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++) {
		for (int i = x; i < x + nRadius * 2; i++) {
			if (inInCircle(i, j, nCenterX, nCenterY, nRadius))
				fm[j*nPitch + i] = nGray;
		}
	}
}

BOOL CgProjectDlg::inInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;
	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (vaildImgPos(i, j) && dDist < nRadius*nRadius) {
		bRet = true;
	}

	return bRet;
}

void CgProjectDlg::OnBnClickedBtnAction()
{
	ClearImage();
	moveCircle(m_nStartX, m_nStartY, m_nEndX, m_nEndY);
	UpdateDisplay();
}

#include "DlgSetMenu.h"
void CgProjectDlg::OnBnClickedBtnSetImage()
{
	m_pDlgSetMenu->ShowWindow(SW_SHOW);
}

void CgProjectDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	delete m_pDlgSetMenu;
}

BOOL CgProjectDlg::vaildImgPos(int x, int y)
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));
}

void CgProjectDlg::ClearImage()
{
	if (m_image.IsNull()) {	//�̹����� ������� ������ Ȯ��
		return;
	}

	// �̹��� ũ�� Ȯ��
	int width = m_image.GetWidth();
	int height = m_image.GetHeight();

	m_image.Destroy(); // ���� �̹��� �޸� ����
	CreateImage();
}

void CgProjectDlg::saveImege(int nStep)
{
	TCHAR path[MAX_PATH];

	GetModuleFileName(NULL, path, MAX_PATH);	//�������� ��� Ž��

	CString modulePath = path;
	int pos = modulePath.ReverseFind(_T('\\'));
	if (pos != -1) {
		modulePath = modulePath.Left(pos); //�������� ��θ� ����
	}

	// ���� �̸� ����
	CString strFile;
	strFile.Format(_T("%s\\image%d.jpg"), modulePath, nStep);
	m_image.Save(strFile);
}

void CgProjectDlg::LoadImege()
{
	CFileDialog dlg(TRUE, _T("jpg"), NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
		_T("Image Files (*.jpg;*.jpeg;*.bmp;*.png)|*.jpg;*.jpeg;*.bmp;*.png||"));

	// ��ȭ ���ڸ� ǥ���ϰ� ����ڰ� ������ �����ߴ��� Ȯ���մϴ�.
	if (dlg.DoModal() == IDOK) {
		CString imagePath = dlg.GetPathName(); //���õ� ���� ��θ� �����ɴϴ�.

		if (m_image.GetWidth() > 0 || m_image.GetHeight() > 0)
			m_image.Destroy(); // ���� �̹����� �����մϴ�.

		m_image.Load(imagePath);

		// ȭ�鿡 ǥ���� �� �ֵ��� ������Ʈ�մϴ�.
		UpdateDisplay();

		CPoint center = findCircleCenter(m_image);

		DrawX(m_image, center, 5);
		CString str;
		str.Format(_T("���� �߽�: (%d, %d)"), center.x, center.y);
		AfxMessageBox(str);

	}
}

CPoint CgProjectDlg::findCircleCenter(CImage& image)
{
	CPoint center(0, 0);
	int count = 0;
	int nWidth = image.GetWidth();
	int nHeight = image.GetHeight();
	for (int y = 0; y < nHeight; y++) {
		for (int x = 0; x < nWidth; x++) {
			BYTE pPixel = image.GetPixel(x, y);	//�ȼ� ����������
			if (pPixel <= 100)
			{
				center.x += x;
				center.y += y;
				count++;
			}
		}
	}

	if (count > 0)
	{
		center.x /= count;
		center.y /= count;
	}

	return center;
}

void CgProjectDlg::DrawX(CImage& image, CPoint center, int size) {
	if (center.x <= 0 ||  center.y <= 0) 
		return;
	
	COLORREF color = RGB(255, 0, 0); // ������

	for (int i = -size; i <= size; ++i) {
		if (center.x + i >= 0 && center.x + i < image.GetWidth() && center.y + i >= 0 && center.y + i < image.GetHeight()) {
			image.SetPixel(center.x + i, center.y + i, color); // �밢�� 1
			image.SetPixel(center.x + i, center.y - i, color); // �밢�� 2
		}
	}

	UpdateDisplay();
}

void CgProjectDlg::OnBnClickedBtnOpen()
{
	LoadImege();
}
