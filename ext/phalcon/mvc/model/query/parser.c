#include "php_phalcon.h"
/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is include which follows the "include" declaration
** in the input file. */
#include <stdio.h>
// 30 "parser.php7.lemon"

#include "parser.php7.inc.h"

// 12 "parser.php7.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    PPCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    PPNOCODE           is a number of type PPCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    PPFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    PPACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    phql_TOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    PPMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is phql_TOKENTYPE.  The entry in the union
**                       for base tokens is called "pp0".
**    PPSTACKDEPTH       is the maximum depth of the parser's stack.
**    phql_ARG_SDECL     A static variable declaration for the %extra_argument
**    phql_ARG_PDECL     A parameter declaration for the %extra_argument
**    phql_ARG_STORE     Code to store %extra_argument into pppParser
**    phql_ARG_FETCH     Code to extract %extra_argument from pppParser
**    PPNSTATE           the combined number of states.
**    PPNRULE            the number of rules in the grammar
**    PPERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define PPCODETYPE unsigned char
#define PPNOCODE 134
#define PPACTIONTYPE unsigned short int
#define phql_TOKENTYPE phql_parser_token*
typedef union {
  phql_TOKENTYPE pp0;
  zval pp204;
  int pp267;
} PPMINORTYPE;
#define PPSTACKDEPTH 100
#define phql_ARG_SDECL phql_parser_status *status;
#define phql_ARG_PDECL ,phql_parser_status *status
#define phql_ARG_FETCH phql_parser_status *status = pppParser->status
#define phql_ARG_STORE pppParser->status = status
#define PPNSTATE 293
#define PPNRULE 161
#define PPERRORSYMBOL 79
#define PPERRSYMDT pp267
#define PP_NO_ACTION      (PPNSTATE+PPNRULE+2)
#define PP_ACCEPT_ACTION  (PPNSTATE+PPNRULE+1)
#define PP_ERROR_ACTION   (PPNSTATE+PPNRULE)

