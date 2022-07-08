#include "raylib.h"
#include "settings.h"
#include "player.h"
#include "rock.h"

#include <iostream>
#include <fstream>
#include <string>

Player::Player(double x, double y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    hitFloor = false;
    hitRock = false;
    vx = 3.0f;
    vy = 0.0f;
    score = 0;
    highscore = GetHighScoreFromFile();
    rect = {(float)x, (float)y, (float)width, (float)height};
    playerImage = LoadImage("res/BirdSprite.png");
    ImageFlipHorizontal(&playerImage);
    playerSprite = LoadTextureFromImage(playerImage);
    playerSprite.width = GetWidth();
    playerSprite.height = GetHeight();
}

void Player::UpdatePosition()
{
    float dt = GetFrameTime();
    if ((y >= (settings::screenHeight)) || (y <= 0)) 
    {
        std::cout << "Player hit floor" << std::endl;
        hitFloor = true;
    }
    if ((x >= (settings::screenWidth - width)) || (x <= 0)) 
    {
        SetScore(GetScore() + 1);
        vx *= -1.0f;
        ImageFlipHorizontal(&playerImage);
        UpdateSprite();
    }
    if (IsKeyDown(KEY_SPACE))
    {
        vy -= 10.5f * dt;
    }
    else
    {
        vy += 7.0f * dt;
    }

    x += vx;
    y += vy;
    rect = {(float)x, (float)y, (float)width, (float)height};
}

void Player::UpdateSprite()
{
    UnloadTexture(playerSprite);
    playerSprite = LoadTextureFromImage(playerImage);
    playerSprite.width = GetWidth();
    playerSprite.height = GetHeight();
}

bool Player::hasHitFloor()
{
    return hitFloor;
}

bool Player::hasHitRock(Rock rock)
{
    if (CheckCollisionRecs(rect, rock.GetRect()))
    {
        std::cout << "You hit a rock!" << std::endl;
        return true;
    }
    return false;
}

// Getters & Setters
double Player::GetX()
{
    return x;
}

double Player::GetY()
{
    return y;
}

int Player::GetWidth()
{
    return width;
}

int Player::GetHeight()
{
    return height;
}

int Player::GetScore()
{
    return score;
}

int Player::GetHighScoreFromFile()
{
    // Read HighScore from file
    std::ifstream file("res/highscore.txt");
    std::string line;
    std::getline(file, line);
    int highscore = std::stoi(line);
    file.close();
    
    return highscore;
}

int Player::GetHighScore()
{
    return highscore;
}

double Player::GetVY()
{
    return vy;
}

Rectangle Player::GetRect()
{
    return rect;
}

Image Player::GetImage()
{
    return playerImage;
}

Texture2D Player::GetSprite()
{
    return playerSprite;
}

void Player::SetX(int x_in)
{
    this->x = x_in;
}

void Player::SetY(int y_in)
{
    this->y = y_in;
}

void Player::SetScore(int score_in)
{
    if (score_in > highscore)
    {
        score = score_in;
        SetHighScore(score_in);
    } 
    else 
    {
        score = score_in;
    }
}

void Player::SetHighScore(int highscore_in)
{
    // Write Highscore to file
    std::ofstream file("res/highscore.txt");
    file << highscore_in;
    file.close();

    highscore = highscore_in;
}

void Player::SetHitRock(bool hitRock_in)
{
    hitRock = hitRock_in;
}

void Player::SetHitFloor(bool hitFloor_in)
{
    hitFloor = hitFloor_in;
}

void Player::SetVY(float vy_in)
{
    vy = vy_in;
}