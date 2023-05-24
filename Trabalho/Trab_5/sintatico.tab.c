/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

    #include <string.h>
    #include <stdio.h>
	#include "symbolTable.h"
	#include "codeGeneration.h"

    void yyerror(char*);
    int yylex();

    extern SymTable table;

    char s_decs[256];


#line 86 "sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_NUM_INT = 5,                    /* NUM_INT  */
  YYSYMBOL_NUM_FLOAT = 6,                  /* NUM_FLOAT  */
  YYSYMBOL_LITERAL_STR = 7,                /* LITERAL_STR  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_STR = 10,                       /* STR  */
  YYSYMBOL_WRITE = 11,                     /* WRITE  */
  YYSYMBOL_READ = 12,                      /* READ  */
  YYSYMBOL_WRITELN = 13,                   /* WRITELN  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_22_ = 22,                       /* '+'  */
  YYSYMBOL_23_ = 23,                       /* '-'  */
  YYSYMBOL_24_ = 24,                       /* '*'  */
  YYSYMBOL_25_ = 25,                       /* '/'  */
  YYSYMBOL_26_ = 26,                       /* '='  */
  YYSYMBOL_27_ = 27,                       /* ';'  */
  YYSYMBOL_28_ = 28,                       /* '{'  */
  YYSYMBOL_29_ = 29,                       /* '}'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_programa = 36,                  /* programa  */
  YYSYMBOL_declaracoes = 37,               /* declaracoes  */
  YYSYMBOL_declaracao = 38,                /* declaracao  */
  YYSYMBOL_declaracao_inteiro = 39,        /* declaracao_inteiro  */
  YYSYMBOL_declaracao_float = 40,          /* declaracao_float  */
  YYSYMBOL_declaracao_string = 41,         /* declaracao_string  */
  YYSYMBOL_bloco = 42,                     /* bloco  */
  YYSYMBOL_comandos = 43,                  /* comandos  */
  YYSYMBOL_comando = 44,                   /* comando  */
  YYSYMBOL_comando_leitura = 45,           /* comando_leitura  */
  YYSYMBOL_comando_escrita = 46,           /* comando_escrita  */
  YYSYMBOL_comando_atribuicao = 47,        /* comando_atribuicao  */
  YYSYMBOL_expressao_numerica = 48,        /* expressao_numerica  */
  YYSYMBOL_termo = 49,                     /* termo  */
  YYSYMBOL_fator = 50,                     /* fator  */
  YYSYMBOL_comando_se = 51,                /* comando_se  */
  YYSYMBOL_comando_se_senao = 52,          /* comando_se_senao  */
  YYSYMBOL_comando_enquanto = 53,          /* comando_enquanto  */
  YYSYMBOL_expressao_booleana = 54,        /* expressao_booleana  */
  YYSYMBOL_operador_relacional = 55        /* operador_relacional  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   90

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
      30,    31,    24,    22,     2,    23,     2,    25,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
      33,    26,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    53,    60,    64,    65,    66,    70,    76,
      84,    89,    96,   102,   109,   116,   121,   125,   126,   127,
     128,   129,   130,   134,   142,   148,   156,   164,   169,   174,
     179,   184,   189,   197,   202,   210,   215,   220,   229,   234,
     239,   244,   253,   260,   267,   274,   282,   283,   284,   285,
     286,   287
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "ID", "NUM_INT",
  "NUM_FLOAT", "LITERAL_STR", "INT", "FLOAT", "STR", "WRITE", "READ",
  "WRITELN", "IF", "ELSE", "WHILE", "DO", "LE", "GE", "EQ", "NE", "'+'",
  "'-'", "'*'", "'/'", "'='", "';'", "'{'", "'}'", "'('", "')'", "'%'",
  "'<'", "'>'", "$accept", "programa", "declaracoes", "declaracao",
  "declaracao_inteiro", "declaracao_float", "declaracao_string", "bloco",
  "comandos", "comando", "comando_leitura", "comando_escrita",
  "comando_atribuicao", "expressao_numerica", "termo", "fator",
  "comando_se", "comando_se_senao", "comando_enquanto",
  "expressao_booleana", "operador_relacional", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,     7,    23,    51,    35,    28,     8,   -76,   -76,   -76,
       3,    19,    25,   -76,    20,   -76,   -76,    52,   -76,    53,
     -76,    54,   -76,    32,    30,    33,    34,    36,    37,    39,
      20,   -76,   -76,   -76,   -76,   -76,   -76,    38,    42,    43,
      44,    58,    67,    68,    69,    69,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,    -8,    15,    45,    46,    47,   -11,
      48,    49,    44,    44,   -76,    -4,    -4,    -4,    -4,    -4,
      55,    56,    57,   -76,   -76,   -76,   -76,   -76,   -76,    44,
      28,    28,   -76,   -76,   -76,   -76,   -76,    44,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,    31,    59,   -76,   -10,
      28,   -76,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       0,     0,     0,     1,    16,     2,     3,     0,     9,     0,
      11,     0,    13,     0,     0,     0,     0,     0,     0,     0,
      16,    18,    17,    19,    20,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     8,    10,
      12,    37,    35,    36,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,    46,    47,     0,
       0,     0,    28,    29,    40,    38,    39,     0,    30,    31,
      32,    33,    34,    24,    23,    25,    45,    42,    44,     0,
       0,    41,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,    75,   -76,   -76,   -76,   -76,   -75,    60,   -76,
     -76,   -76,   -76,   -59,   -76,   -25,   -76,   -76,   -76,    40,
     -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    15,    29,    30,
      31,    32,    33,    54,    55,    88,    34,    35,    36,    60,
      79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      84,    85,    86,    82,    83,    97,    98,    73,    74,    75,
      76,    10,    62,    63,    62,    63,     1,     2,     3,    64,
      96,   101,    77,    78,    23,   102,    87,    11,    99,    17,
      18,    24,    25,    26,    27,    13,    28,    65,    66,    67,
      68,    89,    90,    91,    92,    19,    20,    69,    51,    52,
      53,    21,    22,    62,    63,    12,    14,    37,    40,    38,
      41,    39,    56,    42,    43,    48,    44,    45,    46,    49,
      50,    57,    58,    59,   100,     0,    70,    71,    72,    80,
      81,    16,    93,    94,    95,    61,     0,     0,     0,     0,
      47
};

static const yytype_int8 yycheck[] =
{
       4,     5,     6,    62,    63,    80,    81,    18,    19,    20,
      21,     4,    22,    23,    22,    23,     8,     9,    10,    27,
      79,    31,    33,    34,     4,   100,    30,     4,    87,    26,
      27,    11,    12,    13,    14,     0,    16,    22,    23,    24,
      25,    66,    67,    68,    69,    26,    27,    32,     4,     5,
       6,    26,    27,    22,    23,     4,    28,     5,    26,     6,
      30,     7,     4,    30,    30,    27,    30,    30,    29,    27,
      27,     4,     4,     4,    15,    -1,    31,    31,    31,    31,
      31,     6,    27,    27,    27,    45,    -1,    -1,    -1,    -1,
      30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    36,    37,    38,    39,    40,    41,
       4,     4,     4,     0,    28,    42,    37,    26,    27,    26,
      27,    26,    27,     4,    11,    12,    13,    14,    16,    43,
      44,    45,    46,    47,    51,    52,    53,     5,     6,     7,
      26,    30,    30,    30,    30,    30,    29,    43,    27,    27,
      27,     4,     5,     6,    48,    49,     4,     4,     4,     4,
      54,    54,    22,    23,    27,    22,    23,    24,    25,    32,
      31,    31,    31,    18,    19,    20,    21,    33,    34,    55,
      31,    31,    48,    48,     4,     5,     6,    30,    50,    50,
      50,    50,    50,    27,    27,    27,    48,    42,    42,    48,
      15,    31,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    39,    39,
      40,    40,    41,    41,    42,    43,    43,    44,    44,    44,
      44,    44,    44,    45,    46,    46,    47,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    49,    50,    50,
      50,    50,    51,    52,    53,    54,    55,    55,    55,    55,
      55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     5,     3,
       5,     3,     5,     3,     3,     2,     0,     1,     1,     1,
       1,     1,     1,     5,     5,     5,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     5,     7,     5,     3,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* programa: declaracoes bloco  */
