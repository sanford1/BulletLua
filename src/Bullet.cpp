#include <bulletlua/Bullet.hpp>

#include <bulletlua/Utils/Math.hpp>
#include <cfloat>

Bullet::Bullet(float x, float y, float vx, float vy)
    : position{x - 2.0f, y - 2.0f, 4.0f, 4.0f}, // TODO: Un-hard-code bullet metrics.
      vx{vx}, vy{vy},
      dead{true},
      r{255}, g{255}, b{255},
      dying{true}, life{0}, turn{0}, collisionCheck{false}
{
    fixSpeed();
}

void Bullet::setPosition(float cx, float cy)
{
    position.setCenter(cx, cy);
}

void Bullet::setVelocity(float nvx, float nvy)
{
    vx = nvx;
    vy = nvy;
}

void Bullet::setSpeedAndDirection(float speed, float dir)
{
    vx = speed * std::sin(dir);
    vy = -speed * std::cos(dir);

    fixSpeed();
}

void Bullet::setSpeed(float speed)
{
    float mag = getSpeed();

    vx = (vx * speed) / mag;
    vy = (vy * speed) / mag;

    fixSpeed();
}

void Bullet::setSpeedRelative(float speed)
{
    float mag = getSpeed();

    vx = (vx * (speed + mag)) / mag;
    vy = (vy * (speed + mag)) / mag;

    fixSpeed();
}

float Bullet::getSpeed() const
{
    return std::sqrt(vx * vx + vy * vy);
}


void Bullet::setDirection(float dir)
{
    float speed = getSpeed();
    vx = speed * std::sin(dir);
    vy = -speed * std::cos(dir);
}


void Bullet::setDirectionRelative(float dir)
{
    setDirection(dir + getDirection());
}


void Bullet::aimAtPoint(float tx, float ty)
{
    // TODO: use getDirectionAim
    setDirection(Math::PI -
                 std::atan2(tx - position.x,
                            ty - position.y));
}

float Bullet::getAimDirection(float tx, float ty)
{
    return Math::PI - std::atan2(tx - position.x, ty - position.y);
}


float Bullet::getDirection() const
{
    return Math::PI - std::atan2(vx, vy);
}


void Bullet::vanish()
{
    dying = true;
}


void Bullet::kill()
{
    dead = true;
}


bool Bullet::isDead() const
{
    return dead;
}


bool Bullet::isDying() const
{
    return dying;
}


int Bullet::getTurn() const
{
    return turn;
}


void Bullet::setColor(unsigned char newR, unsigned char newG, unsigned char newB)
{
    r = newR;
    g = newG;
    b = newB;
}

void Bullet::update()
{
    position.x += vx;
    position.y += vy;
}

void Bullet::fixSpeed()
{
    // See https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
    // Setting direction (alone) is dependent on components, so if speed is set to 0.0f,
    // setting a direction will not do anything.
    if (std::abs(vy) < FLT_EPSILON)
    {
        vy = FLT_EPSILON;
    }
}
