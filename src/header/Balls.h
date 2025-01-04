#include <string>

#pragma once
#ifndef BALLS_H
#define BALLS_H

class Balls {
    public:
        Balls(double x, double y, int radius, double speedX, double speedY);
        void move();
        void setX(double x);
        void setY(double y);
        void setRadius(int radius);
        void setSpeedX(double speedX);
        void setSpeedY(double speedY);
        void setColor(std::string color);
        double getX();
        double getY();
        int getRadius();
        double getSpeedX();
        double getSpeedY();
        std::string getColor();

    private:
        double x;
        double y;
        int radius;
        double speedX;
        double speedY;
        std::string color;
};

#endif