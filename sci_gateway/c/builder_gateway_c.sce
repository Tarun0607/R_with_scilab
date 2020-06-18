// This file is released under the 3-clause BSD license. See COPYING-BSD.

function builder_gw_c()

    includes_src_c = ilib_include_flag(get_absolute_file_path("builder_gateway_c.sce") + "../../src/c");

    // PutLhsVar managed by user in sci_sum and in sci_sub
    // if you do not this variable, PutLhsVar is added
    // in gateway generated (default mode in scilab 4.x and 5.x)
    WITHOUT_AUTO_PUTLHSVAR = %t;

    tbx_build_gateway("skeleton_c", ..
    ["c_kruskal_wallis","sci_ckruskal_wallis", "csci"; ...
    "c_kruskal_wallis6","sci_ckruskal_wallis6", "csci6"], ..
    ["sci_ckruskal_wallis.c","sci_ckruskal_wallis6.c"], ..
    get_absolute_file_path("builder_gateway_c.sce"), ..
    ["../../src/c/libckruskal_wallis"], ..
    "", ..
    includes_src_c);

endfunction

builder_gw_c();
clear builder_gw_c; // remove builder_gw_c on stack
