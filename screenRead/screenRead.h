#pragma once
#include <vector>
#include <Windows.h>

namespace selectScrn {
	struct point {
		unsigned int x;
		unsigned int y;

		point(unsigned int x, unsigned int y);
	};


	class polygon {
	public:
		size_t len;
		polygon(std::vector<point>* pnts);

		//~polygon();

		//polygons shouldn't change thus there is no set method
		std::vector<point> getPoints();

		size_t size();

		unsigned int getLeftmostX();

		unsigned int getRightmostX();

		unsigned int getUpmostY();

		unsigned int getDownmostY();
	private:
		//polygon calculations assume the vector is sorted by adjacent verticies
		std::vector<point>* pnts = nullptr;
	};

	class selection {
	public:
		point topLeft;
		point bottomRight;

		selection(point topLeft, point bottomRight);

		selection(polygon* poly);

		//~selection();
	private:
		polygon* poly = nullptr;
	};

	HBITMAP getScreenbitmap();

	HBITMAP getSelectionbitmap(selection sel);
}