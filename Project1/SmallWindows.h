#pragma once


struct flag_render {
	bool b0 : 1;
	bool b1 : 1; 
	bool b2 : 1;
	bool b3 : 1;
	bool b4 : 1;
	bool b5 : 1;
	bool b6 : 1;
	bool b7 : 1;
};
union render_flag {
	flag_render b;
	unsigned char c;
};
class SmallWindows : public sf::Drawable
{
	void head() {
		obj_head[0] = sf::Vertex(screen_pos, color_head);
		obj_head[1] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y), color_head);
		obj_head[2] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y + 45), color_head);
		obj_head[3] = sf::Vertex(sf::Vector2f(screen_pos.x, screen_pos.y + 45), color_head);
	}
	void txt() {
		text_head.setFillColor(color_text);
		text_head.setCharacterSize(font_size);
		text_head.setFont(font);
		text_head.setPosition(screen_pos.x + 10, screen_pos.y + 5);
	}
	void body() {
		sf::Vector2u tex_size = texture.getSize();
		obj_body[0] = sf::Vertex(sf::Vector2f(screen_pos.x, screen_pos.y + 45), sf::Vector2f(0, 0));
		obj_body[1] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y + 45), sf::Vector2f(tex_size.x, 0));
		obj_body[2] = sf::Vertex(sf::Vector2f(screen_pos.x + screen_size.x, screen_pos.y + screen_size.y - 45), sf::Vector2f(tex_size.x, tex_size.y));
		obj_body[3] = sf::Vertex(sf::Vector2f(screen_pos.x, screen_pos.y + screen_size.y - 45), sf::Vector2f(0, tex_size.y));
	}
	void load_default_data() {
		set_color_head(&sf::Color::Black);
		set_screen_pos(&sf::Vector2f(50, 50));
		set_screen_size(&sf::Vector2u(50, 50));
		font.loadFromFile("001.ttf");
		set_color_text(&sf::Color::Red);
		font_size = 24;
		texture.loadFromFile("wall.jpg");
		obj_head.resize(4);
		obj_head.setPrimitiveType(sf::Quads);
		obj_body.resize(4);
		obj_body.setPrimitiveType(sf::Quads);
	}
public:

	void set_color_head(const sf::Color* color) {
		color_head = *color;
		flag.b.b1 = true;
	}
	const sf::Color* get_color_head() {
		return &color_head;
	}
	void set_color_text(const sf::Color* color) {
		color_text = *color;
		flag.b.b0 = true;
	}
	const sf::Color* get_color_text() {
		return &color_text;
	}
	void set_screen_size(const sf::Vector2u* screen_size) {
		this->screen_size = *screen_size;
		flag.b.b1 = true;
		flag.b.b3 = true;
	}
	const sf::Vector2u* get_screen_size() {
		return &screen_size;
	}
	void set_screen_pos(const sf::Vector2f* screen_pos) {
		this->screen_pos = *screen_pos;
		flag.b.b1 = true;
		flag.b.b3 = true;
	}
	const sf::Vector2f* get_screen_pos() {
		return &screen_pos;
	}
	void set_text_head(const std::string& text) {
		text_head.setString(text);
		flag.b.b0 = true;
	}
	const sf::Text* set_text_head() {
		return &text_head;
	}
	void set_font(const std::string& font_name) {
		font.loadFromFile(font_name);
		flag.b.b0 = true;
	}
	void set_font_size(const unsigned short& font_size) {
		this->font_size = font_size;
		flag.b.b0 = true;
	}
	const unsigned short* get_font_size() {
		return &font_size;
	}
	void set_texture_body(const std::string& file) {
		texture.loadFromFile(file);
		flag.b.b3 = true;
	}
	SmallWindows() {
		flag.c = 0;
		load_default_data();
	}
	void processing_cycle() {
		if (flag.b.b1) {
			head();
			flag.b.b1 = false;
		}
		if (flag.b.b3) {
			body();
		}
		if (flag.b.b0) {
			txt();
		}
	}
	~SmallWindows() {
	}

private:
	render_flag flag;
	sf::Vector2u screen_size;
	sf::Vector2f screen_pos;
	sf::Text text_head;
	sf::Font font;
	sf::Texture texture;
	sf::VertexArray obj_head;
	sf::VertexArray obj_body;
	sf::Color color_head;
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