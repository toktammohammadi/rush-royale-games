#include "Log.h"

void Log::write(const QString &message)
{
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString logMessage = QString("[%1] %2").arg(timestamp, message);

    // چاپ در کنسول
    std::cout << logMessage.toStdString() << std::endl;

    // نوشتن در فایل
    QFile file("application.log");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << logMessage << "\n";
        file.close();
    }
}
