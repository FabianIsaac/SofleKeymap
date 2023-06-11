#ifdef ENCODER_ENABLE

static bool tabbing = false;
static uint16_t tabtimer;
#define TABBING_TIMER 850

bool encoder_update_user(uint8_t index, bool clockwise) {

    switch (get_highest_layer(layer_state)) {

        case _QWERTY:
        case _DEVORAK:
            if (index == 0) { /* First encoder */
                
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }

            } else if (index == 1) { /* Second encoder */
            //Cambia entre una app y otra
            if (clockwise) {
                    tabtimer = timer_read();
                    if(!tabbing) {
                        register_code(KC_LALT);
                        tabbing = true;
                    }
                    tap_code(KC_TAB);
                } else {
                    tabtimer = timer_read();
                    if(!tabbing) {
                        register_code(KC_LALT);
                        tabbing = true;
                    }
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
                
            }
        break;

        case _RAISE:
            if (index == 0) { /* First encoder */
                
                if (clockwise) {
                    tap_code16(LCTL(KC_Y));
                } else {
                    tap_code16(LCTL(KC_Z));
                }
                
            } else if (index == 1) { /* Second encoder */

                if (clockwise) {
                    tabtimer = timer_read();
                    if(!tabbing) {
                        register_code(KC_LALT);
                        tabbing = true;
                    }
                    tap_code(KC_TAB);
                } else {
                    tabtimer = timer_read();
                    if(!tabbing) {
                        register_code(KC_LALT);
                        tabbing = true;
                    }
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }
        break;

        case _LOWER:
        
            if (index == 0) { /* First encoder */
                

                if (clockwise) {
                    tap_code(KC_WH_L);
                } else {
                    tap_code(KC_WH_R);
                }
            } else if (index == 1) { /* Second encoder */
        
                if (clockwise) {
                    tabtimer = timer_read();
                    if(!tabbing) {
                    register_code(KC_LCTL);
                        tabbing = true;
                    }
                    tap_code(KC_TAB);
                } else {
                    tabtimer = timer_read();
                    if(!tabbing) {
                        register_code(KC_LCTL);
                        tabbing = true;
                    }
                    register_code(KC_LSFT);
                    tap_code(KC_TAB);
                    unregister_code(KC_LSFT);
                }
            }

        break;

    }
    return 
    true;
}

void matrix_scan_user(void) {
  if(tabbing) {
    if (timer_elapsed(tabtimer) > TABBING_TIMER) {
      unregister_code(KC_LALT);
      tabbing = false;
    }
  }
}

#endif