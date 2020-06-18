// This file is released under the 3-clause BSD license. See COPYING-BSD.

// This macro compiles the files

function builder_c()

    src_c_path = get_absolute_file_path("builder_c.sce");

    CFLAGS = ilib_include_flag("D:/R/R-4.0.1/include/x64");
    //LDFLAGS=ilib_include_flag("D:/R/R-4.0.1/bin/x64 -lR //-lm");

    tbx_build_src(["kruskal_wallis"],       ..
    ["kruskal_wallis.c"], ..
    "c",                ..
    src_c_path,         ..
    "",                 ..
    "",                 ..                 
    CFLAGS);

endfunction

builder_c();
clear builder_c; // remove builder_c on stack
