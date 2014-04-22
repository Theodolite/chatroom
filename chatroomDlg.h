// chatroomDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CchatroomDlg 对话框
class CchatroomDlg : public CDialog
{
// 构造
public:
	CchatroomDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHATROOM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
