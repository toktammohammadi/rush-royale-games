#include "MainWindow.h"
#include <QVBoxLayout>
#include <QDir>
#include <QFile>
#include <QPixmap>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    stackedWidget = new QStackedWidget(this);

    // صفحه اول
    mainPage = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainPage);

    // متن خوش‌آمدگویی
    QLabel *welcomeLabel = new QLabel("Welcome to rushroyal", mainPage);
    QFont font("Arial", 24, QFont::Bold);
    welcomeLabel->setFont(font);
    welcomeLabel->setAlignment(Qt::AlignCenter);

    // تصویر زمینه
    backgroundLabel = new QLabel(mainPage);
    QString imagePath = QStringLiteral ("C:\\Users\\98915\\Desktop\\t.jpg");
    if (QFile::exists(imagePath)) {
        backgroundLabel->setPixmap(QPixmap(imagePath));
    } else {
        backgroundLabel->setText("Image not found: " + imagePath);
    }
    backgroundLabel->setScaledContents(true);

    // دکمه استارت
    startpushButton = new QPushButton("Start", mainPage);
    startpushButton->setObjectName("startpushButton");
    startpushButton->setStyleSheet("font-size: 18px; padding: 10px;");
    connect(startpushButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);

    mainLayout->addWidget(welcomeLabel);
    mainLayout->addWidget(backgroundLabel);
    mainLayout->addWidget(startpushButton);
    mainPage->setLayout(mainLayout);

    // صفحه دوم
    secondPage = new QWidget(this);
    QLabel *secondLabel = new QLabel("This is the second page", secondPage);
    QVBoxLayout *secondLayout = new QVBoxLayout(secondPage);
    board = new Board(6, 5, secondPage);
    secondLayout->addWidget(secondLabel);
    secondPage->setLayout(secondLayout);

    // افزودن صفحات به QStackedWidget
    stackedWidget->addWidget(mainPage);
    stackedWidget->addWidget(secondPage);

    setCentralWidget(stackedWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::onStartButtonClicked()
{
    stackedWidget->setCurrentWidget(secondPage); // رفتن به صفحه دوم
    board = new Board(6, 5);
    board->addAgent(2, 3, Agent("Defender", 10, 5));
    board->addEnemy(Enemy(100, 1));
    board->moveEnemies();
}
