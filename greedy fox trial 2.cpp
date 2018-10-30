#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using namespace sf;


int main(int argc,char **argv)
{
    float playermovementspeed=50;
    int score=0;

    RenderWindow window(VideoMode(800,480),"My project");
    window.setFramerateLimit(30);
    Event event;
    Texture texture;
    Texture spritesheet;
    Texture fruiti;
    Texture Bar;

    Clock clock;

    ///score system///
    Font font;
    font.loadFromFile("BELL.ttf");
    ostringstream ssScore;
    ssScore << "score "<< score;

    Text lblscore;
    lblscore.setCharacterSize(40);
    lblscore.setFillColor(::Color::Red);
    lblscore.setPosition(0,0);
    lblscore.setFont(font);
    lblscore.setString(ssScore.str());

    ///image system///
    fruiti.loadFromFile("image/frutika.png");

    spritesheet.loadFromFile("image/monster-fox.png");

    Bar.loadFromFile("image/bar.png");

    if(!texture.loadFromFile("image/war.png"))
    {
        cout<<"load failed"<<endl;
        system("pause");
    }

    ///Sprite system///
    Sprite sprite(texture);
    Sprite sprite2(texture);

    sprite2.setPosition(-1024,0);
    Sprite sheet(spritesheet);
    Sprite fruitsheet(fruiti);
    Sprite frutika(fruiti);
    Sprite frutika2(fruiti);
    Sprite frutika3(fruiti);
    Sprite frutika4(fruiti);
    Sprite BAR(Bar);

    for(int i=0; i<60; i++)
    {
        sheet.setTextureRect(sf::IntRect(0, 0, 42, 42));
        fruitsheet.setTextureRect(sf::IntRect(42, 42, 42, 42));
        sheet.setPosition(window.getSize().x/2,window.getSize().y/2);
        fruitsheet.setPosition(window.getSize().x,window.getSize().y);
    }

    ///main loop///
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
                sheet.setTextureRect(sf::IntRect(0, 42*2, 42, 42));
            }

            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                sheet.move(-playermovementspeed,0);
                sheet.setTextureRect(sf::IntRect(0, 42, 42, 42));
            }

        }
        ///sprite move///

        sprite.move(7, 0);
        sprite2.move(7, 0);

        frutika.move(7, 0);
        frutika2.move(7, 0);
         frutika3.move(7, 0);
        frutika4.move(7, 0);

        BAR.move(5,0);


        if(sprite.getPosition().x>800)
            sprite.setPosition(-1024, 0);
        if(sprite2.getPosition().x>800)
            sprite2.setPosition(-1024, 0);

            if(frutika.getPosition().x>800)
            frutika.setPosition(-1024, 0);
        if(frutika2.getPosition().x>800)
            frutika2.setPosition(-1024, 0);

             if(frutika3.getPosition().x>800)
            frutika3.setPosition(-1024, 0);
        if(frutika4.getPosition().x>800)
            frutika4.setPosition(-1024, 0);

            if(BAR.getPosition().x>800)
            BAR.setPosition(-1024, 0);


    ///gravity variables///
        if(sheet.getPosition().y < 400)
            sheet.move(0, 10);
            ///

            if(BAR.getPosition().x<800){
                BAR.move(5,0);
               BAR.setTextureRect(sf::IntRect(40, 70, 60, 60));
            }

        if(frutika.getPosition().x<800)
        {
            frutika.move(5,0);
           frutika.setTextureRect(sf::IntRect(42, 42, 42, 42));
        }

        if(frutika2.getPosition().x<100)
        {
            frutika2.move(5,0);
            frutika2.setTextureRect(sf::IntRect(10, 10, 42, 42));
        }
         if(frutika3.getPosition().x<800)
        {
            frutika3.move(5,0);
            frutika3.setTextureRect(sf::IntRect(0, 0, 0, 0));
        }
         if(frutika4.getPosition().x<100)
        {
            frutika4.move(5,0);
            frutika4.setTextureRect(sf::IntRect(0, 0, 0, 0));
        }

       ///fruit logic///


       if(sheet.getGlobalBounds().intersects(frutika.getGlobalBounds())){
            cout<<"collision"<<endl;
            score++;
            ssScore.str("");
            ssScore<< "score" <<score;
             lblscore.setString(ssScore.str());

       }

       if(sheet.getGlobalBounds().intersects(frutika2.getGlobalBounds())){
            cout<<"collision"<<endl;
            score++;
            ssScore.str("");
            ssScore<< "score" <<score;
            lblscore.setString(ssScore.str());

       }

        ///draw///

        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sheet);
        window.draw(fruitsheet);
        window.draw(frutika);
        window.draw(frutika2);
        window.draw(frutika3);
        window.draw(frutika4);
        window.draw(lblscore);
        window.draw(BAR);
        window.display();

    }
}


