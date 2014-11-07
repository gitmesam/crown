/*
 * Copyright (c) 2012-2014 Daniele Bartolini and individual contributors.
 * License: https://github.com/taylor001/crown/blob/master/LICENSE
 */

#pragma once

#include "types.h"
#include "key_code.h"
#include <cstring> // mem*

namespace crown
{

/// Interface for accessing keyboard input device.
///
/// @ingroup Input
struct Keyboard
{
	Keyboard()
		: _modifier(0), _last_button(KeyboardButton::NONE)
	{
		memset(_last_state, 0, KeyboardButton::COUNT);
		memset(_current_state, 0, KeyboardButton::COUNT);
	}

	/// Returns whether the specified @a modifier is pressed.
	/// @note
	/// A modifier is a special key that modifies the normal action
	/// of another key when the two are pressed in combination.
	/// @note
	/// Crown currently supports three different modifier keys: Shift, Ctrl and Alt.
	bool modifier_pressed(ModifierButton::Enum modifier) const
	{
		return (_modifier & (uint8_t) modifier) == modifier;
	}

	/// Returns whether the specified @a b button is pressed in the current frame.
	bool button_pressed(KeyboardButton::Enum b) const
	{
		return (~_last_state[b] & _current_state[b]) != 0;
	}

	/// Returns whether the specified @a b button is released in the current frame.
	bool button_released(KeyboardButton::Enum b) const
	{
		return (_last_state[b] & ~_current_state[b]) != 0;
	}

	/// Returns wheter any button is pressed in the current frame.
	bool any_pressed()
	{
		return button_pressed(_last_button);
	}

	/// Returns whether any button is released in the current frame.
	bool any_released()
	{
		return button_released(_last_button);
	}

	void set_button_state(KeyboardButton::Enum b, bool state)
	{
		_last_button = b;
		_current_state[b] = state;
	}

	void update()
	{
		memcpy(_last_state, _current_state, KeyboardButton::COUNT);
	}

public:

	uint8_t _modifier;

	KeyboardButton::Enum _last_button;
	uint8_t _last_state[KeyboardButton::COUNT];
	uint8_t _current_state[KeyboardButton::COUNT];
};

} // namespace crown
