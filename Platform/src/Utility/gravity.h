#ifndef GRAVITY_H
#define GRAVITY_H
#include "Player/player.h"
namespace platform {

	class Gravity {
	private:
		float _intensity;
		float _strong;
		float _time;
		bool _state;
	public:
		Gravity();
		~Gravity();
		void state(float deltaTime);
		void setStrong(float strong);
		float getStrong() { return _strong; }
		void reset();
	};

}
#endif // !GRAVITY_H
