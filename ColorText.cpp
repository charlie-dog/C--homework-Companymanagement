#include <afxwin.h>
#include "ColorText.h"

CMyApp myApp;

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance ()
{
    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow (m_nCmdShow);
    m_pMainWnd->UpdateWindow ();
    return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map and member functions

BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
    ON_WM_CREATE ()
    ON_BN_CLICKED (IDC_RED, OnRedButtonClicked)
    ON_BN_CLICKED (IDC_GREEN, OnGreenButtonClicked)
    ON_BN_CLICKED (IDC_BLUE, OnBlueButtonClicked)
    ON_BN_CLICKED(IDC_ADDMEMBER, addnew)
    ON_BN_CLICKED(IDC_DELETEMEBER, remove)
    ON_BN_CLICKED(IDC_LOGIN, LOGGIN)
    ON_BN_CLICKED(IDC_SETBONUS, SETBonus)
    ON_BN_CLICKED(IDC_SETEXTRACT, SetSale)
    ON_BN_CLICKED(IDC_SETTIME, SETTime)
    ON_BN_CLICKED(IDC_SEARCH, Searching)
END_MESSAGE_MAP ()

CMainWindow::CMainWindow ()
{
    CString strWndClass = AfxRegisterWndClass (
        0,
        myApp.LoadStandardCursor (IDC_ARROW),
        (HBRUSH) (COLOR_3DFACE + 1),
        myApp.LoadStandardIcon (IDI_WINLOGO)
    );

    Create (strWndClass, _T ("ColorText"));
}

int CMainWindow::OnCreate (LPCREATESTRUCT lpcs)
{
    if (CFrameWnd::OnCreate (lpcs) == -1)
        return -1;

    m_font.CreatePointFont (80, _T ("MS Sans Serif"));

    CClientDC dc (this);
    CFont* pOldFont = dc.SelectObject (&m_font);
    TEXTMETRIC tm;
    dc.GetTextMetrics (&tm);
    m_cxChar = tm.tmAveCharWidth;
    m_cyChar = tm.tmHeight + tm.tmExternalLeading;
    dc.SelectObject (pOldFont);

    m_wndGroupBox1.Create (_T ("人员管理"), WS_CHILD | WS_VISIBLE |
        BS_GROUPBOX, CRect (m_cxChar * 2, m_cyChar, m_cxChar * 80,
        m_cyChar * 9), this, UINT (-1));

    Deletemember.Create(_T("开除"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 5, m_cyChar * 3,
            m_cxChar * 15, m_cyChar * 5), this, IDC_DELETEMEBER);

    dele.Create(_T("工号"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 18,
            m_cyChar * 3, m_cxChar * 23, m_cyChar * 5), this);

    deletenum.Create(ES_LEFT | WS_CHILD | WS_VISIBLE  |
        WS_GROUP, CRect(m_cxChar * 25,
            m_cyChar * 3, m_cxChar * 39, m_cyChar * 5), this, UINT(-1));

    Addmember.Create(_T("招聘"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 5, m_cyChar * 6,
            m_cxChar * 15, m_cyChar * 8), this, IDC_ADDMEMBER);

    addn1.Create(_T("姓名"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 40,
            m_cyChar * 6, m_cxChar * 45, m_cyChar * 8), this);

    addname.Create(ES_LEFT | WS_CHILD | WS_VISIBLE  |
        WS_GROUP, CRect(m_cxChar * 47,
            m_cyChar * 6, m_cxChar * 61, m_cyChar * 8), this, UINT(-1));

    addn2.Create(_T("工号"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 18,
            m_cyChar * 6, m_cxChar * 23, m_cyChar * 8), this);

    edit.Create(_T(""),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 40,
            m_cyChar * 3, m_cxChar * 60, m_cyChar * 5), this);

    addnum.Create(ES_LEFT | WS_CHILD | WS_VISIBLE  |
        WS_GROUP, CRect(m_cxChar * 25,
            m_cyChar * 6, m_cxChar * 39, m_cyChar * 8), this, UINT(-1));


    LOGER.Create(_T("登录"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 90, m_cyChar * 4,
            m_cxChar * 100, m_cyChar * 6), this, IDC_LOGIN);

    m_wndGroupBox3.Create(_T("登录"), WS_CHILD | WS_VISIBLE |
        BS_GROUPBOX, CRect(m_cxChar * 85, m_cyChar, m_cxChar * 115,
            m_cyChar * 9), this, UINT(-1));

    LOGpassword.Create(ES_LEFT | WS_CHILD | WS_VISIBLE | ES_PASSWORD |
        WS_GROUP, CRect(m_cxChar * 90,
            m_cyChar * 6.5, m_cxChar * 110, m_cyChar * 8.5), this, UINT(-1));



    m_wndGroupBox4.Create(_T("信息登记"), WS_CHILD | WS_VISIBLE |
        BS_GROUPBOX, CRect(m_cxChar * 2, m_cyChar*10, m_cxChar * 80,
            m_cyChar * 22), this, UINT(-1));

    SetTime.Create(_T("登记时间"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 4, m_cyChar * 11.5,
            m_cxChar * 17, m_cyChar * 13.5), this, IDC_SETBONUS);

    time1.Create(_T("年"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 20,
            m_cyChar * 11.5, m_cxChar * 25, m_cyChar * 13.5), this);

    time2.Create(_T("月"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 50,
            m_cyChar * 11.5, m_cxChar * 55, m_cyChar * 13.5), this);

    Year.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 27,
            m_cyChar * 11.5, m_cxChar * 48, m_cyChar * 13.5), this, UINT(-1));

    Month.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 58,
            m_cyChar * 11.5, m_cxChar * 78, m_cyChar * 13.5), this, UINT(-1));

    SetBonus.Create(_T("登记售额"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 4, m_cyChar * 14,
            m_cxChar * 17, m_cyChar * 16), this, IDC_SETBONUS);

    SaleId.Create(ES_LEFT | WS_CHILD | WS_VISIBLE  |
        WS_GROUP, CRect(m_cxChar * 27,
            m_cyChar * 14, m_cxChar * 48, m_cyChar * 16), this, UINT(-1));

    SaleAmount.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 58,
            m_cyChar * 14, m_cxChar * 78, m_cyChar * 16), this, UINT(-1));

    salenumt.Create(_T("工号"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 20,
            m_cyChar * 14, m_cxChar * 25, m_cyChar * 16), this);

    saleamontt.Create(_T("金额"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 50,
            m_cyChar * 14, m_cxChar * 55, m_cyChar * 16), this);

    SetExtract.Create(_T("登记奖金"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 4, m_cyChar * 17,
            m_cxChar * 17, m_cyChar * 19), this, IDC_SETEXTRACT);

    BonusId.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 27,
            m_cyChar * 17, m_cxChar * 48, m_cyChar * 19), this, UINT(-1));

    BonusAmount.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 58,
            m_cyChar * 17, m_cxChar * 78, m_cyChar * 19), this, UINT(-1));

    bonusnumt.Create(_T("工号"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 20,
            m_cyChar * 17, m_cxChar * 25, m_cyChar * 19), this);

    bonusamontt.Create(_T("金额"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 50,
            m_cyChar * 17, m_cxChar * 55, m_cyChar * 19), this);

    setsituation.Create(_T("登记状态: 未登记"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 5,
            m_cyChar * 19.5, m_cxChar * 65, m_cyChar * 21.5), this);

    m_wndText.Create (_T ("请登录"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect (m_cxChar * 90,
        m_cyChar * 2, m_cxChar * 110, m_cyChar * 4), this);

    m_wndGroupBox2.Create (_T ("Color"), WS_CHILD | WS_VISIBLE |
        BS_GROUPBOX, CRect (m_cxChar * 64, m_cyChar, m_cxChar * 80,
        m_cyChar * 9), this, UINT (-1));

    m_wndRadioButtonRed.Create (_T ("Red"), WS_CHILD | WS_VISIBLE |
	    WS_GROUP | BS_AUTORADIOBUTTON, CRect (m_cxChar * 66, m_cyChar * 3,
        m_cxChar * 78, m_cyChar * 4), this, IDC_RED);

    m_wndRadioButtonGreen.Create (_T ("Green"), WS_CHILD | WS_VISIBLE |
        BS_AUTORADIOBUTTON, CRect (m_cxChar * 66, (m_cyChar * 9) / 2,
        m_cxChar * 78, (m_cyChar * 11) / 2), this, IDC_GREEN);

    m_wndRadioButtonBlue.Create (_T ("Blue"), WS_CHILD | WS_VISIBLE |
        BS_AUTORADIOBUTTON, CRect (m_cxChar * 66, m_cyChar * 6,
        m_cxChar * 78, m_cyChar * 7), this, IDC_BLUE);

    Search.Create(_T("查询"), WS_CHILD | WS_VISIBLE |
        BS_PUSHBUTTON, CRect(m_cxChar * 90, m_cyChar * 12,
            m_cxChar * 100, m_cyChar * 14), this, IDC_SEARCH);

    search.Create(_T("员工状态"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 100,
            m_cyChar * 15, m_cxChar * 140, m_cyChar * 17), this);

    SearchID.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 90,
            m_cyChar * 15, m_cxChar * 100, m_cyChar * 17), this, UINT(-1));

    m_wndRadioButtonRed.SetCheck (1);

    search.SetTextColor(RGB(0, 0, 255));
    search.SetFont(&m_font, FALSE);
    time1.SetTextColor(RGB(255, 0, 0));
    time1.SetFont(&m_font, FALSE);
    time2.SetTextColor(RGB(255, 0, 0));
    time2.SetFont(&m_font, FALSE);
    setsituation.SetTextColor(RGB(255, 0, 0));
    setsituation.SetFont(&m_font, FALSE);
    saleamontt.SetTextColor(RGB(255, 0, 0));
    saleamontt.SetFont(&m_font, FALSE);
    salenumt.SetTextColor(RGB(255, 0, 0));
    salenumt.SetFont(&m_font, FALSE);
    bonusamontt.SetTextColor(RGB(255, 0, 0));
    bonusamontt.SetFont(&m_font, FALSE);
    bonusnumt.SetTextColor(RGB(255, 0, 0));
    bonusnumt.SetFont(&m_font, FALSE);
    m_wndText.SetTextColor (RGB (255, 0, 0));
    m_wndText.SetFont(&m_font, FALSE);
    dele.SetTextColor(RGB(255, 0, 0));
    dele.SetFont(&m_font, FALSE);
    addn1.SetTextColor(RGB(255, 0, 0));
    addn1.SetFont(&m_font, FALSE);
    addn2.SetTextColor(RGB(255, 0, 0));
    addn2.SetFont(&m_font, FALSE);
    edit.SetTextColor(RGB(255, 0, 0));
    edit.SetFont(&m_font, FALSE);

    m_wndGroupBox1.SetFont (&m_font, FALSE);
    Search.SetFont(&m_font, FALSE);
    m_wndGroupBox2.SetFont (&m_font, FALSE);
    Deletemember.SetFont(&m_font, FALSE);
    Addmember.SetFont(&m_font, FALSE);
    SetBonus.SetFont(&m_font, FALSE);
    SetTime.SetFont(&m_font, FALSE);
    SetExtract.SetFont(&m_font, FALSE);
    LOGER.SetFont(&m_font, FALSE);
    m_wndGroupBox3.SetFont(&m_font, FALSE);
    m_wndGroupBox4.SetFont(&m_font, FALSE);
    m_wndRadioButtonRed.SetFont (&m_font, FALSE);
    m_wndRadioButtonGreen.SetFont (&m_font, FALSE);
    m_wndRadioButtonBlue.SetFont (&m_font, FALSE);
    return 0;
}

