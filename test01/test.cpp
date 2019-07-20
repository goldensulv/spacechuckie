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

    sf::Texture astronaut;
    astronaut.loadFromFile("Assets/astronaut_walking_grey.png");
    sf::Sprite s1(astronaut);
    s1.setScale({0.1,0.1});
    s1.setOrigin(-1, -1);
    s1.setPosition(g_Player.x(), g_Player.top());

    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ball.update();
        g_Player.update();

        window.draw(s1);

        window.draw(ball.m_ball);
        window.draw(g_Player.m_player);
        window.display();
    }

    return 0;
}