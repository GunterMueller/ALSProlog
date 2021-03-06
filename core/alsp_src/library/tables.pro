/*========================================================================*
 |			tables.pro
 |		Copyright (c) 1998 Applied Logic Systems, Inc.
 |
 |		Creation and manipulation of rectangular tables --
 |			Interfaces to tkTable
 |
 | External API:
 | ------------
 |
 |	load_table_package/0.
 |			load_table_package :- load_table_package(tcli).
 |	load_table_package/1.
 |	load_table_package(Interp)
 |	load_table_package(+)
 |		-- loads the TkTable package; checks whether already loaded, etc.
 |
 |	create_table/2
 |	create_table(TableName, Options)
 |	create_table(+, +)
 |
 |		create_table(TableName, Options) 
 |			:- create_table(TableName, Options, tcli).
 |
 |	create_table/3
 |	create_table(TableName, Options, Interp)
 |	create_table(+, +, +)
 |
 |		create_table(TableName, Options, Interp)
 |			:- create_table_r(TableName, Options, Interp, _).
 |
 |	create_table_r/3
 |	create_table_r(TableName, Options, R)
 |	create_table_r(+, +, -)
 |
 |		create_table_r(TableName, Options, R)
 |			:- create_table_r(TableName, Options, tcli, R).
 |
 |	create_table_r/4
 |	create_table_r(TableName, Options, Interp, R)
 |	create_table_r(+, +, +, -)
 |
 |		In Interp: 
 |			- creates a table named TableName, with the following
 |			  options (passed to the TkTable package):
 |		numcols,		colheadings, 	titlerows,	roworigin,	
 |		numrows, 		rowheadings,	titlecols,	colorigin,	
 |		title,			font,		foreground,	background, 
 |		selectmode,		rowstretch,		colstretch,	flashmode,	
 |
 |			- returns TableArrayName in R
 |
 |----------------------
 |	table_tag_region/3.
 |	table_tag_region(TableName, TagName, Region)
 |	table_tag_region(+, +, +)
 |
 |			table_tag_region(TableName, TagName, Region)
 |				:- table_tag_region(TableName, TagName, Region, tcli).
 |
 | table_tag_region/4.
 | table_tag_region(TableName, TagName, Region, Interp)
 | table_tag_region(+, +, +, +)
 |
 |	Under Interp:  Applied tag TagName to region Region in table TableName,
 |	where regions can be specified:
 |		cell(R,C) - cell at row R, col C
 |		row(R)	  - all of row R
 |		col(C)	  - all of col C
 |		colsblock(C1,C2)	- all cols from col C1 to col C2, C1 =< C2;
 |		rowsblock(R1,R2)	- all rows from row R1 to row R2, R1 =< R2;
 |
 |----------------------
 | table_set_tag/3.
 | table_set_tag(TableName, TagName, Properties)
 | table_set_tag(+, +, +)
 |
 | 		table_set_tag(TableName, TagName, Properties)
 |			:- table_set_tag(TableName, TagName, Properties, tcli).
 |
 | table_set_tag/4.
 | table_set_tag(TableName, TagName, Properties, Interp)
 | table_set_tag(+, +, +, +)
 |
 |	Given: 
 |	+ TagName is a tag which has been applied to one or more
 |	regions in table TableName under Interp ; 
 |	+ Properties is a list of Prop=Value equations such as
 |			background = black
 |	Then table_set_tag/4 sets these properties for all the tagged regions.
 *========================================================================*/



module tk_alslib.
use tcltk.


/*-------------------------------------------------------------------*
 *-------------------------------------------------------------------*/
export load_table_package/0.
export load_table_package/1.

load_table_package
	:-
	load_table_package(tcli).

:- dynamic(table_package_loaded/0).
load_table_package(Interp)
	:-
	% table_package_loaded(Interp),
	packages_loaded(Interp,table_package),
	!.

load_table_package(Interp)
	:-
	init_tk_alslib(Interp,_),
	builtins:sys_searchdir(SysSearchdir),
	split_path(SysSearchdir, SSDList),
	append(SSDList, [shared], SharedList),
	append(SharedList, ['tables.tcl'], TablesTclList),
	join_path(TablesTclList, TablesTclPath),
	tcl_call(Interp, [source,TablesTclPath], _),
	tcl_call(Interp, [load_table_package, [SharedList]], X),
	assert(packages_loaded(Interp,table_package)).

/*-------------------------------------------------------------------*
 *-------------------------------------------------------------------*/
:- compiletime, module_closure( create_table, 2, create_table3).
:- compiletime, module_closure( create_table, 3, create_table4).

:- compiletime, module_closure( create_table_r, 3, create_table3_r).
:- compiletime, module_closure( create_table_r, 5, create_table4_r).

