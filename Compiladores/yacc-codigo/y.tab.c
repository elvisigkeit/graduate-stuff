/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "gera_cod.y" /* yacc.c:337  */

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>

using namespace std;

#define YYSTYPE Atributos

int linha = 1;
int coluna = 1;

typedef string Tipo;

struct Atributos {
  string v;
  string c;
  unsigned d1, d2, d3;
  Tipo t;
  int linha;
};

struct DimV {
  string nome;
  unsigned nDim;
  Tipo tipo;
  unsigned d1, d2, d3;
};

map<string,Tipo> tsVar = {
{"int","int"}, {"char","char"}, {"string","string"},
{"boolean","int"}, {"real", "double"},
{"I","int "}, {"C","char "}, 
{"D", "double "}, {"S", "string "}
};
map<string,Tipo> untsVar = {
{"int","I"}, {"char","C"}, {"string","S"},
{"boolean","C"}, {"real", "D"},
};
map<string,Tipo> tsLeitura = {
{"I","int"}, {"C","char"}, 
{"D", "real"}, {"S", "string"}
};
map<string,Tipo> resOpr = {
{ "+II", "I" }, { "+ID", "D" }, { "+DI", "D" }, { "+DD", "D" },
{ "+CC", "C" }, { "+CS", "S" }, { "+SC", "S" }, { "+SS", "S" },
{ "+CI", "I" }, { "+IC", "I" }, 

{ "-II", "I" }, { "-ID", "D" }, { "-DI", "D" }, { "-DD", "D" },
{ "-CC", "C" }, { "-CI", "I" }, { "-IC", "I" }, 

{ "/II", "I" }, { "/ID", "D" }, { "/DI", "D" }, { "/DD", "D" },
{ "/CC", "C" }, { "/CI", "I" }, { "/IC", "I" }, 

{ "*II", "I" }, { "*ID", "D" }, { "*DI", "D" }, { "*DD", "D" },
{ "*CC", "C" }, { "*CI", "I" }, { "*IC", "I" }, 

{ "%II", "I" }, { "%ID", "D" }, { "%DI", "D" }, { "%DD", "D" },
{ "%CC", "C" }, { "%CI", "I" }, { "%IC", "I" },

{ ">II", "I" }, { ">ID", "I" }, { ">DI", "I" }, { ">DD", "I" },
{ ">CC", "I" }, { ">CI", "I" }, { ">IC", "I" }, { ">SS", "I" }, 
{ ">SC", "I" }, { ">CS", "I" },

{ ">=II", "I" }, { ">=ID", "I" }, { ">=DI", "I" }, { ">=DD", "I" },
{ ">=CC", "I" }, { ">=CI", "I" }, { ">=IC", "I" }, { ">=SS", "I" },
{ ">=SC", "I" }, { ">=CS", "I" },

{ "<II", "I" }, { "<ID", "I" }, { "<DI", "I" }, { "<DD", "I" },
{ "<CC", "I" }, { "<CI", "I" }, { "<IC", "I" }, { "<SS", "I" },
{ "<SC", "I" }, { "<CS", "I" },

{ "<=II", "I" }, { "<=ID", "I" }, { "<=DI", "I" }, { "<=DD", "I" },
{ "<=CC", "I" }, { "<=CI", "I" }, { "<=IC", "I" }, { "<=SS", "I" },
{ "<=SC", "I" }, { "<=CS", "I" },

{ "==II", "I" }, { "==ID", "I" }, { "==DI", "I" }, { "==DD", "I" },
{ "==CC", "I" }, { "==CI", "I" }, { "==IC", "I" }, { "==SS", "I" },
{ "==SC", "I" }, { "==CS", "I" },

{ "!=II", "I" }, { "!=ID", "I" }, { "!=DI", "I" }, { "!=DD", "I" },
{ "!=CC", "I" }, { "!=CI", "I" }, { "!=IC", "I" }, { "!=SS", "I" },
{ "!=SC", "I" }, { "!=CS", "I" }
};


int yylex();
int yyparse();
string declTemps();
void yyerror(const char *);

Atributos geraAtribuicao(Atributos id, Atributos var);
string geraNomeVar(Tipo t);
string geraLFim();
string geraLInicio();
string geraLMeio();
string declaraVariavel(string tipo, string vars);
Atributos geraCodigoOperador( Atributos a, string operador, Atributos b );
Atributos geraCodigoComparacao( Atributos a, string operador, Atributos b );
string pegaTipo(string nome);
string pegaTipoVetor(string nome);
string registraDimensoes(string nome, unsigned nDim, unsigned d1, unsigned d2, unsigned d3);
string gera_indice_vetor(Atributos recebido, Tipo tipo_direita, unsigned nrDim, unsigned d1, unsigned d2, unsigned d3);

map<Tipo,int> nVar;
map<string,Tipo> tabelaVars;
map<string,DimV> tabelaVetores;
string ultimoCondIf;
int lMeio = 0;
int lInicio = 0;
int lFim = 0;


