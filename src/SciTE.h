// SciTE - Scintilla based Text Editor
/** @file SciTE.h
 ** Define command IDs used within SciTE.
 **/
// Copyright 1998-2001 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.

#ifndef SCITE_H
#define SCITE_H

// Menu IDs.
// These are located 100 apart. No one will want more than 100 in each menu ;)
#define IDM_MRUFILE			1000
#define IDM_TOOLS			1100
#define IDM_BUFFER			1200
#define IDM_IMPORT			1300
#define IDM_LEXER			1400

// File
#define IDM_NEW			101
#define IDM_OPEN			102
#define IDM_OPENSELECTED		103
#define IDM_REVERT			104
#define IDM_CLOSE			105
#define IDM_SAVE			106
#define IDM_SAVEAS			110
#define IDM_SAVEASHTML		111
#define IDM_SAVEASRTF		112
#define IDM_SAVEASPDF		113
#define IDM_FILER			114
#define IDM_MRU_SEP			120
#define IDM_PRINTSETUP		130
#define IDM_PRINT			131
#define IDM_LOADSESSION		132
#define IDM_SAVESESSION		133
#define IDM_QUIT			140

#define MRU_START	8
#define IMPORT_START 15
#define TOOLS_START 3

// Edit
#define IDM_UNDO			201
#define IDM_REDO			202
#define IDM_CUT				203
#define IDM_COPY			204
#define IDM_PASTE			205
#define IDM_CLEAR			206
#define IDM_SELECTALL		207
#define IDM_FIND			210
#define IDM_FINDNEXT			211
#define IDM_FINDNEXTBACK		212
#define IDM_FINDNEXTSEL		213
#define IDM_FINDNEXTBACKSEL	214
#define IDM_FINDINFILES		215
#define IDM_REPLACE			216
#define IDM_GOTO			220
#define IDM_BOOKMARK_NEXT	221
#define IDM_BOOKMARK_TOGGLE	222
#define IDM_BOOKMARK_PREV	223
#define IDM_BOOKMARK_CLEARALL	224
#define IDM_MATCHBRACE		230
#define IDM_SELECTTOBRACE	231
#define IDM_SHOWCALLTIP		232
#define IDM_COMPLETE		233
#define IDM_COMPLETEWORD	234
#define IDM_EXPAND			235
#define IDM_TOGGLE_FOLDALL	236
#define IDM_UPRCASE			240
#define IDM_LWRCASE			241
#define IDM_ABBREV			242
#define IDM_BLOCK_COMMENT	243
#define IDM_STREAM_COMMENT	244
#define IDM_COPYASRTF		245
#define IDM_BOX_COMMENT		246

#define IDM_PREVMATCHPPC	260
#define IDM_SELECTTOPREVMATCHPPC	261
#define IDM_NEXTMATCHPPC	262
#define IDM_SELECTTONEXTMATCHPPC	263

// Tools
#define IDM_COMPILE			301
#define IDM_BUILD			302
#define IDM_GO				303
#define IDM_STOPEXECUTE		304
#define IDM_FINISHEDEXECUTE	305
#define IDM_NEXTMSG			306
#define IDM_PREVMSG			307

#define IDM_MACRO_SEP		310
#define IDM_MACRORECORD		311
#define IDM_MACROSTOPRECORD	312
#define IDM_MACROPLAY		313
#define IDM_MACROLIST		314

#define IDM_ACTIVATE			320

#define IDM_SRCWIN			350
#define IDM_RUNWIN			351
#define IDM_TOOLWIN			352
#define IDM_STATUSWIN		353
#define IDM_TABWIN			354

// Options
#define IDM_SPLITVERTICAL		401
#define IDM_VIEWSPACE		402
#define IDM_VIEWEOL			403
#define IDM_VIEWGUIDES		404
#define IDM_SELMARGIN		405
#define IDM_FOLDMARGIN		406
#define IDM_LINENUMBERMARGIN	407
#define IDM_VIEWTOOLBAR		408
#define IDM_TOGGLEOUTPUT		409
#define IDM_VIEWTABBAR		410
#define IDM_VIEWSTATUSBAR	411

#define IDM_CLEAROUTPUT		420
#define IDM_SWITCHPANE			421

#define IDM_EOL_CRLF			430
#define IDM_EOL_CR			431
#define IDM_EOL_LF			432
#define IDM_EOL_CONVERT		433

#define IDM_TABSIZE			440

#define IDM_MONOFONT		450

#define IDM_OPENLOCALPROPERTIES	460
#define IDM_OPENUSERPROPERTIES	461
#define IDM_OPENGLOBALPROPERTIES	462
#define IDM_OPENABBREVPROPERTIES	463

//#define IDM_SELECTIONMARGIN	490
//#define IDM_BUFFEREDDRAW	491
//#define IDM_USEPALETTE		492

// Buffers
#define IDM_PREVFILE			501
#define IDM_NEXTFILE			502
#define IDM_CLOSEALL			503
#define IDM_BUFFERSEP		504

// Help
#define IDM_HELP			901
#define IDM_ABOUT			902

// Windows specific windowing options
#define IDM_ONTOP			960
#define IDM_FULLSCREEN		961

// Dialog control IDs
#define IDGOLINE			220
#define IDABOUTSCINTILLA	221
#define IDFINDWHAT			222
#define IDFILES				223
#define IDDIRECTORY			224
#define IDCURRLINE			225
#define IDLASTLINE			226
#define IDEXTEND			227
#define IDTABSIZE			228
#define IDINDENTSIZE		229
#define IDUSETABS			230

#define IDREPLACEWITH		231
#define IDWHOLEWORD			232
#define IDMATCHCASE			233
#define IDDIRECTIONUP		234
#define IDDIRECTIONDOWN		235
#define IDREPLACE			236
#define IDREPLACEALL		237
#define IDREPLACEINSEL		238
#define IDREGEXP			239
#define IDWRAP			240
#define IDUNSLASH			241

// Dialog IDs
#define IDD_FIND			400
#define IDD_REPLACE			401

// Resource IDs
#define IDR_CLOSEFILE 100
#endif
