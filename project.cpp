#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>

using namespace std;
using namespace sf;


int main(int argc,char **argv)
{
    float playermovementspeed=50;

    RenderWindow window(VideoMode(800,480),"My project");
    window.setFramerateLimit(30);
    Event event;
    Texture texture;
    Texture spritesheet;
    Texture fruiti;

    fruiti.loadFromFile("image/Untitled.png");

    spritesheet.loadFromFile("image/monster-fox.png");

    if(!texture.loadFromFile("image/war.png"))
    {
        cout<<"load failed"<<endl;
        system("pause");
    }

    Sprite sprite(texture);
    Sprite sprite2(texture);
//    Sprite sprite[2];
//    for(int i=0; i<10; i++) fruit[i].setTexture(fruitTexture);
    sprite2.setPosition(-1024,0);
    Sprite sheet(spritesheet);
    Sprite fruitsheet(fruiti);
    fruitsheet.setTextureRect(sf::IntRect(88, 0, 42, 42));

    for(int i=0; i<60; i++)
    {
        sheet.setTextureRect(sf::IntRect(0, 0, 42, 42));
        fruitsheet.setTextureRect(sf::IntRect(42, 42, 42, 42));
        sheet.setPosition(window.getSize().x/2,window.getSize().y/2);
        fruitsheet.setPosition(window.getSize().x,window.getSize().y);
    }

    while(window.isOpen())
    {
        while(window.pollEvent(event))
        {

            if(event.type==Event::EventType::Closed)
                window.close();
            if(Keyboard::isKeyPressed(Keyboard::Up) && sheet.getPosition().y>0)
            {
                sheet.move(0,-playermovementspeed);
                sheet.setTextureRect(sf::IntRect(0, 42*3, 42, 42));
            }

            if(Keyboard::isKeyPressed(Keyboard::Down) && sheet.getPosition().y<350)
            {
                sheet.move(0,playermovementspeed);
                sheet.setTextureRect(sf::IntRect(0, 0, 42, 42));
            }

            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                sheet.move(playermovementspeed,0);
                sheet.setTextureRect(sf::IntRect(0, 42*2, 42, 42));            }

            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                sheet.move(-playermovementspeed,0);
                sheet.setTextureRect(sf::IntRect(0, 42, 42, 42));
            }

        }

        sprite.move(7, 0);
        sprite2.move(7, 0);

        if(sprite.getPosition().x>800) sprite.setPosition(-1024, 0);
        if(sprite2.getPosition().x>800) sprite2.setPosition(-1024, 0);

        if(sheet.getPosition().y < 400) sheet.move(0, 10);

        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sheet);
        window.draw(fruitsheet);
        window.display();

    }
}

