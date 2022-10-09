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
	DECLARE_MESSAGE_MAP()
};

BOOL CMyApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow(); // WM_PAINT 메시지 발생

	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMainFrame::CMainFrame()
{
	Create(NULL, L"GUI 프로그래밍");
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);
	dc.Ellipse(100, 200, 300, 400);
	dc.TextOut(100, 100, L"MFC를 직접 상속받은 프로그램");
}

CMyApp app;