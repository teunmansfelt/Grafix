BUILDMODE = DEBUG

.PHONY: all
all:
	@$(MAKE) BUILDMODE=$(BUILDMODE) -C Grafix
	@$(MAKE) BUILDMODE=$(BUILDMODE) -C Sandbox

.PHONY: force
force: clean all

.PHONY: update
update:
	@$(MAKE) update -C vendor
	@echo "\nBuilding spdlog..."
	@$(MAKE) build LIB=spdlog BUILDFLAGS=-DSPDLOG_COMPILED_LIB -C vendor
	@echo "\nBuilding glfw..."
	@$(MAKE) build LIB=glfw BUILDFLAGS=-D_GLFW_COCOA -C vendor
	@echo "\nBuilding glad..."
	@$(MAKE) build LIB=glad -C vendor

.PHONY: clean_all
clean_all: clean clean_vendor

.PHONY: clean
clean:
	@$(MAKE) clean -C Grafix
	@$(MAKE) clean -C Sandbox

.PHONY: clean_vendor
clean_vendor:
	@$(MAKE) clean LIB=$(LIB) -C vendor