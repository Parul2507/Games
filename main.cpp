#include "raylib.h"

struct AnimData
{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float UpdateTime;
    float RunningTime;
};

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

    //AnimData for nebula
    AnimData nebData{ 
        {0.0, 0.0, nebula.width / 8, nebula.height / 8}, //Ractangle rec
        {windowWidth, windowHeight - nebula.height/8}, //vector2 pos
        0, //frame
        1.0/12.0, //float UpdateTime
        0 // float RunningTime
    };
    
    AnimData neb2Data{
        {0.0, 0.0, nebula.width / 8, nebula.height / 8}, 
        {windowWidth+300, windowHeight - nebula.height / 8}, 
        0, 
        1.0 / 16.0, 
        0
    };

    // neebula  velocity(pixel/seconds)
    int nebulaval{-200};

    // scarfy variables
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    AnimData scarfyData;
    scarfyData.rec.width = scarfy.width / 6;
    scarfyData.rec.height = scarfy.height;
    scarfyData.rec.x = 0;
    scarfyData.rec.y = 0;
    scarfyData.pos.x = windowWidth / 2 - scarfyData.rec.width / 2;
    scarfyData.pos.y = windowHeight - scarfyData.rec.height;
    scarfyData.frame = 0;
    scarfyData.UpdateTime = 1.0 / 12.0;
    scarfyData.RunningTime = 0.0;

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
        if (scarfyData.pos.y >= windowHeight - scarfyData.rec.height)
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
        nebData.pos.x += nebulaval * dT;

        //update second nebula position
        neb2Data.pos.x += nebulaval * dT;

        // update scarfy position
        scarfyData.pos.y += velocity * dT;

        // update scarfy's animation frame
        if (!isInAir)
        {
            // update runningTime
            scarfyData.RunningTime += dT;
            if (scarfyData.RunningTime >= scarfyData.UpdateTime)
            {
                scarfyData.RunningTime = 0.0;
                // update animation frame
                scarfyData.rec.x = scarfyData.frame * scarfyData.rec.width;
                scarfyData.frame++;

                if (scarfyData.frame > 5)
                {
                    scarfyData.frame = 0;
                }
            }
        }

        // update nebula's animation frame
        nebData.RunningTime += dT;
        if (nebData.RunningTime >= nebData.UpdateTime)
        {
            nebData.RunningTime = 0.0;
            nebData.rec.x = nebData.frame * nebData.rec.width;
            nebData.frame++;

            if (nebData.frame > 7)
            {
                nebData.frame = 0;
            }
        }

        // update nebula's animation frame
        neb2Data.RunningTime += dT;
        if (neb2Data.RunningTime >= neb2Data.UpdateTime)
        {
            neb2Data.RunningTime = 0.0;
            neb2Data.rec.x = neb2Data.frame * neb2Data.rec.width;
            neb2Data.frame++;

            if (neb2Data.frame > 7)
            {
                neb2Data.frame = 0;
            }
        }

        // draw nebbula
        DrawTextureRec(nebula, nebData.rec, nebData.pos, WHITE);
        //draw the scond nebula
        DrawTextureRec(nebula, neb2Data.rec, neb2Data.pos, BLUE);
        // draw scarfy
        DrawTextureRec(scarfy, scarfyData.rec, scarfyData.pos, WHITE);

        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
}
