
tmp_ld_tmp(Y,X) :- join_path([alsdir,Y,X],Z), simple_load(Z).

bldit(CorePath, SVIm)
	:- 
	split_path(CorePath, CPL),
	append(CPL, [tcltk_interface,common,'tcltk_util.pro'], TcltkUtilList),
	join_path(TcltkUtilList, TcltkUtil),
	simple_load(TcltkUtil),

	tmp_ld_tmp(builtins,'blt_dvsh.pro'), 
	tmp_ld_tmp(builtins,'dbg_class.pro'), 
	tmp_ld_tmp(builtins,'projects.pro'), 

	append(CPL,[als_dev,alsdev,'demo15.pro'], Demo15List), 
	join_path(Demo15List, Demo15),
		simple_load(Demo15),
	append(CPL,[als_dev,alsdev,'serial_cmn.pro'], SerialList), 
	join_path(SerialList, Serial),
		simple_load(Serial),

	tmp_ld_tmp(library,'listutl1.pro'),
	tmp_ld_tmp(library,'miscterm.pro'),
	tmp_ld_tmp(library,'msc_ioin.pro'),
	tmp_ld_tmp(library,'mscioout.pro'),
	tmp_ld_tmp(library,'strctutl.pro'),
	tmp_ld_tmp(library,'strings.pro'),
	tmp_ld_tmp(library,'tcl_sppt.pro'),
	tmp_ld_tmp(library,'tk_alslib.pro'),
	tmp_ld_tmp(library,'typecomp.pro'),
	call(SVIm),
	abolish(tmp_ld_tmp, 2),
	abolish(bldit,2).

module builtins.
tdvf :- demo_init.
endmod.
