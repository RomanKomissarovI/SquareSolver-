OBJFILES := obj/in_out.o obj/solve_equation.o obj/testing.o obj/main.o obj/equation_structs_make.o obj/color_print.o
FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main.exe

run: main.exe
	./main.exe

clean: $(OBJFILES)
	rm obj/*.o

obj/in_out.o: in_out.cpp
	@ g++ in_out.cpp -c $(FLAGS) -o obj/in_out.o

obj/solve_equation.o: solve_equation.cpp
	@ g++ solve_equation.cpp -c $(FLAGS) -o obj/solve_equation.o

obj/testing.o: testing.cpp
	@ g++ testing.cpp -c $(FLAGS) -o obj/testing.o

obj/main.o: main.cpp
	@ g++ main.cpp -c $(FLAGS) -o obj/main.o

obj/equation_structs_make.o: equation_structs_make.cpp
	@ g++ equation_structs_make.cpp -c $(FLAGS) -o obj/equation_structs_make.o

obj/color_print.o: color_print.cpp
	@ g++ color_print.cpp -c $(FLAGS) -o obj/color_print.o

main.exe : $(OBJFILES)
	@ g++ $(FLAGS) $(OBJFILES) -o main.exe
