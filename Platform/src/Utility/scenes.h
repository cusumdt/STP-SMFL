#ifndef SCENES_H
#define SCENES_H

namespace platform {

	class Scene {
	public:
		Scene();
		~Scene();
		virtual void init() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void deInit() = 0;
		virtual void showGUI() = 0;
		virtual void hideGUI() = 0;
	};
}
#endif // !SCENES_H
