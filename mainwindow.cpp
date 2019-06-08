#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
QImage *im;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    im=new QImage(700,600,QImage::Format_ARGB32_Premultiplied); //УСТАНОВКА ПАРАМЕТРОВ ЭКРАНА
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*event) //ВЫЗЫВАЕТСЯ ПРИ ПЕРИСОВКИ ОКНА
{
    QPainter painter(this);
    painter.drawImage(0,0,*im);
    im->fill(0);
}


void MainWindow::on_pushButton_stars_clicked() //ПРИ НАЖАТИИ ПОЯВЛЯЮТСЯ ЗВЕЗДЫ
{
    QImage img(":/image/stars2.png");
    QPainter paint(im);
    QBrush brush;
    bool flag;
    QString str1;
    str1.clear();
    str1.append(ui->lineEdit_Size->text());

    int n=str1.toInt(&flag,10); //ПРЕОБРАЗОВАНИЕ ЗНАЧЕНИЕ С LINEEDIT В ЧИСЛО

    if ((!flag)||(n<0)||(n>10000)) //ФИЛЬТР НА ОТРИЦАТЕЛЬНЫЕ ЧИСЛА
    {
        ui->label_eror->setText("Должно быть введено корректное  число");
    }

    else

    {
        brush.setColor(Qt::gray); //РИСОВКА НЕБА
        brush.setStyle(Qt::SolidPattern);
        paint.setBrush(brush);
        paint.drawRect(0,0,725,500);


        brush.setColor(Qt::darkGreen); //РИСОВКА ЗЕМЛИ
        brush.setStyle(Qt::SolidPattern);
        paint.setBrush(brush);
        paint.drawRect(0,350,700,300);


        ui->label_eror->setText("");
        for (int i = 0; i < n; i++) //ЦИКЛ ЗАПОЛНЕНИЯ ЗВЕЗД
        {
            int a=rand()%630+0;
            int b=rand()%304;
            paint.drawImage(a,b,img,0,0,0,0);

        }

        brush.setColor(Qt::yellow); //РИСОВКА ЛУНЫ
        paint.setBrush(brush);
        paint.drawEllipse(600,25,45,45);


        brush.setColor(Qt::darkYellow); //РИСОВКА ЛУНЫ
        paint.setBrush(brush);
        paint.drawEllipse(620,35,3,3);
        paint.drawEllipse(610,40,6,6);
        paint.drawEllipse(635,44,4,4);
        paint.drawEllipse(630,54,2,2);
        paint.drawEllipse(615,60,3,3);



        QPoint korp[4]; // РИСОВКА ОСНОВАНИЯ ДОМА
        korp[0].setX(300);
        korp[0].setY(450);

        korp[1].setX(200);
        korp[1].setY(450);

        korp[2].setX(200);
        korp[2].setY(350);

        korp[3].setX(300);
        korp[3].setY(350);

        brush.setColor(Qt::red); //ВЫБОР ПАРАМЕТРОВ
        brush.setStyle(Qt::SolidPattern);
        paint.setBrush(brush);
        paint.drawPolygon(korp,4,Qt::OddEvenFill);


        QPoint clos[3]; // РИСОВКА КРЫШИ ДОМА

        clos[0].setX(300);
        clos[0].setY(350);

        clos[1].setX(250);
        clos[1].setY(300);

        clos[2].setX(200);
        clos[2].setY(350);

        brush.setColor(Qt::blue); //ВЫБОР ПАРАМЕТРОВ
        brush.setStyle(Qt::SolidPattern);
        paint.setBrush(brush);
        paint.drawPolygon(clos,3,Qt::OddEvenFill);


        brush.setColor(Qt::yellow); //РИСОВКА ОКНА
        paint.setBrush(brush);
        paint.drawRect(215,390,15,15);
        paint.drawRect(232,390,15,15);
        paint.drawRect(215,407,15,15);
        paint.drawRect(232,407,15,15);


        brush.setColor(Qt::darkCyan); //РИСОВКА ОКНА ДВЕРИ
        paint.setBrush(brush);
        paint.drawRect(275,397,20,50);


        brush.setColor(Qt::black); //РИСОВКА РУЧКИ
        paint.setBrush(brush);
        paint.drawEllipse(288,423,3,3);


    }
    repaint();

}