/* Next are that tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < PPNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   PPNSTATE <= N < PPNSTATE+PPNRULE   Reduce by rule N-PPNSTATE.
**
**   N == PPNSTATE+PPNRULE              A syntax error has occurred.
**
**   N == PPNSTATE+PPNRULE+1            The parser accepts its input.
**
**   N == PPNSTATE+PPNRULE+2            No such action.  Denotes unused
**                                      slots in the pp_action[] table.
**
** The action table is constructed as a single large table named pp_action[].
** Given state S and lookahead X, the action is computed as
**
**      pp_action[ pp_shift_ofst[S] + X ]
**
** If the index value pp_shift_ofst[S]+X is out of range or if the value
** pp_lookahead[pp_shift_ofst[S]+X] is not equal to X or if pp_shift_ofst[S]
** is equal to PP_SHIFT_USE_DFLT, it means that the action is not in the table
** and that pp_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the pp_reduce_ofst[] array is used in place of
** the pp_shift_ofst[] array and PP_REDUCE_USE_DFLT is used in place of
** PP_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  pp_action[]        A single table containing all actions.
**  pp_lookahead[]     A table containing the lookahead for each entry in
**                     pp_action.  Used to detect hash collisions.
**  pp_shift_ofst[]    For each state, the offset into pp_action for
**                     shifting terminals.
**  pp_reduce_ofst[]   For each state, the offset into pp_action for
**                     shifting non-terminals after a reduce.
**  pp_default[]       Default action for each state.
*/
static PPACTIONTYPE pp_action[] = {
 /*     0 */   120,  126,   55,   57,   59,   61,   63,   65,   45,   47,
 /*    10 */    67,   72,   49,   51,   53,   41,   39,   43,   37,   34,
 /*    20 */   122,   74,   69,  120,  126,   55,   57,   59,   61,   63,
 /*    30 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*    40 */    43,   37,   34,  122,   74,   69,   19,   20,   21,   22,
 /*    50 */    23,  293,   32,   33,  120,  126,   55,   57,   59,   61,
 /*    60 */    63,   65,   45,   47,   67,   72,   49,   51,   53,   41,
 /*    70 */    39,   43,   37,   34,  122,   74,   69,   37,   34,  122,
 /*    80 */    74,   69,  294,  220,   81,  218,   95,   90,  111,  209,
 /*    90 */   113,  114,  211,  154,   79,  186,  247,  120,  126,   55,
 /*   100 */    57,   59,   61,   63,   65,   45,   47,   67,   72,   49,
 /*   110 */    51,   53,   41,   39,   43,   37,   34,  122,   74,   69,
 /*   120 */    55,   57,   59,   61,   63,   65,   45,   47,   67,   72,
 /*   130 */    49,   51,   53,   41,   39,   43,   37,   34,  122,   74,
 /*   140 */    69,  130,    7,  120,  126,   55,   57,   59,   61,   63,
 /*   150 */    65,   45,   47,   67,   72,   49,   51,   53,   41,   39,
 /*   160 */    43,   37,   34,  122,   74,   69,   41,   39,   43,   37,
 /*   170 */    34,  122,   74,   69,  140,  240,  120,  126,   55,   57,
 /*   180 */    59,   61,   63,   65,   45,   47,   67,   72,   49,   51,
 /*   190 */    53,   41,   39,   43,   37,   34,  122,   74,   69,  120,
 /*   200 */   126,   55,   57,   59,   61,   63,   65,   45,   47,   67,
 /*   210 */    72,   49,   51,   53,   41,   39,   43,   37,   34,  122,
 /*   220 */    74,   69,   45,   47,   67,   72,   49,   51,   53,   41,
 /*   230 */    39,   43,   37,   34,  122,   74,   69,  122,   74,   69,
 /*   240 */   112,  113,  114,  146,    8,  120,  126,   55,   57,   59,
 /*   250 */    61,   63,   65,   45,   47,   67,   72,   49,   51,   53,
 /*   260 */    41,   39,   43,   37,   34,  122,   74,   69,  168,  295,
 /*   270 */   156,   35,  124,   17,  169,  171,  296,   76,  279,  286,
 /*   280 */   282,  159,   67,   72,   49,   51,   53,   41,   39,   43,
 /*   290 */    37,   34,  122,   74,   69,  128,   49,   51,   53,   41,
 /*   300 */    39,   43,   37,   34,  122,   74,   69,   24,   70,  228,
 /*   310 */    94,  174,  175,  181,  182,  183,  133,  137,  143,  230,
 /*   320 */   149,  222,  223,  123,   89,  178,  176,  177,  179,  180,
 /*   330 */   168,   82,   94,   35,   95,   99,  169,  171,   38,  192,
 /*   340 */   208,  194,  196,  159,  200,  204,   98,  192,  208,  194,
 /*   350 */   196,   80,  200,  204,   83,  210,  173,  128,  430,   84,
 /*   360 */    84,  297,  455,    1,    2,    3,    4,    5,    6,  158,
 /*   370 */    94,  107,  107,  174,  175,  181,  182,  183,  133,  137,
 /*   380 */   143,  226,  149,   92,  103,    6,   31,  178,  176,  177,
 /*   390 */   179,  180,  213,  162,  271,   35,   92,  162,  169,  171,
 /*   400 */   287,  212,  217,   91,  173,  214,   95,  104,  238,   28,
 /*   410 */   237,  173,   92,    9,  234,  173,  105,  158,    6,  128,
 /*   420 */   173,  165,  115,   26,  158,  224,  163,  184,  158,   10,
 /*   430 */   162,  184,  100,  158,  107,  174,  175,  181,  182,  183,
 /*   440 */   133,  137,  143,   78,  149,   11,  221,  217,  173,  178,
 /*   450 */   176,  177,  179,  180,  285,  216,   35,  245,  232,  169,
 /*   460 */   171,  158,   76,   31,  184,  173,  159,  135,  110,   76,
 /*   470 */   131,    6,  173,  284,    6,  173,  199,  236,  158,  197,
 /*   480 */   128,  173,  242,  246,  249,  158,  129,   30,  158,  276,
 /*   490 */   191,  290,  189,  109,  158,  173,  174,  175,  181,  182,
 /*   500 */   183,  133,  137,  143,  173,  149,  160,   15,  158,  245,
 /*   510 */   178,  176,  177,  179,  180,  168,   13,  158,   35,  277,
 /*   520 */   258,  169,  171,  162,   84,  258,  215,  173,  159,  254,
 /*   530 */    14,   96,  259,   85,  265,  244,  107,  259,  173,  160,
 /*   540 */   158,  173,  128,  173,  152,  154,  166,  186,  151,  188,
 /*   550 */   102,  158,  203,   36,  158,  201,  158,  167,  174,  175,
 /*   560 */   181,  182,  183,  133,  137,  143,  429,  149,  258,   40,
 /*   570 */    12,  173,  178,  176,  177,  179,  180,   42,   16,   35,
 /*   580 */   257,  166,  169,  171,  158,  292,  173,  173,  207,  159,
 /*   590 */    84,  205,  251,  252,  260,  173,   29,  166,   44,  158,
 /*   600 */   158,  225,  107,  128,  107,  384,   18,  261,  158,   46,
 /*   610 */   270,   75,   48,   50,   52,   25,  173,  233,  256,  174,
 /*   620 */   175,  181,  182,  183,  133,  137,  143,  173,  149,  158,
 /*   630 */   173,  173,  173,  178,  176,  177,  179,  180,  255,   54,
 /*   640 */   158,   56,   58,  158,  158,  158,  267,  281,  282,   69,
 /*   650 */    60,   87,   27,   62,   77,  256,   64,  173,   66,  173,
 /*   660 */   173,   68,   71,  274,   73,  108,  262,  119,  173,   86,
 /*   670 */   158,  173,  158,  158,  173,  266,  173,   94,  121,  173,
 /*   680 */   173,  158,  173,  127,  158,  173,  139,  158,  145,  158,
 /*   690 */    97,  109,  158,  158,  150,  158,  173,  155,  158,  110,
 /*   700 */    88,  173,  157,   93,  173,  101,  173,  118,  170,  158,
 /*   710 */   106,  172,  173,  187,  158,  173,  116,  158,  229,  158,
 /*   720 */   173,  132,  239,  248,  117,  158,  173,  125,  158,  173,
 /*   730 */   134,  173,   76,  158,  136,  138,  173,  141,  142,  158,
 /*   740 */   173,  173,  158,  144,  158,  147,  148,  153,  185,  158,
 /*   750 */   164,  190,  161,  158,  158,  321,  193,  195,  322,  323,
 /*   760 */   198,  324,  325,  326,  202,  327,  328,  329,  206,  219,
 /*   770 */   241,  243,  227,  332,  269,  333,  268,  272,  340,  273,
 /*   780 */   275,  383,  231,  250,  280,  235,  253,  264,  263,  283,
 /*   790 */   288,  289,  346,  291,  278,
};
static PPCODETYPE pp_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,   13,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,    1,    2,    3,    4,    5,    6,    7,
 /*    30 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*    40 */    18,   19,   20,   21,   22,   23,   60,   61,   62,   63,
 /*    50 */    64,    0,   53,   54,    1,    2,    3,    4,    5,    6,
 /*    60 */     7,    8,    9,   10,   11,   12,   13,   14,   15,   16,
 /*    70 */    17,   18,   19,   20,   21,   22,   23,   19,   20,   21,
 /*    80 */    22,   23,    0,   30,   96,   32,  119,  120,  100,  101,
 /*    90 */   102,  103,   25,   71,   27,   73,   50,    1,    2,    3,
 /*   100 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*   110 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*   120 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   130 */    13,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   140 */    23,   45,   87,    1,    2,    3,    4,    5,    6,    7,
 /*   150 */     8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
 /*   160 */    18,   19,   20,   21,   22,   23,   16,   17,   18,   19,
 /*   170 */    20,   21,   22,   23,   32,   55,    1,    2,    3,    4,
 /*   180 */     5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
 /*   190 */    15,   16,   17,   18,   19,   20,   21,   22,   23,    1,
 /*   200 */     2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
 /*   210 */    12,   13,   14,   15,   16,   17,   18,   19,   20,   21,
 /*   220 */    22,   23,    9,   10,   11,   12,   13,   14,   15,   16,
 /*   230 */    17,   18,   19,   20,   21,   22,   23,   21,   22,   23,
 /*   240 */   101,  102,  103,   68,   88,    1,    2,    3,    4,    5,
 /*   250 */     6,    7,    8,    9,   10,   11,   12,   13,   14,   15,
 /*   260 */    16,   17,   18,   19,   20,   21,   22,   23,   17,    0,
 /*   270 */    72,   20,   23,   25,   23,   24,    0,   26,  114,  115,
 /*   280 */   116,   30,   11,   12,   13,   14,   15,   16,   17,   18,
 /*   290 */    19,   20,   21,   22,   23,   44,   13,   14,   15,   16,
 /*   300 */    17,   18,   19,   20,   21,   22,   23,   59,   11,   12,
 /*   310 */    30,   60,   61,   62,   63,   64,   65,   66,   67,   22,
 /*   320 */    69,   28,   29,   74,   44,   74,   75,   76,   77,   78,
 /*   330 */    17,   25,   30,   20,  119,  120,   23,   24,   98,   33,
 /*   340 */    34,   35,   36,   30,   38,   39,   44,   33,   34,   35,
 /*   350 */    36,   95,   38,   39,   99,   99,  116,   44,   45,  104,
 /*   360 */   104,    0,   80,   81,   82,   83,   84,   85,   86,  129,
 /*   370 */    30,  116,  116,   60,   61,   62,   63,   64,   65,   66,
 /*   380 */    67,   82,   69,   25,   44,   86,   98,   74,   75,   76,
 /*   390 */    77,   78,   17,   98,  112,   20,   25,   98,   23,   24,
 /*   400 */   118,   97,   98,   45,  116,   30,  119,  120,   56,  121,
 /*   410 */   122,  116,   25,   89,   82,  116,   45,  129,   86,   44,
 /*   420 */   116,  126,  104,   51,  129,  126,  131,  132,  129,   90,
 /*   430 */    98,  132,   45,  129,  116,   60,   61,   62,   63,   64,
 /*   440 */    65,   66,   67,   94,   69,   91,   97,   98,  116,   74,
 /*   450 */    75,   76,   77,   78,   98,   17,   20,   98,  126,   23,
 /*   460 */    24,  129,   26,   98,  132,  116,   30,   82,   30,   26,
 /*   470 */    82,   86,  116,  117,   86,  116,   34,   98,  129,   37,
 /*   480 */    44,  116,  123,  124,   41,  129,   98,  122,  129,   46,
 /*   490 */    30,   48,   32,   31,  129,  116,   60,   61,   62,   63,
 /*   500 */    64,   65,   66,   67,  116,   69,   44,   58,  129,   98,
 /*   510 */    74,   75,   76,   77,   78,   17,   57,  129,   20,   99,
 /*   520 */    98,   23,   24,   98,  104,   98,   31,  116,   30,  107,
 /*   530 */    46,   30,  110,   32,  107,  124,  116,  110,  116,   44,
 /*   540 */   129,  116,   44,  116,   70,   71,   25,   73,  127,  128,
 /*   550 */    49,  129,   34,   98,  129,   37,  129,  132,   60,   61,
 /*   560 */    62,   63,   64,   65,   66,   67,   45,   69,   98,   98,
 /*   570 */    92,  116,   74,   75,   76,   77,   78,   98,  125,   20,
 /*   580 */   110,   25,   23,   24,  129,   99,  116,  116,   34,   30,
 /*   590 */   104,   37,  104,   43,   44,  116,   25,   25,   98,  129,
 /*   600 */   129,   45,  116,   44,  116,    0,  125,  108,  129,   98,
 /*   610 */   111,   44,   98,   98,   98,  125,  116,   45,   25,   60,
 /*   620 */    61,   62,   63,   64,   65,   66,   67,  116,   69,  129,
 /*   630 */   116,  116,  116,   74,   75,   76,   77,   78,   45,   98,
 /*   640 */   129,   98,   98,  129,  129,  129,   25,  115,  116,   23,
 /*   650 */    98,   49,   52,   98,   93,   25,   98,  116,   98,  116,
 /*   660 */   116,   98,   98,   58,   98,   30,   45,   98,  116,   30,
 /*   670 */   129,  116,  129,  129,  116,   45,  116,   30,   98,  116,
 /*   680 */   116,  129,  116,   98,  129,  116,   98,  129,   98,  129,
 /*   690 */    49,   31,  129,  129,   98,  129,  116,   98,  129,   30,
 /*   700 */   119,  116,   98,  119,  116,  119,  116,   40,   98,  129,
 /*   710 */   119,   98,  116,   98,  129,  116,  105,  129,   98,  129,
 /*   720 */   116,   45,   98,   98,  106,  129,  116,   74,  129,  116,
 /*   730 */    44,  116,   26,  129,   45,   44,  116,   30,   45,  129,
 /*   740 */   116,  116,  129,   44,  129,   30,   45,  128,   28,  129,
 /*   750 */    45,   30,  130,  129,  129,   30,   34,   34,   30,   30,
 /*   760 */    34,   30,   30,   30,   34,   30,   30,   30,   34,   30,
 /*   770 */    52,   25,   45,    0,   30,    0,  111,   87,    0,  113,
 /*   780 */   125,    0,   44,   42,   25,   45,   44,   44,   43,    3,
 /*   790 */    87,  113,    0,   27,   47,
};
#define PP_SHIFT_USE_DFLT (-15)
static short pp_shift_ofst[] = {
 /*     0 */   443,   51,   82,  269,  276,  361,   46,  120,  352,  372,
 /*    10 */   449,  459,  -15,  484,  -15,  -14,  248,  -14,  -15,  -15,
 /*    20 */   -15,  -15,  -15,  -15,  -14,  -15,  600,  559,  571,  559,
 /*    30 */   -15,   -1,  -15,  -15,  559,  559,  216,  559,  216,  559,
 /*    40 */    58,  559,   58,  559,   58,  559,  271,  559,  271,  559,
 /*    50 */   150,  559,  150,  559,  150,  559,  213,  559,  213,  559,
 /*    60 */   213,  559,  213,  559,  213,  559,  213,  559,  283,  297,
 /*    70 */   559,  626,  559,  283,  567,  251,  293,  375,   67,  635,
 /*    80 */   306,  -15,  635,  -15,  501,  639,  602,  280,  -15,  647,
 /*    90 */   358,  -15,  647,  -15,  -15,  -15,  641,  302,  647,  387,
 /*   100 */   -15,  -15,  340,  647,  371,  -15,  -15,  -15,  660,  669,
 /*   110 */   -15,  314,  -15,  -15,  635,  460,  667,  -15,  559,  244,
 /*   120 */   559,  244,  249,  -15,  653,  -15,  559,  117,  436,   96,
 /*   130 */   -15,  676,  -15,  686,  706,  689,  -15,  691,  559,  142,
 /*   140 */   707,  693,  -15,  699,  559,  175,  715,  701,  -15,  559,
 /*   150 */    22,  474,  -15,  -15,  559,  198,  559,  244,  -15,  462,
 /*   160 */   720,  313,  244,  705,  -15,  521,  498,  -15,  -15,  559,
 /*   170 */   626,  559,  626,  -15,  -15,  -15,  -15,  -15,  -15,  -15,
 /*   180 */   -15,  -15,  -15,  -15,  -15,  -15,  559,  244,  -15,  721,
 /*   190 */   -15,  -15,  722,  725,  723,  728,  442,  726,  729,  731,
 /*   200 */   518,  730,  732,  733,  554,  734,  735,  736,  737,  -15,
 /*   210 */   -15,  375,  -15,  -15,  495,  438,  -15,   53,  739,  -15,
 /*   220 */   -15,  -15,  -15,  -15,  556,  -15,  727,  -15,  559,  626,
 /*   230 */   738,  251,  572,  -15,  740,  -15,  216,  -15,  559,  244,
 /*   240 */   718,  559,  746,  559,  -15,  244,  -15,  559,  244,  741,
 /*   250 */   635,  550,  742,  559,  593,  773,  559,  -15,  244,  -15,
 /*   260 */   744,  621,  745,  743,  559,  630,  775,  744,  -15,  -15,
 /*   270 */   -15,   46,  605,  778,  -14,  781,  635,  747,  635,  759,
 /*   280 */   635,  -15,  786,  559,  -15,  244,  -15,   46,  605,  792,
 /*   290 */   766,  635,  -15,
};
#define PP_REDUCE_USE_DFLT (-34)
static short pp_reduce_ofst[] = {
 /*     0 */   282,  -34,  -34,  -34,  -34,  -34,   55,  156,  324,  339,
 /*    10 */   354,  478,  -34,  -34,  -34,  453,  -34,  481,  -34,  -34,
 /*    20 */   -34,  -34,  -34,  -34,  490,  -34,  -34,  288,  -34,  365,
 /*    30 */   -34,  -34,  -34,  -34,  379,  455,  -34,  240,  -34,  471,
 /*    40 */   -34,  479,  -34,  500,  -34,  511,  -34,  514,  -34,  515,
 /*    50 */   -34,  516,  -34,  541,  -34,  543,  -34,  544,  -34,  552,
 /*    60 */   -34,  555,  -34,  558,  -34,  560,  -34,  563,  -34,  -34,
 /*    70 */   564,  -34,  566,  -34,  -34,  299,  561,  349,  -34,  256,
 /*    80 */   -12,  -34,  255,  -34,  -34,  -34,  -34,  581,  -34,  -33,
 /*    90 */   -34,  -34,  584,  -34,  -34,  -34,  -34,  586,  215,  -34,
 /*   100 */   -34,  -34,  591,  287,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   110 */   -34,  139,  -34,  -34,  318,  611,  618,  -34,  569,  -34,
 /*   120 */   580,  -34,  -34,  -34,  -34,  -34,  585,  -34,  388,  -34,
 /*   130 */   -34,  -34,  -34,  -34,  385,  -34,  -34,  -34,  588,  -34,
 /*   140 */   -34,  -34,  -34,  -34,  590,  -34,  -34,  -34,  -34,  596,
 /*   150 */   421,  619,  -34,  -34,  599,  -34,  604,  -34,  -34,  -34,
 /*   160 */   622,  295,  -34,  -34,  -34,  -34,  425,  -34,  -34,  610,
 /*   170 */   -34,  613,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   180 */   -34,  -34,  -34,  -34,  -34,  -34,  615,  -34,  -34,  -34,
 /*   190 */   -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   200 */   -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   210 */   -34,  304,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
 /*   220 */   -34,  -34,  -34,  -34,  -34,  -34,  -34,  -34,  620,  -34,
 /*   230 */   -34,  332,  -34,  -34,  -34,  -34,  -34,  -34,  624,  -34,
 /*   240 */   -34,  359,  -34,  411,  -34,  -34,  -34,  625,  -34,  -34,
 /*   250 */   488,  -34,  -34,  422,  -34,  -34,  470,  -34,  -34,  -34,
 /*   260 */   499,  -34,  -34,  -34,  427,  -34,  -34,  665,  -34,  -34,
 /*   270 */   -34,  690,  666,  -34,  655,  -34,  420,  -34,  164,  -34,
 /*   280 */   532,  -34,  -34,  356,  -34,  -34,  -34,  703,  678,  -34,
 /*   290 */   -34,  486,  -34,
};
static PPACTIONTYPE pp_default[] = {
 /*     0 */   454,  454,  454,  454,  454,  454,  362,  371,  376,  364,
 /*    10 */   382,  378,  298,  454,  377,  454,  379,  454,  380,  385,
 /*    20 */   386,  387,  388,  389,  454,  381,  454,  454,  363,  454,
 /*    30 */   365,  367,  368,  369,  454,  454,  390,  454,  392,  454,
 /*    40 */   393,  454,  394,  454,  395,  454,  396,  454,  397,  454,
 /*    50 */   398,  454,  399,  454,  400,  454,  401,  454,  402,  454,
 /*    60 */   403,  454,  404,  454,  405,  454,  406,  454,  407,  454,
 /*    70 */   454,  408,  454,  409,  454,  454,  302,  454,  454,  454,
 /*    80 */   313,  299,  454,  310,  350,  454,  348,  454,  351,  454,
 /*    90 */   454,  352,  454,  357,  359,  358,  349,  454,  454,  454,
 /*   100 */   353,  354,  454,  454,  454,  355,  356,  360,  453,  454,
 /*   110 */   452,  312,  314,  316,  454,  320,  331,  317,  454,  330,
 /*   120 */   454,  417,  454,  435,  454,  436,  454,  437,  454,  454,
 /*   130 */   440,  454,  413,  454,  454,  454,  416,  454,  454,  454,
 /*   140 */   454,  454,  418,  454,  454,  454,  454,  454,  419,  454,
 /*   150 */   454,  454,  420,  421,  454,  454,  454,  423,  425,  453,
 /*   160 */   428,  454,  434,  454,  426,  454,  454,  431,  433,  454,
 /*   170 */   438,  454,  439,  441,  442,  443,  444,  445,  446,  447,
 /*   180 */   448,  449,  450,  451,  432,  427,  454,  424,  422,  454,
 /*   190 */   318,  319,  454,  454,  454,  454,  454,  454,  454,  454,
 /*   200 */   454,  454,  454,  454,  454,  454,  454,  454,  454,  315,
 /*   210 */   311,  454,  303,  305,  453,  454,  306,  309,  454,  307,
 /*   220 */   308,  304,  300,  301,  454,  411,  454,  414,  454,  410,
 /*   230 */   454,  454,  454,  412,  454,  415,  391,  366,  454,  375,
 /*   240 */   454,  454,  370,  454,  372,  374,  373,  454,  361,  454,
 /*   250 */   454,  454,  454,  454,  454,  454,  454,  334,  336,  335,
 /*   260 */   454,  454,  454,  454,  454,  454,  454,  454,  337,  339,
 /*   270 */   338,  362,  454,  454,  454,  454,  454,  454,  454,  341,
 /*   280 */   454,  342,  454,  454,  344,  345,  343,  362,  454,  454,
 /*   290 */   454,  454,  347,
};
#define PP_SZ_ACTTAB (sizeof(pp_action)/sizeof(pp_action[0]))

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammer, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef PPFALLBACK
static const PPCODETYPE ppFallback[] = {
};
#endif /* PPFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct ppStackEntry {
  int stateno;       /* The state-number */
  int major;         /* The major token value.  This is the code
                     ** number for the token at this stack level */
  PPMINORTYPE minor; /* The user-supplied minor token value.  This
                     ** is the value of the token  */
};
typedef struct ppStackEntry ppStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct ppParser {
  int ppidx;                    /* Index of top element in stack */
  int pperrcnt;                 /* Shifts left before out of the error */
  phql_ARG_SDECL                /* A place to hold %extra_argument */
  ppStackEntry ppstack[PPSTACKDEPTH];  /* The parser's stack */
};
typedef struct ppParser ppParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *ppTraceFILE = 0;
static char *ppTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void phql_Trace(FILE *TraceFILE, char *zTracePrompt){
  ppTraceFILE = TraceFILE;
  ppTracePrompt = zTracePrompt;
  if( ppTraceFILE==0 ) ppTracePrompt = 0;
  else if( ppTracePrompt==0 ) ppTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *ppTokenName[] = { 
  "$",             "AGAINST",       "BETWEEN",       "EQUALS",      
  "NOTEQUALS",     "LESS",          "GREATER",       "GREATEREQUAL",
  "LESSEQUAL",     "AND",           "OR",            "LIKE",        
  "ILIKE",         "BITWISE_AND",   "BITWISE_OR",    "BITWISE_XOR", 
  "DIVIDE",        "TIMES",         "MOD",           "PLUS",        
  "MINUS",         "IS",            "IN",            "NOT",         
  "BITWISE_NOT",   "COMMA",         "SELECT",        "FROM",        
  "DISTINCT",      "ALL",           "IDENTIFIER",    "DOT",         
  "AS",            "INNER",         "JOIN",          "CROSS",       
  "LEFT",          "OUTER",         "RIGHT",         "FULL",        
  "ON",            "INSERT",        "INTO",          "VALUES",      
  "PARENTHESES_OPEN",  "PARENTHESES_CLOSE",  "UPDATE",        "SET",         
  "DELETE",        "WITH",          "WHERE",         "ORDER",       
  "BY",            "ASC",           "DESC",          "GROUP",       
  "HAVING",        "FOR",           "LIMIT",         "OFFSET",      
  "INTEGER",       "HINTEGER",      "NPLACEHOLDER",  "SPLACEHOLDER",
  "BPLACEHOLDER",  "EXISTS",        "CAST",          "CONVERT",     
  "USING",         "CASE",          "END",           "WHEN",        
  "THEN",          "ELSE",          "NULL",          "STRING",      
  "DOUBLE",        "TRUE",          "FALSE",         "error",       
  "program",       "query_language",  "select_statement",  "insert_statement",
  "update_statement",  "delete_statement",  "select_clause",  "where_clause",
  "group_clause",  "having_clause",  "order_clause",  "select_limit_clause",
  "for_update_clause",  "distinct_all",  "column_list",   "associated_name_list",
  "join_list_or_null",  "column_item",   "expr",          "associated_name",
  "join_list",     "join_item",     "join_clause",   "join_type",   
  "aliased_or_qualified_name",  "join_associated_name",  "join_conditions",  "values_list", 
  "field_list",    "value_list",    "value_item",    "field_item",  
  "update_clause",  "limit_clause",  "update_item_list",  "update_item", 
  "qualified_name",  "new_value",     "delete_clause",  "with_item",   
  "with_list",     "order_list",    "order_item",    "group_list",  
  "group_item",    "integer_or_placeholder",  "argument_list",  "when_clauses",
  "when_clause",   "function_call",  "distinct_or_null",  "argument_list_or_null",
  "argument_item",
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *ppRuleName[] = {
 /*   0 */ "program ::= query_language",
 /*   1 */ "query_language ::= select_statement",
 /*   2 */ "query_language ::= insert_statement",
 /*   3 */ "query_language ::= update_statement",
 /*   4 */ "query_language ::= delete_statement",
 /*   5 */ "select_statement ::= select_clause where_clause group_clause having_clause order_clause select_limit_clause for_update_clause",
 /*   6 */ "select_clause ::= SELECT distinct_all column_list FROM associated_name_list join_list_or_null",
 /*   7 */ "distinct_all ::= DISTINCT",
 /*   8 */ "distinct_all ::= ALL",
 /*   9 */ "distinct_all ::=",
 /*  10 */ "column_list ::= column_list COMMA column_item",
 /*  11 */ "column_list ::= column_item",
 /*  12 */ "column_item ::= TIMES",
 /*  13 */ "column_item ::= IDENTIFIER DOT TIMES",
 /*  14 */ "column_item ::= expr AS IDENTIFIER",
 /*  15 */ "column_item ::= expr IDENTIFIER",
 /*  16 */ "column_item ::= expr",
 /*  17 */ "associated_name_list ::= associated_name_list COMMA associated_name",
 /*  18 */ "associated_name_list ::= associated_name",
 /*  19 */ "join_list_or_null ::= join_list",
 /*  20 */ "join_list_or_null ::=",
 /*  21 */ "join_list ::= join_list join_item",
 /*  22 */ "join_list ::= join_item",
 /*  23 */ "join_item ::= join_clause",
 /*  24 */ "join_clause ::= join_type aliased_or_qualified_name join_associated_name join_conditions",
 /*  25 */ "join_associated_name ::= AS IDENTIFIER",
 /*  26 */ "join_associated_name ::= IDENTIFIER",
 /*  27 */ "join_associated_name ::=",
 /*  28 */ "join_type ::= INNER JOIN",
 /*  29 */ "join_type ::= CROSS JOIN",
 /*  30 */ "join_type ::= LEFT OUTER JOIN",
 /*  31 */ "join_type ::= LEFT JOIN",
 /*  32 */ "join_type ::= RIGHT OUTER JOIN",
 /*  33 */ "join_type ::= RIGHT JOIN",
 /*  34 */ "join_type ::= FULL OUTER JOIN",
 /*  35 */ "join_type ::= FULL JOIN",
 /*  36 */ "join_type ::= JOIN",
 /*  37 */ "join_conditions ::= ON expr",
 /*  38 */ "join_conditions ::=",
 /*  39 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  40 */ "insert_statement ::= INSERT INTO aliased_or_qualified_name PARENTHESES_OPEN field_list PARENTHESES_CLOSE VALUES PARENTHESES_OPEN values_list PARENTHESES_CLOSE",
 /*  41 */ "values_list ::= values_list COMMA value_item",
 /*  42 */ "values_list ::= value_item",
 /*  43 */ "value_item ::= expr",
 /*  44 */ "field_list ::= field_list COMMA field_item",
 /*  45 */ "field_list ::= field_item",
 /*  46 */ "field_item ::= IDENTIFIER",
 /*  47 */ "update_statement ::= update_clause where_clause limit_clause",
 /*  48 */ "update_clause ::= UPDATE associated_name SET update_item_list",
 /*  49 */ "update_item_list ::= update_item_list COMMA update_item",
 /*  50 */ "update_item_list ::= update_item",
 /*  51 */ "update_item ::= qualified_name EQUALS new_value",
 /*  52 */ "new_value ::= expr",
 /*  53 */ "delete_statement ::= delete_clause where_clause limit_clause",
 /*  54 */ "delete_clause ::= DELETE FROM associated_name",
 /*  55 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER",
 /*  56 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER",
 /*  57 */ "associated_name ::= aliased_or_qualified_name",
 /*  58 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER WITH with_item",
 /*  59 */ "associated_name ::= aliased_or_qualified_name AS IDENTIFIER WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  60 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  61 */ "associated_name ::= aliased_or_qualified_name IDENTIFIER WITH with_item",
 /*  62 */ "associated_name ::= aliased_or_qualified_name WITH PARENTHESES_OPEN with_list PARENTHESES_CLOSE",
 /*  63 */ "associated_name ::= aliased_or_qualified_name WITH with_item",
 /*  64 */ "with_list ::= with_list COMMA with_item",
 /*  65 */ "with_list ::= with_item",
 /*  66 */ "with_item ::= IDENTIFIER",
 /*  67 */ "aliased_or_qualified_name ::= qualified_name",
 /*  68 */ "where_clause ::= WHERE expr",
 /*  69 */ "where_clause ::=",
 /*  70 */ "order_clause ::= ORDER BY order_list",
 /*  71 */ "order_clause ::=",
 /*  72 */ "order_list ::= order_list COMMA order_item",
 /*  73 */ "order_list ::= order_item",
 /*  74 */ "order_item ::= expr",
 /*  75 */ "order_item ::= expr ASC",
 /*  76 */ "order_item ::= expr DESC",
 /*  77 */ "group_clause ::= GROUP BY group_list",
 /*  78 */ "group_clause ::=",
 /*  79 */ "group_list ::= group_list COMMA group_item",
 /*  80 */ "group_list ::= group_item",
 /*  81 */ "group_item ::= expr",
 /*  82 */ "having_clause ::= HAVING expr",
 /*  83 */ "having_clause ::=",
 /*  84 */ "for_update_clause ::= FOR UPDATE",
 /*  85 */ "for_update_clause ::=",
 /*  86 */ "select_limit_clause ::= LIMIT integer_or_placeholder",
 /*  87 */ "select_limit_clause ::= LIMIT integer_or_placeholder COMMA integer_or_placeholder",
 /*  88 */ "select_limit_clause ::= LIMIT integer_or_placeholder OFFSET integer_or_placeholder",
 /*  89 */ "select_limit_clause ::=",
 /*  90 */ "limit_clause ::= LIMIT integer_or_placeholder",
 /*  91 */ "limit_clause ::=",
 /*  92 */ "integer_or_placeholder ::= INTEGER",
 /*  93 */ "integer_or_placeholder ::= HINTEGER",
 /*  94 */ "integer_or_placeholder ::= NPLACEHOLDER",
 /*  95 */ "integer_or_placeholder ::= SPLACEHOLDER",
 /*  96 */ "integer_or_placeholder ::= BPLACEHOLDER",
 /*  97 */ "expr ::= MINUS expr",
 /*  98 */ "expr ::= expr MINUS expr",
 /*  99 */ "expr ::= expr PLUS expr",
 /* 100 */ "expr ::= expr TIMES expr",
 /* 101 */ "expr ::= expr DIVIDE expr",
 /* 102 */ "expr ::= expr MOD expr",
 /* 103 */ "expr ::= expr AND expr",
 /* 104 */ "expr ::= expr OR expr",
 /* 105 */ "expr ::= expr BITWISE_AND expr",
 /* 106 */ "expr ::= expr BITWISE_OR expr",
 /* 107 */ "expr ::= expr BITWISE_XOR expr",
 /* 108 */ "expr ::= expr EQUALS expr",
 /* 109 */ "expr ::= expr NOTEQUALS expr",
 /* 110 */ "expr ::= expr LESS expr",
 /* 111 */ "expr ::= expr GREATER expr",
 /* 112 */ "expr ::= expr GREATEREQUAL expr",
 /* 113 */ "expr ::= expr LESSEQUAL expr",
 /* 114 */ "expr ::= expr LIKE expr",
 /* 115 */ "expr ::= expr NOT LIKE expr",
 /* 116 */ "expr ::= expr ILIKE expr",
 /* 117 */ "expr ::= expr NOT ILIKE expr",
 /* 118 */ "expr ::= expr IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 119 */ "expr ::= expr NOT IN PARENTHESES_OPEN argument_list PARENTHESES_CLOSE",
 /* 120 */ "expr ::= PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 121 */ "expr ::= expr IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 122 */ "expr ::= expr NOT IN PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 123 */ "expr ::= EXISTS PARENTHESES_OPEN select_statement PARENTHESES_CLOSE",
 /* 124 */ "expr ::= expr AGAINST expr",
 /* 125 */ "expr ::= CAST PARENTHESES_OPEN expr AS IDENTIFIER PARENTHESES_CLOSE",
 /* 126 */ "expr ::= CONVERT PARENTHESES_OPEN expr USING IDENTIFIER PARENTHESES_CLOSE",
 /* 127 */ "expr ::= CASE expr when_clauses END",
 /* 128 */ "when_clauses ::= when_clauses when_clause",
 /* 129 */ "when_clauses ::= when_clause",
 /* 130 */ "when_clause ::= WHEN expr THEN expr",
 /* 131 */ "when_clause ::= ELSE expr",
 /* 132 */ "expr ::= function_call",
 /* 133 */ "function_call ::= IDENTIFIER PARENTHESES_OPEN distinct_or_null argument_list_or_null PARENTHESES_CLOSE",
 /* 134 */ "distinct_or_null ::= DISTINCT",
 /* 135 */ "distinct_or_null ::=",
 /* 136 */ "argument_list_or_null ::= argument_list",
 /* 137 */ "argument_list_or_null ::=",
 /* 138 */ "argument_list ::= argument_list COMMA argument_item",
 /* 139 */ "argument_list ::= argument_item",
 /* 140 */ "argument_item ::= TIMES",
 /* 141 */ "argument_item ::= expr",
 /* 142 */ "expr ::= expr IS NULL",
 /* 143 */ "expr ::= expr IS NOT NULL",
 /* 144 */ "expr ::= expr BETWEEN expr",
 /* 145 */ "expr ::= NOT expr",
 /* 146 */ "expr ::= BITWISE_NOT expr",
 /* 147 */ "expr ::= PARENTHESES_OPEN expr PARENTHESES_CLOSE",
 /* 148 */ "expr ::= qualified_name",
 /* 149 */ "expr ::= INTEGER",
 /* 150 */ "expr ::= HINTEGER",
 /* 151 */ "expr ::= STRING",
 /* 152 */ "expr ::= DOUBLE",
 /* 153 */ "expr ::= NULL",
 /* 154 */ "expr ::= TRUE",
 /* 155 */ "expr ::= FALSE",
 /* 156 */ "expr ::= NPLACEHOLDER",
 /* 157 */ "expr ::= SPLACEHOLDER",
 /* 158 */ "expr ::= BPLACEHOLDER",
 /* 159 */ "qualified_name ::= IDENTIFIER DOT IDENTIFIER",
 /* 160 */ "qualified_name ::= IDENTIFIER",
};
#endif /* NDEBUG */

/*
** This function returns the symbolic name associated with a token
** value.
*/
const char *phql_TokenName(int tokenType){
#ifndef NDEBUG
  if( tokenType>0 && tokenType<(sizeof(ppTokenName)/sizeof(ppTokenName[0])) ){
    return ppTokenName[tokenType];
  }else{
    return "Unknown";
  }
#else
  return "";
#endif
}

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to phql_ and phql_Free.
*/
void *phql_Alloc(void *(*mallocProc)(size_t)){
  ppParser *pParser;
  pParser = (ppParser*)(*mallocProc)( (size_t)sizeof(ppParser) );
  if( pParser ){
    pParser->ppidx = -1;
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "ppmajor" is the symbol code, and "pppminor" is a pointer to
** the value.
*/
static void pp_destructor(PPCODETYPE ppmajor, PPMINORTYPE *pppminor){
  switch( ppmajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 49:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
    case 68:
    case 69:
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
// 101 "parser.php7.lemon"
{
	if ((pppminor->pp0)) {
		if ((pppminor->pp0)->free_flag) {
			efree((pppminor->pp0)->token);
		}
		efree((pppminor->pp0));
	}
}
// 822 "parser.php7.c"
      break;
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 88:
    case 94:
    case 95:
    case 97:
    case 98:
    case 99:
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 108:
    case 109:
    case 111:
    case 112:
    case 114:
    case 115:
    case 118:
    case 119:
    case 120:
    case 121:
    case 122:
    case 123:
// 114 "parser.php7.lemon"
{
    zval_ptr_dtor(&(pppminor->pp204));
}
// 857 "parser.php7.c"
      break;
    case 87:
    case 89:
    case 90:
    case 91:
    case 92:
    case 93:
    case 105:
    case 106:
    case 113:
    case 130:
    case 131:
// 496 "parser.php7.lemon"
{
    zephir_safe_zval_ptr_dtor((pppminor->pp204));
}
// 874 "parser.php7.c"
      break;
    case 116:
    case 124:
    case 126:
    case 129:
    case 132:
// 939 "parser.php7.lemon"
{
	zval_ptr_dtor(&(pppminor->pp204));
}
// 885 "parser.php7.c"
      break;
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int pp_pop_parser_stack(ppParser *pParser){
  PPCODETYPE ppmajor;
  ppStackEntry *pptos = &pParser->ppstack[pParser->ppidx];

  if( pParser->ppidx<0 ) return 0;
#ifndef NDEBUG
  if( ppTraceFILE && pParser->ppidx>=0 ){
    fprintf(ppTraceFILE,"%sPopping %s\n",
      ppTracePrompt,
      ppTokenName[pptos->major]);
  }
#endif
  ppmajor = pptos->major;
  pp_destructor( ppmajor, &pptos->minor);
  pParser->ppidx--;
  return ppmajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from phql_Alloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void phql_Free(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  ppParser *pParser = (ppParser*)p;
  if( pParser==0 ) return;
  while( pParser->ppidx>=0 ) pp_pop_parser_stack(pParser);
  (*freeProc)((void*)pParser);
}

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is PPNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return PP_NO_ACTION.
*/
static int pp_find_shift_action(
  ppParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->ppstack[pParser->ppidx].stateno;
 
  /* if( pParser->ppidx<0 ) return PP_NO_ACTION;  */
  i = pp_shift_ofst[stateno];
  if( i==PP_SHIFT_USE_DFLT ){
    return pp_default[stateno];
  }
  if( iLookAhead==PPNOCODE ){
    return PP_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=PP_SZ_ACTTAB || pp_lookahead[i]!=iLookAhead ){
#ifdef PPFALLBACK
    int iFallback;            /* Fallback token */
    if( iLookAhead<sizeof(ppFallback)/sizeof(ppFallback[0])
           && (iFallback = ppFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
      if( ppTraceFILE ){
        fprintf(ppTraceFILE, "%sFALLBACK %s => %s\n",
           ppTracePrompt, ppTokenName[iLookAhead], ppTokenName[iFallback]);
      }
#endif
      return pp_find_shift_action(pParser, iFallback);
    }
#endif
    return pp_default[stateno];
  }else{
    return pp_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is PPNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return PP_NO_ACTION.
*/
static int pp_find_reduce_action(
  ppParser *pParser,        /* The parser */
  int iLookAhead            /* The look-ahead token */
){
  int i;
  int stateno = pParser->ppstack[pParser->ppidx].stateno;
 
  i = pp_reduce_ofst[stateno];
  if( i==PP_REDUCE_USE_DFLT ){
    return pp_default[stateno];
  }
  if( iLookAhead==PPNOCODE ){
    return PP_NO_ACTION;
  }
  i += iLookAhead;
  if( i<0 || i>=PP_SZ_ACTTAB || pp_lookahead[i]!=iLookAhead ){
    return pp_default[stateno];
  }else{
    return pp_action[i];
  }
}

/*
** Perform a shift action.
*/
static void pp_shift(
  ppParser *pppParser,          /* The parser to be shifted */
  int ppNewState,               /* The new state to shift in */
  int ppMajor,                  /* The major token to shift in */
  PPMINORTYPE *pppMinor         /* Pointer ot the minor token to shift in */
){
  ppStackEntry *pptos;
  pppParser->ppidx++;
  if( pppParser->ppidx>=PPSTACKDEPTH ){
     phql_ARG_FETCH;
     pppParser->ppidx--;
#ifndef NDEBUG
     if( ppTraceFILE ){
       fprintf(ppTraceFILE,"%sStack Overflow!\n",ppTracePrompt);
     }
#endif
     while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
     /* Here code is inserted which will execute if the parser
     ** stack every overflows */
     phql_ARG_STORE; /* Suppress warning about unused %extra_argument var */
     return;
  }
  pptos = &pppParser->ppstack[pppParser->ppidx];
  pptos->stateno = ppNewState;
  pptos->major = ppMajor;
  pptos->minor = *pppMinor;
#ifndef NDEBUG
  if( ppTraceFILE && pppParser->ppidx>0 ){
    int i;
    fprintf(ppTraceFILE,"%sShift %d\n",ppTracePrompt,ppNewState);
    fprintf(ppTraceFILE,"%sStack:",ppTracePrompt);
    for(i=1; i<=pppParser->ppidx; i++)
      fprintf(ppTraceFILE," %s",ppTokenName[pppParser->ppstack[i].major]);
    fprintf(ppTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static struct {
  PPCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} ppRuleInfo[] = {
  { 80, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 81, 1 },
  { 82, 7 },
  { 86, 6 },
  { 93, 1 },
  { 93, 1 },
  { 93, 0 },
  { 94, 3 },
  { 94, 1 },
  { 97, 1 },
  { 97, 3 },
  { 97, 3 },
  { 97, 2 },
  { 97, 1 },
  { 95, 3 },
  { 95, 1 },
  { 96, 1 },
  { 96, 0 },
  { 100, 2 },
  { 100, 1 },
  { 101, 1 },
  { 102, 4 },
  { 105, 2 },
  { 105, 1 },
  { 105, 0 },
  { 103, 2 },
  { 103, 2 },
  { 103, 3 },
  { 103, 2 },
  { 103, 3 },
  { 103, 2 },
  { 103, 3 },
  { 103, 2 },
  { 103, 1 },
  { 106, 2 },
  { 106, 0 },
  { 83, 7 },
  { 83, 10 },
  { 107, 3 },
  { 107, 1 },
  { 110, 1 },
  { 108, 3 },
  { 108, 1 },
  { 111, 1 },
  { 84, 3 },
  { 112, 4 },
  { 114, 3 },
  { 114, 1 },
  { 115, 3 },
  { 117, 1 },
  { 85, 3 },
  { 118, 3 },
  { 99, 3 },
  { 99, 2 },
  { 99, 1 },
  { 99, 5 },
  { 99, 7 },
  { 99, 6 },
  { 99, 4 },
  { 99, 5 },
  { 99, 3 },
  { 120, 3 },
  { 120, 1 },
  { 119, 1 },
  { 104, 1 },
  { 87, 2 },
  { 87, 0 },
  { 90, 3 },
  { 90, 0 },
  { 121, 3 },
  { 121, 1 },
  { 122, 1 },
  { 122, 2 },
  { 122, 2 },
  { 88, 3 },
  { 88, 0 },
  { 123, 3 },
  { 123, 1 },
  { 124, 1 },
  { 89, 2 },
  { 89, 0 },
  { 92, 2 },
  { 92, 0 },
  { 91, 2 },
  { 91, 4 },
  { 91, 4 },
  { 91, 0 },
  { 113, 2 },
  { 113, 0 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 125, 1 },
  { 98, 2 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 3 },
  { 98, 4 },
  { 98, 3 },
  { 98, 4 },
  { 98, 5 },
  { 98, 6 },
  { 98, 3 },
  { 98, 5 },
  { 98, 6 },
  { 98, 4 },
  { 98, 3 },
  { 98, 6 },
  { 98, 6 },
  { 98, 4 },
  { 127, 2 },
  { 127, 1 },
  { 128, 4 },
  { 128, 2 },
  { 98, 1 },
  { 129, 5 },
  { 130, 1 },
  { 130, 0 },
  { 131, 1 },
  { 131, 0 },
  { 126, 3 },
  { 126, 1 },
  { 132, 1 },
  { 132, 1 },
  { 98, 3 },
  { 98, 4 },
  { 98, 3 },
  { 98, 2 },
  { 98, 2 },
  { 98, 3 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 98, 1 },
  { 116, 3 },
  { 116, 1 },
};

static void pp_accept(ppParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void pp_reduce(
  ppParser *pppParser,         /* The parser */
  int ppruleno                 /* Number of the rule by which to reduce */
){
  int ppgoto;                     /* The next state */
  int ppact;                      /* The next action */
  PPMINORTYPE ppgotominor;        /* The LHS of the rule reduced */
  ppStackEntry *ppmsp;            /* The top of the parser's stack */
  int ppsize;                     /* Amount to pop the stack */
  phql_ARG_FETCH;
  ppmsp = &pppParser->ppstack[pppParser->ppidx];
#ifndef NDEBUG
  if( ppTraceFILE && ppruleno>=0 
        && ppruleno<sizeof(ppRuleName)/sizeof(ppRuleName[0]) ){
    fprintf(ppTraceFILE, "%sReduce [%s].\n", ppTracePrompt,
      ppRuleName[ppruleno]);
  }
#endif /* NDEBUG */

  switch( ppruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  // <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  // <lineno> <thisfile>
  **     break;
  */
      case 0:
// 110 "parser.php7.lemon"
{
	ZVAL_ZVAL(&status->ret, &ppmsp[0].minor.pp204, 1, 1);
}
// 1263 "parser.php7.c"
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 18:
      case 19:
      case 22:
      case 23:
      case 43:
      case 50:
      case 52:
      case 65:
      case 67:
      case 73:
      case 80:
      case 81:
      case 132:
      case 136:
      case 141:
      case 148:
// 118 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
}
// 1289 "parser.php7.c"
        break;
      case 5:
// 138 "parser.php7.lemon"
{
	phql_ret_select_statement(&ppgotominor.pp204, &ppmsp[-6].minor.pp204, &ppmsp[-5].minor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[-4].minor.pp204, &ppmsp[-3].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1296 "parser.php7.c"
        break;
      case 6:
// 146 "parser.php7.lemon"
{
	phql_ret_select_clause(&ppgotominor.pp204, &ppmsp[-4].minor.pp204, &ppmsp[-3].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(26,&ppmsp[-5].minor);
  pp_destructor(27,&ppmsp[-2].minor);
}
// 1305 "parser.php7.c"
        break;
      case 7:
// 154 "parser.php7.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp204, 1);
  pp_destructor(28,&ppmsp[0].minor);
}
// 1313 "parser.php7.c"
        break;
      case 8:
// 158 "parser.php7.lemon"
{
	phql_ret_distinct_all(&ppgotominor.pp204, 0);
  pp_destructor(29,&ppmsp[0].minor);
}
// 1321 "parser.php7.c"
        break;
      case 9:
      case 20:
      case 27:
      case 38:
      case 69:
      case 71:
      case 78:
      case 83:
      case 85:
      case 89:
      case 91:
      case 135:
      case 137:
// 162 "parser.php7.lemon"
{
	ZVAL_UNDEF(&ppgotominor.pp204);
}
// 1340 "parser.php7.c"
        break;
      case 10:
      case 17:
      case 41:
      case 44:
      case 49:
      case 64:
      case 72:
      case 79:
      case 138:
// 170 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1356 "parser.php7.c"
        break;
      case 11:
      case 42:
      case 45:
      case 129:
      case 139:
// 174 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp204, &ppmsp[0].minor.pp204, NULL);
}
// 1367 "parser.php7.c"
        break;
      case 12:
      case 140:
// 182 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_STARALL, NULL, NULL, NULL);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1376 "parser.php7.c"
        break;
      case 13:
// 186 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_DOMAINALL, NULL, ppmsp[-2].minor.pp0, NULL);
  pp_destructor(31,&ppmsp[-1].minor);
  pp_destructor(17,&ppmsp[0].minor);
}
// 1385 "parser.php7.c"
        break;
      case 14:
// 190 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_EXPR, &ppmsp[-2].minor.pp204, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1393 "parser.php7.c"
        break;
      case 15:
// 194 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_EXPR, &ppmsp[-1].minor.pp204, NULL, ppmsp[0].minor.pp0);
}
// 1400 "parser.php7.c"
        break;
      case 16:
// 198 "parser.php7.lemon"
{
	phql_ret_column_item(&ppgotominor.pp204, PHQL_T_EXPR, &ppmsp[0].minor.pp204, NULL, NULL);
}
// 1407 "parser.php7.c"
        break;
      case 21:
      case 128:
// 226 "parser.php7.lemon"
{
	phql_ret_zval_list(&ppgotominor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1415 "parser.php7.c"
        break;
      case 24:
// 247 "parser.php7.lemon"
{
	phql_ret_join_item(&ppgotominor.pp204, &ppmsp[-3].minor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1422 "parser.php7.c"
        break;
      case 25:
// 255 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp204, NULL, NULL, ppmsp[0].minor.pp0);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1430 "parser.php7.c"
        break;
      case 26:
      case 46:
      case 66:
      case 160:
// 259 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp204, NULL, NULL, ppmsp[0].minor.pp0);
}
// 1440 "parser.php7.c"
        break;
      case 28:
// 271 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_INNERJOIN);
  pp_destructor(33,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1449 "parser.php7.c"
        break;
      case 29:
// 275 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_CROSSJOIN);
  pp_destructor(35,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1458 "parser.php7.c"
        break;
      case 30:
// 279 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1468 "parser.php7.c"
        break;
      case 31:
// 283 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_LEFTJOIN);
  pp_destructor(36,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1477 "parser.php7.c"
        break;
      case 32:
// 287 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1487 "parser.php7.c"
        break;
      case 33:
// 291 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_RIGHTJOIN);
  pp_destructor(38,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1496 "parser.php7.c"
        break;
      case 34:
// 295 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-2].minor);
  pp_destructor(37,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1506 "parser.php7.c"
        break;
      case 35:
// 299 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_FULLJOIN);
  pp_destructor(39,&ppmsp[-1].minor);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1515 "parser.php7.c"
        break;
      case 36:
// 303 "parser.php7.lemon"
{
	phql_ret_join_type(&ppgotominor.pp204, PHQL_T_INNERJOIN);
  pp_destructor(34,&ppmsp[0].minor);
}
// 1523 "parser.php7.c"
        break;
      case 37:
// 311 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(40,&ppmsp[-1].minor);
}
// 1531 "parser.php7.c"
        break;
      case 39:
// 324 "parser.php7.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp204, &ppmsp[-4].minor.pp204, NULL, &ppmsp[-1].minor.pp204);
  pp_destructor(41,&ppmsp[-6].minor);
  pp_destructor(42,&ppmsp[-5].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1543 "parser.php7.c"
        break;
      case 40:
// 328 "parser.php7.lemon"
{
	phql_ret_insert_statement(&ppgotominor.pp204, &ppmsp[-7].minor.pp204, &ppmsp[-5].minor.pp204, &ppmsp[-1].minor.pp204);
  pp_destructor(41,&ppmsp[-9].minor);
  pp_destructor(42,&ppmsp[-8].minor);
  pp_destructor(44,&ppmsp[-6].minor);
  pp_destructor(45,&ppmsp[-4].minor);
  pp_destructor(43,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1557 "parser.php7.c"
        break;
      case 47:
// 374 "parser.php7.lemon"
{
	phql_ret_update_statement(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1564 "parser.php7.c"
        break;
      case 48:
// 382 "parser.php7.lemon"
{
	phql_ret_update_clause(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(46,&ppmsp[-3].minor);
  pp_destructor(47,&ppmsp[-1].minor);
}
// 1573 "parser.php7.c"
        break;
      case 51:
// 402 "parser.php7.lemon"
{
	phql_ret_update_item(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1581 "parser.php7.c"
        break;
      case 53:
// 416 "parser.php7.lemon"
{
	phql_ret_delete_statement(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[-1].minor.pp204, &ppmsp[0].minor.pp204);
}
// 1588 "parser.php7.c"
        break;
      case 54:
// 424 "parser.php7.lemon"
{
	phql_ret_delete_clause(&ppgotominor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(48,&ppmsp[-2].minor);
  pp_destructor(27,&ppmsp[-1].minor);
}
// 1597 "parser.php7.c"
        break;
      case 55:
// 432 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, ppmsp[0].minor.pp0, NULL);
  pp_destructor(32,&ppmsp[-1].minor);
}
// 1605 "parser.php7.c"
        break;
      case 56:
// 436 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-1].minor.pp204, ppmsp[0].minor.pp0, NULL);
}
// 1612 "parser.php7.c"
        break;
      case 57:
// 440 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[0].minor.pp204, NULL, NULL);
}
// 1619 "parser.php7.c"
        break;
      case 58:
// 444 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-4].minor.pp204, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp204);
  pp_destructor(32,&ppmsp[-3].minor);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1628 "parser.php7.c"
        break;
      case 59:
// 448 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-6].minor.pp204, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp204);
  pp_destructor(32,&ppmsp[-5].minor);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1639 "parser.php7.c"
        break;
      case 60:
// 452 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-5].minor.pp204, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp204);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1649 "parser.php7.c"
        break;
      case 61:
// 456 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-3].minor.pp204, ppmsp[-2].minor.pp0, &ppmsp[0].minor.pp204);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1657 "parser.php7.c"
        break;
      case 62:
// 460 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-4].minor.pp204, NULL, &ppmsp[-1].minor.pp204);
  pp_destructor(49,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1667 "parser.php7.c"
        break;
      case 63:
// 464 "parser.php7.lemon"
{
	phql_ret_assoc_name(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, NULL, &ppmsp[0].minor.pp204);
  pp_destructor(49,&ppmsp[-1].minor);
}
// 1675 "parser.php7.c"
        break;
      case 68:
// 500 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(50,&ppmsp[-1].minor);
}
// 1683 "parser.php7.c"
        break;
      case 70:
// 512 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(51,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 1692 "parser.php7.c"
        break;
      case 74:
// 536 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp204, &ppmsp[0].minor.pp204, 0);
}
// 1699 "parser.php7.c"
        break;
      case 75:
// 540 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp204, &ppmsp[-1].minor.pp204, PHQL_T_ASC);
  pp_destructor(53,&ppmsp[0].minor);
}
// 1707 "parser.php7.c"
        break;
      case 76:
// 544 "parser.php7.lemon"
{
	phql_ret_order_item(&ppgotominor.pp204, &ppmsp[-1].minor.pp204, PHQL_T_DESC);
  pp_destructor(54,&ppmsp[0].minor);
}
// 1715 "parser.php7.c"
        break;
      case 77:
// 552 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(55,&ppmsp[-2].minor);
  pp_destructor(52,&ppmsp[-1].minor);
}
// 1724 "parser.php7.c"
        break;
      case 82:
// 584 "parser.php7.lemon"
{
	ppgotominor.pp204 = ppmsp[0].minor.pp204;
  pp_destructor(56,&ppmsp[-1].minor);
}
// 1732 "parser.php7.c"
        break;
      case 84:
// 596 "parser.php7.lemon"
{
	phql_ret_for_update_clause(&ppgotominor.pp204);
  pp_destructor(57,&ppmsp[-1].minor);
  pp_destructor(46,&ppmsp[0].minor);
}
// 1741 "parser.php7.c"
        break;
      case 86:
      case 90:
// 608 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp204, &ppmsp[0].minor.pp204, NULL);
  pp_destructor(58,&ppmsp[-1].minor);
}
// 1750 "parser.php7.c"
        break;
      case 87:
// 612 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp204, &ppmsp[0].minor.pp204, &ppmsp[-2].minor.pp204);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(25,&ppmsp[-1].minor);
}
// 1759 "parser.php7.c"
        break;
      case 88:
// 616 "parser.php7.lemon"
{
	phql_ret_limit_clause(&ppgotominor.pp204, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(58,&ppmsp[-3].minor);
  pp_destructor(59,&ppmsp[-1].minor);
}
// 1768 "parser.php7.c"
        break;
      case 92:
      case 149:
// 636 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_INTEGER, ppmsp[0].minor.pp0);
}
// 1776 "parser.php7.c"
        break;
      case 93:
      case 150:
// 640 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_HINTEGER, ppmsp[0].minor.pp0);
}
// 1784 "parser.php7.c"
        break;
      case 94:
      case 156:
// 644 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp204, PHQL_T_NPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1792 "parser.php7.c"
        break;
      case 95:
      case 157:
// 648 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp204, PHQL_T_SPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1800 "parser.php7.c"
        break;
      case 96:
      case 158:
// 652 "parser.php7.lemon"
{
	phql_ret_placeholder_zval(&ppgotominor.pp204, PHQL_T_BPLACEHOLDER, ppmsp[0].minor.pp0);
}
// 1808 "parser.php7.c"
        break;
      case 97:
// 660 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_MINUS, NULL, &ppmsp[0].minor.pp204);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 1816 "parser.php7.c"
        break;
      case 98:
// 664 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_SUB, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(20,&ppmsp[-1].minor);
}
// 1824 "parser.php7.c"
        break;
      case 99:
// 668 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ADD, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(19,&ppmsp[-1].minor);
}
// 1832 "parser.php7.c"
        break;
      case 100:
// 672 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_MUL, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(17,&ppmsp[-1].minor);
}
// 1840 "parser.php7.c"
        break;
      case 101:
// 676 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_DIV, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(16,&ppmsp[-1].minor);
}
// 1848 "parser.php7.c"
        break;
      case 102:
// 680 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_MOD, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(18,&ppmsp[-1].minor);
}
// 1856 "parser.php7.c"
        break;
      case 103:
// 684 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_AND, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(9,&ppmsp[-1].minor);
}
// 1864 "parser.php7.c"
        break;
      case 104:
// 688 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_OR, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(10,&ppmsp[-1].minor);
}
// 1872 "parser.php7.c"
        break;
      case 105:
// 692 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BITWISE_AND, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(13,&ppmsp[-1].minor);
}
// 1880 "parser.php7.c"
        break;
      case 106:
// 696 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BITWISE_OR, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(14,&ppmsp[-1].minor);
}
// 1888 "parser.php7.c"
        break;
      case 107:
// 700 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BITWISE_XOR, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(15,&ppmsp[-1].minor);
}
// 1896 "parser.php7.c"
        break;
      case 108:
// 704 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_EQUALS, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(3,&ppmsp[-1].minor);
}
// 1904 "parser.php7.c"
        break;
      case 109:
// 708 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NOTEQUALS, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(4,&ppmsp[-1].minor);
}
// 1912 "parser.php7.c"
        break;
      case 110:
// 712 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_LESS, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(5,&ppmsp[-1].minor);
}
// 1920 "parser.php7.c"
        break;
      case 111:
// 716 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_GREATER, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(6,&ppmsp[-1].minor);
}
// 1928 "parser.php7.c"
        break;
      case 112:
// 720 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_GREATEREQUAL, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(7,&ppmsp[-1].minor);
}
// 1936 "parser.php7.c"
        break;
      case 113:
// 724 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_LESSEQUAL, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(8,&ppmsp[-1].minor);
}
// 1944 "parser.php7.c"
        break;
      case 114:
// 728 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_LIKE, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 1952 "parser.php7.c"
        break;
      case 115:
// 732 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NLIKE, &ppmsp[-3].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(11,&ppmsp[-1].minor);
}
// 1961 "parser.php7.c"
        break;
      case 116:
// 736 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ILIKE, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1969 "parser.php7.c"
        break;
      case 117:
// 740 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NILIKE, &ppmsp[-3].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(23,&ppmsp[-2].minor);
  pp_destructor(12,&ppmsp[-1].minor);
}
// 1978 "parser.php7.c"
        break;
      case 118:
      case 121:
// 744 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_IN, &ppmsp[-4].minor.pp204, &ppmsp[-1].minor.pp204);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 1989 "parser.php7.c"
        break;
      case 119:
      case 122:
// 748 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NOTIN, &ppmsp[-5].minor.pp204, &ppmsp[-1].minor.pp204);
  pp_destructor(23,&ppmsp[-4].minor);
  pp_destructor(22,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2001 "parser.php7.c"
        break;
      case 120:
// 752 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_SUBQUERY, &ppmsp[-1].minor.pp204, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2010 "parser.php7.c"
        break;
      case 123:
// 764 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_EXISTS, NULL, &ppmsp[-1].minor.pp204);
  pp_destructor(65,&ppmsp[-3].minor);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2020 "parser.php7.c"
        break;
      case 124:
// 768 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_AGAINST, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(1,&ppmsp[-1].minor);
}
// 2028 "parser.php7.c"
        break;
      case 125:
// 772 "parser.php7.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, ppmsp[-1].minor.pp0, NULL);
		phql_ret_expr(&ppgotominor.pp204, PHQL_T_CAST, &ppmsp[-3].minor.pp204, &qualified);
	}
  pp_destructor(66,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(32,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2043 "parser.php7.c"
        break;
      case 126:
// 780 "parser.php7.lemon"
{
	{
		zval qualified;
		phql_ret_raw_qualified_name(&qualified, ppmsp[-1].minor.pp0, NULL);
		phql_ret_expr(&ppgotominor.pp204, PHQL_T_CONVERT, &ppmsp[-3].minor.pp204, &qualified);
	}
  pp_destructor(67,&ppmsp[-5].minor);
  pp_destructor(44,&ppmsp[-4].minor);
  pp_destructor(68,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2058 "parser.php7.c"
        break;
      case 127:
// 788 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_CASE, &ppmsp[-2].minor.pp204, &ppmsp[-1].minor.pp204);
  pp_destructor(69,&ppmsp[-3].minor);
  pp_destructor(70,&ppmsp[0].minor);
}
// 2067 "parser.php7.c"
        break;
      case 130:
// 800 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_WHEN, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(71,&ppmsp[-3].minor);
  pp_destructor(72,&ppmsp[-1].minor);
}
// 2076 "parser.php7.c"
        break;
      case 131:
// 804 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ELSE, &ppmsp[0].minor.pp204, NULL);
  pp_destructor(73,&ppmsp[-1].minor);
}
// 2084 "parser.php7.c"
        break;
      case 133:
// 816 "parser.php7.lemon"
{
	phql_ret_func_call(&ppgotominor.pp204, ppmsp[-4].minor.pp0, &ppmsp[-1].minor.pp204, &ppmsp[-2].minor.pp204);
  pp_destructor(44,&ppmsp[-3].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2093 "parser.php7.c"
        break;
      case 134:
// 824 "parser.php7.lemon"
{
	phql_ret_distinct(&ppgotominor.pp204);
  pp_destructor(28,&ppmsp[0].minor);
}
// 2101 "parser.php7.c"
        break;
      case 142:
// 868 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ISNULL, &ppmsp[-2].minor.pp204, NULL);
  pp_destructor(21,&ppmsp[-1].minor);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2110 "parser.php7.c"
        break;
      case 143:
// 872 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ISNOTNULL, &ppmsp[-3].minor.pp204, NULL);
  pp_destructor(21,&ppmsp[-2].minor);
  pp_destructor(23,&ppmsp[-1].minor);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2120 "parser.php7.c"
        break;
      case 144:
// 876 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BETWEEN, &ppmsp[-2].minor.pp204, &ppmsp[0].minor.pp204);
  pp_destructor(2,&ppmsp[-1].minor);
}
// 2128 "parser.php7.c"
        break;
      case 145:
// 880 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_NOT, NULL, &ppmsp[0].minor.pp204);
  pp_destructor(23,&ppmsp[-1].minor);
}
// 2136 "parser.php7.c"
        break;
      case 146:
// 884 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_BITWISE_NOT, NULL, &ppmsp[0].minor.pp204);
  pp_destructor(24,&ppmsp[-1].minor);
}
// 2144 "parser.php7.c"
        break;
      case 147:
// 888 "parser.php7.lemon"
{
	phql_ret_expr(&ppgotominor.pp204, PHQL_T_ENCLOSED, &ppmsp[-1].minor.pp204, NULL);
  pp_destructor(44,&ppmsp[-2].minor);
  pp_destructor(45,&ppmsp[0].minor);
}
// 2153 "parser.php7.c"
        break;
      case 151:
// 904 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_STRING, ppmsp[0].minor.pp0);
}
// 2160 "parser.php7.c"
        break;
      case 152:
// 908 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_DOUBLE, ppmsp[0].minor.pp0);
}
// 2167 "parser.php7.c"
        break;
      case 153:
