
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy(int health = 100, int speed = 1);
    void move();
    bool isDead() const;
    int getPosition() const;
    void takeDamage(int damage);

private:
    int health;
    int speed;
    int position;
};

#endif
