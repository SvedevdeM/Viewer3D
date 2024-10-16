.PHONY: all clean viewer

all: clean viewer

viewer: 
	cd viewer; make viewer
	./s21_viewer
	
clean:
	rm -rf s21_viewer
