all:
	@(for x in index job env proc sh1 sh2 sh3 t1 t2 pool malloc fs1 fs2; do markdown -o $$x.html $$x.md; done)

clean:
	rm *.html
