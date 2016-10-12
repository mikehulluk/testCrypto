CXXFLAGS = -Wall -std=c++11 -Wextra

default: s1_ch3.exe
	

s1_ch1.exe: set1_challenge1.cpp util.cpp util.h
	g++ $(CXXFLAGS) set1_challenge1.cpp util.cpp -o s1_ch1.exe

s1_ch2.exe: set1_challenge2.cpp util.cpp util.h
	g++ $(CXXFLAGS) set1_challenge2.cpp util.cpp -o s1_ch2.exe

s1_ch3.exe: set1_challenge3.cpp util.cpp util.h
	g++ $(CXXFLAGS) set1_challenge3.cpp util.cpp -o s1_ch3.exe


clean: 
	rm -f s1_ch1.exe s1_ch2.exe