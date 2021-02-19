PDIR = $(abspath ../)

CC = g++
CFLAGS = -Wall -std=c++1z
CDEBUG = -g
BUILDFLAGS = -DDEBUG

NAME = Sandbox

TARGET = $(PDIR)/bin/$(NAME)App
SRCDIR = src
BUILDDIR = $(PDIR)/bin-int/$(NAME)

SOURCES = $(shell find $(SRCDIR) -type f - name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

INC = -I headers -I $(PDIR)/Grafix/headers -I $(PDIR)/vendor/headers
LDLIBS =

$(TARGET): $(OBJECT)
	@echo "\nLinking $(NAME)..."
	@echo "  $(CC) -o $@ -L$(PDIR)/bin -lGrafix $(LDLIBS) $^"
	@$(CC) -o $@ -L$(PDIR)/bin -lGrafix $(LDLIBS) $^

$(BUILDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "  $(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) $(INC) -c -o $@ $<"
	@$(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) $(INC) -c -o $@ $<

.PHONY: clean
clean:
	@echo "Cleaning $(NAME)..."
	@echo "  rm -rf $(BUILDDIR)"; rm -rf $(BUILDDIR)