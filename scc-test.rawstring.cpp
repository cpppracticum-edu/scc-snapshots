/*
@(#)File:           $RCSfile: scc-test.rawstring.cpp,v $
@(#)Version:        $Revision: 8.2 $
@(#)Last changed:   $Date: 2022/05/30 01:02:47 $
@(#)Purpose:        Test SCC on C++11 raw strings
@(#)Author:         J Leffler
@(#)Copyright:      (C) JLSS 2014-15
@(#)Product:        SCC Version 8.0.2 (2022-05-29)
*/

/*TABSTOP=4*/

#ifndef lint
/* Prevent over-aggressive optimizers from eliminating ID string */
extern const char jlss_id_scc_rawstring_cpp[];
const char jlss_id_scc_rawstring_cpp[] = "@(#)$Id: scc-test.rawstring.cpp,v 8.2 2022/05/30 01:02:47 jonathanleffler Exp $";
#endif /* lint */

/* NB: This requires C++11 or C++14 support to compile; C++98 is not adequate */

/*
** Valid string literal prefixes in C++11: R, u8, u8R, u, uR, U, UR, L, LR.
** It is not clear that there's need for special processing unless the
** prefix character is upper-case R, which must be the last character
** before the string literal (it doesn't matter what, if anything,
** appears as the prior string prefix).
**
** L  => wchar_t
** u  => char16_t
** U  => char32_t
** u8 => char (encoded as UTF-8)
*/

char xyz[] = R"aa(/*
not a comment
*/)aa";  /* But this is */
char abc[] = R"/*(not a comment)/*";  /* But this is */
char def[] = R"(a minimal sort of
raw string)";  // But this is
char ghi[] = u8R"utf8(characters—and more€‹›)utf8";     // And so is this

wchar_t jkl[] = LR"wide(characters appear here)wide";   // And this one

char16_t mno[] = uR"RuR("Rossum's Universal Robots")RuR";   // And another

char32_t pqr[] = UR"RuR(close) are allowed)Ru)
inside
a
raw)string)RuR";  // This is a comment

char stu[] = u8R"??(xxx)??";  // Not trigraphs!

