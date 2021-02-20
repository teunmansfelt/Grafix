.PHONY: all
all:
	@$(MAKE) -C Grafix
	@$(MAKE) -C Sandbox

.PHONY: update
update:
	@$(MAKE) update -C vendor
	@$(MAKE) build LIB=spdlog EXT=cpp BUILDFLAGS=SPDLOG_COMPILED_LIB -C vendor
# @$(MAKE) build LIB=glfw CC=gcc EXT=c BUILDFLAGS=_GLFW_COCOA -C vendor

.PHONY: clean
clean:
	@$(MAKE) clean -C Grafix
	@$(MAKE) clean -C Sandbox