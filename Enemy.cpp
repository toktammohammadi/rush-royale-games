
#include "Enemy.h"

Enemy::Enemy(int health, int speed) : health(health), speed(speed), position(0) {}

void Enemy::move() {
    position += speed;  // حرکت دشمن به جلو
}

bool Enemy::isDead() const {
    return health <= 0;  // بررسی زنده بودن دشمن
}

int Enemy::getPosition() const { return position; }

void Enemy::takeDamage(int damage) {
    health -= damage;  // کاهش سلامتی دشمن
}
