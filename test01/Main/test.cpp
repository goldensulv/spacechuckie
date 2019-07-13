// test.cpp

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Options.h"
#include "Ball.h"
#include "Player.h"


int main()
{
    // create game window
    RenderWindow window{{windowWidth, windowHeight}, "X-Ball"};
    window.setFramerateLimit(60);

    Ball ball{windowWidth / 2, windowHeight / 2};
    Player player;

    while (window.isOpen())
    {
        window.clear(Color::Black);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        ball.update();
        player.update();

        window.draw(ball.m_ball);
        window.draw(player.m_player);
        window.display();
    }

    return 0;
}