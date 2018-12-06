#ifndef LEVEL1_H
#define	LEVEL1_H
#include "../Tiles/tiles.h"
#include "../Utility/const_data.h"
#include "SFML/Graphics.hpp"
#include "STP/TMXLoader.hpp"

namespace platform {

	class LEVELONE{
	public:
		Tiles * tiles[MAXTILES];
		LEVELONE();
		~LEVELONE();
		void initLevel();
		void drawLevel();
	};

}

#endif // !LEVEL1_H
