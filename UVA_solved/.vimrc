" PROPERTY OF LUSERX0 "
runtime! debian.vim

" Make the shit a little better
set vb t_vb=
set ruler
set showcmd     " Show (partial) command in status line.
set autowrite       " Automatically save before commands like :next and :make
set hidden      " Hide buffers when they are abandoned
set mouse=a     " Enable mouse usage (all modes)

set laststatus=2
set statusline=%F%m%r%h%w\ [FORMAT=%{&ff}]\ [TYPE=%Y]\ [ASCII=\%03.3b]\ [HEX=\%02.2B]\ [POS=%04l,%04v][%p%%]\ [LEN=%L]


"a lot better
setlocal spell spelllang=en
set nospell
set encoding=utf-8
set number
set modeline 
set guioptions+=a

"MAIN STUFF
set backspace=2 tabstop=3 shiftwidth=3
set ignorecase smartcase
set autoindent smartindent
set gdefault hlsearch incsearch showmatch
set expandtab softtabstop=3
syntax on
colorscheme industry 
"

if has("autocmd")
  filetype plugin indent on
endif

" Autocomplete gia for loops
iabbrev <buffer> for for (i = 0; i < n; ++i){<cr><cr>}

" Use unknown stuff
set ofu=syntaxcomplete#Complete
au BufNewFile,BufRead,BufEnter *.cpp,*.hpp set omnifunc=omni#cpp#complete#Main
au BufNewFile,BufRead *.less set filetype=less

" Tab autocompletes
function! Mosh_Tab_Or_Complete()
    if col('.')>1 && strpart( getline('.'), col('.')-2, 3 ) =~ '^\w'
        return "\<C-N>"
    else
        return "\<Tab>"
    endfunction
    vmap C :s/^/\/\/<cr>gv:s/^\/\/\/\/<cr>gv:s/^<cr>:noh<cr>
    :inoremap <Tab> <C-R>=Mosh_Tab_Or_Complete()<CR>
                       


" Set compilers
autocmd FileType c         set makeprg=gcc\ -Wall\ -O2
autocmd FileType cpp       set makeprg=g++\ -Wall\ -O2
autocmd FileType python    set makeprg=python3

" Save, compile and run files
function! CompileAndRun()
    write
        silent! make %
        redraw!
        cwindow
        if len(getqflist()) == 0
            exec '!time ./a.out'
        endif
endfunction

nnoremap <leader>c :call CompileAndRun()<cr>

" Python-specific settings
    set foldmethod=indent
    set foldlevel=99

" Trailing whitespace
autocmd FileType c,cpp,java,php,python,ruby autocmd BufWritePre <buffer>
":%s/\s\+$//e

command! W :w
command! Q :q

" Markdown-specific setti

 autocmd FileType markdown set formatoptions+=t | set tw=79
