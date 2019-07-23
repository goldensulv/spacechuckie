// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "Collidable.h"
#include "Shape.h"

namespace my {

    constexpr float playerWidth{80.f};
    constexpr float playerHeight{20.f};
    constexpr float playerVelocity{12.f};

    constexpr float gravity{0.7f};

    class Player : public Shape, public Collidable
    {

    public:
        Player();

        void update();

    // ease-of-use getters
        float x() const { return m_player.getPosition().x; } ;
        float y() const { return m_player.getPosition().y; } ;
        float left() const { return x() - playerWidth / 2.f; } ;
        float right() const { return x() + playerWidth / 2.f; } ;
        float top() const { return y() - playerHeight / 2.f; } ;
        float bottom() const { return y() + playerHeight / 2.f; };

    // data-members
        sf::RectangleShape  m_player;    
        sf::Vector2f        m_velocity;

        sf::Image           m_stand;

        sf::Texture         m_standing;
        sf::Texture         m_jumping;
        sf::Sprite          m_sStanding;
        sf::Sprite          m_sJumping;
        sf::Sprite          m_ass;

        sf::Vector2f        m_assVelocity;
        bool                m_isJumping;
        bool                m_lookingRight;
    };

} //end my




#endif /* PLAYER_H */
