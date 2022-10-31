#include <iostream>
#include "imageio.h"
#include <cmath>
#include <cstdlib>

void invert(std::string file) {
	int image[MAX_H][MAX_W];
	int height, width;

	readImage(file, image, height, width);

	for (int row = 0; row < MAX_H; row++) {
		for (int col = 0; col < MAX_W; col++) {
			image[row][col] = abs(image[row][col] - 255);
		}
	}

	writeImage("taskA.pgm", image, height, width);
}

