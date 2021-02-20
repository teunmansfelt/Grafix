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
LDLIBS = -L$(PDIR)/bin -lspdlog -L$(PDIR)/bin -lglfw
LDFRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

PCH = headers/GF_PCH.hpp
PCH_HEADERS = $(shell find $(PDIR)/vendor/include/spdlog -type f -name *.h)
# PCH_HEADERS += $(PDIR)/Grafix/headers/Logger.hpp

$(TARGET): $(OBJECTS)
	@echo "\nLinking $(NAME)..."
	@echo "  $(CC) -dynamiclib -fpic $^ $(LDLIBS) $(LDFRAMEWORKS) -o $@"
	@$(CC) -dynamiclib -fpic $^ $(LDLIBS) $(LDFRAMEWORKS) -o $@

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