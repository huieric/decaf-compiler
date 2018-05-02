# Set the default target. When you make with no arguments,
# this will be the target built.
COMPILER = dcc
PRODUCTS = $(COMPILER)
default: $(PRODUCTS)

LAB1DIR = lab1/src/

INCLUDE += libs/
LIBDIR += libs

# Set up the list of source and object files
SRCS = 

# OBJS can deal with either .cc or .c files listed in SRCS
# OBJS = 

JUNK = *.o lex.yy.c y.tab.c y.tab.h 

# Define the tools we are going to use
CC = g++
LD = g++
LEX = flex
YACC = bison

# We want debugging and most warnings, but lex/yacc generate some 
# static symbols we don't use, so turn off unused warnings to avoid clutter
# Also STL has some signed/unsigned comparisons we want to suppress
CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare

# The -d flag tells lex to set up for debugging.
LEXFLAGS = -d

# The -d flag tells yacc to generate header with token types
# The -t flag turns on debugging capability
# The -y flag means imitate yacc's output file naming conventions
YACCFLAGS = -dvty

# Link with standard C library, math library, and lex library
LIBS = -lc -lm -ll 

# Rules of various parts of the target
lex.yy.c: lex.l parser.y y.tab.h 
	$(LEX) $(LEXFLAGS) 

y.tab.h y.tab.c: parser.y 
	$(YACC) $(YACCFLAGS) parser.y 

# rules to build compiler (dcc)
$(COMPILER): lex.yy.c y.tab.c 
	$(CC) $(CFLAGS) -o $@ lex.yy.c y.tab.c -lfl 

# clean
clean:
	rm -f $(JUNK) y.output $(PRODUCTS)