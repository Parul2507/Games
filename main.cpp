#include "raylib.h"

int main()
{
    const int windowWidth{512};
    const int windowHeight{300};
    InitWindow(windowWidth, windowHeight, "Parul's Gaming");

    //acceleration due to gravity(pixel/secs)
    const int gravity{1};

    //rectangle dimensions
    const int width{50};
    const int height{80};

    //is rectangle in the air
    bool isInAir{};

    //jump velocity

    const int jumpVel{-18};

    int posY{windowHeight - height};

    int velocity{0};

    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(WHITE);

        //ground check
        if(posY >= windowHeight - height){
            //rectangle is on the ground
            velocity = 0;
            isInAir = false;   
            
        }else{
            //rectangle is in the air
            velocity+=gravity;
            isInAir = true;
        }

        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            velocity += jumpVel;
        }

        //update position
        posY += velocity;

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);

        

        EndDrawing();
    }
    CloseWindow();    
}
