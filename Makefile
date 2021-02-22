.PHONY: all
all:
	@$(MAKE) -C Grafix
	@$(MAKE) -C Sandbox

.PHONY: update
update:
	@$(MAKE) update -C vendor
	@$(MAKE) build LIB=spdlog BUILDFLAGS=SPDLOG_COMPILED_LIB -C vendor
	@$(MAKE) build LIB=glfw BUILDFLAGS=_GLFW_COCOA -C vendor

.PHONY: clean_all
clean_all: clean clean_vendor

.PHONY: clean
clean:
	@$(MAKE) clean -C Grafix
	@$(MAKE) clean -C Sandbox

.PHONY: clean_vendor
clean_vendor:
	@$(MAKE) clean LIB=$(LIB) -C vendor