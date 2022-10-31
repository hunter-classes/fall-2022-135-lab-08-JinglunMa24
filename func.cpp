#include <iostream>
#include "imageio.h"
#include <cmath>
#include <cstdlib>

// Task A
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


// Task B
void invert_half(std::string file) {
	int image[MAX_H][MAX_W];
	int height, width;

	readImage(file, image, height, width);

	for (int row = 0; row < MAX_H; row++) {
		for (int col = 0; col < MAX_W; col++) {
			if (col >= MAX_H / 2) {
				image[row][col] = abs(image[row][col] - 255);
			}
		}
	}

	writeImage("taskB.pgm", image, height, width);
}


// Task C
void box(std::string file) {
	int image[MAX_H][MAX_W];
	int height, width;
	readImage(file, image, height, width);

	for (int row = height / 4; row < height * 3/4; row++) {
		for (int col = width / 4; col < width * 3/4; col++) {
			image[row][col] = 255;
		}
	}

	writeImage("taskC.pgm", image, height, width);
}
