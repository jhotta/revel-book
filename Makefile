.PHONY: all
all: main

main:
	cd src && review-epubmaker config.yml
	cd src && review-pdfmaker config.yml
	mv src/revel-webFramewrok4Go-book.epub .
	mv src/revel-webFramewrok4Go-book.pdf .


.PHONY: clean
clean:
	rm -rf src/revel-webFramewrok4Go-book-*
	rm -f src/revel-webFramewrok4Go-book.*
	rm -f revel-webFramewrok4Go-book.*
	