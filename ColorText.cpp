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
    ON_BN_CLICKED(IDC_UPG, UPG)
    ON_BN_CLICKED(IDC_SAVING, Save)
END_MESSAGE_MAP ()

CMainWindow::CMainWindow ()
{
    log = 0;
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

    m_wndGroupBox1.Create (_T ("��Ա����"), WS_CHILD | WS_VISIBLE |
        BS_GROUPBOX, CRect (m_cxChar * 2, m_cyChar, m_cxChar * 80,
        m_cyChar * 12), this, UINT (-1));

    Upgrade.Create(_T("��ְ"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 5, m_cyChar * 3,
            m_cxChar * 15, m_cyChar * 5), this, IDC_UPG);

    up.Create(_T("����"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 18,
            m_cyChar * 3, m_cxChar * 23, m_cyChar * 5), this);

    tos.Create(_T("��/��"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 39,
            m_cyChar * 3, m_cxChar * 46, m_cyChar * 5), this);

    UPid.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 25,
            m_cyChar * 3, m_cxChar * 39, m_cyChar * 5), this, UINT(-1));

    TorS.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 47,
            m_cyChar * 3, m_cxChar * 61, m_cyChar * 5), this, UINT(-1));

    Deletemember.Create(_T("����"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 5, m_cyChar * 6,
            m_cxChar * 15, m_cyChar * 8), this, IDC_DELETEMEBER);

    dele.Create(_T("����"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 18,
            m_cyChar * 6, m_cxChar * 23, m_cyChar * 8), this);

    deletenum.Create(ES_LEFT | WS_CHILD | WS_VISIBLE  |
        WS_GROUP, CRect(m_cxChar * 25,
            m_cyChar * 6, m_cxChar * 39, m_cyChar * 8), this, UINT(-1));

    Addmember.Create(_T("��Ƹ"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 5, m_cyChar * 9,
            m_cxChar * 15, m_cyChar * 11), this, IDC_ADDMEMBER);

    addn1.Create(_T("����"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 40,
            m_cyChar * 9, m_cxChar * 45, m_cyChar * 11), this);

    addname.Create(ES_LEFT | WS_CHILD | WS_VISIBLE  |
        WS_GROUP, CRect(m_cxChar * 47,
            m_cyChar * 9, m_cxChar * 61, m_cyChar * 11), this, UINT(-1));

    addn2.Create(_T("����"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 18,
            m_cyChar * 9, m_cxChar * 23, m_cyChar * 11), this);

    edit.Create(_T(""),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 40,
            m_cyChar * 6, m_cxChar * 60, m_cyChar * 8), this);

    addnum.Create(ES_LEFT | WS_CHILD | WS_VISIBLE  |
        WS_GROUP, CRect(m_cxChar * 25,
            m_cyChar * 9, m_cxChar * 39, m_cyChar * 11), this, UINT(-1));


    LOGER.Create(_T("��¼"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 90, m_cyChar * 4,
            m_cxChar * 100, m_cyChar * 6), this, IDC_LOGIN);

    m_wndGroupBox3.Create(_T("��¼"), WS_CHILD | WS_VISIBLE |
        BS_GROUPBOX, CRect(m_cxChar * 85, m_cyChar, m_cxChar * 115,
            m_cyChar * 9), this, UINT(-1));

    LOGpassword.Create(ES_LEFT | WS_CHILD | WS_VISIBLE | ES_PASSWORD |
        WS_GROUP, CRect(m_cxChar * 90,
            m_cyChar * 6.5, m_cxChar * 110, m_cyChar * 8.5), this, UINT(-1));



    m_wndGroupBox4.Create(_T("��Ϣ�Ǽ�"), WS_CHILD | WS_VISIBLE |
        BS_GROUPBOX, CRect(m_cxChar * 2, m_cyChar*13, m_cxChar * 80,
            m_cyChar * 25), this, UINT(-1));

    SetTime.Create(_T("�Ǽ�ʱ��"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 4, m_cyChar * 14.5,
            m_cxChar * 17, m_cyChar * 16.5), this, IDC_SETTIME);

    time1.Create(_T("��"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 20,
            m_cyChar * 14.5, m_cxChar * 25, m_cyChar * 16.5), this);

    time2.Create(_T("��"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 50,
            m_cyChar * 14.5, m_cxChar * 55, m_cyChar * 16.5), this);

    Year.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 27,
            m_cyChar * 14.5, m_cxChar * 48, m_cyChar * 16.5), this, UINT(-1));

    Month.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 58,
            m_cyChar * 14.5, m_cxChar * 78, m_cyChar * 16.5), this, UINT(-1));

    SetBonus.Create(_T("�Ǽ��۶�"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 4, m_cyChar * 17,
            m_cxChar * 17, m_cyChar * 19), this, IDC_SETEXTRACT);

    SaleId.Create(ES_LEFT | WS_CHILD | WS_VISIBLE  |
        WS_GROUP, CRect(m_cxChar * 27,
            m_cyChar * 17, m_cxChar * 48, m_cyChar * 19), this, UINT(-1));

    SaleAmount.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 58,
            m_cyChar * 17, m_cxChar * 78, m_cyChar * 19), this, UINT(-1));

    salenumt.Create(_T("����"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 20,
            m_cyChar * 17, m_cxChar * 25, m_cyChar * 19), this);

    saleamontt.Create(_T("���"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 50,
            m_cyChar * 17, m_cxChar * 55, m_cyChar * 19), this);

    SetExtract.Create(_T("�Ǽǽ���"), WS_CHILD | WS_VISIBLE |
        WS_GROUP | BS_PUSHBUTTON, CRect(m_cxChar * 4, m_cyChar * 20,
            m_cxChar * 17, m_cyChar * 22), this, IDC_SETBONUS);

    BonusId.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 27,
            m_cyChar * 20, m_cxChar * 48, m_cyChar * 22), this, UINT(-1));

    BonusAmount.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 58,
            m_cyChar * 20, m_cxChar * 78, m_cyChar * 22), this, UINT(-1));

    bonusnumt.Create(_T("����"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 20,
            m_cyChar * 20, m_cxChar * 25, m_cyChar * 22), this);

    bonusamontt.Create(_T("���"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 50,
            m_cyChar * 20, m_cxChar * 55, m_cyChar * 22), this);

    setsituation.Create(_T("�Ǽ�״̬: δ�Ǽ�"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 5,
            m_cyChar * 22.5, m_cxChar * 65, m_cyChar * 24.5), this);

    m_wndText.Create (_T ("���¼"),
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

    Search.Create(_T("��ѯ"), WS_CHILD | WS_VISIBLE |
        BS_PUSHBUTTON, CRect(m_cxChar * 90, m_cyChar * 12,
            m_cxChar * 100, m_cyChar * 14), this, IDC_SEARCH);

    Saving.Create(_T("����"), WS_CHILD | WS_VISIBLE |
        BS_PUSHBUTTON, CRect(m_cxChar * 90, m_cyChar * 18,
            m_cxChar * 100, m_cyChar * 20), this, IDC_SAVING);


    search.Create(_T("Ա��״̬"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 100,
            m_cyChar * 15, m_cxChar * 160, m_cyChar * 20), this);

    searchall.Create(_T("1"),
        WS_CHILD | WS_VISIBLE | SS_CENTER, CRect(m_cxChar * 100,
            m_cyChar * 20, m_cxChar * 200, m_cyChar * 80), this);

    SearchID.Create(ES_LEFT | WS_CHILD | WS_VISIBLE |
        WS_GROUP, CRect(m_cxChar * 90,
            m_cyChar * 15, m_cxChar * 100, m_cyChar * 17), this, UINT(-1));

    m_wndRadioButtonRed.SetCheck (1);

    search.SetTextColor(RGB(0, 0, 255));
    search.SetFont(&m_font, FALSE);
    up.SetTextColor(RGB(255, 0, 0));
    up.SetFont(&m_font, FALSE);
    tos.SetTextColor(RGB(255, 0, 0));
    tos.SetFont(&m_font, FALSE);
    searchall.SetTextColor(RGB(0, 0, 255));
    searchall.SetFont(&m_font, FALSE);
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
    Upgrade.SetFont(&m_font, FALSE);
    m_wndGroupBox2.SetFont (&m_font, FALSE);
    Deletemember.SetFont(&m_font, FALSE);
    Addmember.SetFont(&m_font, FALSE);
    SetBonus.SetFont(&m_font, FALSE);
    SetTime.SetFont(&m_font, FALSE);
    Saving.SetFont(&m_font, FALSE);
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
    deletenum.GetWindowTextA(nu);
    id = atoi(nu);
    nu = D.getname_bynum(id);
    if (nu == "���޴���")
    {
        edit.SetWindowTextA(nu);
        return;
    }
    id=D.Deletmember_bynum(id);
    nu.Format("%s�Ѿ�����", nu);
    edit.SetWindowTextA(nu);
    searchall.SetWindowTextA(D.getsituation_now());
}