#line 186 "y.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CINT = 258,
    CDOUBLE = 259,
    TK_ID = 260,
    TK_VAR = 261,
    TK_CONSOLE = 262,
    TK_SHIFTR = 263,
    TK_SHIFTL = 264,
    TK_TRUE = 265,
    TK_FALSE = 266,
    TK_FOR = 267,
    TK_IN = 268,
    TK_2PT = 269,
    TK_IF = 270,
    TK_THEN = 271,
    TK_ELSE = 272,
    TK_STR = 273,
    TK_ENDL = 274,
    CCHAR = 275,
    TK_CMP = 276,
    TK_CMP_OR = 277,
    TK_CMP_AND = 278,
    TK_UN_NOT = 279,
    TK_END = 280,
    TK_BEGIN = 281,
    TK_OPER = 282
  };
#endif
/* Tokens.  */
#define CINT 258
#define CDOUBLE 259
#define TK_ID 260
#define TK_VAR 261
#define TK_CONSOLE 262
#define TK_SHIFTR 263
#define TK_SHIFTL 264
#define TK_TRUE 265
#define TK_FALSE 266
#define TK_FOR 267
#define TK_IN 268
#define TK_2PT 269
#define TK_IF 270
#define TK_THEN 271
#define TK_ELSE 272
#define TK_STR 273
#define TK_ENDL 274
#define CCHAR 275
#define TK_CMP 276
#define TK_CMP_OR 277
#define TK_CMP_AND 278
#define TK_UN_NOT 279
#define TK_END 280
#define TK_BEGIN 281
#define TK_OPER 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

#define YYUNDEFTOK  2
#define YYMAXUTOK   282

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
      38,    39,    30,    28,    34,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   137,   138,   141,   142,   143,   144,   145,
     146,   149,   153,   154,   157,   160,   163,   166,   170,   174,
     176,   181,   188,   195,   197,   203,   211,   221,   225,   227,
     229,   231,   233,   235,   239,   253,   269,   277,   283,   284,
     294,   303,   305,   309,   311,   316,   322,   330,   332,   334,
     336,   338,   340,   345,   347,   352,   357,   360,   366,   373,
     380,   381,   382,   383,   388,   389,   390,   391
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CINT", "CDOUBLE", "TK_ID", "TK_VAR",
  "TK_CONSOLE", "TK_SHIFTR", "TK_SHIFTL", "TK_TRUE", "TK_FALSE", "TK_FOR",
  "TK_IN", "TK_2PT", "TK_IF", "TK_THEN", "TK_ELSE", "TK_STR", "TK_ENDL",
  "CCHAR", "TK_CMP", "TK_CMP_OR", "TK_CMP_AND", "TK_UN_NOT", "TK_END",
  "TK_BEGIN", "TK_OPER", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "','",
  "'['", "']'", "'='", "'('", "')'", "$accept", "S", "CMDS", "CMD",
  "DECLVAR", "VARS", "VAR", "ENTRADA", "ENTRADA_EXT", "SAIDA", "SAIDA_EXT",
  "FOR", "IF", "BLK", "ATR", "E", "V", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    43,    45,
      42,    47,    37,    59,    44,    91,    93,    61,    40,    41
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     302,    -9,    14,     4,    33,    59,   109,    20,   302,     6,
     -48,   -48,   -48,   -48,   -48,   -48,    59,    59,    22,    24,
     -48,    55,    11,   -48,   -48,    58,   -48,   -48,    37,   -48,
     -48,   -48,   -48,    59,    59,   154,   -48,   113,   -48,   -48,
     -48,    42,   -48,   166,   299,    75,    14,    -3,     0,    72,
      71,    47,    59,   304,   125,   109,    59,    59,    59,    59,
      59,    59,    59,    59,   -48,   127,   -48,    15,    48,   -48,
      59,   -48,   -48,   -48,   -48,    59,   178,   -48,   -48,    -6,
     309,   304,   304,    -7,    -7,   -48,   -48,   -48,   -48,    59,
      59,    52,   190,   137,    53,    63,    97,   202,   299,   101,
      -1,    59,    59,   -48,   -48,    18,    69,    59,   -48,   214,
     226,    59,    59,    73,   238,   109,    74,   250,   299,   103,
       2,   -48,   -48,    59,    80,    76,    59,   -48,   262,    59,
     -48,   274,   -48,   299,   114,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       5,     6,     7,     9,    10,     8,     0,     0,    17,    11,
      13,     0,     0,    18,    27,     0,    61,    62,    60,    65,
      66,    64,    63,     0,     0,     0,    56,     0,    37,    36,
       1,     0,     4,     0,    43,     0,     0,    19,    64,    30,
      29,     0,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     3,     0,     0,    12,
       0,    23,    31,    33,    32,     0,     0,    67,    39,     0,
      53,    55,    54,    47,    48,    49,    50,    51,    41,     0,
       0,    14,     0,     0,    57,     0,     0,     0,    44,     0,
      20,     0,     0,    40,    38,     0,     0,     0,    24,     0,
       0,     0,     0,    15,     0,     0,    58,     0,    45,     0,
      21,    35,    34,     0,     0,     0,     0,    25,     0,     0,
      16,     0,    59,    46,    22,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,    86,    -4,   -48,   -48,    81,   -48,   -44,   -48,
      17,   -48,   -48,   -47,   -48,   -16,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    19,    20,    11,    23,    12,
      24,    13,    14,    39,    15,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    44,    38,    71,    41,    21,    50,    21,    79,    22,
      21,    95,    21,    22,    26,    27,    28,    53,    54,    18,
      40,    29,    30,    61,    62,    63,    16,    96,    17,    48,
      49,    32,    70,   -28,   107,    33,    76,   126,    25,    42,
      80,    81,    82,    83,    84,    85,    86,    87,   103,    34,
      89,    78,    90,   111,    92,   112,   108,    45,    46,    93,
      47,    41,    26,    27,    28,    72,    73,    74,   122,    29,
      30,    51,    52,    97,    98,    66,   127,    31,    68,    32,
      22,    22,    75,    33,    91,   109,   110,    99,   102,    37,
     135,   114,    56,    57,    58,   117,   118,    34,   104,    59,
      60,    61,    62,    63,   106,   113,   125,   128,   119,   123,
     131,   121,   130,   133,     1,     2,     3,   129,     1,     2,
       3,     4,    21,    65,     5,     4,     6,    69,     5,     0,
       6,     0,     1,     2,     3,    37,     0,     0,    64,     4,
       0,     0,     5,     0,     6,     0,    56,    57,    58,     0,
       0,   101,    88,    59,    60,    61,    62,    63,    56,    57,
      58,     0,     0,     0,    77,    59,    60,    61,    62,    63,
      55,     0,     0,     0,     0,    56,    57,    58,     0,     0,
       0,     0,    59,    60,    61,    62,    63,    56,    57,    58,
       0,     0,     0,     0,    59,    60,    61,    62,    63,    56,
      57,    58,    67,     0,     0,     0,    59,    60,    61,    62,
      63,    56,    57,    58,    94,     0,     0,     0,    59,    60,
      61,    62,    63,    56,    57,    58,   100,     0,     0,     0,
      59,    60,    61,    62,    63,    56,    57,    58,   105,     0,
       0,     0,    59,    60,    61,    62,    63,    56,    57,    58,
     115,     0,     0,     0,    59,    60,    61,    62,    63,    56,
      57,    58,   116,     0,     0,     0,    59,    60,    61,    62,
      63,    56,    57,    58,   120,     0,     0,     0,    59,    60,
      61,    62,    63,    56,    57,    58,   124,     0,     0,     0,
      59,    60,    61,    62,    63,    56,    57,    58,   132,     0,
       0,     0,    59,    60,    61,    62,    63,     1,     2,     3,
     134,     0,     0,     0,     4,     0,     0,     5,     0,     6,
      56,    57,    58,     0,     0,    56,     0,    59,    60,    61,
      62,    63,    59,    60,    61,    62,    63,    59,    60,    61,
      62,    63
};

