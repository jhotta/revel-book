.PHONY: all
all: main

.PHONY: main
main:
	make epub
	make pdf


.PHONY: pdf
pdf:
	cd src && review-pdfmaker config.yml
	mv -f src/revel-webFramewrok4Go-book.pdf .
	rm -rf src/revel-webFramewrok4Go-book-pdf

.PHONY: epub
epub:
	cd src && review-epubmaker config.yml
	mv -f src/revel-webFramewrok4Go-book.epub .
	rm -rf src/revel-webFramewrok4Go-book-epub

.PHONY: clean
clean:
	rm -rf src/revel-webFramewrok4Go-book-*
	rm -f src/revel-webFramewrok4Go-book.*
	rm -f revel-webFramewrok4Go-book.*