// 912 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_NULL, NULL);
  pp_destructor(74,&ppmsp[0].minor);
}
// 2175 "parser.php7.c"
        break;
      case 154:
// 916 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_TRUE, NULL);
  pp_destructor(77,&ppmsp[0].minor);
}
// 2183 "parser.php7.c"
        break;
      case 155:
// 920 "parser.php7.lemon"
{
	phql_ret_literal_zval(&ppgotominor.pp204, PHQL_T_FALSE, NULL);
  pp_destructor(78,&ppmsp[0].minor);
}
// 2191 "parser.php7.c"
        break;
      case 159:
// 943 "parser.php7.lemon"
{
	phql_ret_qualified_name(&ppgotominor.pp204, NULL, ppmsp[-2].minor.pp0, ppmsp[0].minor.pp0);
  pp_destructor(31,&ppmsp[-1].minor);
}
// 2199 "parser.php7.c"
        break;
  };
  ppgoto = ppRuleInfo[ppruleno].lhs;
  ppsize = ppRuleInfo[ppruleno].nrhs;
  pppParser->ppidx -= ppsize;
  ppact = pp_find_reduce_action(pppParser,ppgoto);
  if( ppact < PPNSTATE ){
    pp_shift(pppParser,ppact,ppgoto,&ppgotominor);
  }else if( ppact == PPNSTATE + PPNRULE + 1 ){
    pp_accept(pppParser);
  }
}