/* UTF-8 mapping for ISO 8859-15 codes 0xA0..0xFF */
char tuv[] = u8"\n"
    "\u00A0 = A0 U+00A0 NO-BREAK SPACE\n"
    "\u00A1 = A1 U+00A1 INVERTED EXCLAMATION MARK\n"
    "\u00A2 = A2 U+00A2 CENT SIGN\n"
    "\u00A3 = A3 U+00A3 POUND SIGN\n"
    "\u20AC = A4 U+20AC EURO SIGN\n"
    "\u00A5 = A5 U+00A5 YEN SIGN\n"
    "\u0160 = A6 U+0160 LATIN CAPITAL LETTER S WITH CARON\n"
    "\u00A7 = A7 U+00A7 SECTION SIGN\n"
    "\u0161 = A8 U+0161 LATIN SMALL LETTER S WITH CARON\n"
    "\u00A9 = A9 U+00A9 COPYRIGHT SIGN\n"
    "\u00AA = AA U+00AA FEMININE ORDINAL INDICATOR\n"
    "\u00AB = AB U+00AB LEFT-POINTING DOUBLE ANGLE QUOTATION MARK\n"
    "\u00AC = AC U+00AC NOT SIGN\n"
    "\u00AD = AD U+00AD SOFT HYPHEN\n"
    "\u00AE = AE U+00AE REGISTERED SIGN\n"
    "\u00AF = AF U+00AF MACRON\n"
    "\u00B0 = B0 U+00B0 DEGREE SIGN\n"
    "\u00B1 = B1 U+00B1 PLUS-MINUS SIGN\n"
    "\u00B2 = B2 U+00B2 SUPERSCRIPT TWO\n"
    "\u00B3 = B3 U+00B3 SUPERSCRIPT THREE\n"
    "\u017D = B4 U+017D LATIN CAPITAL LETTER Z WITH CARON\n"
    "\u00B5 = B5 U+00B5 MICRO SIGN\n"
    "\u00B6 = B6 U+00B6 PILCROW SIGN\n"
    "\u00B7 = B7 U+00B7 MIDDLE DOT\n"
    "\u017E = B8 U+017E LATIN SMALL LETTER Z WITH CARON\n"
    "\u00B9 = B9 U+00B9 SUPERSCRIPT ONE\n"
    "\u00BA = BA U+00BA MASCULINE ORDINAL INDICATOR\n"
    "\u00BB = BB U+00BB RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK\n"
    "\u0152 = BC U+0152 LATIN CAPITAL LIGATURE OE\n"
    "\u0153 = BD U+0153 LATIN SMALL LIGATURE OE\n"
    "\u0178 = BE U+0178 LATIN CAPITAL LETTER Y WITH DIAERESIS\n"
    "\u00BF = BF U+00BF INVERTED QUESTION MARK\n"
    "\u00C0 = C0 U+00C0 LATIN CAPITAL LETTER A WITH GRAVE\n"
    "\u00C1 = C1 U+00C1 LATIN CAPITAL LETTER A WITH ACUTE\n"
    "\u00C2 = C2 U+00C2 LATIN CAPITAL LETTER A WITH CIRCUMFLEX\n"
    "\u00C3 = C3 U+00C3 LATIN CAPITAL LETTER A WITH TILDE\n"
    "\u00C4 = C4 U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS\n"
    "\u00C5 = C5 U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE\n"
    "\u00C6 = C6 U+00C6 LATIN CAPITAL LETTER AE\n"
    "\u00C7 = C7 U+00C7 LATIN CAPITAL LETTER C WITH CEDILLA\n"
    "\u00C8 = C8 U+00C8 LATIN CAPITAL LETTER E WITH GRAVE\n"
    "\u00C9 = C9 U+00C9 LATIN CAPITAL LETTER E WITH ACUTE\n"
    "\u00CA = CA U+00CA LATIN CAPITAL LETTER E WITH CIRCUMFLEX\n"
    "\u00CB = CB U+00CB LATIN CAPITAL LETTER E WITH DIAERESIS\n"
    "\u00CC = CC U+00CC LATIN CAPITAL LETTER I WITH GRAVE\n"
    "\u00CD = CD U+00CD LATIN CAPITAL LETTER I WITH ACUTE\n"
    "\u00CE = CE U+00CE LATIN CAPITAL LETTER I WITH CIRCUMFLEX\n"
    "\u00CF = CF U+00CF LATIN CAPITAL LETTER I WITH DIAERESIS\n"
    "\u00D0 = D0 U+00D0 LATIN CAPITAL LETTER ETH\n"
    "\u00D1 = D1 U+00D1 LATIN CAPITAL LETTER N WITH TILDE\n"
    "\u00D2 = D2 U+00D2 LATIN CAPITAL LETTER O WITH GRAVE\n"
    "\u00D3 = D3 U+00D3 LATIN CAPITAL LETTER O WITH ACUTE\n"
    "\u00D4 = D4 U+00D4 LATIN CAPITAL LETTER O WITH CIRCUMFLEX\n"
    "\u00D5 = D5 U+00D5 LATIN CAPITAL LETTER O WITH TILDE\n"
    "\u00D6 = D6 U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS\n"
    "\u00D7 = D7 U+00D7 MULTIPLICATION SIGN\n"
    "\u00D8 = D8 U+00D8 LATIN CAPITAL LETTER O WITH STROKE\n"
    "\u00D9 = D9 U+00D9 LATIN CAPITAL LETTER U WITH GRAVE\n"
    "\u00DA = DA U+00DA LATIN CAPITAL LETTER U WITH ACUTE\n"
    "\u00DB = DB U+00DB LATIN CAPITAL LETTER U WITH CIRCUMFLEX\n"
    "\u00DC = DC U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS\n"
    "\u00DD = DD U+00DD LATIN CAPITAL LETTER Y WITH ACUTE\n"
    "\u00DE = DE U+00DE LATIN CAPITAL LETTER THORN\n"
    "\u00DF = DF U+00DF LATIN SMALL LETTER SHARP S\n"
    "\u00E0 = E0 U+00E0 LATIN SMALL LETTER A WITH GRAVE\n"
    "\u00E1 = E1 U+00E1 LATIN SMALL LETTER A WITH ACUTE\n"
    "\u00E2 = E2 U+00E2 LATIN SMALL LETTER A WITH CIRCUMFLEX\n"
    "\u00E3 = E3 U+00E3 LATIN SMALL LETTER A WITH TILDE\n"
    "\u00E4 = E4 U+00E4 LATIN SMALL LETTER A WITH DIAERESIS\n"
    "\u00E5 = E5 U+00E5 LATIN SMALL LETTER A WITH RING ABOVE\n"
    "\u00E6 = E6 U+00E6 LATIN SMALL LETTER AE\n"
    "\u00E7 = E7 U+00E7 LATIN SMALL LETTER C WITH CEDILLA\n"
    "\u00E8 = E8 U+00E8 LATIN SMALL LETTER E WITH GRAVE\n"
    "\u00E9 = E9 U+00E9 LATIN SMALL LETTER E WITH ACUTE\n"
    "\u00EA = EA U+00EA LATIN SMALL LETTER E WITH CIRCUMFLEX\n"
    "\u00EB = EB U+00EB LATIN SMALL LETTER E WITH DIAERESIS\n"
    "\u00EC = EC U+00EC LATIN SMALL LETTER I WITH GRAVE\n"
    "\u00ED = ED U+00ED LATIN SMALL LETTER I WITH ACUTE\n"
    "\u00EE = EE U+00EE LATIN SMALL LETTER I WITH CIRCUMFLEX\n"
    "\u00EF = EF U+00EF LATIN SMALL LETTER I WITH DIAERESIS\n"
    "\u00F0 = F0 U+00F0 LATIN SMALL LETTER ETH\n"
    "\u00F1 = F1 U+00F1 LATIN SMALL LETTER N WITH TILDE\n"
    "\u00F2 = F2 U+00F2 LATIN SMALL LETTER O WITH GRAVE\n"
    "\u00F3 = F3 U+00F3 LATIN SMALL LETTER O WITH ACUTE\n"
    "\u00F4 = F4 U+00F4 LATIN SMALL LETTER O WITH CIRCUMFLEX\n"
    "\u00F5 = F5 U+00F5 LATIN SMALL LETTER O WITH TILDE\n"
    "\u00F6 = F6 U+00F6 LATIN SMALL LETTER O WITH DIAERESIS\n"
    "\u00F7 = F7 U+00F7 DIVISION SIGN\n"
    "\u00F8 = F8 U+00F8 LATIN SMALL LETTER O WITH STROKE\n"
    "\u00F9 = F9 U+00F9 LATIN SMALL LETTER U WITH GRAVE\n"
    "\u00FA = FA U+00FA LATIN SMALL LETTER U WITH ACUTE\n"
    "\u00FB = FB U+00FB LATIN SMALL LETTER U WITH CIRCUMFLEX\n"
    "\u00FC = FC U+00FC LATIN SMALL LETTER U WITH DIAERESIS\n"
    "\u00FD = FD U+00FD LATIN SMALL LETTER Y WITH ACUTE\n"
    "\u00FE = FE U+00FE LATIN SMALL LETTER THORN\n"
    "\u00FF = FF U+00FF LATIN SMALL LETTER Y WITH DIAERESIS\n"
    ;

