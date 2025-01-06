# Define directories and files
SRC_DIR := ./src
SUBSRC_SRC_DIR := 1_Randomness
ADDON_SRC := ./src/addon_src
WEB_BUILD := ./webbuild/content

# Define addons and compiler settings
ADDONS := $(wildcard $(ADDON_SRC)/*.c)
CC := emcc
CFLAGS := -Wall -std=c99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os
INCLUDES := -I./include -I E:/raylib/raylib/src -I E:/raylib/raylib/src/external
LIBS := -L. -L E:/raylib/raylib/src -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 \
        -s FORCE_FILESYSTEM=1 --shell-file E:/raylib/raylib/src/shell.html \
        E:/raylib/raylib/src/web/libraylib.a -DPLATFORM_WEB \
        -s EXPORTED_FUNCTIONS=["_free","_malloc","_main"] -s EXPORTED_RUNTIME_METHODS=ccall

# Find all example source files
EXAMPLES := $(shell find $(SRC_DIR) -type f -name '*.c' -not -path '$(ADDON_SRC)/*')

# Define the output paths
OUTPUTS := $(patsubst $(SRC_DIR)/%.c,$(WEB_BUILD)/%/index.html,$(EXAMPLES))

# Build all targets
all: $(OUTPUTS)

# Rule to compile each example
$(WEB_BUILD)/%/index.html: $(SRC_DIR)/%.c $(ADDONS)
	@echo "Creating directory: $(dir $@)"
	mkdir -p $(dir $@)
	$(CC) -o $@ $< $(ADDONS) $(CFLAGS) $(INCLUDES) $(LIBS)
	@echo "Built $< -> $@"

# Clean rule to remove all built files
clean:
	@rm -rf $(WEB_BUILD)
	@echo "Cleaned build directory."

# Optional: Rule to build a specific file
build_example:
	@if [ -z "$(FILE)" ]; then \
		echo "Error: Specify FILE variable (e.g., make build_example FILE=random_dist)"; \
		exit 1; \
	fi
	mkdir -p $(WEB_BUILD)/$(FILE)
	$(CC) -o $(WEB_BUILD)/$(FILE)/index.html $(SRC_DIR)/${SUBSRC_SRC_DIR}/$(FILE).c $(ADDONS) $(CFLAGS) $(INCLUDES) $(LIBS)
	@echo "Built $(SRC_DIR)/1_Randomness/$(FILE).c -> $(WEB_BUILD)/$(FILE)/$(FILE).html"
