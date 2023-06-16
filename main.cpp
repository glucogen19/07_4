#include <QtWidgets>
#include "tbook.h"

Tbook tbook;

class MainWindow : public QMainWindow {
	public:
		MainWindow();
        void authorB();
        void nameB();
        void countB();
	private:
        QLabel      *aTextLabel;
        QLabel      *nTextLabel;
        QLabel      *cTextLabel;
        QPushButton *aButton;
        QPushButton *nButton;
        QPushButton *cButton;
		
};

MainWindow :: MainWindow(){
    setFixedSize(500,300);
    setWindowTitle("Test QPushButton v7.4");
	QFont fontLabel("Courier", 18, QFont::Normal);
	QFont fontButton("Times", 18, QFont::Bold);
	
    aTextLabel = new QLabel("Автор произведения", this);
    aTextLabel->setGeometry(0, 0, 400, 50);
    aTextLabel->setFont(fontLabel);

    nTextLabel = new QLabel("Название книги", this);
    nTextLabel->setGeometry(0, 50, 400, 50);
    nTextLabel->setFont(fontLabel);
	
    cTextLabel = new QLabel("Количество экземпляров", this);
    cTextLabel->setGeometry(0, 100, 400, 50);
    cTextLabel->setFont(fontLabel);

    aButton = new QPushButton("Author", this);
    aButton->setGeometry(20, 200, 100, 50);
    aButton->setFont(fontButton);
	
    nButton = new QPushButton("Name", this);
    nButton->setGeometry(120, 200, 100, 50);
    nButton->setFont(fontButton);
	
    cButton = new QPushButton("Count", this);
    cButton->setGeometry(220, 200, 100, 50);
    cButton->setFont(fontButton);
	
    connect(aButton, &QPushButton::clicked,
            this, &MainWindow::authorB);
    connect(nButton, &QPushButton::clicked,
            this, &MainWindow::nameB);
    connect(cButton, &QPushButton::clicked,
            this, &MainWindow::countB);
			
}

void MainWindow::authorB(){
    aTextLabel->setText("A = " + tbook.author);
}

void MainWindow::nameB(){
    nTextLabel->setText("N = " + tbook.name);
}

void MainWindow::countB(){
    cTextLabel->setText("C = " + QString::number(tbook.count));
}

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	MainWindow mainWin;
	mainWin.show();
	return app.exec();
	
}
