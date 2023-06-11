#include QMK_KEYBOARD_H
#include <string.h>
#include "lib/lib8tion/lib8tion.h"


enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _DEFAULTS = 0,
    _QWERTY = 0, //0
    _DEVORAK, //2
    _LOWER,//4
    _RAISE,//8
    _ADJUST //16
    // _MACRO = 32 //32
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_DEVORAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_SAVE,
    KC_EMAIL_ECOM,
    KC_EPRS,
    KC_PASS1,
    KC_PASS2,
    KC_PARA,
    KC_PARC
};


#include "encoder.c"
#include "oled.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  |°¬ |  1!  |  2"  |  3#  |  4$  |  5%  |                    |  6&  |  7/  |  8(  |  9)  |  0=  | '?\  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ´¨  |  +*~ |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,;  |  .:  |  -_  | ESC  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |CAMBIO| LGUI | LAlt |LOWER | /Enter  /       \Space \  |RAISE |       | MENU |   }  |
 *            |      |      |      |Space |/       /         \      \ |Enter | ALTGR | CTXT |   ]` |
 *             `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
   KC_GRV,    KC_1,   KC_2,    KC_3,    KC_4,              KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, \
   KC_TAB,    KC_Q,   KC_W,    KC_E,    KC_R,              KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_BSPC, \
  KC_LSFT,    KC_A,   KC_S,    KC_D,    KC_F,              KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_LBRC,   KC_RBRC, \
 KC_LCTRL,    KC_Z,   KC_X,    KC_C,    KC_V,              KC_B, KC_MUTE,     XXXXXXX,  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   QK_GESC, \
              LALT(KC_TAB), KC_LGUI, KC_LALT,MO(2),  KC_ENT,      KC_SPC, MO(3), KC_RALT,  KC_APP, LCTL(KC_LCTRL) \
),
/*
 * Devorak
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  |°¬ |  1!  |  2"  |  3#  |  4$  |  5%  |                    |  6&  |  7/  |  8(  |  9)  |  0=  | '?\  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   :  |   ;  |   P  |   Y  |   F  |                    |   G  |   C  |   H  |   L  |  ´¨  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   R  |   T  |   N  |   S  |  +*~ |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LCtrl |  <>  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  | ESC  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
*             |CAMBIO| LGUI | LAlt |LOWER | /Enter  /       \Space \  |RAISE |       |   {  |   }  |
 *            |      |      |      |Space |/       /         \      \ |Enter | ALTGR |  [^  |   ]` |
 *             `----------------------------------'           '------''---------------------------'
 */
