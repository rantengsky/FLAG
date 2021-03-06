SRCS = $(shell ls *.c)
OBJS = $(SRCS:%.c=%.o)
TARGET = $(BIN_PATH)/ublox-driver

CFLAGS := $(CFLAGS_STD) $(CFLAGS_COMMON) $(CFLAGS_APRIL_LCMTYPES) $(CFLAGS_LCM)
LDFLAGS := $(LDFLAGS_STD) $(LDFLAGS_COMMON) $(LDFLAGS_APRIL_LCMTYPES) $(LDFLAGS_LCM)
DEPS := $(DEPS_STD) $(DEPS_COMMON) $(DEPS_APRIL_LCMTYPES) $(DEPS_LCM)

include $(BUILD_COMMON)


all: $(TARGET)
	@true

$(TARGET): $(OBJS) $(DEPS)
	@$(LD) -o $@ $^ $(LDFLAGS)

clean:
	@rm -rf *.o $(TARGET)