static const yytype_int16 yycheck[] =
{
      16,    17,     6,    47,     8,     8,    22,     8,    55,     9,
       8,    17,     8,     9,     3,     4,     5,    33,    34,     5,
       0,    10,    11,    30,    31,    32,    35,    33,    37,    18,
      19,    20,    35,    33,    35,    24,    52,    35,     5,    33,
      56,    57,    58,    59,    60,    61,    62,    63,    95,    38,
      35,    55,    37,    35,    70,    37,   100,    35,    34,    75,
       5,    65,     3,     4,     5,    48,    49,    50,   115,    10,
      11,    13,    35,    89,    90,    33,   120,    18,     3,    20,
       9,     9,    35,    24,    36,   101,   102,    35,    35,    26,
     134,   107,    21,    22,    23,   111,   112,    38,     1,    28,
      29,    30,    31,    32,     3,    36,     3,   123,    35,    35,
     126,   115,    36,   129,     5,     6,     7,    37,     5,     6,
       7,    12,     8,    37,    15,    12,    17,    46,    15,    -1,
      17,    -1,     5,     6,     7,    26,    -1,    -1,    25,    12,
      -1,    -1,    15,    -1,    17,    -1,    21,    22,    23,    -1,
      -1,    14,    25,    28,    29,    30,    31,    32,    21,    22,
      23,    -1,    -1,    -1,    39,    28,    29,    30,    31,    32,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    21,    22,    23,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    21,
      22,    23,    36,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    21,    22,    23,    36,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    21,    22,    23,    36,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    21,    22,    23,    36,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    21,    22,    23,
      36,    -1,    -1,    -1,    28,    29,    30,    31,    32,    21,
      22,    23,    36,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    21,    22,    23,    36,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    21,    22,    23,    36,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    21,    22,    23,    36,    -1,
      -1,    -1,    28,    29,    30,    31,    32,     5,     6,     7,
      36,    -1,    -1,    -1,    12,    -1,    -1,    15,    -1,    17,
      21,    22,    23,    -1,    -1,    21,    -1,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    28,    29,    30,
      31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,    12,    15,    17,    41,    42,    43,
      44,    47,    49,    51,    52,    54,    35,    37,     5,    45,
      46,     8,     9,    48,    50,     5,     3,     4,     5,    10,
      11,    18,    20,    24,    38,    55,    56,    26,    43,    53,
       0,    43,    33,    55,    55,    35,    34,     5,    18,    19,
      55,    13,    35,    55,    55,    16,    21,    22,    23,    28,
      29,    30,    31,    32,    25,    42,    33,    36,     3,    46,
      35,    48,    50,    50,    50,    35,    55,    39,    43,    53,
      55,    55,    55,    55,    55,    55,    55,    55,    25,    35,
      37,    36,    55,    55,    36,    17,    33,    55,    55,    35,
      36,    14,    35,    53,     1,    36,     3,    35,    48,    55,
      55,    35,    37,    36,    55,    36,    36,    55,    55,    35,
      36,    43,    53,    35,    36,     3,    35,    48,    55,    37,
      36,    55,    36,    55,    36,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    44,    45,    45,    46,    46,    46,    46,    47,    48,
      48,    48,    48,    48,    48,    48,    48,    49,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    54,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     4,     7,    10,     1,     2,     2,
       5,     8,    11,     3,     6,     9,    12,     2,     2,     2,
       2,     3,     3,     3,     9,     9,     2,     2,     6,     4,
       6,     3,     2,     3,     6,     9,    12,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     1,     4,     7,    10,
       1,     1,     1,     1,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 130 "gera_cod.y" /* yacc.c:1652  */
    { cout << "#include <string>\n#include <cstring>\n#include <iostream>\n\nusing namespace std;\n\nint main() {\n"
           << declTemps()
           << yyvsp[0].c
           << "fflush(stdout);\nreturn 0;\n}" << endl; 
    }
#line 1497 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 137 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[-2].c + yyvsp[-1].c; }
#line 1503 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 150 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = declaraVariavel(yyvsp[-1].v, yyvsp[0].c); }
#line 1509 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 153 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[-2].c + "," + yyvsp[0].c; }
#line 1515 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 158 "gera_cod.y" /* yacc.c:1652  */
    { registraDimensoes(yyvsp[-3].v, 1, stoul(yyvsp[-1].v), 0, 0); 
       yyval.c = yyvsp[-3].v + "[" + yyvsp[-1].v + "]";  }
#line 1522 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 161 "gera_cod.y" /* yacc.c:1652  */
    { string largura = registraDimensoes(yyvsp[-6].v, 2, stoul(yyvsp[-4].v), stoul(yyvsp[-1].v), 0); 
       yyval.c = yyvsp[-6].v + "[" + largura + "]";  }
#line 1529 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 164 "gera_cod.y" /* yacc.c:1652  */
    { string largura = registraDimensoes(yyvsp[-9].v, 3, stoul(yyvsp[-7].v), stoul(yyvsp[-4].v), stoul(yyvsp[-1].v)); 
       yyval.c = yyvsp[-9].v + "[" + largura + "]"; }
#line 1536 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 167 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[0].v; }
#line 1542 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 171 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[0].c; }
#line 1548 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 175 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = "cin >> " + yyvsp[0].v + ";\n"; }
#line 1554 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 177 "gera_cod.y" /* yacc.c:1652  */
    { yyval.v = geraNomeVar(pegaTipoVetor(yyvsp[-3].v));
               yyval.c = yyvsp[-1].c 
                    + "cin >> " + yyval.v + ";\n"
                    + yyvsp[-3].v + "[" + yyvsp[-1].v + "] = " + yyval.v + ";\n"; }
#line 1563 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 182 "gera_cod.y" /* yacc.c:1652  */
    { yyval.v = geraNomeVar(pegaTipoVetor(yyvsp[-6].v));
               string indice = gera_indice_vetor(yyvsp[-6], yyvsp[-6].t, 2, stoul(yyvsp[-4].v), stoul(yyvsp[-1].v), 0);
               yyval.c = yyvsp[-4].c + yyvsp[-1].c 
                     + "cin >> " + yyval.v + ";\n"
                     + yyvsp[-6].v + "[" + indice + "] = " + yyval.v + ";\n";
             }
#line 1574 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 189 "gera_cod.y" /* yacc.c:1652  */
    { yyval.v = geraNomeVar(pegaTipoVetor(yyvsp[-9].v));
               string indice = gera_indice_vetor(yyvsp[-9], yyvsp[-9].t, 3, stoul(yyvsp[-7].v), stoul(yyvsp[-4].v), stoul(yyvsp[-1].v));
               yyval.c = yyvsp[-7].c + yyvsp[-4].c + yyvsp[-1].c
                     + "cin >> " + yyval.v + ";\n"
                     + yyvsp[-9].v + "[" + indice + "] = " + yyval.v + ";\n";
            }
#line 1585 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 196 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = "cin >> " + yyvsp[-1].v + ";\n" + yyvsp[0].c; }
#line 1591 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 198 "gera_cod.y" /* yacc.c:1652  */
    { yyval.v = geraNomeVar(pegaTipoVetor(yyvsp[-4].v));
               yyval.c = yyvsp[-2].c 
                    + "cin >> " + yyval.v + ";\n"
                    + yyvsp[-4].v + "[" + yyvsp[-2].v + "] = " + yyval.v + ";\n"
                    + yyvsp[0].c; }
#line 1601 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 204 "gera_cod.y" /* yacc.c:1652  */
    { yyval.v = geraNomeVar(pegaTipoVetor(yyvsp[-7].v));
               string indice = gera_indice_vetor(yyvsp[-7], yyvsp[-7].t, 2, stoul(yyvsp[-5].v), stoul(yyvsp[-2].v), 0);
               yyval.c = yyvsp[-5].c + yyvsp[-2].c 
                     + "cin >> " + yyval.v + ";\n"
                     + yyvsp[-7].v + "[" + indice + "] = " + yyval.v + ";\n"
                     + yyvsp[0].c;
             }
#line 1613 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 212 "gera_cod.y" /* yacc.c:1652  */
    { yyval.v = geraNomeVar(pegaTipoVetor(yyvsp[-10].v));
               string indice = gera_indice_vetor(yyvsp[-10], yyvsp[-10].t, 3, stoul(yyvsp[-8].v), stoul(yyvsp[-5].v), stoul(yyvsp[-2].v));
               yyval.c = yyvsp[-8].c + yyvsp[-5].c + yyvsp[-2].c
                     + "cin >> " + yyval.v + ";\n"
                     + yyvsp[-10].v + "[" + indice + "] = " + yyval.v + ";\n"
                     + yyvsp[0].c;
            }
#line 1625 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 222 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[0].c; }
#line 1631 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 226 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = "cout << " + yyvsp[0].v + ";\n"; }
#line 1637 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 228 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[0].c + "cout << " + yyvsp[0].v + ";\n"; }
#line 1643 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 230 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = "cout << " + yyvsp[0].v + ";\n"; }
#line 1649 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 232 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = "cout << " + yyvsp[-1].v + ";\n" + yyvsp[0].c; }
#line 1655 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 234 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[-1].c + "cout << " + yyvsp[-1].v + ";\n" + yyvsp[0].c; }
#line 1661 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 236 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = "cout << " + yyvsp[-1].v + ";\n" + yyvsp[0].c; }
#line 1667 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 240 "gera_cod.y" /* yacc.c:1652  */
    {  string cond = geraNomeVar("I");
        string inicio = geraLInicio();
        string fim = geraLFim();
        
        yyval.c = yyvsp[-4].c + yyvsp[-2].c 
            + yyvsp[-7].v + " = " + yyvsp[-4].v + ";\n"
            + inicio + ":\n" + cond + " = " + yyvsp[-7].v + " > " + yyvsp[-2].v + ";\n"
            + "if( " + cond + " ) goto " + fim + ";\n"
            + yyvsp[0].c
            + yyvsp[-7].v + " = " + yyvsp[-7].v + " + 1;\n"
            + "goto " + inicio + ";\n"
            + fim + ":\n";
    }
#line 1685 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 254 "gera_cod.y" /* yacc.c:1652  */
    {  string cond = geraNomeVar("I");
        string inicio = geraLInicio();
        string fim = geraLFim();
        
        yyval.c = yyvsp[-4].c + yyvsp[-2].c 
            + yyvsp[-7].v + " = " + yyvsp[-4].v + ";\n"
            + inicio + ":\n" + cond + " = " + yyvsp[-7].v + " > " + yyvsp[-2].v + ";\n"
            + "if( " + cond + " ) goto " + fim + ";\n"
            + yyvsp[0].c
            + yyvsp[-7].v + " = " + yyvsp[-7].v + " + 1;\n"
            + "goto " + inicio + ";\n"
            + fim + ":\n";
    }
#line 1703 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 270 "gera_cod.y" /* yacc.c:1652  */
    { 
      string cond = geraNomeVar("I"); string meio = geraLMeio(); string fim = geraLFim();
      yyval.c = cond + " = !" + ultimoCondIf + ";\n"
           + "if( " + cond + " ) \n\tgoto " + meio + ";\n"
           + "\tgoto " + fim + ";\n" + meio + ":\n"
           + yyvsp[0].c + "\n" + fim + ":\n";
    }
#line 1715 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 278 "gera_cod.y" /* yacc.c:1652  */
    { string cond = geraNomeVar("I"); string meio = geraLMeio(); string fim = geraLFim();
      ultimoCondIf = cond;
      yyval.c = "if( " + cond + " ) \n\tgoto " + meio + ";\n"
           + "\tgoto " + fim + ";\n" + meio + ":\n"
           + yyvsp[0].c + "\n" + fim + ":\n";}
#line 1725 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 285 "gera_cod.y" /* yacc.c:1652  */
    { string cond = geraNomeVar("I"); ultimoCondIf = cond;
      string fim = geraLFim(); string inicio = geraLInicio();
      yyval.c = yyvsp[-2].c
           + cond + " = " + yyvsp[-2].v + ";\n"
           + "if( " + cond + " ) \n\tgoto " + inicio + ";\n"
           + "\tgoto " + fim + ";\n" + inicio + ":\n"
           + yyvsp[0].c + "\n" 
           + fim + ":\n"
           + ultimoCondIf + " = !" + cond + ";\n"; }
#line 1739 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 295 "gera_cod.y" /* yacc.c:1652  */
    { string cond = geraNomeVar("I"); string meio = geraLMeio(); string fim = geraLFim();
      yyval.c = yyvsp[-4].c
           + cond + " = " + yyvsp[-4].v + ";\n"
           + "if( " + cond + " ) \n\tgoto " + meio + ";\n"
           + yyvsp[0].c + "\n\tgoto " + fim + ";\n" + meio + ":\n"
           + yyvsp[-2].c + "\n" + fim + ":\n"; }
#line 1750 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 304 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[-1].c; }
#line 1756 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 306 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = " "; }
#line 1762 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 310 "gera_cod.y" /* yacc.c:1652  */
    { yyval = geraAtribuicao(yyvsp[-2], yyvsp[0]); }
#line 1768 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 312 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = yyvsp[-3].c + yyvsp[0].c 
            + yyvsp[-5].v + "[" + yyvsp[-3].v + "] = " + yyvsp[0].v + ";\n";
       yyval.v = yyvsp[0].v;
     }
