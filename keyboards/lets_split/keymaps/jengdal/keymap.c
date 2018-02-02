#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _QWERTY_MIRROR 5
#define _LOWER_MIRROR 6
#define _RAISE_MIRROR 7
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MIRROR_OR_SPACE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  GUI |Adjust|Lower |Rgt/Spc|Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,                        KC_Y,                        KC_U,         KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,         KC_G,                        KC_H,                        KC_J,         KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,                        KC_N,                        KC_M,         KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  KC_LCTRL,KC_LALT, KC_LGUI, ADJUST,  TO(_LOWER),   LT(_QWERTY_MIRROR, KC_SPC),  LT(_QWERTY_MIRROR, KC_SPC),  TO(_RAISE),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_QWERTY_MIRROR] = KEYMAP( \
  KC_BSPC,  KC_P,     KC_O,    KC_I,    KC_U,      KC_Y,    KC_T,     KC_R,         KC_E,    KC_W,    KC_Q,    KC_ESC, \
  KC_QUOT,  KC_SCLN,  KC_L,    KC_K,    KC_J,      KC_H,    KC_G,     KC_F,         KC_D,    KC_S,    KC_A,    KC_TAB, \
  KC_ENT,   KC_SLSH,  KC_DOT,  KC_COMM, KC_M,      KC_N,    KC_B,     KC_V,         KC_C,    KC_X,    KC_Z,    KC_LSFT, \
  KC_LCTRL, KC_LALT,  KC_LGUI, ADJUST,  TO(_RAISE),_______, _______,  TO(_LOWER),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |      |   \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, TO(_QWERTY), LT(_LOWER_MIRROR, KC_SPC), _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_LOWER_MIRROR] = KEYMAP( \
  KC_DEL,   KC_RPRN,  KC_LPRN,   KC_ASTR,    KC_AMPR,     KC_CIRC, KC_PERC, KC_DLR, KC_HASH, KC_AT, KC_EXLM, KC_TILD, \
  KC_PIPE,  KC_RCBR,  KC_LCBR,   KC_PLUS,    KC_UNDS,     KC_F6,   KC_F5,   KC_F4, KC_F3, KC_F2, KC_F1, KC_DEL, \
  _______,  _______,  _______,   S(KC_NUBS), S(KC_NUHS),  KC_F12,  KC_F11,KC_F10,KC_F9,KC_F8, KC_F7, _______, \
  KC_MPLY,  KC_VOLU,  KC_VOLD,   KC_MNXT,    _______,     _______, _______, _______, _______, _______, _______, _______ \
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, TO(_QWERTY), LT(_RAISE_MIRROR, KC_SPC), _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_RAISE_MIRROR] = KEYMAP( \
  KC_DEL,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_6,    KC_5,    KC_3,    KC_2,    KC_1,    KC_GRV, \
  KC_BSLS,  KC_RBRC,   KC_LBRC,   KC_EQL,   KC_MINS,   KC_F6,   KC_F5,   KC_F4, KC_F3,  KC_F2, KC_F1, KC_DEL, \
  _______, _______, _______,   KC_NUBS,   KC_NUHS,  KC_F12,  KC_F11,  KC_F10, KC_F9, KC_F8, KC_F7, _______, \
  KC_MPLY,  KC_VOLU,  KC_VOLD,   KC_MNXT,    _______,     _______, _______, _______, _______, _______, _______, _______ \
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, _______, _______, AG_NORM, AG_SWAP,  QWERTY,  _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