create_table3(Mod, TableName, Options)
	:-
	create_table4(Mod, TableName, Options, tcli).

create_table4(Mod, TableName, Options, Interp)
	:-
	create_table4_r(Mod, TableName, Options, Interp, [], _).

create_table3_r(Mod, TableName, Options, R)
	:-
	create_table4_r(Mod, TableName, Options, tcli, [], R).

/*-------------------------------------------------------------------*
 *-------------------------------------------------------------------*/
create_table4_r(Mod, TableName, Options, Interp, XOpts,BTR)
	:-
	((dmember(colheadings=ColHeadings, Options),
		ColHeadings \= [])
		->
		length(ColHeadings, NCols0),
%		NCols is NCols0+1,
		NCols = NCols0,
		NTitleRows = 1,
		Roworigin = -1 
		;
		check_default(Options, numcols, 6, NCols),
		ColHeadings = [],
		NTitleRows = 0,
		Roworigin =  0
	),
	((dmember(rowheadings=RowHeadings, Options),
		RowHeadings \= [])
		->
		length(RowHeadings, NRows0),
%		NRows is NRows0+1,
		NRows = NRows0,
		NTitleCols = 1,
		Colorigin = -1
		;
		check_default(Options, numrows, 6, NRows),
		RowHeadings = [],
		NTitleCols = 0,
		Colorigin =  0
	),
	check_default(Options, title,		'',			Title),
	check_default(Options, font,	['Times', 9, normal], Tablefont),
	check_default(Options, foreground,	black,		Foreground),
	check_default(Options, background, '#b9b9b9',	Background),
	check_default(Options, selectmode,	extended,	Selectmode),
	check_default(Options, rowstretch,	unset,		Rowstretch),
	check_default(Options, colstretch,	unset,		Colstretch),
	check_default(Options, flashmode,	on,			Flashmode),
	check_default(Options, width,		NCols,		Width),
	check_default(Options, height,		NRows,		Height),
	check_default(Options, menu,		'',			ReqMenuBar),
	check_default(Options, upperpane,	'',			ReqUpperPane),
	check_default(Options, lowerpane,	'',			ReqLowerPane),

	to_tcl_opts(XOpts, XXOpts),
	catenate(TableName, '_info', TableInfoArrayName),
	OptionsList = [
		colheadings, ColHeadings,
		rowheadings, RowHeadings,
		title,		Title,
		cols,		NCols,
		width,		Width,
		titlerows,	NTitleRows,
		roworigin,	Roworigin,
		rows,		NRows,
		height,		Height,
		titlecols,	NTitleCols,
		colorigin,	Colorigin,
		font,		Tablefont,
		foreground,	Foreground,
		background, Background,
		selectmode,	Selectmode,
		rowstretch,	Rowstretch,
		colstretch,	Colstretch,
		flashmode,	Flashmode,
		menu,		ReqMenuBar,
		upperpane,	ReqUpperPane,
		lowerpane,	ReqLowerPane
		| XXOpts
	],
	tcl_call(Interp, 
			[build_table,TableName,TableInfoArrayName,OptionsList],
			BTR),

	catenate(TableName, '_array', TableArrayName),
	catenate(['set_', TableName, '_table'], SetTableArrayPred),
	catenate(['read_', TableName, '_table'], ReadTableArrayPred),
	SetHead =.. [SetTableArrayPred,Row,Col,Val],
	ReadHead =.. [ReadTableArrayPred,Row,Col,Val],
	Mod:assert( (SetHead :-
		tcl_call(Interp, [set_table,TableArrayName,Row,Col,Val], _)
		) ),
	Mod:assert( 
		(ReadHead :-
		tcl_call(Interp, [read_table,TableArrayName,Row,Col], Val)
		) ),

	Mod:assert(basic_table_info(TableName,NRows,NCols)),
	catenate(['set_', TableName, '_row'], SetTableRowPred),
	SetRowHead =.. [SetTableRowPred,RowN,ColStart,ValsList],
	Mod:assert( (
		SetRowHead :-
		Lim is NCols - ColStart,
		tcl_call(Interp, [write_table_row,TableArrayName,RowN,ColStart,Lim,ValsList], _)
		) ),

	catenate(['set_', TableName, '_col'], SetTableColPred),
	SetColHead =.. [SetTableColPred,ColN,RowStart,ValsList],
	Mod:assert( (
		SetColHead :-
		Lim is NRows - RowStart,
		tcl_call(Interp, [write_table_col,TableArrayName,ColN,RowStart,Lim,ValsList], _)
		) ).

to_tcl_opts([], []).
to_tcl_opts([Tag=Value | XOpts], [Tag, Value | XXOpts])
	:-!,
	to_tcl_opts(XOpts, XXOpts).
