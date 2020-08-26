PROJECT = structures

$(PROJECT): $(PROJECT).c
	gcc -o $(PROJECT) $(PROJECT).c

run: $(PROJECT)
	./$(PROJECT)

.PHONY: clean
clean:
	rm -rf $(PROJECT)