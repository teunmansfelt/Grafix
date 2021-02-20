PDIR = $(abspath ../)

.PHONY: update
update:
	@echo "\nUpdating libraries..."
	@update.bash $(PDIR)/vendor

CC = g++
CFLAGS = -Wall -std=c++1z
CDEBUG = -g 
BUILDFLAGS = -DDEBUG $(LIBFLAGS)

TARGET = $(PDIR)/bin/lib$(LIB).a
SRCDIR = src/$(LIB)
BUILDDIR = ../bin-int/vendor/$(LIB)

SOURCES = $(shell find $(SRCDIR) -type f -name *.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.cpp=.o))

build: $(TARGET)

$(TARGET): $(OBJECTS) 
	@echo "\nCreating static lib: $(LIB)..."
	@echo "  ar -cr $(TARGET) $^"
	@ar -cr $(TARGET) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "  $(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) -I include -c -o $@ $<"
	@$(CC) $(CFLAGS) $(CDEBUG) $(BUILDFLAGS) -I include -c -o $@ $<

.PHONY: clean
clean:
	@echo "Cleaning vendor/$(LIB)..."
	@echo "  rm -rf $(BUILDDIR)"; rm -rf $(BUILDDIR)
