// Board.cpp
#include "Board.h"

Board::Board(int rows, int columns) : rows(rows), columns(columns) {
    agents.resize(rows, std::vector<Agent>(columns, Agent("", 0, 0)));
}

void Board::addAgent(int row, int col, const Agent& agent) {
    if (row >= 0 && row < rows && col >= 0 && col < columns) {
        agents[row][col] = agent;
        Log::getInstance().addEvent("Agent added at (" + QString::number(row) + ", " + QString::number(col) + ")");
    }
}

void Board::addEnemy(const Enemy& enemy) {
    enemies.push_back(enemy);
    Log::getInstance().addEvent("Enemy added to the game.");
}

void Board::moveEnemies() {
    for (auto& enemy : enemies) {
        enemy.move();
        Log::getInstance().addEvent("Enemy moved to position " + QString::number(enemy.getPosition()));
    }
}

void Board::checkEnemies() {
    auto it = enemies.begin();
    while (it != enemies.end()) {
        if (it->isDead()) {
            Log::getInstance().addEvent("Enemy at position " + QString::number(it->getPosition()) + " defeated.");
            it = enemies.erase(it);
        } else {
            ++it;
        }
    }
}

void Board::upgradeAgent(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < columns) {
        agents[row][col].upgrade();
        Log::getInstance().addEvent("Agent at (" + QString::number(row) + ", " + QString::number(col) + ") upgraded to power " +
                                    QString::number(agents[row][col].getPower()));
    }
}
