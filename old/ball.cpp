#include "ball.h"

ball_t::ball_t(SDL_Handler& f): a(f) {
    center.x = 100;
    center.y = 50;
    color.R  = 220;
    color.G  = 20;
    color.B  = 20;
    radius   = 10;
    vec.setMagnitude(1);
    vec.setDirection(PI/2);

}

void ball_t::setCenter(point_t c){
    center = c;
}

void ball_t::setColor(color_t c){
    color = c;
}

void ball_t::setForce(force f){
    vec = f;
}

void ball_t::setRadius(double r){
    radius = r;
}

point_t ball_t::getCenter() const{
    return center;
}
color_t ball_t::getColor() const{
    return color;
}
force ball_t::getForce() const{
    return vec;
}
double ball_t::getRadius() const{
    return radius;
}

void ball_t::draw(SDL_Handler &g) const{
    point_t p;
    for(int x = center.x - radius; x <= center.x + radius; x++){
        for(int y = center.y - radius; y <= center.y + radius; y++){
            p.x = x;
            p.y = y;
            if(center.distance(p) <= radius){
                if(x >= 0 && y >= 0 && x < g.getWidth() && y < g.getHeight()){
                    g.draw(x, y, color.R, color.G, color.B);
                }
            }
        }
    }
}
void ball_t::move(){
    center.y += vec.getMagnitude() * sin(vec.getDirection());
    center.x += vec.getMagnitude() * cos(vec.getDirection());
}

void ball_t::redrawBG() {
    a.draw(center.x - radius, center.y -radius, covers);
}

void ball_t::getBG()
{
    a.getslice(center.x - radius, center.y - radius, radius * 2,
                        radius * 2, covers);
}