void CMainWindow::addnew()
{
    int id;
    CString nu,name;
    addnum.GetWindowTextA(nu);
    id = atoi(nu);
    addname.GetWindowTextA(name);
    if (id == 0)
    {
        edit.SetWindowTextA("0�Ų�����");
        return;
    }
    if (D.getname_bynum(id) == "���޴���")
    {
        D.AddNewmember(id, "salesperson", name);
        nu.Format("��ӭ����%s", D.getname_bynum(id));
        edit.SetWindowTextA(nu);
        searchall.SetWindowTextA(D.getsituation_now());
    }
    else
    {
        edit.SetWindowTextA("����Ѵ���");
    }
}

void CMainWindow::SETBonus()
{
    int id;
    CString nu,sum;
    BonusId.GetWindowTextA(nu);
    BonusAmount.GetWindowTextA(sum);

    id = atoi(nu);
    if (D.Idexsist(id))
    {
        if (D.SetBonus(id, atof(sum)) == 1)
        {
            nu.Format("�Ǽ�״̬:%s������%f", D.getname_bynum(id), D.getbonus_byid(id));
            setsituation.SetWindowTextA(nu);
            searchall.SetWindowTextA(D.getsituation_now());
            return;
        }
        else
        {
            nu.Format("�Ǽ�״̬:����%s������", D.getname_bynum(id));
            setsituation.SetWindowTextA(nu);
            return;
        }
    }
    nu.Format("�Ǽ�״̬:ID%d������", id);
    setsituation.SetWindowTextA(nu);
    return;
}

