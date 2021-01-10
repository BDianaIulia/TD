/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cminus.y"

#include <stdio.h>
#include <stdlib.h>
#include "AST.h"

ASTNode* astRoot = NULL;
int yyerror(char * s);
extern int yylex(void);

#line 81 "cminus.tab.c"

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

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_LESS_OR_EQUAL = 11,             /* LESS_OR_EQUAL  */
  YYSYMBOL_GREATER_OR_EQUAL = 12,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_EQUAL = 13,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 14,                 /* NOT_EQUAL  */
  YYSYMBOL_LEFT_PRNTS = 15,                /* LEFT_PRNTS  */
  YYSYMBOL_RIGHT_PRNTS = 16,               /* RIGHT_PRNTS  */
  YYSYMBOL_LEFT_BRACKET = 17,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 18,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_BRACE = 19,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 20,               /* RIGHT_BRACE  */
  YYSYMBOL_ADD = 21,                       /* ADD  */
  YYSYMBOL_SUBSTRACT = 22,                 /* SUBSTRACT  */
  YYSYMBOL_MULTIPLY = 23,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 24,                    /* DIVIDE  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_LESS = 26,                      /* LESS  */
  YYSYMBOL_GREATER = 27,                   /* GREATER  */
  YYSYMBOL_ASSIGN = 28,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_declaration_list = 33,          /* declaration_list  */
  YYSYMBOL_selection_stmt = 34,            /* selection_stmt  */
  YYSYMBOL_iteration_stmt = 35,            /* iteration_stmt  */
  YYSYMBOL_declaration = 36,               /* declaration  */
  YYSYMBOL_var_declaration = 37,           /* var_declaration  */
  YYSYMBOL_type_specifier = 38,            /* type_specifier  */
  YYSYMBOL_fun_declaration = 39,           /* fun_declaration  */
  YYSYMBOL_params = 40,                    /* params  */
  YYSYMBOL_params_list = 41,               /* params_list  */
  YYSYMBOL_param = 42,                     /* param  */
  YYSYMBOL_compound_stmt = 43,             /* compound_stmt  */
  YYSYMBOL_local_declarations = 44,        /* local_declarations  */
  YYSYMBOL_statement_list = 45,            /* statement_list  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_expression_stmt = 47,           /* expression_stmt  */
  YYSYMBOL_return_stmt = 48,               /* return_stmt  */
  YYSYMBOL_expression = 49,                /* expression  */
  YYSYMBOL_var = 50,                       /* var  */
  YYSYMBOL_simple_expression = 51,         /* simple_expression  */
  YYSYMBOL_relop = 52,                     /* relop  */
  YYSYMBOL_additive_expression = 53,       /* additive_expression  */
  YYSYMBOL_addop = 54,                     /* addop  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_mulop = 56,                     /* mulop  */
  YYSYMBOL_factor = 57,                    /* factor  */
  YYSYMBOL_call = 58,                      /* call  */
  YYSYMBOL_args = 59,                      /* args  */
  YYSYMBOL_args_list = 60                  /* args_list  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    83,    84,    90,    91,    94,    97,    98,
     101,   102,   105,   106,   109,   112,   113,   116,   120,   123,
     124,   127,   130,   131,   137,   138,   144,   145,   146,   147,
     148,   151,   152,   156,   157,   160,   164,   167,   168,   171,
     172,   175,   176,   177,   178,   179,   180,   183,   184,   187,
     188,   191,   192,   195,   196,   199,   200,   201,   202,   205,
     208,   209,   212,   213
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "RETURN",
  "INT", "VOID", "WHILE", "ID", "NUM", "LESS_OR_EQUAL", "GREATER_OR_EQUAL",
  "EQUAL", "NOT_EQUAL", "LEFT_PRNTS", "RIGHT_PRNTS", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "ADD", "SUBSTRACT",
  "MULTIPLY", "DIVIDE", "MOD", "LESS", "GREATER", "ASSIGN", "SEMICOLON",
  "COMMA", "$accept", "program", "declaration_list", "selection_stmt",
  "iteration_stmt", "declaration", "var_declaration", "type_specifier",
  "fun_declaration", "params", "params_list", "param", "compound_stmt",
  "local_declarations", "statement_list", "statement", "expression_stmt",
  "return_stmt", "expression", "var", "simple_expression", "relop",
  "additive_expression", "addop", "term", "mulop", "factor", "call",
  "args", "args_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285
};
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      59,   -50,   -50,     2,   -50,    59,   -50,    -4,   -50,   -50,
     -50,    -3,    62,    -1,   -50,     3,     6,    17,    -8,   -50,
      24,    43,    33,    59,    45,    57,   -50,   -50,   -50,   -50,
     -50,    59,   -50,    67,    -2,    21,    63,     1,    64,    22,
     -50,    44,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
      48,    52,   -50,    35,    47,   -50,   -50,    44,   -50,    53,
      44,    44,    44,    65,   -50,    44,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,    44,    44,   -50,   -50,    44,    68,
     -50,    69,   -50,    70,    58,    71,   -50,   -50,   -50,    51,
      47,   -50,    26,    26,   -50,    44,   -50,    79,   -50,   -50,
      26,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    13,     0,     2,     3,     8,     0,     9,     1,
       4,     0,     0,     0,    10,    13,     0,     0,    15,    18,
       0,    19,     0,     0,     0,     0,    22,    14,    17,    11,
      20,    24,    23,     0,     0,     0,     0,     0,     0,    37,
      58,     0,    21,    32,    28,    29,    27,    25,    26,    30,
       0,    56,    36,    40,    48,    52,    57,     0,    33,     0,
       0,    60,     0,     0,    31,     0,    41,    44,    45,    46,
      49,    50,    42,    43,     0,     0,    53,    54,     0,     0,
      34,     0,    63,     0,    61,     0,    55,    35,    56,    39,
      47,    51,     0,     0,    59,     0,    38,     5,     7,    62,
       0,     6
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,    82,   -50,   -50,   -50,    60,     9,   -50,   -50,
     -50,    72,    74,   -50,   -50,   -49,   -50,   -50,   -37,   -11,
     -50,   -50,    16,   -50,    18,   -50,    14,   -50,   -50,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    44,    45,     5,     6,     7,     8,    17,
      18,    19,    46,    31,    34,    47,    48,    49,    50,    51,
      52,    74,    53,    75,    54,    78,    55,    56,    83,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    36,     9,    37,    63,    11,    38,    39,    40,    20,
      39,    40,    12,    41,    13,    21,    41,    26,    42,   -16,
      79,    16,    23,    81,    82,    85,    14,    43,    87,    36,
      58,    37,    16,    22,    38,    39,    40,    61,    13,    62,
      33,    41,    24,    97,    98,    26,    66,    67,    68,    69,
      14,   101,    26,    39,    40,    43,    70,    71,    99,    41,
      25,    72,    73,    88,    88,     1,     2,    88,     1,    15,
      76,    77,    70,    71,    29,    30,    35,    64,    57,    60,
      65,    86,    80,   100,    92,    93,    94,    10,    95,    96,
      89,    32,    91,    90,     0,    28,    27
};

static const yytype_int8 yycheck[] =
{
      37,     3,     0,     5,    41,     9,     8,     9,    10,    10,
       9,    10,    15,    15,    17,     9,    15,    19,    20,    16,
      57,    12,    30,    60,    61,    62,    29,    29,    65,     3,
      29,     5,    23,    16,     8,     9,    10,    15,    17,    17,
      31,    15,    18,    92,    93,    19,    11,    12,    13,    14,
      29,   100,    19,     9,    10,    29,    21,    22,    95,    15,
      17,    26,    27,    74,    75,     6,     7,    78,     6,     7,
      23,    24,    21,    22,    29,    18,     9,    29,    15,    15,
      28,    16,    29,     4,    16,    16,    16,     5,    30,    18,
      74,    31,    78,    75,    -1,    23,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    32,    33,    36,    37,    38,    39,     0,
      33,     9,    15,    17,    29,     7,    38,    40,    41,    42,
      10,     9,    16,    30,    18,    17,    19,    43,    42,    29,
      18,    44,    37,    38,    45,     9,     3,     5,     8,     9,
      10,    15,    20,    29,    34,    35,    43,    46,    47,    48,
      49,    50,    51,    53,    55,    57,    58,    15,    29,    49,
      15,    15,    17,    49,    29,    28,    11,    12,    13,    14,
      21,    22,    26,    27,    52,    54,    23,    24,    56,    49,
      29,    49,    49,    59,    60,    49,    16,    49,    50,    53,
      55,    57,    16,    16,    16,    30,    18,    46,    46,    49,
       4,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    34,    35,    36,    36,
      37,    37,    38,    38,    39,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      46,    47,    47,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    57,    57,    58,
      59,    59,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     5,     7,     5,     1,     1,
       3,     6,     1,     1,     6,     1,     1,     3,     1,     2,
       4,     4,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     2,     1,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       0,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* program: declaration_list  */
