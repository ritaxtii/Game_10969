#include "menu.h"

menu::menu(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{

	}
	
	Menu[1].setScale(1.1, 1.1f);

	selectedIndex = 1;

	skip.setFont(font);
	skip.setCharacterSize(40);
	skip.setFillColor(sf::Color::Black);
	skip.setString("< press specebar to go back >");
	skip.setPosition(sf::Vector2f(width / 2 - 200, 655));

	PS.push_back(std::make_pair(300, 410));
	PS.push_back(std::make_pair(576, 283));
	PS.push_back(std::make_pair(852, 410));

}
menu::~menu()
{

}

void menu::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bg1.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	sf::Texture texture2;
	texture2.loadFromFile("Pic/logo.png");
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	sprite2.setPosition(173, 63);
	window.draw(sprite2);
	
	sf::Texture tex[MAX_NUMBER_OF_ITEMS];
	tex[0].loadFromFile("Pic/Kami5.png");
	Menu[0].setTexture(tex[0]);
	Menu[0].setPosition(PS[0].first - (Menu[0].getLocalBounds().width / 2), PS[0].second - (Menu[0].getLocalBounds().height / 2));

	tex[1].loadFromFile("Pic/Play.png");
	Menu[1].setTexture(tex[1]);
	Menu[1].setPosition(PS[1].first - (Menu[1].getLocalBounds().width / 2), PS[1].second - (Menu[1].getLocalBounds().height / 2));

	tex[2].loadFromFile("Pic/Exit.png");
	Menu[2].setTexture(tex[2]);
	Menu[2].setPosition(PS[2].first - (Menu[2].getLocalBounds().width / 2), PS[2].second - (Menu[2].getLocalBounds().height / 2));
	
	
	
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(Menu[i]);
	}
	window.draw(skip);
	
	
}
void menu::drawlogin(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/loginbg.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

}

void menu::MoveUp()
{
	if(selectedIndex - 1 >= 0 )
	{
		
		Menu[selectedIndex].setScale(1, 1);
		selectedIndex--;
		Menu[selectedIndex].setScale(1.1f, 1.1f);
		

	}
}
void menu::MoveDown()
{
	if (selectedIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		Menu[selectedIndex].setScale(1, 1);
		selectedIndex++;
		Menu[selectedIndex].setScale(1.1f, 1.1f);
		

	}
}