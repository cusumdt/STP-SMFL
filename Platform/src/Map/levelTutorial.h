#ifndef LEVEL1_H
#define	LEVEL1_H
#include "../Tiles/tiles.h"
#include "../Utility/const_data.h"
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

namespace platform {

	class LEVELONE{
	private:

		Tiles * tiles[MAXTILES];
	public:
		LEVELONE();
		~LEVELONE();
		void initLevel();
		void drawLevel();
	};

}

#endif // !LEVEL1_H
