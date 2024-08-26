OBJFILES := obj/in_out.o obj/solve_equation.o obj/testing.o obj/main.o obj/equation_structs_make.o
FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main.exe

run: main.exe
	./main.exe

clean: $(OBJFILES)
	rm obj/*.o

obj/in_out.o: src/in_out.cpp
	@ g++ src/in_out.cpp -c $(FLAGS) -o obj/in_out.o

obj/solve_equation.o: src/solve_equation.cpp
	@ g++ src/solve_equation.cpp -c $(FLAGS) -o obj/solve_equation.o

obj/testing.o: src/testing.cpp
	@ g++ src/testing.cpp -c $(FLAGS) -o obj/testing.o

obj/main.o: src/main.cpp
	@ g++ src/main.cpp -c $(FLAGS) -o obj/main.o

obj/equation_structs_make.o: src/equation_structs_make.cpp
	@ g++ src/equation_structs_make.cpp -c $(FLAGS) -o obj/equation_structs_make.o

main.exe : $(OBJFILES)
	@ g++ $(FLAGS) $(OBJFILES) -o main.exe
