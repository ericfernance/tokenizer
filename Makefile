CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4)
LIBS = $(shell $(PKGCONFIG) --libs gtk4)
GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)

SRC = app.c win.c main.c
BUILT_SRC = resources.c

BUILD_DIR = build

OBJS = $(addprefix $(BUILD_DIR)/, $(BUILT_SRC:.c=.o) $(SRC:.c=.o))

all: $(BUILD_DIR)/tokenizer

$(BUILD_DIR)/resources.c: tokenizer.gresource.xml window.ui | $(BUILD_DIR)
	$(GLIB_COMPILE_RESOURCES) tokenizer.gresource.xml --target=$@ --sourcedir=. --generate-source

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c -o $@ $(CFLAGS) $<

$(BUILD_DIR)/tokenizer: $(OBJS) | $(BUILD_DIR)
	$(CC) -o $@ $(OBJS) $(LIBS)

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -f $(BUILD_DIR)/$(BUILT_SRC)
	rm -f $(BUILD_DIR)/$(OBJS)
	rm -f $(BUILD_DIR)/tokenizer
	rmdir $(BUILD_DIR) 2>/dev/null || true
