.PHONY: all
all:
	@$(MAKE) -C Grafix
	@$(MAKE) -C Sandbox

.PHONY: clean
clean:
	@$(MAKE) clean -C Grafix
	@$(MAKE) clean -C Sandbox