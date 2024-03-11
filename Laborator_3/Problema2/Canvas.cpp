#include "Canvas.h"
#include <iostream>

using namespace std;


Canvas::Canvas(int width, int height)
{
    this->height = height;
    this->width = width;
    this->matrix = new char* [height];
    for (int i = 0; i < height; ++i)
    {
        this->matrix[i] = new char[width];
        for (int j = 0; j < width; ++j)
        {
            this->matrix[i][j] = ' ';
        }
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < this->height; ++i)
    {
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}


void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++) {
        this->SetPoint(top, i, ch);
        this->SetPoint(bottom, i, ch);
    }
    for (int i = top; i <= bottom; i++) {
        this->SetPoint(i, left, ch);
        this->SetPoint(i, right, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            this->SetPoint(i, j, ch);
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        this->matrix[y1][x1] = ch;
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            int dx = i - x;
            int dy = j - y;
            double distance = sqrt(dx * dx + dy * dy);

            if (abs(distance - ray) < 0.5)
            {
                this->matrix[i][j] = ch;
            }
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            int dx = i - x;
            int dy = j - y;
            double distance = sqrt(dx * dx + dy * dy);

            if (distance <= ray)
            {
                this->matrix[i][j] = ch;
            }
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < this->width && y >= 0 && y < this->height)
        this->matrix[x][y] = ch;
}

void Canvas::Print() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++)
            cout << this->matrix[i][j] << ' ';
        cout << endl;
    }
}
void Canvas::Clear() {
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            this->matrix[i][j] = ' ';
}
