#include "raylib.h"

int main()
{
    // Window dimensions
    const int windowWidth{512};
    const int windowHeight{300};
    // Initialize the window
    InitWindow(windowWidth, windowHeight, "Parul's Gaming");

    // acceleration due to gravity(pixel/secs)/secs
    const int gravity{1'000};

    // nebula varibles
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle nebulaRect;
    nebulaRect.width = nebula.width / 8;
    nebulaRect.height = nebula.height / 8;
    nebulaRect.x = 0;
    nebulaRect.y = 0;

    Vector2 nebulapos;
    nebulapos.x = windowWidth;
    nebulapos.y = windowHeight - nebulaRect.height;

    // neebula  velocity(pixel/seconds)
    int nebulaval{-600};

    // scarfy variables
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRect;
    scarfyRect.width = scarfy.width / 6;
    scarfyRect.height = scarfy.height;
    scarfyRect.x = 0;
    scarfyRect.y = 0;

    Vector2 scarfyPos;
    scarfyPos.x = windowWidth / 2 - scarfyRect.width / 2;
    scarfyPos.y = windowHeight - scarfyRect.height;

    // animation frame
    int frame{};
    // amount of time befor w update h animation frame
    const float updateTime{1.0 / 12.0};
    float runningTime{};

    // is rectangle in the air
    bool isInAir{};

    // jump velocity(pixl/second)
    const int jumpVel{-600};

    int velocity{0};

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {

        // delta time(time since last frame)
        const float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);

        // ground check
        if (scarfyPos.y >= windowHeight - scarfyRect.height)
        {
            // rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // rectangle is in the air
            velocity += gravity * dT;
            isInAir = true;
        }

        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // update nebula position
        nebulapos.x += nebulaval * dT;

        // update scarfy position
        scarfyPos.y += velocity * dT;
 
        if (!isInAir)
        {
            // update runningTime
            runningTime += dT;
            if (runningTime >= updateTime)
            {
                runningTime = 0.0;
                // update animation frame
                scarfyRect.x = frame * scarfyRect.width;
                frame++;

                if (frame > 5)
                {
                    frame = 0;
                }
            }
            else
            {
                scarfyRect.x;
            }
        }

        // draw nebbula
        DrawTextureRec(nebula, nebulaRect, nebulapos, WHITE);

        // draw scarfy
        DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);

        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
}
