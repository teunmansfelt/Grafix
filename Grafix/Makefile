PDIR = $(abspath ../)

CC = g++
CFLAGS = -Wall -std=c++1z
CDEBUG = -g
BUILDFLAGS = -DDEBUG -DSPDLOG_COMPILED_LIB

NAME = Grafix

TARGET = $(PDIR)/bin/lib$(NAME).dylib
SRCDIR = src
BUILDDIR = ../bin-int/$(NAME)

SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

INC = -I headers -I $(PDIR)/vendor/include
LDLIBS = -L$(PDIR)/bin -lspdlog

PCH = headers/GF_PCH.hpp
PCH_HEADERS =

$(TARGET): $(OBJECTS)
	@echo "\nLinking $(NAME)..."
	@echo "  $(CC) -dynamiclib -fpic $^ $(LDLIBS) -o $@"
	@$(CC) -dynamiclib -fpic $^ $(LDLIBS) -o $@

$(PCH).gch: $(PCH) $(PCH_HEADERS)
	@echo "\nPrecompiling headers"
	@echo "  $(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) $(INC) -o $@ $<"
	@$(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) $(INC) -o $@ $<
	@echo "\n"

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(PCH).gch
	@mkdir -p $(dir $@)
	@echo "  $(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) -include $(PCH) $(INC) -c -o $@ $<"
	@$(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) -include $(PCH) $(INC) -c -o $@ $<

.PHONY: clean
clean:
	@echo "Cleaning $(NAME)..."
	@echo "  rm -rf $(BUILDDIR)"; rm -rf $(BUILDDIR)