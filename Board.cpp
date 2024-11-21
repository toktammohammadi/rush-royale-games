#include "Board.h"

Board::Board(int rows, int cols, QWidget *parent)
    : QWidget(parent), rows(rows), cols(cols)
{
    Log::write("Board created with size: " + QString::number(rows) + "x" + QString::number(cols));
}

void Board::addAgent(int x, int y, const Agent &agent)
{
    agents.push_back(agent);
    agentPositions.push_back(QPoint(x, y));
    Log::write(QString("Agent added at position (%1, %2)").arg(x).arg(y));
    update();
}

void Board::addEnemy(const Enemy &enemy)
{
    enemies.push_back(enemy);
    Log::write("Enemy added with initial position (0, 0)");
    update();
}

void Board::moveEnemies()
{
    Log::write("Moving enemies...");
    for (auto &enemy : enemies) {
        enemy.move();
        Log::write("Enemy moved to position: " + QString("(%1, %2)")
                                                     .arg(enemy.getPosition().x())
                                                     .arg(enemy.getPosition().y()));
    }
    update();
}

void Board::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int cellWidth = width() / cols;
    int cellHeight = height() / rows;

    // رسم شبکه
    painter.setPen(Qt::black);
    for (int i = 0; i <= cols; ++i) {
        painter.drawLine(i * cellWidth, 0, i * cellWidth, height());
    }
    for (int i = 0; i <= rows; ++i) {
        painter.drawLine(0, i * cellHeight, width(), i * cellHeight);
    }

    // رسم Agentها
    painter.setBrush(Qt::blue);
    for (size_t i = 0; i < agents.size(); ++i) {
        int x = agentPositions[i].x();
        int y = agentPositions[i].y();
        painter.drawEllipse(x * cellWidth, y * cellHeight, cellWidth, cellHeight);
    }

    // رسم Enemyها
    painter.setBrush(Qt::red);
    for (const auto &enemy : enemies) {
        int x = enemy.getPosition().x();
        int y = enemy.getPosition().y();
        painter.drawRect(x * cellWidth, y * cellHeight, cellWidth, cellHeight);
    }
}
