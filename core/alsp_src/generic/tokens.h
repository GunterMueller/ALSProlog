#define TK_CALL         	1	/* call */
#define TK_OCALL        	2	/* callWithDelayedInterrupt */
#define TK_DBG_CALL     	3	/* dbg_call */
#define TK_SCOLON3      	4	/* $semicolon */
#define TK_COMMA3       	5	/* $comma */
#define TK_IFARROW3     	6	/* $arrow */
#define TK_SCOLON       	7	/* ; */
#define TK_COMMA        	8	/* , */
#define TK_COLON        	9	/* : */
#define TK_VBAR         	10	/* | */
#define TK_IFARROW      	11	/* -> */
#define TK_CUT          	12	/* ! */
#define TK_IS           	13	/* is */
#define TK_LESS         	14	/* < */
#define TK_GRT          	15	/* > */
#define TK_LEQ          	16	/* =< */
#define TK_GEQ          	17	/* >= */
#define TK_ZEBRA        	18	/* =:= */
#define TK_ZEBRA2       	19	/* =\= */
#define TK_HEAPUSED     	20	/* heapused */
#define TK_CPUTIME      	21	/* cputime */
#define TK_REALTIME     	22	/* realtime */
#define TK_RANDOM       	23	/* random */
#define TK_NOT          	24	/* not */
#define TK_BACKSLASH    	25	/* \ */
#define TK_ABS          	26	/* abs */
#define TK_SIN          	27	/* sin */
#define TK_SINH         	28	/* sinh */
#define TK_COS          	29	/* cos */
#define TK_COSH         	30	/* cosh */
#define TK_TAN          	31	/* tan */
#define TK_TANH         	32	/* tanh */
#define TK_ASIN         	33	/* asin */
#define TK_ACOS         	34	/* acos */
#define TK_ATAN         	35	/* atan */
#define TK_SQRT         	36	/* sqrt */
#define TK_EXP          	37	/* exp */
#define TK_EXP10        	38	/* exp10 */
#define TK_LOG          	39	/* log */
#define TK_LOG10        	40	/* log10 */
#define TK_FLOOR        	41	/* floor */
#define TK_ROUND        	42	/* round */
#define TK_CEIL         	43	/* ceil */
#define TK_ERF          	44	/* erf */
#define TK_ERFC         	45	/* erfc */
#define TK_GAMMA        	46	/* gamma */
#define TK_J0           	47	/* j0 */
#define TK_J1           	48	/* j1 */
#define TK_Y0           	49	/* y0 */
#define TK_Y1           	50	/* y1 */
#define TK_TRUNC        	51	/* trunc */
#define TK_PLUS         	52	/* + */
#define TK_MINUS        	53	/* - */
#define TK_ATAN2        	54	/* atan2 */
#define TK_FMOD         	55	/* fmod */
#define TK_HYPOT        	56	/* hypot */
#define TK_JN           	57	/* jn */
#define TK_YN           	58	/* yn */
#define TK_STAR         	59	/* * */
#define TK_SLASHSLASH   	60	/* // */
#define TK_DIV          	61	/* div */
#define TK_MOD          	62	/* mod */
#define TK_BAND         	63	/* /\ */
#define TK_BOR          	64	/* \/ */
#define TK_BXOR         	65	/* xor */
#define TK_LSHFT        	66	/* << */
#define TK_RSHFT        	67	/* >> */
#define TK_SLASH        	68	/* / */
#define TK_HAT          	69	/* ^ */
#define TK_XFX          	70	/* xfx */
#define TK_XFY          	71	/* xfy */
#define TK_YFX          	72	/* yfx */
#define TK_FX           	73	/* fx */
#define TK_FY           	74	/* fy */
#define TK_XF           	75	/* xf */
#define TK_YF           	76	/* yf */
#define TK_RIF          	77	/* :- */
#define TK_QUEST        	78	/* ?- */
#define TK_PRW          	79	/* --> */
#define TK_EQ           	80	/* = */
#define TK_UNIV         	81	/* =.. */
#define TK_ID           	82	/* == */
#define TK_UID          	83	/* \== */
#define TK_ALS          	84	/* @< */
#define TK_AGR          	85	/* @> */
#define TK_ALEQ         	86	/* @=< */
#define TK_AGEQ         	87	/* @>= */
#define TK_DOT          	88	/* . */
#define TK_LBRAC        	89	/* [ */
#define TK_RBRAC        	90	/* ] */
#define TK_LPAREN       	91	/* ( */
#define TK_RPAREN       	92	/* ) */
#define TK_LISTING      	93	/* listing */
#define TK_CONSULT      	94	/* consult */
#define TK_RECONSULT    	95	/* reconsult */
#define TK_NEQ          	96	/* \= */
#define TK_USER         	97	/* user */
#define TK_BUILTINS     	98	/* builtins */
#define TK_NIL          	99	/* [] */
#define TK_MODULE       	100	/* module */
#define TK_USE          	101	/* use */
#define TK_ENDMOD       	102	/* endmod */
#define TK_EXPORT       	103	/* export */
#define TK_LCURLY       	104	/* { */
#define TK_RCURLY       	105	/* } */
#define TK_CURLYS       	106	/* {} */
#define TK_SQUOTE       	107	/* ' */
#define TK_UNDERSCORE   	108	/* _ */
#define TK_DBREF        	109	/* $dbref */
#define TK_DDOUBLE      	110	/* $double */
#define TK_NOTAGAIN     	111	/* \+ */
#define TK_EXPAND       	112	/* expand */
#define TK_ALSCD        	113	/* als$cd */
#define TK_STREAM_DESCRIPTOR	114	/* stream_descriptor */
#define TK_SYMBOL       	115	/* symbol */
#define TK_QSYMBOL      	116	/* qsymbol */
#define TK_FUNCTOR      	117	/* functor */
#define TK_STRING       	118	/* string */
#define TK_LONG_STRING  	119	/* long_string */
#define TK_LONG_SYMBOL  	120	/* long_symbol */
#define TK_LONG_QSYMBOL 	121	/* long_qsymbol */
#define TK_VAR          	122	/* var */
#define TK_INTEGER      	123	/* integer */
#define TK_UINTEGER     	124	/* uinteger */
#define TK_FULLSTOP     	125	/* fullstop */
#define TK_LEXERR       	126	/* lexerr */
#define TK_COMMENT      	127	/* comment */
#define TK_BYTE         	128	/* byte */
#define TK_UBYTE        	129	/* ubyte */
#define TK_CHAR         	130	/* char */
#define TK_UCHAR        	131	/* uchar */
#define TK_SHORT        	132	/* short */
#define TK_USHORT       	133	/* ushort */
#define TK_RSHORT       	134	/* rshort */
#define TK_RUSHORT      	135	/* rushort */
#define TK_INT          	136	/* int */
#define TK_UINT         	137	/* uint */
#define TK_LONG         	138	/* long */
#define TK_ULONG        	139	/* ulong */
#define TK_FLOAT        	140	/* float */
#define TK_DOUBLE       	141	/* double */
#define TK_FAR          	142	/* dosfar */
#define TK_PREPROC      	143	/* preproc */
#define TK_POUND        	144	/* # */
#define TK_EOLN         	145	/* eoln */
#define TK_LINEINFO     	146	/* lineinfo */
#define TK_ATOM_LENGTH  	147	/* atom_length */
#define TK_ATOM         	148	/* atom */
#define TK_BODY         	149	/* body */
#define TK_CALLABLE     	150	/* callable */
#define TK_CHARACTER    	151	/* character */
#define TK_COMPOUND     	152	/* compound */
#define TK_CONSTANT     	153	/* constant */
#define TK_LIST         	154	/* list */
#define TK_NUMBER       	155	/* number */
#define TK_VARIABLE     	156	/* variable */
#define TK_CHARACTER_CODE_LIST	157	/* character_code_list */
#define TK_CHARACTER_LIST	158	/* character_list */
#define TK_CLOSE_OPTION 	159	/* close_option */
#define TK_FLAG_VALUE   	160	/* flag_value */
#define TK_IO_MODE      	161	/* IO_MODE */
#define TK_NOT_LESS_THAN_ZERO	162	/* not_less_than_zero */
#define TK_OPERATOR_PRIORITY	163	/* operator_priority */
#define TK_OPERATOR_SPECIFIER	164	/* operator_specifier */
#define TK_PROLOG_FLAG  	165	/* prolog_flag */
#define TK_READ_OPTION  	166	/* read_option */
#define TK_SOURCE_SINK  	167	/* source_sink */
#define TK_STREAM_OR_ALIAS	168	/* stream_or_alias */
#define TK_STREAM_OPTION	169	/* stream_option */
#define TK_STREAM_POSITION	170	/* stream_position */
#define TK_WRITE_OPTION 	171	/* write_option */
#define TK_OPERATOR     	172	/* operator */
#define TK_PAST_END_OF_STREAM	173	/* past_end_of_stream */
#define TK_PROCEDURE    	174	/* procedure */
#define TK_STATIC_PROCEDURE	175	/* static_procedure */
#define TK_STREAM       	176	/* stream */
#define TK_ACCESS_CLAUSE	177	/* access_clause */
#define TK_CREATE       	178	/* create */
#define TK_INPUT        	179	/* input */
#define TK_MODIFY       	180	/* modify */
#define TK_OPEN         	181	/* open */
#define TK_OUTPUT       	182	/* output */
#define TK_REPOSITION   	183	/* reposition */
#define TK_CHARACTER_CODE	184	/* character_code */
#define TK_EXCEEDED_MAX_ARITY	185	/* exceeded_max_arity */
#define TK_FLAG         	186	/* flag */
#define TK_OVERFLOW     	187	/* overflow */
#define TK_UNDERFLOW    	188	/* underflow */
#define TK_ZERO_DIVIDE  	189	/* zero_divide */
#define TK_UNDEFINED    	190	/* undefined */
#define TK_ERROR        	191	/* error */
#define TK_INSTANTIATION_ERROR	192	/* instantiation_error */
#define TK_TYPE_ERROR   	193	/* type_error */
#define TK_DOMAIN_ERROR 	194	/* domain_error */
#define TK_EXISTENCE_ERROR	195	/* existence_error */
#define TK_PERMISSION_ERROR	196	/* permission_error */
#define TK_REPRESENTATION_ERROR	197	/* representation_error */
#define TK_CALCULATION_ERROR	198	/* calculation_error */
#define TK_RESOURCE_ERROR	199	/* resource_error */
#define TK_SYNTAX_ERROR 	200	/* syntax_error */
#define TK_SYSTEM_ERROR 	201	/* system_error */
#define TK_CHAR_CODE    	202	/* char_code */
#define TK_ATOM_CHARS   	203	/* atom_chars */
#define TK_ATOM_CODES   	204	/* atom_codes */
#define TK_NUMBER_CHARS 	205	/* number_chars */
#define TK_NUMBER_CODES 	206	/* number_codes */
#define TK_SNR          	207	/* stream_not_ready */
#define TK_EOF          	208	/* end_of_file */