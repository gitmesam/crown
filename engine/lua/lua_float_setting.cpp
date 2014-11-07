/*
 * Copyright (c) 2012-2014 Daniele Bartolini and individual contributors.
 * License: https://github.com/taylor001/crown/blob/master/LICENSE
 */

#include "float_setting.h"
#include "lua_stack.h"
#include "lua_environment.h"

namespace crown
{

static int float_setting_value(lua_State* L)
{
	LuaStack stack(L);

	const char* setting_name = stack.get_string(1);

	FloatSetting* setting = FloatSetting::find_setting(setting_name);

	if (setting != NULL)
	{
		stack.push_float(setting->value());
	}
	else
	{
		stack.push_float(0.0f);
	}

	return 1;
}

static int float_setting_synopsis(lua_State* L)
{
	LuaStack stack(L);

	const char* setting_name = stack.get_string(1);

	FloatSetting* setting = FloatSetting::find_setting(setting_name);

	if (setting != NULL)
	{
		stack.push_string(setting->synopsis());
	}
	else
	{
		stack.push_string("");
	}

	return 1;
}

static int float_setting_min(lua_State* L)
{
	LuaStack stack(L);

	const char* setting_name = stack.get_string(1);

	FloatSetting* setting = FloatSetting::find_setting(setting_name);

	if (setting != NULL)
	{
		stack.push_float(setting->min());
	}
	else
	{
		stack.push_float(0);
	}

	return 1;
}

static int float_setting_max(lua_State* L)
{
	LuaStack stack(L);

	const char* setting_name = stack.get_string(1);

	FloatSetting* setting = FloatSetting::find_setting(setting_name);

	if (setting != NULL)
	{
		stack.push_float(setting->max());
	}
	else
	{
		stack.push_float(0);
	}

	return 1;
}

static int float_setting_update(lua_State* L)
{
	LuaStack stack(L);

	const char* setting_name = stack.get_string(1);
	const float setting_value = stack.get_float(2);

	FloatSetting* setting = FloatSetting::find_setting(setting_name);

	if (setting != NULL)
	{
		(*setting) = setting_value;
	}

	return 0;
}

void load_float_setting(LuaEnvironment& env)
{
	env.load_module_function("FloatSetting", "value",    float_setting_value);
	env.load_module_function("FloatSetting", "synopsis", float_setting_synopsis);
	env.load_module_function("FloatSetting", "min",      float_setting_min);
	env.load_module_function("FloatSetting", "max",      float_setting_max);
	env.load_module_function("FloatSetting", "update",   float_setting_update);
}

} // namespace crown
