#include "stdafx.h"
#include "CColorText.h"


CColorText::CColorText()
{
}


CColorText::~CColorText()
{
}


void CColorText::setTransparent(bool ATransparent)
{
	MTransparent = ATransparent;
	Invalidate();
}

void CColorText::SetBackgroundColor(COLORREF AColor)
{
	MBackgroundColor = AColor;
	MTransparent = false;
	Invalidate();
}

void CColorText::SetTextColor(COLORREF AColor)
{
	MTextColor = AColor;
	Invalidate();
}

BEGIN_MESSAGE_MAP(CColorText, CStatic)
	ON_WM_CTLCOLOR_REFLECT()
END_MESSAGE_MAP()

HBRUSH CColorText::CtlColor(CDC* pDC, UINT nCtlColor)
{
	pDC->SetTextColor(MTextColor);
	pDC->SetBkMode(TRANSPARENT);  // we do not want to draw background when drawing text. 
									// background color comes from drawing the control background.
	if (MTransparent)
		return nullptr;  // return nullptr to indicate that the parent object 
						 // should supply the brush. it has the appropriate background color.
	else
		return (HBRUSH)CreateSolidBrush(MBackgroundColor);  // color for the empty area of the control
}