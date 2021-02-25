PDIR = $(abspath ../)

CC = g++
CFLAGS = -Wall -std=c++1z
CDEBUG = -g
BUILDFLAGS = -DSPDLOG_COMPILED_LIB

NAME = Sandbox

TARGET = $(PDIR)/bin/$(NAME)App
SRCDIR = src
BUILDDIR = ../bin-int/$(NAME)

SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

INC = -I headers -I $(PDIR)/Grafix/headers -I $(PDIR)/vendor/include
LDLIBS =

$(TARGET): $(OBJECTS)
	@echo "\nLinking $(NAME)..."
	@echo "  $(CC) -o $@ -L$(PDIR)/bin -lGrafix $(LDLIBS) $^"
	@$(CC) -o $@ -L$(PDIR)/bin -lGrafix $(LDLIBS) $^
	@echo ""

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "  $(CC) $(CFLAGS) $(CDEBUG) -D$(BUILDMODE) $(BUILDFLAGS) $(INC) -c -o $@ $<"
	@$(CC) $(CFLAGS) $(CDEBUG) -D$(BUILDMODE) $(BUILDFLAGS) $(INC) -c -o $@ $<

.PHONY: clean
clean:
	@echo "Cleaning $(NAME)..."
	@echo "  rm -rf $(BUILDDIR)"; rm -rf $(BUILDDIR)