#include "Enemy.h"

Enemy::Enemy(int health, int speed)
    : health(health), speed(speed), position(0, 0)
{
    Log::write("Enemy created with health: " + QString::number(health) + " and speed: " + QString::number(speed));
}

int Enemy::getHealth() const
{
    return health;
}

int Enemy::getSpeed() const
{
    return speed;
}

QPoint Enemy::getPosition() const
{
    return position;
}

void Enemy::move()
{
    position += QPoint(speed, 0);
    Log::write("Enemy moved to position: (" + QString::number(position.x()) + ", " + QString::number(position.y()) + ")");
}

void Enemy::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;

    Log::write("Enemy took " + QString::number(damage) + " damage. Remaining health: " + QString::number(health));
}