#line 1777 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 317 "gera_cod.y" /* yacc.c:1652  */
    { string indice = gera_indice_vetor(yyvsp[-8], yyvsp[0].t, 2, stoul(yyvsp[-6].v), stoul(yyvsp[-3].v), 0);
       yyval.c = yyvsp[-6].c + yyvsp[-3].c + yyvsp[0].c
            + yyvsp[-8].v + "[" + indice + "] = " + yyvsp[-3].v + ";\n";
       yyval.v = yyvsp[-3].v;
     }
#line 1787 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 323 "gera_cod.y" /* yacc.c:1652  */
    { string indice = gera_indice_vetor(yyvsp[-11], yyvsp[0].t, 3, stoul(yyvsp[-9].v), stoul(yyvsp[-6].v), stoul(yyvsp[-3].v));
       yyval.c = yyvsp[-9].c + yyvsp[-6].c + yyvsp[-3].c + yyvsp[0].c
            + yyvsp[-11].v + "[" + indice + "] = " + yyvsp[-6].v + ";\n";
       yyval.v = yyvsp[-6].v;
     }
#line 1797 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 331 "gera_cod.y" /* yacc.c:1652  */
    { yyval = geraCodigoOperador( yyvsp[-2], yyvsp[-1].v, yyvsp[0] ); }
