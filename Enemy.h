#ifndef ENEMY_H
#define ENEMY_H

#include <QPoint>
#include "log.h"


class Enemy
{
public:
    Enemy(int health, int speed);

    int getHealth() const;
    int getSpeed() const;
    QPoint getPosition() const;

    void move();
    void takeDamage(int damage);
    friend class Board;

private:
    int health;
    int speed;
    QPoint position;
};

#endif // ENEMY_H
