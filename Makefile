procbar:ProBar.c Main.c
	@gcc $^ -o $@
	@#gcc ProBar.c Main.c -o procbar
.PHONY:clean
clean:
	@rm -f procbar




