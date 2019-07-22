// Player.cpp

#include "Player.h"
#include "Options.h"

namespace my {

    Player::Player()
    :   m_velocity{0, 0}
    ,   m_standing()
    ,   m_jumping()
    ,   m_sStanding()
    ,   m_sJumping()
    ,   m_assVelocity{0, 0}
    ,   m_isJumping(false)
    {
        m_player.setOrigin(playerWidth / 2.f, playerHeight / 2.f);
        m_player.setPosition(windowWidth / 2, windowHeight - playerHeight / 2);
        m_player.setSize({playerWidth, playerHeight});
        m_player.setFillColor(sf::Color::Blue);

        {
            m_standing.loadFromFile("Assets/astronaut_walking_grey.png");
            sf::Vector2u dimentions = m_standing.getSize();

            m_sStanding.setTexture(m_standing);
            m_sStanding.setScale({0.1,0.1});
            m_sStanding.setOrigin(dimentions.x / 2, dimentions.y);
            m_sStanding.setPosition(x(), top());
        }

        {
            m_jumping.loadFromFile("Assets/astronaut_jumping_grey.png");
            sf::Vector2u dimentions = m_jumping.getSize();

            m_sJumping.setTexture(m_jumping);
            m_sJumping.setScale({0.1,0.1});
            m_sJumping.setOrigin(dimentions.x / 2, dimentions.y);
            m_sJumping.setPosition(x(), top());
        }

        m_ass = m_sStanding;

    }

    void Player::update()
    {
        m_player.move(m_velocity);
        m_assVelocity.x = m_velocity.x;
        m_ass.move(m_assVelocity);
        if (m_isJumping && m_ass.getPosition().y >= top())
        {
            m_ass = m_sStanding;
            m_ass.setPosition(x(), top());
            m_assVelocity.y = 0;
            m_isJumping = false;
        }
        m_velocity.x = 0;

        if (m_isJumping)
        {
            m_assVelocity.y += gravity;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && 0 < left())
        {
            m_velocity.x = -playerVelocity;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && windowWidth > right())
        {
            m_velocity.x = playerVelocity;
        }

        if (!m_isJumping && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        {
            m_ass = m_sJumping;
            m_assVelocity.y = -20;

            m_isJumping = true;
        }
    }

} // end my
