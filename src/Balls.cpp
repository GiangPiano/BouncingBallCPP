#include "./header/balls.h"
#include <string>
Balls::Balls(double x, double y, int radius, double speedX, double speedY) {
    this->x = x;
    this->y = y;
    this->radius = radius;
    this->speedX = speedX;
    this->speedY = speedY;
}

void Balls::move() {
    x += speedX;
    y += speedY;
}

void Balls::setX(double x) {
    this->x = x;
}

void Balls::setY(double y) {
    this->y = y;
}

void Balls::setSpeedX(double speedX) {
    this->speedX = speedX;
}

void Balls::setSpeedY(double speedY) {
    this->speedY = speedY;
}

void Balls::setRadius(int radius) {
    this->radius = radius;
}

double Balls::getX() {
    return x;
}

double Balls::getY() {
    return y;
}

double Balls::getSpeedX() {
    return speedX;
}

double Balls::getSpeedY() {
    return speedY;
}

int Balls::getRadius() {
    return radius;
}