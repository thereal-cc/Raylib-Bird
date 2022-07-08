#pragma once
#include "raylib.h"
#include "rock.h"

class Player
{
    private:
        double x;
        double y;
        int width;
        int height;
        int score;
        int highscore;
        bool hitRock;
        bool hitFloor;
        double vx;
        double vy;
        Image playerImage;
        Texture2D playerSprite;
        Rectangle rect;
    public:
        //Get X, Y, Width, Height, Velocity (Set X, Y, Velocity)
        Player(double x, double y, int width, int height);
        double GetX();
        double GetY();

        void SetX(int x_in);
        void SetY(int y_in);

        int GetWidth();
        int GetHeight();

        double GetVY();
        void SetVY(float vy_in);

        Rectangle GetRect();

        int GetScore();
        void SetScore(int score_in);

        int GetHighScore();
        int GetHighScoreFromFile();
        void SetHighScore(int highscore_in);

        Image GetImage();
        Texture2D GetSprite();

        bool hasHitRock(Rock rock);
        void SetHitRock(bool hitRock_in);
        bool hasHitFloor();
        void SetHitFloor(bool hitFloor_in);

        void UpdatePosition();
        void UpdateSprite();
};