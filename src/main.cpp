#include "./header/balls.h"
#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <random>
#define gravity 1
#define WIDTH 175
#define HEIGHT 50

using namespace std;

vector<string> createBoard(int width, int height) {
    vector<string> board;
    for (int i = 0; i < height; i++) {
        string row = string(width, '.');
        board.push_back(row);
    }
    return board;
}
vector<string> board;

void placeBall(Balls &ball) {
    int x = ball.getX();
    int y = ball.getY();
    int radius = ball.getRadius();
    for (int i = 0; i < board[0].size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if ((i - x) * (i - x) + (j - y) * (j - y) * 3 < radius * radius) {
                board[j][i] = '#';
            }
        }
    }
}

int main() {
    vector<Balls> balls;
    // balls.push_back(Balls(60, 20, 10, 2, 0));
    // balls.push_back(Balls(100, 20, 5, 1, 0));
    // balls.push_back(Balls(140, 20, 7, -2, 0));
    // balls.push_back(Balls(80, 20, 3, -1, 0));
    // balls.push_back(Balls(120, 20, 8, 1, 0));
    // balls.push_back(Balls(160, 20, 1, -1, 0));
    int num = 100;
    for (int i = 0; i < num; i++) {
        balls.push_back(Balls(rand() % WIDTH + 1, rand() % HEIGHT - 1, rand() % 10 + 1, rand() % 10 - 5, 0));
    }


    int frame = 1000;
    system("cls");
    while (frame--) {
        board = createBoard(WIDTH, HEIGHT);

        for (Balls &ball : balls) {
            if (ball.getY() + ball.getRadius() / sqrt(3) >= HEIGHT) {
                ball.setSpeedY(-ball.getSpeedY());
            }
            else {
                ball.setSpeedY(ball.getSpeedY() + gravity);
            }
            if (ball.getX() + ball.getRadius() >= WIDTH || ball.getX() - ball.getRadius() <= 0) {
                ball.setSpeedX(-ball.getSpeedX());
            }
            ball.move();
            placeBall(ball);
        }

        for (auto row : board) {
            cout << row << endl;
        }

        cout << "Ball 1: " << balls[0].getX() << ", " << HEIGHT - (balls[0].getY() + balls[0].getRadius()) << endl;
        _sleep(50);
        cout << "\033[1;1H";
        // break;
    }
    return 0;
}