#line 1803 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 333 "gera_cod.y" /* yacc.c:1652  */
    { yyval = geraCodigoOperador( yyvsp[-2], yyvsp[-1].v, yyvsp[0] ); }
#line 1809 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 335 "gera_cod.y" /* yacc.c:1652  */
    { yyval = geraCodigoOperador( yyvsp[-2], yyvsp[-1].v, yyvsp[0] ); }
#line 1815 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 337 "gera_cod.y" /* yacc.c:1652  */
    { yyval = geraCodigoOperador( yyvsp[-2], yyvsp[-1].v, yyvsp[0] ); }
#line 1821 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 339 "gera_cod.y" /* yacc.c:1652  */
    { yyval = geraCodigoOperador( yyvsp[-2], yyvsp[-1].v, yyvsp[0] ); }
#line 1827 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 341 "gera_cod.y" /* yacc.c:1652  */
    { 
     yyval.v = geraNomeVar("I");
     yyval.c = yyvsp[0].c + yyval.v + " = " + "!" + yyvsp[0].v + ";\n";
   }
#line 1836 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 346 "gera_cod.y" /* yacc.c:1652  */
    { yyval = geraCodigoComparacao( yyvsp[-2], yyvsp[-1].v, yyvsp[0] ); }
#line 1842 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 348 "gera_cod.y" /* yacc.c:1652  */
    { 
     yyval.v = geraNomeVar("I");
     yyval.c = yyvsp[-2].c + yyvsp[0].c + yyval.v + " = " + yyvsp[-2].v + " && " + yyvsp[0].v + ";\n"; 
   }
