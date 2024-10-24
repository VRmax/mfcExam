
// gProjectDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "gProject.h"
#include "gProjectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString g_strFileImage = _T("C:\\image\\save.bmp");
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CgProjectDlg 대화 상자



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


// CgProjectDlg 메시지 처리기

BOOL CgProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//MoveWindow(0,0,1000,800);
	m_pDlgSetMenu = new CDlgSetMenu;
	m_pDlgSetMenu->Create(IDD_SETMENU_DIALOG, this);
	m_pDlgSetMenu->MoveWindow(660, 320, 400, 300);
	m_pDlgSetMenu->ShowWindow(SW_HIDE);

	CreateImage();

	//Invalidate(); // 추가
	//UpdateWindow(); // 추가
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CgProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialogEx::OnPaint();
	}

	UpdateDisplay();
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CgProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CgProjectDlg::CreateImage()
{
	int nWidth = 640;	//가로
	int nHeight = 480;	//세로
	int nBpp = 8;	//8 흑백 16 컬러

	m_image.Create(nWidth, -nHeight, nBpp);	//이미지 생성

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	unsigned char* fm = (unsigned char*)m_image.GetBits();  // 이미지의 첫번째 시작점

	memset(fm, 0xff, nWidth * nHeight);	//메모리초기화
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
	int nDistanceX = (endX - startX) / nStep; //일정한 간격주기
	int nDistanceY = (endY - startY) / nStep;

	unsigned char* fm = (unsigned char*)m_image.GetBits();  // 이미지의 첫번째 시작점
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
	if (m_image.IsNull()) {	//이미지가 비어있지 않은지 확인
		return;
	}

	// 이미지 크기 확인
	int width = m_image.GetWidth();
	int height = m_image.GetHeight();

	m_image.Destroy(); // 이전 이미지 메모리 해제
	CreateImage();
}

void CgProjectDlg::saveImege(int nStep)
{
	TCHAR path[MAX_PATH];

	GetModuleFileName(NULL, path, MAX_PATH);	//실행파일 경로 탐색

	CString modulePath = path;
	int pos = modulePath.ReverseFind(_T('\\'));
	if (pos != -1) {
		modulePath = modulePath.Left(pos); //실행파일 경로만 남김
	}

	// 파일 이름 설정
	CString strFile;
	strFile.Format(_T("%s\\image%d.jpg"), modulePath, nStep);
	m_image.Save(strFile);
}

void CgProjectDlg::LoadImege()
{
	CFileDialog dlg(TRUE, _T("jpg"), NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
		_T("Image Files (*.jpg;*.jpeg;*.bmp;*.png)|*.jpg;*.jpeg;*.bmp;*.png||"));

	// 대화 상자를 표시하고 사용자가 파일을 선택했는지 확인합니다.
	if (dlg.DoModal() == IDOK) {
		CString imagePath = dlg.GetPathName(); //선택된 파일 경로를 가져옵니다.

		if (m_image.GetWidth() > 0 || m_image.GetHeight() > 0)
			m_image.Destroy(); // 기존 이미지를 해제합니다.

		m_image.Load(imagePath);

		// 화면에 표시할 수 있도록 업데이트합니다.
		UpdateDisplay();

		CPoint center = findCircleCenter(m_image);

		DrawX(m_image, center, 5);
		CString str;
		str.Format(_T("원의 중심: (%d, %d)"), center.x, center.y);
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
			BYTE pPixel = image.GetPixel(x, y);	//픽셀 색상가져오기
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
	
	COLORREF color = RGB(255, 0, 0); // 빨간색

	for (int i = -size; i <= size; ++i) {
		if (center.x + i >= 0 && center.x + i < image.GetWidth() && center.y + i >= 0 && center.y + i < image.GetHeight()) {
			image.SetPixel(center.x + i, center.y + i, color); // 대각선 1
			image.SetPixel(center.x + i, center.y - i, color); // 대각선 2
		}
	}

	UpdateDisplay();
}

void CgProjectDlg::OnBnClickedBtnOpen()
{
	LoadImege();
}
