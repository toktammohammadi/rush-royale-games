
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QPainter>
#include "Agent.h"
#include "Enemy.h"
#include "Log.h"

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(int rows, int cols, QWidget *parent = nullptr);

    void addAgent(int x, int y, const Agent &agent);
    void addEnemy(const Enemy &enemy);
    void moveEnemies();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int rows, cols;
    QVector<Agent> agents;
    QVector<QPoint> agentPositions;
    QVector<Enemy> enemies;
};

#endif // BOARD_H
