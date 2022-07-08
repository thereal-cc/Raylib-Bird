#include "raylib.h"
#include "settings.h"
#include "rock.h"
#include "player.h"
#include <iostream>

Rock::Rock(int index)
{
    x = GetRandomValue(0, settings::screenWidth - 51);
    y = 0.0 - (42 * index);
    width = 51;
    height = 42;
    vy = 0.0f;
    rockImage = LoadImage("res/Boulder.png");
    rockSprite = LoadTextureFromImage(rockImage);
    rockSprite.width = GetWidth();
    rockSprite.height = GetHeight();
    rect = {(float)x, (float)y, (float)width, (float)height};
}

void Rock::UpdatePosition()
{
    float dt = GetFrameTime();

    vy += 1.5f * dt;
    y += vy;

    if (y > settings::screenHeight)
    {
        vy = 0.0f;
        int x_in = GetRandomValue(0, (settings::screenWidth - width));
        SetX(x_in);
        SetY(0 - height);
    }

    rect = {(float)x, (float)y, (float)width, (float)height};
}

double Rock::GetX()
{
    return x;
}

double Rock::GetY()
{
    return y;
}

int Rock::GetWidth()
{
    return width;
}

int Rock::GetHeight()
{
    return height;
}

Rectangle Rock::GetRect()
{
    return rect;
}

Image Rock::GetImage()
{
    return rockImage;
}

Texture2D Rock::GetSprite()
{
    return rockSprite;
}

void Rock::SetX(int x_in)
{
    x = x_in;
}

void Rock::SetY(int y_in)
{
    y = y_in;
}