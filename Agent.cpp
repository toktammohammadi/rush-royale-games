#include "Agent.h"

Agent::Agent(const QString &name, int health, int power)
    : name(name), health(health), power(power)
{
    Log::write("Agent created: " + name);
}

QString Agent::getName() const
{
    return name;
}

int Agent::getHealth() const
{
    return health;
}

int Agent::getPower() const
{
    return power;
}

void Agent::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;

    Log::write("Agent " + name + " took " + QString::number(damage) + " damage. Remaining health: " + QString::number(health));
}
