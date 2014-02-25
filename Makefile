.PHONY: all
all:
	make clean
	make main

.PHONY: main
main:
	make epub
	make pdf


.PHONY: pdf
pdf:
	cd src && review-pdfmaker config.yml
	mv -f src/revel-webFramewrok4Go-book.pdf ./bin
	rm -rf src/revel-webFramewrok4Go-book-pdf

.PHONY: epub
epub:
	cd src && review-epubmaker config.yml
	mv -f src/revel-webFramewrok4Go-book.epub ./bin
	rm -rf src/revel-webFramewrok4Go-book-epub

.PHONY: clean
clean:
	rm -rf src/revel-webFramewrok4Go-book-*
	rm -f bin/revel-webFramewrok4Go-book.*