/*
** The following code executes when the parse fails
*/
static void pp_parse_failed(
  ppParser *pppParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sFail!\n",ppTracePrompt);
  }
#endif
  while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following code executes when a syntax error first occurs.
*/
static void pp_syntax_error(
  ppParser *pppParser,           /* The parser */
  int ppmajor,                   /* The major type of the error token */
  PPMINORTYPE ppminor            /* The minor type of the error token */
){
  phql_ARG_FETCH;
#define PPTOKEN (ppminor.pp0)
// 34 "parser.php7.lemon"

	if (status->scanner_state->start_length) {
		{

			char *token_name = NULL;
			int token_found = 0;
			unsigned int token_length;
			const phql_token_names *tokens = phql_tokens;
			int active_token = status->scanner_state->active_token;
			int near_length = status->scanner_state->start_length;

			if (active_token) {

				do {
					if (tokens->code == active_token) {
						token_name = tokens->name;
						token_length = tokens->length;
						token_found = 1;
						break;
					}
					++tokens;
				} while (tokens[0].code != 0);

			}

			if (!token_name) {
				token_length = strlen("UNKNOWN");
				token_name = estrndup("UNKNOWN", token_length);
				token_found = 0;
			}

			status->syntax_error_len = 96 + status->token->len + token_length + near_length + status->phql_length;;
			status->syntax_error = emalloc(sizeof(char) * status->syntax_error_len);

			if (near_length > 0) {
				if (status->token->value) {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), near to '%s', when parsing: %s (%d)", token_name, status->token->value, status->scanner_state->start, status->phql, status->phql_length);
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, near to '%s', when parsing: %s (%d)", token_name, status->scanner_state->start, status->phql, status->phql_length);
				}
			} else {
				if (active_token != PHQL_T_IGNORE) {
					if (status->token->value) {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s(%s), at the end of query, when parsing: %s (%d)", token_name, status->token->value, status->phql, status->phql_length);
					} else {
						snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected token %s, at the end of query, when parsing: %s (%d)", token_name, status->phql, status->phql_length);
					}
				} else {
					snprintf(status->syntax_error, status->syntax_error_len, "Syntax error, unexpected EOF, at the end of query");
				}
				status->syntax_error[status->syntax_error_len - 1] = '\0';
			}

			if (!token_found) {
				if (token_name) {
					efree(token_name);
				}
			}
		}
	} else {
		status->syntax_error_len = strlen("Syntax error, unexpected EOF");
		status->syntax_error = estrndup("Syntax error, unexpected EOF", status->syntax_error_len);
	}

	status->status = PHQL_PARSING_FAILED;

