EXEC = bin/mycat

COMPILER = gcc

FLAGS = -std=c2x -Wall

MAIN = main.c

BIN_PATH = /usr/local/bin

$(EXEC): $(MAIN)
	$(COMPILER) $(FLAGS) -o $(EXEC) $(MAIN)

run: $(EXEC)
	$(EXEC)

clean:
	rm -f $(EXEC)

install: $(EXEC)
	install -m 755 $(EXEC) $(BIN_PATH)/mycat

uninstall:
	rm -f $(BIN_PATH)/mycat
