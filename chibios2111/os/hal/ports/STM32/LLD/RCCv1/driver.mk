ifeq ($(USE_SMART_BUILD),yes)
PLATFORMSRC +=
else
PLATFORMSRC +=
endif

PLATFORMINC += $(CHIBIOS)/os/hal/ports/STM32/LLD/RCCv1
