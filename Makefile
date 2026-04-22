CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
BUILD_DIR = build

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC))

TARGET = $(BUILD_DIR)/program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
