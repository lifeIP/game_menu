#include <iostream>
#include "lib.h"
#include "obj.h"

void home_screen(sf::RenderWindow* window, HomeScreen* home, flags* f_load);
void screen_start_game(sf::RenderWindow* window, SmallWindows* smal_w);
void buttons(sf::RenderWindow* window, Button* button, sf::Vector2f* button_pos, sf::Vector2u* button_size, const std::string& text);
int main() {
	flags f_load; /*loading flag*/
	f_load.ui[0] = 0;
	f_load.ui[1] = 0;
	sf::Uint32 style = sf::Style::Fullscreen;
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "", style);
	bool del = false;
	//warehouse of objects+
	HomeScreen home(&window);
	SmallWindows s_window(&window);
	Button start_game(&window, &f_load, 0);
	Button settings(&window, &f_load, 1);
	Button shop(&window, &f_load, 2);
	Button exit(&window, &f_load, 3);
	
	//warehouse of objects-
	while (window.isOpen()) {
		sf::Event some_event;
		while (window.pollEvent(some_event)) {
			if (some_event.type == sf::Event::EventType::KeyPressed) {
				switch (some_event.key.code)
				{
				case sf::Keyboard::E:
					//inventory
					f_load.b[3].b7 = false;
					break;

				case sf::Keyboard::Escape:
					window.close();
					break;
				}
			}
			else if (some_event.type == sf::Event::EventType::MouseButtonReleased) {
				switch (some_event.mouseButton.button)
				{
				case sf::Mouse::Left:
					if (f_load.b[0].b0) {
						std::cout << 0;
					}
					if (f_load.b[1].b0) {
						std::cout << 1;
					}
					if (f_load.b[2].b0) {
						std::cout << 2;
					}
					if (f_load.b[3].b0) {
						std::cout << 3;
					}
					if (f_load.b[4].b0) {
						std::cout << 4;
					}
					if (f_load.b[5].b0) {
						std::cout << 5;
					}
					if (f_load.b[6].b0) {
						std::cout << 6;
					}
					if (f_load.b[7].b0) {
						std::cout << 7;
					}
					break;
				}
			}
		}
		window.clear(sf::Color::Black);
		//Place for the rendering function+
		home_screen(&window, &home, &f_load);
		
		buttons(&window, &start_game, &sf::Vector2f(60, 60), &sf::Vector2u(400, 65), "start game");
		buttons(&window, &settings, &sf::Vector2f(60, 130), &sf::Vector2u(400, 65), "settings");
		
		buttons(&window, &shop, &sf::Vector2f(60, 200), &sf::Vector2u(400, 65), "shop");
		buttons(&window, &exit, &sf::Vector2f(60, 270), &sf::Vector2u(400, 65), "exit");
		screen_start_game(&window, &s_window);
		//Place for the rendering function-
		window.display();
	}
}
void screen_start_game(sf::RenderWindow* window, SmallWindows* smal_w) {
	smal_w->set_color_head(&sf::Color::Color(79, 79, 79, 255));
	smal_w->set_screen_pos(&sf::Vector2f(500, 60));
	smal_w->set_screen_size(&sf::Vector2u(500, 500));
	smal_w->head();
	window->draw(*smal_w);
}
void buttons(sf::RenderWindow* window, Button* button, sf::Vector2f* button_pos, sf::Vector2u* button_size, const std::string& text) {
	button->set_button_pos(button_pos);
	button->set_button_size(button_size);
	button->set_text(text);
	button->set_color_text(244, 219, 22, 255);
	button->set_font_size(30);
	button->button_monitoring();
	window->draw(*button);
}
void home_screen(sf::RenderWindow *window, HomeScreen *home, flags* f_load) {
	window->draw(*home);
}