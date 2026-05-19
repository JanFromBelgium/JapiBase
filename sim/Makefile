# Japi Base host simulator — dependency-free host build (gcc only).
CC      = gcc
JAPIINC = ../Japi Base Pico 2
CFLAGS  = -std=c11 -Wall -Wextra -O2 -I"$(JAPIINC)" -Ishim

sim_demo: japi_sim.c sim_demo.c shim/ff.h shim/lfs.h
	$(CC) $(CFLAGS) -o sim_demo japi_sim.c sim_demo.c

clean:
	rm -f sim_demo

.PHONY: clean
