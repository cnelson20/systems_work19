all: ui worker

ui: ui.o
	gcc ui.o -o ui

ui.o: ui.c
	gcc ui.c -c
	
worker: worker.o
	gcc worker.o -o worker
	
worker.o: worker.c
	gcc worker.c -c 