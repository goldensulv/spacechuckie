// Ball.cpp

#include "Ball.h"
#include "Options.h"

extern my::Player g_Player;

namespace my {

    constexpr float ballRadius{10.f}; 
    constexpr float ballVelocity{8.f};

    Ball::Ball(float a_x, float a_y)
    :    m_velocity{-ballVelocity, -ballVelocity} // c++11 initialization syntax, will give compile time errors
    {
        m_ball.setPosition(a_x, a_y);
        m_ball.setRadius(ballRadius);
        m_ball.setFillColor(sf::Color::Green);
        m_ball.setOrigin(ballRadius, ballRadius);

    }

    void Ball::update()
    {
        m_ball.move(m_velocity);

        if (0 >= left() || windowWidth <= right())
        {
            m_velocity.x *= -1;
        }
        if (0 >= top() || windowHeight <= bottom())
        {
            m_velocity.y *= -1;
        }

        if (my::Collidable::areColliding(*this, g_Player))
        {
            if (y() < g_Player.top())
            {
                m_velocity.x *= -1;
            }
            else
            {
                if (x() < g_Player.x())
                {
                    m_velocity.x -= (g_Player.x() - x()) / (playerWidth / 2) * ballVelocity;
                }
                else if (x() > g_Player.x())
                {
                    m_velocity.x += (x() - g_Player.x()) / (playerWidth / 2) * ballVelocity;
                }
            }
        }
    }

} //end my