#line 44 "sintatico.y"
                             {
		
		fprintf(out_file, "%s", (yyvsp[-1].c).str);
		dumpCodeDeclarationEnd();
		fprintf(out_file, "%s", (yyvsp[0].c).str);
	}
#line 1196 "sintatico.tab.c"
    break;

  case 3: /* declaracoes: declaracao declaracoes  */
#line 53 "sintatico.y"
                                     {

		strcpy((yyval.c).str, (yyvsp[-1].c).str);
		//printf("{%s}\n", $2.str);
		sprintf((yyval.c).str + strlen((yyval.c).str), "%s", (yyvsp[0].c).str);
	}
#line 1207 "sintatico.tab.c"
    break;

  case 4: /* declaracoes: %empty  */
#line 60 "sintatico.y"
                 { (yyval.c).str[0] = '\0'; }
#line 1213 "sintatico.tab.c"
    break;

  case 5: /* declaracao: declaracao_inteiro  */
#line 64 "sintatico.y"
                               { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1219 "sintatico.tab.c"
    break;

  case 6: /* declaracao: declaracao_float  */
#line 65 "sintatico.y"
                           { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1225 "sintatico.tab.c"
    break;

  case 7: /* declaracao: declaracao_string  */
#line 66 "sintatico.y"
                            { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1231 "sintatico.tab.c"
    break;

  case 8: /* declaracao_inteiro: INT ID '=' NUM_INT ';'  */
#line 70 "sintatico.y"
                                            {
	
		addSymTable(&table, INTEGER, (yyvsp[-3].c).str, (yyvsp[-1].c).str);
		makeCodeDeclaration((yyval.c).str, INTEGER, (yyvsp[-3].c).str, (yyvsp[-1].c).str);
	}
#line 1241 "sintatico.tab.c"
    break;

  case 9: /* declaracao_inteiro: INT ID ';'  */
#line 76 "sintatico.y"
                      {
		
		addSymTable(&table, INTEGER, (yyvsp[-1].c).str, NULL);
		makeCodeDeclaration((yyval.c).str, INTEGER, (yyvsp[-1].c).str, NULL);
	}
#line 1251 "sintatico.tab.c"
    break;

  case 10: /* declaracao_float: FLOAT ID '=' NUM_FLOAT ';'  */
#line 84 "sintatico.y"
                                              {
		addSymTable(&table, REAL, (yyvsp[-3].c).str, (yyvsp[-1].c).str);
		makeCodeDeclaration((yyval.c).str, REAL, (yyvsp[-3].c).str, (yyvsp[-1].c).str);
	}
#line 1260 "sintatico.tab.c"
    break;

  case 11: /* declaracao_float: FLOAT ID ';'  */
#line 89 "sintatico.y"
                        {
		addSymTable(&table, REAL, (yyvsp[-1].c).str, NULL);
		makeCodeDeclaration((yyval.c).str, REAL, (yyvsp[-1].c).str, NULL);
	}
#line 1269 "sintatico.tab.c"
    break;

  case 12: /* declaracao_string: STR ID '=' LITERAL_STR ';'  */
#line 96 "sintatico.y"
                                               {

		addSymTable(&table, STRING, (yyvsp[-3].c).str, (yyvsp[-1].c).str);
		makeCodeDeclaration((yyval.c).str, STRING, (yyvsp[-3].c).str, (yyvsp[-1].c).str);
	}
#line 1279 "sintatico.tab.c"
    break;

  case 13: /* declaracao_string: STR ID ';'  */
#line 102 "sintatico.y"
                      {
		addSymTable(&table, STRING, (yyvsp[-1].c).str, NULL);
		makeCodeDeclaration((yyval.c).str, STRING, (yyvsp[-1].c).str, NULL);
	}
#line 1288 "sintatico.tab.c"
    break;

  case 14: /* bloco: '{' comandos '}'  */
#line 109 "sintatico.y"
                          {

		strcpy((yyval.c).str, (yyvsp[-1].c).str);
	}
#line 1297 "sintatico.tab.c"
    break;

  case 15: /* comandos: comando comandos  */
#line 116 "sintatico.y"
                             {
		strcpy((yyval.c).str, (yyvsp[-1].c).str);
		sprintf((yyval.c).str + strlen((yyval.c).str), "%s", (yyvsp[0].c).str);
	}
#line 1306 "sintatico.tab.c"
    break;

  case 16: /* comandos: %empty  */
#line 121 "sintatico.y"
                 { (yyval.c).str[0] = '\0'; }
#line 1312 "sintatico.tab.c"
    break;

  case 17: /* comando: comando_escrita  */
#line 125 "sintatico.y"
                              { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1318 "sintatico.tab.c"
    break;

  case 18: /* comando: comando_leitura  */
#line 126 "sintatico.y"
                                  { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1324 "sintatico.tab.c"
    break;

  case 19: /* comando: comando_atribuicao  */
#line 127 "sintatico.y"
                                  { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1330 "sintatico.tab.c"
    break;

  case 20: /* comando: comando_se  */
#line 128 "sintatico.y"
                                  { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1336 "sintatico.tab.c"
    break;

  case 21: /* comando: comando_se_senao  */
#line 129 "sintatico.y"
                                  { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1342 "sintatico.tab.c"
    break;

  case 22: /* comando: comando_enquanto  */
#line 130 "sintatico.y"
                                  { strcpy((yyval.c).str, (yyvsp[0].c).str); }
#line 1348 "sintatico.tab.c"
    break;

  case 23: /* comando_leitura: READ '(' ID ')' ';'  */
#line 134 "sintatico.y"
                                    {
		
		if (!makeCodeRead((yyval.c).str, (yyvsp[-2].c).str))
			YYABORT;
	}
#line 1358 "sintatico.tab.c"
    break;

  case 24: /* comando_escrita: WRITE '(' ID ')' ';'  */
#line 142 "sintatico.y"
                                     {

		if (!makeCodeWrite((yyval.c).str, (yyvsp[-2].c).str, 0))
			YYABORT;
	}
#line 1368 "sintatico.tab.c"
    break;

  case 25: /* comando_escrita: WRITELN '(' ID ')' ';'  */
#line 148 "sintatico.y"
                                {

		if (!makeCodeWrite((yyval.c).str, (yyvsp[-2].c).str, 1))
			YYABORT;
	}
#line 1378 "sintatico.tab.c"
    break;

  case 26: /* comando_atribuicao: ID '=' expressao_numerica ';'  */
#line 156 "sintatico.y"
                                                   {
		
		if (!makeCodeAssignment((yyval.c).str, (yyvsp[-3].c).str, (yyvsp[-1].c).str))
			YYABORT;
	}
#line 1388 "sintatico.tab.c"
    break;

  case 27: /* expressao_numerica: termo  */
#line 164 "sintatico.y"
                           {

		strcpy((yyval.c).str, (yyvsp[0].c).str);
	}
#line 1397 "sintatico.tab.c"
    break;

  case 28: /* expressao_numerica: expressao_numerica '+' expressao_numerica  */
#line 169 "sintatico.y"
                                                     {

		makeCodeAdd((yyval.c).str, (yyvsp[0].c).str);
	}
#line 1406 "sintatico.tab.c"
    break;

  case 29: /* expressao_numerica: expressao_numerica '-' expressao_numerica  */
#line 174 "sintatico.y"
                                                     {
		
		makeCodeSub((yyval.c).str, (yyvsp[0].c).str);
	}
#line 1415 "sintatico.tab.c"
    break;

  case 30: /* expressao_numerica: termo '+' fator  */
#line 179 "sintatico.y"
                           {

		makeCodeAdd((yyval.c).str, (yyvsp[0].c).str);
	}
#line 1424 "sintatico.tab.c"
    break;

  case 31: /* expressao_numerica: termo '-' fator  */
#line 184 "sintatico.y"
                           {

		makeCodeSub((yyval.c).str, (yyvsp[0].c).str);
	}
#line 1433 "sintatico.tab.c"
    break;

  case 32: /* expressao_numerica: termo '*' fator  */
#line 189 "sintatico.y"
                           {
		
		// printf("{%s}\n", $$.str);
		makeCodeMul((yyvsp[-2].c).str, (yyvsp[0].c).str);
		strcpy((yyval.c).str, (yyvsp[-2].c).str);

	}
#line 1445 "sintatico.tab.c"
    break;

  case 33: /* expressao_numerica: termo '/' fator  */
#line 197 "sintatico.y"
                           {

		makeCodeDiv((yyval.c).str, (yyvsp[0].c).str);
	}
#line 1454 "sintatico.tab.c"
    break;

  case 34: /* expressao_numerica: termo '%' fator  */
#line 202 "sintatico.y"
                           {

		makeCodeMod((yyval.c).str, (yyvsp[0].c).str);
	}
#line 1463 "sintatico.tab.c"
    break;

  case 35: /* termo: NUM_INT  */
#line 210 "sintatico.y"
                {

		makeCodeLoad((yyval.c).str, (yyvsp[0].c).str, 0);
	}
#line 1472 "sintatico.tab.c"
    break;

  case 36: /* termo: NUM_FLOAT  */
#line 215 "sintatico.y"
                    {

		makeCodeLoad((yyval.c).str, (yyvsp[0].c).str, 0);
	}
#line 1481 "sintatico.tab.c"
    break;

  case 37: /* termo: ID  */
#line 220 "sintatico.y"
              {

		if (!makeCodeLoad((yyval.c).str, (yyvsp[0].c).str, 1)) 
			YYABORT;

	}
#line 1492 "sintatico.tab.c"
    break;

  case 38: /* fator: NUM_INT  */
#line 229 "sintatico.y"
                {
		
		makeCodeLoad((yyval.c).str, (yyvsp[0].c).str, 0);
	}
#line 1501 "sintatico.tab.c"
    break;

  case 39: /* fator: NUM_FLOAT  */
#line 234 "sintatico.y"
                    {

		makeCodeLoad((yyval.c).str, (yyvsp[0].c).str, 0);
	}
#line 1510 "sintatico.tab.c"
    break;

  case 40: /* fator: ID  */
#line 239 "sintatico.y"
              {

		makeCodeLoad((yyval.c).str, (yyvsp[0].c).str, 1);
	}
#line 1519 "sintatico.tab.c"
    break;

  case 41: /* fator: '(' expressao_numerica ')'  */
#line 244 "sintatico.y"
                                      {
		
		strcpy((yyval.c).str, (yyvsp[-1].c).str);
	}
#line 1528 "sintatico.tab.c"
    break;

  case 42: /* comando_se: IF '(' expressao_booleana ')' bloco  */
#line 253 "sintatico.y"
                                                 {
		
		makeCodeIf((yyval.c).str, (yyvsp[-2].c).str, (yyvsp[-2].c).op, (yyvsp[0].c).str);
	}
#line 1537 "sintatico.tab.c"
    break;

  case 43: /* comando_se_senao: IF '(' expressao_booleana ')' bloco ELSE bloco  */
#line 260 "sintatico.y"
                                                                  {

		makeCodeIfElse((yyval.c).str, (yyvsp[-4].c).str, (yyvsp[-4].c).op, (yyvsp[-2].c).str, (yyvsp[0].c).str);
	}
#line 1546 "sintatico.tab.c"
    break;

  case 44: /* comando_enquanto: WHILE '(' expressao_booleana ')' bloco  */
#line 267 "sintatico.y"
                                                          {

		makeCodeWhile((yyval.c).str, (yyvsp[-2].c).str, (yyvsp[-2].c).op, (yyvsp[0].c).str);
	}
#line 1555 "sintatico.tab.c"
    break;

  case 45: /* expressao_booleana: ID operador_relacional expressao_numerica  */
#line 274 "sintatico.y"
                                                               {
		
		(yyval.c).op = (yyvsp[-1].c).op;
		if (!makeCodeComp((yyval.c).str, (yyvsp[-2].c).str, (yyvsp[0].c).str))
			YYABORT;
	}
#line 1566 "sintatico.tab.c"
    break;

  case 46: /* operador_relacional: '<'  */
#line 282 "sintatico.y"
                           { (yyval.c).op = -4; }
#line 1572 "sintatico.tab.c"
    break;

  case 47: /* operador_relacional: '>'  */
#line 283 "sintatico.y"
                               { (yyval.c).op = -3; }
#line 1578 "sintatico.tab.c"
    break;

  case 48: /* operador_relacional: LE  */
#line 284 "sintatico.y"
                               { (yyval.c).op = 3; }
#line 1584 "sintatico.tab.c"
    break;

  case 49: /* operador_relacional: GE  */
#line 285 "sintatico.y"
                               { (yyval.c).op = 4; }
#line 1590 "sintatico.tab.c"
    break;

  case 50: /* operador_relacional: EQ  */
#line 286 "sintatico.y"
                               { (yyval.c).op = -2; }
#line 1596 "sintatico.tab.c"
    break;

  case 51: /* operador_relacional: NE  */
#line 287 "sintatico.y"
                               { (yyval.c).op = 2; }
#line 1602 "sintatico.tab.c"
    break;


#line 1606 "sintatico.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 290 "sintatico.y"


void yyerror(char *s)
{
   fprintf(stderr, "Error: %s at line %d", s, cont_lines);
   fprintf(stderr, "\n");
}


