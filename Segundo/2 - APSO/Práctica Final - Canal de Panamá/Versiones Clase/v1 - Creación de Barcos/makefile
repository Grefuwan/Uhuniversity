all: servidor_ncurses canalpanama barcoeste barcooeste

servidor_ncurses: servidor_ncurses.c definiciones.h comun.h
	cc servidor_ncurses.c -o servidor_ncurses -lncurses -Wall

canalpanama: canalpanama.c
	cc canalpanama.c -o canalpanama -Wall

barcoeste: barcoeste.c comun.h
	cc barcoeste.c -o barcoeste -Wall

barcooeste: barcooeste.c comun.h
	cc barcooeste.c -o barcooeste -Wall
	
borratodo:
	rm canalpanama servidor_ncurses barcoeste