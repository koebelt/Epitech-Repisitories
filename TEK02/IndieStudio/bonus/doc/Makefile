all:
	mkdir -p ../../doc
	make -C ./sphinx html
	cp -r doxygen/build/html ../../doc/uml

clean:
	make -C ./sphinx clean
	rm -rf ../../doc
	rm -rf doxygen/build

re: clean all


.PHONY: all clean re