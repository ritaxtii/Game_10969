#include "play.h"

using namespace std;

play::play(float width, float height)
{
	
}
play::~play()
{

}

void play::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bg.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	
}

void play::Music()
{
	music.play();
}

