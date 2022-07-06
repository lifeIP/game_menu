#pragma once
class Button: public sf::Drawable
{
	sf::Vector2i mouse_pos;
	sf::Vector2u offset;//done
	sf::Vector2f button_pos;//done
	sf::Vector2u button_size;//done
	std::vector<unsigned int>rgba;//done
	std::vector<unsigned int>rgba_text;//done
	flags* f_load;
	int button_number;//done
	bool a1;
	unsigned short font_size;
public:
	void set_font_size(const unsigned short& font_size) {
		this->font_size = font_size;
	}
	void set_offset_text(sf::Vector2u& offset) {
		this->offset = offset;
	}
	void set_color(const unsigned int& r, const unsigned int& g, const unsigned int& b, const unsigned int& a) {
		rgba[0] = r;
		rgba[1] = g;
		rgba[2] = b;
		rgba[3] = a;
		config_button_pos_size_texture_config();
	}
	void set_color_text(const unsigned int& r, const unsigned int& g, const unsigned int& b, const unsigned int& a) {
		rgba_text[0] = r;
		rgba_text[1] = g;
		rgba_text[2] = b;
		rgba_text[3] = a;
		config_button_text();
	}
	void set_font(const std::string& font_name) {
		font.loadFromFile(font_name);
		config_button_text();
	}
	void set_text(const std::string& text) {
		this->text.setString(text);
		config_button_text();
	}
	void set_button_pos(sf::Vector2f* button_pos) {
		this->button_pos = *button_pos;
		config_button_pos_size_texture_config();
	}
	sf::Vector2f get_button_pos() const{
		return button_pos;
	}
	void set_button_size(sf::Vector2u* button_size) {
		this->button_size = *button_size;
		config_button_pos_size_texture_config();
	}
	sf::Vector2u get_button_size() const {
		return button_size;
	}
	Button(sf::RenderWindow* window, flags* f_load, int button_number) {
		this->window = window;
		button_pos = sf::Vector2f(window->getSize().x/2, window->getSize().y / 2);
		button_size = sf::Vector2u(400, 65);
		this->button_number = button_number;
		rgba = { 0,0,100,80 };
		rgba_text = { 0,0,0,255 };
		this->f_load = f_load;
		font.loadFromFile("001.ttf");
		text.setFont(font);
		font_size = 24;
		text.setCharacterSize(font_size);
		text.setFillColor(sf::Color::Yellow);
		text.setPosition(sf::Vector2f(button_pos.x + 5, button_pos.y + 5));
		offset = sf::Vector2u(5,5);
		config_button_pos_size_texture_config();
	}
	~Button() {
		std::cout << "destructor called" << std::endl;
	}

	void button_monitoring() {
		mouse_pos = sf::Mouse::getPosition();
		if (mouse_pos.x > button_pos.x && mouse_pos.x < button_pos.x + button_size.x && mouse_pos.y > button_pos.y && mouse_pos.y < button_pos.y + button_size.y) {
			rgba = { 100,0, 0, 80 };
			a1 = true;
			config_button_pos_size_texture_config();
			f_load->b[button_number].b0 = true;
		}
		else {
			if (a1) {
				rgba = { 0,0,100,80 };
				config_button_pos_size_texture_config();
				f_load->b[button_number].b0 = false;
				a1 = false;
			}
		}
	}
	
private:
	sf::RenderWindow* window;
	sf::Text text;
	sf::Font font;
	sf::Texture texture;
	sf::VertexArray obj;
	void config_button_pos_size_texture_config() {
		sf::Vector2u size = window->getSize();
		obj.resize(4);
		obj.setPrimitiveType(sf::Quads);
		obj[0] = sf::Vertex(sf::Vector2f(button_pos.x, button_pos.y), sf::Color::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
		obj[1] = sf::Vertex(sf::Vector2f(button_pos.x + button_size.x, button_pos.y), sf::Color::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
		obj[2] = sf::Vertex(sf::Vector2f(button_pos.x + button_size.x, button_pos.y + button_size.y), sf::Color::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
		obj[3] = sf::Vertex(sf::Vector2f(button_pos.x, button_pos.y + button_size.y), sf::Color::Color(rgba[0], rgba[1], rgba[2], rgba[3]));
	}
	void config_button_text()
	{
		text.setFont(font);
		text.setCharacterSize(font_size);
		text.setFillColor(sf::Color::Color(rgba_text[1], rgba_text[2], rgba_text[2], rgba_text[3]));
		text.setPosition(sf::Vector2f(button_pos.x + offset.x, button_pos.y + offset.y));
	}
	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.texture = &texture;
		target.draw(obj, states);
		target.draw(text);
	}
};

