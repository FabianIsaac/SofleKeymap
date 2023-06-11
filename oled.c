#ifdef OLED_ENABLE

#include <stdio.h>

static void print_status_narrow(void) {

    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE "), false);
    oled_write_ln_P(PSTR(""), true);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR(" MAC"), false);
    } else {
        oled_write_ln_P(PSTR(" WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("qwrty"), false);
            
            break;
        case _DEVORAK:
            oled_write_ln_P(PSTR("dvork"), true);
            
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }


    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {

        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            // pimoroni_trackball_set_rgbw(28, 40, 51, 0.2);
            break;
        case _DEVORAK:
            oled_write_P(PSTR("Base\n"), false);
            // pimoroni_trackball_set_rgbw(88, 214, 141, 0.5);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            // pimoroni_trackball_set_rgbw(169, 50, 38, 0.5);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            // pimoroni_trackball_set_rgbw(44, 23, 221, 0.5);
            break;
        case _ADJUST:
            oled_write_P(PSTR(" Adj "), false);
            // pimoroni_trackball_set_rgbw(241, 196, 15, 0.5);
            break;


        default:
            oled_write_ln_P(PSTR("Undef"), false);

    }
    oled_write_P(PSTR("\n\n"), false);

    led_t led_usb_state = host_keyboard_led_state();

    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);

    // if(led_usb_state.caps_lock){
    //     pimoroni_trackball_set_rgbw(22, 187, 22, 0.5);
    // }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    }
    return false;
}
#endif