#define _WIN32_WINNT	_WIN32_WINNT_MAXVER
#include <afxwin.h>

class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

BOOL CMyApp::InitInstance()
{
	AfxMessageBox(L"파생 클래스의 InitInstance() Overriding");

	return TRUE;
}

CMyApp app;