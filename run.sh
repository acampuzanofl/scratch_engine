#!/bin/sh
g++ main.cpp gameengine.cpp character.cpp levelstate.cpp transform.cpp animation.cpp sprite.cpp input.cpp  -o scratch_engine -lsfml-graphics -lsfml-window -lsfml-system
./scratch_engine
