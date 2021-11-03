#include <iostream>
#include "BMPImage.h"
using namespace std;

int main(int argc, char ** argv) {
    SDLWrapper g(700,700,false);
    BMPImage overlay("images/sorbet3.bmp", 0, 0);
    BMPImage test("images/transparent.bmp", 40, 40);

    overlay.setBackground(g);
    while (!g.getQuit()){
        for(int i = 0; i < 100; i++){
            test.redrawBkG(g);
            test.draw(g, i, 40);

            if(g.kbhit()){
                g.getKey();
            }

            g.update();
        }
    }
    return 0;
}