void CMainWindow::SetSale()
{
    int id;
    CString nu, sum;
    SaleId.GetWindowTextA(nu);
    SaleAmount.GetWindowTextA(sum);

    id = atoi(nu);
    if (D.Idexsist(id))
    {
        if (D.SetEarn(id, atof(sum)) == 1)
        {
            
            nu.Format("�Ǽ�״̬:����%s���۶�%f", D.getname_bynum(id), D.getearnmoney_id(id));
            setsituation.SetWindowTextA(nu);
            D.setTotalmoney();
            D.Updatesalary();
            searchall.SetWindowTextA(D.getsituation_now());
            return;
        }
        else
        {
            nu.Format("�Ǽ�״̬:%s��������", D.getname_bynum(id));
            setsituation.SetWindowTextA(nu);
            return;
        }
    }
    nu.Format("�Ǽ�״̬:ID%d������", id);
    setsituation.SetWindowTextA(nu);
    return;
}

void CMainWindow::LOGGIN()
{
    CString s;
    char ch[64];
    time_t t = time(0);
    strftime(ch, sizeof(ch), "don-%H-%M", localtime(&t));
    LOGpassword.GetWindowTextA(s);
    if (s == ch)
    {
        log = 1;

        m_wndText.SetWindowTextA("��½�ɹ���������ȷ����ʽ�ٵ����");

    }
    else
    {
        m_wndText.SetWindowTextA("��������������");

    }
}

void CMainWindow::Searching()
{
    int id;
    CString nu;
    SearchID.GetWindowTextA(nu);
    id = atoi(nu);
    nu = D.getsituation_now();
    searchall.SetWindowTextA(nu);
    if (D.Idexsist(id))
    {

        nu = D.getsituation_now_num(id);
        search.SetWindowTextA(nu);
    }
    else
        search.SetWindowTextA("���޴���");
}

void CMainWindow::SETTime()
{
    int year, month;
    CString y, m;
    Year.GetWindowTextA(y);
    Month.GetWindowTextA(m);
    year = atoi(y);
    month = atoi(m);
    if (month > 12 || month <=0)
    {
        y.Format("�Ǽ�״̬��%d�������ţ��", month);
        setsituation.SetWindowTextA(y);
        return;
    }
    D.year = year;
    D.month = month;
    y.Format("�Ǽ�״̬���趨ʱ��%d��%d��", year,month);
    setsituation.SetWindowTextA(y);
    return;
}

void CMainWindow::UPG()
{
    int id;
    CString nu;
    UPid.GetWindowTextA(nu);
    id = atoi(nu);
    TorS.GetWindowTextA(nu);
    
    if (D.Idexsist(id)&&((nu=="��")||(nu="��")))
    {
        if((nu == "��"))
        D.Upgrade_bynum(id,1);
        else D.Upgrade_bynum(id, 0);
        nu.Format("��ϲ%s%s", D.get_statename(id), D.getname_bynum(id));
        edit.SetWindowTextA(nu);
    }
    else
    {
        edit.SetWindowTextA("���޴���");
    }
    
}

void CMainWindow::Save()
{
    D.Savedata();
}
