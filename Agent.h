
#ifndef AGENT_H
#define AGENT_H

#include <QString>

class Agent {
public:
    Agent(QString name = "", int power = 0, int speed = 0);
    void upgrade();
    int getPower() const;
    int getSpeed() const;
    QString getName() const;

private:
    QString name;
    int power;
    int speed;
};

#endif
