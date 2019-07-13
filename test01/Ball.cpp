// Ball.cpp

#include "Ball.h"
#include "Options.h"

constexpr float ballRadius{10.f}; 
constexpr float ballVelocity{8.f};

Ball::Ball(float a_x, float a_y)
:    m_velocity{-ballVelocity, -ballVelocity} // c++11 initialization syntax, will give compile time errors
{
    m_ball.setPosition(a_x, a_y);
    m_ball.setRadius(ballRadius);
    m_ball.setFillColor(Color::Green);
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
}