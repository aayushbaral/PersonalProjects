#include <iostream>
#include "ImageOutput.h"

using namespace std;

int main() {
    ImageOutput *myImage = new ImageOutput();
    uint8_t colors[] = {25, 120, 25, 2};
    myImage->draw(200, 200, colors, "image.bmp");
    return 0;
}