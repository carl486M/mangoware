#include <iostream>
#define SDL_MAIN_HANDLED
#include <mango/engine.hpp>
#include <mango/sprite.hpp>
#include <mango/scancode.hpp>


int main(int argc, char* argv[]) {
	mango engine = mango::instance("What", 854, 480, 0);
	sprite mario("./assets/mario.bmp", 16, 32);
	sprite luigi("./assets/mario.bmp", 16, 32);
	bool running = true;

	mario.setPosition(vec2(0, 0));
	luigi.setPosition(vec2(200, 200));
	engine.setColor(255, 255, 255, 255);
	mario.angle = 0;
	mario.size = 2;
	luigi.size = 2;
	luigi.setColor(0, 255, 0, 255);
	while (engine.event.running) {
		engine.update();

		if (engine.event.keyDown(MANGO_SCANCODE_RIGHT)) {
			mario.flip = true;
			mario.x += 1;
		} if (engine.event.keyDown(MANGO_SCANCODE_LEFT)) {
			mario.flip = false;
			mario.x -= 1;
		} if (engine.event.keyDown(MANGO_SCANCODE_UP)) {
			mario.y -= 1;
		} if (engine.event.keyDown(MANGO_SCANCODE_DOWN)) {
			mario.y += 1;
		} if (mario.collided(&luigi)) {
			std::cout << "HEY" << std::endl;
		}

		luigi.render();
		mario.render(vec2(mario.x, mario.y), mario.angle, mario.size);

		engine.render();
	}

	return 0;
}