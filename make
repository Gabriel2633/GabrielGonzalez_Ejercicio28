all: pinocho.dat graficas.png 

%.png: %.dat graficas.png 
	python3 plot.py

%.dat: a.out
	./a.out

a.out: c.cpp
	g++ c.cpp 

clean:
rm -rf *.x *.dat *.png