#include "stdafx.h"
#include "Color.h"

COLORREF CColor::m_CustColors[16];

void CColor::Init(COLORREF color)
{
	CHOOSECOLOR& cc = m_cc;
	cc.lStructSize = sizeof(CHOOSECOLOR);
	cc.rgbResult = color;
	cc.Flags = CC_RGBINIT;
}

BOOL CColor::DoModal(HWND hWnd)
{
	m_cc.hwndOwner = hWnd;
	return ChooseColor(&m_cc);
}
