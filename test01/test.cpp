// test.cpp

#include <SFML/Graphics.hpp>

#include "Options.h"
#include "Ball.h"
#include "Player.h"

my::Player g_Player;


int main()
{
    // create game window
    sf::RenderWindow window{{windowWidth, windowHeight}, "X-Ball"};
    window.setFramerateLimit(60);

    my::Ball ball{windowWidth / 2, windowHeight / 2};

    sf::Image background;
    background.loadFromFile("Assets/round_background.jpeg");


    sf::Texture back;
    back.loadFromImage(background);

    sf::Sprite b;
    b.setTexture(back);

    b.scale(1.5, 1.5);

    sf::Vector2f a = (sf::Vector2f)background.getSize();
    a.x /= 2;
    a.y /= 2; 
    b.setOrigin(a);
    // sf::Rect<int> background(0, 0, windowWidth, windowHeight);

    while (window.isOpen())
    {
        b.rotate(-0.02);
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(b);
        ball.update();

        g_Player.update();
        window.draw(g_Player.m_player);
        window.draw(g_Player.m_ass);

        window.draw(ball.m_ball);
        window.display();
    }

    return 0;
}