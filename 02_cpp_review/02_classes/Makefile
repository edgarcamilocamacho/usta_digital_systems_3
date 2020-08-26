PROJECT = classes

$(PROJECT): $(PROJECT).cpp
	g++ -o $(PROJECT) $(PROJECT).cpp

run: $(PROJECT)
	./$(PROJECT)

.PHONY: clean
clean:
	rm -rf $(PROJECT)