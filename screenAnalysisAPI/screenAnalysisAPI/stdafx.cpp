#include "stdafx.h"


namespace scrnSelect {

	struct point {
		unsigned int x;
		unsigned int y;

		point(unsigned int x = 0, unsigned int y = 0) {
			this->x = x;
			this->y = y;
		}
	};

	class polygon {
	public:
		size_t len;
		polygon(std::vector<point> * pnts) {
			this->pnts = pnts;
			len = pnts->size();
		}

		~polygon() {
			delete pnts;
			delete &len;
		}

		//polygons shouldn't change thus there is no set method
		std::vector<point> getPoints() {
			return *pnts;
		}

		
	private:
		//polygon calculations assume the vector is sorted by adjacent verticies
		std::vector<point> *pnts;
		unsigned int getLeftmostX() {
			unsigned int out = pnts->at(0).x;
			for (unsigned int i = 1; i < len; i++) {
				//@TODO
			}
		}

		unsigned int getRightmostX() {
			unsigned int out = pnts->at(0).x;
			for (unsigned int i = 1; i < len; i++) {
				//@TODO
			}
		}

		unsigned int getHighestY() {
			unsigned int out = pnts->at(0).y;
			for (unsigned int i = 1; i < len; i++) {
				//@TODO
			}
		}

		unsigned int getLowestY() {
			unsigned int out = pnts->at(0).y;
			for (unsigned int i = 1; i < len; i++) {
				//@TODO
			}
		}


	};



}
