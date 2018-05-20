# Set the default target. When you make with no arguments,
# this will be the target built.
PARSER = bin/parser
PRODUCTS = $(PARSER)
default: $(PRODUCTS)

# Set up the list of source files
SRCDIR = src

# OBJS can deal with either .cc or .c files listed in SRCS
OBJDIR = obj
# OBJS = $(patsubst %.cc, %.o, $(filter %.cc,$(LIBDIR)/*) $(patsubst %.c, %.o, $(filter %.c,$(LIBDIR)/*))

# Generated executable files
BINDIR = bin 

# Junk files to be cleaned
# JUNK = $(filter %.o *.yy.c *.tab.c *.tab.h,$(foreach dir,$(SRCDIR),$(wildcard $(dir)/*)))

# Define the tools we are going to use
CC = g++
LD = g++
LEX = flex
YACC = bison

# We want debugging and most warnings, but lex/yacc generate some 
# static symbols we don't use, so turn off unused warnings to avoid clutter
# Also STL has some signed/unsigned comparisons we want to suppress
CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare $(addprefix -I ,$(INCLUDE))

# The -d flag tells lex to set up for debugging.
LEXFLAGS = -d

# The -d flag tells yacc to generate header with token types
# The -t flag turns on debugging capability
# The -y flag means imitate yacc's output file naming conventions
YACCFLAGS = -dvty

# Link with standard C library, math library, and lex library
LIBFLAGS = -lc -lm -ll 

INCLUDE += src obj ../libs
LIBDIR += ../libs
LIBS = $(filter %.cc,$(wildcard $(LIBDIR)/*))

# Rules of various parts of the target
obj:
	@mkdir -p $(OBJDIR)

bin:
	@mkdir -p $(BINDIR)

lex.yy.c: y.tab.h 	
	$(LEX) -o $(OBJDIR)/lex.yy.c $(LEXFLAGS) $(SRCDIR)/scanner.l

y.tab.h y.tab.c: obj
	$(YACC) $(YACCFLAGS) $(SRCDIR)/parser.y -o $(OBJDIR)/y.tab.h -o $(OBJDIR)/y.tab.c

# rules to build compiler (dcc)
$(PARSER): lex.yy.c	bin
	$(CC) $(CFLAGS) -o $@ $(OBJDIR)/lex.yy.c $(OBJDIR)/y.tab.c $(SRCDIR)/main.cc $(filter-out $(LIBDIR)/hashtable.cc,$(LIBS)) $(LIBFLAGS)

# clean
clean:
	rm -r -f $(OBJDIR) $(BINDIR)