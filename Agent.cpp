
#include "Agent.h"

Agent::Agent(QString name, int power, int speed) : name(name), power(power), speed(speed) {}

void Agent::upgrade() {
    power += 10;  // افزایش قدرت هنگام ارتقا
}

int Agent::getPower() const { return power; }
int Agent::getSpeed() const { return speed; }
QString Agent::getName() const { return name; }
