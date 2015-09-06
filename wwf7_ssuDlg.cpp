// wwf7_ssuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wwf7_ssu.h"
#include "wwf7_ssuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWwf7_ssuDlg dialog

CWwf7_ssuDlg::CWwf7_ssuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWwf7_ssuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWwf7_ssuDlg)
	m_fid = _T("");
	m_mode = _T("editTopic");
	m_msg = _T("");
	m_pid = _T("");
	m_srv = _T("localhost");
	m_subj = _T("");
	m_tid = _T("");
	m_log = _T("");
	m_obj = _T("/forum/post_message.asp?PN=1");
	m_ref = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWwf7_ssuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWwf7_ssuDlg)
	DDX_Control(pDX, IDC_LOG, m_logw);
	DDX_Text(pDX, IDC_EDTFID, m_fid);
	DDX_Text(pDX, IDC_EDTMODE, m_mode);
	DDX_Text(pDX, IDC_EDTMSG, m_msg);
	DDX_Text(pDX, IDC_EDTPID, m_pid);
	DDX_Text(pDX, IDC_EDTSRV, m_srv);
	DDX_Text(pDX, IDC_EDTSUBJ, m_subj);
	DDX_Text(pDX, IDC_EDTTID, m_tid);
	DDX_Text(pDX, IDC_LOG, m_log);
	DDX_Text(pDX, IDC_EDTOBJ, m_obj);
	DDX_Text(pDX, IDC_EDTREF, m_ref);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWwf7_ssuDlg, CDialog)
	//{{AFX_MSG_MAP(CWwf7_ssuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNSTART, OnBtnstart)
	ON_BN_CLICKED(IDC_BTNCLEARLOG, OnBtnclearlog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWwf7_ssuDlg message handlers

BOOL CWwf7_ssuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWwf7_ssuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWwf7_ssuDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWwf7_ssuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWwf7_ssuDlg::OnBtnstart() 
{
	UpdateData( TRUE );

	CInternetSession session;
	CHttpFile	 *file = NULL;
	CHttpConnection  *http = NULL;
	CString formdata = "";

	formdata += CString( "mode=" ) + m_mode;
	formdata += CString( "&subject=" ) + UrlEncode( m_subj );
	formdata += CString( "&message=" ) + UrlEncode( m_msg );
	formdata += CString( "&PID=" ) + m_pid;
	formdata += CString( "&TID=" ) + m_tid;
	formdata += CString( "&FID=" ) + m_fid;
	formdata += CString( "&browser=IE&Submit=Update+Post" );

	m_log += "Starting...\r\n";
	m_log += "post data:\r\n";
	m_log += formdata;
	m_log += "\r\n";

	m_log += CString( "trying " ) + m_srv + CString( "...\r\n" );
	UpdateData( FALSE );
	m_logw.SetSel( m_log.GetLength(), m_log.GetLength(), FALSE );

	try
	{
		http = session.GetHttpConnection( m_srv );

		m_log += "sending request...\r\n";
		UpdateData( FALSE );
		m_logw.SetSel( m_log.GetLength(), m_log.GetLength(), FALSE );

		file = http->OpenRequest(
			CHttpConnection::HTTP_VERB_POST,
			m_obj,
			m_ref
		);

		file->AddRequestHeaders( 
			"Accept: text/*\r\n" \
			"Content-Type: application/x-www-form-urlencoded\r\n" \
		);

		file->SendRequestEx( formdata.GetLength() );
		file->WriteString( formdata );
		file->EndRequest();

		m_log += "response:\r\n--------\r\n";
		CString line;
		for( int i = 0; file->ReadString( line ); i++ )
		{
			m_log += line + CString( "\r\n" );
		}
		m_log += "--------\r\n";
		UpdateData( FALSE );
		m_logw.SetSel( m_log.GetLength(), m_log.GetLength(), FALSE );

		file->Close();
		delete file;

		m_log += "done!\r\n\r\n";
	}

	catch( CInternetException *pEx )
	{
		m_log += "error!\r\n\r\n";
		pEx->Delete();
	}

	UpdateData( FALSE );
	m_logw.SetSel( m_log.GetLength(), m_log.GetLength(), FALSE );
}

void CWwf7_ssuDlg::OnBtnclearlog() 
{
	m_log = "";
	UpdateData( FALSE );
}

CString CWwf7_ssuDlg::UrlEncode(CString str)
{
	CString result = "";
	CString hex;

	for( int i = 0; i < str.GetLength(); i++ )
	{
		hex.Format( "%%%02x", ( unsigned char )str[i] );
		result += hex;
	}

	return result;
}
