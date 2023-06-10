CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4 gtksourceview-5)
LIBS = $(shell $(PKGCONFIG) --libs gtk4 gtksourceview-5 cmocka)
GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)
SRC = jwt.c app.c win.c main.c
BUILT_SRC = resources.c
BUILD_DIR = build
OBJS = $(addprefix $(BUILD_DIR)/, $(BUILT_SRC:.c=.o) $(SRC:.c=.o))

all: $(BUILD_DIR)/tokenizer

$(BUILD_DIR)/resources.c: tokenizer.gresource.xml | $(BUILD_DIR)
	$(GLIB_COMPILE_RESOURCES) tokenizer.gresource.xml --target=$@ --sourcedir=. --generate-source

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $(CFLAGS) $<

$(BUILD_DIR)/tokenizer: $(OBJS) | $(BUILD_DIR)
	$(CC) -o $@ $(OBJS) $(LIBS)

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

install:
	cp $(BUILD_DIR)/tokenizer /usr/local/bin

uninstall:
	rm -f /usr/local/bin/tokenizer

test: test.c
	$(CC) -o test jwt.c test.c $(CFLAGS) $(LIBS)
	./test
	rm -f test

