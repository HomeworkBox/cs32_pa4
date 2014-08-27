all: dynb dynb-virt

diff: all
	./diff.sh

dynb-virt: dynb-virt.cpp
	g++ -g3 -O0 -Wall ./dynb-virt.cpp -o dynb-virt

dynb: dynb.cpp dynb.h dynb-main.cpp
	g++ -g3 -O0 -Wall ./dynb.cpp ./dynb-main.cpp -o dynb

clean:
	rm -rf ./dynb ./dynb-virt
