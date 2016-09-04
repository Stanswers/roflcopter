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

CC=clang
CFLAGS=-O

rofl: roflcopter.c roflcopter.h
	$(CC) $(CFLAGS) -o roflcopter roflcopter.c -lncurses
