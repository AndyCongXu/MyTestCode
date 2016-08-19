set nocompatible

if has("syntax")
syntax on
endif

colorscheme ron

filetype on
filetype plugin on

set background=dark

if has("autocmd")
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif

filetype plugin indent on
endif

set ignorecase
set smartcase
set autowrite
set autoindent
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
set softtabstop=4
set paste
"set cindent
set cinoptions={0,1s,t0,n-2,p2s,(03s,=.5s,>1s,=1s,:1s
set showmatch
set linebreak
set whichwrap=b,s,<,>,[,]
"set mouse=a
set number
set previewwindow
set history=50
set laststatus=2
set ruler
set showcmd
set showmode
set incsearch
set hlsearch


"-- Tlist --
let Tlist_Auto_Open=1
let Tlist_GainFocus_On_ToggleOpen=0
let Tlist_Close_On_Select=0
let Tlist_Exit_OnlyWindow=1
let Tlist_Use_SingleClick=0
let Tlist_Auto_Highlight_Tag=1
let Tlist_Highlight_Tag_On_BufEnter=0
let Tlist_Process_File_Always=0
let Tlist_Auto_Update=1
let Tlist_File_Fold_Auto_Close=0
let Tlist_Sort_Type="order"
let Tlist_Use_Horiz_Window=0
let Tlist_Use_Right_Window=0
let Tlist_WinWidth=50
let Tlist_WinHeight=50
let Tlist_Inc_Winwidth=0
let Tlist_Compact_Format=0
let Tlist_Enable_Fold_Column=1
let Tlist_Display_Prototype=0
let Tlist_Display_Tag_Scope=0
let Tlist_Show_Menu=1
let Tlist_Max_Submenu_Item=100
let Tlist_Max_Tag_Length=50
let Tlist_Ctags_Cmd='/home/xchonxu/ctags-5.8/ctags'


map <F5> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR><CR> :TlistUpdate<CR>
imap <F5> <ESC>:!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<CR><CR> :TlistUpdate<CR>
set tags=tags
set tags+=./tags
set tags+=/proj/MPS_DEV_REPO/xchonxu/xchonxu_rdc_g11_wp_fp_linux/tags

"-- omnicppcomplete setting --
imap <F3> <C-X><C-O>
imap <F2> <C-X><C-I>
set completeopt=menu,menuone " 关掉智能补全时的预览窗口
let OmniCpp_MayCompleteDot = 1 " autocomplete with .
let OmniCpp_MayCompleteArrow = 1 " autocomplete with ->
let OmniCpp_MayCompleteScope = 1 " autocomplete with ::
let OmniCpp_SelectFirstItem = 2 " select first item (but don't insert)
let OmniCpp_NamespaceSearch = 2 " search namespaces in this and included files
let OmniCpp_ShowPrototypeInAbbr = 1 " show function prototype in popup window
let OmniCpp_GlobalScopeSearch=1 " enable the global scope search
let OmniCpp_DisplayMode=1 " Class scope completion mode: always show all members
"let OmniCpp_DefaultNamespaces=["std"]
let OmniCpp_ShowScopeInAbbr=1 " show scope in abbreviation and remove the last colum
let OmniCpp_ShowAccess=1
set nocp
filetype plugin on

