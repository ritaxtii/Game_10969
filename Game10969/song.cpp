#include "song.h"
#include <bits/stdc++.h>
using namespace std;


song::song(float width, float height)
{
	if (!font.loadFromFile("font.ttf"))
	{

	}

	//vector<string> vecname;

	last_song = -1;

	vecname.push_back("THE BEGINNING");
	vecname.push_back("DEEPER DEEPER");
	vecname.push_back("MIGHTY LONG FALL");
	vecname.push_back("CRY OUT");
	vecname.push_back("C.H.A.O.S.M.Y.T.H");
	vecname.push_back("RENEGADES");
	vecname.push_back("WONDER");
	vecname.push_back("TAKING OFF");
	vecname.push_back("Re:make");
	vecname.push_back("STAND OUT FIT IN");

	Hook.push_back("Hook/song0.wav");
	Hook.push_back("Hook/song1.wav");
	Hook.push_back("Hook/song2.wav");
	Hook.push_back("Hook/song3.wav");
	Hook.push_back("Hook/song4.wav");
	Hook.push_back("Hook/song5.wav");
	Hook.push_back("Hook/song6.wav");
	Hook.push_back("Hook/song7.wav");
	Hook.push_back("Hook/song8.wav");
	Hook.push_back("Hook/song9.wav");

	for (int i = 0; i < MAX ; i++)
	{
		namesong[i].setFont(font);
		namesong[i].setFillColor(sf::Color::Black);
		namesong[i].setString(vecname[i]);
		namesong[i].setCharacterSize(50 - 7 * abs(i - 3));
		if (i <= 3)
		{
			namesong[i].setPosition(sf::Vector2f((width / 4) + 9 * abs(3 - i), 40 + 115 * pow(1.3, i)));
		}
		else if (i <= 6)
		{
			namesong[i].setPosition(sf::Vector2f((width / 4) + 9 * abs(3 - i), namesong[7 - i].getPosition().y - namesong[6 - i].getPosition().y - namesong[6 - i].getLocalBounds().height + namesong[i - 1].getPosition().y + namesong[i-1].getLocalBounds().height));
		}
		
	}
	namesong[3].setFillColor(sf::Color::Red);
	selectedIndex = 3;
	number_song = 3;
	namesong[0].setFillColor(sf::Color(0, 0, 0, 96));
	namesong[1].setFillColor(sf::Color(0, 0, 0, 128));
	namesong[2].setFillColor(sf::Color(0, 0, 0, 191));
	namesong[4].setFillColor(sf::Color(0, 0, 0, 191));
	namesong[5].setFillColor(sf::Color(0, 0, 0, 128));
	namesong[6].setFillColor(sf::Color(0, 0, 0, 96));

	skip.setFont(font);
	skip.setCharacterSize(40);
	skip.setFillColor(sf::Color::Black);
	skip.setString("< press specebar to go back >");
	skip.setPosition(sf::Vector2f(width / 2 - 200, 655));



}
song::~song()
{

}

void song::draw(sf::RenderWindow& window)
{
	sf::Texture texture;
	texture.loadFromFile("Pic/bg1.jpg");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(0, 0);
	window.draw(sprite);

	if (last_song != number_song)
	{
		song_Hook.openFromFile(Hook[number_song]);
		if (number_song != 1 && number_song != 8 && number_song !=6)
		{
			song_Hook.setVolume(30.f);
		}
		else if (number_song == 6)
		{
			song_Hook.setVolume(50.f);
		}
		else
		{
			song_Hook.setVolume(100.f);
		}
		song_Hook.setLoop(true);
		song_Hook.play();
	}
	last_song = number_song;

	for (int i = 0; i < 7; i++)
	{
		window.draw(namesong[i]);
	}
	window.draw(skip);

}

void song::MoveUp()
{
	if (number_song == 0) number_song = MAX - 1;
	else number_song--;
		
		string mem = vecname[MAX - 1];
		for (int i = MAX - 1; i > 0; i--)
		{
			vecname[i] = vecname[i - 1];
		}
		vecname[0] = mem;
		for (int i = 0; i < MAX; i++)
		{
			namesong[i].setString(vecname[i]);
		}
		namesong[selectedIndex].setFillColor(sf::Color::Red);
}
void song::MoveDown()
{
	if (number_song == MAX - 1) number_song = 0;
	else number_song++;

	string mem = vecname[0];
	for (int i = 0; i < MAX-1; i++)
	{
		vecname[i] = vecname[i + 1];
	}
	vecname[MAX-1] = mem;
	for (int i = 0; i < MAX; i++)
	{
		namesong[i].setString(vecname[i]);
	}
	namesong[selectedIndex].setFillColor(sf::Color::Red);
}

void song::StopHook()
{
	song_Hook.stop();
}