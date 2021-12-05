#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请吃饭";
}


void Student::treat(QString foodName)
{
    // QString -> char * 先转成 QByteArray ( .toUtf8() ) 再转 char * ()
    qDebug()<<"请吃:" << foodName.toUtf8().data();
}
