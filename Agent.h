#ifndef AGENT_H
#define AGENT_H

#include <QString>
#include "log.h"

class Agent
{
public:
    Agent(const QString &name, int health, int power);

    QString getName() const;
    int getHealth() const;
    int getPower() const;

    void takeDamage(int damage);

private:
    QString name;
    int health;
    int power;
};

#endif // AGENT_H
