all: servidor_ncurses canalpanama barcoeste barcooeste

servidor_ncurses: servidor_ncurses.c definiciones.h comun.h
	cc servidor_ncurses.c -o servidor_ncurses -lncurses

canalpanama: canalpanama.c
	cc canalpanama.c -o canalpanama 

barcoeste: barcoeste.c comun.h comunbarcos.c comunbarcos.h
	cc barcoeste.c comunbarcos.c -o barcoeste

barcooeste: barcooeste.c comun.h comunbarcos.c comunbarcos.h
	cc barcooeste.c comunbarcos.c -o barcooeste


