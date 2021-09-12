all: servidor_ncurses canalpanama barcoeste barcooeste gEsclusae gEsclusao gLago

servidor_ncurses: servidor_ncurses.c definiciones.h comun.h
	cc servidor_ncurses.c -o servidor_ncurses -lncurses -Wall

canalpanama: canalpanama.c
	cc canalpanama.c -o canalpanama -Wall

barcoeste: barcoeste.c comun.h comunbarcos.c comunbarcos.h
	cc barcoeste.c comunbarcos.c -o barcoeste -Wall

barcooeste: barcooeste.c comun.h comunbarcos.c comunbarcos.h
	cc barcooeste.c comunbarcos.c -o barcooeste -Wall

gEsclusae: gEsclusae.c
	cc gEsclusae.c -o gEsclusae -Wall
	
gEsclusao: gEsclusao.c
	cc gEsclusao.c -o gEsclusao -Wall
	
gLago: gLago.c
	cc gLago.c -o gLago -Wall
