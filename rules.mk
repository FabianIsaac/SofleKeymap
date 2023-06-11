#Comprime el codigo
LTO_ENABLE = yes

#Para habilitar la función OLED
OLED_ENABLE = yes

#Perillas / Encoder
ENCODER_ENABLE = yes

#Special Extra Key Doesn’t Work (System, Audio Control Keys)
EXTRAKEY_ENABLE = yes

MOUSEKEY_ENABLE = yes
WPM_ENABLE = no
RGBLIGHT_ENABLE = yes

#Debug options
VERBOSE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no


SPLIT_KEYBOARD = yes

#POINTING_DEVICE_ENABLE = yes
#POINTING_DEVICE_DRIVER = pimoroni_trackball

ifeq ($(PROMICRO), yes)
  BOOTLOADER = caterina
else ifeq ($(ELITEC), yes)
  BOOTLOADER = atmel-dfu
endif
