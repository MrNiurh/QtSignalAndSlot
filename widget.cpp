#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建一个老师的对象
    this->tea= new Teacher(this);

    // 创建一个学生对象
    this->stu = new Student(this);

    // 连接
    // connect(tea,&Teacher::hungry,stu,&Student::treat);

    // 指针 -> 地址
    // 函数指针 -> 函数地址

    void (Teacher:: * teacherSignal)(QString) = &Teacher::hungry;
    void(Student:: * studentSlot)(QString) = &Student::treat;
    connect(tea,teacherSignal,stu,studentSlot);


    // 调用下课函数
    classIsOver();
}

void Widget::classIsOver()
{
    // 调用下课函数
   // emit tea->hungry();
    emit tea->hungry("黄焖鸡米饭");
}

Widget::~Widget()
{
    delete ui;
}

