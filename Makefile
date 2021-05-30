.PHONY: clean
clean:
	test -d bin || mkdir bin
	rm -fR bin/*

