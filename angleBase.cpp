#include "angleBase.h"
#include <cmath>
#include <iostream>
#include <QTextStream>
#include <qstring.h>
#define pi 3.1415926

    angleBase::angleBase()
    {
        degree = 0;
        minute = 0;
        second = 0;
    }
    angleBase::angleBase(int d, int m, int s)
    {
        d %= 360;
        degree = d;
        minute = m;
        second = s;
    }
    angleBase::angleBase(const angleBase &m)
    {
        this->degree = m.degree;
        this->minute = m.minute;
        this->second = m.second;
    }
    angleBase::angleBase(double &a,bool flag)
    {
        if(flag==0)
        {
            this->degree = int(a);
            this->minute = int((a - degree) * 60);
            this->second = (a - degree - minute) * 3600;
        }
        else
        {
            double temp;
            temp=a * 180/pi;
            this->degree=int(temp);
            this->minute=int((a - degree) * 60);
            this->second=(a - degree - minute) * 3600;
        }
    }
    angleBase angleBase::operator=(const angleBase &m)
    {
        degree = m.degree;
        minute = m.minute;
        second = m.second;
        return *this;
    }
    angleBase angleBase::operator-(const angleBase &m)
    {
        angleBase res = *this;
        res.second = res.second - m.second;
        while(res.second<0)
        {
            res.second += 60;
            res.minute--;
        }
        res.minute = res.minute - m.minute;
        while(res.minute<0)
        {
            res.minute +=60;
            res.degree--;
        }
        res.degree = res.degree - m.degree;
        while (res.degree < 0) res.degree += 360;
        res.degree %= 360;
        return res;
    }
    angleBase angleBase::operator+(const angleBase &m)
    {
        angleBase res = *this;
        res.second = second + m.second;
        while (res.second>=60)
        {
            res.second -= 60;
            res.minute++;
        }
        res.minute = minute + m.minute;
        while(res.minute>=60)
        {
            res.minute -= 60;
            degree++;
        }
        res.degree = degree + m.degree;
        res.degree = res.degree % 360;
        return res;
    }
    angleBase angleBase::operator-(int m)
    {
        angleBase temp = *this;
        temp.degree -=m;
        while (temp.degree < 0) temp.degree += 360;
        temp.degree %= 360;
        return temp;
    }
    angleBase angleBase::operator+(int m)
    {
        angleBase temp = *this;
        temp.degree += m;
        temp.degree %= 360;
        return temp;
    }
    double angleBase::toReg()
    {
        double temp;
        temp = (degree + minute / 60.0 + second / 3600.0) * 3.1415926 / 180.0;
        return temp;
    }
    double angleBase::toDeg()
    {
        double temp;
        temp = (degree + minute / 60.0 + second / 3600.0);
        return temp;
    }
    QString angleBase::show_angle()
    {
        QString temp;
        temp = QString::number(degree) + " "+ QString::number(minute) + " " + QString::number(second) + " ";
        return temp;
    }
    std::ostringstream& operator<<(std::ostringstream &os,const angleBase &m)
    {
        os << m.degree << "°" << m.minute << "'" << m.second << "''"<<'\n';
        return os;
    }
    QTextStream& operator<<(QTextStream &os, const angleBase &m)
    {
        os << m.degree << "°" << m.minute << "'" << m.second << "''" << '\n';
        return os;
    }

    double DegtoReg(double degree)
    {
        while(degree>360)
        {
            degree -= 360;
        }
        while (degree<0)
        {
            degree += 360;
        }
        double reg = degree * pi / 180.0;
        return reg;
    }

    double RegtoDeg(double reg)
    {
        while (reg<0)
        {
            reg += 2 * pi;
        }
        while(reg>2*pi)
        {
            reg -= 2 * pi;
        }
        double degree = reg * 180 / pi;
        return degree;
    }

    angleBase DegtoengDeg(double m)
    {
        while (m>360)
        {
            m -= 360;
        }
        while(m<0)
        {
            m += 360;
        }
        angleBase temp;
        temp.degree = int(m);
        temp.minute = int((m - temp.degree) * 60);
        temp.second = ((m - temp.degree) * 60 - temp.minute) * 60;
        return temp;
    }

    angleBase RegtoengDeg(double m)
    {
        while (m<0)
        {
            m += 2 * pi;
        }
        while(m>2*pi)
        {
            m -= 2 * pi;
        }
        angleBase temp;
        double n = RegtoDeg(m);
        temp = DegtoengDeg(n);
        return temp;
    }