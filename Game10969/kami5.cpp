#include "kami5.h"
#include <bits/stdc++.h>

using namespace std;


kami5::kami5(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{

	}

	FILE* fp;
	char name[100];
	char score[100];
	vector<pair<string, string>> vec;
	fp = fopen("Text.txt", "r+t");


	while (!feof(fp))
	{
		fgets(name, 100, fp);
		fgets(score, 100, fp);
		

		vec.push_back(make_pair(name, score));

	}
	fclose(fp);
	if (!vec.empty())
		vec.erase(vec.end() - 1);

	MAX_TOP_USER = vec.size();
	for (int i = 0; i < vec.size(); i++)
	{
		username[i].setFont(font);
		username[i].setCharacterSize(45);
		username[i].setFillColor(sf::Color::Black);
		username[i].setString(vec[i].first);
		
		
	}
	username[0].setCharacterSize(55);

	username[0].setPosition(sf::Vector2f(420 - (username[0].getLocalBounds().width / 2), 190));
	username[1].setPosition(sf::Vector2f(420 - (username[1].getLocalBounds().width / 2), 270-5));
	username[2].setPosition(sf::Vector2f(420 - (username[2].getLocalBounds().width / 2), 335 - 5));
	username[3].setPosition(sf::Vector2f(420 - (username[3].getLocalBounds().width / 2), 400 - 5));
	username[4].setPosition(sf::Vector2f(420 - (username[4].getLocalBounds().width / 2), 465 - 5));
	for (int i = 0; i < vec.size(); i++)
	{
		userscore[i].setFont(font);
		userscore[i].setCharacterSize(45);
		userscore[i].setFillColor(sf::Color::Black);
		userscore[i].setString(vec[i].second);
		
	}
	userscore[0].setCharacterSize(55);
	userscore[0].setPosition(sf::Vector2f(732 - (userscore[0].getLocalBounds().width / 2), 190));
	userscore[1].setPosition(sf::Vector2f(732 - (userscore[1].getLocalBounds().width / 2), 270 - 5));
	userscore[2].setPosition(sf::Vector2f(732 - (userscore[2].getLocalBounds().width / 2), 335 - 5));
	userscore[3].setPosition(sf::Vector2f(732 - (userscore[3].getLocalBounds().width / 2), 400 - 5));
	userscore[4].setPosition(sf::Vector2f(732 - (userscore[4].getLocalBounds().width / 2), 465 - 5));

	
	skip.setFont(font);
	skip.setCharacterSize(40);
	skip.setFillColor(sf::Color::Black);
	skip.setString("< press specebar to go back >");
	skip.setPosition(sf::Vector2f(width / 2 -200 ,655));
	
	

}
kami5::~kami5()
{

}

void kami5::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bgkami.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	for (int i = 0; i < MAX_TOP_USER; i++)
	{
		window.draw(username[i]);
		window.draw(userscore[i]);
	}
	window.draw(skip);


}
