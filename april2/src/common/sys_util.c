/* Copyright (C) 2013-2016, The Regents of The University of Michigan.
All rights reserved.

This software was developed in the APRIL Robotics Lab under the
direction of Edwin Olson, ebolson@umich.edu. This software may be
available under alternative licensing terms; contact the address above.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sys_util.h"

#include "string_util.h"

char *expand_environment_variables(const char *str){
    assert(str != NULL);

    wordexp_t result;
    int res = wordexp(str, &result, WRDE_NOCMD | WRDE_UNDEF);
    if (res) {
        fprintf (stderr, "expand_environment_variables(): unable to expand '%s'\n", str);
        return strdup(str);
    }
    char *out = strdup("");
    char *tmp;
    for (int i = 0; i < result.we_wordc; i++){
        tmp = sprintf_alloc ("%s%s ", out, result.we_wordv[i]);
        free(out);
        out = tmp;
    }

    wordfree(&result);
    str_rstrip(out);
    return out;

}
