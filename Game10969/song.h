#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <bits/stdc++.h>
using namespace std;

#define MAX 10
class song
{
public:
	song(float width, float height);
	~song();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void StopHook();
	int numsong() { return number_song; }

private:
	int selectedIndex,number_song;
	int last_song;
	vector<string> vecname;
	vector<string> Hook;
	sf::Music song_Hook;
	sf::Font font;
	sf::Text namesong[MAX];
	sf::Text skip;
	
};

