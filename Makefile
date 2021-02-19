.PHONY: all
all:
	@$(MAKE) -C Grafix
	@$(MAKE) -C Sandbox

.PHONY: update
update:
	@$(MAKE) update -C vendor
	@$(MAKE) build LIB=spdlog LIBFLAGS=-DSPDLOG_COMPILED_LIB -C vendor

.PHONY: clean
clean:
	@$(MAKE) clean -C Grafix
	@$(MAKE) clean -C Sandbox