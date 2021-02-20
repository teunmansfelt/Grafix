PDIR = $(abspath ../)

.PHONY: update
update:
	@echo "\nUpdating libraries..."
	@update.bash $(PDIR)

CPPFLAGS = -Wall -std=c++1z
CFLAGS = -std=c11

TARGET = $(PDIR)/bin/lib$(LIB).a
SRCDIR = src/$(LIB)
BUILDDIR = ../bin-int/vendor/$(LIB)

SOURCES = $(shell find $(SRCDIR) -type f -name *.$(EXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(EXT)=.o))

INC = -I include -I src

build: $(TARGET)

$(TARGET): $(OBJECTS) 
	@echo "\nCreating static lib: $(LIB)..."
	@echo "  ar -cr $(TARGET) $^"
	@ar -cr $(TARGET) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "  g++ $(CPPFLAGS) -D$(BUILDFLAGS) $(INC) -c -o $@ $<"
	@g++ $(CPPFLAGS) -D$(BUILDFLAGS) $(INC) -c -o $@ $<

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "  gcc $(CFLAGS) -D$(BUILDFLAGS) $(INC) -c -o $@ $<"
	@gcc $(CFLAGS) -D$(BUILDFLAGS) $(INC) -c -o $@ $<

.PHONY: clean
clean:
	@echo "Cleaning vendor/$(LIB)..."
	@echo "  rm -rf $(BUILDDIR)"; rm -rf $(BUILDDIR)
