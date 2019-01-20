#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<windows.h>
#include<iostream>
#include<bits/stdc++.h>
#include<fstream>

using namespace std;
using namespace sf;

Color notSelected(255,255,255),done(255,255,0);

int main(int argc,char **argv)
{
    float playermovementspeed=50;
    float time=0.0f;
    Clock clock;
    int score=0,highscore;
    static bool Gameover;
    bool over=false;

    RenderWindow window(VideoMode(800,480),"Greedy Fox");

    window.setFramerateLimit(30);
    Event event;
    Texture texture;
    Texture spritesheet;
    Texture fruiti;
    Texture Bar;
    Texture gameover;
    Texture game_front;
    Texture gamesound;
    Texture screenfox,Highscore;

    SoundBuffer buffer;

    if(!buffer.loadFromFile("audio/beep sound.wav")){
        cout<<"Error"<<endl;
    }

    Music music;
    Sound sound;
    music.openFromFile("audio/gamesound.ogg");
    music.play();
    music.setVolume(20);
    sound.setBuffer(buffer);
    sound.setVolume(80);
    music.setLoop(true);

    ///score system///
    Font font,style1,style2,style3;
    Text lblscore,newgametxt,highscoretxt,optiontxt,exittxt,gametxt,notetxt,gameovertxt,
         gameovertxt1,gameovertxt2,scoretxt,bestscoretxt,bestscoretxt1,instructiontxt,instructiontxt1,instructiontxt2,instructiontxt3,instructiontxt4;

    font.loadFromFile("BELL.ttf");
    ostringstream ssScore;
    ostringstream ssScore2;
    ssScore << "Score "<< score;
    ssScore2 << "Game Over";

    style1.loadFromFile("BELL.ttf");
    gametxt.setFont(style1);
    gametxt.setString("Greedy Fox!");
    gametxt.setCharacterSize(80);
    gametxt.setScale(1.f,1.f);
    gametxt.setFillColor(Color::Black);

    style2.loadFromFile("BELL.ttf");
    newgametxt.setFont(style2);
    newgametxt.setString("New Game ");
    newgametxt.setCharacterSize(80);
    newgametxt.setScale(0.5f,0.5f);
    newgametxt.setFillColor(notSelected);

    highscoretxt.setFont(style2);
    highscoretxt.setString("Highscore ");
    highscoretxt.setCharacterSize(80);
    highscoretxt.setScale(0.5f,0.5f);
    highscoretxt.setFillColor(notSelected);

    optiontxt.setFont(style2);
    optiontxt.setString("Instruction ");
    optiontxt.setCharacterSize(80);
    optiontxt.setScale(0.5f,0.5f);
    optiontxt.setFillColor(notSelected);

    exittxt.setFont(style2);
    exittxt.setString("Exit ");
    exittxt.setCharacterSize(80);
    exittxt.setScale(0.5f,0.5f);
    exittxt.setFillColor(notSelected);

    notetxt.setFont(style1);
    notetxt.setString("#Please Press Enter To Select#");
    notetxt.setCharacterSize(50);
    notetxt.setScale(0.5f,0.5f);
    notetxt.setFillColor(Color::Green);

    gameovertxt.setFont(style2);
    gameovertxt.setString("GAME OVER! ");
    gameovertxt.setCharacterSize(100);
    gameovertxt.setScale(0.7f,0.7f);
    gameovertxt.setFillColor(Color::Black);

    gameovertxt1.setFont(style2);
    gameovertxt1.setString("Graps Are Sour!!! ");
    gameovertxt1.setCharacterSize(70);
    gameovertxt1.setScale(0.7f,0.7f);
    gameovertxt1.setPosition(220,220);
    gameovertxt1.setFillColor(Color::Red);

    gameovertxt2.setFont(style2);
    gameovertxt2.setString("Score: ");
    gameovertxt2.setCharacterSize(50);
    gameovertxt2.setScale(0.7f,0.7f);
    gameovertxt2.setPosition(250,150);
    gameovertxt2.setFillColor(Color::Blue);

    bestscoretxt.setFont(style2);
    bestscoretxt.setString("HighScore: ");
    bestscoretxt.setCharacterSize(50);
    bestscoretxt.setScale(0.7f,0.7f);
    bestscoretxt.setPosition(260,180);
    bestscoretxt.setFillColor(Color::Black);

    instructiontxt.setFont(style2);
    instructiontxt.setString("Left Arrow->Left Moves");
    instructiontxt.setCharacterSize(50);
    instructiontxt.setScale(0.7f,0.7f);
    instructiontxt.setPosition(240,180);
    instructiontxt.setFillColor(Color::White);

    instructiontxt1.setFont(style2);
    instructiontxt1.setString("Right Arrow->Right Moves");
    instructiontxt1.setCharacterSize(50);
    instructiontxt1.setScale(0.7f,0.7f);
    instructiontxt1.setPosition(240,220);
    instructiontxt1.setFillColor(Color::White);

    instructiontxt2.setFont(style2);
    instructiontxt2.setString("Up Arrow->Up Moves");
    instructiontxt2.setCharacterSize(50);
    instructiontxt2.setScale(0.7f,0.7f);
    instructiontxt2.setPosition(240,260);
    instructiontxt2.setFillColor(Color::White);

    instructiontxt3.setFont(style2);
    instructiontxt3.setString("Down Arrow->Down Moves");
    instructiontxt3.setCharacterSize(50);
    instructiontxt3.setScale(0.7f,0.7f);
    instructiontxt3.setPosition(240,300);
    instructiontxt3.setFillColor(Color::White);

    instructiontxt4.setFont(style2);
    instructiontxt4.setString("Space->For Back");
    instructiontxt4.setCharacterSize(50);
    instructiontxt4.setScale(0.7f,0.7f);
    instructiontxt4.setPosition(240,140);
    instructiontxt4.setFillColor(Color::White);

    lblscore.setCharacterSize(40);
    lblscore.setFillColor(::Color::Red);
    lblscore.setPosition(0,0);
    lblscore.setFont(font);
    lblscore.setString(ssScore.str());

    Text lblscore2;
    lblscore2.setCharacterSize(50);
    lblscore2.setFillColor(::Color::Red);
    lblscore2.setPosition(300,300);
    lblscore2.setFont(font);


    ///image system///
    fruiti.loadFromFile("image/frutikaa.png");

    spritesheet.loadFromFile("image/monster-fox.png");

    Bar.loadFromFile("image/baar.png");

    game_front.loadFromFile("image/gamedeath.png");

    screenfox.loadFromFile("image/screenfox.png");

    Highscore.loadFromFile("image/highscore.png");

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
    Sprite BAR2(Bar);
    Sprite BAR3(Bar);
    Sprite GameOver(gameover);
    Sprite game_death(game_front);
    Sprite Fox(screenfox);
    Sprite highscorebackround(Highscore);

    sheet.setScale(::Vector2f(1.8f,1.8f));
    BAR.setScale(Vector2f(1.0f,1.0f));

    window.setKeyRepeatEnabled(true);

    for(int i=0; i<60; i++)
    {
        sheet.setTextureRect(sf::IntRect(0, 0, 42, 42));
        fruitsheet.setTextureRect(sf::IntRect(42, 42, 42, 42));
        sheet.setPosition(window.getSize().x/2,window.getSize().y/2);
        fruitsheet.setPosition(window.getSize().x,window.getSize().y);
    }

    bool menu=true,game=false, gamedeath=false,showhighscore=false,newgame=false;

    int menuselect=1;

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

        if(menu)
        {
            gametxt.setPosition(20.f,3.f);
            newgametxt.setPosition(500.f,100.f);
            highscoretxt.setPosition(500.f,180.f);
            optiontxt.setPosition(500.f,260.f);
            exittxt.setPosition(500.f,330.f);
            notetxt.setPosition(400.f,440.f);
            Fox.setTextureRect(sf::IntRect(10, 120, 230, 160));
            Fox.setScale(::Vector2f(1.5f,1.5f));
            Fox.setPosition(30,140);

            window.clear();
            game_death.setScale(1.f,1.f);

            window.draw(game_death);
            window.draw(gametxt);
            window.draw(newgametxt);
            window.draw(highscoretxt);
            window.draw(optiontxt);
            window.draw(exittxt);
            window.draw(notetxt);
            window.draw(Fox);
            window.display();
            time=clock.getElapsedTime().asSeconds();

            if(Keyboard::isKeyPressed(Keyboard::Down) && time > 0.2)
            {
                // sound.play();
                menuselect++;
                clock.restart();
            }
            if(Keyboard::isKeyPressed(Keyboard::Up) && time > 0.2)
            {
                //sound.play();
                menuselect--;
                clock.restart();
            }
        }

        if(menuselect%4==1)
        {
            newgametxt.setFillColor(done);
            highscoretxt.setFillColor(notSelected);
            optiontxt.setFillColor(notSelected);
            exittxt.setFillColor(notSelected);

            if(Keyboard::isKeyPressed(Keyboard::Enter) && game==false)
            {
                game=true;
                gamedeath=false;
                menu=false;
            }
        }
        else if(menuselect%4==2)
        {
            highscoretxt.setFillColor(done);
            optiontxt.setFillColor(notSelected);
            exittxt.setFillColor(notSelected);
            newgametxt.setFillColor(notSelected);

            if(Keyboard::isKeyPressed(Keyboard::Enter) && game==false)
            {
                game=false;
                gamedeath=false;
                menu=false;
                showhighscore=true;

            }

                if(Keyboard::isKeyPressed(Keyboard::Space))
                {
                    menu=true;
                    gamedeath=false;
                    game=false;
                    showhighscore=false;
                }

        }
        else if(menuselect%4==3)
        {
            optiontxt.setFillColor(done);
            exittxt.setFillColor(notSelected);
            newgametxt.setFillColor(notSelected);
            highscoretxt.setFillColor(notSelected);

            if(Keyboard::isKeyPressed(Keyboard::Enter) && game==false)
            {
                game=false;
                gamedeath=false;
                menu=false;
                showhighscore=false;

                window.draw(highscorebackround);
                window.draw(instructiontxt);
                window.draw(instructiontxt1);
                window.draw(instructiontxt2);
                window.draw(instructiontxt3);
                window.draw(instructiontxt4);
                window.display();
            }
            if(Keyboard::isKeyPressed(Keyboard::Space)){
                game=false;
                gamedeath=false;
                menu=true;
            }
        }
        else if(menuselect%4==0)
        {
            exittxt.setFillColor(done);
            newgametxt.setFillColor(notSelected);
            highscoretxt.setFillColor(notSelected);
            optiontxt.setFillColor(notSelected);


            if(Keyboard::isKeyPressed(Keyboard::Enter))
            {
                return 0;
            }
        }

        if(game)
        {
            if(Keyboard::isKeyPressed(Keyboard::Enter) && game==false)
            {
                game=false;
                gamedeath=false;
                menu=true;
            }

            ///sprite move///

            sprite.move(7, 0);
            sprite2.move(7, 0);

            frutika.move(5, 0);
            frutika2.move(5, 0);
            frutika3.move(5, 0);
            frutika4.move(5, 0);

            BAR.move(3,0);
            BAR2.move(4,0);

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

            if(BAR2.getPosition().x>800)
            BAR2.setPosition(-1024, 0);

             if(BAR3.getPosition().x>800)
            BAR3.setPosition(-1024, 0);

            ///gravity variables///
            if(sheet.getPosition().y < 400)
                sheet.move(0, 10);
            ///

            if(BAR.getPosition().x<800)
            {
                BAR.move(5,0);
                BAR.setTextureRect(sf::IntRect(40, 70, 60, 60));
            }
            BAR2.move(5,0);
            BAR2.setTextureRect(sf::IntRect(150, 160, 60, 80));

            //BAR3.move(5,0);
            //BAR3.setTextureRect(sf::IntRect(200, 300, 50, 20));

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
                frutika3.move(6,0);
                frutika3.setTextureRect(sf::IntRect(65, 77, 38, 35));
            }
            if(frutika4.getPosition().x<100)
            {
                frutika4.move(5,0);
                frutika4.setTextureRect(sf::IntRect(0, 0, 0, 0));
            }


            ///fruit logic///

            if(sheet.getGlobalBounds().intersects(frutika.getGlobalBounds()))
            {
                sound.play();
                score++;
                frutika.setPosition(422235,452263);
                ssScore.str("");
                ssScore<< "Score" <<" "<<score;
                lblscore.setString(ssScore.str());

            }

            if(sheet.getGlobalBounds().intersects(frutika2.getGlobalBounds()))
            {
                sound.play();
                score++;
                frutika2.setPosition(422235,452263);
                ssScore.str("");
                ssScore<< "Score" <<" "<< score;
                lblscore.setString(ssScore.str());

            }

            if(sheet.getGlobalBounds().intersects(frutika3.getGlobalBounds()))
            {
                sound.play();
                score++;
                frutika3.setPosition(422235,452263);
                ssScore.str("");
                ssScore<< "Score" <<" "<< score;
                lblscore.setString(ssScore.str());

            }

            if(sheet.getGlobalBounds().intersects(BAR.getGlobalBounds()))
            {
                over=true;
                gamedeath=true;
            }

            if(sheet.getGlobalBounds().intersects(BAR2.getGlobalBounds()))
            {
                over=true;
                gamedeath=true;
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
            window.draw(lblscore2);
            window.draw(BAR);
            window.draw(BAR2);
           // window.draw(BAR3);
            window.draw(GameOver);
            window.display();

        }

        if(showhighscore)
        {
            menu=false;
            gamedeath=false;
            game=false;

            scoretxt.setFont(style2);
            scoretxt.setString(to_string(score));
            scoretxt.setCharacterSize(50);
            scoretxt.setScale(0.7f,0.7f);
            scoretxt.setPosition(350,150);
            scoretxt.setFillColor(Color::Blue);

            ifstream readfile;
            readfile.open("Highscore.txt");
            if(readfile.is_open())
            {
                while(!readfile.eof())
                {
                    readfile>>highscore;
                }
            }
            readfile.close();

            ofstream writefile("Highscore.txt");
            if(writefile.is_open())
            {
                if(score>highscore)
                {
                    highscore=score;
                }
                writefile<<highscore;
            }
            writefile.close();

            bestscoretxt1.setFont(style2);
            bestscoretxt1.setString(to_string(highscore));
            bestscoretxt1.setCharacterSize(50);
            bestscoretxt1.setScale(0.7f,0.7f);
            bestscoretxt1.setPosition(440,180);
            bestscoretxt1.setFillColor(Color::Black);

            window.draw(highscorebackround);
            window.draw(bestscoretxt);
            window.draw(bestscoretxt1);
            window.display();

        }

        if(gamedeath)
        {
            game=false;
            menu=false;

            //GameSound.stop();
            gameovertxt.setPosition(13.f,2.f);
            scoretxt.setFont(style2);
            scoretxt.setString(to_string(score));
            scoretxt.setCharacterSize(50);
            scoretxt.setScale(0.7f,0.7f);
            scoretxt.setPosition(350,150);
            scoretxt.setFillColor(Color::Blue);

            ifstream readfile;
            readfile.open("Highscore.txt");
            if(readfile.is_open())
            {
                while(!readfile.eof())
                {
                    readfile>>highscore;
                }
            }
            readfile.close();

            ofstream writefile("Highscore.txt");
            if(writefile.is_open())
            {
                if(score>highscore)
                {
                    highscore=score;
                }
                writefile<<highscore;
            }
            writefile.close();

            bestscoretxt1.setFont(style2);
            bestscoretxt1.setString(to_string(highscore));
            bestscoretxt1.setCharacterSize(50);
            bestscoretxt1.setScale(0.7f,0.7f);
            bestscoretxt1.setPosition(280,180);
            bestscoretxt1.setFillColor(Color::Blue);


            window.draw(game_death);
            window.draw(gameovertxt);
            window.draw(gameovertxt1);
            window.draw(gameovertxt2);
            window.draw(scoretxt);

            window.display();
            if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                menu=true;
                gamedeath=false;
            }
        }
    }
    return 0;
}




