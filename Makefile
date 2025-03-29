CC = gcc
CFLAGS = -Wall -Wextra -I./src -I./src/menu -I./src/csv_handler -I./src/sorter
LDFLAGS = 

SRC_DIR = src
MODULES_DIRS = menu csv_handler sorter
BIN_DIR = bin
BUILD_DIR = build

TARGET = $(BIN_DIR)/student-data-organizer

SRC = $(wildcard $(SRC_DIR)/*.c) $(foreach dir, $(MODULES_DIRS), $(wildcard $(SRC_DIR)/$(dir)/*.c))
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
