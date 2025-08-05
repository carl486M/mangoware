#include <mango/engine.hpp>
#include <mango/sprite.hpp>
#include <mango/scancode.hpp>

int main(int argc, char **argv){
	mango engine = mango::instance("What", 640, 480, 0);
	sprite mario("./assets/mario.bmp", 16, 32);
	bool running = true;
	mario.setPosition(vec2(0, 0));
	engine.setColor(25, 255, 255, 255);

	while (engine.event.running) {
		engine.update();

		if (engine.event.keyDown(MANGO_SCANCODE_RIGHT)) {
			mario.x += 1;
		}

		mario.render(vec2(mario.x, mario.y), mario.angle, mario.size);

		engine.render();
	}

	return 0;
}