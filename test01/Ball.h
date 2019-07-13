// Ball.h
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Ball
{

public:
    Ball(float a_x, float a_y);

    void update();

//  Ease-of-use getters
    float x() { return m_ball.getPosition().x; };
    float y() { return m_ball.getPosition().y; };
    float left() { return x() - m_ball.getRadius(); };
    float right() { return x() + m_ball.getRadius(); };
    float top() { return y() - m_ball.getRadius(); };
    float bottom() { return y() + m_ball.getRadius(); };

// data-members
    CircleShape m_ball;
    Vector2f    m_velocity; // 2d vector

};



#endif /* BALL_H */
