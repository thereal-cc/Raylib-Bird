#include "raylib.h"
#include "settings.h"
#include "player.h"
#include "rock.h"
#include <iostream>

int main(void)
{
    InitWindow(settings::screenWidth, settings::screenHeight, settings::title.c_str());
    SetTargetFPS(settings::fps);
    SetRandomSeed(time(NULL));

    Player player(48, settings::screenHeight/2 - 24, 48, 48);
    Rock rocks[2] = {{1}, {2}};
    Font font = LoadFont("res/Anton-Regular.ttf");

    while(!WindowShouldClose())
    {
        bool collisionDetected = false;

        player.UpdatePosition();

        for (int i = 0; i < 2; i++)
        {
            rocks[i].UpdatePosition();
            
            if ((player.hasHitFloor() || player.hasHitRock(rocks[i])) && !collisionDetected)
            {
                collisionDetected = true;
                player.SetX(GetScreenWidth() / 2);
                player.SetY(GetScreenHeight() / 2);
                player.SetScore(0);
                player.SetHitRock(false);
                player.SetHitFloor(false);
                player.SetVY(0.0f);
            }
        }
        BeginDrawing();
            ClearBackground(SKYBLUE);
            DrawTexture(player.GetSprite(), player.GetX(), player.GetY(), WHITE);
            for (int i = 0; i < 2; i++)
            {
                DrawTexture(rocks[i].GetSprite(), rocks[i].GetX(), rocks[i].GetY(), WHITE);
            }
            DrawText(TextFormat("Score: %03i", player.GetScore()), 10, 10, 20, WHITE);
            DrawText(TextFormat("Best: %03i", player.GetHighScore()), 10, 30, 20, WHITE);
        EndDrawing();  
        
    }

    UnloadTexture(player.GetSprite());
    UnloadImage(player.GetImage());

    for (int i = 0; i < 2; i++)
    {
        UnloadTexture(rocks[i].GetSprite());
        UnloadImage(rocks[i].GetImage());
    }

    UnloadFont(font);
    CloseWindow();

    return 0;
}