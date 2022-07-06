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
	void set_text_head(const std::string& text) {
		this->text_head.setString(text);
	}
	void set_font(const std::string& font_name) {
		font.loadFromFile(font_name);
	}
	void set_font_size(const unsigned short& font_size) {
		this->font_size = font_size;
	}
	SmallWindows(sf::RenderWindow* window) {
		this->window = window;
		set_color_head(&sf::Color::Black);
		set_screen_pos(&sf::Vector2f(50, 50));
		set_screen_size(&sf::Vector2u(50, 50));
		font.loadFromFile("001.ttf");
		set_color_text(&sf::Color::Red);
		font_size = 24;
		
	}
	~SmallWindows() {
	}
	void head() {
		obj_head.resize(4);
		obj_head.setPrimitiveType(sf::Quads);
		obj_head[0] = sf::Vertex(screen_pos, color_head);
		obj_head[1] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y), color_head);
		obj_head[2] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y + 45), color_head);
		obj_head[3] = sf::Vertex(sf::Vector2f(screen_pos.x, screen_pos.y + 45), color_head);
		text_head.setFillColor(color_text);
		text_head.setCharacterSize(font_size);
		text_head.setFont(font);
		text_head.setPosition(screen_pos.x + 10, screen_pos.y + 5);
	}
	void body() {
		obj_body.resize(4);
		obj_body.setPrimitiveType(sf::Quads);
		obj_body[0] = sf::Vertex(sf::Vector2f(screen_pos.x, screen_pos.y + 45), color_head);
		obj_body[1] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y + 45), color_head);
		obj_body[2] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y + screen_size.y - 45), color_head);
		obj_body[3] = sf::Vertex(sf::Vector2f(screen_pos.x, screen_pos.y + screen_size.y - 45), color_head);
	}
	void text_in_screen(const unsigned short row) {}


private:
	sf::RenderWindow* window;
	sf::Vector2u screen_size;
	sf::Vector2f screen_pos;
	sf::Text text_head;
	sf::Font font;
	sf::Texture texture;
	sf::VertexArray obj_head;
	sf::VertexArray obj_body;
	sf::Color color_head;
	sf::Color color_body;
	sf::Color color_text;
	unsigned short font_size;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.texture = &texture;
		target.draw(obj_body, states);
		target.draw(obj_head);
		target.draw(text_head);
	}
};