// 2308 "parser.php7.c"
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void pp_accept(
  ppParser *pppParser           /* The parser */
){
  phql_ARG_FETCH;
#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sAccept!\n",ppTracePrompt);
  }
#endif
  while( pppParser->ppidx>=0 ) pp_pop_parser_stack(pppParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  phql_ARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "phql_Alloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void phql_(
  void *ppp,                   /* The parser */
  int ppmajor,                 /* The major token code number */
  phql_TOKENTYPE ppminor       /* The value for the token */
  phql_ARG_PDECL               /* Optional %extra_argument parameter */
){
  PPMINORTYPE ppminorunion;
  int ppact;            /* The parser action. */
  int ppendofinput;     /* True if we are at the end of input */
  int pperrorhit = 0;   /* True if ppmajor has invoked an error */
  ppParser *pppParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  pppParser = (ppParser*)ppp;
  if( pppParser->ppidx<0 ){
    if( ppmajor==0 ) return;
    pppParser->ppidx = 0;
    pppParser->pperrcnt = -1;
    pppParser->ppstack[0].stateno = 0;
    pppParser->ppstack[0].major = 0;
  }
  ppminorunion.pp0 = ppminor;
  ppendofinput = (ppmajor==0);
  phql_ARG_STORE;

#ifndef NDEBUG
  if( ppTraceFILE ){
    fprintf(ppTraceFILE,"%sInput %s\n",ppTracePrompt,ppTokenName[ppmajor]);
  }
#endif

  do{
    ppact = pp_find_shift_action(pppParser,ppmajor);
    if( ppact<PPNSTATE ){
      pp_shift(pppParser,ppact,ppmajor,&ppminorunion);
      pppParser->pperrcnt--;
      if( ppendofinput && pppParser->ppidx>=0 ){
        ppmajor = 0;
      }else{
        ppmajor = PPNOCODE;
      }
    }else if( ppact < PPNSTATE + PPNRULE ){
      pp_reduce(pppParser,ppact-PPNSTATE);
    }else if( ppact == PP_ERROR_ACTION ){
      int ppmx;
#ifndef NDEBUG
      if( ppTraceFILE ){
        fprintf(ppTraceFILE,"%sSyntax Error!\n",ppTracePrompt);
      }
#endif
#ifdef PPERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( pppParser->pperrcnt<0 ){
        pp_syntax_error(pppParser,ppmajor,ppminorunion);
      }
      ppmx = pppParser->ppstack[pppParser->ppidx].major;
      if( ppmx==PPERRORSYMBOL || pperrorhit ){
#ifndef NDEBUG
        if( ppTraceFILE ){
          fprintf(ppTraceFILE,"%sDiscard input token %s\n",
             ppTracePrompt,ppTokenName[ppmajor]);
        }
#endif
        pp_destructor(ppmajor,&ppminorunion);
        ppmajor = PPNOCODE;
      }else{
         while(
          pppParser->ppidx >= 0 &&
          ppmx != PPERRORSYMBOL &&
          (ppact = pp_find_shift_action(pppParser,PPERRORSYMBOL)) >= PPNSTATE
        ){
          pp_pop_parser_stack(pppParser);
        }
        if( pppParser->ppidx < 0 || ppmajor==0 ){
          pp_destructor(ppmajor,&ppminorunion);
          pp_parse_failed(pppParser);
          ppmajor = PPNOCODE;
        }else if( ppmx!=PPERRORSYMBOL ){
          PPMINORTYPE u2;
          u2.PPERRSYMDT = 0;
          pp_shift(pppParser,ppact,PPERRORSYMBOL,&u2);
        }
      }
      pppParser->pperrcnt = 3;
      pperrorhit = 1;
#else  /* PPERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( pppParser->pperrcnt<=0 ){
        pp_syntax_error(pppParser,ppmajor,ppminorunion);
      }
      pppParser->pperrcnt = 3;
      pp_destructor(ppmajor,&ppminorunion);
      if( ppendofinput ){
        pp_parse_failed(pppParser);
      }
      ppmajor = PPNOCODE;
#endif
    }else{
      pp_accept(pppParser);
      ppmajor = PPNOCODE;
    }
  }while( ppmajor!=PPNOCODE && pppParser->ppidx>=0 );
  return;
}
/* base.c
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

const phql_token_names phql_tokens[] =
{
  { SL("INTEGER"),			   PHQL_T_INTEGER },
  { SL("DOUBLE"),			   PHQL_T_DOUBLE },
  { SL("STRING"),			   PHQL_T_STRING },
  { SL("IDENTIFIER"),		   PHQL_T_IDENTIFIER },
  { SL("HEXAINTEGER"),		   PHQL_T_HINTEGER },
  { SL("MINUS"),			   PHQL_T_MINUS },
  { SL("+"),				   PHQL_T_ADD },
  { SL("-"),				   PHQL_T_SUB },
  { SL("*"),				   PHQL_T_MUL },
  { SL("/"),				   PHQL_T_DIV },
  { SL("&"),				   PHQL_T_BITWISE_AND },
  { SL("|"),				   PHQL_T_BITWISE_OR },
  { SL("%%"),				   PHQL_T_MOD },
  { SL("AND"),				   PHQL_T_AND },
  { SL("OR"),				   PHQL_T_OR },
  { SL("LIKE"),				   PHQL_T_LIKE },
  { SL("ILIKE"),			   PHQL_T_ILIKE },
  { SL("DOT"),				   PHQL_T_DOT },
  { SL("COLON"),			   PHQL_T_COLON },
  { SL("COMMA"),			   PHQL_T_COMMA },
  { SL("EQUALS"),			   PHQL_T_EQUALS },
  { SL("NOT EQUALS"),		   PHQL_T_NOTEQUALS },
  { SL("NOT"),				   PHQL_T_NOT },
  { SL("<"),				   PHQL_T_LESS },
  { SL("<="),				   PHQL_T_LESSEQUAL },
  { SL(">"),				   PHQL_T_GREATER },
  { SL(">="),				   PHQL_T_GREATEREQUAL },
  { SL("("),				   PHQL_T_PARENTHESES_OPEN },
  { SL(")"),				   PHQL_T_PARENTHESES_CLOSE },
  { SL("NUMERIC PLACEHOLDER"), PHQL_T_NPLACEHOLDER },
  { SL("STRING PLACEHOLDER"),  PHQL_T_SPLACEHOLDER },
  { SL("UPDATE"),			   PHQL_T_UPDATE },
  { SL("SET"),				   PHQL_T_SET },
  { SL("WHERE"),			   PHQL_T_WHERE },
  { SL("DELETE"),			   PHQL_T_DELETE },
  { SL("FROM"),				   PHQL_T_FROM },
  { SL("AS"),				   PHQL_T_AS },
  { SL("INSERT"),			   PHQL_T_INSERT },
  { SL("INTO"),				   PHQL_T_INTO },
  { SL("VALUES"),			   PHQL_T_VALUES },
  { SL("SELECT"),			   PHQL_T_SELECT },
  { SL("ORDER"),			   PHQL_T_ORDER },
  { SL("BY"),			       PHQL_T_BY },
  { SL("LIMIT"),		       PHQL_T_LIMIT },
  { SL("OFFSET"),		       PHQL_T_OFFSET },
  { SL("GROUP"),		       PHQL_T_GROUP },
  { SL("HAVING"),		       PHQL_T_HAVING },
  { SL("IN"),			       PHQL_T_IN },
  { SL("ON"),			       PHQL_T_ON },
  { SL("INNER"),		       PHQL_T_INNER },
  { SL("JOIN"),		           PHQL_T_JOIN },
  { SL("LEFT"),		           PHQL_T_LEFT },
  { SL("RIGHT"),		       PHQL_T_RIGHT },
  { SL("IS"),			       PHQL_T_IS },
  { SL("NULL"),		           PHQL_T_NULL },
  { SL("NOT IN"),		       PHQL_T_NOTIN },
  { SL("CROSS"),		       PHQL_T_CROSS },
  { SL("OUTER"),		       PHQL_T_OUTER },
  { SL("FULL"),		           PHQL_T_FULL },
  { SL("ASC"),		           PHQL_T_ASC },
  { SL("DESC"),		           PHQL_T_DESC },
  { SL("BETWEEN"),	           PHQL_T_BETWEEN },
  { SL("DISTINCT"),	           PHQL_T_DISTINCT },
  { SL("AGAINST"),	           PHQL_T_AGAINST },
  { SL("CAST"),		           PHQL_T_CAST },
  { SL("CONVERT"),	           PHQL_T_CONVERT },
  { SL("USING"),		       PHQL_T_USING },
  { SL("ALL"),		           PHQL_T_ALL },
  { SL("EXISTS"),		       PHQL_T_EXISTS },
  { SL("CASE"),		           PHQL_T_CASE },
  { SL("WHEN"),		           PHQL_T_WHEN },
  { SL("THEN"),		           PHQL_T_THEN },
  { SL("ELSE"),		           PHQL_T_ELSE },
  { SL("END"),		           PHQL_T_END },
  { SL("FOR"),		           PHQL_T_FOR },
  { SL("WITH"),		           PHQL_T_WITH },
  { NULL, 0, 0 }
};

static void *phql_wrapper_alloc(size_t bytes)
{
	return emalloc(bytes);
}

static void phql_wrapper_free(void *pointer)
{
	efree(pointer);
}

static void phql_parse_with_token(void* phql_parser, int opcode, int parsercode, phql_scanner_token *token, phql_parser_status *parser_status)
{

	phql_parser_token *pToken;

	pToken = emalloc(sizeof(phql_parser_token));
	pToken->opcode = opcode;
	pToken->token = token->value;
	pToken->token_len = token->len;
	pToken->free_flag = 1;
	phql_(phql_parser, parsercode, pToken, parser_status);

	token->value = NULL;
	token->len = 0;
}

/**
 * Creates an error message when it's triggered by the scanner
 */
