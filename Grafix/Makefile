PDIR = $(abspath ../)

CC = g++
CFLAGS = -Wall -std=c++1z
CDEBUG = -g
BUILDFLAGS = -DDEBUG

NAME = Grafix

TARGET = $(PDIR)/bin/lib$(NAME).dylib
SRCDIR = src
BUILDDIR = $(PDIR)/bin-int/$(NAME)

SOURCES = $(shell find $(SRCDIR) -type f - name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

INC = -I headers -I $(PDIR)/vendor/headers
LDLIBS =

$(TARGET): $(OBJECT)
	@echo "\nLinking $(NAME)..."
	@echo "  $(CC) -dynamiclib -fpic -o $@ $(LDLIBS) $^"
	@$(CC) -dynamiclib -fpic -o $@ $(LDLIBS) $^

$(BUILDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "  $(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) $(INC) -c -o $@ $<"
	@$(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) $(INC) -c -o $@ $<

.PHONY: clean
clean:
	@echo "Cleaning $(NAME)..."
	@echo "  rm -rf $(BUILDDIR)"; rm -rf $(BUILDDIR)