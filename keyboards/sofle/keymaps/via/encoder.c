 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

//Setting up what encoder rotation does. If your encoder can be pressed as a button, that function can be set in Via.

#ifdef ENCODER_ENABLE
bool shift_held = false;
static uint16_t held_shift = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
				case 0:
                    if (clockwise) {
                        tap_code(KC_WH_D);
                    } else {
                        tap_code(KC_WH_U);
                    }
				break;
			    case 3:
                    if (clockwise) {
                        tap_code16(C(KC_RGHT));
                    } else {
                        tap_code16(C(KC_LEFT));
                    }
                break;
			default:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
				break;
		}

		} else if (index == 1) {
			switch (get_highest_layer(layer_state)) {
				case 0:
                    if (clockwise) {
                        tap_code(KC_VOLU);
                    } else {
                        tap_code(KC_VOLD);
                    }
				break;
			    case 2:
					if (clockwise) {
                        tap_code16(C(KC_TAB));
                    } else {
                        tap_code16(S(C(KC_TAB)));
                    }
				break;
			    default:
					if (clockwise) {
                        tap_code(KC_PGDN);
                    } else {
                        tap_code(KC_PGUP);
                    }
				break;
		}
    }
    return true;
}

#endif
