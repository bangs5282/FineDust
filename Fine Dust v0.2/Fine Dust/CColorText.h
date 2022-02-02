#pragma once
#include <afxwin.h>
class CColorText :
	public CStatic
{

public:
	CColorText();
	~CColorText();

public:
	// make the background transparent (or if ATransparent == true, restore the previous background color)
	void setTransparent(bool ATransparent = true);
	// set background color and make the background opaque
	void SetBackgroundColor(COLORREF);
	void SetTextColor(COLORREF);

protected:
	HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);

private:
	bool MTransparent = true;
	COLORREF MBackgroundColor = RGB(255, 255, 255);  // default is white (in case someone sets opaque without setting a color)
	COLORREF MTextColor = RGB(0, 0, 0);  // default is black. it would be more clean 
										   // to not use the color before set with SetTextColor(..), but whatever...
protected:
	DECLARE_MESSAGE_MAP()
};