static void phql_scanner_error_msg(phql_parser_status *parser_status, zval **error_msg TSRMLS_DC)
{

	char *error = NULL, *error_part;
	unsigned int length;
	phql_scanner_state *state = parser_status->scanner_state;

    ZVAL_UNDEF(*error_msg);

	if (state->start) {
		length = 64 + state->start_length + parser_status->phql_length;
		error = emalloc(sizeof(char) * length);
		if (state->start_length > 16) {
			error_part = estrndup(state->start, 16);
			snprintf(error, length, "Scanning error before '%s...' when parsing: %s (%d)", error_part, parser_status->phql, parser_status->phql_length);
			efree(error_part);
		} else {
			snprintf(error, length, "Scanning error before '%s' when parsing: %s (%d)", state->start, parser_status->phql, parser_status->phql_length);
		}
		error[length - 1] = '\0';
        ZVAL_STRING(*error_msg, error);
	} else {
		ZVAL_STRING(*error_msg, "Scanning error near to EOF");
	}

	if (error) {
		efree(error);
	}
}

/**
 * Executes the internal PHQL parser/tokenizer
 */
int phql_parse_phql(zval *result, zval *phql TSRMLS_DC)
{
    zval err_msg, *error_msg = &err_msg;
    ZVAL_UNDEF(error_msg);
	ZVAL_NULL(result);

	if (phql_internal_parse_phql(&result, Z_STRVAL_P(phql), Z_STRLEN_P(phql), &error_msg TSRMLS_CC) == FAILURE) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, Z_STRVAL_P(error_msg));
		return FAILURE;
	}

	return SUCCESS;
}

