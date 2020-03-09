#include "screenRead.h"
#include "windows.h"
#include <atlimage.h>


int main() {
	
	selectScrn::point topLeft(100,100);
	selectScrn::point bottomRight(1050,1050);
	selectScrn::selection select(topLeft,bottomRight);
	HBITMAP bmp = selectScrn::getSelectionbitmap(select);
	CImage image;
	image.Attach(bmp);
	image.Save(_T("filename.jpg"));
	
	return 0;
}