void CMainWindow::OnRedButtonClicked ()
{
    m_wndText.SetTextColor (RGB (255, 0, 0));
}

void CMainWindow::OnGreenButtonClicked ()
{
    m_wndText.SetTextColor (RGB (0, 255, 0));
}

void CMainWindow::OnBlueButtonClicked ()
{
    m_wndText.SetTextColor (RGB (0, 0, 255));
}

/////////////////////////////////////////////////////////////////////////
// CColorStatic message map and member functions

BEGIN_MESSAGE_MAP (CColorStatic, CStatic)
    ON_WM_CTLCOLOR_REFLECT ()
END_MESSAGE_MAP ()

CColorStatic::CColorStatic ()
{
    m_clrText = RGB (0, 0, 0);
    m_clrBack = ::GetSysColor (COLOR_3DFACE);
    m_brBkgnd.CreateSolidBrush (m_clrBack);
}

void CColorStatic::SetTextColor (COLORREF clrText)
{
    m_clrText = clrText;
    Invalidate ();
}

void CColorStatic::SetBkColor (COLORREF clrBack)
{
    m_clrBack = clrBack;
    m_brBkgnd.DeleteObject ();
    m_brBkgnd.CreateSolidBrush (clrBack);
    Invalidate ();
}

HBRUSH CColorStatic::CtlColor (CDC* pDC, UINT nCtlColor)
{
    pDC->SetTextColor (m_clrText);
    pDC->SetBkColor (m_clrBack);
    return (HBRUSH) m_brBkgnd;
}

void CMainWindow::remove()
{
    int id;
    CString nu;
    dele.GetWindowTextA(nu);
    id = atoi(nu);
    nu=D
    id=D.Deletmember_bynum(id);
    if (id == -1);
}

void CMainWindow::addnew()
{

}

void CMainWindow::SETBonus()
{

}

void CMainWindow::SetSale()
{

}

void CMainWindow::LOGGIN()
{

}

void CMainWindow::Searching()
{

}

void CMainWindow::SETTime()
{

}

