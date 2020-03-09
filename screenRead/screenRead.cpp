// screenRead.cpp : Defines the functions for the static library.
//

#include "screenRead.h"

#include <iostream>
namespace selectScrn {
	/*POINT*/
	//Defining Point Constructor
	point::point(unsigned int x = 0, unsigned int y = 0) {
		this->x = x;
		this->y = y;
	}
	/*END POINT*/

	/*POLYGON*/
	polygon::polygon(std::vector<point>* pnts) {
		this->pnts = pnts;
		len = pnts->size();
	}

	/*
	polygon::~polygon() {
		delete pnts;
		delete& len;
	}
	*/

	std::vector<point> polygon::getPoints() {
		return *pnts;
	}

	size_t polygon::size() {
		return pnts->size();
	}
		
	/*O(n) functions to get extremes of polygon*/
	unsigned int polygon::getLeftmostX() {
		unsigned int out = pnts->at(0).x;
		for (unsigned int i = 1; i < len; i++) {
			if (pnts->at(i).x < out) {
				out = pnts->at(i).x;
			}
		}
		return out;
	}

	unsigned int polygon::getRightmostX() {
		unsigned int out = pnts->at(0).x;
		for (unsigned int i = 1; i < len; i++) {
			if (pnts->at(i).x > out) {
				out = pnts->at(i).x;
			}
		}
		return out;
	}

	unsigned int polygon::getUpmostY() {
		unsigned int out = pnts->at(0).y;
		for (unsigned int i = 1; i < len; i++) {
			if (pnts->at(i).y < out) {
				out = pnts->at(i).y;
			}
		}
		return out;
	}

	unsigned int polygon::getDownmostY() {
		unsigned int out = pnts->at(0).y;
		for (unsigned int i = 1; i < len; i++) {
			if (pnts->at(i).y > out) {
					out = pnts->at(i).y;
			}
		}
		return out;
	}
	/*END POLYGON*/
	

	/*SELECTION*/
	selection::selection(point topLeft, point bottomRight) {
		this->topLeft = topLeft;
		this->bottomRight = bottomRight;
		std::vector<point> pnts;
		pnts.push_back(topLeft);
		pnts.push_back(bottomRight);
		poly = new polygon(&pnts);
	}

	selection::selection(polygon * poly) {
		this->poly = poly;
		this->topLeft = point(poly->getLeftmostX(),poly->getUpmostY());
		this->bottomRight = point(poly->getRightmostX(), poly->getDownmostY());
	}

	/*
	selection::~selection() {
		
		delete this->poly;
		
	}
	*/
	/*END SELECTION*/

	HBITMAP getScreenbitmap() {
		// get the device context of the screen
		HDC hScreenDC = CreateDC(L"DISPLAY", NULL, NULL, NULL);
		// and a device context to put it in
		HDC hMemoryDC = CreateCompatibleDC(hScreenDC);

		int width = GetDeviceCaps(hScreenDC, HORZRES);
		int height = GetDeviceCaps(hScreenDC, VERTRES);

		HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);

		// get a new bitmap
		HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemoryDC, hBitmap);

		BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, 0, 0, SRCCOPY);
		hBitmap = (HBITMAP)SelectObject(hMemoryDC, hOldBitmap);
		
		// clean up
		DeleteDC(hMemoryDC);
		DeleteDC(hScreenDC);
		return hBitmap;
	}

	//polygons are not used in the inital captures
	HBITMAP getSelectionbitmap(selection sel) {
		
		HDC hScreenDC = CreateDC(L"DISPLAY", NULL, NULL, NULL);
		HDC hMemoryDC = CreateCompatibleDC(hScreenDC);

		//get width and height of the selection
		int width = sel.bottomRight.x - sel.topLeft.x;
		int height = sel.bottomRight.y - sel.topLeft.y;

		HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);

		HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemoryDC, hBitmap);

		BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, sel.topLeft.x, sel.topLeft.y, SRCCOPY);
		hBitmap = (HBITMAP)SelectObject(hMemoryDC, hOldBitmap);

		DeleteDC(hMemoryDC);
		DeleteDC(hScreenDC);
		return hBitmap;
	}

}
