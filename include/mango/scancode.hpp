#pragma once

/*
    The scancodes... copied from SDL2's SDL2/SDL_scancode.h
    Thank them.
*/

typedef enum mango_scancodes {
    MANGO_SCANCODE_UNKNOWN = 0,
    MANGO_SCANCODE_A = 4,
    MANGO_SCANCODE_B = 5,
    MANGO_SCANCODE_C = 6,
    MANGO_SCANCODE_D = 7,
    MANGO_SCANCODE_E = 8,
    MANGO_SCANCODE_F = 9,
    MANGO_SCANCODE_G = 10,
    MANGO_SCANCODE_H = 11,
    MANGO_SCANCODE_I = 12,
    MANGO_SCANCODE_J = 13,
    MANGO_SCANCODE_K = 14,
    MANGO_SCANCODE_L = 15,
    MANGO_SCANCODE_M = 16,
    MANGO_SCANCODE_N = 17,
    MANGO_SCANCODE_O = 18,
    MANGO_SCANCODE_P = 19,
    MANGO_SCANCODE_Q = 20,
    MANGO_SCANCODE_R = 21,
    MANGO_SCANCODE_S = 22,
    MANGO_SCANCODE_T = 23,
    MANGO_SCANCODE_U = 24,
    MANGO_SCANCODE_V = 25,
    MANGO_SCANCODE_W = 26,
    MANGO_SCANCODE_X = 27,
    MANGO_SCANCODE_Y = 28,
    MANGO_SCANCODE_Z = 29,
    MANGO_SCANCODE_1 = 30,
    MANGO_SCANCODE_2 = 31,
    MANGO_SCANCODE_3 = 32,
    MANGO_SCANCODE_4 = 33,
    MANGO_SCANCODE_5 = 34,
    MANGO_SCANCODE_6 = 35,
    MANGO_SCANCODE_7 = 36,
    MANGO_SCANCODE_8 = 37,
    MANGO_SCANCODE_9 = 38,
    MANGO_SCANCODE_0 = 39,
    MANGO_SCANCODE_RETURN = 40,
    MANGO_SCANCODE_ESCAPE = 41,
    MANGO_SCANCODE_BACKSPACE = 42,
    MANGO_SCANCODE_TAB = 43,
    MANGO_SCANCODE_SPACE = 44,
    MANGO_SCANCODE_MINUS = 45,
    MANGO_SCANCODE_EQUALS = 46,
    MANGO_SCANCODE_LEFTBRACKET = 47,
    MANGO_SCANCODE_RIGHTBRACKET = 48,
    MANGO_SCANCODE_BACKSLASH = 49, 
    MANGO_SCANCODE_NONUSHASH = 50, 
    MANGO_SCANCODE_SEMICOLON = 51,
    MANGO_SCANCODE_APOSTROPHE = 52,
    MANGO_SCANCODE_GRAVE = 53,
    MANGO_SCANCODE_COMMA = 54,
    MANGO_SCANCODE_PERIOD = 55,
    MANGO_SCANCODE_SLASH = 56,
    MANGO_SCANCODE_CAPSLOCK = 57,
    MANGO_SCANCODE_F1 = 58,
    MANGO_SCANCODE_F2 = 59,
    MANGO_SCANCODE_F3 = 60,
    MANGO_SCANCODE_F4 = 61,
    MANGO_SCANCODE_F5 = 62,
    MANGO_SCANCODE_F6 = 63,
    MANGO_SCANCODE_F7 = 64,
    MANGO_SCANCODE_F8 = 65,
    MANGO_SCANCODE_F9 = 66,
    MANGO_SCANCODE_F10 = 67,
    MANGO_SCANCODE_F11 = 68,
    MANGO_SCANCODE_F12 = 69,
    MANGO_SCANCODE_PRINTSCREEN = 70,
    MANGO_SCANCODE_SCROLLLOCK = 71,
    MANGO_SCANCODE_PAUSE = 72,
    MANGO_SCANCODE_INSERT = 73, 
    MANGO_SCANCODE_HOME = 74,
    MANGO_SCANCODE_PAGEUP = 75,
    MANGO_SCANCODE_DELETE = 76,
    MANGO_SCANCODE_END = 77,
    MANGO_SCANCODE_PAGEDOWN = 78,
    MANGO_SCANCODE_RIGHT = 79,
    MANGO_SCANCODE_LEFT = 80,
    MANGO_SCANCODE_DOWN = 81,
    MANGO_SCANCODE_UP = 82,
    MANGO_SCANCODE_NUMLOCKCLEAR = 83,
    MANGO_SCANCODE_KP_DIVIDE = 84,
    MANGO_SCANCODE_KP_MULTIPLY = 85,
    MANGO_SCANCODE_KP_MINUS = 86,
    MANGO_SCANCODE_KP_PLUS = 87,
    MANGO_SCANCODE_KP_ENTER = 88,
    MANGO_SCANCODE_KP_1 = 89,
    MANGO_SCANCODE_KP_2 = 90,
    MANGO_SCANCODE_KP_3 = 91,
    MANGO_SCANCODE_KP_4 = 92,
    MANGO_SCANCODE_KP_5 = 93,
    MANGO_SCANCODE_KP_6 = 94,
    MANGO_SCANCODE_KP_7 = 95,
    MANGO_SCANCODE_KP_8 = 96,
    MANGO_SCANCODE_KP_9 = 97,
    MANGO_SCANCODE_KP_0 = 98,
    MANGO_SCANCODE_KP_PERIOD = 99,
    MANGO_SCANCODE_NONUSBACKSLASH = 100,
    MANGO_SCANCODE_APPLICATION = 101, /**< windows contextual menu, compose */
    MANGO_SCANCODE_POWER = 102,
    MANGO_SCANCODE_KP_EQUALS = 103,
    MANGO_SCANCODE_F13 = 104,
    MANGO_SCANCODE_F14 = 105,
    MANGO_SCANCODE_F15 = 106,
    MANGO_SCANCODE_F16 = 107,
    MANGO_SCANCODE_F17 = 108,
    MANGO_SCANCODE_F18 = 109,
    MANGO_SCANCODE_F19 = 110,
    MANGO_SCANCODE_F20 = 111,
    MANGO_SCANCODE_F21 = 112,
    MANGO_SCANCODE_F22 = 113,
    MANGO_SCANCODE_F23 = 114,
    MANGO_SCANCODE_F24 = 115,
    MANGO_SCANCODE_EXECUTE = 116,
    MANGO_SCANCODE_HELP = 117,    /**< AL Integrated Help Center */
    MANGO_SCANCODE_MENU = 118,    /**< Menu (show menu) */
    MANGO_SCANCODE_SELECT = 119,
    MANGO_SCANCODE_STOP = 120,    /**< AC Stop */
    MANGO_SCANCODE_AGAIN = 121,   /**< AC Redo/Repeat */
    MANGO_SCANCODE_UNDO = 122,    /**< AC Undo */
    MANGO_SCANCODE_CUT = 123,     /**< AC Cut */
    MANGO_SCANCODE_COPY = 124,    /**< AC Copy */
    MANGO_SCANCODE_PASTE = 125,   /**< AC Paste */
    MANGO_SCANCODE_FIND = 126,    /**< AC Find */
    MANGO_SCANCODE_MUTE = 127,
    MANGO_SCANCODE_VOLUMEUP = 128,
    MANGO_SCANCODE_VOLUMEDOWN = 129,
/* not sure whether there's a reason to enable these */
/*     MANGO_SCANCODE_LOCKINGCAPSLOCK = 130,  */
/*     MANGO_SCANCODE_LOCKINGNUMLOCK = 131, */
/*     MANGO_SCANCODE_LOCKINGSCROLLLOCK = 132, */
    MANGO_SCANCODE_KP_COMMA = 133,
    MANGO_SCANCODE_KP_EQUALSAS400 = 134,
    MANGO_SCANCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    MANGO_SCANCODE_INTERNATIONAL2 = 136,
    MANGO_SCANCODE_INTERNATIONAL3 = 137, /**< Yen */
    MANGO_SCANCODE_INTERNATIONAL4 = 138,
    MANGO_SCANCODE_INTERNATIONAL5 = 139,
    MANGO_SCANCODE_INTERNATIONAL6 = 140,
    MANGO_SCANCODE_INTERNATIONAL7 = 141,
    MANGO_SCANCODE_INTERNATIONAL8 = 142,
    MANGO_SCANCODE_INTERNATIONAL9 = 143,
    MANGO_SCANCODE_LANG1 = 144, /**< Hangul/English toggle */
    MANGO_SCANCODE_LANG2 = 145, /**< Hanja conversion */
    MANGO_SCANCODE_LANG3 = 146, /**< Katakana */
    MANGO_SCANCODE_LANG4 = 147, /**< Hiragana */
    MANGO_SCANCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
    MANGO_SCANCODE_LANG6 = 149, /**< reserved */
    MANGO_SCANCODE_LANG7 = 150, /**< reserved */
    MANGO_SCANCODE_LANG8 = 151, /**< reserved */
    MANGO_SCANCODE_LANG9 = 152, /**< reserved */

    MANGO_SCANCODE_ALTERASE = 153,    /**< Erase-Eaze */
    MANGO_SCANCODE_SYSREQ = 154,
    MANGO_SCANCODE_CANCEL = 155,      /**< AC Cancel */
    MANGO_SCANCODE_CLEAR = 156,
    MANGO_SCANCODE_PRIOR = 157,
    MANGO_SCANCODE_RETURN2 = 158,
    MANGO_SCANCODE_SEPARATOR = 159,
    MANGO_SCANCODE_OUT = 160,
    MANGO_SCANCODE_OPER = 161,
    MANGO_SCANCODE_CLEARAGAIN = 162,
    MANGO_SCANCODE_CRSEL = 163,
    MANGO_SCANCODE_EXSEL = 164,

    MANGO_SCANCODE_KP_00 = 176,
    MANGO_SCANCODE_KP_000 = 177,
    MANGO_SCANCODE_THOUSANDSSEPARATOR = 178,
    MANGO_SCANCODE_DECIMALSEPARATOR = 179,
    MANGO_SCANCODE_CURRENCYUNIT = 180,
    MANGO_SCANCODE_CURRENCYSUBUNIT = 181,
    MANGO_SCANCODE_KP_LEFTPAREN = 182,
    MANGO_SCANCODE_KP_RIGHTPAREN = 183,
    MANGO_SCANCODE_KP_LEFTBRACE = 184,
    MANGO_SCANCODE_KP_RIGHTBRACE = 185,
    MANGO_SCANCODE_KP_TAB = 186,
    MANGO_SCANCODE_KP_BACKSPACE = 187,
    MANGO_SCANCODE_KP_A = 188,
    MANGO_SCANCODE_KP_B = 189,
    MANGO_SCANCODE_KP_C = 190,
    MANGO_SCANCODE_KP_D = 191,
    MANGO_SCANCODE_KP_E = 192,
    MANGO_SCANCODE_KP_F = 193,
    MANGO_SCANCODE_KP_XOR = 194,
    MANGO_SCANCODE_KP_POWER = 195,
    MANGO_SCANCODE_KP_PERCENT = 196,
    MANGO_SCANCODE_KP_LESS = 197,
    MANGO_SCANCODE_KP_GREATER = 198,
    MANGO_SCANCODE_KP_AMPERSAND = 199,
    MANGO_SCANCODE_KP_DBLAMPERSAND = 200,
    MANGO_SCANCODE_KP_VERTICALBAR = 201,
    MANGO_SCANCODE_KP_DBLVERTICALBAR = 202,
    MANGO_SCANCODE_KP_COLON = 203,
    MANGO_SCANCODE_KP_HASH = 204,
    MANGO_SCANCODE_KP_SPACE = 205,
    MANGO_SCANCODE_KP_AT = 206,
    MANGO_SCANCODE_KP_EXCLAM = 207,
    MANGO_SCANCODE_KP_MEMSTORE = 208,
    MANGO_SCANCODE_KP_MEMRECALL = 209,
    MANGO_SCANCODE_KP_MEMCLEAR = 210,
    MANGO_SCANCODE_KP_MEMADD = 211,
    MANGO_SCANCODE_KP_MEMSUBTRACT = 212,
    MANGO_SCANCODE_KP_MEMMULTIPLY = 213,
    MANGO_SCANCODE_KP_MEMDIVIDE = 214,
    MANGO_SCANCODE_KP_PLUSMINUS = 215,
    MANGO_SCANCODE_KP_CLEAR = 216,
    MANGO_SCANCODE_KP_CLEARENTRY = 217,
    MANGO_SCANCODE_KP_BINARY = 218,
    MANGO_SCANCODE_KP_OCTAL = 219,
    MANGO_SCANCODE_KP_DECIMAL = 220,
    MANGO_SCANCODE_KP_HEXADECIMAL = 221,

    MANGO_SCANCODE_LCTRL = 224,
    MANGO_SCANCODE_LSHIFT = 225,
    MANGO_SCANCODE_LALT = 226, /**< alt, option */
    MANGO_SCANCODE_LGUI = 227, /**< windows, command (apple), meta */
    MANGO_SCANCODE_RCTRL = 228,
    MANGO_SCANCODE_RSHIFT = 229,
    MANGO_SCANCODE_RALT = 230, /**< alt gr, option */
    MANGO_SCANCODE_RGUI = 231, /**< windows, command (apple), meta */

    MANGO_SCANCODE_MODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   special KMOD_MODE for it I'm adding it here
                                 */

    MANGO_SCANCODE_AUDIONEXT = 258,
    MANGO_SCANCODE_AUDIOPREV = 259,
    MANGO_SCANCODE_AUDIOSTOP = 260,
    MANGO_SCANCODE_AUDIOPLAY = 261,
    MANGO_SCANCODE_AUDIOMUTE = 262,
    MANGO_SCANCODE_MEDIASELECT = 263,
    MANGO_SCANCODE_WWW = 264,             /**< AL Internet Browser */
    MANGO_SCANCODE_MAIL = 265,
    MANGO_SCANCODE_CALCULATOR = 266,      /**< AL Calculator */
    MANGO_SCANCODE_COMPUTER = 267,
    MANGO_SCANCODE_AC_SEARCH = 268,       /**< AC Search */
    MANGO_SCANCODE_AC_HOME = 269,         /**< AC Home */
    MANGO_SCANCODE_AC_BACK = 270,         /**< AC Back */
    MANGO_SCANCODE_AC_FORWARD = 271,      /**< AC Forward */
    MANGO_SCANCODE_AC_STOP = 272,         /**< AC Stop */
    MANGO_SCANCODE_AC_REFRESH = 273,      /**< AC Refresh */
    MANGO_SCANCODE_AC_BOOKMARKS = 274,    /**< AC Bookmarks */

    /* @} *//* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    MANGO_SCANCODE_BRIGHTNESSDOWN = 275,
    MANGO_SCANCODE_BRIGHTNESSUP = 276,
    MANGO_SCANCODE_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
    MANGO_SCANCODE_KBDILLUMTOGGLE = 278,
    MANGO_SCANCODE_KBDILLUMDOWN = 279,
    MANGO_SCANCODE_KBDILLUMUP = 280,
    MANGO_SCANCODE_EJECT = 281,
    MANGO_SCANCODE_SLEEP = 282,           /**< SC System Sleep */

    MANGO_SCANCODE_APP1 = 283,
    MANGO_SCANCODE_APP2 = 284,

    /* @} *//* Walther keys */

    /**
     *  \name Usage page 0x0C (additional media keys)
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    MANGO_SCANCODE_AUDIOREWIND = 285,
    MANGO_SCANCODE_AUDIOFASTFORWARD = 286,

    /* @} *//* Usage page 0x0C (additional media keys) */

    /**
     *  \name Mobile keys
     *
     *  These are values that are often used on mobile phones.
     */
    /* @{ */

    MANGO_SCANCODE_SOFTLEFT = 287, /**< Usually situated below the display on phones and
                                      used as a multi-function feature key for selecting
                                      a software defined function shown on the bottom left
                                      of the display. */
    MANGO_SCANCODE_SOFTRIGHT = 288, /**< Usually situated below the display on phones and
                                       used as a multi-function feature key for selecting
                                       a software defined function shown on the bottom right
                                       of the display. */
    MANGO_SCANCODE_CALL = 289, /**< Used for accepting phone calls. */
    MANGO_SCANCODE_ENDCALL = 290, /**< Used for rejecting phone calls. */

    /* @} *//* Mobile keys */

    /* Add any other keys here. */

    MANGO_NUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
                                 for array bounds */
} mango_scancodes;