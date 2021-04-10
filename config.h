/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_green1[]      = "#458b74";
static const char col_green2[]      = "#316453";
static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
  [SchemeSel]  = { col_gray4, col_green2,  col_green1  },
};

/* tagging */
static const char *tags[] = { "1", "2" };

static const Rule rules[] = {
  /* xprop(1):
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
   */
  /* class      instance    title       tags mask     isfloating   monitor */
  { "Chromium-browser",  NULL,       NULL,       1,       0,           -1 },
  { "Anki",              NULL,       NULL,       1,       0,           -1 },
  { "kdenlive",          NULL,       NULL,       1,       0,           -1 },
  { "Inkscape",          NULL,       NULL,       1,       0,           -1 },
  { "Emacs",             NULL,       NULL,       2,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
  /* symbol     arrange function */
  { ">M>",      centeredfloatingmasteralways }, /* first entry is default */
  { "[M]",      monocle },
  { "=[]",      leftstack },
  { NULL,       NULL },  /* needed to use cyclelayout function */
};

/* key definitions */
#define MODKEY Mod4Mask

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* the -i flag run bash as if was interactive and so read ~/.bashrc file */
/* so if you add paths to PATH variable in ~/.bashrc, bash will be aware */
/* of those paths to look for binaries */
#define SHCMD_INTERACTIVE(cmd) { .v = (const char*[]){ "/bin/bash", "-ic", cmd, NULL } }

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_green2, "-sf", col_gray4, NULL };

static const char *termcmd[]  = { "st", NULL };

/* find the keys in /usr/include/X11/keysymdef.h file */

static Key keys[] = {
  /* modifier              key        function        argument */
  /* TODO: add binding for inkscape, kdenlive, and taking screenshots */

  { MODKEY,             XK_0,       spawn,          {.v = dmenucmd } },
  { MODKEY,             XK_1,       spawn,          SHCMD("chromium-browser")},
  { MODKEY,             XK_2,       spawn,          SHCMD("emacsclient -nc") },
  { MODKEY,             XK_3,       spawn,          {.v = termcmd } },

  { 0,                  XK_F8,      view,           {.ui = 1 << 0} },
  { MODKEY,             XK_F8,      tag,            {.ui = 1 << 0} },
  { 0,                  XK_F9,      view,           {.ui = 1 << 1} },
  { MODKEY,             XK_F9,      tag,            {.ui = 1 << 1} },
  { 0,                  XK_F10,     view,           {.ui = ~0 } },

  { MODKEY,             XK_c,       setlayout,      {.v = &layouts[0]} },  /* centeredfloatingmasteralways layout */
  { MODKEY,             XK_t,       setlayout,      {.v = &layouts[1]} },  /* monocle layout */
  { MODKEY,             XK_l,       setlayout,      {.v = &layouts[2]} },  /* leftstack layout */

  { MODKEY,             XK_d,       focusstack,     {.i = +1 } },
  { MODKEY,             XK_Tab,     zoom,           {0} },

  { MODKEY,             XK_plus,    setmfact,       {.f = +0.05} },
  { MODKEY,             XK_minus,   setmfact,       {.f = -0.05} },
  { MODKEY|ShiftMask,   XK_plus,    incnmaster,     {.i = +1 } },
  { MODKEY|ShiftMask,   XK_minus,   incnmaster,     {.i = -1 } },

  { MODKEY,             XK_q,       killclient,     {0} },
  { MODKEY|ShiftMask,   XK_q,       quit,           {0} },
};

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
