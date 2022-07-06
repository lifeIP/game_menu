/*#pragma once
class LandscapeGenerator : public sf::Drawable, private sf::Transformable
{
private:

public:
	bool load_map(const std::string tileset, sf::Vector2u tilesize, const int* tiles, sf::Vector2u visible_size) {
		if (!m_tileset.loadFromFile(tileset)) {
			return false;
		}
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(visible_size.x * visible_size.y * 4);
		for (unsigned int i = 0; i < visible_size.x; ++i) {
			for (unsigned int j = 0; j < visible_size.y; ++j) {
				int tileNumber = tiles[j * visible_size.x + i];
				int tu = tileNumber % (m_tileset.getSize().x / tilesize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tilesize.x);

				sf::Vertex* quad = &m_vertices[(i + j * tilesize.x) * 4];

				quad[0].position = sf::Vector2f(i * tilesize.x, j * tilesize.y);
				quad[1].position = sf::Vector2f((i + 1) * tilesize.x, j * tilesize.y);
				quad[2].position = sf::Vector2f((i + 1) * tilesize.x, (j + 1) * tilesize.y);
				quad[3].position = sf::Vector2f(i * tilesize.x, (j + 1) * tilesize.y);

				quad[0].texCoords = sf::Vector2f(tu * tilesize.x, tv * tilesize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tilesize.x, tv * tilesize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tilesize.x, (tv + 1) * tilesize.y);
				quad[3].texCoords = sf::Vector2f(tu * tilesize.x, (tv + 1) * tilesize.y);
			}
		}
		return true;
	}
private:
	sf::VertexArray m_vertices;
	sf::Texture m_tileset;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		states.transform *= getTransform();
		states.texture = &m_tileset;
		target.draw(m_vertices, states);
	}
};*/