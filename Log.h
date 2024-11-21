#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <iostream>

class Log
{
public:
    // تابعی برای نوشتن پیام‌ها در لاگ
    static void write(const QString &message);
};

#endif // LOG_H