#line 1851 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 353 "gera_cod.y" /* yacc.c:1652  */
    { 
     yyval.v = geraNomeVar("I");
     yyval.c = yyvsp[-2].c + yyvsp[0].c + yyval.v + " = " + yyvsp[-2].v + " || " + yyvsp[0].v + ";\n";
   }
#line 1860 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 361 "gera_cod.y" /* yacc.c:1652  */
    { 
               yyval.v = geraNomeVar(yyvsp[-3].t);
               yyval.c = yyvsp[-1].c + yyval.v + " = " + yyvsp[-3].v + "[" + yyvsp[-1].v + "];\n";    
               yyval.t = pegaTipoVetor(yyvsp[-3].v);                
             }
#line 1870 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 367 "gera_cod.y" /* yacc.c:1652  */
    { yyval.v = geraNomeVar(yyvsp[-5].t);
               string indice = gera_indice_vetor(yyvsp[-6], yyvsp[-6].t, 2, stoul(yyvsp[-4].v), stoul(yyvsp[-1].v), 0);
               yyval.c = yyvsp[-4].c + yyval.v + yyvsp[-1].c 
                     + yyvsp[-6].v + "[" + indice + "] = " + yyval.v + ";\n";
               yyval.t = pegaTipoVetor(yyvsp[-6].v);
            }
