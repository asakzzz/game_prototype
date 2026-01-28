hello_world: hello_world
	g++ hello_world.cpp -o hello_world -lsfml-graphics -lsfml-window -lsfml-system

run : 
	./hello_world

delete : 
	rm hello_world