/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 6;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 6;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            =22;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]   	    = { "JetBrains Mono Medium:size=9:antialias=true:autohint=true", "Noto Color Emoji:size=8:antialias=true:autohint=true" };
static const char dmenufont[]       = "JetBrains Mono Medium:size=9:antialias=true:autohint=true";
static const char col_gray1[]       = "#282c34";
static const char col_gray2[]       = "#282c34";
static const char col_gray3[]       = "#d7d7d7";
static const char col_gray4[]       = "#d7d7d7";
static const char col_cyan[]        = "#304569";
static const char col_border[]        = "#304569";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_border  },
};

/* staticstatus */
static const int statmonval = 0;

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      		instance    title       			tags mask   iscentered  isfloating  monitor */
	{ "Gimp",    		NULL,     	NULL,           		0,         	0,			1,          -1 },
	{ "vmrc",    		NULL,     	NULL,           		0,         	0,			1,          -1 },
	{ "Vmrc",    		NULL,     	NULL,           		0,         	0,			1,          -1 },
	{ "fzfmenu",    	NULL,     	NULL,           		0,         	1,			1,          -1 },
	{ NULL,    	 		NULL,     	"Picture-in-Picture",	0,			0,			1,          -1 },
	{ NULL,    	 		NULL,     	"Picture in picture",	0,			0,          1,          -1 },
	{ NULL,    	 		NULL,     	"galculator",       	0,			0,          1,          -1 },
	{ NULL,    	 		NULL,     	"mpv floating",			0,			0,         	1,          -1 },
	{ NULL,    	 		NULL,     	"mpvfloating",       	0,			0,         	1,          -1 },
	{ "Tor Browser",  	NULL,     	NULL,       			0,			0,         	1,          -1 },
	{ NULL,      		NULL,     	"Event Tester", 		0,			0,         	0,          -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]    = { "dmenu_run", "-p", "Launch: ", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/* WINDOW MANAGEMENT */
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY,   	                XK_Return, spawn,          {.v = termcmd } },
	{ NULL,                       	XK_F12,    togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ControlMask,           XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },

	/* WINDOW GAPS MANAGEMENT */
	{ MODKEY,    			        XK_z,      incrgaps,       {.i = +1 } },
	{ MODKEY, 					    XK_x,      incrgaps,       {.i = -1 } },
	{ MODKEY,    			        XK_a,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,   		    XK_a,      defaultgaps,    {0} },

	/* LAYOUT MANAGEMENT */
	{ MODKEY,           			XK_Tab,    cyclelayout,    {.i = +1 } },
    { MODKEY|ShiftMask,       		XK_Tab,    cyclelayout,    {.i = -1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_s,      togglesticky,   {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

	/* MONITOR MANAGEMENT */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* TAG MANAGEMENT */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	/* QUIT & RELOAD DWM */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask, 			XK_r,      quit,           {1} },

	/* APPLICATIONS KEYBINDIGS */
    { MODKEY|ControlMask,        	XK_t,      spawn,          SHCMD("trayer --edge bottom --SetDockType true --SetPartialStrut true --transparent true --alpha 256 --tint 0x000000 --expand true --padding 1 --monitor primary --iconspacing 5") },
    { MODKEY|ControlMask|ShiftMask, XK_t,      spawn,          SHCMD("killall trayer") },
    { MODKEY|Mod1Mask,        		XK_l,      spawn,          SHCMD("slock") },
    /* { MODKEY|Mod1Mask,        	XK_w,      spawn,          CMD("brave") }, */
	/* { MODKEY|Mod1Mask,        	XK_c,      spawn,          CMD("alacritty -e mocp") }, */
	/* { MODKEY|Mod1Mask,       	XK_e,      spawn,          CMD("alacritty -e vim") }, */
	/* { MODKEY|Mod1Mask,        	XK_f,      spawn,          CMD("alacritty -e vifm") }, */
	/* { MODKEY|Mod1Mask,        	XK_h,      spawn,          CMD("alacritty -e htop") }, */
	/* { MODKEY|Mod1Mask,        	XK_i,      spawn,          CMD("alacritty -e weechat") }, */
	/* { MODKEY|Mod1Mask,        	XK_n,      spawn,          CMD("alacritty -e newsboat") }, */
	/* { MODKEY|Mod1Mask|ShiftMask, XK_w,      spawn,          CMD("alacritty -e w3m https://www.duckduckgo.com") }, */
	/* { MODKEY|Mod1Mask|ShiftMask, XK_m,      spawn,          CMD("ferdi") }, */
};

/* MOUSE KEYBINDIGS */
/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
