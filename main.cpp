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

    Rectangle nebulaRect{0, 0, nebula.width / 8, nebula.height / 8};
    Vector2 nebulapos{windowWidth, windowHeight - nebulaRect.height};
    
    Rectangle neb2Rect{0, 0, nebula.width / 8, nebula.height / 8};
    Vector2 neb2Pos{windowWidth+300, windowHeight - nebulaRect.height};

    // animation frame for nebula
    int nebulaframe;
    const float nebulaUpdateTime{1.0 / 12.0};
    float nebulaRunningTime;

    int neb2frame;
    const float neb2UpdateTime{1.0 / 16.0};
    float neb2RunningTime;

    // neebula  velocity(pixel/seconds)
    int nebulaval{-200};

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
    // amount of time befor we update the animation frame
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

        //update second nebula position
        neb2Pos.x += nebulaval * dT;

        // update scarfy position
        scarfyPos.y += velocity * dT;

        // update scarfy's animation frame
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

        // update nebula's animation frame
        nebulaRunningTime += dT;
        if (nebulaRunningTime >= nebulaUpdateTime)
        {
            nebulaRunningTime = 0.0;
            nebulaRect.x = nebulaframe * nebulaRect.width;
            nebulaframe++;

            if (nebulaframe > 7)
            {
                nebulaframe = 0;
            }
        }

        // update nebula's animation frame
        neb2RunningTime += dT;
        if (neb2RunningTime >= neb2UpdateTime)
        {
            neb2RunningTime = 0.0;
            neb2Rect.x = neb2frame * neb2Rect.width;
            neb2frame++;

            if (neb2frame > 7)
            {
                neb2frame = 0;
            }
        }

        // draw nebbula
        DrawTextureRec(nebula, nebulaRect, nebulapos, WHITE);

        //draw the scond nebula
        DrawTextureRec(nebula, neb2Rect, neb2Pos, BLUE);

        // draw scarfy
        DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);

        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
}
