// chatroomDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CchatroomDlg �Ի���
class CchatroomDlg : public CDialog
{
// ����
public:
	CchatroomDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHATROOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreTranslateMessage(MSG* pMsg);
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	CListBox m_listbox_main;
	CEdit m_editctrl_main;
	afx_msg void OnLbnSelchangeList1();
};
