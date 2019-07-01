/*!A cross-platform build utility based on Lua
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (C) 2015 - 2019, TBOOX Open Source Group.
 *
 * @author      OpportunityLiu
 * @file        file___len.c
 *
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * trace
 */
#define TB_TRACE_MODULE_NAME "file___len"
#define TB_TRACE_MODULE_DEBUG (0)

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include "file.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */

/*
 * #file
 */
tb_int_t xm_io_file___len(lua_State* lua)
{
    // check
    tb_assert_and_check_return_val(lua, 0);

    xm_io_file* file = (xm_io_file*)luaL_checkudata(lua, 1, xm_io_file_udata);
    if(xm_io_file_is_closed_file(file))
        xm_io_file_error_closed(lua);
    else if (xm_io_file_is_file(file))
    {
        lua_pushnumber(lua, (lua_Number)tb_file_size(file->file_ref));
        xm_io_file_success();
    }
    else
        xm_io_file_error(lua, "getting file size for this file is invalid");
}
