# ======================
# Variables
# ======================
CC=gcc
OPT=-Wall

final : out/main.o out/taylor.o out/euler.o out/differentiation.o out/graphic.o
	$(CC) $(OPT) out/main.o out/taylor.o out/euler.o out/differentiation.o out/graphic.o -o final -lm

out/main.o : lib/main.c
	$(CC) $(OPT) -c lib/main.c -o out/main.o -lm

out/taylor.o : lib/taylor.c 
	$(CC) $(OPT) -c lib/taylor.c -o out/taylor.o -lm

out/euler.o : lib/euler.c
	$(CC) $(OPT) -c lib/euler.c -o out/euler.o -lm

out/differentiation.o : lib/differentiation.c
		$(CC) $(OPT) -c lib/differentiation.c -o out/differentiation.o -lm

out/graphic.o : lib/graphic.c
		$(CC) $(OPT) -c lib/graphic.c -o out/graphic.o -lm

# ======
# Clean
# ======
clean :
	rm -f out/*.o
realclean : clean
	rm -f final
