main: main.o func.o imageio.o
	g++ -o main main.o func.o imageio.o

func.o: func.cpp func.h imageio.h

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h


clean:
	rm -f sample.o imageio.o func.o
