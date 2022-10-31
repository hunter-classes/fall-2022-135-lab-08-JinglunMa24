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
		for (int col = width / 2; col < MAX_W; col++) {
			image[row][col] = abs(image[row][col] - 255);
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


// Task D
void frame(std::string file) {
	int image[MAX_H][MAX_W];
	int height, width;
	readImage(file, image, height, width);

	for (int row = height / 4; row < height * 3/4; row++) {
		for (int col = width / 4; col < width * 3/4; col++) {
			if (row == height / 4 || row == height * 3/4 - 1|| col == width / 4 || col == width * 3/4 - 1) {
				image[row][col] == 255;
			}
		}
	}

	writeImage("taskD.pgm", image, height, width);
}


// Task E
void scale(std::string file) {
	int image[MAX_H][MAX_W];
	int output[MAX_H][MAX_W];
	int height, width;
	readImage(file, image, height, width);

	for (int row = 0; row < height;	row++) {
		for (int col = 0; col < width; col++) {
			output[row * 2][col * 2] = image[row][col];
			output[row * 2][col * 2 + 1] = image[row][col];
			output[row * 2 + 1][col * 2] = image[row][col];
			output[row * 2 + 1][col * 2 + 1] = image[row][col];
		}
	}
	height *= 2;
	width *= 2;

	writeImage("taskE.pgm", output, height, width);
} 


// Task F
void pixelate(std::string file) {
	int image[MAX_H][MAX_W];
	int height, width;
	readImage(file, image, height, width);

	for (int row = 0; row < height; row += 2) {
		for (int col = 0; col < width; col += 2) {
			int avg = (image[row][col] + image[row][col+1] + image[row+1][col] + image[row+1][col+1]) / 4;
			image[row][col] = avg;
			image[row][col+1] = avg;
			image[row+1][col] = avg;
			image[row+1][col+1] = avg;
		}
	}

	writeImage("taskF.pgm", image, height, width);
}