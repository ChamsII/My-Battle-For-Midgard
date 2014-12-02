##
## Makefile for Makefile in /home/alimou_c/Battle_for_midgar/alimou_c/quete1
## 
## Made by ALI MOUIGNI Chamsoudine
## Login   <alimou_c@etna-alternance.net>
## 
## Started on  Fri Oct 31 12:34:54 2014 ALI MOUIGNI Chamsoudine
## Last update Sat Nov  1 17:15:52 2014 ALI MOUIGNI Chamsoudine
##

CC	=	gcc
CFLAGS	=	-W -Wall -Werror -ansi -pedantic

OBJ	=	main.o fonc_heros.o readline.o battle.o outils.o fonc_monster.o fonct_utils.o fonc_quete2.o fonc_quete22.o fonc_critical.o

all:	ragnarok

ragnarok:	$(OBJ)
		@echo Files ragnarok copmiled -----> start rynning
		$(CC) $(CFLAGS) -o ragnarok $(OBJ)

main.o:	main.c
	@echo Compiling: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

fonc_hero.o:	fonc_hero.c
		@echo Compiling: fonc_hero.c
		$(CC) $(CFLAGS) -c fonc_hero.c -o fonc_hero.o

battle.o:	battle.c
		@echo Compiling : battle.c
		$(CC) $(CFLAGS) -c battle.c -o battle.o

outils.o:	outils.c
		@echo Compiling: outils.c
		$(CC) $(CFLAGS) -c outils.c -o outils.o

readline.o:	readline.c
		@echo Compiling: readline.c
		$(CC) $(CFLAGS) -c readline.c -o readline.o

fonc_monster.o:	fonc_monster.c
			@echo Compiling: fonc_monster.c
			$(CC) $(CFLAGS) -c fonc_monster.c -o fonc_monster.o

fonct_utils.o:		fonct_utils.c
			@echo Compiling: fonct_utils.c
			$(CC) $(CFLAGS) -c fonct_utils.c -o fonct_utils.o

fonc_quete2.o:		fonc_quete2.c
			@echo Compiling: fonc_quete2.c
			$(CC) $(CFLAGS) -c fonc_quete2.c -o fonc_quete2.o

fonc_quete22.o:		fonc_quete22.c
			@echo Compiling: fonc_quete22.c
			$(CC) $(CFLAGS) -c fonc_quete22.c -o fonc_quete22.o

fonc_critical.o:	fonc_critical.c
			@echo Compiling: fonc_critical.c
			$(CC) $(CFLAGS) -c fonc_critical.c -o fonc_critical.o

main.c:			outils.h heros.h
fonc_hero.c:		outils.h heros.h
battle.c:		outils.h heros.h
outils.c:		outils.h heros.h
fonc_monster.c:		outils.h heros.h
fonct_utils.c:		outils.h heros.h
fonc_quete2.c:		outils.h heros.h
fonc_quete22.c:		outils.h heros.h
fonc_critical.c:	outils.h heros.h

clean:
	@echo Delete $(OBJ) ragnarok
	@echo Delete $(OBJ) ragnarok
	rm -Rf $(OBJ) ragnarok