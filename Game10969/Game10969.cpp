#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <bits/stdc++.h>
#include <windows.h>

#include "menu.h"
#include "song.h"
#include "level.h"
#include "kami5.h"
#include "play.h"

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#define __STD_WANT_LIB_EXIT__ 1



using namespace std;

vector<string> file_song;
sf::RenderWindow window(sf::VideoMode(1152, 720), "10969");
vector <pair< pair<int, sf::Sprite>, int >> vec;
vector <pair< pair<int, sf::Sprite>, int >> item_SP;
vector <long long int> score_[10];
sf::Texture popup[6];
sf::Texture cent[4];
sf::Sprite S[6];
sf::Texture NewH;
sf::Sprite newH;
sf::Texture item[4];
sf::Sprite Item[4];
sf::Texture mitem[4];
sf::Sprite mItem[4];
sf::Sprite sprite[4];
sf::Sprite wait_s[4];
sf::Texture tex[4];
sf::Sprite POPUP;
sf::Music music;
sf::Text Score;
sf::Text sc;
sf::Text GD[6];
sf::Font font;
bool bmitem[4] = {};
long long int GD_Count[5] = {};
int good = -1;
float rota = 4;
vector<char> username;
char L, R , T , U;
string to_string(int num);
string user_name = "";
string PlusL = "";
sf::Texture Bboom[10];
long long time_x;
long long int s = 0;
int numsong = 0;
int numlevel = 0;

bool check(char s, sf::Event event);
int plusL(int position, int n);
void random(int numlevel, int numsong, long long t);
void draw_username();
void random_SP();
void endgame();
void BlackBoom(float x,float y,int rot);
void draw_tab();
void draw_name(int T,int st);
void show_wait();
void save();

struct boom {

    sf::RectangleShape booom;
    int time_boom;
    int x;
    int y;
    sf::IntRect uvRect;
    
};
vector<boom> Boom;

struct Cenn {

    sf::RectangleShape Pic;
    int time;
    int x;
    int y;
    sf::IntRect uvRect;

};
vector<Cenn> cen;

long long time_good = 0;


