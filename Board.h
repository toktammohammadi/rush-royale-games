
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Agent.h"
#include "Enemy.h"
#include "Log.h"

class Board {
public:
    Board(int rows, int columns);
    void addAgent(int row, int col, const Agent& agent);
    void addEnemy(const Enemy& enemy);
    void moveEnemies();
    void checkEnemies();
    void upgradeAgent(int row, int col);

private:
    int rows;
    int columns;
    std::vector<std::vector<Agent>> agents;
    std::vector<Enemy> enemies;
};

#endif