[_DEVORAK] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______, \
  _______,  KC_DOT, KC_COMM,    KC_P,    KC_Y,    KC_F,                            KC_G,    KC_C,    KC_H,    KC_L, KC_LBRC, _______, \
  _______,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                            KC_D,    KC_R,    KC_T,    KC_N,    KC_S, _______, \
  _______, KC_NUBS,    KC_Q,    KC_J,    KC_K,    KC_X, KC_MUTE,       XXXXXXX,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, _______, \
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |  (   |      |  )   |      |     |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |Reload|      |                    |   "  |  <   |   ?  |  >   |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |S. All| Save |      | Find |      |-------.    ,-------|   '  |  {   |   =  |  }   |  -_  |  +   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift| Undo | Cut  | Copy | Past | SPast|-------|    |-------|   .  |  [   |   /  |  ]   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
*             |CAMBIO| LGUI | LAlt |LOWER | /Enter  /       \Space \  |RAISE |       |   {  |   }  |
 *            |      |      |      |      |/       /         \      \ |      | ALTGR |  [^  |   ]` |
 *             `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,                        XXXXXXX,  LSFT(KC_8),       XXXXXXX,    LSFT(KC_9),  XXXXXXX, XXXXXXX, \
  _______,    XXXXXXX,    XXXXXXX,    XXXXXXX, LCTL(KC_R),       XXXXXXX,                     LSFT(KC_2),      KC_NUBS, LSFT(KC_MINS),  LSFT(KC_NUBS),  XXXXXXX, _______, \
  _______, LCTL(KC_A), LCTL(KC_S),    XXXXXXX, LCTL(KC_F),       XXXXXXX,                        KC_MINS,      KC_QUOT,     LSFT(KC_0),       KC_BSLS,  KC_SLSH, KC_RBRC, \
  _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),    LGUI(KC_V),  KC_MPLY,    _______,    KC_DOT, LSFT(KC_QUOT),   LSFT(KC_7),  LSFT(KC_BSLS), XXXXXXX, _______, \
                          _______,    _______,    _______,       _______,  _______,    _______,     MO(4),      _______,       _______,        _______\
), 
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10  | F11  | F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Ins  | Pscr | Menu |      |      |                    |      | Home |  Up  | End  | DLine| Bspc |
 * |      |      |      |      |      |      |                    |      |REPAG |      |AVPAG |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Shift| LAt  | LCtl |LShift|      |      |-------.    ,-------|      | Left | Down | Rigth|  Del |      |
 * |------+------+------+------+------+------|  MPLY |    |       |------+------+------+------+------+------|
 * | CTRL | Undo |  Cut | Copy | Paste|SPaste|-------|    |-------|      | LStr |      | LEnd |      | ENT  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |CAMBIO| LGUI | LAlt |LOWER | /Enter  /       \Space \  |RAISE |       |   {  |   }  |
 *            |      |      |      |Space |/       /         \      \ |Enter | ALTGR |  [^  |   ]` |
 *             `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
    KC_F1,      KC_F2,      KC_F3,       KC_F4,      KC_F5,      KC_F6,                             KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12, \
  _______,     KC_INS,    KC_PSCR,      KC_APP,    XXXXXXX,    XXXXXXX,                           KC_PGUP, KC_LSTRT,   KC_UP,  KC_LEND, KC_DLINE, KC_BSPC, \
  _______,    KC_LALT,    KC_LCTL,     KC_LSFT,    XXXXXXX,    XXXXXXX,                           KC_PGDN,  KC_LEFT, KC_DOWN,  KC_RGHT,   KC_DEL, XXXXXXX, \
  _______,    XXXXXXX,    XXXXXXX,     XXXXXXX,    XXXXXXX,    XXXXXXX,  KC_MPLY,       _______,  XXXXXXX, KC_PRVWD, XXXXXXX, KC_NXTWD,  XXXXXXX,  KC_ENT, \
                          _______,     _______,    _______,      MO(4),  _______,       _______,  _______,  _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |RESET |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |MACWIN|QWERTY|COLEMA|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TOG  |  HUI | SAI  | VAI  | SPI  | Caps |-------.    ,-------|      | PREV | PLAY | NEXT |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | MOD  |  HUD | SAD  | VAD  | SPD  |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *             `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  RESET  , XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, CG_TOGG,KC_QWERTY,KC_DEVORAK, XXXXXXX,  XXXXXXX,                       KC_EMAIL_ECOM, KC_EPRS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RGB_TOG, RGB_HUI,  RGB_SAI,   RGB_VAI, RGB_SPI,  KC_CAPS,                       XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
  RGB_MOD, RGB_HUD,  RGB_SAD,   RGB_VAD, RGB_SPD,  XXXXXXX, XXXXXXX,     XXXXXXX, KC_PASS1, KC_PASS2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                        _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *             `----------------------------------'           '------''---------------------------'
 */
/*   [_MACRO] = LAYOUT( \
//   XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//   XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//   XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//   XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
//                    _______, _______, _______, _______, _______,     _______, _______, KC_APP, _______, _______ \
//   )*/
};




//funcion que recibe dos teclas y las ejecuta
bool dos_teclas(uint16_t keycode_uno, uint16_t keycode_dos, keyrecord_t *record){
    if (record->event.pressed) {
        register_mods(mod_config(keycode_uno));
        register_code(keycode_dos);
    } else {
        unregister_mods(mod_config(keycode_uno));
        unregister_code(keycode_dos);
    }
    return false;
}


uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_DEVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DEVORAK);
            }
            return false;

        
        case KC_BSPC:
        {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }

        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            return dos_teclas(MOD_LCTL, KC_BSPC, record);

        case KC_EMAIL_ECOM:
            if (record->event.pressed) {
                SEND_STRING("email1");
            }
            break;
        case KC_EPRS:
            if (record->event.pressed) {
                SEND_STRING("email2");
            }
            break;
        case KC_PASS1:
            if (record->event.pressed) {
                SEND_STRING("password");
            }
            break;
        case KC_PASS2:
            if (record->event.pressed) {
                SEND_STRING("password");
            }
            break;
    }
    return true;
}

void keyboard_post_init_kb(void) {

}

