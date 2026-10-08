// Copyright 2026 nathan
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Derived from the epomaker_split65 default keymap:
//   Copyright 2024 yangzheng20003 (@yangzheng20003)
//   SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_record/rgb_record.h"

// Key Overrides
const key_override_t tilde_esc_override  = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));
// Shift+Esc = ~  (tilde)
const key_override_t grave_esc_override  = ko_make_basic(MOD_MASK_GUI,  KC_ESC, KC_GRV);
// GUI+Esc  = `  (grave)
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// Shift+Backspace = Delete

const key_override_t *key_overrides[] = {
    &tilde_esc_override,
    &grave_esc_override,
    &delete_key_override,
};

enum layers {
    _BL = 0,
    _FL,
    _MBL,
    _MFL,
    _RST, /* hold-only recovery layer: reachable solely by holding Fn + the
           * top-right corner key; carries EE_CLR so a factory reset needs a
           * deliberate hold, never a tap. */
};

#define ______ HS_BLACK

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT( /* Base */
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,   
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGUP,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LCMD,  KC_LALT,  KC_SPC,                                 LT(_FL, KC_SPC),   KC_RALT,  KC_RCMD,  KC_RCTL,                      KC_LEFT,  KC_DOWN, KC_RGHT),

    [_FL] = LAYOUT( /* Base */
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,  KC_F12,   _______,  LT(_RST, KC_NO),
        RM_NEXT,  KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   _______,            _______,  _______,  _______, _______,    _______,  RM_HUED, RM_HUEU,  _______,  KC_INS,
        _______,  KC_A,     TO(_MBL), _______,  _______,  _______,            _______,  _______,  _______, _______,    RM_SATD,  RM_SATU, _______,            KC_HOME,
        _______,  _______,  RM_TOGG,  _______,  _______,  _______,            NK_TOGG,  _______,  _______, _______,    QK_BOOT,           _______,  RM_VALU,  KC_END,
        KC_FILP,  GU_TOGG,  RM_SPDD,  _______,                                KC_BATQ,  RM_SPDU,  _______, _______,                       NK_TOGG,  GU_TOGG,  RM_TOGG),

    [_MBL] = LAYOUT( /* Base */
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_DEL,   
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGUP,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LALT,  KC_LGUI,  KC_SPC,                                 LT(_MFL, KC_SPC),   KC_RALT,  KC_RCMD,  KC_RCTL,                      KC_LEFT,  KC_DOWN, KC_RGHT),
    [_MFL] = LAYOUT( /* Base */
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,   KC_F11,  KC_F12,   _______,  LT(_RST, KC_NO),
        RM_NEXT,  KC_BT1,   KC_BT2,   KC_BT3,   KC_2G4,   _______,            _______,  _______,  _______, _______,    _______,  RM_HUED, RM_HUEU,  _______,  KC_INS,
        _______,  TO(_BL),  KC_S,     _______,  _______,  _______,            _______,  _______,  _______, _______,    RM_SATD,  RM_SATU, _______,            KC_HOME,
        _______,  _______,  RM_TOGG,  _______,  _______,  _______,            NK_TOGG,  _______,  _______, _______,    QK_BOOT,           _______,  RM_VALU,  KC_END,
        KC_FILP,  _______,  RM_SPDD,  _______,                                KC_BATQ,  RM_SPDU,  _______, _______,                       NK_TOGG,  GU_TOGG,  RM_TOGG),

    [_RST] = LAYOUT( /* Hold-only recovery layer (reached via LT(_RST, ...) on the
                      * Fn-layer top-right corner). EE_CLR wipes the emulated
                      * EEPROM back to factory defaults; every other key passes
                      * through so the held key itself stays inert.
                      *
                      * EE_CLR sits at the right-half bottom-right corner (the
                      * KC_RGHT position) — the far corner from the Fn-layer key
                      * that arms this layer. Reaching it needs a held Fn chord
                      * from the left hand AND a press on the opposite half's
                      * bottom corner, so it cannot be hit by a single stray
                      * keypress and is nowhere near Backspace.
                      *
                      * NOTE: ______ here is HS_BLACK (0x0000 = KC_NO), NOT
                      * KC_TRNS. That is intentional: KC_NO is not
                      * ACTION_TRANSPARENT, so it blocks fall-through and keeps
                      * the base layer unreachable while reset is armed. Do not
                      * "fix" these to KC_TRNS. */
        _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______, _______,    _______,  _______, _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______, _______,    _______,  _______, _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______, _______,    _______,  _______, _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______, _______,    _______,           _______,  _______,  _______,
        _______,  _______,  _______,  _______,                                _______,  _______,  _______, _______,                       _______,  _______,  EE_CLR),

};


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},  // Base:  volume
    [1] = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},   // Fn:    RGB brightness
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},  // Mac:   volume
    [3] = {ENCODER_CCW_CW(RM_VALD, RM_VALU)},   // MacFn: RGB brightness
};
#endif
// clang-format on

bool is_keyboard_master(void) {
    gpio_set_pin_input(SPLIT_HAND_PIN);
    return gpio_read_pin(SPLIT_HAND_PIN);
}

/* Force a solid white at half brightness instead of the vendor's rainbow wave.
 * RGB_MATRIX_DEFAULT_* only apply to a blank EEPROM, and these halves carry
 * saved RGB settings from the stock firmware, so the stored state wins unless
 * we set it here. This runs on every boot, so it overrides whatever is stored;
 * the *_noeeprom variants keep it out of the wear-levelled flash — the intent
 * is a boot-time override, not a new stored value, so persisting it would only
 * add write churn. */
void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(RGB_MATRIX_DEFAULT_HUE, RGB_MATRIX_DEFAULT_SAT, RGB_MATRIX_DEFAULT_VAL);
}

