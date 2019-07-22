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
        window.draw(g_Player.m_player);
        window.draw(g_Player.m_ass);

        window.draw(ball.m_ball);
        window.display();
    }

    return 0;
}