#line 1881 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 374 "gera_cod.y" /* yacc.c:1652  */
    { yyval.v = geraNomeVar(yyvsp[-8].t);
               string indice = gera_indice_vetor(yyvsp[-9], yyvsp[-9].t, 3, stoul(yyvsp[-7].v), stoul(yyvsp[-4].v), stoul(yyvsp[-1].v));
               yyval.c = yyvsp[-7].c + yyval.v + yyvsp[-4].c + yyvsp[-1].c
                     + yyvsp[-9].v + "[" + indice + "] = " + yyval.v + ";\n";
               yyval.t = pegaTipoVetor(yyvsp[-9].v);
            }
#line 1892 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 380 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = ""; yyval.v = yyvsp[0].v; yyval.t = pegaTipo(yyvsp[0].v); }
#line 1898 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 381 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = ""; yyval.v = yyvsp[0].v; yyval.t = "I"; }
#line 1904 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 382 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = ""; yyval.v = yyvsp[0].v; yyval.t = "D"; }
#line 1910 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 383 "gera_cod.y" /* yacc.c:1652  */
    {
               yyval.v = geraNomeVar("C"); 
               yyval.c = yyval.v + " = " + yyvsp[0].v + ";\n";
               yyval.t = "C"; 
             }
#line 1920 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 388 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = ""; yyval.v = yyvsp[0].v; yyval.t = "S"; }
#line 1926 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 389 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = ""; yyval.v = "1"; yyval.t = "I"; }
#line 1932 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 390 "gera_cod.y" /* yacc.c:1652  */
    { yyval.c = ""; yyval.v = "0"; yyval.t = "I"; }
#line 1938 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 391 "gera_cod.y" /* yacc.c:1652  */
    { yyval = yyvsp[-1]; }
#line 1944 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1948 "y.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 394 "gera_cod.y" /* yacc.c:1918  */


#include "lex.yy.c"

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Linha %d, coluna %d, proximo a: %s\n", linha, coluna, yytext );
   exit( 0 );
}

string geraLInicio() {
  char buf[20] = "";
  
  sprintf( buf, "inicio%d", lInicio++ );
  
  return buf;
}

string geraLMeio() {
  char buf[20] = "";
  
  sprintf( buf, "meio%d", lMeio++ );
  
  return buf;
}

string geraLFim() {
  char buf[20] = "";
  
  sprintf( buf, "fim%d", lFim++ );
  
  return buf;
}

string toString( int n ) {
  char buf[20] = "";
  
  sprintf( buf, "%d", n );
  
  return buf;
}

string geraNomeVar( Tipo t ) {
  return "t_" + t + "_" + toString( nVar[t]++ );
}

Tipo buscaTipoOperacao( Tipo a, string operador, Tipo b ) {
  return resOpr[operador + a + b];
}

Atributos geraCodigoComparacao(Atributos a, string operador, Atributos b) {
  Atributos r;
  if(operador == "<>")
    operador = "!=";
  
  r.t = buscaTipoOperacao( a.t, operador, b.t );
  if( r.t == "" ) {
    string temp = "Operacao '" + operador + "' invalida entre " + tsLeitura[a.t] + " e " + tsLeitura[b.t]; 
    yyerror( temp.c_str() );
  }

  if (a.t == "S" || b.t == "S") {
    r.v = geraNomeVar("I"); string strCmp = geraNomeVar("I");
    r.c = a.c + b.c;
    if(a.t == "C") {
      string var = geraNomeVar("S");
      r.c += var + "[0] = " + a.v + ";\n" + var + "[1] = 0;\n";
      a.v = var;
    }
    if(b.t == "C") {
      string var = geraNomeVar("S");
      r.c += var + "[0] = " + b.v + ";\n" + var + "[1] = 0;\n";
      b.v = var;
    }
    r.c += strCmp + " = strncmp (" + a.v + ", " + b.v + ", 255);\n";
    r.c += r.v + " = " + strCmp + " " + operador + " 0;\n";
    return r;
  }
  r.v = geraNomeVar("I");
  r.c = a.c + b.c + r.v + " = " + a.v + operador + b.v + ";\n"; 
  return r;
}

Atributos geraCodigoOperador( Atributos a, string operador, Atributos b ) {
  Atributos r;
  
  r.t = buscaTipoOperacao( a.t, operador, b.t );
  if( r.t == "" ) {
    string temp = "Operacao '" + operador + "' invalida entre " + tsLeitura[a.t] + " e " + tsLeitura[b.t]; 
    yyerror( temp.c_str() );
  }

  if(r.t == "S" && operador == "+") {
    string lenTemp = geraNomeVar("I");
    r.v = geraNomeVar("S"); string varB = geraNomeVar("S");
    r.c = a.c + b.c;
    r.c += r.v + "[255] = 0;\n";
    r.c += varB + "[255] = 0;\n";
    if(a.t == "C")
      r.c += r.v + "[0] = " + a.v + ";\n" + r.v + "[1] = 0;\n";
    else
      r.c += "strncpy(" + r.v + ", " + a.v + ", 255);\n";
    if(b.t == "C")
      r.c += varB + "[0] = " + b.v + ";\n" + varB + "[1] = 0;\n";
    else
      r.c += "strncpy(" + varB + ", " + b.v + ", 255);\n";
    r.c += lenTemp + " = strlen(" + varB + ");\n";
    r.c += lenTemp + " = 255 - " + lenTemp + ";\n";
    r.c += "strncat(" + r.v + ", " + varB + ", " + lenTemp + ");\n";
    return r;
  }
  
  r.v = geraNomeVar( r.t );
  r.c = a.c + b.c + 
        "  " + r.v + " = " + a.v + operador + b.v + ";\n";
  return r;
}

