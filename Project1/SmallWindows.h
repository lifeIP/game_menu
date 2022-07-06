#pragma once

class SmallWindows : public sf::Drawable
{
public:

	void set_color_head(const sf::Color* color) {
		color_head = *color;
	}
	void set_color_body(const sf::Color* color) {
		color_body = *color;
	}
	void set_color_text(const sf::Color* color) {
		color_text = *color;
	}
	void set_screen_size(const sf::Vector2u* screen_size) {
		this->screen_size = *screen_size;
	}
	void set_screen_pos(const sf::Vector2f* screen_pos) {
		this->screen_pos = *screen_pos;
	}
	void set_text(const std::string& text, unsigned short row) {
		this->text[row-1].setString(text);
	}
	void set_font(const std::string& font_name) {
		font.loadFromFile(font_name);
	}
	SmallWindows(sf::RenderWindow* window) {
		this->window = &window;
		number_of_rows = 5;
		text = new sf::Text[number_of_rows];
		set_color_head(&sf::Color::Black);
		set_screen_pos(&sf::Vector2f(50, 50));
		set_screen_size(&sf::Vector2u(50, 50));
		head();
	}
	~SmallWindows() {

		delete[]text;
	}
	void head() {
		obj_head.resize(4);
		obj_head.setPrimitiveType(sf::Quads);
		obj_head[0] = sf::Vertex(screen_pos, color_head);
		obj_head[1] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y), color_head);
		obj_head[2] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y + screen_size.y), color_head);
		obj_head[3] = sf::Vertex(sf::Vector2f(screen_pos.x, screen_pos.y + screen_size.y), color_head);
	}
	void body() {}
	void text_in_screen(const unsigned short row) {}


private:
	sf::RenderWindow** window;
	sf::Vector2u screen_size;
	sf::Vector2f screen_pos;
	unsigned short number_of_rows;
	sf::Text* text;
	sf::Font font;
	sf::Texture texture;
	sf::VertexArray obj_head;
	sf::VertexArray obj_body;
	sf::Color color_head;
	sf::Color color_body;
	sf::Color color_text;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.texture = &texture;
		target.draw(obj_head, states);
	}
};