to_tcl_opts([_ | XOpts], XXOpts)
	:-
	to_tcl_opts(XOpts, XXOpts).

/*-------------------------------------------------------------------*
 *-------------------------------------------------------------------*/
export table_set_tag/3.
export table_set_tag/4.
table_set_tag(TableName, TagName, Properties)
	:-
	table_set_tag(TableName, TagName, Properties, tcli).

table_set_tag(TableName, TagName, Properties, Interp)
	:-
	check_tag_props(Properties,
					[anchor,background,bg,font,foreground,fg,image,relief],
					TclProps),
	catenate(['.', TableName, '_toplevel.table'], TablePath),
	tcl_call(Interp, [TablePath,tag,configure,TagName | TclProps], _).

check_tag_props([], _, []).
check_tag_props([Tag=Val | Properties], OKTags, [TclTag,TclVal | TclProps])
	:-
	check_tcl_tag(Tag,Val,TclTag,TclVal),
	!,
	check_tag_props(Properties, OKTags, TclProps).
check_tag_props([Tag=Val | Properties], OKTags, TclProps)
	:-
	check_tag_props(Properties, OKTags, TclProps).

check_tcl_tag(Tag,Val,TclTag,TclVal)
	:-
	check_tcl_tag_value(Tag,Val,TclVal),
	catenate('-',Tag,TclTag).


check_tcl_tag_value(anchor,Val,Val)
	:-
	dmember(Val, [center,n,ne,e,se,s,sw,w,nw]).

check_tcl_tag_value(background,Val,Val)
	:-
	colorname(Val).

check_tcl_tag_value(bg,Val,Val)
	:-
	colorname(Val).

check_tcl_tag_value(foreground,Val,Val)
	:-
	colorname(Val).

check_tcl_tag_value(fg,Val,Val)
	:-
	colorname(Val).

check_tcl_tag_value(relief,Val,Val)
	:-
	dmember(Val, [raised,sunken,flat,groove,ridge]).

check_tcl_tag_value(image,Val,Val)
	:-!.

check_tcl_tag_value(font,Font,TclFont)
	:-
	check_font(Font, TclFont).

	%% extend???
check_font([Family,Size,Style], [Family,Size,Style]).

	%% needs real specification:
colorname(Val).


/*-------------------------------------------------------------------*
 *-------------------------------------------------------------------*/
cell_index(R,C,Index)
	:-
	number_codes(R,RCs),
	number_codes(C,CCs),
	append(RCs,[0', | CCs], ICs),
	atom_codes(Index, ICs).

export table_tag_region/3.
export table_tag_region/4.
table_tag_region(TableName, TagName, Region)
	:-
	table_tag_region(TableName, TagName, Region, tcli).

table_tag_region(TableName, TagName, Region, Interp)
	:-
	catenate(['.', TableName, '_toplevel.table'], TablePath),
	apply_region_tag(Region, TablePath, TagName, Interp).

apply_region_tag([], TablePath, TagName, Interp).
apply_region_tag([H | T], TablePath, TagName, Interp)
	:-
	apply_region_tag(H, TablePath, TagName, Interp),
	apply_region_tag(T, TablePath, TagName, Interp).

apply_region_tag(cell(R,C), TablePath, TagName, Interp)
	:-
	cell_index(R,C,Index),
	tcl_call(Interp,[TablePath,tag,cell,TagName,Index], _).

apply_region_tag(row(R), TablePath, TagName, Interp)
	:-
	tcl_call(Interp,[TablePath,tag,row,TagName,R], _).

apply_region_tag(col(C), TablePath, TagName, Interp)
	:-
	tcl_call(Interp,[TablePath,tag,col,TagName,C], _).

apply_region_tag(colsblock(C,C), TablePath, TagName, Interp)
	:-!,
	tcl_call(Interp,[TablePath,tag,col,TagName,C], _).

apply_region_tag(colsblock(C1,C2), TablePath, TagName, Interp)
	:-
	C1 < C2,
	tcl_call(Interp,[TablePath,tag,col,TagName,C1], _),
	C1N is C1 + 1,
	apply_region_tag(colsblock(C1N,C2), TablePath, TagName, Interp).

apply_region_tag(rowsblock(R,R), TablePath, TagName, Interp)
	:-!,
	tcl_call(Interp,[TablePath,tag,row,TagName,R], _).

apply_region_tag(rowsblock(R1,R2), TablePath, TagName, Interp)
	:-
	R1 < R2,
	tcl_call(Interp,[TablePath,tag,row,TagName,R1], _),
	R1N is R1 + 1,
	apply_region_tag(rowsblock(R1N,R2), TablePath, TagName, Interp).


endmod.
