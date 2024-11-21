
#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Log {
public:
    static Log& getInstance();
    void addEvent(const QString& event);

private:
    Log();
    QFile file;
};

#endif
