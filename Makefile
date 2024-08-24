.PHONY: all target

OBJFILES := obj/in_out.o obj/solve_equation.o obj/testing.o obj/main.o obj/equation_structs_make.o
FLAGS := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: main.exe

run: main.exe
	./main.exe

clean: $(OBJFILES)
	rm *.o

obj/%.o: src/%.cpp
	@ g++ -c $(FLAGS) $< -o $@

main.exe : $(OBJFILES)
	@ g++ $(FLAGS) $(OBJFILES) -o main.exe
