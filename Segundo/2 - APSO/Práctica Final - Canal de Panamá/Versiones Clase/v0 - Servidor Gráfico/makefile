all: servidor_ncurses prueba

servidor_ncurses: servidor_ncurses.c definiciones.h comun.h
	cc servidor_ncurses.c -o servidor_ncurses -lncurses

prueba: prueba.c comun.h
	cc prueba.c -o prueba

