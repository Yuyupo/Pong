#!/bin/bash

if [ $1 = "clean" ]; then
  rm -rf build/
  echo "Clean build"
fi

mkdir build
cd build

g++ -std=c++11 -I /usr/local/include -c ../Player.cpp -o player.o
g++ -std=c++11 -I /usr/local/include -c ../Enemy.cpp -o enemy.o
g++ -std=c++11 -I /usr/local/include -c ../Ball.cpp -o ball.o

g++ -std=c++11  -I /usr/local/include -c ../main.cpp -o app.o
g++ ball.o enemy.o player.o app.o -o app -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
rm *.o
cd ..
./build/app