// Ball.h
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

#include "Collidable.h"
#include "Shape.h"

namespace my {

    class Ball : public Shape, public Collidable
    {

    public:
        Ball(float a_x, float a_y);

        void update();

    //  Ease-of-use getters
        float x() const { return m_ball.getPosition().x; };
        float y() const { return m_ball.getPosition().y; };
        float left() const { return x() - m_ball.getRadius(); };
        float right() const { return x() + m_ball.getRadius(); };
        float top() const { return y() - m_ball.getRadius(); };
        float bottom() const { return y() + m_ball.getRadius(); };

    // data-members
        sf::CircleShape m_ball;
        sf::Vector2f    m_velocity; // 2d vector

        sf::Texture     m_elon;

    };

} //end my




#endif /* BALL_H */
