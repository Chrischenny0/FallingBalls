#ifndef CL10_18_2021_BALL_H
#define CL10_18_2021_BALL_H

#include "point.h"
#include "color.h"
#include "force.h"
#include "SDL_Plotter.h"
#include "SDL_Handler.h"
#include <vector>

class ball_t{
    private:
        point_t center;
        color_t color;
        force   vec;
        double  radius;
        SDL_Handler& a;
        vector<vector<unsigned char>> covers;

    public:
        ball_t(SDL_Handler& f);

        void setCenter(point_t);
        void setColor(color_t);
        void setForce(force);
        void setRadius(double);

        point_t getCenter() const;
        color_t getColor() const;
        force getForce() const;
        double getRadius() const;

        void draw(SDL_Handler &g) const;
        void applyForce(force v){
            vec.apply(v);
        }
        void move();

        void redrawBG();
        void getBG();

};

#endif //CL10_18_2021_BALL_H
