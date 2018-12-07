#include "gravity.h"
#include <iostream>

namespace platform {

	Gravity::Gravity() {
		_intensity = 0.5f;
		_strong = 0;
		_time = 0.0f;
		_state = true;
	}

	Gravity::~Gravity() {
	}
	void Gravity::state(float deltaTime) {
		_state = true;
			
			_time += deltaTime;
			if (_time>1) {
				_time = 0;
				_strong =_intensity;
			}
		
	}
	void Gravity::setStrong(float strong) {
		_strong = strong;
	
	}
	void Gravity::reset() {
		_strong = 2.98f;
	}

}