int main()
{
    
    int stage = -2;
    int mem = 0;
    int runSP = 0;
    float OP_SP = 255;
    int end = false;
    int s_t;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            score_[j].push_back(0);
        }
    }

    menu Menu(window.getSize().x, window.getSize().y);
    song Song(window.getSize().x, window.getSize().y);
    level Level(window.getSize().x, window.getSize().y);
    kami5 Kami5(window.getSize().x, window.getSize().y);
    play Play(window.getSize().x, window.getSize().y);
    
    sf::Clock cl;
    sf::Clock clock;
    
    file_song.push_back("song/song0.wav");
    file_song.push_back("song/song1.wav");
    file_song.push_back("song/song2.wav");
    file_song.push_back("song/song3.wav");
    file_song.push_back("song/song4.wav");
    file_song.push_back("song/song5.wav");
    file_song.push_back("song/song6.wav");
    file_song.push_back("song/song7.wav");
    file_song.push_back("song/song8.wav");
    file_song.push_back("song/song9.wav");
    file_song.push_back("song/song10.wav");

    
    
    popup[0].loadFromFile("Pic/n1.png");
    S[0].setTexture(popup[0]);
    S[0].setPosition(sf::Vector2f(5, 15));

    popup[1].loadFromFile("Pic/n2.png");
    S[1].setTexture(popup[1]);
    S[1].setPosition(sf::Vector2f(130, 15));

    popup[2].loadFromFile("Pic/n3.png");
    S[2].setTexture(popup[2]);
    S[2].setPosition(sf::Vector2f(255, 15));

    popup[3].loadFromFile("Pic/n4.png");
    S[3].setTexture(popup[3]);
    S[3].setPosition(sf::Vector2f(380, 15));

    popup[4].loadFromFile("Pic/n5.png");
    S[4].setTexture(popup[4]);
    S[4].setPosition(sf::Vector2f(700, 15));

    popup[5].loadFromFile("Pic/n6.png");
    S[5].setTexture(popup[5]);
    S[5].setPosition(sf::Vector2f(850, 15));

    item[0].loadFromFile("Pic/SItem/Ryota.png");
    Item[0].setTexture(item[0]);

    item[1].loadFromFile("Pic/SItem/Taka.png");
    Item[1].setTexture(item[1]);

    item[2].loadFromFile("Pic/SItem/Tomoya.png");
    Item[2].setTexture(item[2]);

    item[3].loadFromFile("Pic/SItem/Toru.png");
    Item[3].setTexture(item[3]);

    mitem[0].loadFromFile("Pic/SItem/miniRyota.png");
    mItem[0].setTexture(mitem[0]);
    mItem[0].setPosition(524,15);

    mitem[1].loadFromFile("Pic/SItem/miniTaka.png");
    mItem[1].setTexture(mitem[1]);
    mItem[1].setPosition(565,15);

    mitem[2].loadFromFile("Pic/SItem/miniTomoya.png");
    mItem[2].setTexture(mitem[2]);
    mItem[2].setPosition(606, 15);

    mitem[3].loadFromFile("Pic/SItem/miniToru.png");
    mItem[3].setTexture(mitem[3]);
    mItem[3].setPosition(647, 15);

    NewH.loadFromFile("Pic/NewH.png");
    newH.setTexture(NewH);
    newH.setPosition(sf::Vector2f(500,160));

 
    sf::Text score_SP;
    font.loadFromFile("font.ttf");
    Score.setFont(font);
    Score.setFillColor(sf::Color::White);
    Score.setString("0");
    Score.setCharacterSize(55);
    Score.setPosition(955,-17);

    sc.setFont(font);
    sc.setFillColor(sf::Color::White);
    sc.setString("0");
    sc.setCharacterSize(100);

    GD[0].setFont(font);
    GD[0].setFillColor(sf::Color::Yellow);
    GD[0].setString("x 0");
    GD[0].setCharacterSize(40);
    GD[0].setPosition(55, -3);

    GD[1].setFont(font);
    GD[1].setFillColor(sf::Color::Green);
    GD[1].setString("x 0");
    GD[1].setCharacterSize(40);
    GD[1].setPosition(180, -3);

    GD[2].setFont(font);
    GD[2].setFillColor(sf::Color::Cyan);
    GD[2].setString("x 0");
    GD[2].setCharacterSize(40);
    GD[2].setPosition(305, -3);

    GD[3].setFont(font);
    GD[3].setFillColor(sf::Color::Red);
    GD[3].setString("x 0");
    GD[3].setCharacterSize(40);
    GD[3].setPosition(430, -3);

    GD[4].setFont(font);
    GD[4].setFillColor(sf::Color::White);
    GD[4].setString("x 0");
    GD[4].setCharacterSize(40);
    GD[4].setPosition(750, -3);

    GD[5].setFont(font);
    GD[5].setFillColor(sf::Color::Green);
    GD[5].setString("");
    GD[5].setCharacterSize(40);
    GD[5].setPosition(1070, -3);

    sf::Texture popup;
    popup.loadFromFile("Pic/popend.png");
    POPUP.setTexture(popup);
    POPUP.setOrigin(0, 0);

    sf::RectangleShape booom0(sf::Vector2f(256.0f, 256.0f));
    sf::RectangleShape booom1(sf::Vector2f(256.0f, 256.0f));
    sf::RectangleShape booom2(sf::Vector2f(256.0f, 256.0f));
    sf::RectangleShape booom3(sf::Vector2f(256.0f, 256.0f));
    sf::RectangleShape booom4(sf::Vector2f(256.0f, 256.0f));
    sf::RectangleShape booom5(sf::Vector2f(256.0f, 256.0f));
    sf::RectangleShape booom6(sf::Vector2f(256.0f, 256.0f));
    sf::RectangleShape booom7(sf::Vector2f(256.0f, 256.0f));
    sf::RectangleShape booom8(sf::Vector2f(256.0f, 256.0f));

    sf::RectangleShape CenT0(sf::Vector2f(106.0f, 106.0f));
    sf::RectangleShape CenT1(sf::Vector2f(106.0f, 106.0f));
    sf::RectangleShape CenT2(sf::Vector2f(106.0f, 106.0f));
    sf::RectangleShape CenT3(sf::Vector2f(106.0f, 106.0f));

    
    
    Bboom[0].loadFromFile("Pic/Effect/Y.png");
    Bboom[1].loadFromFile("Pic/Effect/G1.png");
    Bboom[2].loadFromFile("Pic/Effect/B.png");
    Bboom[3].loadFromFile("Pic/Effect/R.png");
    Bboom[4].loadFromFile("Pic/Effect/Ryota.png");
    Bboom[5].loadFromFile("Pic/Effect/Taka.png");
    Bboom[6].loadFromFile("Pic/Effect/Tomoya.png");
    Bboom[7].loadFromFile("Pic/Effect/G.png"); //Toru
    Bboom[8].loadFromFile("Pic/Effect/Bk1.png"); //Black

    cent[0].loadFromFile("Pic/Center/Green.png");
    cent[1].loadFromFile("Pic/Center/Red.png");
    cent[2].loadFromFile("Pic/Center/Yellow.png");
    cent[3].loadFromFile("Pic/Center/Pink.png");

    booom0.setTexture(&Bboom[0]);
    booom1.setTexture(&Bboom[1]);
    booom2.setTexture(&Bboom[2]);
    booom3.setTexture(&Bboom[3]);
    booom4.setTexture(&Bboom[4]);
    booom5.setTexture(&Bboom[5]);
    booom6.setTexture(&Bboom[6]);
    booom7.setTexture(&Bboom[7]);
    booom8.setTexture(&Bboom[8]);

    CenT0.setTexture(&cent[0]);
    CenT1.setTexture(&cent[1]);
    CenT2.setTexture(&cent[2]);
    CenT3.setTexture(&cent[3]);

    sf::Texture Center;
    Center.loadFromFile("Pic/Center/center.png");
    sf::Sprite center;
    center.setTexture(Center);
    center.setPosition(sf::Vector2f(523, 307));

    sf::Texture Howto;
    Howto.loadFromFile("Pic/Howtoplay.png");
    sf::Sprite How;
    How.setTexture(Howto);
    How.setPosition(sf::Vector2f(0, 0));
   
    
    string st;
    long long Boomtime=0;
    long long time;
    while (window.isOpen())
    {
        
        sf::Event event;
        time = cl.getElapsedTime().asMilliseconds();
        time_x = time;
        
        //Wait play
        if (stage == 5)
        {
            Play.draw(window);
            window.draw(center);
            show_wait();
            draw_tab();
            while (window.pollEvent(event))
            {

                if (event.type == sf::Event::Closed)
                    window.close();
                switch (event.key.code)
                {
                case sf::Keyboard::Space:
                    music.openFromFile(file_song[numsong]);
                    Sleep(300);
                    Song.StopHook();
                    music.play();
                    stage = 4;
                    cl.restart();
                    break;
                }
            }
            window.display();
        }
        //Play
        if (stage == 4)
        {
            Play.draw(window);
            draw_tab();
            if (good != -1 && time - time_good <= 500) window.draw(GD[5]);
            if (runSP < 4)
            {
                if (time - item_SP[runSP].first.first <= 10000 && time - item_SP[runSP].first.first >= 0)
                {
                    if (((time - item_SP[runSP].first.first) / 100) % 2 == 0)
                        window.draw(item_SP[runSP].first.second);
                   /* if (item_SP[runSP].first.second.getRotation() == 90) rota = -3;
                    else if (item_SP[runSP].first.second.getRotation() == 324) rota = 3;
                        item_SP[runSP].first.second.rotate(rota);*/

                    if (OP_SP <= 0)
                    {
                        sf::RectangleShape bbooom(sf::Vector2f(256.0f, 256.0f));
                        bbooom.setTexture(&Bboom[item_SP[runSP].second + 4]);
                        bbooom.setPosition(item_SP[runSP].first.second.getPosition().x-68, item_SP[runSP].first.second.getPosition().y-80.5);
                        bbooom.setRotation(item_SP[runSP].first.second.getRotation());
                        boom M_boom = { bbooom , time_x , 0, 0 , {0,0,256,256} };
                        Boom.push_back(M_boom);
                        time_good = time;
                        bmitem[item_SP[runSP].second] = true;
                        GD[5].setFillColor(sf::Color::Yellow);
                        if (item_SP[runSP].second == 0) //Ryota
                        {
                            if (s % 2 == 0)
                            {
                                PlusL = "+ 5000";
                                s += 5000;
                            }
                        }
                        else if (item_SP[runSP].second == 1)
                        {
                            PlusL = "+ 5000" ;
                            s += 5000;
                        }
                        else if (item_SP[runSP].second == 2)
                        {
                            if (s % 2 == 0)
                            {
                                PlusL = "+ 5000";
                                s += 5000;
                            }

                        }
                        else if (item_SP[runSP].second == 3)
                        {
                            PlusL = "+ 5%";
                            s *= 1.05;
                        }

                        runSP++, OP_SP = 255;
                    }
                    else item_SP[runSP].first.second.setColor(sf::Color(255, 255, 255, OP_SP));

                }
                else if (time - item_SP[runSP].first.first >= 10000)
                {
                    BlackBoom(item_SP[runSP].first.second.getPosition().x-68, item_SP[runSP].first.second.getPosition().y-80.5, 0);
                    OP_SP = 255;
                    runSP++;
                }
            }
            
            if (!cen.empty())
            {
            if (time - cen[0].time >= 0 )
            {
            cen[0].x = (time - cen[0].time) / 80;
            cen[0].y = 0;

            if (cen[0].x >= 9) cen.erase(cen.begin());
            else
            {
                cen[0].uvRect.left = cen[0].x * cen[0].uvRect.width;
                cen[0].uvRect.top = cen[0].y * cen[0].uvRect.height;
                cen[0].Pic.setTextureRect(cen[0].uvRect);
                window.draw(cen[0].Pic);
            }
            }
            else
            {
                window.draw(center);
            }
            }
            else
            {
                window.draw(center);
            }
            
            


            for (int i = 0; i < Boom.size(); i++)
            {

                Boom[i].x = ((time - Boom[i].time_boom) / 20) % 6;
                Boom[i].y = ((time - Boom[i].time_boom) / 20) / 6;

                if (Boom[i].y >= 5)
                {
                    Boom.erase(Boom.begin());
                    i--;
                }
                else
                {
                    Boom[i].uvRect.left = Boom[i].x * Boom[i].uvRect.width;
                    Boom[i].uvRect.top = Boom[i].y * Boom[i].uvRect.height;
                    Boom[i].booom.setTextureRect(Boom[i].uvRect);
                    window.draw(Boom[i].booom);
                }

            }

            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i].first.second.getPosition().x > 533 && vec[i].second == 0) //523
                {
                    GD_Count[4]++;
                   // BlackBoom(vec[0].first.second.getPosition().x - 77, vec[0].first.second.getPosition().y - 107,0);
                    vec.erase(vec.begin());
                }
                else if (vec[i].first.second.getPosition().x < 513 && vec[i].second == 1) //523
                {
                    GD_Count[4]++;
                   // BlackBoom(vec[0].first.second.getPosition().x - 77, vec[0].first.second.getPosition().y - 107,0);
                    vec.erase(vec.begin());
                }
                else if (vec[i].first.second.getPosition().y > 317 && vec[i].second == 2) //307
                {
                    GD_Count[4]++;
                  //  BlackBoom(vec[0].first.second.getPosition().x - 77, vec[0].first.second.getPosition().y - 107,0);
                    vec.erase(vec.begin());
                }
                else if (vec[i].first.second.getPosition().y < 297 && vec[i].second == 3) //307
                {
                    GD_Count[4]++;
                   // BlackBoom(vec[0].first.second.getPosition().x - 77, vec[0].first.second.getPosition().y - 107,0);
                    vec.erase(vec.begin());
                }
                else break;
            }
            if (!end)
            {
                for (int i = 0; i < vec.size(); i++)
                {
                    if (vec[i].first.first <= time + 4000 && vec[i].first.first <= time)
                    {
                        if (vec[i].second == 0 && vec[i].first.second.getPosition().x <= 533)
                        {
                            window.draw(vec[i].first.second);
                            vec[i].first.second.move(6.f, 0.0f);

                        }
                        else if (vec[i].second == 1 && vec[i].first.second.getPosition().x >= 513)
                        {
                            window.draw(vec[i].first.second);
                            vec[i].first.second.move(-6.f, 0.0f);
                        }
                        else if (vec[i].second == 2 && vec[i].first.second.getPosition().y <= 317)
                        {
                            window.draw(vec[i].first.second);
                            vec[i].first.second.move(0.f, 6.0f);
                        }
                        else if (vec[i].second == 3 && vec[i].first.second.getPosition().y >= 297)
                        {
                            window.draw(vec[i].first.second);
                            vec[i].first.second.move(0.f, -6.0f);
                        }
                        if (vec[i].first.first > time + 4000) break;
                    }
                }
            }



            while (window.pollEvent(event))
            {
                if (sf::Event::KeyReleased && !vec.empty())
                {
                    if (vec[0].second == 0 && check(L, event)) s += plusL(vec[0].first.second.getPosition().x, 523), time_good = time;
                    else if (vec[0].second == 1 && check(R, event)) s += plusL(vec[0].first.second.getPosition().x, 523), time_good = time;
                    else if (vec[0].second == 2 && check(T, event)) s += plusL(vec[0].first.second.getPosition().y, 307), time_good = time;
                    else if (vec[0].second == 3 && check(U, event)) s += plusL(vec[0].first.second.getPosition().y, 307), time_good = time;

                }
                if (runSP < 4)
                {
                    if (time - item_SP[runSP].first.first <= 10000 && time - item_SP[runSP].first.first >= 0)
                    {
                        if (sf::Event::KeyReleased)
                        {
                            if (event.key.code == sf::Keyboard::Space) OP_SP -= 12.75, cout << OP_SP << endl;
                        }
                    }
                }

                if (sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Escape) end = true,music.pause();
                }

                if (vec.empty())
                {
                    end = true;
                }

                if (event.type == sf::Event::Closed)
                    window.close();
                if (end)
                {
                    if (sf::Event::KeyReleased)
                    {
                        if (event.key.code == sf::Keyboard::Space)
                        {
                            Sleep(300);
                            stage = 2;
                            score_[numsong][numlevel] = max(score_[numsong][numlevel], s);
                        }
                    }
                }
            }

            if (end) endgame();
            window.display();
        }


        //Menu
        else if (stage == 1)
        {
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Left:
                        Menu.MoveUp();
                        break;
                    case sf::Keyboard::Right:
                        Menu.MoveDown();
                        break;
                    case sf::Keyboard::Space:
                        stage = -2;
                        Sleep(300);
                        break;
                    case sf::Keyboard::Return:
                        switch (Menu.GetPressedItem())
                        {
                            //Kami5
                        case 0:
                            stage = -1;
                            break;
                            //Play
                        case 1:
                            stage = 2;
                            break;
                            //Exit
                        case 2:
                            save();
                            window.close();
                            break;
                        }
                    }


                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }


            window.clear();
            Menu.draw(window);
            if (((time - s_t) / 10000) % 2 == 1) window.draw(How);
            else draw_name(time,s_t);
            window.display();
        }

        //choose song
        else if (stage == 2)
        {
            
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        Song.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        Song.MoveDown();
                        break;
                    case sf::Keyboard::Return:
                        numsong = Song.numsong();
                        cout << numsong << endl;
                        stage = 3;
                        break;
                    case sf::Keyboard::Space:
                        stage = 1;
                        s_t = time;
                        Sleep(300);
                        break;
                    }


                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }


            window.clear();
            Song.draw(window);
            window.display();
        }

        //choose level
        else if (stage == 3)
        {
            window.clear();
            Level.draw(window);
            window.display();
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        Level.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        Level.MoveDown();
                        break;
                    case sf::Keyboard::Return:
                        numlevel = Level.numlevel();
                        cout << "level" << numlevel << endl;
                        vec.clear();
                        random(numlevel,numsong,time);
                        random_SP();
                        cout << numsong <<endl;
                        rota = 4;
                        end = false;
                        bmitem[0] = 0;
                        bmitem[1] = 0;
                        bmitem[2] = 0;
                        bmitem[3] = 0;
                        GD_Count[0] = 0;
                        GD_Count[1] = 0;
                        GD_Count[2] = 0;
                        GD_Count[3] = 0;
                        GD_Count[4] = 0;
                        good = -1;
                        rota = 4;
                        PlusL = "";
                        s = 0;
                        OP_SP = 255;
                        runSP = 0;
                        stage = 5;
                        break;
                    case sf::Keyboard::Space:
                        stage = 2;
                        Sleep(300);
                        break;
                    }


                }
                if (event.type == sf::Event::Closed)
                    window.close();
            }


            
        }

        
       
        //kami5
        else if (stage == -1)
        {

            while (window.pollEvent(event))
            {
          
                if (event.type == sf::Event::Closed)
                    window.close();
                switch (event.key.code)
                {
                case sf::Keyboard::Space:
                    stage = 1;
                    s_t = time;
                    Sleep(300);
                    break;
                }
            }
            window.clear();
            Kami5.draw(window);
            window.display();
        }

        //login
        else if (stage == -2)
        {

        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::TextEntered)
                username.push_back(event.text.unicode);
            if (!username.empty() && username.back() == 8)
            {
                username.pop_back();
                if (!username.empty())
                    username.pop_back();

            }
            
             if (username.size()!=1 &&!username.empty()&& username.back() == 13 )
            {
                username.pop_back();
                stage = 1;
                s_t = time;
                Sleep(300);
            }
            if (!username.empty() && !((username.back() >= 'a' && username.back() <= 'z' ) ||( username.back() >= 'A' && username.back() <= 'Z' ) ||( username.back() >= '0' && username.back() <= '9') || username.back() == '_' ))
            {
                username.pop_back();
            }
            if (username.size() > 15)
            {
                username.pop_back();
            }
            
            if (event.type == sf::Event::Closed)
                window.close();
           
        }
      
            window.clear();
            Menu.drawlogin(window);
            draw_username();
            window.display();
        }

    }

    
    return 0;
}

