#define _WIN32_WINNT	_WIN32_WINNT_MAXVER
#include <afxwin.h>

class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

class CMainFrame : public CFrameWnd {
public:
	CMainFrame();

protected:
	afx_msg void OnPaint();

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);

	DECLARE_MESSAGE_MAP()
};

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
END_MESSAGE_MAP()

CMainFrame::CMainFrame()
{
	Create(NULL, L"메시지 맵");
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.TextOutW(100, 100, L"메시지 맵 프로그래밍");

	CPen pen(PS_SOLID, 3, RGB(0, 0, 255));
	CBrush brush(RGB(255, 255, 200));

	int olddc = dc.SaveDC();

	dc.SelectObject(&pen);
	dc.SelectObject(&brush);
	dc.Rectangle(300, 300, 500, 500);

	dc.RestoreDC(olddc);
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	//AfxMessageBox(L"마우스 왼쪽 버튼 다운");
	CClientDC dc(this);
	dc.Ellipse(point.x - 50, point.y - 50, point.x + 50, point.y + 50);
}

void CMainFrame::OnRButtonDown(UINT nFlags, CPoint point)
{
	//AfxMessageBox(L"마우스 오른쪽 버튼 다운");
	CClientDC dc(this);
	dc.Ellipse(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
}

void CMainFrame::OnLButtonUp(UINT nFlags, CPoint point)
{
	//AfxMessageBox(L"마우스 왼쪽 버튼 업");
	CClientDC dc(this);
	dc.Rectangle(point.x - 50, point.y - 50, point.x + 50, point.y + 50);
}

void CMainFrame::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	dc.Ellipse(point.x - 20, point.y - 20, point.x + 20, point.y + 20);
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_DOWN)
		AfxMessageBox(L"아래");
}

void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);

	CString str;
	str.Format(L"(%d, %d), (%d, %d)", rect.left, rect.top, rect.right, rect.bottom);
	dc.TextOutW(100, 200, str);
}

CMyApp app;