#line 80 "cminus.y"
                                                {astRoot = createProgramUnitNode((yyvsp[0].node)); (yyval.node) = astRoot;}
#line 1195 "cminus.tab.c"
    break;

  case 3: /* declaration_list: declaration  */
#line 83 "cminus.y"
                                                                                {(yyval.node) = createDeclarationList((yyvsp[0].node));}
#line 1201 "cminus.tab.c"
    break;

  case 4: /* declaration_list: declaration declaration_list  */
#line 84 "cminus.y"
                                                                                {
															(yyval.node) = (yyvsp[0].node);
															addLinkToList((yyval.node), (yyvsp[-1].node));
														}
#line 1210 "cminus.tab.c"
    break;

  case 5: /* selection_stmt: IF LEFT_PRNTS expression RIGHT_PRNTS statement  */
#line 90 "cminus.y"
                                                                                                                { (yyval.node) = createIfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL);}
#line 1216 "cminus.tab.c"
    break;

  case 6: /* selection_stmt: IF LEFT_PRNTS expression RIGHT_PRNTS statement ELSE statement  */
#line 91 "cminus.y"
                                                                                                                { (yyval.node) = createIfStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1222 "cminus.tab.c"
    break;

  case 7: /* iteration_stmt: WHILE LEFT_PRNTS expression RIGHT_PRNTS statement  */
#line 94 "cminus.y"
                                                                                        {(yyval.node) = createWhileStatement((yyvsp[-2].node), (yyvsp[0].node));}
#line 1228 "cminus.tab.c"
    break;

  case 8: /* declaration: var_declaration  */
#line 97 "cminus.y"
                                                {(yyval.node) = createDeclarationNode((yyvsp[0].node));}
#line 1234 "cminus.tab.c"
    break;

  case 9: /* declaration: fun_declaration  */
#line 98 "cminus.y"
                                                {(yyval.node) = createDeclarationNode((yyvsp[0].node));}
#line 1240 "cminus.tab.c"
    break;

  case 10: /* var_declaration: type_specifier ID SEMICOLON  */
#line 101 "cminus.y"
                                                                                                                {(yyval.node) = createVarDeclaration((yyvsp[-2].node), (yyvsp[-1].name), 0);}
#line 1246 "cminus.tab.c"
    break;

  case 11: /* var_declaration: type_specifier ID LEFT_BRACKET NUM RIGHT_BRACKET SEMICOLON  */
#line 102 "cminus.y"
                                                                                                {(yyval.node) = createVarDeclaration((yyvsp[-5].node), (yyvsp[-4].name), (yyvsp[-2].value));}
#line 1252 "cminus.tab.c"
    break;

  case 12: /* type_specifier: INT  */
#line 105 "cminus.y"
                                        {(yyval.node) = createTypeSpecifier("INT");}
#line 1258 "cminus.tab.c"
    break;

  case 13: /* type_specifier: VOID  */
#line 106 "cminus.y"
                                                        {(yyval.node) = createTypeSpecifier("VOID");}
#line 1264 "cminus.tab.c"
    break;

  case 14: /* fun_declaration: type_specifier ID LEFT_PRNTS params RIGHT_PRNTS compound_stmt  */
#line 109 "cminus.y"
                                                                                                {(yyval.node) = createFunctionDeclarationNode((yyvsp[-5].node), (yyvsp[-4].name), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1270 "cminus.tab.c"
    break;

  case 15: /* params: params_list  */
#line 112 "cminus.y"
                                        {(yyval.node) = createParametersDeclarationNode((yyvsp[0].node));}
#line 1276 "cminus.tab.c"
    break;

  case 16: /* params: VOID  */
#line 113 "cminus.y"
                                                        {(yyval.node) = createParametersDeclarationNode(NULL);}
#line 1282 "cminus.tab.c"
    break;

  case 17: /* params_list: params_list COMMA param  */
#line 116 "cminus.y"
                                                        {
													(yyval.node) = (yyvsp[-2].node);
													addLinkToList((yyval.node), (yyvsp[0].node));
												}
#line 1291 "cminus.tab.c"
    break;

  case 18: /* params_list: param  */
#line 120 "cminus.y"
                                                                                        {(yyval.node) = createListNode("ParametersList", (yyvsp[0].node));}
#line 1297 "cminus.tab.c"
    break;

  case 19: /* param: type_specifier ID  */
#line 123 "cminus.y"
                                                                                                { (yyval.node) = createVarDeclaration((yyvsp[-1].node), (yyvsp[0].name), 0);}
#line 1303 "cminus.tab.c"
    break;

  case 20: /* param: type_specifier ID LEFT_BRACKET RIGHT_BRACKET  */
#line 124 "cminus.y"
                                                                        { (yyval.node) = createVarDeclaration((yyvsp[-3].node), (yyvsp[-2].name), 0);}
#line 1309 "cminus.tab.c"
    break;

  case 21: /* compound_stmt: LEFT_BRACE local_declarations statement_list RIGHT_BRACE  */
#line 127 "cminus.y"
                                                                                        {(yyval.node) = createCompoundStatement((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1315 "cminus.tab.c"
    break;

  case 22: /* local_declarations: %empty  */
#line 130 "cminus.y"
                                                                                                                        {(yyval.node) = createListNode("localDeclaration", NULL);}
#line 1321 "cminus.tab.c"
    break;

  case 23: /* local_declarations: local_declarations var_declaration  */
#line 131 "cminus.y"
                                                                                                        {
																			(yyval.node) = (yyvsp[-1].node);
																			addLinkToList((yyval.node), (yyvsp[0].node)); 
																		}
#line 1330 "cminus.tab.c"
    break;

  case 24: /* statement_list: %empty  */
#line 137 "cminus.y"
                                                                                                                                {(yyval.node) = createListNode("StatementList",NULL);}
#line 1336 "cminus.tab.c"
    break;

  case 25: /* statement_list: statement_list statement  */
#line 138 "cminus.y"
                                                                                                                {
																			(yyval.node) = (yyvsp[-1].node);
																			addLinkToList((yyval.node), (yyvsp[0].node));
																		}
#line 1345 "cminus.tab.c"
    break;

  case 26: /* statement: expression_stmt  */
#line 144 "cminus.y"
                                                                {(yyval.node) = createStatementNode((yyvsp[0].node));}
#line 1351 "cminus.tab.c"
    break;

  case 27: /* statement: compound_stmt  */
#line 145 "cminus.y"
                                                                        {(yyval.node) = createStatementNode((yyvsp[0].node));}
#line 1357 "cminus.tab.c"
    break;

  case 28: /* statement: selection_stmt  */
#line 146 "cminus.y"
                                                                        {(yyval.node) = createStatementNode((yyvsp[0].node));}
#line 1363 "cminus.tab.c"
    break;

  case 29: /* statement: iteration_stmt  */
#line 147 "cminus.y"
                                                                        {(yyval.node) = createStatementNode((yyvsp[0].node));}
#line 1369 "cminus.tab.c"
    break;

  case 30: /* statement: return_stmt  */
#line 148 "cminus.y"
                                                                        {(yyval.node) = createStatementNode((yyvsp[0].node));}
#line 1375 "cminus.tab.c"
    break;

  case 31: /* expression_stmt: expression SEMICOLON  */
#line 151 "cminus.y"
                                                        {(yyval.node) = createExpressionStatement((yyvsp[-1].node));}
#line 1381 "cminus.tab.c"
    break;

  case 32: /* expression_stmt: SEMICOLON  */
#line 152 "cminus.y"
                                                                                        {(yyval.node) = createExpressionStatement(NULL);}
#line 1387 "cminus.tab.c"
    break;

  case 33: /* return_stmt: RETURN SEMICOLON  */
#line 156 "cminus.y"
                                                                {(yyval.node) = createReturnStatement(NULL);}
#line 1393 "cminus.tab.c"
    break;

  case 34: /* return_stmt: RETURN expression SEMICOLON  */
#line 157 "cminus.y"
                                                                {(yyval.node) = createReturnStatement((yyvsp[-1].node));}
#line 1399 "cminus.tab.c"
    break;

  case 35: /* expression: var ASSIGN expression  */
#line 160 "cminus.y"
                                                        {
												(yyval.node) = (yyvsp[0].node);
												addLinkToList((yyval.node), (yyvsp[-2].node));
											}
#line 1408 "cminus.tab.c"
    break;

  case 36: /* expression: simple_expression  */
#line 164 "cminus.y"
                                                                {(yyval.node) = createExpressionNode((yyvsp[0].node));}
#line 1414 "cminus.tab.c"
    break;

  case 37: /* var: ID  */
#line 167 "cminus.y"
                                                                                                {(yyval.node) = createVarNode((yyvsp[0].name), NULL);}
#line 1420 "cminus.tab.c"
    break;

  case 38: /* var: ID LEFT_BRACKET expression RIGHT_BRACKET  */
#line 168 "cminus.y"
                                                                {(yyval.node) = createVarNode((yyvsp[-3].name), (yyvsp[-1].node));}
#line 1426 "cminus.tab.c"
    break;

  case 39: /* simple_expression: additive_expression relop additive_expression  */
#line 171 "cminus.y"
                                                                                {(yyval.node) = createSimpleExpresion((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1432 "cminus.tab.c"
    break;

  case 40: /* simple_expression: additive_expression  */
#line 172 "cminus.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1438 "cminus.tab.c"
    break;

  case 41: /* relop: LESS_OR_EQUAL  */
#line 175 "cminus.y"
                                                {(yyval.node) = createDefaultNode("LESS_OR_EQUAL", 0);}
#line 1444 "cminus.tab.c"
    break;

  case 42: /* relop: LESS  */
#line 176 "cminus.y"
                                                                {(yyval.node) = createDefaultNode("LESS", 0);}
#line 1450 "cminus.tab.c"
    break;

  case 43: /* relop: GREATER  */
#line 177 "cminus.y"
                                                                {(yyval.node) = createDefaultNode("GREATER", 0);}
#line 1456 "cminus.tab.c"
    break;

  case 44: /* relop: GREATER_OR_EQUAL  */
#line 178 "cminus.y"
                                                {(yyval.node) = createDefaultNode("GREATER_OR_EQUAL", 0);}
#line 1462 "cminus.tab.c"
    break;

  case 45: /* relop: EQUAL  */
#line 179 "cminus.y"
                                                                {(yyval.node) = createDefaultNode("EQUAL", 0);}
#line 1468 "cminus.tab.c"
    break;

  case 46: /* relop: NOT_EQUAL  */
#line 180 "cminus.y"
                                                        {(yyval.node) = createDefaultNode("NOT_EQUAL", 0);}
#line 1474 "cminus.tab.c"
    break;

  case 47: /* additive_expression: additive_expression addop term  */
#line 183 "cminus.y"
                                                                                {(yyval.node) = createAdditiveExpression((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1480 "cminus.tab.c"
    break;

  case 48: /* additive_expression: term  */
#line 184 "cminus.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1486 "cminus.tab.c"
    break;

  case 49: /* addop: ADD  */
#line 187 "cminus.y"
                                                                {(yyval.node) = createDefaultNode("ADD", 0);}
#line 1492 "cminus.tab.c"
    break;

  case 50: /* addop: SUBSTRACT  */
#line 188 "cminus.y"
                                                        {(yyval.node) = createDefaultNode("SUBSTRACT", 0);}
#line 1498 "cminus.tab.c"
    break;

  case 51: /* term: term mulop factor  */
#line 191 "cminus.y"
                                                {(yyval.node) = createTerm((yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));}
#line 1504 "cminus.tab.c"
    break;

  case 52: /* term: factor  */
#line 192 "cminus.y"
                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1510 "cminus.tab.c"
    break;

  case 53: /* mulop: MULTIPLY  */
#line 195 "cminus.y"
                                                        {(yyval.node) = createDefaultNode("MULTIPLY", 0);}
#line 1516 "cminus.tab.c"
    break;

  case 54: /* mulop: DIVIDE  */
#line 196 "cminus.y"
                                                                {(yyval.node) = createDefaultNode("DIVIDE", 0);}
#line 1522 "cminus.tab.c"
    break;

  case 55: /* factor: LEFT_PRNTS expression RIGHT_PRNTS  */
#line 199 "cminus.y"
                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1528 "cminus.tab.c"
    break;

  case 56: /* factor: var  */
#line 200 "cminus.y"
                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1534 "cminus.tab.c"
    break;

  case 57: /* factor: call  */
#line 201 "cminus.y"
                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1540 "cminus.tab.c"
    break;

  case 58: /* factor: NUM  */
#line 202 "cminus.y"
                                                                                                {(yyval.node) = createNumNode((yyvsp[0].value));}
#line 1546 "cminus.tab.c"
    break;

  case 59: /* call: ID LEFT_PRNTS args RIGHT_PRNTS  */
#line 205 "cminus.y"
                                                                {(yyval.node) = createCall((yyvsp[-3].name), (yyvsp[-1].node));}
#line 1552 "cminus.tab.c"
    break;

  case 60: /* args: %empty  */
#line 208 "cminus.y"
                                                                {(yyval.node) = NULL;}
#line 1558 "cminus.tab.c"
    break;

  case 61: /* args: args_list  */
#line 209 "cminus.y"
                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1564 "cminus.tab.c"
    break;

  case 62: /* args_list: args_list COMMA expression  */
#line 212 "cminus.y"
                                                                { (yyval.node) = (yyvsp[-2].node); addLinkToList((yyval.node), (yyvsp[0].node)); }
#line 1570 "cminus.tab.c"
    break;

  case 63: /* args_list: expression  */
#line 213 "cminus.y"
                                                                                        { (yyval.node) = createListNode("ArgumentsList", (yyvsp[0].node)); }
#line 1576 "cminus.tab.c"
    break;


#line 1580 "cminus.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 216 "cminus.y"



int yyerror(char * s) 
/* yacc error handler */
{    
	printf ( "%s\n", s); 
	return 0;
}  