/**
 * Executes a PHQL parser/tokenizer
 */
int phql_internal_parse_phql(zval **result, char *phql, unsigned int phql_length, zval **error_msg TSRMLS_DC)
{
	zend_phalcon_globals *phalcon_globals_ptr = ZEPHIR_VGLOBAL;
	phql_parser_status *parser_status = NULL;
	int scanner_status, status = SUCCESS, error_length, cache_level;
	phql_scanner_state *state;
	phql_scanner_token token;
	void* phql_parser;
	char *error;
    unsigned long phql_key = 0;
    zval *temp_ast;

	if (!phql) {
		ZVAL_STRING(*error_msg, "PHQL statement cannot be NULL");
		return FAILURE;
	}

	cache_level = phalcon_globals_ptr->orm.cache_level;
	if (cache_level >= 0) {
		phql_key = zend_inline_hash_func(phql, phql_length + 1);
		if (phalcon_globals_ptr->orm.parser_cache != NULL) {
            if ((temp_ast = zend_hash_index_find(phalcon_globals_ptr->orm.parser_cache, phql_key)) != NULL) {
                ZVAL_ZVAL(*result, temp_ast, 1, 0);
                Z_TRY_ADDREF_P(*result);
                return SUCCESS;
            }
		}
	}

	phql_parser = phql_Alloc(phql_wrapper_alloc);

	parser_status = emalloc(sizeof(phql_parser_status));
	state = emalloc(sizeof(phql_scanner_state));

	parser_status->status = PHQL_PARSING_OK;
	parser_status->scanner_state = state;
    ZVAL_UNDEF(&parser_status->ret);

	parser_status->syntax_error = NULL;
	parser_status->token = &token;
	parser_status->enable_literals = phalcon_globals_ptr->orm.enable_literals;
	parser_status->phql = phql;
	parser_status->phql_length = phql_length;

	state->active_token = 0;
	state->start = phql;
	state->start_length = 0;
	state->end = state->start;

	token.value = NULL;
	token.len = 0;

	while (0 <= (scanner_status = phql_get_token(state, &token))) {

		/* Calculate the 'start' length */
		state->start_length = (phql + phql_length - state->start);

		state->active_token = token.opcode;

		/* Parse the token found */
		switch (token.opcode) {

			case PHQL_T_IGNORE:
				break;

			case PHQL_T_ADD:
				phql_(phql_parser, PHQL_PLUS, NULL, parser_status);
				break;
			case PHQL_T_SUB:
				phql_(phql_parser, PHQL_MINUS, NULL, parser_status);
				break;
			case PHQL_T_MUL:
				phql_(phql_parser, PHQL_TIMES, NULL, parser_status);
				break;
			case PHQL_T_DIV:
				phql_(phql_parser, PHQL_DIVIDE, NULL, parser_status);
				break;
			case PHQL_T_MOD:
				phql_(phql_parser, PHQL_MOD, NULL, parser_status);
				break;
			case PHQL_T_AND:
				phql_(phql_parser, PHQL_AND, NULL, parser_status);
				break;
			case PHQL_T_OR:
				phql_(phql_parser, PHQL_OR, NULL, parser_status);
				break;
			case PHQL_T_EQUALS:
				phql_(phql_parser, PHQL_EQUALS, NULL, parser_status);
				break;
			case PHQL_T_NOTEQUALS:
				phql_(phql_parser, PHQL_NOTEQUALS, NULL, parser_status);
				break;
			case PHQL_T_LESS:
				phql_(phql_parser, PHQL_LESS, NULL, parser_status);
				break;
			case PHQL_T_GREATER:
				phql_(phql_parser, PHQL_GREATER, NULL, parser_status);
				break;
			case PHQL_T_GREATEREQUAL:
				phql_(phql_parser, PHQL_GREATEREQUAL, NULL, parser_status);
				break;
			case PHQL_T_LESSEQUAL:
				phql_(phql_parser, PHQL_LESSEQUAL, NULL, parser_status);
				break;

			case PHQL_T_IDENTIFIER:
				phql_parse_with_token(phql_parser, PHQL_T_IDENTIFIER, PHQL_IDENTIFIER, &token, parser_status);
				break;

			case PHQL_T_DOT:
				phql_(phql_parser, PHQL_DOT, NULL, parser_status);
				break;
			case PHQL_T_COMMA:
				phql_(phql_parser, PHQL_COMMA, NULL, parser_status);
				break;

			case PHQL_T_PARENTHESES_OPEN:
				phql_(phql_parser, PHQL_PARENTHESES_OPEN, NULL, parser_status);
				break;
			case PHQL_T_PARENTHESES_CLOSE:
				phql_(phql_parser, PHQL_PARENTHESES_CLOSE, NULL, parser_status);
				break;

			case PHQL_T_LIKE:
				phql_(phql_parser, PHQL_LIKE, NULL, parser_status);
				break;
			case PHQL_T_ILIKE:
				phql_(phql_parser, PHQL_ILIKE, NULL, parser_status);
				break;
			case PHQL_T_NOT:
				phql_(phql_parser, PHQL_NOT, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_AND:
				phql_(phql_parser, PHQL_BITWISE_AND, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_OR:
				phql_(phql_parser, PHQL_BITWISE_OR, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_NOT:
				phql_(phql_parser, PHQL_BITWISE_NOT, NULL, parser_status);
				break;
			case PHQL_T_BITWISE_XOR:
				phql_(phql_parser, PHQL_BITWISE_XOR, NULL, parser_status);
				break;
			case PHQL_T_AGAINST:
				phql_(phql_parser, PHQL_AGAINST, NULL, parser_status);
				break;
			case PHQL_T_CASE:
				phql_(phql_parser, PHQL_CASE, NULL, parser_status);
				break;
			case PHQL_T_WHEN:
				phql_(phql_parser, PHQL_WHEN, NULL, parser_status);
				break;
			case PHQL_T_THEN:
				phql_(phql_parser, PHQL_THEN, NULL, parser_status);
				break;
			case PHQL_T_END:
				phql_(phql_parser, PHQL_END, NULL, parser_status);
				break;
			case PHQL_T_ELSE:
				phql_(phql_parser, PHQL_ELSE, NULL, parser_status);
				break;
			case PHQL_T_FOR:
				phql_(phql_parser, PHQL_FOR, NULL, parser_status);
				break;
            case PHQL_T_WITH:
    			phql_(phql_parser, PHQL_WITH, NULL, parser_status);
    			break;

			case PHQL_T_INTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_INTEGER, PHQL_INTEGER, &token, parser_status);
				} else {
					ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_DOUBLE:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_DOUBLE, PHQL_DOUBLE, &token, parser_status);
				} else {
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_STRING:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_STRING, PHQL_STRING, &token, parser_status);
				} else {
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_TRUE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_TRUE, NULL, parser_status);
				} else {
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_FALSE:
				if (parser_status->enable_literals) {
					phql_(phql_parser, PHQL_FALSE, NULL, parser_status);
				} else {
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;
			case PHQL_T_HINTEGER:
				if (parser_status->enable_literals) {
					phql_parse_with_token(phql_parser, PHQL_T_HINTEGER, PHQL_HINTEGER, &token, parser_status);
				} else {
                    ZVAL_STRING(*error_msg, "Literals are disabled in PHQL statements");
					parser_status->status = PHQL_PARSING_FAILED;
				}
				break;

			case PHQL_T_NPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_NPLACEHOLDER, PHQL_NPLACEHOLDER, &token, parser_status);
				break;
			case PHQL_T_SPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_SPLACEHOLDER, PHQL_SPLACEHOLDER, &token, parser_status);
				break;
			case PHQL_T_BPLACEHOLDER:
				phql_parse_with_token(phql_parser, PHQL_T_BPLACEHOLDER, PHQL_BPLACEHOLDER, &token, parser_status);
				break;

			case PHQL_T_FROM:
				phql_(phql_parser, PHQL_FROM, NULL, parser_status);
				break;
			case PHQL_T_UPDATE:
				phql_(phql_parser, PHQL_UPDATE, NULL, parser_status);
				break;
			case PHQL_T_SET:
				phql_(phql_parser, PHQL_SET, NULL, parser_status);
				break;
			case PHQL_T_WHERE:
				phql_(phql_parser, PHQL_WHERE, NULL, parser_status);
				break;
			case PHQL_T_DELETE:
				phql_(phql_parser, PHQL_DELETE, NULL, parser_status);
				break;
			case PHQL_T_INSERT:
				phql_(phql_parser, PHQL_INSERT, NULL, parser_status);
				break;
			case PHQL_T_INTO:
				phql_(phql_parser, PHQL_INTO, NULL, parser_status);
				break;
			case PHQL_T_VALUES:
				phql_(phql_parser, PHQL_VALUES, NULL, parser_status);
				break;
			case PHQL_T_SELECT:
				phql_(phql_parser, PHQL_SELECT, NULL, parser_status);
				break;
			case PHQL_T_AS:
				phql_(phql_parser, PHQL_AS, NULL, parser_status);
				break;
			case PHQL_T_ORDER:
				phql_(phql_parser, PHQL_ORDER, NULL, parser_status);
				break;
			case PHQL_T_BY:
				phql_(phql_parser, PHQL_BY, NULL, parser_status);
				break;
			case PHQL_T_LIMIT:
				phql_(phql_parser, PHQL_LIMIT, NULL, parser_status);
				break;
			case PHQL_T_OFFSET:
				phql_(phql_parser, PHQL_OFFSET, NULL, parser_status);
				break;
			case PHQL_T_GROUP:
				phql_(phql_parser, PHQL_GROUP, NULL, parser_status);
				break;
			case PHQL_T_HAVING:
				phql_(phql_parser, PHQL_HAVING, NULL, parser_status);
				break;
			case PHQL_T_ASC:
				phql_(phql_parser, PHQL_ASC, NULL, parser_status);
				break;
			case PHQL_T_DESC:
				phql_(phql_parser, PHQL_DESC, NULL, parser_status);
				break;
			case PHQL_T_IN:
				phql_(phql_parser, PHQL_IN, NULL, parser_status);
				break;
			case PHQL_T_ON:
				phql_(phql_parser, PHQL_ON, NULL, parser_status);
				break;
			case PHQL_T_INNER:
				phql_(phql_parser, PHQL_INNER, NULL, parser_status);
				break;
			case PHQL_T_JOIN:
				phql_(phql_parser, PHQL_JOIN, NULL, parser_status);
				break;
			case PHQL_T_LEFT:
				phql_(phql_parser, PHQL_LEFT, NULL, parser_status);
				break;
			case PHQL_T_RIGHT:
				phql_(phql_parser, PHQL_RIGHT, NULL, parser_status);
				break;
			case PHQL_T_CROSS:
				phql_(phql_parser, PHQL_CROSS, NULL, parser_status);
				break;
			case PHQL_T_FULL:
				phql_(phql_parser, PHQL_FULL, NULL, parser_status);
				break;
			case PHQL_T_OUTER:
				phql_(phql_parser, PHQL_OUTER, NULL, parser_status);
				break;
			case PHQL_T_IS:
				phql_(phql_parser, PHQL_IS, NULL, parser_status);
				break;
			case PHQL_T_NULL:
				phql_(phql_parser, PHQL_NULL, NULL, parser_status);
				break;
			case PHQL_T_BETWEEN:
				phql_(phql_parser, PHQL_BETWEEN, NULL, parser_status);
				break;
			case PHQL_T_DISTINCT:
				phql_(phql_parser, PHQL_DISTINCT, NULL, parser_status);
				break;
			case PHQL_T_ALL:
				phql_(phql_parser, PHQL_ALL, NULL, parser_status);
				break;
			case PHQL_T_CAST:
				phql_(phql_parser, PHQL_CAST, NULL, parser_status);
				break;
			case PHQL_T_CONVERT:
				phql_(phql_parser, PHQL_CONVERT, NULL, parser_status);
				break;
			case PHQL_T_USING:
				phql_(phql_parser, PHQL_USING, NULL, parser_status);
				break;
			case PHQL_T_EXISTS:
				phql_(phql_parser, PHQL_EXISTS, NULL, parser_status);
				break;

			default:
				parser_status->status = PHQL_PARSING_FAILED;
				error_length = sizeof(char) * 32;
				error = emalloc(error_length);
				snprintf(error, error_length, "Scanner: Unknown opcode %d", token.opcode);
				error[error_length - 1] = '\0';
                ZVAL_STRING(*error_msg, error);
				efree(error);
				break;
		}

		if (parser_status->status != PHQL_PARSING_OK) {
			status = FAILURE;
			break;
		}

		state->end = state->start;
	}

	if (status != FAILURE) {
		switch (scanner_status) {

			case PHQL_SCANNER_RETCODE_ERR:
			case PHQL_SCANNER_RETCODE_IMPOSSIBLE:
                if (Z_TYPE_P(*error_msg) == IS_UNDEF) {
                    phql_scanner_error_msg(parser_status, error_msg TSRMLS_CC);
                }

				status = FAILURE;
				break;

			default:
				phql_(phql_parser, 0, NULL, parser_status);
		}
	}

	state->active_token = 0;
	state->start = NULL;

	if (parser_status->status != PHQL_PARSING_OK) {
		status = FAILURE;
		if (parser_status->syntax_error) {
            if (Z_TYPE_P(*error_msg) == IS_UNDEF) {
                ZVAL_STRING(*error_msg, parser_status->syntax_error);
            }

			efree(parser_status->syntax_error);
		}
	}

	phql_Free(phql_parser, phql_wrapper_free);

	if (status != FAILURE) {
		if (parser_status->status == PHQL_PARSING_OK) {
			if (Z_TYPE_P(&parser_status->ret) == IS_ARRAY) {

				/**
				 * Set a unique id for the parsed ast
				 */
				if (phalcon_globals_ptr->orm.cache_level >= 1) {
                    if (Z_TYPE_P(&parser_status->ret) == IS_ARRAY) {
                        add_assoc_long(&parser_status->ret, "id", phalcon_globals_ptr->orm.unique_cache_id++);
                    }
				}

                ZVAL_ZVAL(*result, &parser_status->ret, 1, 1);

				/**
				 * Store the parsed definition in the cache
				 */
				if (cache_level >= 0) {

                    if (!phalcon_globals_ptr->orm.parser_cache) {
                        ALLOC_HASHTABLE(phalcon_globals_ptr->orm.parser_cache);
                        zend_hash_init(phalcon_globals_ptr->orm.parser_cache, 0, NULL, ZVAL_PTR_DTOR, 0);
                    }

                    Z_TRY_ADDREF_P(*result);

                    zend_hash_index_update(
                        phalcon_globals_ptr->orm.parser_cache,
                        phql_key,
                        *result
                    );
				}

			}
		}
	}

	efree(parser_status);
	efree(state);

	return status;
}
