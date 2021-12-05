#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

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
    //classIsOver();

    // 点击一个下课的按钮，再触发下课
    QPushButton *btn = new QPushButton("下课",this);
    // 重置窗口大小
    this->resize(600,400);

    // 点击按钮，触发下课
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    void (Teacher:: * teacherSignal2)(void) = &Teacher::hungry;
    void(Student:: * studentSlot2)(void) = &Student::treat;
    connect(tea,teacherSignal2,stu,studentSlot2);

    // 信号连接信号
    connect(btn,&QPushButton::clicked,tea,teacherSignal2);

    // 断开信号
    //disconnect(btn,&QPushButton::clicked,tea,teacherSignal2);

    // 拓展
    // 1.信号可以连接信号
    // 2.一个信号可以连接多个槽函数
    // 3.多个信号可以连接同一个槽函数
    // 4.信号和槽函数的参数类型必须一一对应
    // 5.信号和槽的参数个数不需要一致 信号的参数个数可以多于槽函数的参数个数

    [=](){
        btn->setText("aaaa");
    }();

    QPushButton *btn2 = new QPushButton("关闭",this);
    btn2->move(100,0);
    btn2->setParent(this);

    connect(btn2,&QPushButton::clicked,[=](){
        emit tea->hungry("宫保鸡丁");
        this->close();
    });

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

