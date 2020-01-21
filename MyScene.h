#pragma once

#include "Scene.h"

// A child of the Scene class to make a new animated scene.
// Feel free to add any new member functions or variables to MyScene.
class MyScene : public Scene
{
    protected:
        
        int xx = 0;
        int xy = 0;
        int xdx = 1;
        int xdy = 1;
        int xnegate = 0;

        int ox = 10;
        int oy = 10;
        int odx = 1;
        int ody = 1;
        int onegate = 0;
        // Called once when the scene begins.
        virtual void init()
        {
            // Keep this call to the parent's version of init()
            Scene::init();
            // Your code here


        }

        // Called once every frame. 
        virtual void update()
        {
            clearBoard();
            // Your code here
            board[xy][xx] = 'x';
            board[oy][ox] = 'o';

            xx += xdx;
            xy += xdy;

            xdx = xnegate ? rand() % 3 : -(rand() % 3);
            xdy = xnegate ? rand() % 3 : -(rand() % 3);

            ox += odx;
            oy += ody;

            odx = onegate ? rand() % 3 : -(rand() % 3);
            ody = onegate ? rand() % 3 : -(rand() % 3);
            if(xx == ox && oy == xy)
            {
                xdx *= -1;
                xdy *= -1;
                xnegate ^= 1;

                odx *= -1;
                ody *= -1;
                onegate ^= 1;
            }

            // Keep this call to the parent's version of update()
            Scene::update();
        }
};
