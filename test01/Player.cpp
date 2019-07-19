// Player.cpp

#include "Player.h"
#include "Options.h"

namespace my {

    Player::Player()
    :    m_velocity{0, 0}
    {
        m_player.setPosition(windowWidth / 2, windowHeight - playerHeight / 2);
        m_player.setSize({playerWidth, playerHeight});
        m_player.setFillColor(sf::Color::Blue);
        m_player.setOrigin(playerWidth / 2.f, playerHeight / 2.f);

    }

    void Player::update()
    {
        m_player.move(m_velocity);
        m_velocity.x = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && 0 < left())
        {
            m_velocity.x = -playerVelocity;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && windowWidth > right())
        {
            m_velocity.x = playerVelocity;
        }
    }

} // end my


