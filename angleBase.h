#ifndef ANGLEBASE_H
#define ANGLEBASE_H
#include <iostream>
#include <sstream>
class angleBase
{
public:
    angleBase();
    //度分秒输入
    angleBase(int d, int m, double s);
    //拷贝
    angleBase(const angleBase &m);
    //浮点数输入，flag为0是数学角度，为1是弧度，默认为0
    angleBase(double m,bool flag=0);
    angleBase operator=(const angleBase &m);
    angleBase operator-(const angleBase &m);
    angleBase operator+(const angleBase &m);
    angleBase operator-(int m);
    angleBase operator+(int m);//数学角度转弧度
    static double DegtoReg(double degree);
    //弧度转数学角度
    static double RegtoDeg(double reg);
    //数学角度转工程角度
    static angleBase DegtoengDeg(double m);
    //弧度转工程角度
    static angleBase RegtoengDeg(double m);
    friend angleBase operator-(int m,angleBase &ang);
    void show_angle();
    friend std::ostream& operator<< (std::ostream &os, const angleBase &m);
    double toReg();   //工程角度转化成弧度
    double toDeg();   //工程角度化成数学角度
    int degree;
    int minute;
    double second;
};

#endif // ANGLEBASE_H

