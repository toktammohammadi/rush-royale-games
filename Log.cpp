
#include "Log.h"

Log::Log() : file("game_log.txt") {
    file.open(QIODevice::Append | QIODevice::Text);
}

Log& Log::getInstance() {
    static Log instance;
    return instance;
}

void Log::addEvent(const QString& event) {
    if (file.isOpen()) {
        QTextStream out(&file);
        out << event << "\n";
    }
}
