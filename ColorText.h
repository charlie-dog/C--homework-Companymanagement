#include "company.h"
#define IDC_RED         100
#define IDC_GREEN       101
#define IDC_BLUE        102
#define IDC_ADDMEMBER          103
#define IDC_DELETEMEBER        104
#define IDC_LOGIN        105
#define IDC_SETBONUS        106
#define IDC_SETEXTRACT        107
#define IDC_SETTIME        108
#define IDC_SEARCH        109
class CColorStatic : public CStatic
{
protected:
    COLORREF m_clrText;
    COLORREF m_clrBack;
    CBrush m_brBkgnd;

public:
    CColorStatic ();
    void SetTextColor (COLORREF clrText);
    void SetBkColor (COLORREF clrBack);

protected:
    afx_msg HBRUSH CtlColor (CDC* pDC, UINT nCtlColor);
    DECLARE_MESSAGE_MAP ()
};

class CMyApp : public CWinApp
{
public:
    virtual BOOL InitInstance ();
};

class CMainWindow : public CFrameWnd
{
protected:
    int m_cxChar;
    int m_cyChar;
    CFont m_font;

    CColorStatic m_wndText;
    CColorStatic Situation;
    CColorStatic search;
    CColorStatic Print;
    CColorStatic addn1;
    CColorStatic addn2;
    CColorStatic bonusnumt;
    CColorStatic salenumt;
    CColorStatic bonusamontt;
    CColorStatic saleamontt;
    CColorStatic dele;
    CColorStatic edit;
    CColorStatic setsituation;
    CColorStatic time1;
    CColorStatic time2;

    CButton m_wndRadioButtonRed;
    CButton m_wndRadioButtonGreen;
    CButton m_wndRadioButtonBlue;
    CButton Addmember;
    CButton Deletemember;
    CButton LOGER;
    CButton SetBonus;
    CButton SetExtract;
    CButton SetTime;
    CButton Search;

    CButton m_wndGroupBox1;
    CButton m_wndGroupBox2;
    CButton m_wndGroupBox3;
    CButton m_wndGroupBox4;

    CEdit addname;
    CEdit addnum;
    CEdit deletenum;
    CEdit BonusAmount;
    CEdit BonusId;
    CEdit SaleId;
    CEdit SaleAmount;
    CEdit Year;
    CEdit Month;
    CEdit LOGpassword;
    CEdit SearchID;

    Company D;
public:
    CMainWindow ();

protected:
    afx_msg int OnCreate (LPCREATESTRUCT lpcs);
    afx_msg void OnRedButtonClicked ();
    afx_msg void OnGreenButtonClicked ();
    afx_msg void OnBlueButtonClicked ();

    DECLARE_MESSAGE_MAP ()
};