/* Samples from the standard - exploiting string concatenation */
const char *p = R"(a\
b
c)";    /* Trailing comment */
const char *q = "a\\\nb\nc";

/* Lots of string concatenation here */
const char *mix =

R"a(
)\
a"
)a" /* comment separator */
" is equivalent to " "\n)\\\na\"\n" /* comment separator */
R"(??)" /* comment separator */
"\?\?" /* comment separator */
R"#(
)??="
)#" /* comment separator */
"\n)\?\?=\"\n"; /* comment separator */

/* Testing almost matches */

const char *a01 = R"aa( )a )bs )aaa )aa )aa"; /* comment terminator */
const char *a02 = R"abcdefghijklmnop( hoops to jump through )abcdefghijklmnop";

const char *a05 = R"abcdefghijklmnop( hoops
to jump through )abcdefghijklmnop)abc))abcdefghijklmnopq
)abcdefghijklmnop";   /* And a final comment */

#if defined(REGEX_TYPE_DEFINED)
/* Bug report (issue #1) from Oleg Skinderev 2022-05-22 via GitHub */
/* Input string - should be unchanged */
static regex incl1{R"/(\s*#\s*include\s*"([^"]*)"\s*)/"};
static regex incl2{R"/(\s*#\s*include\s*<([^>]*)>\s*)/"};
/* Buggy output - should be the same as the input but wasn't */
/* NB: to stand a chance of compiling, rename incl1 to incl3, incl2 to incl4 */
static regex incl1{R"/(\s*#\s*include\s*"([^"]*)\s*)/"};
static regex incl2{R"/(\s*#\s*include\s*<([^>]*)\s*)/"};
#endif /* REGEX_TYPE_DEFINED */

#if defined(STRING_TYPE_DEFINED)
/* Bug report (issue #2) from Oleg Skinderev 2022-05-29 via GitHub */
/* Input quoted data - double and single quoted */
/* Double-quoted data provided by OS (except for backslash/single-quotes) */
/* Single-quoted data adapted by JL */
string str1 = "RC-21\'\\\\M2";
string str2 = "\"\\r\\n\'\t\\\"\\\\\"";
string str3 = 'R\\\\M2';
string str4 = '\'\\r\"\\"\\n\t\\\'\\\\\'';
/* Buggy output - should be the same as the input but wasn't */
/* NB: defining STRING_TYPE_DEFINED won't let this compile */
string str1 = "RC-21\'\\\\2";
string str2 = "\"\\\\\'\t\\\"\\\\\"";
string str3 = 'R\\\\2';
string str4 = '\'\\\"\\\\\t\\\'\\\\\'';
#endif /* STRING_TYPE_DEFINED */
