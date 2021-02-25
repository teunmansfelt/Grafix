PDIR = $(abspath ../)

.PHONY: update
update:
	@echo "\nUpdating libraries..."
	@update.bash $(PDIR)

CPPFLAGS = -Wall -std=c++1z
CFLAGS = -std=c11 -m64

TARGET = $(PDIR)/bin/lib$(LIB).a
SRCDIR = ./$(LIB)
BUILDDIR = ../bin-int/vendor/$(LIB)

SOURCES_CPP = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS_CPP = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES_CPP:.cpp=.o))

SOURCES_C = $(shell find $(SRCDIR) -type f -name *.c)
OBJECTS_C = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES_C:.c=.o))

SOURCES_M = $(shell find $(SRCDIR) -type f -name *.m)
OBJECTS_M = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES_M:.m=.o))

INC = -I $(LIB) -I ./

build: $(TARGET)

$(TARGET): $(OBJECTS_CPP) $(OBJECTS_C) $(OBJECTS_M)
	@echo "\nCreating static lib: $(LIB)..."
	@echo "  ar -cr $(TARGET) $^"; ar -cr $(TARGET) $^
	@echo "  ranlib $(TARGET)"; ranlib $(TARGET)
	@echo ""

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "  g++ $(CPPFLAGS) $(BUILDFLAGS) $(INC) -c -o $@ $<"
	@g++ $(CPPFLAGS) $(BUILDFLAGS) $(INC) -c -o $@ $<

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "  gcc $(CFLAGS) $(BUILDFLAGS) $(INC) -c -o $@ $<"
	@gcc $(CFLAGS) $(BUILDFLAGS) $(INC) -c -o $@ $<

$(BUILDDIR)/%.o: $(SRCDIR)/%.m
	@mkdir -p $(dir $@)
	@echo "  g++ $(CFLAGS) $(BUILDFLAGS) $(INC) -c -o $@ $<"
	@g++ $(CFLAGS) $(BUILDFLAGS) $(INC) -c -o $@ $<

.PHONY: clean
clean:
	@echo "Cleaning vendor/$(LIB)..."
	@echo "  rm -rf $(BUILDDIR)"; rm -rf $(BUILDDIR)