string pegaTipo(string nome) {
  map<string,Tipo>::iterator it = tabelaVars.find(nome);
  if (it == tabelaVars.end()){
    string temp = "Variavel " + nome + " nao foi definida anteriormente."; 
    yyerror( temp.c_str() );
  }
  return it->second;
}

string pegaTipoVetor(string nome) {
  map<string,DimV>::iterator itv = tabelaVetores.find(nome);
  if (itv == tabelaVetores.end()){
    string temp = "Variavel " + nome + " nao foi definida anteriormente."; 
    yyerror( temp.c_str() );
  }

  DimV vet = itv->second;
  string vet_nome;
  
  if (vet.nDim == 1)
    vet_nome = vet.nome + "[" + to_string(vet.d1) + "]";
  if (vet.nDim == 2)
    vet_nome = vet.nome + "[" + to_string(vet.d1*vet.d2) + "]";
  else 
    vet_nome = vet.nome + "[" + to_string(vet.d1*vet.d2*vet.d3) + "]";

  map<string,Tipo>::iterator it = tabelaVars.find(vet_nome);
  if (it == tabelaVars.end()){
    string temp = "Variavel " + nome + " nao foi definida anteriormente."; 
    yyerror( temp.c_str() );
  }
  return it->second;
}

void registraVariavel(string nome, string tipo){
  tabelaVars[nome] = untsVar[tipo];
}

string registraDimensoes(string nome, unsigned nDim, unsigned d1, unsigned d2, unsigned d3){
  DimV novo; 
  novo.nome = nome;
  novo.nDim = nDim; novo.d1 = d1; novo.d2 = d2; novo.d3 = d3;
  tabelaVetores[nome] = novo;
  if (nDim == 1)
    return to_string(d1);
  if (nDim == 2)
    return to_string(d1*d2);
  return to_string(d1*d2*d3); 
}

Atributos geraAtribuicao(Atributos id, Atributos var) {
  Atributos saida;
  if (var.t == "S") {
    saida.v = var.v;
    saida.c += var.c + id.v + "[255] = 0;\n";
    saida.c += "strncpy(" + id.v + ", " + var.v + ", 255);\n";
    return saida;
  }
  saida.v = var.v;
  saida.c = var.c + id.v + " = " + var.v + ";\n";
  return saida;
}

string gera_indice_vetor(Atributos recebido, Tipo tipo_direita, unsigned nrDim, unsigned d1, unsigned d2, unsigned d3) {
  if(recebido.t != tipo_direita) {
    string temp = "Operacao '=' invalida entre ";
           temp += recebido.t + " e " + tipo_direita; 
    yyerror(temp.c_str());
  }

  map<string,DimV>::iterator it = tabelaVetores.find(recebido.v);
  if (it == tabelaVetores.end()){
    string temp = "Variavel " + recebido.v + " nao foi definida anteriormente."; 
    yyerror( temp.c_str() );
  }
  
  DimV dimensoes = it->second;
  if(dimensoes.nDim != nrDim) {
    string temp = "Número errado de parâmetros: ";
           temp += nrDim + ", deveria ser " + dimensoes.nDim; 
    yyerror(temp.c_str());
  }
  if(dimensoes.nDim == 3)
    return to_string(dimensoes.d1*d1+dimensoes.d2*d2+d3);
  if(dimensoes.nDim == 2)
    return to_string(dimensoes.d1*d1+d2);
  return to_string(d1);  
}

string declaraVariavel(string tipo, string vars) {
  size_t posf;
  string retorno;
  string restante = vars;
  do {
    posf = restante.find(",");

    string nome = restante.substr (0, posf);

    registraVariavel(nome, tipo);

    restante = restante.substr (posf+1);

    if (tipo == "string")
      retorno += "char " + nome + "[257];\n";
  } while (posf != string::npos);
  
  if (tipo == "string")
    return retorno;
  return tsVar[tipo] + " " + vars + ";\n";
}

string declTemps() {
  if (nVar.empty())
    return "";
  string vars;

  for(const auto& varAtual : nVar) {
    string temps;
    if(varAtual.first == "S") {
      for (int i=0; i<varAtual.second; i++) 
        temps += "char t_" + varAtual.first + "_" + to_string(i) + "[257];\n";
    } else {
      temps = tsVar[varAtual.first];
      for(int i=0; i<varAtual.second; i++) {
        temps = temps + "t_" + varAtual.first + "_" + to_string(i);
        if(i+1 != varAtual.second)
          temps+=", ";
      }
      temps += ";\n";
    }
    vars = vars + temps;
  }

  return vars;
}

int main( int argc, char* st[]) {
  yyparse();
  
  return 0;
}
