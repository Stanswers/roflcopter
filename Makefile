######################################
# rofl.c
#
# Lets watch a sweet roflcopter fly.
#
# Author:  Justin Helgesen
#          justinhelgesen@gmail.com
# Created: 9/4/2016
#
# The MIT License (MIT)
# Copyright (c) 2016 Justin Helgesen
# 
######################################

CC=gcc
CFLAGS=-O
BINARY=roflcopter
MANPAGE=roflcopter.1.gz

.PHONY: all install uninstall clean

all: roflcopter

roflcopter: roflcopter.c roflcopter.h
	$(CC) $(CFLAGS) -o $(BINARY) roflcopter.c -lncurses

install: all
	gzip < roflcopter.1 > roflcopter.1.gz
	cp $(BINARY) /usr/bin/
	cp roflcopter.1.gz /usr/share/man/man1/

uninstall:
	rm -f /usr/bin/$(BINARY) || true
	rm -f /usr/share/man/man1/$(MANPAGE) || true

clean:
	rm -f $(BINARY) || true
	rm -f $(MANPAGE) || true
