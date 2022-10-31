#include <iostream>
#include "func.h"
#include "imageio.h"

int main() {
	invert("image1.pgm"); // Task A

	invert_half("image2.pgm"); // Task B

	box("image2.pgm"); // Task C

	return 0;
}