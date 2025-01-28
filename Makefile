CC            = /usr/bin/gcc
CFLAGS        = -std=c11 -Werror -fsanitize=address
CFLAGS_STRICT = -std=c11 -Wall -Werror -fsanitize=address
TARGET        = src/main
OUT           = bin/main
INCLUDE       = -I ./raylib/include
LINK          = -L ./raylib/lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all: $(TARGET)

$(TARGET): $(TARGET).c
	mkdir -p bin
	$(CC) $(INCLUDE) $(CFLAGS) -o $(OUT) $(TARGET).c $(LINK)

clean:
	rm -rf ./bin