string to_string(int num)
{
    ostringstream os;
    os << num;
    return os.str();
}
bool check(char s, sf::Event event)
{
   // cout << s;

    if (s == 'A' && event.key.code == sf::Keyboard::A) return true;
    else if (s == 'B' && event.key.code == sf::Keyboard::B) return true;
    else if (s == 'C' && event.key.code == sf::Keyboard::C) return true;
    else if (s == 'D' && event.key.code == sf::Keyboard::D) return true;
    else if (s == 'E' && event.key.code == sf::Keyboard::E) return true;
    else if (s == 'F' && event.key.code == sf::Keyboard::F) return true;
    else if (s == 'G' && event.key.code == sf::Keyboard::G) return true;
    else if (s == 'H' && event.key.code == sf::Keyboard::H) return true;
    else if (s == 'I' && event.key.code == sf::Keyboard::I) return true;
    else if (s == 'J' && event.key.code == sf::Keyboard::J) return true;
    else if (s == 'K' && event.key.code == sf::Keyboard::K) return true;
    else if (s == 'L' && event.key.code == sf::Keyboard::L) return true;
    else if (s == 'M' && event.key.code == sf::Keyboard::M) return true;
    else if (s == 'N' && event.key.code == sf::Keyboard::N) return true;
    else if (s == 'O' && event.key.code == sf::Keyboard::O) return true;
    else if (s == 'P' && event.key.code == sf::Keyboard::P) return true;
    else if (s == 'Q' && event.key.code == sf::Keyboard::Q) return true;
    else if (s == 'R' && event.key.code == sf::Keyboard::R) return true;
    else if (s == 'S' && event.key.code == sf::Keyboard::S) return true;
    else if (s == 'T' && event.key.code == sf::Keyboard::T) return true;
    else if (s == 'U' && event.key.code == sf::Keyboard::U) return true;
    else if (s == 'V' && event.key.code == sf::Keyboard::V) return true;
    else if (s == 'W' && event.key.code == sf::Keyboard::W) return true;
    else if (s == 'X' && event.key.code == sf::Keyboard::X) return true;
    else if (s == 'Y' && event.key.code == sf::Keyboard::Y) return true;
    else if (s == 'Z' && event.key.code == sf::Keyboard::Z) return true;
    else return false;

}
int plusL(int position, int n)
{
    int x = abs(n - position);
    if (x <= 106)
    {
        long long int  s = ((106 - x) * 100) / 106;
        if (s >= 95) good = 0, GD_Count[0]++;
        else if (s >= 75) good = 1, GD_Count[1]++;
        else if (s >= 50) good = 2, GD_Count[2]++;
        else {
            good = 3; s = -50; GD_Count[3]++ ;
        }
        
        if (!vec.empty())
    {
        sf::RectangleShape bbooom(sf::Vector2f(256.0f, 256.0f));
        bbooom.setTexture(&Bboom[good]);
        bbooom.setPosition(vec[0].first.second.getPosition().x - 77, vec[0].first.second.getPosition().y - 107);
        boom M_boom = { bbooom , time_x , 0, 0 , {0,0,256,256} };
        Boom.push_back(M_boom);

        vec.erase(vec.begin());
    }
        if (s >= 0)
        {
            GD[5].setFillColor(sf::Color::Green);
            PlusL = "+ " + to_string(s);
        }

        else
        {
            GD[5].setFillColor(sf::Color::Red);
            PlusL = "- " + to_string(abs(s));
        }
        
        return s;
    }
    else
    {
        good = 3; 
        if (!vec.empty())
        {
            sf::RectangleShape bbooom(sf::Vector2f(256.0f, 256.0f));
            bbooom.setTexture(&Bboom[good]);
            bbooom.setPosition(vec[0].first.second.getPosition().x - 77, vec[0].first.second.getPosition().y - 107);
            boom M_boom = { bbooom , time_x , 0, 0 , {0,0,256,256} };
            Boom.push_back(M_boom);

            vec.erase(vec.begin());
        }
        GD_Count[3]++;
        long long int i = 50;
        GD[5].setFillColor(sf::Color::Red);
        PlusL = "- " + to_string(i);
        return -50;
    }
    
}
void BlackBoom(float x, float y,int rot)
{
    sf::RectangleShape bbooom(sf::Vector2f(256.0f, 256.0f));
    bbooom.setTexture(&Bboom[8]);
    bbooom.setPosition(x,y);
    bbooom.setRotation(rot);
    boom M_boom = { bbooom , time_x , 0, 0 , {0,0,256,256} };
    Boom.push_back(M_boom);
}
void random(int numlevel, int numsong, long long t)
{
    srand(time(NULL));
    if (numlevel == 0)
    {

        int nl = rand() % 13;
        int nr = rand() % 13;

       // cout << nr << " " << nl;


        if (nl == 0) tex[0].loadFromFile("Pic/Level1/Q.png"), L = 'Q';
        else if (nl == 1) tex[0].loadFromFile("Pic/Level1/W.png"), L = 'W';
        else if (nl == 2) tex[0].loadFromFile("Pic/Level1/E.png"), L = 'E';
        else if (nl == 3) tex[0].loadFromFile("Pic/Level1/R.png"), L = 'R';
        else if (nl == 4) tex[0].loadFromFile("Pic/Level1/T.png"), L = 'T';
        else if (nl == 5) tex[0].loadFromFile("Pic/Level1/A.png"), L = 'A';
        else if (nl == 6) tex[0].loadFromFile("Pic/Level1/S.png"), L = 'S';
        else if (nl == 7) tex[0].loadFromFile("Pic/Level1/D.png"), L = 'D';
        else if (nl == 8) tex[0].loadFromFile("Pic/Level1/F.png"), L = 'F';
        else if (nl == 9) tex[0].loadFromFile("Pic/Level1/Z.png"), L = 'Z';
        else if (nl == 10) tex[0].loadFromFile("Pic/Level1/X.png"), L = 'X';
        else if (nl == 11) tex[0].loadFromFile("Pic/Level1/C.png"), L = 'C';
        else if (nl == 12) tex[0].loadFromFile("Pic/Level1/V.png"), L = 'V';

        if (nr == 0) tex[1].loadFromFile("Pic/Level1/Y.png"), R = 'Y';
        else if (nr == 1) tex[1].loadFromFile("Pic/Level1/U.png"), R = 'U';
        else if (nr == 2) tex[1].loadFromFile("Pic/Level1/I.png"), R = 'I';
        else if (nr == 3) tex[1].loadFromFile("Pic/Level1/O.png"), R = 'O';
        else if (nr == 4) tex[1].loadFromFile("Pic/Level1/P.png"), R = 'P';
        else if (nr == 5) tex[1].loadFromFile("Pic/Level1/G.png"), R = 'G';
        else if (nr == 6) tex[1].loadFromFile("Pic/Level1/H.png"), R = 'H';
        else if (nr == 7) tex[1].loadFromFile("Pic/Level1/J.png"), R = 'J';
        else if (nr == 8) tex[1].loadFromFile("Pic/Level1/K.png"), R = 'K';
        else if (nr == 9) tex[1].loadFromFile("Pic/Level1/L.png"), R = 'L';
        else if (nr == 10) tex[1].loadFromFile("Pic/Level1/B.png"), R = 'B';
        else if (nr == 11) tex[1].loadFromFile("Pic/Level1/N.png"), R = 'N';
        else if (nr == 12) tex[1].loadFromFile("Pic/Level1/M.png"), R = 'M';

        sprite[0].setTexture(tex[0]);
        wait_s[0].setTexture(tex[0]);
        sprite[0].setPosition(sf::Vector2f(-106, 307));
        wait_s[0].setPosition(sf::Vector2f(306, 307));
        sprite[1].setTexture(tex[1]);
        wait_s[1].setTexture(tex[1]);
        sprite[1].setPosition(sf::Vector2f(1152, 307));
        wait_s[1].setPosition(sf::Vector2f(752, 307));
    }

    else if (numlevel == 1)
    {
        int nl = rand() % 9;
        int nr = rand() % 9;
        int nt = rand() % 8;
        cout << nr << " " << nl << " " << nt;
        if (nl == 0) tex[0].loadFromFile("Pic/Level2/Q.png"), L = 'Q';
        else if (nl == 1) tex[0].loadFromFile("Pic/Level2/W.png"), L = 'W';
        else if (nl == 2) tex[0].loadFromFile("Pic/Level2/E.png"), L = 'E';
        else if (nl == 3) tex[0].loadFromFile("Pic/Level2/A.png"), L = 'A';
        else if (nl == 4) tex[0].loadFromFile("Pic/Level2/S.png"), L = 'S';
        else if (nl == 5) tex[0].loadFromFile("Pic/Level2/D.png"), L = 'D';
        else if (nl == 6) tex[0].loadFromFile("Pic/Level2/Z.png"), L = 'Z';
        else if (nl == 7) tex[0].loadFromFile("Pic/Level2/X.png"), L = 'X';
        else if (nl == 8) tex[0].loadFromFile("Pic/Level2/C.png"), L = 'C';


        if (nr == 0) tex[1].loadFromFile("Pic/Level2/U.png"), R = 'U';
        else if (nr == 1) tex[1].loadFromFile("Pic/Level2/I.png"), R = 'I';
        else if (nr == 2) tex[1].loadFromFile("Pic/Level2/O.png"), R = 'O';
        else if (nr == 3) tex[1].loadFromFile("Pic/Level2/P.png"), R = 'P';
        else if (nr == 4) tex[1].loadFromFile("Pic/Level2/J.png"), R = 'J';
        else if (nr == 5) tex[1].loadFromFile("Pic/Level2/K.png"), R = 'K';
        else if (nr == 6) tex[1].loadFromFile("Pic/Level2/L.png"), R = 'L';
        else if (nr == 7) tex[1].loadFromFile("Pic/Level2/N.png"), R = 'N';
        else if (nr == 8) tex[1].loadFromFile("Pic/Level2/M.png"), R = 'M';

        if (nt == 0) tex[2].loadFromFile("Pic/Level2/R.png"), T = 'R';
        else if (nt == 1) tex[2].loadFromFile("Pic/Level2/T.png"), T = 'T';
        else if (nt == 2) tex[2].loadFromFile("Pic/Level2/Y.png"), T = 'Y';
        else if (nt == 3) tex[2].loadFromFile("Pic/Level2/F.png"), T = 'F';
        else if (nt == 4) tex[2].loadFromFile("Pic/Level2/G.png"), T = 'G';
        else if (nt == 5) tex[2].loadFromFile("Pic/Level2/H.png"), T = 'H';
        else if (nt == 6) tex[2].loadFromFile("Pic/Level2/V.png"), T = 'V';
        else if (nt == 7) tex[2].loadFromFile("Pic/Level2/B.png"), T = 'B';

        sprite[0].setTexture(tex[0]);
        wait_s[0].setTexture(tex[0]);
        sprite[0].setPosition(sf::Vector2f(-106, 307));
        wait_s[0].setPosition(sf::Vector2f(306, 307));
        sprite[1].setTexture(tex[1]);
        wait_s[1].setTexture(tex[1]);
        sprite[1].setPosition(sf::Vector2f(1152, 307));
        wait_s[1].setPosition(sf::Vector2f(752, 307));
        sprite[2].setTexture(tex[2]);
        wait_s[2].setTexture(tex[2]);
        sprite[2].setPosition(sf::Vector2f(523, -322));
        wait_s[2].setPosition(sf::Vector2f(523, 78));
    }

    else if (numlevel == 2)
    {
        int nl = rand() % 7;
        int nr = rand() % 6;
        int nt = rand() % 6;
        int nu = rand() % 7;

        if (nl == 0) tex[0].loadFromFile("Pic/Level3/Q.png"), L = 'Q';
        else if (nl == 1) tex[0].loadFromFile("Pic/Level3/W.png"), L = 'W';
        else if (nl == 2) tex[0].loadFromFile("Pic/Level3/A.png"), L = 'A';
        else if (nl == 3) tex[0].loadFromFile("Pic/Level3/S.png"), L = 'S';
        else if (nl == 4) tex[0].loadFromFile("Pic/Level3/D.png"), L = 'D';
        else if (nl == 5) tex[0].loadFromFile("Pic/Level3/Z.png"), L = 'Z';
        else if (nl == 6) tex[0].loadFromFile("Pic/Level3/X.png"), L = 'X';

        if (nr == 0) tex[1].loadFromFile("Pic/Level3/O.png"), R = 'O';
        else if (nr == 1) tex[1].loadFromFile("Pic/Level3/P.png"), R = 'P';
        else if (nr == 2) tex[1].loadFromFile("Pic/Level3/J.png"), R = 'J';
        else if (nr == 3) tex[1].loadFromFile("Pic/Level3/K.png"), R = 'K';
        else if (nr == 4) tex[1].loadFromFile("Pic/Level3/L.png"), R = 'L';
        else if (nr == 5) tex[1].loadFromFile("Pic/Level3/M.png"), R = 'M';

        if (nt == 0) tex[2].loadFromFile("Pic/Level3/E.png"), T = 'E';
        else if (nt == 1) tex[2].loadFromFile("Pic/Level3/R.png"), T = 'R';
        else if (nt == 2) tex[2].loadFromFile("Pic/Level3/T.png"), T = 'T';
        else if (nt == 3) tex[2].loadFromFile("Pic/Level3/Y.png"), T = 'Y';
        else if (nt == 4) tex[2].loadFromFile("Pic/Level3/U.png"), T = 'U';
        else if (nt == 5) tex[2].loadFromFile("Pic/Level3/I.png"), T = 'I';

        if (nu == 0) tex[3].loadFromFile("Pic/Level3/F.png"), U = 'F';
        else if (nu == 1) tex[3].loadFromFile("Pic/Level3/G.png"), U = 'G';
        else if (nu == 2) tex[3].loadFromFile("Pic/Level3/H.png"), U = 'H';
        else if (nu == 3) tex[3].loadFromFile("Pic/Level3/C.png"), U = 'C';
        else if (nu == 4) tex[3].loadFromFile("Pic/Level3/V.png"), U = 'V';
        else if (nu == 5) tex[3].loadFromFile("Pic/Level3/B.png"), U = 'B';
        else if (nu == 6) tex[3].loadFromFile("Pic/Level3/N.png"), U = 'N';


        sprite[0].setTexture(tex[0]);
        wait_s[0].setTexture(tex[0]);
        sprite[0].setPosition(sf::Vector2f(-106, 307));
        wait_s[0].setPosition(sf::Vector2f(306,307));
        sprite[1].setTexture(tex[1]);
        wait_s[1].setTexture(tex[1]);
        sprite[1].setPosition(sf::Vector2f(1152, 307));
        wait_s[1].setPosition(sf::Vector2f(752, 307));
        sprite[2].setTexture(tex[2]);
        wait_s[2].setTexture(tex[2]);
        sprite[2].setPosition(sf::Vector2f(523, -322));
        wait_s[2].setPosition(sf::Vector2f(523, 78));
        sprite[3].setTexture(tex[3]);
        wait_s[3].setTexture(tex[3]);
        sprite[3].setPosition(sf::Vector2f(523, 936));
        wait_s[3].setPosition(sf::Vector2f(523, 536));

    }
    FILE* fp;
    char time1[1000];
    fp = fopen("song0.txt", "r+t");
    if (numsong == 0) fp = fopen("tack/song0.txt", "r+t");
    else if (numsong == 1) fp = fopen("tack/song1.txt", "r+t");
    else if (numsong == 2) fp = fopen("tack/song2.txt", "r+t");
    else if (numsong == 3) fp = fopen("tack/song3.txt", "r+t");
    else if (numsong == 4) fp = fopen("tack/song4.txt", "r+t");
    else if (numsong == 5) fp = fopen("tack/song5.txt", "r+t");
    else if (numsong == 6) fp = fopen("tack/song6.txt", "r+t");
    else if (numsong == 7) fp = fopen("tack/song7.txt", "r+t");
    else if (numsong == 8) fp = fopen("tack/song8.txt", "r+t");
    else if (numsong == 9) fp = fopen("tack/song9.txt", "r+t");

    int n = 0;

    while (!feof(fp))
    {
        int num = 0;
        fgets(time1, 100, fp);

        for (int i = 0; i < strlen(time1) - 1; i++)
        {
            num = (num * 10) + time1[i] - 48;
        }

        int w = 2500;
        if (n % (numlevel + 2) == 0)
        {
            vec.push_back(make_pair(make_pair(num, sprite[0]), 0));

            sf::RectangleShape C(sf::Vector2f(106.0f, 106.0f));
            C.setTexture(&cent[0]);
            C.setPosition(sf::Vector2f(523, 307));
            Cenn M_cen = { C,num - (80 * 9) +w,0,0,{0,0,106,106} };
            cen.push_back(M_cen);

            
        }

        if (n % (numlevel + 2) == 1)
        {
            vec.push_back(make_pair(make_pair(num, sprite[1]), 1));
            sf::RectangleShape C(sf::Vector2f(106.0f, 106.0f));
            C.setTexture(&cent[1]);
            C.setPosition(sf::Vector2f(523, 307));
            Cenn M_cen = { C,num - (80 * 9) +w,0,0,{0,0,106,106} };
            cen.push_back(M_cen);
        }

        if (n % (numlevel + 2) == 2)
        {
            vec.push_back(make_pair(make_pair(num, sprite[2]), 2));
            sf::RectangleShape C(sf::Vector2f(106.0f, 106.0f));
            C.setTexture(&cent[2]);
            C.setPosition(sf::Vector2f(523, 307));
            Cenn M_cen = { C,num - (80 * 9)+w,0,0,{0,0,106,106} };
            cen.push_back(M_cen);
        }

        if (n % (numlevel + 2) == 3)
        {
            vec.push_back(make_pair(make_pair(num, sprite[3]), 3));
            sf::RectangleShape C(sf::Vector2f(106.0f, 106.0f));
            C.setTexture(&cent[3]);
            C.setPosition(sf::Vector2f(523, 307));
            Cenn M_cen = { C,num - (80 * 9)+w,0,0,{0,0,106,106} };
            cen.push_back(M_cen);
        }
        n++;
    }
    fclose(fp);

    if (!vec.empty()) vec.pop_back();
}
void draw_username()
{
    sf::Text US_name;
    sf::Font font;
    font.loadFromFile("font.ttf");
    US_name.setFont(font);
    
    user_name = "";
        for (int i = 0; i < username.size(); i++)
        {
            user_name += username[i];
        }
        
    US_name.setCharacterSize(55);
    if (username.empty())
    {
        US_name.setFillColor(sf::Color(255, 255, 255, 128));
        US_name.setString("ENTER YOUR NAME");
        //US_name.setFillColor(sf::Color::White);
    }
    else
    {
        US_name.setString(user_name);
        US_name.setFillColor(sf::Color::White);
    }
    int w = US_name.getLocalBounds().width;
    US_name.setPosition((1152 / 2) - (w / 2), 325);
    window.draw(US_name);
}
void random_SP()
{
    srand(time(NULL));
    while (item_SP.size() != 4)
    {
        int when = rand() % (vec.size() - 100) + 50;
        int item_appear = vec[when].first.first;
        int wath_item = rand() % 4;
        bool have = TRUE;
        for (int i = 0; i < item_SP.size(); i++)
        {
            if (item_SP[i].second == wath_item || item_SP[i].first.first == item_appear || abs(item_SP[i].first.first - item_appear)<=10000 )
            {
                have = FALSE;
                break;
            }
        }
        if (have)
        {
            Item[wath_item].setRotation(0.f);
            Item[wath_item].setPosition(sf::Vector2f(rand() % 852 + 150, rand() % 420 + 150));

            item_SP.push_back(make_pair(make_pair(item_appear, Item[wath_item]), wath_item));
            cout << item_appear << " " << wath_item << endl;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (item_SP[i].first.first > item_SP[j].first.first)
            {
                int t = item_SP[i].first.first;
                sf::Sprite sp = item_SP[i].first.second;
                int num = item_SP[i].second;

                item_SP[i].first.first = item_SP[j].first.first;
                item_SP[i].first.second = item_SP[j].first.second;
                item_SP[i].second = item_SP[j].second;

                item_SP[j].first.first = t;
                item_SP[j].first.second = sp;
                item_SP[j].second = num;

            }
        }
    }
}
void endgame()
{
    window.draw(POPUP);
    sc.setString("SCORE : " + to_string(s));
    int w = sc.getLocalBounds().width;
    sc.setPosition((1152 / 2) - (w / 2), 200);
    if (s > score_[numsong][numlevel])
    {
        newH.setPosition((1152 / 2) - (w / 2)-200, 210);
        window.draw(newH);
    }
    
    window.draw(sc);

    sf::Text skip;
    skip.setFont(font);
    skip.setCharacterSize(40);
    skip.setFillColor(sf::Color::White);
    skip.setString("< press specebar to play again >");
    skip.setPosition(sf::Vector2f(1152 / 2 - 210, 655));
    window.draw(skip);
   
}
void draw_tab()
{   Score.setString(to_string(s));
    GD[5].setString(PlusL);
    window.draw(Score);
    for (int i = 0; i < 6; i++)
    {
        window.draw(S[i]);
        if (i < 5)
        {
            if (i < 4 && bmitem[i])  window.draw(mItem[i]);
            GD[i].setString("x " + to_string(GD_Count[i]));
            window.draw(GD[i]);
        }
    }
        
}
void draw_name(int T,int st)
{
    string U = "Created by";
    string my = "CE KMITL 64010522 PARITA NAWAREE";
    string dmy = "";
    int n = ((T - st)%10000) / 150;

    if (n < 32)
    {
        for (int i = 0; i <= n; i++)
        {
            dmy += my[i];
        }
        dmy += "|";
    }
    else dmy = my;

    sf::Text show;
    show.setFont(font);
    show.setCharacterSize(50);
    show.setFillColor(sf::Color::Black);
    show.setString(dmy);
    int w = show.getLocalBounds().width;
    show.setPosition(sf::Vector2f((1152 / 2) - (w / 2), 550));
    window.draw(show);

    sf::Text show2;
    show2.setFont(font);
    show2.setCharacterSize(40);
    show2.setFillColor(sf::Color::Black);
    show2.setString(U);
    w = show2.getLocalBounds().width;
    show2.setPosition(sf::Vector2f((1152 / 2) - (w / 2), 500));
    window.draw(show2);



    /* int w = US_name.getLocalBounds().width;
    US_name.setPosition((1152 / 2) - (w / 2), 325);
    window.draw(US_name);*/


    /*skip.setFont(font);
	skip.setCharacterSize(40);
	skip.setFillColor(sf::Color::Black);
	skip.setString("< press specebar to go back >");
	skip.setPosition(sf::Vector2f(width / 2 - 200, 655));*/
    

}
void show_wait()
{
    for (int i = 0; i < 4; i++)
    {
        window.draw(wait_s[i]);
    }
    sf::Text skip;
    skip.setFont(font);
    skip.setCharacterSize(40);
    skip.setFillColor(sf::Color::Black);
    skip.setString("< press specebar to \" Play \" >");
    skip.setPosition(sf::Vector2f(1152 / 2 - 200, 655));
    window.draw(skip);
}
void save()
{
    FILE* fp;
    char name[100];
    char score[100];
    vector<pair<string, int>> vex;
    fp = fopen("Text.txt", "r+t");


    while (!feof(fp))
    {
        fgets(name, 100, fp);
        fgets(score, 100, fp);
        stringstream geek(score);
        int x = 0;
        geek >> x;
        string ss = "";
        for (int i = 0; i < strlen(name) - 1; i++)
        {
            ss += name[i];
        }

        vex.push_back(make_pair(ss, x));

    }
    fclose(fp);
    if (!vex.empty())
        vex.erase(vex.end() - 1);
    
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += score_[i][j];
        }
    }
    vex.push_back(make_pair(user_name, sum));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (vex[i].second > vex[j].second)
            {
                int x = vex[j].second;
                string ss= vex[j].first;
                vex[j].second = vex[i].second;
                vex[j].first = vex[i].first;
                vex[i].second = x;
                vex[i].first = ss;
            }
        }
    }
    FILE* f;
    f = fopen("Text.txt", "w");
    for (int i = 0; i < 5; i++)
    {
        char ss[100];
        strcpy(ss, vex[i].first.c_str());
        fprintf(f, "%s\n%d\n", ss, vex[i].second);
    }
    fclose(f);
    
    
}