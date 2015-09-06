// wwf7_ssuDlg.h : header file
//

#if !defined(AFX_WWF7_SSUDLG_H__272E5C02_68C8_45B2_BD41_F11798805416__INCLUDED_)
#define AFX_WWF7_SSUDLG_H__272E5C02_68C8_45B2_BD41_F11798805416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWwf7_ssuDlg dialog

class CWwf7_ssuDlg : public CDialog
{
// Construction
public:
	CString UrlEncode( CString str );
	CWwf7_ssuDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWwf7_ssuDlg)
	enum { IDD = IDD_WWF7_SSU_DIALOG };
	CEdit	m_logw;
	CString	m_fid;
	CString	m_mode;
	CString	m_msg;
	CString	m_pid;
	CString	m_srv;
	CString	m_subj;
	CString	m_tid;
	CString	m_log;
	CString	m_obj;
	CString	m_ref;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWwf7_ssuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWwf7_ssuDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnstart();
	afx_msg void OnBtnclearlog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WWF7_SSUDLG_H__272E5C02_68C8_45B2_BD41_F11798805416__INCLUDED_)
