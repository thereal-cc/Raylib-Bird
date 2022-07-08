#pragma once
#include "raylib.h"

class Rock
{
    private:
        double x;
        double y;
        int width;
        int height;
        double vy;
        Image rockImage;
        Texture2D rockSprite;
        Rectangle rect;
    public:
        Rock(int index);

        double GetX();
        double GetY();

        void SetX(int x_in);
        void SetY(int y_in);

        int GetWidth();
        int GetHeight();

        Rectangle GetRect();

        Image GetImage();
        Texture2D GetSprite();

        void UpdatePosition();
};