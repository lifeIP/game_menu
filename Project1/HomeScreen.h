#pragma once
class HomeScreen: public sf::Drawable
{
public:
	HomeScreen(sf::RenderWindow* window);
	~HomeScreen();
	void coords();
private:
	sf::Vector2u size;
	sf::Texture texture;
	sf::VertexArray vertex;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

inline void HomeScreen::coords()
{
	texture.loadFromFile("wall.jpg");
	sf::Vector2u tex_size = texture.getSize();
	vertex.setPrimitiveType(sf::Quads);
	vertex.resize(4);
	vertex[0] = sf::Vertex(sf::Vector2f(0,0), sf::Vector2f(0,0));
	vertex[1] = sf::Vertex(sf::Vector2f(size.x, 0), sf::Vector2f(tex_size.x, 0));
	vertex[2] = sf::Vertex(sf::Vector2f(size.x, size.y), sf::Vector2f(tex_size.x, tex_size.y));
	vertex[3] = sf::Vertex(sf::Vector2f(0, size.y), sf::Vector2f(0, tex_size.y));
}
inline HomeScreen::HomeScreen(sf::RenderWindow* window)
{
	size = window->getSize();
	coords();
}
HomeScreen::~HomeScreen()
{
}

inline void HomeScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = &texture;
	target.draw(vertex, states);
}
